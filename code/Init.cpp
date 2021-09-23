s32 sortTmpOrder(void *a, void *b)
{
    tmp_order *ordA = (tmp_order *)a;
    tmp_order *ordB = (tmp_order *)b;
    
    if(ordA->init < ordB->init) { return -1; }
    else if(ordA->init == ordB->init) { return 0; }
    else { return 1; }
}

void RollOnClick(UIContext *cxt, void *data)
{
    InitPage *Page = State.Init;
    
    s32 visibleMobs   = Page->Mobs.selectedIndex;
    s32 visibleAllies = Page->Allies.selectedIndex;
    
    for(u32 i = 0; i < visibleMobs; i++)
    {
        InitField *f = Page->MobFields + i;
        
        s32 finalVal = ls_unistrToInt(f->final.text);
        if(finalVal != 0) { continue; }
        
        s32 die = pcg32_bounded(&pcg32_global, 20) + 1;
        s32 bonus = ls_unistrToInt(f->bonus.text);
        
        ls_unistrClear(&f->final.text);
        ls_unistrFromInt_t(&f->final.text, bonus + die);
        f->final.viewEndIdx = f->final.text.len;
    }
    
    for(u32 i = 0; i < visibleAllies; i++)
    {
        InitField *f = Page->AllyFields + i;
        
        s32 finalVal = ls_unistrToInt(f->final.text);
        if(finalVal != 0) { continue; }
        
        s32 die = pcg32_bounded(&pcg32_global, 20) + 1;
        s32 bonus = ls_unistrToInt(f->bonus.text);
        
        ls_unistrClear(&f->final.text);
        ls_unistrFromInt_t(&f->final.text, bonus + die);
        f->final.viewEndIdx = f->final.text.len;
    }
}

void SetOnClick(UIContext *cxt, void *data)
{
    AssertMsg(!State.inBattle, "Clicking this should be impossible while in Battle\n");
    
    InitPage *Page = State.Init;
    
    s32 visibleMobs   = Page->Mobs.selectedIndex;
    s32 visibleAllies = Page->Allies.selectedIndex;
    s32 visibleOrder  = visibleMobs + visibleAllies + PARTY_NUM;  //TODO: @VisibleOrder
    
    tmp_order ord[ORDER_NUM] = {};
    u32 idx = 0;
    
    for(u32 i = 0; i < visibleMobs; i++)
    {
        InitField *f = Page->MobFields + i;
        
        ord[idx].init = ls_unistrToInt(f->final.text);
        ord[idx].name = &f->name.text;
        ord[idx].ID   = f->ID;
        
        idx += 1;
    }
    
    for(u32 i = 0; i < visibleAllies; i++)
    {
        InitField *f = Page->AllyFields + i;
        
        ord[idx].init = ls_unistrToInt(f->final.text);
        ord[idx].name = &f->name.text;
        ord[idx].ID   = f->ID;
        
        idx += 1;
    }
    
    for(u32 i = 0; i < PARTY_NUM; i++)
    {
        ord[idx].init = ls_unistrToInt(Page->PlayerInit[i].text);
        ord[idx].name = (unistring *)(PartyNameUTF32 + i);
        ord[idx].ID   = i;
        
        idx += 1;
    }
    
    ls_quicksortCustom(ord, sizeof(tmp_order), visibleOrder, sortTmpOrder);
    
    for(u32 i = 0, j = visibleOrder - 1; i < visibleOrder; i++, j--)
    {
        Order *f = Page->OrderFields + i;
        
        ls_unistrSet(&f->field.text, *ord[j].name);
        f->ID = ord[j].ID;
        
        //TODO: Make this just a reference to Order[i].field.text ??
        if(i == 0) 
        { 
            ls_unistrSet(&Page->Current.text, *ord[j].name); 
            Page->Current.viewEndIdx = Page->Current.text.len;
        }
    }
    
    for(u32 i = 0; i < PARTY_NUM; i++)
    { Page->PlayerInit[i].isReadonly = TRUE; }
    
    for(u32 i = 0; i < MOB_NUM; i++)  {
        Page->MobFields[i].name.isReadonly  = TRUE;
        Page->MobFields[i].bonus.isReadonly = TRUE;
        Page->MobFields[i].final.isReadonly = TRUE;
    }
    
    for(u32 i = 0; i < ALLY_NUM; i++) { 
        Page->AllyFields[i].name.isReadonly  = TRUE;
        Page->AllyFields[i].bonus.isReadonly = TRUE;
        Page->AllyFields[i].final.isReadonly = TRUE;
    }
    
    Page->turnsInRound = visibleOrder - 1;
    
    State.inBattle = TRUE;
}

