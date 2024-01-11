struct CachedPageEntry
{
    s32 pageIndex   = -1;
    s32 talentIndex = -1;
    s32 orderID     = -1;
    
    //TODO: This feels stupid. It should be moved to a separate cached talent entry in the main app
    CachedTalentEntry *talentPage;
    
    b32 acError     = FALSE;
    b32 meleeError  = FALSE;
    b32 rangedError = FALSE;
    
    //Ability scores of the page without any modifications applied.
    s32 origAS[AS_COUNT];
    
    //Ability scores after modifications (status effects, archetypes)
    s32 modAS[AS_COUNT];
    
    utf32 origin;
    utf32 shortDesc;
    utf32 AC;
    utf32 HP; utf32 totHP; s32 hitDice;
    utf32 ST;
    utf32 RD;
    utf32 RI;
    utf32 defensiveCapacity;
    utf32 melee;
    utf32 ranged;
    utf32 specialAttacks;
    utf32 psych;
    utf32 magics;
    utf32 spells;
    utf32 tactics_before;
    utf32 tactics_during;
    utf32 tactics_stats;
    utf32 skills;
    utf32 racialMods;
    utf32 spec_qual;
    utf32 given_equip;
    utf32 properties;
    utf32 boons;
    utf32 specials;
    utf32 org;
    utf32 treasure;
    utf32 desc;
    utf32 source;
    
    utf32 name;
    utf32 gs;
    utf32 pe;
    utf32 alignment;
    utf32 type;
    utf32 subtype;
    utf32 archetype;
    utf32 size;
    utf32 initiative;
    utf32 senses;
    utf32 perception;
    utf32 aura;
    utf32 immunities;
    utf32 resistances; //TODO: Parse this cooler in hyperGol. Can make it in a single u32 I think.
    utf32 weaknesses;
    utf32 speed;
    utf32 space;
    utf32 reach;
    utf32 STR;
    utf32 DEX;
    utf32 CON;
    utf32 INT;
    utf32 WIS;
    utf32 CHA;
    utf32 BAB;
    utf32 BMC;
    utf32 DMC;
    utf32 talents[24]; s32 talentEntry[24]; //NOTE: Original talent entries to open the talent page.
    utf32 languages;
    utf32 environment;
};

const u32 PAREN_BIT_U32 = 0x40000000;
const u16 PAREN_BIT_U16 = 0x4000;

const u32 INTERN_BIT_U32 = 0x80000000;
const u16 INTERN_BIT_U16 = 0x8000;

struct NPCPageEntry
{
    u64 HP;
    
    u32 origin;
    u32 shortDesc;
    u32 AC;
    u32 ST;
    u32 RD;
    u32 RI;
    u32 defensiveCapacity;
    u32 melee;
    u32 ranged;
    u32 specialAttacks;
    u32 psych;
    u32 magics;
    u32 spells;
    u32 tactics[3];
    u32 skills[24];
    u32 talents[24];
    u32 racialMods;
    u32 spec_qual;
    u32 given_equip;
    u32 properties;
    u32 boons;
    u32 specials[24];
    u32 desc;
    u32 source;
    u32 name;
    
    u16 gs;
    u16 alignment;
    u16 type;
    u16 subtype[8];
    u16 archetype[4];
    u16 size;
    u16 initiative;
    u16 senses[8];
    u16 perception;
    u16 aura;
    u16 immunities[16];
    u16 resistances[16];
    u16 weaknesses[16];
    u16 speed;
    u16 space;
    u16 reach;
    u16 STR;
    u16 DEX;
    u16 CON;
    u16 INT;
    u16 WIS;
    u16 CHA;
    u16 BAB;
    u16 BMC;
    u16 DMC;
    u16 languages[24];
};

struct PageEntry
{
    u64 HP;                //
    
    u32 origin;            //
    u32 shortDesc;         //
    u32 AC;                //
    u32 ST;                //
    u32 RD;                //
    u32 RI;                //
    u32 defensiveCapacity; //
    u32 melee;             //
    u32 ranged;            //
    u32 specialAttacks;    //
    u32 psych;             //
    u32 magics;            //
    u32 spells;            //
    u32 skills[24];        //
    u32 talents[24];       //
    u32 racialMods;        //
    u32 spec_qual;         //
    u32 specials[24];      //
    u32 org;               //
    u32 treasure;          //
    u32 desc;              //
    u32 source;            //
    u32 name;              //
    
    u16 gs;                //
    u16 alignment;         //
    u16 type;              //
    u16 subtype[8];        //
    u16 archetype[4];      //
    u16 size;              //
    u16 initiative;        //
    u16 senses[8];         //
    u16 perception;        //
    u16 aura;              //
    u16 immunities[16];    //
    u16 resistances[16];   //
    u16 weaknesses[16];    //
    u16 speed;             //
    u16 space;             //
    u16 reach;             //
    u16 STR;               //
    u16 DEX;               //
    u16 CON;               //
    u16 INT;               //
    u16 WIS;               //
    u16 CHA;               //
    u16 BAB;               //
    u16 BMC;               //
    u16 DMC;               //
    u16 languages[24];     //
    u16 environment;       //600
};

struct Codex
{
    buffer names;
    buffer types;
    buffer subtypes;
    
    buffer generalStrings;
    buffer numericValues;
    buffer archetypes;
    buffer sizes;
    buffer senses;
    buffer auras;
    buffer immunities;
    buffer resistances;
    buffer weaknesses;
    buffer specialAttacks;
    buffer spells;
    buffer talents;
    buffer skills;
    buffer languages;
    buffer environment;
    buffer specials;
    
    buffer talentsModule;
    
    //TODO: Change these to FixedArray
    Array<PageEntry>    pages;
    Array<NPCPageEntry> npcPages;
    Array<TalentEntry>  talentPages;
};

struct Compendium
{
    Codex codex;
    
    UIButton   addEnemy;
    UIButton   addAlly;
    
    ArchetypeInfo arch;
    StaticArray<ArchetypeDiff, MAX_CONCURRENT_ARCHETYPES> appliedArchetypes;
    
    UITextBox  searchBarNameMobs;
    UITextBox  searchBarGSMobs;
    UITextBox  searchBarTypeMobs;
    
    UITextBox  searchBarNameNPCs;
    UITextBox  searchBarGSNPCs;
    UITextBox  searchBarTypeNPCs;
    
    b32        isViewingPage;
    s32        pageIndex = -1;
    
    b32        isViewingMobTable;
    Array<u16> viewIndices;
    
    b32        isViewingNPCTable;
    Array<u16> npcViewIndices;
    
    b32        isViewingTalentPage;
    s32        talentIndex;
};

Compendium         compendium     = {};
CachedPageEntry    cachedPage     = {};
UIScrollableRegion pageScroll     = {};
UIScrollableRegion tableScroll    = {};
UIScrollableRegion npcTableScroll = {};

//NOTE: Used in Init.cpp
CachedPageEntry mainCachedPage   = {};
b32 mainCachedPageNeedsReCaching = FALSE;

const s32 NPC_PAGE_INDEX_OFFSET = 5000;

//NOTE: Kinda hacky but okay.
s32 internal_newToOldMap[] = { 
    -5, -5, -4, -4, -3, -3, -2, -2, -1, -1,
    0, 0, 1, 1, 2, 2, 3, 3, 4, 4,
    5, 5, 6, 6, 7, 7, 8, 8, 9, 9,
    10, 10, 11, 11, 12, 12, 13, 13, 14, 14,
    15, 15, 16, 16, 17, 17, 18, 18, 19, 19,
    20, 20, 21, 21, 22, 22, 23, 23, 24, 24
};
s32 *newToOldMap = internal_newToOldMap + 10;

void CachePage(PageEntry, s32, CachedPageEntry *, Status *);
void CachePage(NPCPageEntry, s32, CachedPageEntry *, Status *);
void GetPageEntryAndCache(s32 compendiumIdx, s32 ordID, CachedPageEntry *page, 
                          Status *status = NULL)
{
    if(compendiumIdx < NPC_PAGE_INDEX_OFFSET)
    { 
        PageEntry pEntry = compendium.codex.pages[compendiumIdx];
        CachePage(pEntry, compendiumIdx, page, status);
    }
    else
    { 
        NPCPageEntry pEntry = compendium.codex.npcPages[compendiumIdx - NPC_PAGE_INDEX_OFFSET];
        CachePage(pEntry, compendiumIdx, page, status);
    }
    
    page->orderID = ordID;
}

b32 CompendiumOpenMonsterTable(UIContext *c, void *userData)
{
    compendium.isViewingMobTable   = TRUE;
    compendium.isViewingNPCTable   = FALSE;
    compendium.isViewingPage       = FALSE;
    compendium.isViewingTalentPage = FALSE;
    compendium.pageIndex           = -1;
    compendium.talentIndex         = -1;
    cachedPage.talentIndex         = -1;
    
    ls_staticArrayClear(&compendium.appliedArchetypes);
    
    return FALSE;
}

b32 CompendiumOpenNPCTable(UIContext *c, void *userData)
{
    compendium.isViewingNPCTable   = TRUE;
    compendium.isViewingMobTable   = FALSE;
    compendium.isViewingPage       = FALSE;
    compendium.isViewingTalentPage = FALSE;
    compendium.pageIndex           = -1;
    compendium.talentIndex         = -1;
    cachedPage.talentIndex         = -1;
    
    ls_staticArrayClear(&compendium.appliedArchetypes);
    
    return FALSE;
}

utf32 CompendiumGetGSEntryFromSet(u16 gsEntry)
{
    if(gsEntry == GS_SENTINEL_VALUE) { return U""_W; }
    
    u16 gsBase = gsEntry & 0x003F;
    s32 indexInGSSet = gsBase;
    
    u16 rmBase = 999;
    if((gsEntry & GS_RM_VALUE_BIT) != 0)
    {
        rmBase = (gsEntry & 0x0FC0) >> GS_RM_BIT_OFFSET;
        indexInGSSet += (rmBase * rmIncreaseStride);
    }
    
    AssertMsgF((indexInGSSet >= 0) && (indexInGSSet < gsSetCount),
               "Invalid Index (%d) for GS (%d) RM (%d) when Applying Archetype\n", indexInGSSet, gsBase, rmBase);
    if((indexInGSSet < 0) || (indexInGSSet >= gsSetCount)) { return U"NOT_FOUND"_W; }
    
    return gsSet[indexInGSSet];
}

#if 0
void CompendiumOpenTalentPageView()
{
    compendium.isViewingPage       = TRUE;
    compendium.isViewingNPCTable   = FALSE;
    compendium.isViewingMobTable   = FALSE;
    compendium.isViewingTalentPage = FALSE;
    compendium.pageIndex           = cachedPage.pageIndex;
    compendium.talentIndex         = -1;
}
#endif

enum SearchKind
{
    SEARCH_NAME,
    SEARCH_GS,
    SEARCH_TYPE,
};

struct CompendiumSearchData
{ 
    UITextBox *searchBar;
    buffer *searchBuffer;
    SearchKind kind;
};

u16 findNeedleAndFillIndexBuffer(utf8 needle, u16 *indexBuffer, buffer *buf, u32 buffSize)
{
    u8 dataBuffer[128] = {};
    utf8 toMatchLower = { dataBuffer, 0, 0, 128 };
    
    buf->cursor = 4;
    
    u16 nibCount = 0;
    while(buf->cursor < buf->size)
    {
        if(nibCount > buffSize)
        { AssertMsg(FALSE, "Index Buffer when searching is not large enough\n"); return nibCount; }
        
        s32 strByteLen = ls_bufferPeekWord(buf);
        u8 *data       = (u8 *)buf->data + buf->cursor + 2;
        
        utf8 toMatch   = ls_utf8Constant(data, strByteLen);
        ls_utf8ToLower(&toMatchLower, toMatch);
        
        if(ls_utf8Contains(toMatchLower, needle))
        {
            indexBuffer[nibCount] = buf->cursor;
            nibCount += 1;
        }
        
        ls_bufferReadSkip(buf, strByteLen + 2);
    }
    
    return nibCount;
}

b32 CompendiumSearchFunctionMobs(UIContext *c, void *userData)
{
    ls_arenaUse(compTempArena);
    
    CompendiumSearchData *searchData = (CompendiumSearchData *)userData;
    
    //NOTE: Reset the scrollbar when searching
    tableScroll.deltaY = 0;
    
    //NOTE: The limit under which we reset the view and stop searching
    s32 minCharLimit = 2;
    if(searchData->kind == SEARCH_GS) { minCharLimit = 1; }
    
    if(searchData->searchBar->text.len < minCharLimit)
    { 
        tableScroll.minY = -((compendium.codex.pages.count-30) * 19);
        ls_arrayClear(&compendium.viewIndices);
        for(u16 i = 0; i < compendium.viewIndices.cap; i++)
        { ls_arrayAppend(&compendium.viewIndices, i); }
        
        return FALSE;
    }
    
    //NOTE:Iterate over the name buffer to find all names which exactly contain the substring needle
    utf8 needle = ls_utf8FromUTF32(searchData->searchBar->text);
    
    u8 dataBuffer[128] = {};
    utf8 needleLower = { dataBuffer, 0, 0, 128 };
    
    ls_utf8ToLower(&needleLower, needle);
    
    u16 indexBuffer[4096] = {};
    u16 nibCount = findNeedleAndFillIndexBuffer(needleLower, indexBuffer, searchData->searchBuffer, 4096);
    
    //TODO: Put the needle on the stack
    ls_utf8Free(&needle);
    
    if(nibCount > 0)
    {
        ls_arrayClear(&compendium.viewIndices);
        
        //NOTE: Now that we have a buffer of all matching name indices, let's search through the actual pages
        b32 shouldStop = FALSE;
        for(u16 i = 0; i < compendium.codex.pages.count; i++)
        {
            if(nibCount == 0)      { break; }
            if(shouldStop == TRUE) { break; }
            
            switch(searchData->kind)
            {
                case SEARCH_NAME:
                { 
                    u16 indexToMatch = compendium.codex.pages[i].name;
                    
                    for(u32 j = 0; j < nibCount; j++)
                    {
                        if(indexBuffer[j] == indexToMatch)
                        {
                            ls_arrayAppend(&compendium.viewIndices, i);
                            
                            indexBuffer[j] = indexBuffer[nibCount-1];
                            nibCount -= 1;
                            break;
                        }
                    }
                    
                } break;
                
                case SEARCH_GS:
                {
                    u16 indexToMatch = compendium.codex.pages[i].gs;
                    
                    //NOTE: Quick exit since GS only increases. *SHOULD* not create problems?
                    if(indexToMatch > indexBuffer[nibCount-1]) { shouldStop = TRUE; }
                    
                    for(u32 j = 0; j < nibCount; j++)
                    {
                        if(indexBuffer[j] == indexToMatch)
                        {
                            ls_arrayAppend(&compendium.viewIndices, i);
                            break;
                        }
                    }
                } break;
                
                case SEARCH_TYPE:
                {
                    u16 indexToMatch = compendium.codex.pages[i].type;
                    
                    for(u32 j = 0; j < nibCount; j++)
                    {
                        if(indexBuffer[j] == indexToMatch)
                        {
                            ls_arrayAppend(&compendium.viewIndices, i);
                            break;
                        }
                    }
                } break;
            }
        }
    }
    
    //NOTE: Adjust scrollbar height to new monster table count.
    if(compendium.viewIndices.count > 30) { tableScroll.minY = -((compendium.viewIndices.count-30) * 19); }
    else                                  { tableScroll.minY = -1; }
    
    
    ls_arenaUse(globalArena);
    
    return FALSE;
}

b32 CompendiumSearchFunctionNPCs(UIContext *c, void *userData)
{
    ls_arenaUse(compTempArena);
    
    CompendiumSearchData *searchData = (CompendiumSearchData *)userData;
    
    //NOTE: Reset the scrollbar when searching
    npcTableScroll.deltaY = 0;
    
    //NOTE: The limit under which we reset the view and stop searching
    s32 minCharLimit = 2;
    if(searchData->kind == SEARCH_GS) { minCharLimit = 1; }
    
    if(searchData->searchBar->text.len < minCharLimit)
    { 
        npcTableScroll.minY = -((compendium.codex.npcPages.count-30) * 19);
        ls_arrayClear(&compendium.npcViewIndices);
        for(u16 i = 0; i < compendium.npcViewIndices.cap; i++)
        { ls_arrayAppend(&compendium.npcViewIndices, i); }
        
        return FALSE;
    }
    
    //NOTE:Iterate over the name buffer to find all names which exactly contain the substring needle
    utf8 needle = ls_utf8FromUTF32(searchData->searchBar->text);
    
    u8 dataBuffer[128] = {};
    utf8 needleLower = { dataBuffer, 0, 0, 128 };
    
    ls_utf8ToLower(&needleLower, needle);
    
    u16 indexBuffer[4096] = {};
    u16 nibCount = findNeedleAndFillIndexBuffer(needleLower, indexBuffer, searchData->searchBuffer, 4096);
    
    //TODO: Put the needle on the stack
    ls_utf8Free(&needle);
    
    if(nibCount > 0)
    {
        ls_arrayClear(&compendium.npcViewIndices);
        
        //NOTE: Now that we have a buffer of all matching name indices, let's search through the actual pages
        b32 shouldStop = FALSE;
        for(u16 i = 0; i < compendium.codex.npcPages.count; i++)
        {
            if(nibCount == 0)      { break; }
            if(shouldStop == TRUE) { break; }
            
            switch(searchData->kind)
            {
                case SEARCH_NAME:
                {
                    u16 indexToMatch = compendium.codex.npcPages[i].name;
                    
                    for(u32 j = 0; j < nibCount; j++)
                    {
                        if(indexBuffer[j] == indexToMatch)
                        {
                            ls_arrayAppend(&compendium.npcViewIndices, i);
                            
                            indexBuffer[j] = indexBuffer[nibCount-1];
                            nibCount -= 1;
                            break;
                        }
                    }
                } break;
                
                case SEARCH_GS:
                {
                    u16 indexToMatch = compendium.codex.npcPages[i].gs;
                    
                    //NOTE: Quick exit since GS only increases. *SHOULD* not create problems?
                    if(indexToMatch > indexBuffer[nibCount-1]) { shouldStop = TRUE; }
                    
                    for(u32 j = 0; j < nibCount; j++)
                    {
                        if(indexBuffer[j] == indexToMatch)
                        {
                            ls_arrayAppend(&compendium.npcViewIndices, i);
                            break;
                        }
                    }
                } break;
                
                case SEARCH_TYPE:
                {
                    u16 indexToMatch = compendium.codex.npcPages[i].type;
                    
                    for(u32 j = 0; j < nibCount; j++)
                    {
                        if(indexBuffer[j] == indexToMatch)
                        {
                            ls_arrayAppend(&compendium.npcViewIndices, i);
                            break;
                        }
                    }
                } break;
            }
        }
    }
    
    //NOTE: Adjust scrollbar height to new table count.
    if(compendium.npcViewIndices.count > 30) { npcTableScroll.minY = -((compendium.npcViewIndices.count-30) * 19); }
    else                                     { npcTableScroll.minY = -1; }
    
    ls_arenaUse(globalArena);
    
    return FALSE;
}

//-------------------------------------------
//NOTE: Utility Dice/Bonus Finding Functions
s32 rightFindBonus(utf32 key, s32 offset, s32 min)
{
    s32 maybePlus  = ls_utf32RightFind(key, offset, '+');
    s32 maybeMinus = ls_utf32RightFind(key, offset, '-');
    
    if(maybePlus != -1 && maybePlus > min) { return maybePlus; }
    else if(maybeMinus != -1 && maybeMinus > min) { return maybeMinus; }
    else { return -1; }
};

s64 rightFindBonusEX(utf32 key, s32 offset, s32 min)
{
    s32 maybePlus  = ls_utf32RightFind(key, offset, '+');
    s32 maybeMinus = ls_utf32RightFind(key, offset, '-');
    
    s32 beginOffset = -1;
    s32 endOffset   = -1;
    if(maybePlus != -1 && maybePlus > min) { beginOffset = maybePlus; }
    else if(maybeMinus != -1 && maybeMinus > min) { beginOffset = maybeMinus; }
    else { return -1; }
    
    endOffset = beginOffset + 1; //NOTE: Skip the sign;
    
    u32 *At         = key.data + endOffset;
    s32 addedSpaces = 0;
    b32 afterValue  = FALSE;
    while (At != (key.data + key.len))
    { 
        if(At + 1  > (key.data + key.len)) { break; }
        if(endOffset > offset)             { return -1; }
        
        if(*At == ' ')
        {
            if(afterValue) { addedSpaces += 1; }
            At++; endOffset++; continue;
        }
        
        if(ls_utf32IsNumber(*At))
        { 
            if(afterValue == FALSE) { afterValue = TRUE; }
            At++; endOffset++; continue;
        }
        
        break;
    }
    
    return ((s64)beginOffset << 32 | endOffset);
};

s64 leftFindBonus(utf32 key, s32 offset, s32 max)
{
    if(offset < 0)    { return -1; }
    if(offset >= max) { return -1; }
    
    s32 maybePlus  = ls_utf32LeftFind(key, offset, '+');
    s32 maybeMinus = ls_utf32LeftFind(key, offset, '-');
    
    s32 beginOffset = -1;
    s32 endOffset   = -1;
    if(maybePlus != -1 && maybePlus < max) { beginOffset = maybePlus; }
    else if(maybeMinus != -1 && maybeMinus < max) { beginOffset = maybeMinus; }
    else { return -1; }
    
    endOffset       = beginOffset+1; //NOTE: Skip the sign
    
    u32 *At         = key.data + endOffset;
    s32 addedSpaces = 0;
    b32 afterValue  = FALSE;
    while (At != (key.data + key.len))
    { 
        if(At + 1  > (key.data + key.len)) { break; }
        if(endOffset > max)                  { return -1; }
        
        if(*At == ' ')
        {
            if(afterValue) { addedSpaces += 1; }
            At++; endOffset++; continue;
        }
        
        if(ls_utf32IsNumber(*At))
        { 
            if(afterValue == FALSE) { afterValue = TRUE; }
            At++; endOffset++; continue;
        }
        
        break;
    }
    
    return ((s64)beginOffset << 32 | endOffset);
};

s64 leftFindDiceThrow(utf32 key, s32 offset, s32 max)
{
    s32 diceIdx = ls_utf32LeftFind(key, offset+1, 'd');
    if(diceIdx == -1) { return -1; }
    
    do
    {
        if(diceIdx > max) { return -1; }
        
        if((ls_utf32IsNumber(key.data[diceIdx-1]) == TRUE) &&
           (ls_utf32IsNumber(key.data[diceIdx+1]) == TRUE))
        { 
            s32 end = ls_utf32LeftFindNotNumber(key, diceIdx+1);
            //NOTE: If end == -1 it means it never found a NON number character.
            //      So the number goes until the end of the string and end == key.len
            if(end == -1) { end = key.len; }
            
            return ((s64)diceIdx << 32) | end;
        }
        
        diceIdx = ls_utf32LeftFind(key, diceIdx+1, 'd'); //NOTE: The +1 is to avoid infinite loops
        
    } while(diceIdx != -1);
    
    return -1;
};

