//
//  AppDelegate.m
//  HyperPCMan
//
//  Created by Lowy on 13/11/2019.
//  Copyright © 2019 Lowy. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)control:(NSControl *)control textView:(NSTextView *)textView doCommandBySelector:(SEL)commandSelector {
    ViewController *v = mainVC;
    
    if (commandSelector == @selector(insertNewline:)) {
    // Do something against ENTER key
    NSInteger allyNum = [v->AllySelector indexOfSelectedItem];
    NSInteger mobNum = [v->MobSelector indexOfSelectedItem];
    
        for(int i = 0; i < allyNum; i++) {
            void *LabelField = (__bridge void *)(v->Allies[i]->Box->Label);
            void *BonusField = (__bridge void *)(v->Allies[i]->Box->Box);
            void *InitField = (__bridge void *)(v->Allies[i]->Init);
            
            if((__bridge void *)control == LabelField) {
                if((i+1) == allyNum) { return YES; }
                [v->Allies[i+1]->Box->Label setStringValue:@""];
                [control.window makeFirstResponder:v->Allies[i+1]->Box->Label];
                return YES;
            }
            
            if((__bridge void *)control == BonusField) {
                if((i+1) == allyNum) { return YES; }
                [v->Allies[i+1]->Box->Box setStringValue:@""];
                [control.window makeFirstResponder:v->Allies[i+1]->Box->Box];
                return YES;
            }

            if((__bridge void *)control == InitField) {
                if((i+1) == allyNum) { return YES; }
                [v->Allies[i+1]->Init setStringValue:@""];
                [control.window makeFirstResponder:v->Allies[i+1]->Init];
                return YES;
            }
        }
        
        for(int i = 0; i < mobNum; i++) {
            void *LabelField = (__bridge void *)(v->Mobs[i]->Box->Label);
            void *BonusField = (__bridge void *)(v->Mobs[i]->Box->Box);
            void *InitField = (__bridge void *)(v->Mobs[i]->Init);
            
            if((__bridge void *)control == LabelField) {
                if((i+1) == mobNum) { return YES; }
                [v->Mobs[i+1]->Box->Label setStringValue:@""];
                [control.window makeFirstResponder:v->Mobs[i+1]->Box->Label];
                return YES;
            }
            
            if((__bridge void *)control == BonusField) {
                if((i+1) == mobNum) { return YES; }
                [v->Mobs[i+1]->Box->Box setStringValue:@""];
                [control.window makeFirstResponder:v->Mobs[i+1]->Box->Box];
                return YES;
            }

            if((__bridge void *)control == InitField) {
                if((i+1) == mobNum) { return YES; }
                [v->Mobs[i+1]->Init setStringValue:@""];
                [control.window makeFirstResponder:v->Mobs[i+1]->Init];
                return YES;
            }
        }
        
        for(int i = 0; i < PARTY_SIZE; i++) {
            void *InitField = (__bridge void *)(v->Heros[i]->Box->Box);
            if((__bridge void *)control == InitField) {
                if((i + 1) == PARTY_SIZE) { return YES; }
                [control.window makeFirstResponder:v->Heros[i+1]->Box->Box];
                return YES;
            }
        }
        
        [control.window makeFirstResponder:control.window];
        return YES;
    }
    
    // return true if the action was handled; otherwise false
    return NO;
}
  
- (void)comboBoxSelectionDidChange:(NSNotification *)notification {
    
    NSComboBox *t = notification.object;
    
    if(t.identifier == mainVC->MobSelector.identifier)
    {
        mainVC->currentTurnIdx = 0;
        
        NSInteger num = [mainVC->MobSelector indexOfSelectedItem];
        [mainVC resetMobs];
        for(int i = 0; i < num; i++) { [mainVC->Mobs[i] show]; }
               
        NSInteger allyNum = [mainVC->AllySelector indexOfSelectedItem];
        [mainVC showNOrder:(num + allyNum + PARTY_SIZE - mainVC->notInBattle)];
    }
    else if(t.identifier == mainVC->AllySelector.identifier)
    {
        mainVC->currentTurnIdx = 0;

        NSInteger num = [mainVC->AllySelector indexOfSelectedItem];
        [mainVC resetAllies];
        for(int i = 0; i < num; i++) { [mainVC->Allies[i] show]; }
        
        NSInteger mobNum = [mainVC->MobSelector indexOfSelectedItem];
        [mainVC showNOrder:(num + mobNum + PARTY_SIZE - mainVC->notInBattle)];
    }
}