void ResetOnClick(UIContext *cxt, void *data)
{
    InitPage *Page = State.Init;
    
    Page->Mobs.selectedIndex   = 0;
    Page->Allies.selectedIndex = 0;
    State.inBattle = FALSE;
    
    unistring zeroUTF32 = { (u32 *)U"0", 1, 1 };
    
    for(u32 i = 0; i < PARTY_NUM; i++) 
    { 
        ls_unistrSet(&Page->PlayerInit[i].text, zeroUTF32);
        Page->PlayerInit[i].viewEndIdx = Page->PlayerInit[i].text.len;
    }
    
    s32 currID = PARTY_NUM;
    for(u32 i = 0; i < MOB_NUM; i++)   
    { 
        InitField *f = Page->MobFields + i;
        
        ls_uiTextBoxClear(cxt, &f->name);
        ls_unistrSet(&f->name.text, ls_unistrConstant(MobName[i]));
        f->name.viewEndIdx = f->name.text.len;
        
        ls_unistrSet(&f->bonus.text ,zeroUTF32);
        f->bonus.viewEndIdx = f->bonus.text.len;
        
        ls_unistrSet(&f->final.text, zeroUTF32);
        f->final.viewEndIdx = f->final.text.len;
        
        f->ID = currID;
        currID += 1;
    }
    
    for(u32 i = 0; i < ALLY_NUM; i++)  
    { 
        InitField *f = Page->AllyFields + i;
        
        ls_uiTextBoxClear(cxt, &f->name);
        ls_unistrSet(&f->name.text, ls_unistrConstant(AllyName[i]));
        f->name.viewEndIdx = f->name.text.len;
        
        ls_unistrSet(&f->bonus.text ,zeroUTF32);
        f->bonus.viewEndIdx = f->bonus.text.len;
        
        ls_unistrSet(&f->final.text, zeroUTF32);
        f->final.viewEndIdx = f->final.text.len;
        
        f->ID = currID;
        currID += 1;
    }
    
    for(u32 i = 0; i < ORDER_NUM; i++)
    {
        Order *f = Page->OrderFields + i;
        
        ls_unistrClear(&f->field.text);
        f->field.currPos = 1.0;
    }
    
    for(u32 i = 0; i < COUNTER_NUM; i++)
    {
        Counter *f = Page->Counters + i;
        
        ls_uiTextBoxClear(cxt, &f->name);
        ls_uiTextBoxClear(cxt, &f->rounds);
        f->roundsLeft      = 0;
        f->startIdxInOrder = 0;
        f->roundCounter    = 0;
        f->isActive        = FALSE;
    }
    
    ls_unistrClear(&Page->Current.text);
    
    ls_unistrSet(&Page->RoundCounter.text, zeroUTF32);
    Page->RoundCounter.viewEndIdx = Page->RoundCounter.text.len;
}

void NextOnClick(UIContext *cxt, void *data)
{
    InitPage *Page = State.Init;
    
    s32 visibleMobs   = Page->Mobs.selectedIndex;
    s32 visibleAllies = Page->Allies.selectedIndex;
    s32 visibleOrder  = visibleMobs + visibleAllies + PARTY_NUM; //TODO: @VisibleOrder
    
    Page->currIdx = (Page->currIdx + 1) % visibleOrder;
    
    //NOTE: Increase the round
    if(Page->currIdx == 0)
    {
        Page->roundCount += 1;
        ls_unistrFromInt_t(&Page->RoundCounter.text, Page->roundCount);
        Page->RoundCounter.viewEndIdx = Page->RoundCounter.text.len;
    }
    
    //NOTE: Set the Current
    ls_unistrSet(&Page->Current.text, Page->OrderFields[Page->currIdx].field.text);
    Page->Current.viewEndIdx = Page->Current.text.len;
    
    //NOTE: Advance the Counters
    for(u32 i = 0; i < COUNTER_NUM; i++)
    {
        Counter *C = Page->Counters + i;
        
        if(C->isActive == TRUE)
        {
            if(C->roundCounter >= Page->turnsInRound)
            { 
                C->roundCounter = 0;
                C->roundsLeft -= 1;
                
                AssertMsg(C->roundsLeft >= 0, "Rounds Left became negative");
                
                if(C->roundsLeft == 0)
                {
                    ls_uiTextBoxClear(cxt, &C->name);
                    ls_uiTextBoxClear(cxt, &C->rounds);
                    
                    C->roundCounter = 0;
                    C->isActive     = FALSE;
                    
                    continue;
                }
                
                ls_unistrFromInt_t(&C->rounds.text, C->roundsLeft);
                C->rounds.viewEndIdx = C->rounds.text.len;
                
                continue;
            }
            
            C->roundCounter += 1;
            continue;
        }
    }
}