s64 leftFindDiceBonus(utf32 s, s32 off, s32 max)
{
    //NOTE: This function expects to start from a valid dice throw (i.e. 1d3 ) then it
    //      first looks for '+' or '-', without any non numeric characters in between.
    //      If it doesn't find it before other non-numeric, it means the bonus doesn't exist
    //      EXCEPT FOR WHITESPACE, WHICH IS IGNORED!
    
    AssertMsg(s.data, "Source data is null.\n");
    AssertMsg(off >= 0, "Negative offset.\n"); 
    
    if(s.data == NULL) { return -1; }
    if(s.len  == 0)    { return -1; }
    if(off >= s.len)   { return -1; }
    if(off < 0)        { return -1; }
    
    s32 beginIdx = -1;
    {
        u32 *At    = s.data + off;
        s32 offset = off;
        while (At != (s.data + s.len))
        { 
            if(At + 1 > (s.data + s.len)) { break; }
            if(offset > max)              { return -1; }
            
            if(*At == '+' || *At == '-') { beginIdx = offset; break; }
            if(*At == ' ' || ls_utf32IsNumber(*At)) { At++; offset++; continue; }
            break;
        }
        
        if(beginIdx == -1) return -1;
    }
    
    s32 endIdx = -1;
    {
        u32 *At         = s.data + beginIdx + 1; //Skip the +/-
        s32 offset      = beginIdx + 1;
        s32 addedSpaces = 0;
        b32 afterValue  = FALSE;
        while (At != (s.data + s.len))
        { 
            if(At + 1 > (s.data + s.len)) { break; }
            if(offset > max)              { return -1; }
            
            if(*At == ' ')
            {
                if(afterValue) { addedSpaces += 1; }
                At++; offset++; continue;
            }
            
            if(ls_utf32IsNumber(*At))
            { 
                if(afterValue == FALSE) { afterValue = TRUE; }
                At++; offset++; continue;
            }
            
            //NOTE: Not a valid bonus if it's actually another dice throw!
            if(*At == 'd') //NOTE: Already SUS
            {
                //TODO: Is this enough? (1d3+ 22 d 7) ????
                if((At+1 < (s.data + s.len)) && ls_utf32IsNumber(*(At+1))) { return -1; }
            }
            
            break;
        }
        
        endIdx = offset - addedSpaces;
    }
    
    return ((s64)beginIdx << 32 | endIdx);
};

b32 CompendiumPageHasTalent(CachedPageEntry *page, utf32 needle)
{
    s32 talentIndex = 0;
    while(page->talents[talentIndex].len)
    {
        if(ls_utf32LeftFind(page->talents[talentIndex], needle) != -1) { return TRUE; }
        talentIndex += 1;
    }
    
    return FALSE;
}

s32 CompendiumPageMithicalRank(utf32 gs)
{
    s32 rmIdx = 0;
    for(s32 i = rmSetCount-1; i >= 0; i--)
    { if(ls_utf32LeftFind(gs, rmSet[i]) != -1) { return i+1; } }
    
    return 0;
}

//
//-------------------------------------------


//NOTE: I'm pretty sure Deviation doesn't matter, because it's a non-stacking bonus unaffected by other things
//      in AC. Since it's not affacted by STR or DEX (Which are the quanities changing) I can ignore it.
//      Incorporeal creatures get adjusted for free
void CalculateAndCacheAC(utf32 AC, CachedPageEntry *cachedPage, b32 isNPC, Status *status = NULL)
{
    cachedPage->acError = FALSE;
    
    s32 acExprBeginIdx = ls_utf32LeftFind(AC, (u32)'(');
    s32 acExprEndIdx   = ls_utf32LeftFind(AC, (u32)')');
    
    if((acExprBeginIdx == -1) || (acExprEndIdx == -1))
    { 
        cachedPage->acError = TRUE;
        ls_utf32Set(&cachedPage->AC, AC);
        return;
    }
    
    s32 acExprBegin = acExprBeginIdx + 1;
    s32 acExprLen   = acExprEndIdx - acExprBegin;
    utf32 acExpr    = { AC.data + acExprBegin, acExprLen, acExprLen };
    
    //TODO: Golarion has "armor" and "shield" with small letters... fuck them
    s32 armorBonusIdx  = ls_utf32LeftFind(acExpr, ls_utf32Constant(U"Armatura"));
    if(armorBonusIdx == -1) { armorBonusIdx = ls_utf32LeftFind(acExpr, ls_utf32Constant(U"armatura")); }
    
    s32 shieldBonusIdx = ls_utf32LeftFind(acExpr, ls_utf32Constant(U"Scudo"));
    if(shieldBonusIdx == -1) { shieldBonusIdx = ls_utf32LeftFind(acExpr, ls_utf32Constant(U"scudo")); }
    
    s32 natArmorBonusIdx = ls_utf32LeftFind(acExpr, ls_utf32Constant(U"Naturale"));
    if(natArmorBonusIdx == -1) { natArmorBonusIdx = ls_utf32LeftFind(acExpr, ls_utf32Constant(U"naturale")); }
    
    s32 dexBonusNew = cachedPage->modAS[AS_DEX] - 10;
    s32 dexBonusOld = newToOldMap[cachedPage->origAS[AS_DEX]];
    
    s32 strBonusNew = cachedPage->modAS[AS_STR] - 10;
    s32 strBonusOld = newToOldMap[cachedPage->origAS[AS_STR]];
    
    s32 conBonusNew = cachedPage->modAS[AS_CON] - 10;
    s32 conBonusOld = newToOldMap[cachedPage->origAS[AS_CON] - 10];
    
    s32 newMaxDex      = 999;
    s32 newArmorBonus  = -1;
    s32 newShieldBonus = -1;
    s32 oldArmorBonus  = -1;
    s32 oldShieldBonus = -1;
    
    //TODO: Clear Modifiers to Armor and Shields (Like "Chiodato")
    if(armorBonusIdx != -1)
    {
        Armor *found = NULL;
        s32    index = -1;
        if(isNPC == TRUE)
        {
            for(u32 i = 0; i < armorTableCount; i++)
            {
                Armor *armor = armorTable + i;
                if(ls_utf32LeftFind(cachedPage->properties, armor->name) != -1)
                { found = armor; index = i; break; }
                
                if(ls_utf32LeftFind(cachedPage->given_equip, armor->name) != -1)
                { found = armor; index = i; break; }
            }
        }
        else
        {
            for(u32 i = 0; i < armorTableCount; i++)
            {
                Armor *armor = armorTable + i;
                if(ls_utf32LeftFind(cachedPage->treasure, armor->name) != -1)
                { found = armor; index = i; break; }
            }
        }
        
        if(found)
        {
            if(found->dexMax != -1)
            {
                s32 candidateMaxDex = found->dexMax + s32((conBonusNew + strBonusNew) / 2);
                newMaxDex           = ls_min(newMaxDex, candidateMaxDex);
            }
            oldArmorBonus = found->armorBonus;
            newArmorBonus = armorTablePrana[index].armorBonus;
        }
        else
        {
            //NOTE: Look for magic items giving an armor bonus, like "Bracciali dell'Armatura"
            s32 braccialiIdx = ls_utf32LeftFind(cachedPage->properties, ls_utf32Constant(U"Bracciali dell'Armatura"));
            
            /*TODO: Do I need this?
                    if(braccialiIdx == -1)
                    { braccialiIdx = ls_utf32LeftFind(cachedPage->given_equip, U"Bracciali dell'Armatura"); }
                    */
            
            if(braccialiIdx != -1)
            {
                s32 nextComma = ls_utf32LeftFind(cachedPage->properties, braccialiIdx, ls_utf32Constant(U", "));
                
                if(nextComma != -1) //TODO: What about if we are at the end of the string?
                {
                    s64 braceBonusRange = leftFindBonus(cachedPage->properties, braccialiIdx, nextComma);
                    s32 braceBonusBegin = braceBonusRange >> 32;
                    s32 braceBonusEnd   = (s32)braceBonusRange;
                    
                    newArmorBonus = ls_utf32ToIntIgnoreWhitespace({cachedPage->properties.data + braceBonusBegin, braceBonusEnd - braceBonusBegin, braceBonusEnd - braceBonusBegin});
                    oldArmorBonus = newArmorBonus;
                }
                else
                {
                    cachedPage->acError = TRUE;
                    ls_utf32Set(&cachedPage->AC, AC);
                    return;
                }
            }
            else
            {
                cachedPage->acError = TRUE;
                ls_utf32Set(&cachedPage->AC, AC);
                return;
            }
        }
    }
    
    if(shieldBonusIdx != -1)
    {
        //NOTE: Look for the shield in the treasure line.
        Armor *found = NULL;
        s32    index = -1;
        
        if(isNPC == TRUE)
        {
            for(u32 i = 0; i < shieldTableCount; i++)
            {
                Armor *shield = shieldTable + i;
                if(ls_utf32LeftFind(cachedPage->properties, shield->name) != -1)
                { found = shield; index = i; break; }
                
                if(ls_utf32LeftFind(cachedPage->given_equip, shield->name) != -1)
                { found = shield; index = i; break; }
            }
        }
        else
        {
            for(u32 i = 0; i < shieldTableCount; i++)
            {
                Armor *shield = shieldTable + i;
                if(ls_utf32LeftFind(cachedPage->treasure, shield->name) != -1)
                { found = shield; index = i; break; }
            }
        }
        
        if(found)
        {
            if(found->dexMax != -1)
            {
                s32 candidateMaxDex = found->dexMax + s32((conBonusNew + strBonusNew) / 2);
                newMaxDex           = ls_min(newMaxDex, candidateMaxDex);
            }
            oldShieldBonus = found->armorBonus;
            newShieldBonus = shieldTablePrana[index].armorBonus;
        }
        else
        {
            cachedPage->acError = TRUE;
            ls_utf32Set(&cachedPage->AC, AC);
            return;
        }
    }
    
    s32 oldNatArmor = 0;
    s32 newNatArmor = 0;
    
    if(natArmorBonusIdx != -1)
    {
        s64 natBonusRange    = rightFindBonusEX(acExpr, natArmorBonusIdx, -1);
        s32 natBonusBegin    = natBonusRange >> 32;
        s32 natBonusEnd      = (s32)natBonusRange;
        
        if(natBonusRange == -1)
        {
            cachedPage->acError = TRUE;
            ls_utf32Set(&cachedPage->AC, AC);
            LogMsg(FALSE, "Can't find bonus in Natural Armor\n");
            return;
        }
        
        s32 rangeLen         = natBonusEnd - natBonusBegin;
        utf32 natBonusString = { acExpr.data + natBonusBegin, rangeLen, rangeLen };
        oldNatArmor          = ls_utf32ToIntIgnoreWhitespace(natBonusString);
        newNatArmor          = (f32)oldNatArmor * 1.34f;
    }
    
    //TODO: I don't really like these hardcoded offsets, would prefer to have a LeftFindNumeric() function
    s32 firstValEnd     = ls_utf32LeftFind(AC, (u32)',');
    s32 secondValBegin  = firstValEnd + 11;
    s32 secondValEnd    = ls_utf32LeftFind(AC, secondValBegin, (u32)',');
    s32 secondValLen    = secondValEnd - secondValBegin;
    s32 thirdValBegin   = secondValEnd + 14;
    s32 semiToken       = ls_utf32LeftFind(AC, thirdValBegin, (u32)';');
    s32 parenToken      = ls_utf32LeftFind(AC, thirdValBegin, (u32)'(');
    s32 spaceToken      = ls_utf32LeftFind(AC, thirdValBegin, (u32)' ');
    
    //TODO: I don't really like these hardcoded offsets, would prefer to have a LeftFindNumeric() function
    s32 thirdValEnd = AC.len - 1;
    if(semiToken != -1)
    {
        if(parenToken != -1)
        {
            if(semiToken < parenToken) { thirdValEnd = semiToken; }
            else                       { thirdValEnd = parenToken - 1; }
        }
        else if(spaceToken != -1)
        {
            if(semiToken < spaceToken) { thirdValEnd = semiToken; }
            else                       { thirdValEnd = spaceToken; }
        }
        else
        {
            thirdValEnd = semiToken - 1;
        }
    }
    else
    {
        if(parenToken != -1)
        {
            if(spaceToken != -1)
            {
                if(parenToken < spaceToken) { thirdValEnd = parenToken; }
                else                        { thirdValEnd = spaceToken; }
            }
            else
            {
                thirdValEnd = parenToken;
            }
        }
        else
        {
            if(spaceToken != -1) { thirdValEnd = spaceToken; }
        }
    }
    s32 thirdValLen = thirdValEnd - thirdValBegin;
    
    if((firstValEnd == -1) || (secondValEnd == -1) || (thirdValEnd == -1)
       || (secondValBegin >= AC.len) || (thirdValBegin >= AC.len))
    {
        cachedPage->acError = TRUE;
        ls_utf32Set(&cachedPage->AC, AC);
        return;
    }
    
    s32 acDiff[AC_TYPES_COUNT] = {};
    //NOTE: Apply Archetypes
    if(compendium.appliedArchetypes.count > 0)
    { CompendiumApplyAllArchetypeAC(acDiff); }
    
    //TODO: Dodge and other AC types
    newArmorBonus += acDiff[AC_ARMOR];
    newNatArmor   += acDiff[AC_NATURAL];
    
    
    s32 totAC   = ls_utf32ToInt({AC.data, firstValEnd, firstValEnd});
    s32 touchAC = ls_utf32ToInt({AC.data + secondValBegin, secondValLen, secondValLen});
    s32 flatAC  = ls_utf32ToInt({AC.data + thirdValBegin, thirdValLen, thirdValLen});
    
    //NOTE: Adjust the dex bonus
    s32 dexBonusToAC = ls_min(dexBonusNew, newMaxDex);
    totAC   = (totAC   - dexBonusOld) + dexBonusToAC;
    touchAC = (touchAC - dexBonusOld) + dexBonusToAC;
    
    //NOTE: Adjust the dex MALUS on being flat footed!
    if(dexBonusOld < 0)
    { flatAC  = (flatAC  - dexBonusOld) + dexBonusToAC; }
    
    //NOTE: Adjust the armor bonus
    if(armorBonusIdx != -1)
    {
        totAC  = (totAC - oldArmorBonus) + newArmorBonus;
        flatAC = (flatAC - oldArmorBonus) + newArmorBonus;
    }
    
    if(shieldBonusIdx != -1)
    {
        totAC  = (totAC - oldShieldBonus) + newShieldBonus;
        flatAC = (flatAC - oldShieldBonus) + newShieldBonus;
    }
    
    //NOTE: Adjust Natural Armor Bonus
    if(natArmorBonusIdx != -1)
    {
        totAC  = (totAC - oldNatArmor) + newNatArmor;
        flatAC = (flatAC - oldNatArmor) + newNatArmor;
    }
    
    //NOTETODO: Technically an incorporeal creature can't have nat armor bonus. Check?
    b32 isIncorporeal = (ls_utf32LeftFind(cachedPage->subtype, ls_utf32Constant(U"Incorporeo")) != -1);
    if(isIncorporeal)
    {
        s32 chaBonusNew = cachedPage->modAS[AS_CHA] - 10;
        s32 chaBonusOld = newToOldMap[cachedPage->origAS[AS_CHA] - 10];
        
        s32 chaBonusToAC     = chaBonusNew < 1 ? 1 : chaBonusNew;
        s32 chaBonusOldToAC  = chaBonusOld < 1 ? 1 : chaBonusOld;
        totAC   = (totAC - chaBonusOldToAC) + chaBonusToAC;
        flatAC  = (flatAC - chaBonusOldToAC) + chaBonusToAC;
        touchAC = (touchAC - chaBonusOldToAC) + chaBonusToAC;
    }
    
    //TODO: Maybe make it a flag?
    b32 hasSchivareProdigioso = ls_utf32LeftFind(cachedPage->defensiveCapacity, 
                                                 ls_utf32Constant(U"Schivare Prodigioso"));
    
    //NOTE: Apply status conditions if present
    if(status)
    {
        b32 hasLostDexBonus = FALSE;
        for(s32 i = 0; i < STATUS_COUNT; i++)
        {
            if(!status[i].check.isActive) { continue; }
            
            s32 dexAC = dexBonusToAC > 0 ? dexBonusToAC : 0;
            switch(status[i].type)
            {
                case STATUS_ACCECATO:
                case STATUS_ACCOVACCIATO:
                case STATUS_STORDITO:
                {
                    totAC -= 2; touchAC -= 2; flatAC -= 2;
                    if(!hasLostDexBonus) {
                        hasLostDexBonus = TRUE;
                        totAC -= dexAC; touchAC -= dexAC;
                    }
                } break;
                
                case STATUS_IMMOBILIZZATO:
                {
                    if(!hasSchivareProdigioso) { 
                        totAC -= 4; touchAC -= 4; flatAC -= 4;
                        if(!hasLostDexBonus) {
                            hasLostDexBonus = TRUE;
                            totAC -= dexAC; touchAC -= dexAC;
                        }
                    }
                } break;
                
                case STATUS_IMPREPARATO:
                {
                    if(!hasSchivareProdigioso && !hasLostDexBonus) {
                        hasLostDexBonus = TRUE;
                        totAC -= dexAC; touchAC -= dexAC;
                    }
                } break;
                
                case STATUS_PRONO:
                { //TODO
                    Assert(FALSE);
                } break;
            }
        }
    }
    
    u32 buff[32] = {};
    utf32 tmpString = { buff, 32, 32 };
    
    ls_utf32Clear(&cachedPage->AC);
    ls_utf32FromInt_t(&cachedPage->AC, totAC);
    ls_utf32Append(&cachedPage->AC, ls_utf32Constant(U", contatto "));
    ls_utf32FromInt_t(&tmpString, touchAC);
    ls_utf32Append(&cachedPage->AC, tmpString);
    ls_utf32Append(&cachedPage->AC, ls_utf32Constant(U", impreparato "));
    ls_utf32FromInt_t(&tmpString, flatAC);
    ls_utf32Append(&cachedPage->AC, tmpString);
    ls_utf32Append(&cachedPage->AC, {AC.data + thirdValEnd, AC.len - thirdValEnd, AC.len - thirdValEnd});
}

void CalculateAndCacheST(utf32 ST, CachedPageEntry *cachedPage, Status *status = NULL)
{
    s32 conBonusNew = cachedPage->modAS[AS_CON] - 10;
    s32 dexBonusNew = cachedPage->modAS[AS_DEX] - 10;
    s32 wisBonusNew = cachedPage->modAS[AS_WIS] - 10;
    s32 chaBonusNew = cachedPage->modAS[AS_CHA] - 10;
    s32 conBonusOld = newToOldMap[cachedPage->origAS[AS_CON] - 10];
    s32 dexBonusOld = newToOldMap[cachedPage->origAS[AS_DEX] - 10];
    s32 wisBonusOld = newToOldMap[cachedPage->origAS[AS_WIS] - 10];
    s32 chaBonusOld = newToOldMap[cachedPage->origAS[AS_CHA] - 10];
    
    b32 isConstruct = ls_utf32LeftFind(cachedPage->type, ls_utf32Constant(U"Costrutto")) != -1;
    if(isConstruct) { conBonusNew = 0; conBonusOld = 0; }
    
    b32 isUndead    = ls_utf32LeftFind(cachedPage->type, ls_utf32Constant(U"Non Morto")) != -1;
    
    //TODO: Make these not hardcoded like that
    s32 conSaveBegin = 7;
    s32 conSaveEnd   = ls_utf32LeftFind(ST, (u32)',');
    s32 dexSaveBegin = conSaveEnd + 11;
    s32 dexSaveEnd   = ls_utf32LeftFind(ST, dexSaveBegin, (u32)',');
    s32 wisSaveBegin = dexSaveEnd + 10;
    s32 semiToken    = ls_utf32LeftFind(ST, wisSaveBegin, (u32)';');
    s32 parenToken   = ls_utf32LeftFind(ST, wisSaveBegin, (u32)'(');
    
    s32 wisSaveEnd = semiToken - 1;
    if(semiToken != -1 && parenToken != -1 && semiToken > parenToken)
    { wisSaveEnd = parenToken - 1; }
    else if(semiToken == -1)
    {
        wisSaveEnd = parenToken - 1;
        if(parenToken == -1)
        {
            wisSaveEnd = ST.len - 1;
        }
    }
    
    if((conSaveEnd == -1) || (dexSaveEnd == -1)) { ls_utf32Set(&cachedPage->ST, ST); return; }
    
    s32 conSave = ls_utf32ToInt({ST.data + conSaveBegin, conSaveEnd - conSaveBegin, conSaveEnd - conSaveBegin});
    s32 dexSave = ls_utf32ToInt({ST.data + dexSaveBegin, dexSaveEnd - dexSaveBegin, dexSaveEnd - dexSaveBegin});
    s32 wisSave = ls_utf32ToInt({ST.data + wisSaveBegin, wisSaveEnd - wisSaveBegin+1, wisSaveEnd - wisSaveBegin+1});
    
    if(isUndead) { conSave = (conSave - chaBonusOld) + chaBonusNew; }
    else         { conSave = (conSave - conBonusOld) + conBonusNew; }
    
    dexSave = (dexSave - dexBonusOld) + dexBonusNew;
    wisSave = (wisSave - wisBonusOld) + wisBonusNew;
    
    //NOTE: Handle Status Conditions
    if(status)
    {
        for(s32 i = 0; i < STATUS_COUNT; i++)
        {
            if(!status[i].check.isActive) { continue; }
            
            switch(status[i].type)
            {
                case STATUS_INFERMO:
                case STATUS_PANICO:
                case STATUS_SPAVENTATO:
                case STATUS_SCOSSO:
                {
                    conSave -= 2;
                    dexSave -= 2;
                    wisSave -= 2;
                } break;
            }
        }
    }
    
    u32 buff[32] = {};
    utf32 tmpString = { buff, 32, 32 };
    
    ls_utf32Clear(&cachedPage->ST);
    ls_utf32Append(&cachedPage->ST, ls_utf32Constant(U"Tempra "));
    
    if(conSave >= 0) ls_utf32AppendChar(&cachedPage->ST, (u32)'+');
    
    ls_utf32FromInt_t(&tmpString, conSave);
    ls_utf32Append(&cachedPage->ST, tmpString);
    ls_utf32Clear(&tmpString);
    
    ls_utf32Append(&cachedPage->ST, ls_utf32Constant(U", Riflessi "));
    
    if(dexSave >= 0) ls_utf32AppendChar(&cachedPage->ST, (u32)'+');
    
    ls_utf32FromInt_t(&tmpString, dexSave);
    ls_utf32Append(&cachedPage->ST, tmpString);
    ls_utf32Clear(&tmpString);
    
    ls_utf32Append(&cachedPage->ST, ls_utf32Constant(U", Volont\U000000E0 "));
    
    if(wisSave >= 0) ls_utf32AppendChar(&cachedPage->ST, (u32)'+');
    
    ls_utf32FromInt_t(&tmpString, wisSave);
    ls_utf32Append(&cachedPage->ST, tmpString);
    ls_utf32Clear(&tmpString);
    
    ls_utf32AppendBuffer(&cachedPage->ST, ST.data + wisSaveEnd+1, ST.len - (wisSaveEnd+1));
}