- (void)SetupInitTab:(NSTabViewItem *)item {
                
    int yPos = 750;
    for(int i = 0; i < PARTY_SIZE; i++) {
    
        //TODO: Remove the formatter from hero. Maybe make it a BattleEntity
        //      as well?
        BattleEntity *Hero = [[BattleEntity alloc]initHero:NSMakeRect(525, yPos, 30, 20) name:HeroNames[i]];
                   
        CheckButton *InBattle = [[CheckButton alloc] initWithAction:NSMakeRect(560, yPos, 20, 20) blk:^void(CheckButton *s){
            ViewController *vc = self->mainVC;
            NSInteger mobs = [vc->MobSelector indexOfSelectedItem];
            NSInteger allies = [vc->AllySelector indexOfSelectedItem];
            if([s->Button state] == NSControlStateValueOff) {
                vc->notInBattle += 1;
                [vc showNOrder:(mobs + allies + PARTY_SIZE - vc->notInBattle)];
            }
            else if([s->Button state] == NSControlStateValueOn) {
                self->mainVC->notInBattle -= 1;
                [vc showNOrder:(mobs + allies + PARTY_SIZE - vc->notInBattle)];
            }
        }];
        
        [Hero->Box->Box setDelegate:self];
        [[item view] addSubview:Hero->Box->Box];
        [[item view] addSubview:Hero->Box->Label];
        [[item view] addSubview:InBattle->Button];
        mainVC->Heros[i] = Hero;
        mainVC->InBattle[i] = InBattle;
        yPos -= 30;
    }
        
    for(int i = 0; i < ALLY_SIZE; i++) {
    
        BattleEntity *Ally = [[BattleEntity alloc] initWithFrame:NSMakeRect(525, yPos, 70, 20) name:AllyNames[i]];
                   
        [Ally->Box->Label setDelegate:self];
        [Ally->Box->Box setDelegate:self];
        [Ally->Init setDelegate:self];
        [[item view] addSubview:Ally->Box->Box];
    	[[item view] addSubview:Ally->Box->Label];
        [[item view] addSubview:Ally->Init];
        mainVC->Allies[i] = Ally;
        yPos -= 30;
    }
 
    yPos = 750;
    for(int i = 0; i < MOB_SIZE; i++) {

        BattleEntity *Mob = [[BattleEntity alloc] initWithFrame:NSMakeRect(365, yPos, 70, 20) name:EnemyNames[i]];
        
        [Mob->Box->Label setDelegate:self];
        [Mob->Box->Box setDelegate:self];
        [Mob->Init setDelegate:self];
        [[item view] addSubview:Mob->Box->Box];
        [[item view] addSubview:Mob->Box->Label];
        [[item view] addSubview:Mob->Init];
        mainVC->Mobs[i] = Mob;
        yPos -= 30;
    }
    
    yPos = 750;
    for(int i = 0; i < ORDER_SIZE; i++) {
         //NOTE:TODO: Something fucky happening. Slowdown HERE! In button creation
        OrderField *Order = [[OrderField alloc]
                             initOrder:CGPointMake(680, yPos) num:i+1];
                
        [[item view] addSubview:Order->Name];
        [[item view] addSubview:Order->Num];
        [[item view] addSubview:Order->Remove->Button];
        mainVC->Order[i] = Order;
        yPos -= 22;
    }
    
    mainVC->CurrentInTurn = [[NSTextField alloc] initWithFrame:NSMakeRect(820, 750, 120, 20)];
    [mainVC->CurrentInTurn setAlignment:NSTextAlignmentCenter];
    [mainVC->CurrentInTurn setEditable:false];
    [[item view] addSubview:mainVC->CurrentInTurn];
    
    mainVC->RoundCount = [[NSTextField alloc] initWithFrame:NSMakeRect(1200, 820, 30, 20)];
    [mainVC->RoundCount setAlignment:NSTextAlignmentCenter];
    [mainVC->RoundCount setEditable:false];
    [[item view] addSubview:mainVC->RoundCount];
    
    ActionButton *Reset = [[ActionButton alloc] initWithAction:NSMakeRect(20, 810, 80, 24) name:@"Reset" blk:^void(){
        ViewController *vc = self->mainVC;
        [vc resetMobs]; [vc resetAllies]; [vc resetOrder];
        [vc->MobSelector selectItemAtIndex:0];
        [vc->AllySelector selectItemAtIndex:0];
        [vc->RoundCount setStringValue:@""];
        [vc->CurrentInTurn setStringValue:@""];
        vc->currentTurnIdx = 0; vc->notInBattle = 0; vc->removed = 0;
        for(int i = 0; i < COUNTER_SIZE; i++) { [vc->Counters[i] reset]; }
        for(int i = 0; i < PARTY_SIZE; i++) {
            [vc->Heros[i]->Box->Box setStringValue:@""];
            [vc->InBattle[i]->Button setState:NSControlStateValueOn];
        }
        [vc resetOrder];
    }];
        
    ActionButton *Map = [[ActionButton alloc] initWithAction:NSMakeRect(100, 810, 80, 24) name:@"Map" blk:^void(){
        NSLog(@"Map Button!");
    }];
        
    ActionButton *Roll = [[ActionButton alloc] initWithAction:NSMakeRect(420, 780, 80, 24) name:@"Roll" blk:^void(){
        NSInteger mobNum = [self->mainVC->MobSelector indexOfSelectedItem];
        NSInteger allyNum = [self->mainVC->AllySelector indexOfSelectedItem];
        int newRand;
        
        for(int i = 0; i < mobNum; i++)
        {
            newRand = arc4random_uniform(20) + 1;
            [self->mainVC->Mobs[i]->Init setIntValue:(newRand + [self->mainVC->Mobs[i]->Box->Box intValue])];
        }
        
        for(int i = 0; i < allyNum; i++)
        {
            newRand = arc4random_uniform(20) + 1;
            [self->mainVC->Allies[i]->Init setIntValue:(newRand + [self->mainVC->Allies[i]->Box->Box intValue])];
        }
    }];
    
    ActionButton *Set = [[ActionButton alloc] initWithAction:NSMakeRect(695, 780, 80, 24) name:@"Set" blk:^void(){
        ViewController *vc = self->mainVC;
        
        NSInteger mobNum  = [vc->MobSelector indexOfSelectedItem];
        NSInteger allyNum = [vc->AllySelector indexOfSelectedItem];
        NSInteger orderNum = PARTY_SIZE + mobNum + allyNum;
        
        vc->currentTurnIdx = 0;
        vc->turnsInRound = orderNum - vc->notInBattle;
        [vc->RoundCount setStringValue:@""];
       
        NSMutableArray *orderArr = [[NSMutableArray alloc] init];
        for(int i = 0; i < PARTY_SIZE; i++) {
            if([vc->InBattle[i]->Button state] == NSControlStateValueOn) {
                [orderArr addObject:vc->Heros[i]];
            }
        }
        for(int i = 0; i < mobNum; i++) { [orderArr addObject:vc->Mobs[i]]; }
        for(int i = 0; i < allyNum; i++) { [orderArr addObject:vc->Allies[i]]; }
        
        [orderArr sortUsingComparator:^(BattleEntity *a, BattleEntity *b) {
            if(a->isHero == true) {
                if(b->isHero == true) {
                    if([a->Box->Box intValue] > [b->Box->Box intValue])
                    { return (NSComparisonResult)NSOrderedAscending; }
                    if([a->Box->Box intValue] < [b->Box->Box intValue])
                    { return (NSComparisonResult)NSOrderedDescending; }
                    return (NSComparisonResult)NSOrderedSame;
                }
                if([a->Box->Box intValue] > [b->Init intValue])
                { return (NSComparisonResult)NSOrderedAscending; }
                if([a->Box->Box intValue] < [b->Init intValue])
                { return (NSComparisonResult)NSOrderedDescending; }
                return (NSComparisonResult)NSOrderedSame;
            }
            if(b->isHero == true) {
                if([b->Box->Box intValue] > [a->Init intValue])
                { return (NSComparisonResult)NSOrderedAscending; }
                if([b->Box->Box intValue] < [a->Init intValue])
                { return (NSComparisonResult)NSOrderedDescending; }
                return (NSComparisonResult)NSOrderedSame;
            }
            if([a->Init intValue] > [b->Init intValue])
            { return (NSComparisonResult)NSOrderedAscending; }
            if([a->Init intValue] < [b->Init intValue])
            { return (NSComparisonResult)NSOrderedDescending; }
            return (NSComparisonResult)NSOrderedSame;
        }];
        
        for(int i = 0; i < orderNum; i++) {
            BattleEntity *b = orderArr[i];
            [vc->Order[i]->Name setStringValue:[b->Box->Label stringValue]];
            [vc->Order[i]->Num setIntValue:(i+1)];
            
            if(i == 0) {
                [vc->CurrentInTurn
                 setStringValue:[b->Box->Label stringValue]];
            }
        }
    }];
    
    ActionButton *Next = [[ActionButton alloc] initWithAction:NSMakeRect(840, 780, 80, 24) name:@"Next" blk:^void(){
        ViewController *vc = self->mainVC;
        NSInteger mobNum = [vc->MobSelector indexOfSelectedItem];
        NSInteger allyNum = [vc->AllySelector indexOfSelectedItem];
        NSInteger num = mobNum + allyNum + PARTY_SIZE - vc->notInBattle;// - removeSize;
        
        if(mobNum == 0 && allyNum == 0) { return; }
        
        //TODO: Maybe bug when removing from order and currentTurnIdx gets >= than num?
        //      Probably not because currentTurnIdx gets managed when removing from order
        if(vc->currentTurnIdx == (num-1)) {
            vc->currentTurnIdx = 0;
            [vc->RoundCount setIntValue:([vc->RoundCount intValue]+1)];
        } else {
            vc->currentTurnIdx += 1;
        }

        //NOTE: We need numberOfTurnsI >= turnsInRound, rather then ==, because if
        //      turnsInRound was modified while the counter was on the boundary, it
        //      ends up in a wrong state!
        for(int i = 0; i < COUNTER_SIZE; i++) {
            Counter *curr = vc->Counters[i];
            if(curr->isCounting == true) {
                curr->elapsedTurns += 1;
                if(curr->elapsedTurns >= vc->turnsInRound) {
                    [curr tick];
                }
            }
        }
        
        [vc->CurrentInTurn
         setStringValue:[vc->Order[vc->currentTurnIdx]->Name stringValue]];
    }];
    
    [[item view] addSubview:Reset->Button]; [[item view] addSubview:Map->Button];
    [[item view] addSubview:Roll->Button]; [[item view] addSubview:Set->Button];
    [[item view] addSubview:Next->Button];
    mainVC->Reset = Reset; mainVC->Map = Map;
    mainVC->Roll = Roll; mainVC->Set = Set;
    mainVC->Next = Next;
    
    yPos = 760;
    for(int i = 0; i < COUNTER_SIZE; i++) {
        
        Counter *C = [[Counter alloc] initWithFrame:NSMakeRect(20, yPos, 80, 20) name:counterNames[i]];
        [[item view] addSubview:C->Field->Box];
        [[item view] addSubview:C->Field->Label];
        [[item view] addSubview:C->Count];
        [[item view] addSubview:C->SetButton->Button];
        
        mainVC->Counters[i] = C;
        
        yPos -= 40;
    }

    NSArray *MobSelValues = @[@"No Enemies", @"1 Enemy", @"2 Enemies", @"3 Enemies", @"4 Enemies", @"5 Enemies", @"6 Enemies", @"7 Enemies", @"8 Enemies", @"9 Enemies", @"10 Enemies", @"11 Enemies", @"12 Enemies", @"13 Enemies", @"14 Enemies", @"15 Enemies", @"16 Enemies"];
    NSComboBox *MobSel = [[NSComboBox alloc] initWithFrame:NSMakeRect(315, 780, 100, 25)];
    [MobSel addItemsWithObjectValues:MobSelValues];
    [MobSel selectItemAtIndex:0];
    MobSel.identifier = @"MobSel";
    [[item view] addSubview:MobSel];
    mainVC->MobSelector = MobSel;
    [mainVC->MobSelector setDelegate:self];
    
    NSArray *AllySelValues = @[@"No Allies", @"1 Ally", @"2 Allies", @"3 Allies", @"4 Allies"];
    NSComboBox *AllySel = [[NSComboBox alloc] initWithFrame:NSMakeRect(500, 780, 100, 25)];
    [AllySel addItemsWithObjectValues:AllySelValues];
    [AllySel selectItemAtIndex:0];
    AllySel.identifier = @"AllySel";
    [[item view] addSubview:AllySel];
    mainVC->AllySelector = AllySel;
    [mainVC->AllySelector setDelegate:self];
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    mainVC = (ViewController *) NSApplication.sharedApplication.orderedWindows.firstObject.contentViewController;
    
    mainVC->currentTurnIdx = 0;
    
    NSWindow *MainWindow = [NSApp windows][0];
    [MainWindow setFrame:NSMakeRect(300, 160, 1280, 960) display:true];
    
    NSTabView __strong *MainTabView = [[NSTabView alloc] initWithFrame:NSMakeRect(0, 0, 1280, 890)];
    NSTabViewItem *item0 = [[NSTabViewItem alloc] init];
    [item0 setLabel:@"PC"];
    NSTabViewItem *item1 = [[NSTabViewItem alloc] init];
    [item1 setLabel:@"Feats"];
    NSTabViewItem *item2 = [[NSTabViewItem alloc] init];
    [item2 setLabel:@"Init"];
    NSTabViewItem *item3 = [[NSTabViewItem alloc] init];
    [item3 setLabel:@"Party"];

    [self SetupInitTab:item2];
    [mainVC resetOrder];
    
    NSArray *tabViewItems = [[NSArray alloc] initWithObjects:item0, item1, item2, item3, nil];
    [MainTabView setTabViewItems:tabViewItems];
    [MainTabView selectTabViewItemAtIndex:2];
    [[MainWindow contentView] addSubview:MainTabView];
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


@end