void StartCounterOnClick(UIContext *cxt, void *data)
{
    Counter *C = (Counter *)data;
    
    if(State.inBattle == FALSE) { return; }
    
    s32 val = ls_unistrToInt(C->rounds.text);
    if(val <= 0) { return; }
    
    C->name.isReadonly   = TRUE;
    C->rounds.isReadonly = TRUE;
    
    C->isActive        = TRUE;
    C->roundCounter    = 0;
    C->roundsLeft      = val;
    C->startIdxInOrder = State.Init->currIdx;
    
    return;
}

void PlusOneCounterOnClick(UIContext *cxt, void *data)
{
    Counter *C = (Counter *)data;
    
    C->roundsLeft += 1;
    ls_unistrFromInt_t(&C->rounds.text, C->roundsLeft);
    
    return;
}

void SetInitTab(UIContext *cxt)
{
    InitPage *Page = State.Init;
    
    for(u32 i = 0; i < MOB_NUM + 1; i++) { ls_uiListBoxAddEntry(cxt, &Page->Mobs, (char *)Enemies[i]); }
    for(u32 i = 0; i < ALLY_NUM + 1; i++) { ls_uiListBoxAddEntry(cxt, &Page->Allies, (char *)Allies[i]); }
    
    for(u32 i = 0; i < PARTY_NUM; i++) 
    { 
        Page->PlayerInit[i].text       = ls_unistrFromUTF32(U"0");
        Page->PlayerInit[i].viewEndIdx = Page->PlayerInit[i].text.len;
        Page->PlayerInit[i].maxLen     = 2;
    }
    
    s32 currID = PARTY_NUM;
    for(u32 i = 0; i < MOB_NUM; i++)   
    { 
        InitField *f = Page->MobFields + i;
        
        f->name.text        = ls_unistrFromUTF32(MobName[i]);
        f->name.viewEndIdx  = f->name.text.len;
        
        f->bonus.text       = ls_unistrFromUTF32(U"0");
        f->bonus.viewEndIdx = f->bonus.text.len;
        f->bonus.maxLen     = 2;
        
        f->final.text       = ls_unistrFromUTF32(U"0");
        f->final.viewEndIdx = f->final.text.len;
        f->final.maxLen     = 2;
        
        f->ID = currID;
        currID += 1;
    }
    
    for(u32 i = 0; i < ALLY_NUM; i++)  
    { 
        InitField *f = Page->AllyFields + i;
        
        f->name.text        = ls_unistrFromUTF32(AllyName[i]);
        f->name.viewEndIdx  = f->name.text.len;
        
        f->bonus.text       = ls_unistrFromUTF32(U"0");
        f->bonus.viewEndIdx = f->bonus.text.len;
        f->bonus.maxLen     = 2;
        
        f->final.text       = ls_unistrFromUTF32(U"0");
        f->final.viewEndIdx = f->final.text.len;
        f->final.maxLen     = 2;
        
        f->ID = currID;
        currID += 1;
    }
    
    for(u32 i = 0; i < ORDER_NUM; i++)
    {
        Order *f = Page->OrderFields + i;
        
        Color lColor      = ls_uiAlphaBlend(RGBA(0x10, 0xDD, 0x20, 0x99), cxt->widgetColor);
        Color rColor      = ls_uiAlphaBlend(RGBA(0xDD, 0x10, 0x20, 0x99), cxt->widgetColor);
        f->field          = ls_uiSliderInit(NULL, 100, -50, 1.0, SL_BOX, lColor, rColor);
        
        f->pos.text       = ls_unistrFromInt(i);
        f->pos.viewEndIdx = f->pos.text.len;
        f->pos.maxLen     = 2;
        
        f->remove.name    = ls_unistrFromUTF32(U"X");
        f->remove.onClick = 0x0;
        f->remove.onHold  = 0x0;
    }
    
    for(u32 i = 0; i < COUNTER_NUM; i++)
    {
        Counter *f = Page->Counters + i;
        
        f->name.text     = ls_unistrAlloc(16);
        f->rounds.text   = ls_unistrAlloc(16);
        f->rounds.maxLen = 2;
        
        f->start.name    = ls_unistrFromUTF32(U"Start");
        f->start.onClick = StartCounterOnClick;
        f->start.data    = (void *)f;
        f->start.onHold  = 0x0;
        
        f->plusOne.name    = ls_unistrFromUTF32(U"+1");
        f->plusOne.onClick = PlusOneCounterOnClick;
        f->plusOne.data    = (void *)f;
        f->plusOne.onHold  = 0x0;
        
        f->stop.name    = ls_unistrFromUTF32(U"Stop");
        f->stop.onClick = 0x0;
        f->stop.data    = (void *)f;
        f->stop.onHold  = 0x0;
    }
    
    for(u32 i = 0; i < THROWER_NUM; i++)
    {
        DiceThrow *f = Page->Throwers + i;
        
        f->name.text   = ls_unistrAlloc(32);
        f->toHit.text  = ls_unistrAlloc(32);
        f->hitRes.text = ls_unistrAlloc(16);
        f->damage.text = ls_unistrAlloc(32);
        f->dmgRes.text = ls_unistrAlloc(16);
        
        f->hitRes.maxLen = 4;
        f->dmgRes.maxLen = 4;
        
        f->throwDie.name    = ls_unistrFromUTF32(U"Go");
        f->throwDie.onClick = 0x0;
        f->throwDie.onHold  = 0x0;
    }
    
    {
        // General Thrower
        Page->GeneralThrower.toHit.text  = ls_unistrAlloc(32);
        Page->GeneralThrower.hitRes.text = ls_unistrAlloc(16);
        
        Page->GeneralThrower.hitRes.maxLen = 4;
        
        Page->GeneralThrower.throwDie.name    = ls_unistrFromUTF32(U"Go");
        Page->GeneralThrower.throwDie.onClick = 0x0;
        Page->GeneralThrower.throwDie.onHold  = 0x0;
    }
    
    
    Page->Current.text            = ls_unistrAlloc(16);
    Page->Current.isReadonly      = TRUE;
    
    Page->RoundCounter.text       = ls_unistrFromUTF32(U"0");
    Page->RoundCounter.viewEndIdx = Page->RoundCounter.text.len;
    Page->RoundCounter.isReadonly = TRUE;
    
    Page->Roll.name     = ls_unistrFromUTF32(U"Roll");
    Page->Roll.onClick  = RollOnClick;
    Page->Roll.onHold   = 0x0;
    
    Page->Set.name      = ls_unistrFromUTF32(U"Set");
    Page->Set.onClick   = SetOnClick;
    Page->Set.onHold    = 0x0;
    
    Page->Reset.name    = ls_unistrFromUTF32(U"Reset");
    Page->Reset.onClick = ResetOnClick;
    Page->Reset.onHold  = 0x0;
    
    Page->Next.name     = ls_unistrFromUTF32(U"Next");
    Page->Next.onClick  = NextOnClick;
    Page->Next.onHold   = 0x0;
}