#if 0
void CalculateAndCacheHP(utf32 hp, CachedPageEntry *cachedPage)
{
    s32 hpEndIndex  = ls_utf32LeftFind(hp, (u32)' ');
    if(hpEndIndex == -1) hpEndIndex = ls_utf32LeftFind(hp, (u32)'(');
    AssertMsg(hpEndIndex >= 0, "HP index can't be found\n");
    
    s32 hpExprBegin = ls_utf32LeftFind(hp, (u32)'(') + 1;
    s32 hpExprLen   = ls_utf32LeftFind(hp, (u32)')') - hpExprBegin;
    
    utf32 hpExpr    = {hp.data + hpExprBegin, hpExprLen, hpExprLen};
    
    s64 diceThrows[8] = {};
    
    s64 firstDiceThrow = leftFindDiceThrow(hpExpr, 0, hpExpr.len);
    AssertMsg(firstDiceThrow != -1, "No HP Dice?\n");
    
    diceThrows[0] = firstDiceThrow;
    
    s32 throwBegin = firstDiceThrow >> 32;
    s32 throwEnd   = (s32)firstDiceThrow;
    
    //NOTE: There might be multiple HP Dice because of multiple Class Levels
    s64 throwBonus = leftFindDiceBonus(hpExpr, throwBegin+1, hpExpr.len);
    s32 dIdx = 1;
    while(throwBonus == -1)
    {
        diceThrows[dIdx] = leftFindDiceThrow(hpExpr, throwBegin+1, hpExpr.len);
        if(diceThrows[dIdx] == -1) { break; } //NOTE: Means there's only dice throws, no bonus
        
        dIdx += 1;
        
        throwBegin = diceThrows[dIdx-1] >> 32;
        throwEnd   = (s32)diceThrows[dIdx-1];
        
        throwBonus = leftFindDiceBonus(hpExpr, throwBegin+1, hpExpr.len);
    }
    
    //NOTE: We should have found ALL dice throws, and the bonus if it exists.
    s32 finalHP = 0;
    s32 totalHpDice = 0;
    s32 totalHpDiceMul = 0;
    s32 currIdx = 0;
    for(s32 i = 0; i < dIdx; i++)
    {
        s32 throwD       = diceThrows[i] >> 32;
        s32 throwEnd     = (s32)diceThrows[i];
        
        utf32 dieValExpr = {hpExpr.data + currIdx, throwD - currIdx, throwD - currIdx};
        utf32 dieMulExpr = {hpExpr.data + throwD+1, throwEnd - throwD - 1, throwEnd - throwD - 1};
        s32 dieValue     = ls_utf32ToIntIgnoreWhitespace(dieValExpr);
        s32 dieMul       = ls_utf32ToIntIgnoreWhitespace(dieMulExpr);
        
        currIdx  = throwEnd;
        
        finalHP += dieValue*dieMul;
        totalHpDice += dieValue;
        totalHpDiceMul += dieMul;
    }
    
    //NOTE: Set this integer to be used in certain calculations.
    cachedPage->hitDice = totalHpDice;
    
    s32 flatBegin = throwBonus >> 32;
    s32 flatEnd   = (s32)throwBonus;
    s32 flatVal   = ls_utf32ToIntIgnoreWhitespace({hpExpr.data + flatBegin, flatEnd - flatBegin, flatEnd - flatBegin});
    
    b32 hasToughness       = CompendiumPageHasTalent(cachedPage, ls_utf32Constant(U"Robustezza"));
    b32 hasMithicToughness = CompendiumPageHasTalent(cachedPage, ls_utf32Constant(U"Robustezza[M]"));
    
    b32 isUndead = ls_utf32LeftFind(cachedPage->type, ls_utf32Constant(U"Non Morto")) != -1;
    b32 isConstruct = ls_utf32LeftFind(cachedPage->type, ls_utf32Constant(U"Costrutto")) != -1;
    
    //TODO: Class Level can give bonus HP (seems like most monsters do.)
    if(isConstruct) {
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Piccola")))      { flatVal += 5; }
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Media")))        { flatVal += 10; }
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Grande")))       { flatVal += 15; }
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Enorme")))       { flatVal += 20; }
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Mastodontica"))) { flatVal += 30; }
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Colossale")))    { flatVal += 40; }
    }
    else if(isUndead) { 
        flatVal -= totalHpDice*(newToOldMap[cachedPage->origAS[AS_CHA] - 10]);
        flatVal += totalHpDice*(cachedPage->modAS[AS_CHA] - 10);
    }
    else { 
        flatVal -= totalHpDice*(newToOldMap[cachedPage->origAS[AS_CON] - 10]);
        flatVal += totalHpDice*(cachedPage->modAS[AS_CON] - 10);
    }
    
    //NOTE: Mithical Creatures get extra HP based on Hit Die Kind and mithical rank.
    s32 rmRank = CompendiumPageMithicalRank(cachedPage->gs);
    if(rmRank > 0) { 
        flatVal -= rmRank*totalHpDiceMul;
        flatVal += (s32)((rmRank*totalHpDiceMul)*1.5f);
    }
    
    if(hasMithicToughness)
    {
        if(totalHpDice >= 3) {
            flatVal -= 2*totalHpDice;
            flatVal += 4*totalHpDice;
        }
        else { flatVal -= 6; flatVal += 12; }
    }
    else if(hasToughness)
    {
        if(totalHpDice >= 3) {
            flatVal -= totalHpDice;
            flatVal += 2*totalHpDice;
        }
        else { flatVal -= 3; flatVal += 6; }
    }
    
    finalHP += flatVal;
    
    ls_utf32FromInt_t(&cachedPage->HP, finalHP);
    
    //NOTE: We copy the current cachedPage->HP into totHP to basically create a view into 
    //      the cachedPage->HP string, and only keep the total value!
    cachedPage->totHP = cachedPage->HP;
    
    ls_utf32Append(&cachedPage->HP, {hp.data + hpEndIndex, hp.len - hpEndIndex, hp.len - hpEndIndex });
    
    return;
}
#endif

