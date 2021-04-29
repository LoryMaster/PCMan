string getText(HWND hwnd);
void UpdateSavingThrows();
void HideElem(HWND box);
void ShowElem(HWND box);
void HideOrder(OrderField *o, s32 n);
void ShowOrder(OrderField *o, s32 n);
void HideInitField(InitField *f, s32 n);
void HideInitFieldAdd(InitField *f, u32 idx, s32 max);
void ShowInitFieldAdd(InitField *f, u32 idx, s32 max);
void SwitchInitAddToSelect(InitField *f, u32 idx, s32 max);

//TODO: I'd like to add functionality for removing Ability Scores.
//TODO: Start using the ElementMap to stop doing the stupid for loops everywhere
void OnButton(u32 commandID, u32 notificationCode, HWND handle)
{
    InitPage  *Init = State.Init;
    FeatsPage *Feats = State.Feats;
    PCPage    *PCPage   = State.PC;
    
    Button *clicked = (Button *)ElementMap[commandID].ptr;
    
    if(clicked->LinkedText != 0x0) {
        TextBox *text = clicked->LinkedText;
        
        AbilityScores *S = PCPage->Scores;
        
        string s = getText(text->box);
        u32 val = ls_stoi(s);
        val += clicked->value;
        
        if(S->Plus1[ABILITY_STR]->id ||
           S->Plus10[ABILITY_STR]->id)
        {
            Edit_SetText(S->Bonus[ABILITY_STR]->box, getASBonusStr(val));
            pc.AbilityScores[ABILITY_STR] = val;
        }
        else if(S->Plus1[ABILITY_DEX]->id ||
                S->Plus10[ABILITY_DEX]->id) 
        {
            Edit_SetText(S->Bonus[ABILITY_DEX]->box, getASBonusStr(val));
            pc.AbilityScores[ABILITY_DEX] = val;
        } 
        else if(S->Plus1[ABILITY_CON]->id ||
                S->Plus10[ABILITY_CON]->id)
        {
            Edit_SetText(S->Bonus[ABILITY_CON]->box, getASBonusStr(val));
            pc.AbilityScores[ABILITY_CON] = val;
        } 
        else if(S->Plus1[ABILITY_INT]->id ||
                S->Plus10[ABILITY_INT]->id)
        {
            Edit_SetText(S->Bonus[ABILITY_INT]->box, getASBonusStr(val));
            pc.AbilityScores[ABILITY_INT] = val;
        } 
        else if(S->Plus1[ABILITY_WIS]->id ||
                S->Plus10[ABILITY_WIS]->id)
        {
            Edit_SetText(S->Bonus[ABILITY_WIS]->box, getASBonusStr(val));
            pc.AbilityScores[ABILITY_WIS] = val;
        } 
        else if(S->Plus1[ABILITY_CHA]->id ||
                S->Plus10[ABILITY_CHA]->id)
        {
            Edit_SetText(S->Bonus[ABILITY_CHA]->box, getASBonusStr(val));
            pc.AbilityScores[ABILITY_CHA] = val;
        } 
        
        string newVal = ls_itos(val);
        ls_strNullTerminate(&newVal);
        
        BOOL ret = SetWindowTextA(text->box, newVal.data);
        
        UpdateSavingThrows();
        
        ls_strFree(&s);
        ls_strFree(&newVal);
    }
    
    if(commandID == Init->Roll->id)
    {
        for(u32 i = 0; i < Init->VisibleMobs; i++)
        {
            char v[32] = {};
            u32 len = Edit_GetText(Init->MobFields[i].Final->box, v, 32);
            s32 finalVal = ls_atoi(v, len);
            if(finalVal != 0) { continue; }
            
            s32 die = pcg32_bounded(&pcg32_global, 20) + 1;
            u32 bonusLen = Edit_GetText(Init->MobFields[i].Bonus->box, v, 32);
            s32 bonus = ls_atoi(v, bonusLen);
            char final[32] = {};
            ls_itoa_t(bonus + die, final, 32);
            Edit_SetText(Init->MobFields[i].Final->box, final);
        }
        
        for(u32 i = 0; i < Init->VisibleAllies; i++)
        {
            char v[32] = {};
            u32 len = Edit_GetText(Init->AllyFields[i].Final->box, v, 32);
            s32 finalVal = ls_atoi(v, len);
            if(finalVal != 0) { continue; }
            
            s32 die = pcg32_bounded(&pcg32_global, 20) + 1;
            u32 bonusLen = Edit_GetText(Init->AllyFields[i].Bonus->box, v, 32);
            s32 bonus = ls_atoi(v, bonusLen);
            char final[32] = {};
            ls_itoa_t(bonus + die, final, 32);
            Edit_SetText(Init->AllyFields[i].Final->box, final);
        }
    }
    
    if(commandID == Init->Save->id)
    {
        u32 numEncounters = State.encounters.numEncounters;
        Encounter *curr = &State.encounters.Enc[numEncounters];
        
        Edit_GetText(State.Init->EncounterName->box, curr->name, 32);
        
        curr->numMobs = State.Init->VisibleMobs;
        curr->numAllies = State.Init->VisibleAllies;
        
        for(u32 i = 0; i < curr->numMobs; i++)
        {
            Edit_GetText(State.Init->MobFields[i].Name->box, curr->mobNames[i], 32);
            
            char bonus[32] = {};
            u32 len = Edit_GetText(State.Init->MobFields[i].Bonus->box, bonus, 32);
            curr->mobBonus[i] = ls_atoi(bonus, len);
        }
        
        for(u32 i = 0; i < curr->numAllies; i++)
        {
            Edit_GetText(State.Init->AllyFields[i].Name->box, curr->allyNames[i], 32);
            
            char bonus[32] = {};
            u32 len = Edit_GetText(State.Init->AllyFields[i].Bonus->box, bonus, 32);
            curr->allyBonus[i] = ls_atoi(bonus, len);
        }
        
        State.encounters.numEncounters += 1;
        
        const u32 baseHeight = 20;
        u32 height = 0;
        if(State.encounters.numEncounters == 1) { height = baseHeight*3; }
        else { height = baseHeight*(State.encounters.numEncounters + 1); }
        SetWindowPos(State.Init->EncounterSel->box, NULL, NULL, NULL, 100, height, SWP_NOMOVE | SWP_NOZORDER);
        
        ComboBox_InsertString(State.Init->EncounterSel->box, -1, curr->name);
    }
    
    if(commandID == Init->Set->id)
    {
        tmp_order ord[ORDER_NUM] = {};
        u32 idx = 0;
        
        for(u32 i = 0; i < Init->VisibleMobs; i++)
        {
            char v[32] = {};
            u32 len = Edit_GetText(Init->MobFields[i].Final->box, v, 32);
            ord[idx].init     = ls_atoi(v, len);
            ord[idx].nameBox  = Init->MobFields[i].Name->box;
            ord[idx].fieldId  = Init->MobFields[i].id;
            ord[idx].isParty  = FALSE;
            ord[idx++].isMob  = TRUE;
        }
        
        for(u32 i = 0; i < Init->VisibleAllies; i++)
        {
            char v[32] = {};
            u32 len = Edit_GetText(Init->AllyFields[i].Final->box, v, 32);
            ord[idx].init     = ls_atoi(v, len);
            ord[idx].nameBox  = Init->AllyFields[i].Name->box;
            ord[idx].fieldId  = Init->AllyFields[i].id;
            ord[idx].isParty  = FALSE;
            ord[idx++].isMob  = FALSE;
        }
        
        for(u32 i = 0; i < PARTY_NUM; i++)
        {
            char v[32] = {};
            u32 len = Edit_GetText(Init->PlayerFields[i].Bonus->box, v, 32);
            ord[idx].init      = ls_atoi(v, len);
            ord[idx].nameBox   = Init->PlayerFields[i].Bonus->label;
            ord[idx].fieldId   = Init->PlayerFields[i].id;
            ord[idx].isParty   = TRUE;
            ord[idx++].isMob   = FALSE;
        }
        
        order_ascending(ord, Init->VisibleOrder);
        
        for(u32 i = 0, j = Init->VisibleOrder - 1; i < Init->VisibleOrder; i++, j--)
        {
            char v[32] = {};
            u32 len = Edit_GetText(ord[j].nameBox, v, 32);
            
            Edit_SetText(Init->Order[i].Field->box, v);
            Init->Order[i].fieldId  = ord[j].fieldId;
            Init->Order[i].isMob    = ord[j].isMob;
            Init->Order[i].isParty  = ord[j].isParty;
            
            if(i == 0) { Edit_SetText(Init->Current->box, v); }
        }
        
        for(u32 i = 0; i < PARTY_NUM; i++)
        {
            Edit_SetReadOnly(Init->PlayerFields[i].Bonus->box, TRUE);
        }
        
        for(u32 i = 0; i < MOB_NUM; i++)  { 
            Edit_SetReadOnly(Init->MobFields[i].Name->box, TRUE);
            Edit_SetReadOnly(Init->MobFields[i].Bonus->box, TRUE);
            Edit_SetReadOnly(Init->MobFields[i].Final->box, TRUE);
        }
        
        for(u32 i = 0; i < ALLY_NUM; i++) { 
            Edit_SetReadOnly(Init->AllyFields[i].Name->box, TRUE);
            Edit_SetReadOnly(Init->AllyFields[i].Bonus->box, TRUE);
            Edit_SetReadOnly(Init->AllyFields[i].Final->box, TRUE);
        }
        
        Init->turnsInRound = Init->VisibleOrder - 1;
        
        State.inBattle = TRUE;
        HideElem(Init->Set->box);    HideElem(Init->Roll->box);
        HideElem(Init->Mobs->box);   HideElem(Init->Mobs->label);
        HideElem(Init->Allies->box); HideElem(Init->Allies->label);
        ShowElem(Init->Next->box);   ShowElem(Init->RoundCounter->box);
    }
    
    if(commandID == Init->Next->id)
    {
        //NOTE: Make sure removing order fields doesn't fuck this up!
        Init->currIdx = (Init->currIdx + 1) % Init->VisibleOrder;
        if(Init->currIdx == 0) 
        {
            char bf[8] = {};
            u32 rLen = Edit_GetText(Init->RoundCounter->box, bf, 8);
            s32 newRoundCount = ls_atoi(bf, rLen) + 1;
            char newStr[8] = {};
            u32 newLen = ls_itoa_t(newRoundCount, newStr, 8);
            Edit_SetText(Init->RoundCounter->box, newStr);
        }
        
        char v[32] = {};
        u32 len = Edit_GetText(Init->Order[Init->currIdx].Field->box, v, 32);
        Edit_SetText(Init->Current->box, v);
        
        for(u32 i = 0; i < COUNTER_NUM; i++)
        {
            Counter *C = &Init->Counters[i];
            
            if(C->isActive == TRUE)
            {
                if(C->roundCounter >= Init->turnsInRound)
                { 
                    C->roundCounter = 0;
                    
                    char v[8] = {};
                    u32 len = Edit_GetText(C->Rounds->box, v, 8);
                    s32 val = ls_atoi(v, len);
                    
                    if((val - 1) == 0)
                    {
                        Edit_SetReadOnly(Init->Counters[i].Field->box, FALSE);
                        Edit_SetText(Init->Counters[i].Field->box, "");
                        Edit_SetText(Init->Counters[i].Rounds->box, "");
                        
                        Init->Counters[i].roundCounter = 0;
                        Init->Counters[i].isActive     = FALSE;
                        continue;
                    }
                    
                    char newV[8] = {};
                    ls_itoa_t(val - 1, newV, 8);
                    
                    Edit_SetText(C->Rounds->box, newV);
                    continue;
                }
                
                C->roundCounter += 1;
                continue;
            }
        }
    }
    
    if(commandID == Init->Reset->id)
    {
        State.inBattle = FALSE;
        
        for(u32 i = 0; i < PARTY_NUM; i++)
        {
            Edit_SetText(Init->PlayerFields[i].Bonus->box, "0");
            Edit_SetReadOnly(Init->PlayerFields[i].Bonus->box, FALSE);
        }
        
        for(u32 i = 0; i < MOB_NUM; i++)
        { 
            Init->MobFields[i].id = i;
            Edit_SetText(Init->MobFields[i].Name->box, MobName[i]);
            Edit_SetText(Init->MobFields[i].Bonus->box, "");
            Edit_SetText(Init->MobFields[i].Final->box, "0");
            
            Edit_SetReadOnly(Init->MobFields[i].Name->box, FALSE);
            Edit_SetReadOnly(Init->MobFields[i].Bonus->box, FALSE);
            Edit_SetReadOnly(Init->MobFields[i].Final->box, FALSE);
        }
        
        for(u32 i = 0; i < ALLY_NUM; i++)
        { 
            Init->AllyFields[i].id = i;
            Edit_SetText(Init->AllyFields[i].Name->box, AllyName[i]);
            Edit_SetText(Init->AllyFields[i].Bonus->box, "");
            Edit_SetText(Init->AllyFields[i].Final->box, "0");
            
            Edit_SetReadOnly(Init->AllyFields[i].Name->box, FALSE);
            Edit_SetReadOnly(Init->AllyFields[i].Bonus->box, FALSE);
            Edit_SetReadOnly(Init->AllyFields[i].Final->box, FALSE);
        }
        
        for(u32 i = 0; i < ORDER_NUM; i++)
        { 
            Edit_SetText(Init->Order[i].Field->box, "");
            Init->Order[i].fieldId = 0;
            Init->Order[i].isMob   = 0;
            Init->Order[i].isParty = 0;
        }
        
        for(u32 i = 0; i < COUNTER_NUM; i++)
        {
            Edit_SetReadOnly(Init->Counters[i].Field->box, FALSE);
            Edit_SetText(Init->Counters[i].Field->box, "");
            Edit_SetText(Init->Counters[i].Rounds->box, "");
            
            Init->Counters[i].roundCounter = 0;
            Init->Counters[i].isActive     = FALSE;
        }
        
        Init->VisibleMobs   = 0;
        Init->VisibleAllies = 0;
        Init->VisibleOrder  = PARTY_NUM;
        
        Edit_SetText(Init->Current->box, "");
        Edit_SetText(Init->RoundCounter->box, "1");
        Init->currIdx       = 0;
        Init->turnsInRound  = 0;
        
        HideInitField(Init->MobFields, MOB_NUM);
        HideInitField(Init->AllyFields, ALLY_NUM);
        HideOrder(Init->Order, ORDER_NUM);
        HideElem(Init->Next->box);
        HideElem(Init->RoundCounter->box);
        
        ShowOrder(Init->Order, Init->VisibleOrder);
        ShowElem(Init->Set->box);
        ShowElem(Init->Mobs->box);
        ShowElem(Init->Allies->box);
        
        ComboBox_SetCurSel(Init->Mobs->box, 0);
        ComboBox_SetCurSel(Init->Allies->box, 0);
    }
    
    for(u32 i = 0; i < COUNTER_NUM; i++)
    {
        if(commandID == Init->Counters[i].Start->id)
        {
            if(State.inBattle == FALSE) { return; }
            
            char rounds[8] = {};
            
            Edit_SetReadOnly(Init->Counters[i].Field->box, TRUE);
            u32 len = Edit_GetText(Init->Counters[i].Rounds->box, rounds, 8);
            
            s32 val = ls_atoi(rounds, len);
            if(val <= 0) { return; }
            
            Init->Counters[i].isActive     = TRUE;
            Init->Counters[i].roundCounter = 0;
            
            return;
        }
    }
    
    for(u32 i = 0; i < MOB_NUM; i++)
    {
        if(State.inBattle == FALSE) { return; }
        
        if(commandID == Init->MobFields[i].New.Add->id)
        {
            SwitchInitAddToSelect(Init->MobFields, i, MOB_NUM);
            return;
        }
        
        if(commandID == Init->MobFields[i].New.Ok->id)
        {
            //Add to Order
            ShowOrder(&Init->Order[Init->VisibleOrder], 1);
            
            char name[32] = {};
            Edit_GetText(Init->MobFields[i].New.Name->box, name, 32);
            Edit_SetText(Init->Order[Init->VisibleOrder].Field->box, name);
            Edit_SetText(Init->MobFields[i].Name->box, name);
            
            Init->Order[Init->VisibleOrder].isMob     = TRUE;
            Init->Order[Init->VisibleOrder].isParty   = FALSE;
            Init->Order[Init->VisibleOrder].fieldId = Init->MobFields[i].id;
            
            Init->VisibleMobs += 1;
            Init->VisibleOrder += 1;
            Init->turnsInRound += 1;
            
            HideElem(Init->MobFields[i].New.Name->box);
            HideElem(Init->MobFields[i].New.Bonus->box);
            HideElem(Init->MobFields[i].New.Ok->box);
            
            ShowElem(Init->MobFields[i].Name->box);
            ShowElem(Init->MobFields[i].Final->box);
            ShowElem(Init->MobFields[i].Bonus->box);
            
            ShowInitFieldAdd(Init->MobFields, i+1, MOB_NUM);
            
            return;
        }
    }
    
    for(u32 i = 0; i < ALLY_NUM; i++)
    {
        if(State.inBattle == FALSE) { return; }
        
        if(commandID == Init->AllyFields[i].New.Add->id)
        {
            SwitchInitAddToSelect(Init->AllyFields, i, ALLY_NUM);
            return;
        }
        
        if(commandID == Init->AllyFields[i].New.Ok->id)
        {
            //Add to Order
            ShowOrder(&Init->Order[Init->VisibleOrder], 1);
            
            char name[32] = {};
            Edit_GetText(Init->AllyFields[i].New.Name->box, name, 32);
            Edit_SetText(Init->Order[Init->VisibleOrder].Field->box, name);
            Edit_SetText(Init->AllyFields[i].Name->box, name);
            
            Init->Order[Init->VisibleOrder].isMob   = FALSE;
            Init->Order[Init->VisibleOrder].isParty = FALSE;
            Init->Order[Init->VisibleOrder].fieldId = Init->AllyFields[i].id;
            
            Init->VisibleAllies += 1;
            Init->VisibleOrder += 1;
            Init->turnsInRound += 1;
            
            HideElem(Init->AllyFields[i].New.Name->box);
            HideElem(Init->AllyFields[i].New.Bonus->box);
            HideElem(Init->AllyFields[i].New.Ok->box);
            
            ShowElem(Init->AllyFields[i].Name->box);
            ShowElem(Init->AllyFields[i].Final->box);
            ShowElem(Init->AllyFields[i].Bonus->box);
            
            ShowInitFieldAdd(Init->AllyFields, i+1, ALLY_NUM);
            
            return;
        }
    }
    
    for(u32 i = 0; i < Init->VisibleOrder; i++)
    {
        if(commandID == Init->Order[i].Remove->id)
        {
            if(State.inBattle == FALSE) { return; }
            
            //TODO: When Removing the last added entry, it's going to fuck up the names, because
            //      It will copy from the name in the mob/ally list from itself???
            //      
            //      BUT ONLY IF THERE WERE MULTIPLE ADD/REMOVE ALREADY HAPPENING!
            //      IT'S A PROBLEM WITH THE ID SYSTEM REUSING IDs!
            if(Init->Order[i].isMob == TRUE)
            {
                u32 mobId = Init->Order[i].fieldId;
                
                InitField *toRemove = getInitById(Init->MobFields, Init->VisibleMobs, mobId);
                if(toRemove == 0x0) { /*TODO: Logging */ Assert(FALSE); }
                
                char name[32] = {};
                Edit_GetText(Init->MobFields[Init->VisibleMobs - 1].Name->box, name, 32);
                Edit_SetText(toRemove->Name->box, name);
                
                char box[8] = {};
                Edit_GetText(Init->MobFields[Init->VisibleMobs - 1].Bonus->box, box, 8);
                Edit_SetText(toRemove->Bonus->box, box);
                
                char final[8] = {};
                Edit_GetText(Init->MobFields[Init->VisibleMobs - 1].Final->box, final, 8);
                Edit_SetText(toRemove->Final->box, final);
                
                toRemove->id = Init->MobFields[Init->VisibleMobs - 1].id;
                
                HideInitField(&Init->MobFields[Init->VisibleMobs - 1], 1);
                HideInitFieldAdd(Init->MobFields, Init->VisibleMobs, MOB_NUM);
                ShowInitFieldAdd(Init->MobFields, Init->VisibleMobs-1, MOB_NUM);
                
                Init->VisibleMobs -= 1;
            }
            else if(Init->Order[i].isParty == TRUE)
            {
                //NOTE: Probably just do nothing?
            }
            else
            {
                u32 allyId = Init->Order[i].fieldId;
                
                InitField *toRemove = getInitById(Init->AllyFields, Init->VisibleAllies, allyId);
                if(toRemove == 0x0) { /*TODO: Logging */ Assert(FALSE); }
                
                char name[32] = {};
                Edit_GetText(Init->AllyFields[Init->VisibleAllies - 1].Name->box, name, 32);
                Edit_SetText(toRemove->Name->box, name);
                
                char box[8] = {};
                Edit_GetText(Init->AllyFields[Init->VisibleAllies - 1].Bonus->box, box, 32);
                Edit_SetText(toRemove->Bonus->box, box);
                
                char final[8] = {};
                Edit_GetText(Init->AllyFields[Init->VisibleAllies - 1].Final->box, final, 32);
                Edit_SetText(toRemove->Final->box, final);
                
                toRemove->id = Init->AllyFields[Init->VisibleAllies - 1].id;
                
                HideInitField(&Init->AllyFields[Init->VisibleAllies - 1], 1);
                HideInitFieldAdd(Init->AllyFields, Init->VisibleAllies, ALLY_NUM);
                ShowInitFieldAdd(Init->AllyFields, Init->VisibleAllies-1, ALLY_NUM);
                
                Init->VisibleAllies -= 1;
            }
            
            //NOTE: Move everything that is below the removed up 1.
            if(i != (Init->VisibleOrder - 1)) 
            {
                for(u32 j = i + 1; j < Init->VisibleOrder; j++)
                {
                    char v[32] = {};
                    u32 len = Edit_GetText(Init->Order[j].Field->box, v, 32);
                    Edit_SetText(Init->Order[j-1].Field->box, v);
                    
                    Init->Order[j-1].fieldId = Init->Order[j].fieldId;
                    Init->Order[j-1].isMob   = Init->Order[j].isMob;
                    Init->Order[j-1].isParty = Init->Order[j].isParty;
                }
            }
            
            Edit_SetText(Init->Order[Init->VisibleOrder - 1].Field->box, "");
            HideOrder(Init->Order + (Init->VisibleOrder - 1), 1);
            
            Init->turnsInRound -= 1;
            Init->VisibleOrder -= 1;
            if(Init->currIdx >= i) { Init->currIdx -= 1; }
            
            //NOTE:TODO: Should I return here?
        }
    }
    
}