void DrawInitField(UIContext *cxt, InitField *F, s32 x, s32 y)
{
    s32 w = 120;
    
    InitPage *Page = State.Init;
    
    ls_uiTextBox(cxt, &F->name,  x         , y, w, 20);
    ls_uiTextBox(cxt, &F->bonus, x + w     , y, 32, 20);
    ls_uiTextBox(cxt, &F->final, x + w + 32, y, 32, 20);
}

void DrawOrderField(UIContext *cxt, Order *f, s32 xPos, s32 yPos)
{
    ls_uiSlider(cxt, &f->field, xPos + 50, yPos, 120, 20);
    ls_uiTextBox(cxt, &f->pos, xPos + 25, yPos, 32, 20);
    ls_uiButton(cxt, &f->remove, xPos, yPos, 20, 20);
}

void DrawInitTab(UIContext *cxt)
{
    InitPage *Page = State.Init;
    
    s32 visibleMobs   = Page->Mobs.selectedIndex;
    s32 visibleAllies = Page->Allies.selectedIndex;
    
    //TODO: Change to allow removal of party
    s32 visibleOrder  = visibleMobs + visibleAllies + PARTY_NUM;  //TODO: @VisibleOrder
    
    // Party
    s32 yPos = 658;
    for(u32 i = 0; i < PARTY_NUM; i++)
    {
        ls_uiLabel(cxt, ls_unistrConstant(PartyName[i]), 580, yPos+6);
        ls_uiTextBox(cxt, Page->PlayerInit + i, 662, yPos, 32, 20);
        yPos -= 20;
    }
    
    // Allies
    yPos = 478;
    for(u32 i = 0; i < visibleAllies; i++)
    {
        DrawInitField(cxt, Page->AllyFields + i, 546, yPos);
        yPos -= 20;
    }
    
    // Enemies
    yPos = 658;
    for(u32 i = 0; i < visibleMobs; i++)
    {
        DrawInitField(cxt, Page->MobFields + i, 296, yPos);
        yPos -= 20;
    }
    
    // Order
    yPos = 658;
    for(u32 i = 0; i < visibleOrder; i += 2)
    {
        DrawOrderField(cxt, Page->OrderFields + i, 770, yPos);
        
        if((i+1) < visibleOrder)
        { DrawOrderField(cxt, Page->OrderFields + (i+1), 956, yPos); }
        
        yPos -= 20;
    }
    
    // Counters
    yPos = 658;
    for(u32 i = 0; i < COUNTER_NUM; i++)
    {
        Counter *f = Page->Counters + i;
        
        ls_uiLabel(cxt, ls_unistrConstant(CounterNames[i]), 20, yPos+24);
        
        ls_uiTextBox(cxt, &f->name, 20, yPos, 100, 20);
        ls_uiTextBox(cxt, &f->rounds, 125, yPos, 36, 20);
        
        if(!f->isActive) { ls_uiButton(cxt, &f->start, 166, yPos, 48, 20); }
        else
        {
            ls_uiButton(cxt, &f->plusOne, 166, yPos, 48, 20);
            ls_uiButton(cxt, &f->stop, 85, yPos+22, 48, 20);
        }
        
        yPos -= 44;
    }
    
    // Dice Throwers
    u32 xPos = 20;
    yPos = 110;
    for(u32 i = 0; i < THROWER_NUM; i++)
    {
        DiceThrow *f = Page->Throwers + i;
        
        ls_uiTextBox(cxt, &f->name,   xPos,       yPos,      120, 20);
        ls_uiTextBox(cxt, &f->toHit,  xPos,       yPos + 24, 138, 20);
        ls_uiTextBox(cxt, &f->hitRes, xPos + 138, yPos + 24, 36,  20);
        ls_uiTextBox(cxt, &f->damage, xPos,       yPos + 48, 138, 20);
        ls_uiTextBox(cxt, &f->dmgRes, xPos + 138, yPos + 48, 36,  20);
        
        ls_uiButton(cxt, &f->throwDie, xPos + 126, yPos, 48, 20);
        
        xPos += 212;
    }
    
    xPos = 20;
    yPos = 62;
    // General Thrower
    {
        ls_uiTextBox(cxt, &Page->GeneralThrower.toHit,  xPos,       yPos, 168, 20);
        ls_uiTextBox(cxt, &Page->GeneralThrower.hitRes, xPos + 168, yPos, 36,  20);
        
        ls_uiButton(cxt, &Page->GeneralThrower.throwDie, xPos + 210, yPos, 48, 20);
    }
    
    ls_uiButton(cxt, &Page->Reset, 600, 698, 48, 20);
    
    
    if(!State.inBattle)
    {
        //TODO: Clicking on a ListBox Entry clicks also what's behind it.
        ls_uiListBox(cxt, &Page->Mobs, 336, 698, 100, 20);
        ls_uiListBox(cxt, &Page->Allies, 570, 518, 100, 20);
        
        
        ls_uiButton(cxt, &Page->Roll, 486, 698, 48, 20);
        ls_uiButton(cxt, &Page->Set, 710, 698, 48, 20);
    }
    else
    {
        ls_uiTextBox(cxt, &Page->Current, 870, 688, 100, 20);
        ls_uiTextBox(cxt, &Page->RoundCounter, 1180, 740, 30, 20);
        
        ls_uiButton(cxt, &Page->Next, 900, 718, 48, 20);
    }
    
#if 0
    
    Page->Save  = AddButton(WinH, wA, "Save",  670, 42, 45, 20, (*ElementId)++); wA += 1;
    
    Page->GeneralThrower = AddGeneralThrower(WinH, &wA, 20, 752, ElementId);
    Page->numWindows += 3;
    
    
    Page->EncounterName = AddTextBox(WinH, wA, 0, LABEL_NULL, 644, 62, 100, 20, (*ElementId)++); wA += 1;
    Page->numWindows += 1;
    
    //NOTE:EncounterSelection
    {
        Page->EncounterSel = AddUnsortedComboBox(WinH, wA, "Encounters", LABEL_UP, 
                                                 520, 60, 100, 20, (*ElementId)++, 1);
        wA += 2;
        
        Page->numWindows += 2;
    }
    
    return;
#endif
}