s32 CalculateAndCacheHP(CachedPageEntry *cachedPage, u64 hp)
{
    //TODO: Not sure if for Mithic Rank we get the sum of all HD faces, or just the race dice.
    s32 totalHpDiceFace = 0;
    s32 totalHpDice = 0;
    s32 finalHp = 0;
    
    for(s32 i = 0; i < HP_MAX_DICE_COUNT; i++)
    {
        s32 count = ((hp >> (HP_DIE_BITLEN*i)) & HP_DIE_COUNT_MASK) >> HP_DIE_FACE_BITLEN;
        s32 face  = ((hp >> (HP_DIE_BITLEN*i)) & HP_DIE_FACE_MASK);
        
        if(face == 0) { break; }
        
        totalHpDice     += count;
        finalHp         += count*dieFacesToInt[face];
        totalHpDiceFace += dieFacesToInt[face];
    }
    
    //NOTE: Set this integer to be used in certain calculations.
    cachedPage->hitDice = totalHpDice;
    
    s32 flatVal = (hp & HP_FLAT_MASK) >> HP_FLAT_OFFSET;
    
    b32 hasToughness       = CompendiumPageHasTalent(cachedPage, ls_utf32Constant(U"Robustezza"));
    b32 hasMithicToughness = CompendiumPageHasTalent(cachedPage, ls_utf32Constant(U"Robustezza[M]"));
    
    b32 isUndead = ls_utf32LeftFind(cachedPage->type, ls_utf32Constant(U"Non Morto")) != -1;
    b32 isConstruct = ls_utf32LeftFind(cachedPage->type, ls_utf32Constant(U"Costrutto")) != -1;
    
    //TODO: Class Level can give bonus HP (seems like most monsters do.)
    if(isConstruct) {
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Piccola")))      { flatVal += 5; }
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Media")))        { flatVal += 10; }
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Grande")))       { flatVal += 15; }
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Enorme")))       { flatVal += 20; }
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Mastodontica"))) { flatVal += 30; }
        if(ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Colossale")))    { flatVal += 40; }
    }
    else if(isUndead) { 
        flatVal -= totalHpDice*(newToOldMap[cachedPage->origAS[AS_CHA] - 10]);
        flatVal += totalHpDice*(cachedPage->modAS[AS_CHA] - 10);
    }
    else { 
        flatVal -= totalHpDice*(newToOldMap[cachedPage->origAS[AS_CON] - 10]);
        flatVal += totalHpDice*(cachedPage->modAS[AS_CON] - 10);
    }
    
    //NOTE: Mithical Creatures get extra HP based on Hit Die Kind and mithical rank.
    s32 rmRank = CompendiumPageMithicalRank(cachedPage->gs);
    if(rmRank > 0) { 
        flatVal -= rmRank*totalHpDiceFace;
        flatVal += (s32)((rmRank*totalHpDiceFace)*1.5f);
    }
    
    if(hasMithicToughness)
    {
        if(totalHpDice >= 3) {
            flatVal -= 2*totalHpDice;
            flatVal += 4*totalHpDice;
        }
        else { flatVal -= 6; flatVal += 12; }
    }
    else if(hasToughness)
    {
        if(totalHpDice >= 3) {
            flatVal -= totalHpDice;
            flatVal += 2*totalHpDice;
        }
        else { flatVal -= 3; flatVal += 6; }
    }
    
    finalHp += flatVal;
    
    return finalHp;
}

void CalculateAndCacheBMC(utf32 BMC, CachedPageEntry *cachedPage)
{
    if(ls_utf32AreEqual(BMC, ls_utf32Constant(U"-"))) { ls_utf32Set(&cachedPage->BMC, BMC); return; }
    
    s32 endIdx = ls_utf32LeftFind(BMC, (u32)'(');
    if(endIdx == -1) endIdx = BMC.len;
    
    //TODO: Fuck Golarion
    b32 useDex = ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Minuscola"));
    useDex |= ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Minuta"));
    useDex |= ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Piccolissima"));
    useDex |= ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Minuscolo"));
    useDex |= ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Minuto"));
    useDex |= ls_utf32AreEqual(cachedPage->size, ls_utf32Constant(U"Piccolissimo"));
    
    useDex |= (ls_utf32LeftFind(cachedPage->subtype, ls_utf32Constant(U"Incorporeo")) != -1);
    
    s32 statBonusNew = -1;
    s32 statBonusOld = -1;
    
    if(useDex == TRUE) {
        statBonusNew = cachedPage->modAS[AS_DEX] - 10;
        statBonusOld = newToOldMap[cachedPage->origAS[AS_DEX] - 10];
    }
    else {
        statBonusNew = cachedPage->modAS[AS_STR] - 10;
        statBonusOld = newToOldMap[cachedPage->origAS[AS_STR] - 10];
    }
    
    s32 bmcVal = ls_utf32ToInt({BMC.data, endIdx, endIdx});
    
    bmcVal = (bmcVal - statBonusOld) + statBonusNew;
    
    u32 buff[32] = {};
    utf32 tmpString = { buff, 32, 32 };
    
    ls_utf32Clear(&cachedPage->BMC);
    
    if(bmcVal >= 0) ls_utf32AppendChar(&cachedPage->BMC, (u32)'+');
    
    ls_utf32FromInt_t(&tmpString, bmcVal);
    ls_utf32Append(&cachedPage->BMC, tmpString);
    ls_utf32AppendChar(&cachedPage->BMC, (u32)' ');
    ls_utf32AppendBuffer(&cachedPage->BMC, BMC.data + endIdx, BMC.len - endIdx);
}

void CalculateAndCacheDMC(utf32 DMC, CachedPageEntry *cachedPage)
{
    if(ls_utf32AreEqual(DMC, ls_utf32Constant(U"-"))) { ls_utf32Set(&cachedPage->DMC, DMC); return; }
    
    s32 endIdx = ls_utf32LeftFind(DMC, (u32)'(');
    if(endIdx == -1) endIdx = DMC.len;
    
    s32 dexBonusNew = cachedPage->modAS[AS_DEX] - 10;
    s32 dexBonusOld = newToOldMap[cachedPage->origAS[AS_DEX] - 10];
    
    s32 strBonusNew = cachedPage->modAS[AS_STR] - 10;
    s32 strBonusOld = newToOldMap[cachedPage->origAS[AS_STR] - 10];
    
    s32 dmcVal = ls_utf32ToInt({DMC.data, endIdx, endIdx});
    
    dmcVal = (dmcVal - dexBonusOld - strBonusOld) + dexBonusNew + strBonusNew;
    
    u32 buff[32] = {};
    utf32 tmpString = { buff, 32, 32 };
    
    ls_utf32Clear(&cachedPage->DMC);
    
    if(dmcVal >= 0) ls_utf32AppendChar(&cachedPage->DMC, (u32)'+');
    
    ls_utf32FromInt_t(&tmpString, dmcVal);
    ls_utf32Append(&cachedPage->DMC, tmpString);
    ls_utf32AppendChar(&cachedPage->DMC, (u32)' ');
    ls_utf32AppendBuffer(&cachedPage->DMC, DMC.data + endIdx, DMC.len - endIdx);
}

void CalculateAndCacheInitiative(utf32 Init, CachedPageEntry *cachedPage, Status *status = NULL)
{
    //TODO: Fix cases like +12 (+99 Maremma Maiala)
    //      Those cases trip the M detection, so we need a first pass to make sure the M isn't between
    //      A couple of parentheses.
    //
    if(Init.len == 0) { ls_utf32Set(&cachedPage->initiative, Init); return; }
    
    s32 dexBonusNew = cachedPage->modAS[AS_DEX] - 10;
    s32 dexBonusOld = newToOldMap[cachedPage->origAS[AS_DEX] - 10];
    
    s32 multiToken  = ls_utf32LeftFind(Init, (u32)'/');
    //s32 mithicToken = ls_utf32LeftFind(Init, (u32)'M');
    s32 mithicToken = ls_utf32LeftFind(Init, U'\U00001D39');
    
    s32 commaIdx = ls_utf32LeftFind(Init, (u32)',');
    s32 semiIdx  = ls_utf32LeftFind(Init, (u32)';');
    s32 spaceIdx = ls_utf32LeftFind(Init, (u32)' ');
    
    s32 endIdx = commaIdx;
    if(commaIdx == -1) 
    { 
        endIdx = semiIdx;
        
        if(semiIdx == -1)
        {
            endIdx = spaceIdx;
            
            if(spaceIdx == -1)
            { 
                endIdx = Init.len;
            }
        }
    }
    
    //NOTE: Handle status conditions
    s32 statusEffect = 0;
    if(status)
    {
        for(s32 i = 0; i < STATUS_COUNT; i++)
        {
            if(!status[i].check.isActive) { continue; }
            
            switch(status[i].type)
            {
                case STATUS_ASSORDATO: { statusEffect = -4; } break;
                
                case STATUS_PANICO:
                case STATUS_SPAVENTATO:
                case STATUS_SCOSSO:
                {
                    statusEffect = -2;
                } break;
            }
        }
    }
    
    u32 buff[32] = {};
    utf32 tmpString = { buff, 32, 32 };
    ls_utf32Clear(&cachedPage->initiative);
    
    s32 initOne = -999;
    s32 initTwo = -999;
    if(multiToken != -1)
    {
        if(mithicToken != -1)
        {
            if(mithicToken < multiToken) // +16M/-4, ...
            {
                s32 twoLen  = endIdx - multiToken - 1;
                
                initOne = ls_utf32ToInt({Init.data, mithicToken, mithicToken});
                initTwo = ls_utf32ToInt({Init.data + multiToken + 1, twoLen, twoLen});
                initOne = (initOne - dexBonusOld) + dexBonusNew;
                initTwo = (initTwo - dexBonusOld) + dexBonusNew;
                
                initOne += statusEffect;
                initTwo += statusEffect;
                
                if(initOne >= 0) ls_utf32AppendChar(&cachedPage->initiative, (u32)'+');
                ls_utf32FromInt_t(&tmpString, initOne);
                ls_utf32Append(&cachedPage->initiative, tmpString);
                ls_utf32Clear(&tmpString);
                ls_utf32AppendChar(&cachedPage->initiative, (u32)'M');
                ls_utf32AppendChar(&cachedPage->initiative, (u32)'/');
                if(initTwo >= 0) ls_utf32AppendChar(&cachedPage->initiative, (u32)'+');
                ls_utf32FromInt_t(&tmpString, initTwo);
                ls_utf32Append(&cachedPage->initiative, tmpString);
                ls_utf32AppendBuffer(&cachedPage->initiative, Init.data + endIdx, Init.len - endIdx);
                return;
            }
            else // +23/+3M ...
            {
                s32 twoLen  = mithicToken - multiToken - 1;
                
                initOne = ls_utf32ToInt({Init.data, multiToken, multiToken});
                initTwo = ls_utf32ToInt({Init.data + multiToken + 1, twoLen, twoLen});
                initOne = (initOne - dexBonusOld) + dexBonusNew;
                initTwo = (initTwo - dexBonusOld) + dexBonusNew;
                
                initOne += statusEffect;
                initTwo += statusEffect;
                
                if(initOne >= 0) ls_utf32AppendChar(&cachedPage->initiative, (u32)'+');
                ls_utf32FromInt_t(&tmpString, initOne);
                ls_utf32Append(&cachedPage->initiative, tmpString);
                ls_utf32Clear(&tmpString);
                ls_utf32AppendChar(&cachedPage->initiative, (u32)'/');
                if(initTwo >= 0) ls_utf32AppendChar(&cachedPage->initiative, (u32)'+');
                ls_utf32FromInt_t(&tmpString, initTwo);
                ls_utf32Append(&cachedPage->initiative, tmpString);
                ls_utf32AppendChar(&cachedPage->initiative, (u32)'M');
                ls_utf32AppendBuffer(&cachedPage->initiative, Init.data + endIdx, Init.len - endIdx);
                
                return;
            }
        }
        else // +12/+2,  ...
        {
            s32 twoLen  = endIdx - multiToken - 1;
            
            initOne = ls_utf32ToInt({Init.data, multiToken, multiToken});
            initTwo = ls_utf32ToInt({Init.data + multiToken + 1, twoLen, twoLen});
            initOne = (initOne - dexBonusOld) + dexBonusNew;
            initTwo = (initTwo - dexBonusOld) + dexBonusNew;
            
            initOne += statusEffect;
            initTwo += statusEffect;
            
            if(initOne >= 0) ls_utf32AppendChar(&cachedPage->initiative, (u32)'+');
            ls_utf32FromInt_t(&tmpString, initOne);
            ls_utf32Append(&cachedPage->initiative, tmpString);
            ls_utf32Clear(&tmpString);
            ls_utf32AppendChar(&cachedPage->initiative, (u32)'/');
            if(initTwo >= 0) ls_utf32AppendChar(&cachedPage->initiative, (u32)'+');
            ls_utf32FromInt_t(&tmpString, initTwo);
            ls_utf32Append(&cachedPage->initiative, tmpString);
            ls_utf32AppendBuffer(&cachedPage->initiative, Init.data + endIdx, Init.len - endIdx);
            
            return;
        }
    }
    else
    {
        if(mithicToken != -1) // +23M ...
        {
            initOne = ls_utf32ToInt({Init.data, mithicToken, mithicToken});
            initOne = (initOne - dexBonusOld) + dexBonusNew;
            
            initOne += statusEffect;
            
            if(initOne >= 0) ls_utf32AppendChar(&cachedPage->initiative, (u32)'+');
            ls_utf32FromInt_t(&tmpString, initOne);
            ls_utf32Append(&cachedPage->initiative, tmpString);
            ls_utf32AppendChar(&cachedPage->initiative, (u32)'M');
            ls_utf32AppendBuffer(&cachedPage->initiative, Init.data + endIdx, Init.len - endIdx);
            
            return;
        }
        else // +12 ...
        {
            initOne = ls_utf32ToInt({Init.data, endIdx, endIdx});
            initOne = (initOne - dexBonusOld) + dexBonusNew;
            
            initOne += statusEffect;
            
            if(initOne >= 0) ls_utf32AppendChar(&cachedPage->initiative, (u32)'+');
            ls_utf32FromInt_t(&tmpString, initOne);
            ls_utf32Append(&cachedPage->initiative, tmpString);
            ls_utf32AppendBuffer(&cachedPage->initiative, Init.data + endIdx, Init.len - endIdx);
            
            return;
        }
    }
    
    LogMsg(FALSE, "Missed case of initiative.\n");
    ls_utf32Set(&cachedPage->initiative, Init);
    return;
}

void CalculateAndCacheMelee(utf32 Melee, CachedPageEntry *cachedPage, Status *status = NULL)
{
    //-----------------------------------------------------------------------------------------//
    //NOTE: Setup all constants and checks to correctly modify and represent the melee attacks //
    //-----------------------------------------------------------------------------------------//
    
    cachedPage->meleeError = FALSE;
    
    const s32 naturalAttacksCount = 39;
    const utf32 naturalAttacks[naturalAttacksCount] = { 
        ls_utf32Constant(U"morso"), ls_utf32Constant(U"Morso"), ls_utf32Constant(U"morsi"),
        ls_utf32Constant(U"Morsi"), ls_utf32Constant(U"artiglio"), ls_utf32Constant(U"Artiglio"),
        ls_utf32Constant(U"artigli"), ls_utf32Constant(U"Artigli"), ls_utf32Constant(U"ala "),
        ls_utf32Constant(U"Ala "), ls_utf32Constant(U"ali"), ls_utf32Constant(U"Ali"),
        ls_utf32Constant(U"tentacolo"), ls_utf32Constant(U"Tentacolo"), ls_utf32Constant(U"tentacoli"),
        ls_utf32Constant(U"Tentacoli"), ls_utf32Constant(U"zoccolo"), ls_utf32Constant(U"Zoccolo"),
        ls_utf32Constant(U"zoccoli"), ls_utf32Constant(U"Zoccoli"), ls_utf32Constant(U"chela"),
        ls_utf32Constant(U"Chela"), ls_utf32Constant(U"chele"), ls_utf32Constant(U"Chele"),
        ls_utf32Constant(U"colpo di coda"), ls_utf32Constant(U"Colpo di coda"), ls_utf32Constant(U"corno"),
        ls_utf32Constant(U"Corno"), ls_utf32Constant(U"corni"), ls_utf32Constant(U"Corni"),
        ls_utf32Constant(U"pungiglione"), ls_utf32Constant(U"Pungiglione"), ls_utf32Constant(U"pungiglioni"),
        ls_utf32Constant(U"Pungiglioni"), ls_utf32Constant(U"schianto"), ls_utf32Constant(U"Schianto"),
        ls_utf32Constant(U"schianti"), ls_utf32Constant(U"Schianti"),
        
        //NOTE: Eccezioni!
        ls_utf32Constant(U"capelli uncinati"),
    };
    
    if(Melee.len < 2) { ls_utf32Set(&cachedPage->melee, Melee); return; }
    
    s32 sciameIdx  = ls_utf32LeftFind(Melee, ls_utf32Constant(U"sciame"));
    s32 sciame2Idx = ls_utf32LeftFind(Melee, ls_utf32Constant(U"Sciame"));
    s32 truppaIdx  = ls_utf32LeftFind(Melee, ls_utf32Constant(U"truppa"));
    
    //NOTE: Quick exit on special types of attacks
    if(sciameIdx  != -1) { cachedPage->meleeError = TRUE; ls_utf32Set(&cachedPage->melee, Melee); return; }
    if(sciame2Idx != -1) { cachedPage->meleeError = TRUE; ls_utf32Set(&cachedPage->melee, Melee); return; }
    if(truppaIdx  != -1) { cachedPage->meleeError = TRUE; ls_utf32Set(&cachedPage->melee, Melee); return; }
    
    s32 strBonusNew = cachedPage->modAS[AS_STR] - 10;
    s32 strBonusOld = newToOldMap[cachedPage->origAS[AS_STR] - 10];
    
    s32 dexBonusNew = cachedPage->modAS[AS_STR] - 10;
    s32 dexBonusOld = newToOldMap[cachedPage->origAS[AS_DEX] - 10];
    
    s32 chaBonusNew = cachedPage->modAS[AS_CHA] - 10;
    s32 chaBonusOld = newToOldMap[cachedPage->origAS[AS_CHA] - 10];
    
    s32 bab = ls_utf32ToInt(cachedPage->BAB);
    
    b32 hasAdvancedArch  = ls_utf32LeftFind(cachedPage->archetype, ls_utf32Constant(U"Avanzato")) != -1;
    b32 isIncorporeal    = ls_utf32LeftFind(cachedPage->subtype, ls_utf32Constant(U"Incorporeo")) != -1;
    b32 hasChangelingMod = ls_utf32LeftFind(cachedPage->spec_qual, ls_utf32Constant(U"Changeling Imponente")) != -1;
    
    b32 hasWeaponFinesse = CompendiumPageHasTalent(cachedPage, ls_utf32Constant(U"Arma Accurata"));
    b32 hasMithicWeaponFinesse = CompendiumPageHasTalent(cachedPage, ls_utf32Constant(U"Arma Accurata[M]"));
    
    //NOTE: Special Enemies with special bullshit!
    b32 isTiyanak = ls_utf32AreEqual(cachedPage->name, ls_utf32Constant(U"Tiyanak"));
    
    s32 parenOpenIdx = ls_utf32LeftFind(Melee, '(');
    if(parenOpenIdx == -1) { cachedPage->meleeError = TRUE; ls_utf32Set(&cachedPage->melee, Melee); return; }
    AssertMsg(parenOpenIdx != -1, "NOOOOOOO!\n");
    
    //------------------------------------------------------------------//
    //NOTE: Start separating the string in the main part and paren part //
    //------------------------------------------------------------------//
    ls_utf32Clear(&cachedPage->melee);
    s32 stringIndex = 0;
    
    while(parenOpenIdx != -1)
    {
        s32 slashIdx = ls_utf32LeftFind(Melee, stringIndex, '/');
        s32 bonuses[9] = {};
        s32 attacksCount = 1;
        
        if(slashIdx == -1 || slashIdx > parenOpenIdx)
        { bonuses[0] = rightFindBonus(Melee, parenOpenIdx, stringIndex); }
        else 
        { bonuses[0] = rightFindBonus(Melee, slashIdx, stringIndex); }
        
        //TODO: What to do about this?
        if(bonuses[0] == -1) { cachedPage->meleeError = TRUE; ls_utf32Set(&cachedPage->melee, Melee); return; }
        AssertMsg(bonuses[0] != -1, "Missing value in 1 Attack!");
        
        if(slashIdx != -1 && slashIdx < parenOpenIdx)
        {
            //NOTE: Now count the attacks
            s32 currSlash = slashIdx;
            s32 lastSlash = slashIdx;
            while(currSlash = ls_utf32LeftFind(Melee, currSlash+1, '/'), currSlash != -1 && currSlash < parenOpenIdx)
            {
                if(attacksCount >= 8) { break; }
                AssertMsg(attacksCount < 8, "Too many attacks, BUG!\n");
                
                bonuses[attacksCount] = rightFindBonus(Melee, currSlash, stringIndex);
                attacksCount += 1;
                
                lastSlash = currSlash;
            }
            
            bonuses[attacksCount] = lastSlash+1;
            attacksCount += 1;
            
            //NOTE: We got all the attacks. We are done?
        }
        
        //NOTE: Skip the sign we are on and look for first.
        bonuses[attacksCount] = ls_utf32LeftFindNotNumber(Melee, bonuses[attacksCount-1]+1);
        
        u32 tmpBuff[32]  = {};
        utf32 tmpString = { tmpBuff, 0, 32 };
        
        u32 bonusBuffer[256]  = {};
        utf32 newBonusString = { bonusBuffer, 0, 256 };
        
        for(s32 i = 0; i < attacksCount; i++)
        {
            s32 len = bonuses[i+1] - bonuses[i];
            s32 oldBonus = ls_utf32ToInt({Melee.data + bonuses[i], len, len});
            s32 newBonus = oldBonus - strBonusOld + strBonusNew;
            if(hasWeaponFinesse || isIncorporeal) { newBonus = oldBonus - dexBonusOld + dexBonusNew; }
            
            //NOTE: Handle status conditions
            if(status)
            {
                for(s32 i = 0; i < STATUS_COUNT; i++)
                {
                    if(!status[i].check.isActive) { continue; }
                    
                    switch(status[i].type)
                    {
                        case STATUS_ABBAGLIATO: { newBonus -= 1; } break;
                        
                        case STATUS_INFERMO:
                        case STATUS_INTRALCIATO:
                        case STATUS_LOTTA:
                        case STATUS_SCOSSO:
                        case STATUS_SPAVENTATO:
                        case STATUS_PANICO: { newBonus -= 2; } break;
                        
                        case STATUS_PRONO: { newBonus -= 4; } break;
                        
                        //TODONOTE: I think this would only apply against enemies that can't see you... so...
                        //case STATUS_INVISIBILE: { newBonus += 2 } break; 
                    }
                }
            }
            
            ls_utf32FromInt_t(&tmpString, newBonus);
            
            if(newBonus > 0) { ls_utf32AppendChar(&newBonusString, '+'); }
            ls_utf32Append(&newBonusString, tmpString);
            
            if(i < attacksCount-1) { ls_utf32AppendChar(&newBonusString, '/'); }
        }
        
        ls_utf32Append(&cachedPage->melee, {Melee.data + stringIndex, bonuses[0] - stringIndex, bonuses[0] - stringIndex});
        ls_utf32Append(&cachedPage->melee, newBonusString);
        
        s32 parenCloseIdx = ls_utf32LeftFind(Melee, parenOpenIdx, ')');
        
        //NOTE: Assume this is a formatting error and clamp it to the end
        if(parenCloseIdx == -1) { parenCloseIdx = Melee.len - 1; }
        //AssertMsg(parenCloseIdx != -1, "WHAAAT!?");
        
        utf32 insideParen = { Melee.data+parenOpenIdx+1, parenCloseIdx-parenOpenIdx-1, parenCloseIdx-parenOpenIdx-1 };
        //NOTE: And now, fix the damage
        {
            b32 isNatural = FALSE;
            for(s32 nIdx = 0; nIdx < naturalAttacksCount; nIdx++)
            {
                utf32 haystack = { Melee.data + stringIndex, parenOpenIdx - stringIndex, parenOpenIdx - stringIndex };
                if(ls_utf32LeftFind(haystack, naturalAttacks[nIdx]) != -1)
                { isNatural = TRUE; break; }
            }
            
#if 0 //TODO: Fix energy damage being applied the strength bonus on a few creatures like Fuoco Fatuo.
            const s32 elementalTestCount = 10;
            utf32 elementalTest[elementalTestCount] = {
                ls_utf32Constant(U"elettricit\U000000E0"), ls_utf32Constant(U"Elettricit\U000000E0"),
                ls_utf32Constant(U"fuoco"), ls_utf32Constant(U"Fuoco"),
                ls_utf32Constant(U"acido"), ls_utf32Constant(U"Acido"),
                ls_utf32Constant(U"freddo"), ls_utf32Constant(U"Freddo"),
                ls_utf32Constant(U"sonoro"), ls_utf32Constant(U"Sonoro"),
            };
            
            if(ls_utf32LeftFindAny(insideParen, elementalTest, elementalTestCount) != -1) {
                ls_log("Found: {utf32}", insideParen);
            }
#endif
            
            s64 diceThrowRange = leftFindDiceThrow(Melee, parenOpenIdx, parenCloseIdx);
            s32 diceThrowIdx = s32(diceThrowRange >> 32);
            s32 diceThrowEnd = s32(diceThrowRange);
            if(diceThrowIdx != -1)
            {
                //NOTE: Now find the bonus. If it doesn't exist, notify it somehow!
                s64 diceBonusRange = leftFindDiceBonus(Melee, diceThrowIdx+1, parenCloseIdx);
                s32 diceBonus     = s32(diceBonusRange >> 32);
                s32 dmgBonusEnd   = s32(diceBonusRange);
                
                s32 oldDBonus = 0;
                if(diceBonusRange != -1)
                {
                    utf32 tmpDmgString = {Melee.data + diceBonus, dmgBonusEnd - diceBonus, dmgBonusEnd - diceBonus};
                    oldDBonus = ls_utf32ToIntIgnoreWhitespace(tmpDmgString);
                }
                else
                {
                    dmgBonusEnd = diceThrowEnd;
                }
                
                //NOTE: Escaped From Unhandled case
                if(isIncorporeal && oldDBonus != 0)
                { cachedPage->meleeError = TRUE; ls_utf32Set(&cachedPage->melee, Melee); return; }
                
                s32 newDBonus = 0;
                if(!isIncorporeal) //NOTE: Shitty way to not add damage when creature is incorporeal.
                {
                    if(isNatural == TRUE)
                    {
                        s32 add     = 0;
                        s32 postAdd = 0;
                        
                        if(hasChangelingMod) { add += 1; }
                        if(hasAdvancedArch)  { add += 2; }
                        if(isTiyanak)        { add += chaBonusOld; postAdd += chaBonusNew; }
                        
                        //TODO: Felino Marino, WTF!?!?!?
                        //TODO: Mastino Ombra, WTF!?!?!?
                        //TODO: Rakshasa Mitico, WTF!?!?!? Mithic Arma Accurata
                        s32 halfNew = strBonusNew / 2;
                        s32 halfOld = strBonusOld / 2;
                        if(oldDBonus == strBonusOld + add) //NOTE: It's primary
                        { 
                            newDBonus = oldDBonus - strBonusOld + strBonusNew;
                        }
                        else if(oldDBonus == halfOld + add)  //NOTE: It's secondary
                        { 
                            newDBonus = oldDBonus - halfOld + halfNew;
                        }
                        else if(oldDBonus == strBonusOld + halfOld + add)  //NOTE: It's SINGLE ONLY attack
                        { 
                            s32 oldBon = strBonusOld + halfOld;
                            s32 newBon = strBonusNew + halfNew;
                            newDBonus = oldDBonus - oldBon + newBon;
                        }
                        //NOTE: Many have special attacks that give them 2*STR bonus!
                        else if(oldDBonus == strBonusOld*2 + add)
                        { 
                            newDBonus = oldDBonus - strBonusOld*2 + strBonusNew*2;
                        }
                        else
                        {
                            //NOTE: Escaped From Unhandled case
                            cachedPage->meleeError = TRUE; 
                            ls_utf32Set(&cachedPage->melee, Melee);
                            return;
                        }
                        
                        //NOTE: Add the postAdd
                        newDBonus += postAdd;
                    }
                    else
                    {
                        if(hasMithicWeaponFinesse)
                        {
                            //TODO: Also when wearing a shield there's no penalty on damage or throw bonus.
                            newDBonus = oldDBonus - dexBonusOld + dexBonusNew;
                        }
                        else
                        {
                            //TODO: Broken Weapons!!
                            newDBonus = oldDBonus - strBonusOld + strBonusNew;
                        }
                    }
                }
                
                //NOTE: Handle Status Conditions
                if(status && status[STATUS_INFERMO].check.isActive) { newDBonus -= 2; }
                
                //NOTE: Now print the damage
                ls_utf32Append(&cachedPage->melee, {Melee.data + bonuses[attacksCount],
                                   diceThrowEnd - bonuses[attacksCount], diceThrowEnd - bonuses[attacksCount]});
                if(newDBonus != 0)
                {
                    ls_utf32FromInt_t(&tmpString, newDBonus);
                    if(newDBonus > 0) { ls_utf32AppendChar(&cachedPage->melee, '+'); }
                    ls_utf32Append(&cachedPage->melee, tmpString);
                }
                ls_utf32Append(&cachedPage->melee, {Melee.data + dmgBonusEnd,
                                   parenCloseIdx - dmgBonusEnd + 1, parenCloseIdx - dmgBonusEnd + 1});
            }
            else
            {
                ls_utf32Append(&cachedPage->melee, {Melee.data + bonuses[attacksCount],
                                   parenCloseIdx - bonuses[attacksCount] + 1, parenCloseIdx - bonuses[attacksCount] + 1});
            }
        }
        
        stringIndex = parenCloseIdx+1;
        
        parenOpenIdx = ls_utf32LeftFind(Melee, parenCloseIdx, '(');
    }
    
    s32 remaining_len = Melee.len - stringIndex;
    if(remaining_len != 0)
    {
        //NOTE: Something went wrong. For security append it so that we don't miss possibly important data
        LogMsgF(remaining_len == 0, "Stuff left at the end of the original string: %d\n", remaining_len);
        ls_utf32Append(&cachedPage->melee, {Melee.data + stringIndex, remaining_len, remaining_len});
    }
    
}

void CalculateAndCacheRanged(utf32 Ranged, CachedPageEntry *cachedPage, Status *status = NULL)
{
    cachedPage->rangedError = FALSE;
    
    s32 strBonusNew = cachedPage->modAS[AS_STR] - 10;
    s32 strBonusOld = newToOldMap[cachedPage->origAS[AS_STR] - 10];
    
    s32 dexBonusNew = cachedPage->modAS[AS_DEX] - 10;
    s32 dexBonusOld = newToOldMap[cachedPage->origAS[AS_DEX] - 10];
    
    s32 chaBonusNew = cachedPage->modAS[AS_CHA] - 10;
    s32 chaBonusOld = newToOldMap[cachedPage->origAS[AS_CHA] - 10];
    
    s32 bab = ls_utf32ToInt(cachedPage->BAB);
    
    //TODO: This is unused, but it should be used.
    //      +2 to DEX should mean an increase in TxC / Dmg with certain weapons/talents
    //b32 hasAdvancedArch  = ls_utf32LeftFind(cachedPage->archetype, ls_utf32Constant(U"Avanzato")) != -1;
    b32 isIncorporeal    = ls_utf32LeftFind(cachedPage->subtype, ls_utf32Constant(U"Incorporeo")) != -1;
    
    s32 parenOpenIdx = ls_utf32LeftFind(Ranged, '(');
    if(parenOpenIdx == -1) { cachedPage->rangedError = TRUE; ls_utf32Set(&cachedPage->ranged, Ranged); return; }
    AssertMsg(parenOpenIdx != -1, "NOOOOOOO!\n");
    
    //NOTE: Prepare the string
    ls_utf32Clear(&cachedPage->ranged);
    s32 stringIndex = 0;
    
    while(parenOpenIdx != -1)
    {
        //NOTE: Get the weapon used for this attack
        RangedWeapon *weapon = NULL;
        utf32 searchBlock = { Ranged.data + stringIndex, parenOpenIdx - stringIndex, parenOpenIdx - stringIndex };
        for(s32 i = 0; i < rangedWeaponCount; i++)
        {
            if(ls_utf32LeftFind(searchBlock, rangedTable[i].name) != -1)
            {
                weapon = rangedTable + i;
                break;
            }
        }
        
        if(weapon == NULL) { cachedPage->rangedError = TRUE; ls_utf32Set(&cachedPage->ranged, Ranged); return; }
        
        s32 slashIdx = ls_utf32LeftFind(Ranged, stringIndex, '/');
        s32 bonuses[9] = {};
        s32 attacksCount = 1;
        
        if(slashIdx == -1 || slashIdx > parenOpenIdx)
        { bonuses[0] = rightFindBonus(Ranged, parenOpenIdx, stringIndex); }
        else 
        { bonuses[0] = rightFindBonus(Ranged, slashIdx, stringIndex); }
        
        //TODO: What to do about this?
        if(bonuses[0] == -1) { cachedPage->rangedError = TRUE; ls_utf32Set(&cachedPage->ranged, Ranged); return; }
        AssertMsg(bonuses[0] != -1, "Missing value in 1 Attack!");
        
        if(slashIdx != -1 && slashIdx < parenOpenIdx)
        {
            //NOTE: Now count the attacks
            s32 currSlash = slashIdx;
            s32 lastSlash = slashIdx;
            while(currSlash = ls_utf32LeftFind(Ranged, currSlash+1, '/'), currSlash != -1 && currSlash < parenOpenIdx)
            {
                if(attacksCount >= 8) { break; }
                AssertMsg(attacksCount < 8, "Too many attacks, BUG!\n");
                
                bonuses[attacksCount] = rightFindBonus(Ranged, currSlash, stringIndex);
                attacksCount += 1;
                
                lastSlash = currSlash;
            }
            
            bonuses[attacksCount] = lastSlash+1;
            attacksCount += 1;
            
            //NOTE: We got all the attacks. We are done?
        }
        
        //NOTE: Skip the sign we are on and look for first.
        bonuses[attacksCount] = ls_utf32LeftFindNotNumber(Ranged, bonuses[attacksCount-1]+1);
        
        u32 tmpBuff[32]  = {};
        utf32 tmpString = { tmpBuff, 0, 32 };
        
        u32 bonusBuffer[256]  = {};
        utf32 newBonusString = { bonusBuffer, 0, 256 };
        
        for(s32 i = 0; i < attacksCount; i++)
        {
            s32 len = bonuses[i+1] - bonuses[i];
            s32 oldBonus = ls_utf32ToInt({Ranged.data + bonuses[i], len, len});
            s32 newBonus = oldBonus - dexBonusOld + dexBonusNew; //TODO: Is this everything??
            
            //NOTE: Handle status conditions
            if(status)
            {
                for(s32 i = 0; i < STATUS_COUNT; i++)
                {
                    if(!status[i].check.isActive) { continue; }
                    
                    switch(status[i].type)
                    {
                        case STATUS_ABBAGLIATO: { newBonus -= 1; } break;
                        
                        case STATUS_INFERMO:
                        case STATUS_INTRALCIATO:
                        case STATUS_LOTTA:
                        case STATUS_SCOSSO:
                        case STATUS_SPAVENTATO:
                        case STATUS_PANICO: { newBonus -= 2; } break;
                        
                        case STATUS_PRONO: { newBonus -= 4; } break;
                        
                        //TODONOTE: I think this would only apply against enemies that can't see you... so...
                        //case STATUS_INVISIBILE: { newBonus += 2 } break; 
                    }
                }
            }
            
            //NOTE: Now print the TxC
            ls_utf32FromInt_t(&tmpString, newBonus);
            
            if(newBonus > 0) { ls_utf32AppendChar(&newBonusString, '+'); }
            ls_utf32Append(&newBonusString, tmpString);
            
            if(i < attacksCount-1) { ls_utf32AppendChar(&newBonusString, '/'); }
        }
        
        ls_utf32Append(&cachedPage->ranged, {Ranged.data + stringIndex, bonuses[0] - stringIndex, bonuses[0] - stringIndex});
        ls_utf32Append(&cachedPage->ranged, newBonusString);
        
        s32 parenCloseIdx = ls_utf32LeftFind(Ranged, parenOpenIdx, ')');
        
        //NOTE: Assume this is a formatting error and clamp it to the end
        if(parenCloseIdx == -1) { parenCloseIdx = Ranged.len - 1; }
        //AssertMsg(parenCloseIdx != -1, "WHAAAT!?");
        
        //NOTE: And now, fix the damage, Ranged attacks cannot be natural!
        {
            s64 diceThrowRange = leftFindDiceThrow(Ranged, parenOpenIdx, parenCloseIdx);
            s32 diceThrowIdx = s32(diceThrowRange >> 32);
            s32 diceThrowEnd = s32(diceThrowRange);
            if(diceThrowIdx != -1)
            {
                //NOTE: Now find the bonus. If it doesn't exist, notify it somehow!
                s64 diceBonusRange = leftFindDiceBonus(Ranged, diceThrowIdx+1, parenCloseIdx);
                s32 diceBonus     = s32(diceBonusRange >> 32);
                s32 dmgBonusEnd   = s32(diceBonusRange);
                
                s32 oldDBonus = 0;
                if(diceBonusRange != -1)
                {
                    utf32 tmpDmgString = {Ranged.data + diceBonus, dmgBonusEnd - diceBonus, dmgBonusEnd - diceBonus};
                    oldDBonus = ls_utf32ToIntIgnoreWhitespace(tmpDmgString);
                }
                else
                {
                    dmgBonusEnd = diceThrowEnd;
                }
                
                //NOTE: Escaped From Unhandled case
                if(isIncorporeal && oldDBonus != 0)
                { cachedPage->rangedError = TRUE; ls_utf32Set(&cachedPage->ranged, Ranged); return; }
                
                //TODO: Broken Weapons!!
                s32 newDBonus = oldDBonus;
                if(!isIncorporeal)
                {
                    if(weapon->type == RANGED_THROW)
                    {
                        newDBonus = oldDBonus - strBonusOld + strBonusNew;
                    }
                    else if(weapon->type == RANGED_AIM_STR)
                    {
                        if(strBonusOld < 0) { newDBonus -= strBonusOld; }
                        if(strBonusNew < 0) { newDBonus += strBonusNew; }
                    }
                    else if(weapon->type == RANGED_AIM_STR_BON)
                    {
                        newDBonus = oldDBonus - strBonusOld + strBonusNew;
                    }
                }
                
                //NOTE: Handle Status Conditions
                if(status && status[STATUS_INFERMO].check.isActive) { newDBonus -= 2; }
                
                ls_utf32Append(&cachedPage->ranged, {Ranged.data + bonuses[attacksCount],
                                   diceThrowEnd - bonuses[attacksCount], diceThrowEnd - bonuses[attacksCount]});
                if(newDBonus != 0) 
                {
                    ls_utf32FromInt_t(&tmpString, newDBonus);
                    if(newDBonus > 0) { ls_utf32AppendChar(&cachedPage->ranged, '+'); }
                    ls_utf32Append(&cachedPage->ranged, tmpString);
                }
                ls_utf32Append(&cachedPage->ranged, {Ranged.data + dmgBonusEnd,
                                   parenCloseIdx - dmgBonusEnd + 1, parenCloseIdx - dmgBonusEnd + 1});
            }
            else
            {
                ls_utf32Append(&cachedPage->ranged, {Ranged.data + bonuses[attacksCount],
                                   parenCloseIdx - bonuses[attacksCount] + 1, parenCloseIdx - bonuses[attacksCount] + 1});
            }
        }
        
        stringIndex = parenCloseIdx+1;
        
        parenOpenIdx = ls_utf32LeftFind(Ranged, parenCloseIdx, '(');
    }
    
    //NOTE: It's mostly formatting errors because of fucking golarion!
    LogMsgF(Ranged.len - stringIndex == 0, "Stuff left at the end of the original string: %d\n", Ranged.len - stringIndex);
}

//NOTE: Skill map to Skill Cat
enum SkillASCat { SK_STR, SK_DEX, SK_CON, SK_INT, SK_WIS, SK_CHA, SK_UNDEFINED };

const char32_t *skillNames[] = {
    U"Acrobazia", U"Addestrare Animali", U"Artigianato", U"Artista della Fuga",
    U"Camuffare", U"Cavalcare", U"Conoscenze", U"Diplomazia", U"Disattivare Congegni",
    U"Furtivit\U000000E0", U"Guarire", U"Intimidire", U"Intrattenere", U"Intuizione", U"Linguistica", U"Nuotare",
    U"Percezione", U"Professione", U"Raggirare", U"Rapidit\U000000E0 di Mano", U"Sapienza Magica", U"Scalare",
    U"Sopravvivenza", U"Utilizzare Congegni Magici", U"Valutare", U"Volare",
    
    //NOTE: Oddballs
    U"Esibire", U"Eseguire"
};

SkillASCat mapPosToCat[] = { 
    SK_DEX, SK_CHA, SK_INT, SK_DEX, SK_CHA, SK_DEX,
    SK_INT, SK_CHA, SK_DEX, SK_DEX, SK_WIS, SK_CHA, SK_CHA, SK_WIS, SK_INT, SK_STR, SK_WIS, SK_WIS,
    SK_CHA, SK_DEX, SK_INT, SK_STR, SK_WIS, SK_CHA, SK_INT, SK_DEX,
    
    //NOTE: Oddballs
    SK_CHA, SK_CHA
};
constexpr s32 mapPosToCatLen = (sizeof(mapPosToCat) / sizeof(SkillASCat));

static_assert((sizeof(skillNames) / sizeof(char32_t*)) == (sizeof(mapPosToCat) / sizeof(SkillASCat)), "SkillToAS");

void CalculateAndCacheSkill(utf32 Skill, CachedPageEntry *cachedPage, Status *status = NULL)
{
    if(ls_utf32AreEqual(Skill, ls_utf32Constant(U"-")))
    { ls_utf32Append(&cachedPage->skills, Skill); return; }
    
    SkillASCat skillCat = SK_UNDEFINED;
    
    for(s32 i = 0; i < mapPosToCatLen; i++)
    {
        utf32 check = ls_utf32Constant(skillNames[i]);
        
        if(ls_utf32LeftFind(Skill, check) != -1)
        {
            skillCat = mapPosToCat[i];
            break;
        }
    }
    
    
    //LogMsg(skillCat != SK_UNDEFINED, "Unable to find Skill AS Category!\n");
    
    s32 asBonusNew = 0;
    s32 asBonusOld = 0;
    
    switch(skillCat)
    {
        case SK_STR:
        {
            asBonusNew = cachedPage->modAS[AS_STR] - 10;
            asBonusOld = newToOldMap[cachedPage->origAS[AS_STR] - 10];
        } break;
        
        case SK_DEX:
        {
            asBonusNew = cachedPage->modAS[AS_DEX] - 10;
            asBonusOld = newToOldMap[cachedPage->origAS[AS_DEX] - 10];
        } break;
        
        case SK_CON:
        {
            asBonusNew = cachedPage->modAS[AS_CON] - 10;
            asBonusOld = newToOldMap[cachedPage->origAS[AS_CON] - 10];
        } break;
        
        case SK_INT:
        {
            asBonusNew = cachedPage->modAS[AS_INT] - 10;
            asBonusOld = newToOldMap[cachedPage->origAS[AS_INT] - 10];
        } break;
        
        case SK_WIS:
        {
            asBonusNew = cachedPage->modAS[AS_WIS] - 10;
            asBonusOld = newToOldMap[cachedPage->origAS[AS_WIS] - 10];
        } break;
        
        case SK_CHA:
        {
            asBonusNew = cachedPage->modAS[AS_CHA] - 10;
            asBonusOld = newToOldMap[cachedPage->origAS[AS_CHA] - 10];
        } break;
    }
    
    //NOTE: Calculate Status Effect on Skill Modifier
    s32 statusEffect = 0;
    if(status)
    {
        for(s32 i = 0; i < STATUS_COUNT; i++)
        {
            if(!status[i].check.isActive) { continue; }
            
            switch(status[i].type)
            {
                case STATUS_ABBAGLIATO:
                {
                    if(ls_utf32LeftFind(Skill, ls_utf32Constant(U"Percezione")) != -1)
                    { statusEffect += -1; }
                } break;
                
                case STATUS_ACCECATO:
                {
                    if(skillCat == SK_STR || skillCat == SK_DEX)
                    { statusEffect += -4; }
                } break;
                
                case STATUS_AFFASCINATO:
                {
                    //TODO: -4 to `Reaction` skill checks (like Perception)
                    //      I'd prefer to modify the entire skill row itself to show both values?
                    //Assert(FALSE);
                } break;
                
                case STATUS_INFERMO:
                case STATUS_PANICO:
                case STATUS_SPAVENTATO:
                case STATUS_SCOSSO: { statusEffect += -2; } break;
            }
        }
    }
    
    //NOTE: Need To find the bonus now
    s32 openParenIdx  = ls_utf32LeftFind(Skill, '(');
    s32 closeParenIdx = -1;
    if(openParenIdx != -1)
    {
        closeParenIdx = ls_utf32LeftFind(Skill, ')');
        AssertMsg(closeParenIdx != -1, "Paren block doesn't close\n");
        
        //NOTE: Extract the paren block and operate on 2 strings separately
        u32 d1 [128] = {};
        utf32 parenBlock = {d1, 0, 128};
        
        u32 d2 [128] = {};
        utf32 cleanBlock = {d2, 0, 128};
        
        ls_utf32Set(&parenBlock, {Skill.data + openParenIdx-1, closeParenIdx - openParenIdx + 2, closeParenIdx - openParenIdx + 2});
        
        ls_utf32Set(&cleanBlock, {Skill.data, openParenIdx-1, openParenIdx-1});
        ls_utf32Append(&cleanBlock,{Skill.data + closeParenIdx + 1, Skill.len-closeParenIdx-1, Skill.len-closeParenIdx-1});
        
        //NOTE: Now find the bonuses
        s64 mainBonusRange = leftFindBonus(cleanBlock, 0, cleanBlock.len);
        if(mainBonusRange == -1)
        {
            LogMsg(FALSE, "No bonus in clean part of paren-FUL skill");
            ls_utf32Append(&cachedPage->skills, Skill);
            return;
        }
        
        s32 mainBonus    = mainBonusRange >> 32;
        s32 mainBonusEnd = (s32)mainBonusRange;
        
        s64 parenBonuses[16] = {};
        s32 pbIdx = 0;
        s32 parenBlockIdx = 0;
        
        parenBonuses[pbIdx] = leftFindBonus(parenBlock, parenBlockIdx, parenBlock.len);
        while(parenBonuses[pbIdx] != -1)
        {
            parenBlockIdx = (s32)parenBonuses[pbIdx];
            
            pbIdx += 1;
            parenBonuses[pbIdx] = leftFindBonus(parenBlock, parenBlockIdx, parenBlock.len);
        }
        
        //NOTE: Now fix the bonuses!
        s32 mainBonusValue = ls_utf32ToIntIgnoreWhitespace({cleanBlock.data + mainBonus, mainBonusEnd - mainBonus, mainBonusEnd - mainBonus});
        mainBonusValue = mainBonusValue - asBonusOld + asBonusNew;
        
        //NOTE: STATUS
        mainBonusValue += statusEffect;
        
        s32 parenBonusValues[16] = {};
        for(s32 i = 0; i < pbIdx; i++)
        {
            s32 parenBonus    = parenBonuses[i] >> 32;
            s32 parenBonusEnd = (s32)parenBonuses[i];
            
            parenBonusValues[i] = ls_utf32ToIntIgnoreWhitespace({parenBlock.data + parenBonus, parenBonusEnd - parenBonus, parenBonusEnd - parenBonus});
            parenBonusValues[i] = parenBonusValues[i] - asBonusOld + asBonusNew;
            
            //NOTE: STATUS
            parenBonusValues[i] += statusEffect;
        }
        
        //NOTE: And finally, generate the final string.
        u32 valueBuff[16] = {};
        utf32 valueStr = { valueBuff, 0, 16 };
        
        u32 d3 [256] = {};
        utf32 resultBlock = { d3, 0, 256 };
        
        //Set clean block with bonus
        ls_utf32Set(&resultBlock, { cleanBlock.data, mainBonus, mainBonus });
        ls_utf32FromInt_t(&valueStr, mainBonusValue);
        if(mainBonusValue >= 0) { ls_utf32AppendChar(&resultBlock, '+'); }
        ls_utf32Append(&resultBlock, valueStr);
        ls_utf32Append(&resultBlock, { cleanBlock.data + mainBonusEnd, cleanBlock.len - mainBonusEnd, cleanBlock.len - mainBonusEnd });
        
        //Set paren block with all bonuses
        s32 currIdx = 0;
        for(s32 i = 0; i < pbIdx; i++)
        {
            s32 bgIdx = parenBonuses[i] >> 32;
            ls_utf32Append(&resultBlock, { parenBlock.data + currIdx, bgIdx - currIdx, bgIdx - currIdx });
            
            ls_utf32FromInt_t(&valueStr, parenBonusValues[i]);
            if(parenBonusValues[i] >= 0) { ls_utf32AppendChar(&resultBlock, '+'); }
            ls_utf32Append(&resultBlock, valueStr);
            ls_utf32AppendChar(&resultBlock, ' '); //NOTETODO: Fuck this, justt append a fucking space
            currIdx = (s32)parenBonuses[i];
        }
        ls_utf32Append(&resultBlock, { parenBlock.data + currIdx, parenBlock.len - currIdx, parenBlock.len - currIdx });
        
        ls_utf32Append(&cachedPage->skills, resultBlock);
        
        return;
    }
    else
    {
        s32 end          = Skill.len;
        s64 bonusRange   = leftFindBonus(Skill, 0, end);
        s32 bonus        = bonusRange >> 32;
        end              = (s32)bonusRange;
        
        if(bonus == -1)
        {
            LogMsg(FALSE, "No bonus in paren-less skill");
            ls_utf32Append(&cachedPage->skills, Skill);
            return;
        }
        
        s32 bonusValue = ls_utf32ToIntIgnoreWhitespace({Skill.data + bonus, end - bonus, end - bonus});
        bonusValue = bonusValue - asBonusOld + asBonusNew;
        
        //NOTE: STATUS
        bonusValue += statusEffect;
        
        u32 tmpBuff[32]  = {};
        utf32 tmpString = { tmpBuff, 0, 32 };
        
        ls_utf32Append(&cachedPage->skills, {Skill.data, bonus, bonus});
        
        ls_utf32FromInt_t(&tmpString, bonusValue);
        if(bonusValue >= 0) { ls_utf32AppendChar(&cachedPage->skills, '+'); }
        
        ls_utf32Append(&cachedPage->skills, tmpString);
        ls_utf32Append(&cachedPage->skills, {Skill.data + end, Skill.len - end, Skill.len - end});
        
        return;
    }
}

void ShortenAndCacheName(utf32 orig_name, utf32 *out)
{
    if(orig_name.len < 17) { ls_utf32Set(out, orig_name); return; }
    
    //TODO: Can't we operate directly on `out` ?
    u32 tmpNameBuff[128] = {};
    utf32 name = { tmpNameBuff, 0, 128 };
    ls_utf32Copy_t(orig_name, &name);
    
    //NOTE: First remove the articles which are redundant to understanding the name
    utf32 articles[6] = {{(u32 *)U" di ", 4, 4}, {(u32 *)U" del ", 5, 5}, {(u32 *)U" della ", 7, 7}, 
        {(u32 *)U" delle ", 7, 7}, {(u32 *)U" dell'", 6, 6}, {(u32 *)U" d'", 3, 3}};
    s32 removeLen[6] = { 2, 3, 5, 5, 5, 2 };
    
    for(u32 i = 0; i < 5; i++)
    {
        s32 index = ls_utf32LeftFind(name, articles[i]);
        while(index >= 0)
        {
            ls_utf32RmSubstr(&name, index, index + removeLen[i]);
            index = ls_utf32LeftFind(name, articles[i]);
        }
    }
    
    if(name.len < 17) { ls_utf32Set(out, name); return; }
    
    //NOTE: If that was not enough, we shorten each word of the name by removing all vowels.
    u32 vowels[5] = { (u32)'a', (u32)'e', (u32)'i', (u32)'o', (u32)'u' };
    for(u32 i = 0; i < 5; i++)
    {
        s32 index = ls_utf32LeftFind(name, vowels[i]);
        while(index > 0)
        {
            ls_utf32RmIdx(&name, index);
            index = ls_utf32LeftFind(name, vowels[i]);
        }
    }
    
    //NOTE: If the name is still too long, shorten it to length 16
    if(name.len > 16) { name.len = 16; }
    
    ls_utf32Set(out, name);
}

void AddIncrementalToName(UIContext *c, utf32 name, UITextBox *box)
{
    s32 visibleMobs   = State.Init->Mobs.selectedIndex;
    s32 visibleAllies = State.Init->Allies.selectedIndex;
    s32 visibleOrder = visibleMobs + visibleAllies + party_count - State.Init->orderAdjust;
    
    //NOTE: Determine the number of the new mob/ally
    s32 cleanLen       = name.len;
    s32 maxIncremental = 0;
    for(u32 i = 0; i < visibleOrder; i++)
    {
        Order *o = State.Init->OrderFields + i;
        
        if(ls_utf32AreEqualUpTo(o->field.text, name, cleanLen))
        {
            s32 lenDiff         = (o->field.text.len - name.len) - 1;
            utf32 justTheNumber = { o->field.text.data + cleanLen + 1, lenDiff, lenDiff}; //Skip the space
            s32 incremental     = ls_utf32ToInt(justTheNumber);
            if(incremental > maxIncremental) maxIncremental = incremental;
        }
    }
    
    //TODO:Yet more temporary copy @ConvertNation
    u32 buff[32] = {};
    utf32 tmp = { buff, 0, 32 };
    
    u32 buff2[32] = {};
    utf32 tmp2 = { buff2, 0, 32 };
    
    ls_utf32FromInt_t(&tmp2, maxIncremental+1);
    ls_utf32Append(&tmp, name);
    ls_utf32AppendChar(&tmp, (u32)' ');
    ls_utf32Append(&tmp, tmp2);
    
    ls_uiTextBoxSet(c, box, tmp);
}

b32 AddMobOnClick(UIContext *, void *);
b32 AddAllyOnClick(UIContext *, void *);
b32 CompendiumAddPageToInitMob(UIContext *c, void *userData)
{
    s32 visibleMobs = State.Init->Mobs.selectedIndex;
    InitField *f = State.Init->MobFields + visibleMobs;
    
    if(!compendium.isViewingPage)  return FALSE;
    if(compendium.pageIndex == -1) return FALSE;
    if(visibleMobs == mob_count)     return FALSE;
    
    ls_uiTextBoxSet(c, &f->maxLife, cachedPage.totHP);
    
    u32 buff[32] = {};
    utf32 tmp = { buff, 0, 32 };
    ShortenAndCacheName(cachedPage.name, &tmp);
    AddIncrementalToName(c, tmp, &f->editFields[IF_IDX_NAME]);
    
    ls_uiTextBoxSet(c, &f->editFields[IF_IDX_BONUS], cachedPage.initiative);
    f->compendiumIdx = compendium.pageIndex;
    
    AddMobOnClick(NULL, NULL);
    
    
    
    return TRUE;
}

b32 CompendiumAddPageToInitAlly(UIContext *c, void *userData)
{
    s32 visibleAllies = State.Init->Allies.selectedIndex;
    InitField *f = State.Init->AllyFields + visibleAllies;
    
    if(!compendium.isViewingPage)  return FALSE;
    if(compendium.pageIndex == -1) return FALSE;
    if(visibleAllies == ally_count)  return FALSE;
    
    ls_uiTextBoxSet(c, &f->maxLife, cachedPage.totHP);
    
    u32 buff[32] = {};
    utf32 tmp = { buff, 0, 32 };
    ShortenAndCacheName(cachedPage.name, &tmp);
    AddIncrementalToName(c, tmp, &f->editFields[IF_IDX_NAME]);
    
    ls_uiTextBoxSet(c, &f->editFields[IF_IDX_BONUS], cachedPage.initiative);
    f->compendiumIdx = compendium.pageIndex;
    
    AddAllyOnClick(NULL, NULL);
    
    return TRUE;
}

b32 onStatusChange(UIContext *c, void *data)
{
    s64 mixedIndices = (s64)data;
    s32 ordIndex     = (s32)mixedIndices;
    s32 statusIndex  = mixedIndices >> 32;
    
    Order *ord = State.Init->OrderFields + ordIndex;
    Status *changed = ord->status + statusIndex;
    
    //NOTE: Check for conflicting status on activation!
    Status *all = ord->status;
    if(changed->check.isActive)
    {
        switch(changed->type)
        {
            case STATUS_SCOSSO:
            {
                all[STATUS_SPAVENTATO].check.isActive = FALSE;
                all[STATUS_PANICO].check.isActive     = FALSE;
            } break;
            
            case STATUS_SPAVENTATO:
            {
                all[STATUS_SCOSSO].check.isActive = FALSE;
                all[STATUS_PANICO].check.isActive = FALSE;
            } break;
            
            case STATUS_PANICO:
            {
                all[STATUS_SCOSSO].check.isActive     = FALSE;
                all[STATUS_SPAVENTATO].check.isActive = FALSE;
            } break;
            
            
            case STATUS_ABBAGLIATO: { all[STATUS_ACCECATO].check.isActive   = FALSE; } break;
            case STATUS_ACCECATO:   { all[STATUS_ABBAGLIATO].check.isActive = FALSE; } break;
            
            case STATUS_IMMOBILIZZATO: { all[STATUS_LOTTA].check.isActive         = FALSE; } break;
            case STATUS_LOTTA:         { all[STATUS_IMMOBILIZZATO].check.isActive = FALSE; } break;
            
            case STATUS_AFFATICATO: { all[STATUS_ESAUSTO].check.isActive = FALSE;    } break;
            case STATUS_ESAUSTO:    { all[STATUS_AFFATICATO].check.isActive = FALSE; } break;
        }
    }
    
    //NOTE: We re-cache the page to apply the changes.
    GetPageEntryAndCache(ord->compendiumIdx, ord->ID, &mainCachedPage, ord->status);
    
    return TRUE;
}

//TODO: Using a normal utf32 string is a PROBLEM (especially when mixed with arenas).
//      The reason is, we don't really want these strings in the cachedPage to be re-allocated, or grown.
//      We want the memory to be the same size all the time, and never be handled.
//      What we should really do is make a `StaticUTF32` kind of string, that is only allocated once,
//      And never again. It can't be grown, and will give a runtime error when the space is not enough.
void initCachedPage(CachedPageEntry *cachedPage)
{
    const u32 maxSubtypes    = 8;
    const u32 maxArchetypes  = 4;
    const u32 maxSenses      = 8;
    const u32 maxImmunities  = 16;
    const u32 maxResistances = 16;
    const u32 maxWeaknesses  = 16;
    const u32 maxTalents     = 24;
    const u32 maxSkills      = 24;
    const u32 maxLanguages   = 24;
    const u32 maxSpecials    = 24;
    
    cachedPage->origin            = ls_utf32Alloc(128);
    cachedPage->shortDesc         = ls_utf32Alloc(768);
    cachedPage->AC                = ls_utf32Alloc(192);
    cachedPage->HP                = ls_utf32Alloc(128);
    cachedPage->ST                = ls_utf32Alloc(256);
    cachedPage->RD                = ls_utf32Alloc(128);
    cachedPage->RI                = ls_utf32Alloc(128);
    cachedPage->defensiveCapacity = ls_utf32Alloc(256);
    cachedPage->melee             = ls_utf32Alloc(1280);
    cachedPage->ranged            = ls_utf32Alloc(1280);
    cachedPage->specialAttacks    = ls_utf32Alloc(1536);
    cachedPage->psych             = ls_utf32Alloc(2048);
    cachedPage->magics            = ls_utf32Alloc(2048);
    cachedPage->spells            = ls_utf32Alloc(2560);
    
    cachedPage->tactics_before    = ls_utf32Alloc(448);
    cachedPage->tactics_during    = ls_utf32Alloc(832);
    cachedPage->tactics_stats     = ls_utf32Alloc(736);
    
    cachedPage->racialMods        = ls_utf32Alloc(256);
    cachedPage->spec_qual         = ls_utf32Alloc(512);
    cachedPage->given_equip       = ls_utf32Alloc(512);
    cachedPage->properties        = ls_utf32Alloc(640);
    cachedPage->boons             = ls_utf32Alloc(512);
    
    cachedPage->specials          = ls_utf32Alloc(maxTalents * 2048);
    
    cachedPage->org               = ls_utf32Alloc(512);
    cachedPage->treasure          = ls_utf32Alloc(1024);
    cachedPage->desc              = ls_utf32Alloc(10240);
    cachedPage->source            = ls_utf32Alloc(256);
    
    cachedPage->name              = ls_utf32Alloc(64);
    cachedPage->gs                = ls_utf32Alloc(16);
    cachedPage->pe                = ls_utf32Alloc(16);
    cachedPage->alignment         = ls_utf32Alloc(32);
    cachedPage->type              = ls_utf32Alloc(32);
    cachedPage->subtype           = ls_utf32Alloc(maxSubtypes * 16);
    cachedPage->archetype         = ls_utf32Alloc(maxArchetypes * 32);
    cachedPage->size              = ls_utf32Alloc(32);
    cachedPage->initiative        = ls_utf32Alloc(32);
    cachedPage->senses            = ls_utf32Alloc(maxSenses * 32);
    cachedPage->perception        = ls_utf32Alloc(128);
    cachedPage->aura              = ls_utf32Alloc(128);
    
    cachedPage->immunities        = ls_utf32Alloc(maxImmunities * 32);
    cachedPage->resistances       = ls_utf32Alloc(maxResistances * 32);;
    cachedPage->weaknesses        = ls_utf32Alloc(maxWeaknesses * 32);;
    
    cachedPage->speed             = ls_utf32Alloc(96);
    cachedPage->space             = ls_utf32Alloc(32);
    cachedPage->reach             = ls_utf32Alloc(768);
    
    cachedPage->STR               = ls_utf32Alloc(32);
    cachedPage->DEX               = ls_utf32Alloc(32);
    cachedPage->CON               = ls_utf32Alloc(32);
    cachedPage->INT               = ls_utf32Alloc(32);
    cachedPage->WIS               = ls_utf32Alloc(32);
    cachedPage->CHA               = ls_utf32Alloc(32);
    cachedPage->BAB               = ls_utf32Alloc(32);
    cachedPage->BMC               = ls_utf32Alloc(64);
    cachedPage->DMC               = ls_utf32Alloc(96);
    
    for(s32 i = 0; i < maxTalents; i++) { cachedPage->talents[i] = ls_utf32Alloc(64); }
    cachedPage->skills            = ls_utf32Alloc(maxSkills    * 32);
    cachedPage->languages         = ls_utf32Alloc(maxLanguages * 64);
    cachedPage->environment       = ls_utf32Alloc(96);
}

void LoadCompendium(UIContext *c, string path)
{
    ls_arenaUse(compendiumArena);
    
    ls_uiButtonInit(c, &compendium.addEnemy, UIBUTTON_CLASSIC, U"Add Enemy", CompendiumAddPageToInitMob);
    ls_uiButtonInit(c, &compendium.addAlly, UIBUTTON_CLASSIC, U"Add Ally", CompendiumAddPageToInitAlly);
    
    ls_uiButtonInit(c, &compendium.arch.chooseArchetype, UIBUTTON_CLASSIC, 
                    U"Archetype", CompendiumOpenArchetypeWindow);
    
    for(s32 archIdx = 0; archIdx < MAX_ARCHETYPES; archIdx++)
    { 
        ls_uiButtonInit(c, &compendium.arch.archetypes[archIdx], UIBUTTON_CLASSIC,
                        archetypeName[archIdx], CompendiumSelectArchetype);
        compendium.arch.archetypes[archIdx].data = (void*)((s64)archIdx);
    }
    
    //NOTE: First Initialize the cached page to avoid constant alloc/free when setting it
    initCachedPage(&cachedPage);
    
    //NOTE: Same initialization for the talent entry page
    InitCachedTalentEntry(&compendiumCachedTalent);
    cachedPage.talentPage = &compendiumCachedTalent;
    
    //NOTE: Now load the Compendium from file
    buffer CompendiumBuff = ls_bufferInitFromFile(path);
    
    //NOTE: No valid file was found.
    if(CompendiumBuff.data == 0)
    {
        compendium.codex.names          = ls_bufferInit(128);
        compendium.codex.types          = ls_bufferInit(128);
        compendium.codex.subtypes       = ls_bufferInit(128);
        
        compendium.codex.numericValues  = ls_bufferInit(128);
        compendium.codex.archetypes     = ls_bufferInit(128);
        compendium.codex.senses         = ls_bufferInit(128);
        compendium.codex.auras          = ls_bufferInit(128);
        compendium.codex.immunities     = ls_bufferInit(128);
        compendium.codex.resistances    = ls_bufferInit(128);
        compendium.codex.weaknesses     = ls_bufferInit(128);
        compendium.codex.specialAttacks = ls_bufferInit(128);
        compendium.codex.spells         = ls_bufferInit(128);
        compendium.codex.talents        = ls_bufferInit(128);
        compendium.codex.skills         = ls_bufferInit(128);
        compendium.codex.languages      = ls_bufferInit(128);
        compendium.codex.environment    = ls_bufferInit(128);
        compendium.codex.specials       = ls_bufferInit(128);
        
        compendium.codex.talentsModule  = ls_bufferInit(128);
    }
    else
    {
        const u32 reserve = 32;
        
        //NOTE: We point to the beginning of the block, which contains a 4 bytes size
        //      And also copy the size into the buffer struct itself. This is necessary
        //      Because all the indices in the Page Entries are relative to the complete block, size included
        auto viewIntoBuffer = [reserve](buffer *src, buffer *dst) {
            u8 *blockBegin       = (u8 *)src->data + src->cursor;
            u32 blockSize        = ls_bufferReadDWord(src);
            *dst                 = ls_bufferViewIntoPtr((void *)blockBegin, blockSize);
            ls_bufferReadSkip(src, blockSize);
        };
        
        //NOTE: First we map the talents module
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.talentsModule);
        
        //TODO: Change this to a FixedArray
        u32 talentsCount = ls_bufferReadDWord(&CompendiumBuff);
        u8 *talentsSrc   = (u8 *)CompendiumBuff.data + CompendiumBuff.cursor;
        ls_arrayFromPointer(&compendium.codex.talentPages, (void *)talentsSrc, talentsCount);
        ls_bufferReadSkip(&CompendiumBuff, talentsCount * sizeof(TalentEntry));
        
        //NOTE: Then map the general buffers and mob/npc entries.
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.generalStrings);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.numericValues);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.names);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.types);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.subtypes);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.archetypes);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.sizes);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.senses);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.auras);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.immunities);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.resistances);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.weaknesses);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.specialAttacks);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.spells);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.talents);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.skills);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.languages);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.environment);
        viewIntoBuffer(&CompendiumBuff, &compendium.codex.specials);
        
        //TODO: Change these to a FixedArray
        u32 entryCount = ls_bufferReadDWord(&CompendiumBuff);
        u8 *pagesSrc = (u8 *)CompendiumBuff.data + CompendiumBuff.cursor;
        ls_arrayFromPointer(&compendium.codex.pages, (void *)pagesSrc, entryCount);
        ls_bufferReadSkip(&CompendiumBuff, entryCount * sizeof(PageEntry));
        
        u32 npcEntryCount = ls_bufferReadDWord(&CompendiumBuff);
        u8 *npcPagesSrc = (u8 *)CompendiumBuff.data + CompendiumBuff.cursor;
        ls_arrayFromPointer(&compendium.codex.npcPages, (void *)npcPagesSrc, npcEntryCount);
    }
    
    const u32 currentViewIndicesCount = 3200;
    compendium.viewIndices = ls_arrayAlloc<u16>(currentViewIndicesCount);
    for(u16 i = 0; i < currentViewIndicesCount; i++)
    { ls_arrayAppend(&compendium.viewIndices, i); }
    
    const u32 currentNPCViewIndicesCount = 1200;
    compendium.npcViewIndices = ls_arrayAlloc<u16>(currentNPCViewIndicesCount);
    for(u16 i = 0; i < currentNPCViewIndicesCount; i++)
    { ls_arrayAppend(&compendium.npcViewIndices, i); }
    
    compendium.isViewingMobTable = TRUE;
    
    ls_arenaUse(globalArena);
    
    return;
}

void AppendEntryFromBuffer(buffer *buf, utf32 *base, const char32_t *sep, u32 index, const char *name = "")
{
    if(index == 0) { AssertMsg(FALSE, "We shouldn't be here\n"); return; } //NOTE: Index zero means no entry
    
    buf->cursor = index;
    
    u32 byteLen   = (u32)ls_bufferPeekWord(buf);
    u8 *utf8_data = (u8 *)buf->data + buf->cursor + 2;
    utf8 toAppend = ls_utf8Constant(utf8_data, byteLen);
    u32 sepLen    = 0;
    
    if(sep) { sepLen = ls_utf32Len(sep); }
    
    if(base->len + toAppend.len + sepLen > base->size)
    { ls_printf("%cs: Fuck Size: %d, Len: %d, ByteLen: %d, Index: %d\n", name, base->size, toAppend.len, byteLen, index);
        AssertMsg(FALSE, ""); }
    
    if(sep)
    {
        ls_memcpy((void *)sep, base->data + base->len, sepLen*4);
        base->len += sepLen;
    }
    
    for(u32 i = 0; i < toAppend.len; i++)
    {
        u32 c = ls_utf32CharFromUtf8(toAppend, i);
        base->data[base->len + i] = c;
    }
    base->len += toAppend.len;
    
    ls_bufferSeekBegin(buf);
}

void AppendEntryFromBuffer(buffer *buf, utf32 *base, const char32_t *sep, u16 index, const char *name = "")
{ AppendEntryFromBuffer(buf, base, sep, (u32)index, name); }

void GetEntryFromBuffer_t(buffer *buf, utf32 *toSet, u32 index, const char *name = "")
{
    if(index == 0) { toSet->len = 0; return; } //NOTE: Index zero means no entry
    
    buf->cursor = index;
    
    s32 byteLen   = ls_bufferPeekWord(buf);
    u8 *utf8_data = (u8 *)buf->data + buf->cursor + 2;
    
    u32 len = ls_utf8Len(utf8_data, byteLen);
    
    LogMsgF(toSet->size >= len, "%cs: Fuck Size: %d, Len: %d, ByteLen: %d, Index: %d\n", name, toSet->size, len, byteLen, index);
    
    ls_utf32FromUTF8_t(toSet, utf8_data, len);
    
    ls_bufferSeekBegin(buf);
}

void GetEntryFromBuffer_t(buffer *buf, utf32 *toSet, u16 index, const char *name = "")
{ GetEntryFromBuffer_t(buf, toSet, (u32)index, name); }

utf8 GetEntryFromBuffer_8(buffer *buf, u32 index)
{
    if(index == 0) { return {}; } //NOTE: Index zero means no entry
    
    buf->cursor = index;
    
    u32 byteLen   = (u32)ls_bufferPeekWord(buf);
    u8 *utf8_data = (u8 *)buf->data + buf->cursor + 2;
    
    utf8 result = ls_utf8Constant(utf8_data, (s32)byteLen);
    
    ls_bufferSeekBegin(buf);
    
    return result;
}

utf8 GetEntryFromBuffer_8(buffer *buf, u16 index)
{
    return GetEntryFromBuffer_8(buf, (u32)index);
}

void SetMonsterTable(UIContext *c)
{
    Codex *codex = &compendium.codex;
    
    s32 monsterTableMinY = -((codex->pages.count-30) * 19);
    tableScroll = { 0, 10, c->width-4, c->height-36, 0, 0, c->width-32, monsterTableMinY };
    
    CompendiumSearchData *nameSearchMob = (CompendiumSearchData *)ls_alloc(sizeof(CompendiumSearchData));
    nameSearchMob->searchBar            = &compendium.searchBarNameMobs;
    nameSearchMob->searchBuffer         = &compendium.codex.names;
    nameSearchMob->kind                 = SEARCH_NAME;
    
    compendium.searchBarNameMobs.text         = ls_utf32Alloc(64);
    compendium.searchBarNameMobs.postInput    = CompendiumSearchFunctionMobs;
    compendium.searchBarNameMobs.data         = nameSearchMob;
    compendium.searchBarNameMobs.isSingleLine = TRUE;
    
    CompendiumSearchData *gsSearchMob = (CompendiumSearchData *)ls_alloc(sizeof(CompendiumSearchData));
    gsSearchMob->searchBar            = &compendium.searchBarGSMobs;
    //gsSearchMob->searchBuffer         = &compendium.codex.gs;
    gsSearchMob->kind                 = SEARCH_GS;
    
    compendium.searchBarGSMobs.text         = ls_utf32Alloc(8);
    compendium.searchBarGSMobs.postInput    = CompendiumSearchFunctionMobs;
    compendium.searchBarGSMobs.data         = gsSearchMob;
    compendium.searchBarGSMobs.isSingleLine = TRUE;
    
    CompendiumSearchData *typeSearchMob = (CompendiumSearchData *)ls_alloc(sizeof(CompendiumSearchData));
    typeSearchMob->searchBar            = &compendium.searchBarTypeMobs;
    typeSearchMob->searchBuffer         = &compendium.codex.types;
    typeSearchMob->kind                 = SEARCH_TYPE;
    
    compendium.searchBarTypeMobs.text         = ls_utf32Alloc(64);
    compendium.searchBarTypeMobs.postInput    = CompendiumSearchFunctionMobs;
    compendium.searchBarTypeMobs.data         = typeSearchMob;
    compendium.searchBarTypeMobs.isSingleLine = TRUE;
    
    ls_uiSelectFontByPixelHeight(c, 18);
    
    return;
}

void SetNPCTable(UIContext *c)
{
    Codex *codex = &compendium.codex;
    
    s32 npcTableMinY = -((codex->npcPages.count-30) * 19);
    npcTableScroll = { 0, 10, c->width-4, c->height-36, 0, 0, c->width-32, npcTableMinY };
    
    CompendiumSearchData *nameSearchNPC = (CompendiumSearchData *)ls_alloc(sizeof(CompendiumSearchData));
    nameSearchNPC->searchBar            = &compendium.searchBarNameNPCs;
    nameSearchNPC->searchBuffer         = &compendium.codex.names;
    nameSearchNPC->kind                 = SEARCH_NAME;
    
    UITextBox *name    = &compendium.searchBarNameNPCs;
    name->text         = ls_utf32Alloc(64);
    name->postInput    = CompendiumSearchFunctionNPCs;
    name->data         = nameSearchNPC;
    name->isSingleLine = TRUE;
    
    CompendiumSearchData *gsSearchNPC = (CompendiumSearchData *)ls_alloc(sizeof(CompendiumSearchData));
    gsSearchNPC->searchBar            = &compendium.searchBarGSNPCs;
    //gsSearchNPC->searchBuffer         = &compendium.codex.gs;
    gsSearchNPC->kind                 = SEARCH_GS;
    
    UITextBox *gs    = &compendium.searchBarGSNPCs;
    gs->text         = ls_utf32Alloc(8);
    gs->postInput    = CompendiumSearchFunctionNPCs;
    gs->data         = gsSearchNPC;
    gs->isSingleLine = TRUE;
    
    CompendiumSearchData *typeSearchNPC = (CompendiumSearchData *)ls_alloc(sizeof(CompendiumSearchData));
    typeSearchNPC->searchBar            = &compendium.searchBarTypeNPCs;
    typeSearchNPC->searchBuffer         = &compendium.codex.types;
    typeSearchNPC->kind                 = SEARCH_TYPE;
    
    UITextBox *type    = &compendium.searchBarTypeNPCs;
    type->text         = ls_utf32Alloc(64);
    type->postInput    = CompendiumSearchFunctionNPCs;
    type->data         = typeSearchNPC;
    type->isSingleLine = TRUE;
    
    ls_uiSelectFontByPixelHeight(c, 18);
    
    return;
}

//TODO: IMPORTANT! Status Conditions that apply to AC MUST be applied to DMC as well!!
void CachePage(PageEntry page, s32 viewIndex, CachedPageEntry *cachedPage, Status *status = NULL)
{
    u32 tempUTF32Buffer[4096] = {};
    utf32 tempString = { tempUTF32Buffer, 0, 4096 };
    
    Arena prevArena = ls_arenaUse(compTempArena);
    
    Codex *c = &compendium.codex;
    
    b32 hasArchetype = compendium.appliedArchetypes.count > 0;
    
    cachedPage->pageIndex    = viewIndex;
    
    //TODO: What's missing (apart from possible bug fixes)
    //      Special Attacks
    //      Random Fixes on Attacks/Special Attacks
    //      Maybe DC for Channeling Energy on clerics with Carisma?
    //TODO: Perception is not being modified by statuses! :StatusPerception
    
    //NOTE: Everything tries to be ordered like the struct, to be organized
    //      But I need to have these stats earlier because other paramaters depend on them
    
    //NOTE: GS and PE are moved down below because certain archetypes need those info to determine GS change
    if(hasArchetype)
    {
        GetEntryFromBuffer_t(&c->names, &cachedPage->name, page.name, "name");
        CompendiumApplyAllArchetypeNames(&cachedPage->name);
    }
    else
    {
        GetEntryFromBuffer_t(&c->names, &cachedPage->name, page.name, "name");
    }
    
    //TODO: Remember irrelevant AS (dash instead of a number)
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.STR, "str");
    cachedPage->origAS[AS_STR] = ls_utf32ToInt(tempString);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.DEX, "dex");
    cachedPage->origAS[AS_DEX] = ls_utf32ToInt(tempString);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.CON, "con");
    cachedPage->origAS[AS_CON] = ls_utf32ToInt(tempString);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.INT, "int");
    cachedPage->origAS[AS_INT] = ls_utf32ToInt(tempString);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.WIS, "wis");
    cachedPage->origAS[AS_WIS] = ls_utf32ToInt(tempString);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.CHA, "cha");
    cachedPage->origAS[AS_CHA] = ls_utf32ToInt(tempString);
    ls_utf32Clear(&tempString);
    
    ls_memcpy(cachedPage->origAS, cachedPage->modAS, AS_COUNT*sizeof(s32));
    
    //NOTE: Apply the archetype on the Ability Scores
    if(hasArchetype) { CompendiumApplyAllArchetypeAS(cachedPage->modAS); }
    
    //NOTE: Apply Status Conditions on the Ability Scores
    //TODO: Perception is not being modified by statuses! :StatusPerception
    if(status)
    {
        s32 str = cachedPage->modAS[AS_STR];
        s32 dex = cachedPage->modAS[AS_DEX];
        
        for(s32 i = 0; i < STATUS_COUNT; i++)
        {
            if(!status[i].check.isActive) { continue; }
            
            switch(status[i].type)
            {
                case STATUS_AFFATICATO:   { str -= 2; dex -= 2; } break;
                case STATUS_ESAUSTO:      { str -= 6; dex -= 6; } break;
                case STATUS_INTRALCIATO:  { dex -= 4; }           break;
                case STATUS_LOTTA:        { dex -= 4; }           break;
                
                case STATUS_INDIFESO:     { dex  = 0; }           goto out_of_for_loop;
                case STATUS_PIETRIFICATO: { dex  = 0; }           goto out_of_for_loop;
                case STATUS_PARALIZZATO:  { str  = 0; dex  = 0; } goto out_of_for_loop;
            }
        }
        
        out_of_for_loop:
        
        ls_utf32FromInt_t(&cachedPage->STR, str);
        ls_utf32FromInt_t(&cachedPage->DEX, dex);
    }
    
    //NOTE: Now that the statuses and archetypes have been applied, we cache the AS into strings
    ls_utf32FromInt_t(&cachedPage->STR, cachedPage->modAS[AS_STR]);
    ls_utf32FromInt_t(&cachedPage->DEX, cachedPage->modAS[AS_DEX]);
    ls_utf32FromInt_t(&cachedPage->CON, cachedPage->modAS[AS_CON]);
    ls_utf32FromInt_t(&cachedPage->INT, cachedPage->modAS[AS_INT]);
    ls_utf32FromInt_t(&cachedPage->WIS, cachedPage->modAS[AS_WIS]);
    ls_utf32FromInt_t(&cachedPage->CHA, cachedPage->modAS[AS_CHA]);
    
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->BAB, page.BAB, "bab");
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->treasure, page.treasure, "treasure");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->origin, page.origin, "origin");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->shortDesc, page.shortDesc, "shortDesc");
    
    GetEntryFromBuffer_t(&c->sizes, &cachedPage->size, page.size, "size");
    if(hasArchetype) { CompendiumApplyAllArchetypeSize(&cachedPage->size); }
    
    GetEntryFromBuffer_t(&c->types, &cachedPage->type, page.type, "type");
    
    ls_utf32Clear(&cachedPage->subtype);
    if(page.subtype[0])
    {
        ls_utf32Append(&cachedPage->subtype, ls_utf32Constant(U" ("));
        AppendEntryFromBuffer(&c->subtypes, &cachedPage->subtype, NULL, page.subtype[0]);
        u32 i = 1;
        while(page.subtype[i] && i < 8)
        {
            AppendEntryFromBuffer(&c->subtypes, &cachedPage->subtype, U", ", page.subtype[i]);
            i += 1;
        }
        ls_utf32Append(&cachedPage->subtype, ls_utf32Constant(U") "));
    }
    
    
    ls_utf32Clear(&cachedPage->archetype);
    if(page.archetype[0])
    {
        ls_utf32Append(&cachedPage->archetype, ls_utf32Constant(U"["));
        AppendEntryFromBuffer(&c->archetypes, &cachedPage->archetype, NULL, page.archetype[0]);
        u32 i = 1;
        while(page.archetype[i] && i < 4)
        {
            AppendEntryFromBuffer(&c->archetypes, &cachedPage->archetype, U", ", page.archetype[i]);
            i += 1;
        }
        
        if(hasArchetype) { CompendiumAddAllArchetypesToList(&cachedPage->archetype); }
        
        ls_utf32Append(&cachedPage->archetype, ls_utf32Constant(U"] "));
    }
    else if(hasArchetype)
    {
        CompendiumAddAllArchetypesToList(&cachedPage->archetype);
    }
    
    
    //NOTE: Early talents are for attack modifiers!
    s32 talentsIdx = 0;
    for(s32 tIdx = 0; tIdx < 24; tIdx++) { ls_utf32Clear(&cachedPage->talents[tIdx]); }
    while(page.talents[talentsIdx] && talentsIdx < 24)
    {
        BuildTalentFromPacked_t(c, page.talents[talentsIdx], &tempString);
        ls_utf32Set(&cachedPage->talents[talentsIdx], tempString);
        ls_utf32Clear(&tempString);
        
        cachedPage->talentEntry[talentsIdx] = page.talents[talentsIdx];
        
        talentsIdx += 1;
    }
    
    //NOTE: Racial Mods, Special Qualities
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->racialMods, page.racialMods, "racialMods");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->spec_qual, page.spec_qual, "spec_qual");
    
    //NOTE: General Battle Stats. AC, HP, Saving Throws, BMC/DMC, Initiative, RD/RI
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.AC, "ac");
    CalculateAndCacheAC(tempString, cachedPage, FALSE, status);
    ls_utf32Clear(&tempString);
    
    //GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.HP, "hp");
    ls_utf32Clear(&cachedPage->HP);
    s32 totalHP = CalculateAndCacheHP(cachedPage, page.HP);
    BuildHPFromPacked_t(cachedPage, page.HP, totalHP);
    
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.ST, "st");
    CalculateAndCacheST(tempString, cachedPage, status);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.BMC, "bmc");
    CalculateAndCacheBMC(tempString, cachedPage);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.DMC, "dmc");
    CalculateAndCacheDMC(tempString, cachedPage);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.initiative, "initiative");
    CalculateAndCacheInitiative(tempString, cachedPage, status);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->RD, page.RD, "rd");
    if(hasArchetype) { CompendiumApplyAllArchetypeRD(cachedPage->hitDice, &cachedPage->RD); }
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->RI, page.RI, "ri");
    if(hasArchetype) { CompendiumApplyAllArchetypeRI(cachedPage->gs, &cachedPage->RI); }
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->defensiveCapacity, page.defensiveCapacity, "defensiveCapacity");
    
    //NOTE: GS and PE are moved here because certain archetypes need previous info to determine GS change
    ls_utf32Clear(&cachedPage->gs);
    ls_utf32Clear(&cachedPage->pe);
    if(hasArchetype)
    {
        CompendiumApplyAllArchetypeGS(page.gs, cachedPage->hitDice, &cachedPage->gs, &cachedPage->pe);
    }
    else
    {
        //TODO: Check gsValue and rmValue are in range!
        if(page.gs != GS_SENTINEL_VALUE)
        {
            u16 gsValue = page.gs & 0x003F;
            ls_utf32Set(&cachedPage->gs, CompendiumGetGSEntryFromSet(page.gs));
            ls_utf32Set(&cachedPage->pe, peSet[gsValue]);
        }
        else
        {
            ls_utf32Set(&cachedPage->gs, U"0"_W);
            ls_utf32Set(&cachedPage->pe, U"0"_W);
        }
    }
    
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.melee, "melee");
    CalculateAndCacheMelee(tempString, cachedPage, status);
    ls_utf32Clear(&tempString);
    
    if(hasArchetype) { CompendiumApplyAllArchetypeMelee(&cachedPage->melee); }
    
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.ranged, "ranged");
    CalculateAndCacheRanged(tempString, cachedPage, status);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->specialAttacks, page.specialAttacks, "specialAttacks");
    if(hasArchetype) { CompendiumApplyAllArchetypeSpecAtk(&cachedPage->specialAttacks); }
    
    //NOTE: Spells need a little of pre-processing to handle superscripts (D and S for Dominio and Stirpe)
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.psych, "psych");
    {
        ls_utf32Replace(&tempString, U"\U00001D30", U"[D]");
        ls_utf32Replace(&tempString, U"\U000002E2", U"[S]");
        ls_utf32Replace(&tempString, U"\U00001D2E", U"[B]");
        ls_utf32Replace(&tempString, U"\U00001D39", U"[M]");
        ls_utf32Replace(&tempString, U"\U00002E34", U"");
    }
    ls_utf32Set(&cachedPage->psych, tempString);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.magics, "magics");
    {
        ls_utf32Replace(&tempString, U"\U00001D30", U"[D]");
        ls_utf32Replace(&tempString, U"\U000002E2", U"[S]");
        ls_utf32Replace(&tempString, U"\U00001D2E", U"[B]");
        ls_utf32Replace(&tempString, U"\U00001D39", U"[M]");
        ls_utf32Replace(&tempString, U"\U00002E34", U"");
    }
    ls_utf32Set(&cachedPage->magics, tempString);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.spells, "spells");
    {
        ls_utf32Replace(&tempString, U"\U00001D30", U"[D]");
        ls_utf32Replace(&tempString, U"\U000002E2", U"[S]");
        ls_utf32Replace(&tempString, U"\U00001D2E", U"[B]");
        ls_utf32Replace(&tempString, U"\U00001D39", U"[M]");
        ls_utf32Replace(&tempString, U"\U00002E34", U"");
    }
    ls_utf32Set(&cachedPage->spells, tempString);
    ls_utf32Clear(&tempString);
    
    //NOTE: Mobs don't have tactics/equip/properties or boons. We need to clear it to
    //      avoid pollution from the previous cachedPage
    ls_utf32Clear(&cachedPage->tactics_before);
    ls_utf32Clear(&cachedPage->tactics_during);
    ls_utf32Clear(&cachedPage->tactics_stats);
    
    ls_utf32Clear(&cachedPage->given_equip);
    ls_utf32Clear(&cachedPage->properties);
    ls_utf32Clear(&cachedPage->boons);
    
    ls_utf32Clear(&cachedPage->specials);
    if(page.specials[0])
    {
        GetEntryFromBuffer_t(&c->specials, &cachedPage->specials, page.specials[0], "specials");
        u32 i = 1;
        while(page.specials[i] && i < 24)
        {
            AppendEntryFromBuffer(&c->specials, &cachedPage->specials, U"\n\n", page.specials[i]);
            i += 1;
        }
    }
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->org, page.org, "org");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->desc, page.desc, "desc");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->source, page.source, "source");
    
    //GetEntryFromBuffer_t(&c->alignment, &cachedPage->alignment, page.alignment, "alignment");
    ls_utf32Clear(&cachedPage->alignment);
    BuildAlignmentFromPacked_t(page.alignment, &cachedPage->alignment);
    
    ls_utf32Clear(&cachedPage->senses);
    if(page.senses[0])
    {
        GetEntryFromBuffer_t(&c->senses, &cachedPage->senses, page.senses[0], "senses");
        u32 i = 1;
        while(page.senses[i] && i < 8)
        {
            AppendEntryFromBuffer(&c->senses, &cachedPage->senses, U", ", page.senses[i]);
            i += 1;
        }
    }
    
    if(hasArchetype) { CompendiumApplyAllArchetypeSenses(&cachedPage->senses); }
    
    
    //TODO :StatusPerception
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->perception, page.perception, "perception");
    GetEntryFromBuffer_t(&c->auras, &cachedPage->aura, page.aura, "aura");
    
    ls_utf32Clear(&cachedPage->immunities);
    if(page.immunities[0])
    {
        GetEntryFromBuffer_t(&c->immunities, &cachedPage->immunities, page.immunities[0], "immunities");
        u32 i = 1;
        while(page.immunities[i] && i < 16)
        {
            AppendEntryFromBuffer(&c->immunities, &cachedPage->immunities, U", ", page.immunities[i]);
            i += 1;
        }
    }
    
    ls_utf32Clear(&cachedPage->resistances);
    if(page.resistances[0])
    {
        GetEntryFromBuffer_t(&c->resistances, &cachedPage->resistances, page.resistances[0], "resistances");
        u32 i = 1;
        while(page.resistances[i] && i < 16)
        {
            AppendEntryFromBuffer(&c->resistances, &cachedPage->resistances, U", ", page.resistances[i]);
            i += 1;
        }
    }
    
    if(hasArchetype) { CompendiumApplyAllArchetypeResistances(cachedPage->hitDice, &cachedPage->resistances); }
    
    
    ls_utf32Clear(&cachedPage->weaknesses);
    if(page.weaknesses[0])
    {
        GetEntryFromBuffer_t(&c->weaknesses, &cachedPage->weaknesses, page.weaknesses[0], "weaknesses");
        u32 i = 1;
        while(page.weaknesses[i] && i < 16)
        {
            AppendEntryFromBuffer(&c->weaknesses, &cachedPage->weaknesses, U", ", page.weaknesses[i]);
            i += 1;
        }
    }
    
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->speed, page.speed, "speed");
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->space, page.space, "space");
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->reach, page.reach, "reach");
    
    ls_utf32Clear(&cachedPage->skills);
    s32 i = 0;
    while(page.skills[i] && i < 24)
    {
        if((page.skills[i] & INTERN_BIT_U32) != 0)
        { GetEntryFromBuffer_t(&c->skills, &tempString, (page.skills[i] & (~INTERN_BIT_U32)), "skills"); }
        else
        { 
            i = BuildSkillFromPacked_t(page.skills, i, &tempString);
            AssertMsgF(i <= 23, "When unpacking skill, got invalid index: %d\n", i);
        }
        
        CalculateAndCacheSkill(tempString, cachedPage, status);
        if(i < 23 && page.skills[i+1] != 0) { ls_utf32Append(&cachedPage->skills, ls_utf32Constant(U", ")); }
        ls_utf32Clear(&tempString);
        i += 1;
    }
    
    ls_utf32Clear(&cachedPage->languages);
    if(page.languages[0])
    {
        GetEntryFromBuffer_t(&c->languages, &cachedPage->languages, page.languages[0], "languages");
        u32 i = 1;
        while(page.languages[i] && i < 24)
        {
            AppendEntryFromBuffer(&c->languages, &cachedPage->languages, U", ", page.languages[i]);
            i += 1;
        }
    }
    
    GetEntryFromBuffer_t(&c->environment, &cachedPage->environment, page.environment, "environment");
    
    ls_arenaClear(compTempArena);
    ls_arenaUse(prevArena);
}

void CachePage(NPCPageEntry page, s32 viewIndex, CachedPageEntry *cachedPage, Status *status = NULL)
{
    u32 tempUTF32Buffer[4096] = {};
    utf32 tempString = { tempUTF32Buffer, 0, 4096 };
    
    Arena prevArena = ls_arenaUse(compTempArena);
    
    Codex *c = &compendium.codex;
    
    cachedPage->pageIndex = viewIndex;
    
    //TODO: What's missing (apart from possible bug fixes)
    //      Special Attacks
    //      Random Fixes on Attacks/Special Attacks
    //      Maybe DC for Channeling Energy on clerics with Carisma?
    
    //NOTE: Everything tries to be ordered like the struct, to be organized
    //      But I need to have these stats earlier because other paramaters depend on them
    GetEntryFromBuffer_t(&c->names, &cachedPage->name, page.name, "name");
    
    ls_utf32Clear(&cachedPage->gs);
    ls_utf32Clear(&cachedPage->pe);
    if(page.gs != GS_SENTINEL_VALUE)
    {
        u16 gsValue = page.gs & 0x003F;
        ls_utf32Set(&cachedPage->gs, CompendiumGetGSEntryFromSet(page.gs));
        ls_utf32Set(&cachedPage->pe, peSet[gsValue]);
    }
    else
    {
        ls_utf32Set(&cachedPage->gs, U"0"_W);
        ls_utf32Set(&cachedPage->pe, U"0"_W);
    }
    
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->STR, page.STR, "str");
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->DEX, page.DEX, "dex");
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->CON, page.CON, "con");
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->INT, page.INT, "int");
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->WIS, page.WIS, "wis");
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->CHA, page.CHA, "cha");
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->BAB, page.BAB, "bab");
    
    cachedPage->origAS[AS_STR] = ls_utf32ToInt(cachedPage->STR);
    cachedPage->origAS[AS_DEX] = ls_utf32ToInt(cachedPage->DEX);
    cachedPage->origAS[AS_CON] = ls_utf32ToInt(cachedPage->CON);
    cachedPage->origAS[AS_INT] = ls_utf32ToInt(cachedPage->INT);
    cachedPage->origAS[AS_WIS] = ls_utf32ToInt(cachedPage->WIS);
    cachedPage->origAS[AS_CHA] = ls_utf32ToInt(cachedPage->CHA);
    
    //NOTE: Cache Status Conditions
    if(status)
    {
        s32 str = cachedPage->origAS[AS_STR];
        s32 dex = cachedPage->origAS[AS_DEX];
        
        for(s32 i = 0; i < STATUS_COUNT; i++)
        {
            if(!status[i].check.isActive) { continue; }
            
            switch(status[i].type)
            {
                case STATUS_AFFATICATO:   { str -= 2; dex -= 2; } break;
                case STATUS_ESAUSTO:      { str -= 6; dex -= 6; } break;
                case STATUS_INTRALCIATO:  { dex -= 4; }           break;
                case STATUS_LOTTA:        { dex -= 4; }           break;
                
                case STATUS_INDIFESO:     { dex  = 0; }           goto out_of_for_loop;
                case STATUS_PIETRIFICATO: { dex  = 0; }           goto out_of_for_loop;
                case STATUS_PARALIZZATO:  { str  = 0; dex  = 0; } goto out_of_for_loop;
            }
        }
        
        out_of_for_loop:
        
        ls_utf32FromInt_t(&cachedPage->STR, str);
        ls_utf32FromInt_t(&cachedPage->DEX, dex);
    }
    
    
    //NOTE: NPCs don't have a treasure field. We must clear to avoid pollution from the previous cachedPage
    ls_utf32Clear(&cachedPage->treasure);
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->origin, page.origin, "origin");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->shortDesc, page.shortDesc, "short_desc");
    GetEntryFromBuffer_t(&c->sizes, &cachedPage->size, page.size, "size");
    
    //NOTE: NPC Specific Equip, Properties, Boons
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->given_equip, page.given_equip, "given_equip");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->properties, page.properties, "properties");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->boons, page.boons, "boons");
    
    //NOTE: Type, SubTypes, ArcheTypes
    GetEntryFromBuffer_t(&c->types, &cachedPage->type, page.type, "type");
    
    ls_utf32Clear(&cachedPage->subtype);
    if(page.subtype[0])
    {
        ls_utf32Append(&cachedPage->subtype, ls_utf32Constant(U" ("));
        AppendEntryFromBuffer(&c->subtypes, &cachedPage->subtype, NULL, page.subtype[0], "subtypes");
        u32 i = 1;
        while(page.subtype[i] && i < 8)
        {
            AppendEntryFromBuffer(&c->subtypes, &cachedPage->subtype, U", ", page.subtype[i], "subtypes");
            i += 1;
        }
        ls_utf32Append(&cachedPage->subtype, ls_utf32Constant(U") "));
    }
    
    ls_utf32Clear(&cachedPage->archetype);
    if(page.archetype[0])
    {
        ls_utf32Append(&cachedPage->archetype, ls_utf32Constant(U"["));
        AppendEntryFromBuffer(&c->archetypes, &cachedPage->archetype, NULL, page.archetype[0], "archetypes");
        u32 i = 1;
        while(page.archetype[i] && i < 4)
        {
            AppendEntryFromBuffer(&c->archetypes, &cachedPage->archetype, U", ", page.archetype[i], "archetypes");
            i += 1;
        }
        ls_utf32Append(&cachedPage->archetype, ls_utf32Constant(U"] "));
    }
    
    //NOTE: Early talents are for attack modifiers!
    s32 talentsIdx = 0;
    for(s32 tIdx = 0; tIdx < 24; tIdx++) { ls_utf32Clear(&cachedPage->talents[tIdx]); }
    while(page.talents[talentsIdx] && talentsIdx < 24)
    {
        BuildTalentFromPacked_t(c, page.talents[talentsIdx], &tempString);
        ls_utf32Set(&cachedPage->talents[talentsIdx], tempString);
        ls_utf32Clear(&tempString);
        
        cachedPage->talentEntry[talentsIdx] = page.talents[talentsIdx];
        
        talentsIdx += 1;
    }
    
    //NOTE: Racial Mods, Special Qualities
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->racialMods, page.racialMods, "racial mods");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->spec_qual, page.spec_qual, "spec_qual");
    
    //NOTE: General Battle Stats. AC, HP, Saving Throws, BMC/DMC, Initiative, RD/RI
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.AC, "AC");
    CalculateAndCacheAC(tempString, cachedPage, TRUE, status);
    ls_utf32Clear(&tempString);
    
    //GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.HP, "HP");
    //CalculateAndCacheHP(tempString, cachedPage);
    //ls_utf32Clear(&tempString);
    
    ls_utf32Clear(&cachedPage->HP);
    s32 totalHP = CalculateAndCacheHP(cachedPage, page.HP);
    BuildHPFromPacked_t(cachedPage, page.HP, totalHP);
    
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.ST, "ST");
    CalculateAndCacheST(tempString, cachedPage, status);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.BMC, "BMC");
    CalculateAndCacheBMC(tempString, cachedPage);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.DMC, "DMC");
    CalculateAndCacheDMC(tempString, cachedPage);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->numericValues, &tempString, page.initiative, "initiative");
    CalculateAndCacheInitiative(tempString, cachedPage, status);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->RD, page.RD, "RD");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->RI, page.RI, "RI");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->defensiveCapacity, page.defensiveCapacity, "Def.Cap");
    
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.melee, "Melee");
    CalculateAndCacheMelee(tempString, cachedPage, status);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.ranged, "Ranged");
    CalculateAndCacheRanged(tempString, cachedPage, status);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->specialAttacks, page.specialAttacks, "Spec.Atk");
    
    //NOTE: Spells need a little of pre-processing to handle superscripts (D and S for Dominio and Stirpe)
    //      All the preprocessing sould eventually become obsolete, as I replace them with packed bits
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.psych, "Psych");
    {
        ls_utf32Replace(&tempString, U"\U00001D30", U"[D]");
        ls_utf32Replace(&tempString, U"\U000002E2", U"[S]");
        ls_utf32Replace(&tempString, U"\U00001D2E", U"[B]");
        ls_utf32Replace(&tempString, U"\U00001D39", U"[M]");
        ls_utf32Replace(&tempString, U"\U00002E34", U"");
    }
    ls_utf32Set(&cachedPage->psych, tempString);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.magics, "Magics");
    {
        ls_utf32Replace(&tempString, U"\U00001D30", U"[D]");
        ls_utf32Replace(&tempString, U"\U000002E2", U"[S]");
        ls_utf32Replace(&tempString, U"\U00001D2E", U"[B]");
        ls_utf32Replace(&tempString, U"\U00001D39", U"[M]");
        ls_utf32Replace(&tempString, U"\U00002E34", U"");
    }
    ls_utf32Set(&cachedPage->magics, tempString);
    ls_utf32Clear(&tempString);
    
    GetEntryFromBuffer_t(&c->generalStrings, &tempString, page.spells, "Spells");
    {
        ls_utf32Replace(&tempString, U"\U00001D30", U"[D]");
        ls_utf32Replace(&tempString, U"\U000002E2", U"[S]");
        ls_utf32Replace(&tempString, U"\U00001D2E", U"[B]");
        ls_utf32Replace(&tempString, U"\U00001D39", U"[M]");
        ls_utf32Replace(&tempString, U"\U00002E34", U"");
    }
    ls_utf32Set(&cachedPage->spells, tempString);
    ls_utf32Clear(&tempString);
    
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->tactics_before, page.tactics[0], "tactics-before");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->tactics_during, page.tactics[1], "tactics-during");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->tactics_stats,  page.tactics[2], "tactics-stats");
    
    ls_utf32Clear(&cachedPage->specials);
    if(page.specials[0])
    {
        GetEntryFromBuffer_t(&c->specials, &cachedPage->specials, page.specials[0], "specials");
        u32 i = 1;
        while(page.specials[i] && i < 24)
        {
            AppendEntryFromBuffer(&c->specials, &cachedPage->specials, U"\n\n", page.specials[i], "specials");
            i += 1;
        }
    }
    
    //NOTE: NPCs don't have an org field. We need to clear it to avoid pollution from the previous cachedPage
    ls_utf32Clear(&cachedPage->org);
    
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->desc, page.desc, "desc");
    GetEntryFromBuffer_t(&c->generalStrings, &cachedPage->source, page.source, "source");
    
    //GetEntryFromBuffer_t(&c->alignment, &cachedPage->alignment, page.alignment, "align");
    ls_utf32Clear(&cachedPage->alignment);
    BuildAlignmentFromPacked_t(page.alignment, &cachedPage->alignment);
    
    ls_utf32Clear(&cachedPage->senses);
    if(page.senses[0])
    {
        GetEntryFromBuffer_t(&c->senses, &cachedPage->senses, page.senses[0], "senses");
        u32 i = 1;
        while(page.senses[i] && i < 8)
        {
            AppendEntryFromBuffer(&c->senses, &cachedPage->senses, U", ", page.senses[i], "senses");
            i += 1;
        }
    }
    
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->perception, page.perception, "perception");
    GetEntryFromBuffer_t(&c->auras, &cachedPage->aura, page.aura, "aura");
    
    ls_utf32Clear(&cachedPage->immunities);
    if(page.immunities[0])
    {
        GetEntryFromBuffer_t(&c->immunities, &cachedPage->immunities, page.immunities[0], "immunities");
        u32 i = 1;
        while(page.immunities[i] && i < 16)
        {
            AppendEntryFromBuffer(&c->immunities, &cachedPage->immunities, U", ", page.immunities[i], "immunities");
            i += 1;
        }
    }
    
    ls_utf32Clear(&cachedPage->resistances);
    if(page.resistances[0])
    {
        GetEntryFromBuffer_t(&c->resistances, &cachedPage->resistances, page.resistances[0], "resistances");
        u32 i = 1;
        while(page.resistances[i] && i < 16)
        {
            AppendEntryFromBuffer(&c->resistances, &cachedPage->resistances, U", ", page.resistances[i], "resistances");
            i += 1;
        }
    }
    
    ls_utf32Clear(&cachedPage->weaknesses);
    if(page.weaknesses[0])
    {
        GetEntryFromBuffer_t(&c->weaknesses, &cachedPage->weaknesses, page.weaknesses[0], "weaknesses");
        u32 i = 1;
        while(page.weaknesses[i] && i < 16)
        {
            AppendEntryFromBuffer(&c->weaknesses, &cachedPage->weaknesses, U", ", page.weaknesses[i], "weaknesses");
            i += 1;
        }
    }
    
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->speed, page.speed, "speed");
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->space, page.space, "space");
    GetEntryFromBuffer_t(&c->numericValues, &cachedPage->reach, page.reach, "reach");
    
    ls_utf32Clear(&cachedPage->skills);
    s32 i = 0;
    while(page.skills[i] && i < 24)
    {
        if((page.skills[i] & INTERN_BIT_U32) != 0)
        { GetEntryFromBuffer_t(&c->skills, &tempString, (page.skills[i] & (~INTERN_BIT_U32)), "skills"); }
        else
        { 
            i = BuildSkillFromPacked_t(page.skills, i, &tempString);
            AssertMsgF(i <= 23, "When unpacking skill, got invalid index: %d\n", i);
        }
        
        CalculateAndCacheSkill(tempString, cachedPage, status);
        if(i < 23 && page.skills[i+1] != 0) { ls_utf32Append(&cachedPage->skills, ls_utf32Constant(U", ")); }
        ls_utf32Clear(&tempString);
        i += 1;
    }
    
    ls_utf32Clear(&cachedPage->languages);
    if(page.languages[0])
    {
        GetEntryFromBuffer_t(&c->languages, &cachedPage->languages, page.languages[0], "languages");
        u32 i = 1;
        while(page.languages[i] && i < 24)
        {
            AppendEntryFromBuffer(&c->languages, &cachedPage->languages, U", ", page.languages[i], "languages");
            i += 1;
        }
    }
    
    //NOTE: NPCs don't have an environment field. We need to clear it to avoid pollution from the previous cachedPage
    ls_utf32Clear(&cachedPage->environment);
    
    ls_arenaClear(compTempArena);
    ls_arenaUse(prevArena);
}

//TODO: Make Certain Fields modifiable directly??
s32 DrawPage(UIContext *c, CachedPageEntry *page, s32 baseX, s32 baseY, s32 width, s32 minY)
{
    if(page->talentIndex != -1)
    {
        if(page->talentPage->entryIndex != page->talentIndex)
        { CacheTalentEntry(page->talentPage, page->talentIndex); }
        
        return DrawTalentPage(c, page->talentPage, baseX, baseY, width, minY);
    }
    
    //NOTE: Used to adjust the next line position when changing font size, because
    //      a change in pixel height will make the next line too close / too far from the ideal position.
    s32 prevPixelHeight = 0;
    s32 currPixelHeight = 0;
    
    Color originalTextColor = c->textColor;
    Color pureWhite         = RGBg(0xFF);
    Color missingLink       = RGB(0xAB, 0x0B, 0x06);
    Color availableLink     = RGB(0x47, 0x56, 0xFF);
    c->textColor            = RGBg(0xAA);
    
    //NOTE: Currently layout.maxY shouldn't even be used...
    UILayoutRect baseR  = { c->scroll->x + 10, baseY, c->scroll->x + 10 + width, 0xFEFE, c->scroll->x + 10, baseY };
    UILayoutRect alignR = { baseX, baseY, baseX + width, minY, baseX, baseY };
    UILayoutRect offset = {};
    
    s32 hSepWidth = width;
    
    auto renderAndAlignWS = [&](const char32_t *s) {
        alignR = ls_uiLabelLayout(c, s, alignR);
        //baseR.startY  = offset.startY;
    };
    
    auto renderAndAlignW = [&](utf32 s) {
        alignR  = ls_uiLabelLayout(c, s, alignR);
        //baseR.startY = alignR.startY;
    };
    
    auto renderAndAlignS = [&](const char32_t *s) {
        alignR = baseR;
        alignR = ls_uiLabelLayout(c, s, alignR, pureWhite);
    };
    
    auto renderAndAlign = [&](utf32 s) {
        offset   = ls_uiLabelLayout(c, s, alignR);
        baseR.startY -= offset.maxY;
    };
    
    //---------------//
    //    HEADER     //
    //---------------//
    prevPixelHeight = ls_uiSelectFontByFontSize(c, FS_MEDIUM);
    ls_uiLabelLayout(c, page->name, baseR, pureWhite);
    {
        UILayoutRect headerLayout = baseR; headerLayout.startX += 465;
        ls_uiLabelLayout(c, U"GS", headerLayout, pureWhite); headerLayout.startX += 30;
        ls_uiLabelLayout(c, page->gs, headerLayout, pureWhite); headerLayout.startX += 100;
        ls_uiLabelLayout(c, U"PE", headerLayout, pureWhite); headerLayout.startX += 35;
        offset = ls_uiLabelLayout(c, page->pe, headerLayout, pureWhite);
        ls_uiHSeparator(c, baseR.startX, baseR.startY-4, hSepWidth, 1, RGB(0, 0, 0));
        
        currPixelHeight = ls_uiSelectFontByFontSize(c, FS_SMALL);
        baseR.startY += prevPixelHeight - currPixelHeight; prevPixelHeight = currPixelHeight;
        baseR.startY -= offset.maxY;
        
        if(page->origin.len)
        {
            offset = ls_uiLabelLayout(c, page->origin, baseR, pureWhite);
            baseR.startY -= offset.maxY;
        }
        
        if(page->shortDesc.len)
        {
            offset = ls_uiLabelLayout(c, page->shortDesc, baseR);
            baseR.startY -= (offset.maxY + 4);
        }
        
        renderAndAlignS(U"Allineamento: ");
        renderAndAlign(page->alignment);
        
        renderAndAlignS(U"Categoria: ");
        renderAndAlignW(page->type);
        
        if(page->subtype.len)   renderAndAlignW(page->subtype);
        else                    renderAndAlignWS(U" ");
        if(page->archetype.len) renderAndAlignW(page->archetype);
        else                    renderAndAlignWS(U" ");
        if(page->size.len)      renderAndAlignW(page->size);
        
        baseR.startY -= offset.maxY;
        
        renderAndAlignS(U"Iniziativa: ");
        renderAndAlign(page->initiative);
        
        alignR = baseR;
        renderAndAlignS(U"Sensi: ");
        if(page->senses.len) { renderAndAlignW(page->senses); }
        
        //TODO: This breaks when Perception starts too close to the limit line,
        //      To be fixed the layout system has to use a 6 point bound, rather than just 4 points
        //      So that we have a minimumX and a baseX, to know where to position the newline. @NewLayout
        
        //TODO: This is because the hypergol parser will miss Perception, if the golarion input is not perfect.
        //      Example Meladaemon
        
        //TODO: Muntjac Grigiastro, the spacing between senses and Defense is not large enough.
        if(page->perception.len)
        {
            alignR = ls_uiLabelLayout(c, U"Percezione ", alignR);
            baseR.startY = alignR.startY;
            renderAndAlign(page->perception);
        }
        else { baseR.startY -= offset.maxY; }
        
        if(page->aura.len)
        {
            renderAndAlignS(U"Aura: ");
            renderAndAlign(page->aura);
        }
        //else
        //{ baseR.startY -= 8; }
    }
    
    //---------------//
    //    DEFENSE    //
    //---------------//
    currPixelHeight = ls_uiSelectFontByFontSize(c, FS_MEDIUM);
    baseR.startY -= currPixelHeight - prevPixelHeight; prevPixelHeight = currPixelHeight;
    baseR.startY -= 8;
    {
        offset = ls_uiLabelLayout(c, U"Difesa", baseR, pureWhite);
        ls_uiHSeparator(c, baseR.startX, baseR.startY-4, hSepWidth, 1, RGB(0, 0, 0));
        
        currPixelHeight = ls_uiSelectFontByFontSize(c, FS_SMALL);
        baseR.startY += prevPixelHeight - currPixelHeight; prevPixelHeight = currPixelHeight;
        baseR.startY -= offset.maxY;
        
        if(page->acError == TRUE)
        {
            c->textColor = RGB(0xCC, 0x22, 0x22);
            renderAndAlignS(U"CA: ");
            renderAndAlign(page->AC);
            c->textColor = RGBg(0xAA);
        }
        else {
            renderAndAlignS(U"CA: ");
            renderAndAlign(page->AC);
        }
        
        renderAndAlignS(U"PF: ");
        renderAndAlign(page->HP);
        
        renderAndAlignS(U"Tiri Salvezza: ");
        renderAndAlign(page->ST);
        
        if(page->RD.len)
        {
            renderAndAlignS(U"RD: ");
            renderAndAlign(page->RD);
        }
        
        if(page->RI.len)
        {
            renderAndAlignS(U"RI: ");
            renderAndAlign(page->RI);
        }
        
        if(page->immunities.len)
        {
            renderAndAlignS(U"Immunit\U000000E0: ");
            renderAndAlign(page->immunities);
        }
        
        if(page->resistances.len)
        {
            renderAndAlignS(U"Resistenze: ");
            renderAndAlign(page->resistances);
        }
        
        if(page->defensiveCapacity.len)
        {
            renderAndAlignS(U"Capacit\U000000E0 Difensive: ");
            renderAndAlign(page->defensiveCapacity);
        }
        
        if(page->weaknesses.len)
        {
            renderAndAlignS(U"Debolezze: ");
            renderAndAlign(page->weaknesses);
        }
    }
    
    //---------------//
    //    ATTACK     //
    //---------------//
    
    currPixelHeight = ls_uiSelectFontByFontSize(c, FS_MEDIUM);
    baseR.startY -= currPixelHeight - prevPixelHeight; prevPixelHeight = currPixelHeight;
    baseR.startY -= 8;
    {
        offset = ls_uiLabelLayout(c, U"Attacco", baseR, pureWhite);
        ls_uiHSeparator(c, baseR.startX, baseR.startY-4, hSepWidth, 1, RGB(0, 0, 0));
        
        currPixelHeight = ls_uiSelectFontByFontSize(c, FS_SMALL);
        baseR.startY += prevPixelHeight - currPixelHeight; prevPixelHeight = currPixelHeight;
        baseR.startY -= offset.maxY;
        
        if(page->speed.len)
        {
            renderAndAlignS(U"Velocit\U000000E0: ");
            renderAndAlign(page->speed);
        }
        
        if(page->melee.len)
        {
            if(page->meleeError == TRUE)
            { c->textColor = RGB(0xCC, 0x22, 0x22); }
            
            renderAndAlignS(U"Mischia: ");
            renderAndAlign(page->melee);
            
            c->textColor = RGBg(0xAA);
        }
        
        if(page->ranged.len)
        {
            if(page->rangedError == TRUE)
            { c->textColor = RGB(0xCC, 0x22, 0x22); }
            
            renderAndAlignS(U"Distanza: ");
            renderAndAlign(page->ranged);
            
            c->textColor = RGBg(0xAA);
        }
        
        if(page->specialAttacks.len)
        {
            c->textColor = RGB(0xCC, 0x22, 0x22);
            
#if _DEBUG
            __ui_shouldTag = TRUE;
#endif
            renderAndAlignS(U"Attacchi Speciali: ");
            
#if _DEBUG
            __ui_shouldTag = FALSE;
#endif
            renderAndAlign(page->specialAttacks);
            c->textColor = RGBg(0xAA);
        }
        
        if(page->space.len)
        {
            renderAndAlignS(U"Spazio: ");
            renderAndAlign(page->space);
        }
        
        if(page->reach.len)
        {
            renderAndAlignS(U"Portata: ");
            renderAndAlign(page->reach);
        }
        
        if(page->psych.len)
        {
            renderAndAlignS(U"Magia Psichica: ");
            alignR.minX = baseR.minX + (0.03f*c->width);
            renderAndAlign(page->psych);
        }
        
        if(page->magics.len)
        {
            renderAndAlignS(U"Capacit\U000000E0 Magiche: ");
            alignR.minX = baseR.minX + (0.03f*c->width);
            renderAndAlign(page->magics);
        }
        
        if(page->spells.len)
        {
            renderAndAlignS(U"Incantesimi Conosciuti: ");
            alignR.minX = baseR.minX + (0.03f*c->width);
            renderAndAlign(page->spells);
        }
    }
    
    //---------------//
    //    TACTICS    //
    //---------------//
    
    if(page->tactics_before.len || page->tactics_during.len || page->tactics_stats.len)
    {
        currPixelHeight = ls_uiSelectFontByFontSize(c, FS_MEDIUM);
        baseR.startY -= currPixelHeight - prevPixelHeight; prevPixelHeight = currPixelHeight;
        baseR.startY -= 8;
        {
            offset = ls_uiLabelLayout(c, U"Tattiche", baseR, pureWhite);
            ls_uiHSeparator(c, baseR.startX, baseR.startY-4, hSepWidth, 1, RGB(0, 0, 0));
            
            currPixelHeight = ls_uiSelectFontByFontSize(c, FS_SMALL);
            baseR.startY += prevPixelHeight - currPixelHeight; prevPixelHeight = currPixelHeight;
            baseR.startY -= offset.maxY;
            
            if(page->tactics_before.len)
            {
                renderAndAlignS(U"Prima del Combattimento: ");
                renderAndAlign(page->tactics_before);
            }
            
            if(page->tactics_during.len)
            {
                renderAndAlignS(U"Durante il Combattimento: ");
                renderAndAlign(page->tactics_during);
            }
            
            if(page->tactics_stats.len)
            {
                renderAndAlignS(U"Statistiche Base: ");
                renderAndAlign(page->tactics_stats);
            }
        }
    }
    
    //---------------//
    //     STATS     //
    //---------------//
    
    currPixelHeight = ls_uiSelectFontByFontSize(c, FS_MEDIUM);
    baseR.startY -= currPixelHeight - prevPixelHeight; prevPixelHeight = currPixelHeight;
    baseR.startY -= 8;
    {
        offset = ls_uiLabelLayout(c, U"Statistiche", baseR, pureWhite);
        ls_uiHSeparator(c, baseR.startX, baseR.startY-4, hSepWidth, 1, RGB(0, 0, 0));
        
        currPixelHeight = ls_uiSelectFontByFontSize(c, FS_SMALL);
        baseR.startY += prevPixelHeight - currPixelHeight; prevPixelHeight = currPixelHeight;
        baseR.startY -= offset.maxY;
        
        renderAndAlignS(U"Caratteristiche: ");
        renderAndAlignWS(U"FOR ");   renderAndAlignW(page->STR);
        renderAndAlignWS(U", DEX "); renderAndAlignW(page->DEX);
        renderAndAlignWS(U", COS "); renderAndAlignW(page->CON);
        renderAndAlignWS(U", INT "); renderAndAlignW(page->INT);
        renderAndAlignWS(U", SAG "); renderAndAlignW(page->WIS);
        renderAndAlignWS(U", CAR "); renderAndAlign(page->CHA);
        
        renderAndAlignS(U"BAB: ");
        renderAndAlign(page->BAB);
        
        renderAndAlignS(U"BMC: ");
        renderAndAlign(page->BMC);
        
        renderAndAlignS(U"DMC: ");
        renderAndAlign(page->DMC);
        
        s32 talentIdx = 0;
        if(page->talents[talentIdx].len)
        {
            renderAndAlignS(U"Talenti: ");
            alignR.minX = baseR.minX + (0.03f*c->width);
            while(TRUE)
            {
                if(talentIdx == 23 || page->talents[talentIdx+1].len == 0)
                { 
                    TalentDisplayResult res = CheckTalentTooltipAndClick(c, page, alignR, page->talents[talentIdx],
                                                                         page->talentEntry[talentIdx]);
                    
                    switch(res) {
                        case TSR_NORMAL: {
                            offset   = ls_uiLabelLayout(c, page->talents[talentIdx], alignR);
                            baseR.startY -= offset.maxY;
                        } break;
                        
                        case TSR_AVAILABLE: {
                            offset   = ls_uiLabelLayout(c, page->talents[talentIdx], alignR, availableLink);
                            baseR.startY -= offset.maxY;
                        } break;
                        
                        case TSR_MISSING: { 
                            offset   = ls_uiLabelLayout(c, page->talents[talentIdx], alignR, missingLink);
                            baseR.startY -= offset.maxY;
                        } break;
                    }
                    
                    break;
                }
                
                TalentDisplayResult res = CheckTalentTooltipAndClick(c, page, alignR, page->talents[talentIdx], 
                                                                     page->talentEntry[talentIdx]);
                
                switch(res) {
                    case TSR_NORMAL: {
                        alignR = ls_uiLabelLayout(c, page->talents[talentIdx], alignR);
                    } break;
                    
                    case TSR_AVAILABLE: {
                        alignR = ls_uiLabelLayout(c, page->talents[talentIdx], alignR, availableLink);
                    } break;
                    
                    case TSR_MISSING: { 
                        alignR = ls_uiLabelLayout(c, page->talents[talentIdx], alignR, missingLink);
                    } break;
                }
                
                renderAndAlignWS(U", ");
                baseR.startY = alignR.startY;
                talentIdx += 1;
            }
        }
        
        if(page->skills.len)
        {
            renderAndAlignS(U"Abilit\U000000E0: ");
            alignR.minX = baseR.minX + (0.03f*c->width);
            renderAndAlign(page->skills);
        }
        
        if(page->languages.len)
        {
            renderAndAlignS(U"Linguaggi: ");
            renderAndAlign(page->languages);
        }
        
        if(page->racialMods.len)
        {
            renderAndAlignS(U"Modificatori Razziali: ");
            renderAndAlign(page->racialMods);
        }
        
        if(page->spec_qual.len)
        {
            renderAndAlignS(U"Qualit\U000000E0 Speciali: ");
            renderAndAlign(page->spec_qual);
        }
        
        if(page->given_equip.len)
        {
            renderAndAlignS(U"Dotazioni da Combattimento: ");
            renderAndAlign(page->given_equip);
        }
        
        if(page->properties.len)
        {
            renderAndAlignS(U"Propriet\U000000E0: ");
            renderAndAlign(page->properties);
        }
        
        if(page->boons.len)
        {
            renderAndAlignS(U"Beneficio: ");
            renderAndAlign(page->boons);
        }
    }
    
    //---------------//
    //   SPECIALS    //
    //---------------//
    
    if(page->specials.len)
    {
        currPixelHeight = ls_uiSelectFontByFontSize(c, FS_MEDIUM);
        baseR.startY -= currPixelHeight - prevPixelHeight; prevPixelHeight = currPixelHeight;
        baseR.startY -= 8;
        {
            offset = ls_uiLabelLayout(c, U"Capacit\U000000E0 Speciali:", baseR, pureWhite);
            ls_uiHSeparator(c, baseR.startX, baseR.startY-4, hSepWidth, 1, RGB(0, 0, 0));
            
            currPixelHeight = ls_uiSelectFontByFontSize(c, FS_SMALL);
            baseR.startY += prevPixelHeight - currPixelHeight; prevPixelHeight = currPixelHeight;
            baseR.startY -= offset.maxY;
            baseR.startY -= 8; //NOTE: Random spacing because it feels cramped
            
            offset = ls_uiLabelLayout(c, page->specials, baseR);
            baseR.startY -= (offset.maxY + 8);
        }
    }
    
    //---------------//
    //      ORG      //
    //---------------//
    
    if(page->environment.len || page->org.len || page->treasure.len)
    {
        currPixelHeight = ls_uiSelectFontByFontSize(c, FS_MEDIUM);
        baseR.startY -= currPixelHeight - prevPixelHeight; prevPixelHeight = currPixelHeight;
        baseR.startY -= 8;
        {
            offset = ls_uiLabelLayout(c, U"Ecologia", baseR, pureWhite);
            ls_uiHSeparator(c, baseR.startX, baseR.startY-4, hSepWidth, 1, RGB(0, 0, 0));
            baseR.startY -= offset.maxY;
            
            currPixelHeight = ls_uiSelectFontByFontSize(c, FS_SMALL);
            baseR.startY += prevPixelHeight - currPixelHeight; prevPixelHeight = currPixelHeight;
            
            renderAndAlignS(U"Ambiente: ");
            renderAndAlign(page->environment);
            
            renderAndAlignS(U"Organizzazione: ");
            renderAndAlign(page->org);
            
            renderAndAlignS(U"Tesoro: ");
            renderAndAlign(page->treasure);
        }
    }
    
    //---------------//
    //     FINAL     //
    //---------------//
    currPixelHeight = ls_uiSelectFontByFontSize(c, FS_MEDIUM);
    baseR.startY -= currPixelHeight - prevPixelHeight; prevPixelHeight = currPixelHeight;
    baseR.startY -= 8;
    {
        offset = ls_uiLabelLayout(c, U"Descrizione", baseR, pureWhite);
        ls_uiHSeparator(c, baseR.startX, baseR.startY-4, hSepWidth, 1, RGB(0, 0, 0));
        baseR.startY -= offset.maxY;
        
        currPixelHeight = ls_uiSelectFontByFontSize(c, FS_SMALL);
        baseR.startY += prevPixelHeight - currPixelHeight; prevPixelHeight = currPixelHeight;
        
        offset = ls_uiLabelLayout(c, page->desc, baseR);
        baseR.startY -= offset.maxY;
        
        baseR.startY += (currPixelHeight-1);
        ls_uiHSeparator(c, baseR.startX, baseR.startY-4, hSepWidth, 1, RGB(0, 0, 0));
        
        
        //TODO: Make these links openable.
        //      To do it we need to call this function
        //      https://learn.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-shellexecutea
        //
        //      Leaving the "verb" (second param) null and passing the http link should open the page in the
        //      default browser.
        //
        //      If that doesn't work, windows in both CommandPrompt and Powershell has a "start" command
        //      that opens whatever path you give it with the appropriate command. So an http link should get
        //      opened in the default browser.
        
        baseR.startY -= (currPixelHeight+8);
        renderAndAlignS(U"Fonte: ");
        renderAndAlign(page->source);
    }
    
    c->textColor = originalTextColor;
    
    return baseR.startY;
}

void DrawNPCTable(UIContext *c)
{
    Input *UserInput = &c->UserInput;
    Codex *codex     = &compendium.codex;
    
    Color bkgColor = RGBg(0x40);
    
    s32 baseX = 20;
    s32 baseY = 630;
    
    ls_uiTextBox(c, &compendium.searchBarNameNPCs, baseX, baseY + 40, 200, 20);
    ls_uiTextBox(c, &compendium.searchBarGSNPCs,   baseX + 295, baseY + 40, 60, 20);
    ls_uiTextBox(c, &compendium.searchBarTypeNPCs, baseX + 375, baseY + 40, 160, 20);
    
    ls_uiStartScrollableRegion(c, &npcTableScroll);
    
    s32 startI = -(npcTableScroll.deltaY / 19);
    s32 endI   = startI+36 < compendium.npcViewIndices.count ? startI+36 : compendium.npcViewIndices.count;
    endI       = endI < codex->npcPages.count ? endI : codex->npcPages.count;
    
    for(s32 i = startI; i < endI; i++)
    {
        NPCPageEntry entry = codex->npcPages[compendium.npcViewIndices[i]];
        Color hoverColor = bkgColor;
        
        if(LeftClickIn(baseX-4, baseY-4, 300, 18)) //TODONOTE: I don't like it...
        {
            compendium.isViewingPage = TRUE;
            compendium.isViewingNPCTable = FALSE;
            compendium.pageIndex  = compendium.npcViewIndices[i] + NPC_PAGE_INDEX_OFFSET;
        }
        
        if(MouseInRect(baseX-4, baseY-4, 300, 18)) { hoverColor = RGBg(0x66); }
        
        //NOTE: Matriarca delle Scimmie Cappuccine Corallo is too long...
        //      Adding a scissor cuts it... but I don't like that solution a lot...
        //      What if I want automatic '...' at the end of a label??
        ls_uiRect(c, baseX-4, baseY+npcTableScroll.deltaY-4, 300, 20, hoverColor, c->borderColor);
        c->scissor = UIRect { baseX-4, 0, 298, s32(c->height) };
        ls_uiLabel(c, GetEntryFromBuffer_8(&codex->names, entry.name), baseX, baseY+npcTableScroll.deltaY, 1);
        c->scissor = UIRect { 0, 0, s32(c->width), s32(c->height) };
        baseX += 299;
        
        ls_uiRect(c, baseX-4, baseY+npcTableScroll.deltaY-4, 80, 20, bkgColor, c->borderColor);
        ls_uiLabel(c, CompendiumGetGSEntryFromSet(entry.gs), baseX, baseY+npcTableScroll.deltaY, 1);
        baseX += 79;
        
        ls_uiRect(c, baseX-4, baseY+npcTableScroll.deltaY-4, 180, 20, bkgColor, c->borderColor);
        ls_uiLabel(c, GetEntryFromBuffer_8(&codex->types, entry.type), baseX, baseY+npcTableScroll.deltaY, 1);
        baseX += 179;
        
        //TODO: Show all subtypes. Right now we only grab one.
        //      We can do this by overloading the function GetEntryFromBuffer and passing the array itself.
        ls_uiRect(c, baseX-4, baseY+npcTableScroll.deltaY-4, 188, 20, bkgColor, c->borderColor);
        ls_uiLabel(c, GetEntryFromBuffer_8(&codex->subtypes, entry.subtype[0]), baseX, baseY+npcTableScroll.deltaY, 1);
        baseX += 187;
        
        baseY -= 19;
        baseX = 20;
    }
    
    ls_uiEndScrollableRegion(c);
    
}

void DrawMonsterTable(UIContext *c)
{
    Input *UserInput = &c->UserInput;
    Codex *codex     = &compendium.codex;
    
    Color bkgColor = RGBg(0x40);
    
    s32 baseX = 20;
    s32 baseY = 630;
    
    ls_uiTextBox(c, &compendium.searchBarNameMobs, baseX, baseY + 40, 200, 20);
    ls_uiTextBox(c, &compendium.searchBarGSMobs,   baseX + 295, baseY + 40, 60, 20);
    ls_uiTextBox(c, &compendium.searchBarTypeMobs, baseX + 375, baseY + 40, 160, 20);
    
    ls_uiStartScrollableRegion(c, &tableScroll);
    
    s32 startI = -(tableScroll.deltaY / 19);
    s32 endI   = startI+36 < compendium.viewIndices.count ? startI+36 : compendium.viewIndices.count;
    endI       = endI < codex->pages.count ? endI : codex->pages.count;
    
    for(s32 i = startI; i < endI; i++)
    {
        PageEntry entry = codex->pages[compendium.viewIndices[i]];
        Color hoverColor = bkgColor;
        
        if(LeftClickIn(baseX-4, baseY-4, 300, 18)) //TODONOTE: I don't like it...
        {
            compendium.isViewingPage = TRUE; 
            compendium.isViewingMobTable = FALSE;
            compendium.pageIndex     = compendium.viewIndices[i];
        }
        
        if(MouseInRect(baseX-4, baseY-4, 300, 18)) { hoverColor = RGBg(0x66); }
        
        //NOTE: Matriarca delle Scimmie Cappuccine Corallo is too long...
        //      Adding a scissor cuts it... but I don't like that solution a lot...
        //      What if I want automatic '...' at the end of a label??
        ls_uiRect(c, baseX-4, baseY+tableScroll.deltaY-4, 300, 20, hoverColor, c->borderColor);
        c->scissor = UIRect { baseX-4, 0, 298, s32(c->height) };
        ls_uiLabel(c, GetEntryFromBuffer_8(&codex->names, entry.name), baseX, baseY+tableScroll.deltaY, 1);
        c->scissor = UIRect { 0, 0, s32(c->width), s32(c->height) };
        baseX += 299;
        
        ls_uiRect(c, baseX-4, baseY+tableScroll.deltaY-4, 80, 20, bkgColor, c->borderColor);
        ls_uiLabel(c, CompendiumGetGSEntryFromSet(entry.gs), baseX, baseY+tableScroll.deltaY, 1);
        baseX += 79;
        
        ls_uiRect(c, baseX-4, baseY+tableScroll.deltaY-4, 180, 20, bkgColor, c->borderColor);
        ls_uiLabel(c, GetEntryFromBuffer_8(&codex->types, entry.type), baseX, baseY+tableScroll.deltaY, 1);
        baseX += 179;
        
        //TODO: Show all subtypes. Right now we only grab one.
        //      We can do this by overloading the function GetEntryFromBuffer and passing the array itself.
        ls_uiRect(c, baseX-4, baseY+tableScroll.deltaY-4, 188, 20, bkgColor, c->borderColor);
        ls_uiLabel(c, GetEntryFromBuffer_8(&codex->subtypes, entry.subtype[0]), baseX, baseY+tableScroll.deltaY, 1);
        baseX += 187;
        
        baseY -= 19;
        baseX = 20;
    }
    
    ls_uiEndScrollableRegion(c);
    
    return;
}

#if _DEBUG
void testAllCompendiumForAsserts(UIContext *c, b32);
#endif

b32 DrawCompendium(UIContext *c)
{
    //NOTE: This arena is cleared every frame,
    //      Because here we store utf32 strings (currently only for the Search Function)
    ls_arenaClear(compTempArena);
    
    Codex *codex = &compendium.codex;
    Input *UserInput = &c->UserInput;
    
    b32 userInput = FALSE;
    
#if _DEBUG
    if(KeyPress(keyMap::F1))
    {
        b32 logNames = KeyHeld(keyMap::Shift);
        testAllCompendiumForAsserts(c, logNames);
    }
#endif
    
    if(compendium.isViewingNPCTable)
    {
        DrawNPCTable(c); 
    }
    else if(compendium.isViewingMobTable)
    {
        DrawMonsterTable(c);
    }
    /*
    else if(compendium.isViewingTalentPage)
    {
        if(cachedTalent.entryIndex != compendium.talentIndex)
        {
            CacheTalentEntry(&cachedTalent, compendium.talentIndex);
        }
        
        DrawTalentPage(c, &cachedTalent, 0, 670, c->width-42, 0 );
        
        if(KeyPress(keyMap::Escape)) { CompendiumOpenPageView(); }
    }*/
    else if(compendium.isViewingPage)
    {
        //NOTE: We draw the buttons only when on an actual creature page.
        if(cachedPage.talentIndex == -1)
        {
            userInput |= ls_uiButton(c, &compendium.addEnemy, 
                                     0.01f*c->width, c->height - 0.060*c->height, c->menuBarColor);
            userInput |= ls_uiButton(c, &compendium.addAlly, 
                                     0.14f*c->width, c->height - 0.060*c->height, c->menuBarColor);
            userInput |= ls_uiButton(c, &compendium.arch.chooseArchetype, 
                                     0.27f*c->width, c->height - 0.060*c->height, c->menuBarColor);
        }
        
        ls_uiHSeparator(c, 0.01f*c->width, (c->height - 0.066*c->height)+1, c->width - 0.04f*c->width, 1, RGBg(0));
        ls_uiHSeparator(c, 0.01f*c->width, c->height - 0.066*c->height, c->width - 0.04f*c->width, 1, RGBg(0xDD));
        ls_uiHSeparator(c, 0.01f*c->width, (c->height - 0.066*c->height)-1, c->width - 0.04f*c->width, 1, RGBg(0));
        
        //NOTE: It's a Mob's Page Index
        if(compendium.pageIndex < NPC_PAGE_INDEX_OFFSET)
        {
            if(KeyHeld(keyMap::Shift) && KeyPressOrRepeat(keyMap::DArrow) && compendium.pageIndex < (codex->pages.count-1))
            { compendium.pageIndex += 1; ls_staticArrayClear(&compendium.appliedArchetypes); }
            
            if(KeyHeld(keyMap::Shift) && KeyPressOrRepeat(keyMap::UArrow) && compendium.pageIndex > 0)
            { compendium.pageIndex -= 1; ls_staticArrayClear(&compendium.appliedArchetypes); }
            
            if(cachedPage.pageIndex != compendium.pageIndex)
            { 
                PageEntry pEntry = compendium.codex.pages[compendium.pageIndex];
                CachePage(pEntry, compendium.pageIndex, &cachedPage);
                
                //NOTE: Reset the page scroll for the new page (Fuck GCC)
                pageScroll = { 0, 10, c->width-4, c->height-60, 0, 0, c->width-32, 0 };
            }
            
            //NOTE: The first frame is impossible to scroll, because the minY value will be not initialized yet
            //      It's should be fine though. We run at 30FPS on the Compendium, so it should never be felt/seen.
            //      The minY is set by the DrawPage call itself
            ls_uiStartScrollableRegion(c, &pageScroll);
            pageScroll.minY = DrawPage(c, &cachedPage, 0, 646, c->width-42, 0);
            //TODO: When the page is smaller than the viewport, it ends up flip-flopping if we don't clamp it.
            //      Kind of annoying. Can we do something like this in endscrollaberegion automatically?
            if(pageScroll.minY > -19) { pageScroll.minY = -1; }
            ls_uiEndScrollableRegion(c);
        }
        else
        {
            s32 npcPageIndex = compendium.pageIndex - NPC_PAGE_INDEX_OFFSET;
            
            if(KeyHeld(keyMap::Shift) && KeyPressOrRepeat(keyMap::DArrow) && npcPageIndex < (codex->npcPages.count-1))
            { compendium.pageIndex += 1; npcPageIndex += 1; ls_staticArrayClear(&compendium.appliedArchetypes); }
            
            if(KeyHeld(keyMap::Shift) && KeyPressOrRepeat(keyMap::UArrow) && npcPageIndex > 0)
            { compendium.pageIndex -= 1; npcPageIndex -= 1; ls_staticArrayClear(&compendium.appliedArchetypes); }
            
            if(cachedPage.pageIndex != compendium.pageIndex)
            { 
                NPCPageEntry pEntry = compendium.codex.npcPages[npcPageIndex];
                CachePage(pEntry, compendium.pageIndex, &cachedPage);
                
                //NOTE: Reset the page scroll for the new page (Fuck GCC)
                pageScroll = { 0, 10, c->width-4, c->height-60, 0, 0, c->width-32, 0 };
            }
            
            //NOTE: The first frame is impossible to scroll, because the minY value will be not initialized yet
            //      It's should be fine though. We run at 30FPS on the Compendium, so it should never be felt/seen.
            //      The minY is set by the DrawPage call itself
            ls_uiStartScrollableRegion(c, &pageScroll);
            pageScroll.minY = DrawPage(c, &cachedPage, 0, 646, c->width-42, 0);
            //TODO: When the page is smaller than the viewport, it ends up flip-flopping if we don't clamp it.
            //      Kind of annoying. Can we do something like this in endscrollaberegion automatically?
            if(pageScroll.minY > -19) { pageScroll.minY = -1; }
            ls_uiEndScrollableRegion(c);
        }
    }
    else
    {
        AssertMsg(FALSE, "Unhandled page viewing in Compendium\n");
    }
    
    //TODO: Disallow selecting the same archetype multiple times.
    //TODO: Put a limit to the number of archetypes that can be selected at once (probably around 4)
    //TODO: Certain archetypes can't be allowed on certain creatures. 
    //      Example: Giant can't be applied to Colossal Creatures.
    if(compendium.arch.isChoosingArchetype == TRUE)
    {
        //NOTE: Draw the Archetype Selection Window
        
        //NOTE: Darken the Compendium Page to indicate inactiveness
        ls_uiRect(c, 0, 0, c->width, 0.935f*c->height, RGBA(0, 0, 0, 0xAA), RGBA(0, 0, 0, 0xAA), 1);
        
        //NOTE: Draw the Archetype Selection Window
        ls_uiRect(c, 0.1f*c->width, 0.47f*c->height, 0.8f*c->width, 0.33f*c->height, 2);
        
        //NOTE: Draw all the available archetype selection buttons
        s32 baseX = 0.12f*c->width;
        s32 baseY = 0.74f*c->height;
        
        for(s32 archIdx = 0; archIdx < MAX_ARCHETYPES; archIdx++)
        {
            ls_uiButton(c, &compendium.arch.archetypes[archIdx], baseX, baseY, 3);
            
            baseX += 0.04f*c->width + compendium.arch.archetypes[archIdx].w;
            if(archIdx > 5)
            {
                baseX  = 0.12f*c->width;
                baseY -= 0.064f*c->height;
            }
        }
    }
    
    return userInput;
}