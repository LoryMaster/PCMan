//
//  ViewController.h
//  TheTruePCMan
//
//  Created by Lowy on 09/10/2019.
//  Copyright © 2019 Lowy. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ViewController : NSViewController {

    int currentTurnIdx;
    int turnsInRound;
    int removeSize;
    int notInBattle;
    
    bool isCounter1Counting;
    int numberOfTurns1;
    bool isCounter2Counting;
    int numberOfTurns2;
    bool isCounter3Counting;
    int numberOfTurns3;
    bool isCounter4Counting;
    int numberOfTurns4;
    
    @public int PARTY_SIZE;
    @public int MOB_SIZE;
    @public int ALLY_SIZE;
    @public int ORDER_SIZE;
    
    @public NSTextField * __strong MobLabelArr[16];
    @public NSTextField * __strong MobFieldArr[16];
    @public NSTextField * __strong MobBonusArr[16];
    @public NSButton * __strong SymbolCheckArr[1][16];
    
    @public NSTextField * __strong HeroLabelArr[8];
    @public NSTextField * __strong HeroFieldArr[8];
    @public NSButton * __strong HeroActiveArr[8];
    
    @public NSTextField * __strong AllyLabelArr[4];
    @public NSTextField * __strong AllyBonusArr[4];
    @public NSTextField * __strong AllyFieldArr[4];
    
    @public NSTextField * __strong OrderNumArr[28];
    @public NSTextField * __strong OrderFieldArr[28];
    @public NSButton * __strong OrderRemoveArr[28];
    
    @public NSWindow __strong *battleWindow;
    bool isBattleWindowOpen;
    
    @public NSImage __strong *Image;
    @public NSImageView __strong *ImageView;
}

- (void)showOrderFields:(NSInteger)num;
- (void)setCurrentTurnIdx:(int)v;
- (void)hideFields;
- (void)hideAllies;
- (void)hideMobs;
- (void)setMobLabels;
- (void)setAllyLabels;
- (void)changePos:(int)oldPos newPos:(int)newPos;

@property (strong) IBOutlet NSView *MainView;

// PC Tab //

@property (strong) NSArray *AbilityBonus;

@property (weak) IBOutlet NSTextField *NameLabel;
@property (weak) IBOutlet NSTextField *NameField;

@property (weak) IBOutlet NSTextField *PlayerLabel;
@property (weak) IBOutlet NSTextField *PlayerField;

@property (weak) IBOutlet NSTextField *RaceLabel;
@property (weak) IBOutlet NSComboBox *RaceSelector;
@property (weak) IBOutlet NSTextField *ClassLabel;
@property (weak) IBOutlet NSComboBox *ClassSelector;

@property (weak) IBOutlet NSTextField *GenMethodLabel;
@property (weak) IBOutlet NSComboBox *GenMethodSel;

@property (weak) IBOutlet NSTextField *STRLabel;
@property (weak) IBOutlet NSTextField *STRField;
@property (weak) IBOutlet NSTextField *STRBonus;

@property (weak) IBOutlet NSTextField *DEXLabel;
@property (weak) IBOutlet NSTextField *DEXField;
@property (weak) IBOutlet NSTextField *DEXBonus;

@property (weak) IBOutlet NSTextField *CONLabel;
@property (weak) IBOutlet NSTextField *CONField;
@property (weak) IBOutlet NSTextField *CONBonus;

@property (weak) IBOutlet NSTextField *INTLabel;
@property (weak) IBOutlet NSTextField *INTField;
@property (weak) IBOutlet NSTextField *INTBonus;

@property (weak) IBOutlet NSTextField *WISLabel;
@property (weak) IBOutlet NSTextField *WISField;
@property (weak) IBOutlet NSTextField *WISBonus;

@property (weak) IBOutlet NSTextField *CHALabel;
@property (weak) IBOutlet NSTextField *CHAField;
@property (weak) IBOutlet NSTextField *CHABonus;

@property (weak) IBOutlet NSTextField *LvlLabel;
@property (weak) IBOutlet NSTextField *LvlField;

@property (weak) IBOutlet NSTextField *ExpLabel;
@property (weak) IBOutlet NSTextField *ExpField;

@property (weak) IBOutlet NSTextField *NextXPLabel;
@property (weak) IBOutlet NSTextField *NextXPField;

@property (weak) IBOutlet NSTextField *XPCurveLabel;
@property (weak) IBOutlet NSComboBox *XPCurveSel;

@property (weak) IBOutlet NSTextField *BABLabel;
@property (weak) IBOutlet NSTextField *BABField;

@property (weak) IBOutlet NSTextField *FortLabel;
@property (weak) IBOutlet NSTextField *FortField;

@property (weak) IBOutlet NSTextField *RefLabel;
@property (weak) IBOutlet NSTextField *RefField;

@property (weak) IBOutlet NSTextField *WillLabel;
@property (weak) IBOutlet NSTextField *WillField;

@property (weak) IBOutlet NSTextField *RaceTraitsField;

@property (weak) IBOutlet NSTabView *TabController;

// Feats Tab //

@property (weak) IBOutlet NSTableView *FeatsTable;

// Initiative Tab //

@property (weak) IBOutlet NSTextField *MobNumberLabel;
@property (weak) IBOutlet NSComboBox *MobNumberSel;

@property (weak) IBOutlet NSTextField *AllyNumberLabel;
@property (weak) IBOutlet NSComboBox *AllyNumberSel;

@property (weak) IBOutlet NSButton *InitiativeRollButton;
@property (weak) IBOutlet NSButton *ResetButton;
@property (weak) IBOutlet NSButton *MapButton;

@property (weak) IBOutlet NSTextField *RoundCount;

@property (weak) IBOutlet NSTextField *Mob1Label;
@property (weak) IBOutlet NSTextField *Mob1Field;
@property (weak) IBOutlet NSTextField *Mob1Bonus;
@property (weak) IBOutlet NSButton *Star1Check;

@property (weak) IBOutlet NSTextField *Mob2Label;
@property (weak) IBOutlet NSTextField *Mob2Field;
@property (weak) IBOutlet NSTextField *Mob2Bonus;
@property (weak) IBOutlet NSButton *Star2Check;

@property (weak) IBOutlet NSTextField *Mob3Label;
@property (weak) IBOutlet NSTextField *Mob3Field;
@property (weak) IBOutlet NSTextField *Mob3Bonus;
@property (weak) IBOutlet NSButton *Star3Check;

@property (weak) IBOutlet NSTextField *Mob4Label;
@property (weak) IBOutlet NSTextField *Mob4Field;
@property (weak) IBOutlet NSTextField *Mob4Bonus;
@property (weak) IBOutlet NSButton *Star4Check;

@property (weak) IBOutlet NSTextField *Mob5Label;
@property (weak) IBOutlet NSTextField *Mob5Field;
@property (weak) IBOutlet NSTextField *Mob5Bonus;
@property (weak) IBOutlet NSButton *Star5Check;

@property (weak) IBOutlet NSTextField *Mob6Label;
@property (weak) IBOutlet NSTextField *Mob6Field;
@property (weak) IBOutlet NSTextField *Mob6Bonus;
@property (weak) IBOutlet NSButton *Star6Check;

@property (weak) IBOutlet NSTextField *Mob7Label;
@property (weak) IBOutlet NSTextField *Mob7Field;
@property (weak) IBOutlet NSTextField *Mob7Bonus;
@property (weak) IBOutlet NSButton *Star7Check;

@property (weak) IBOutlet NSTextField *Mob8Label;
@property (weak) IBOutlet NSTextField *Mob8Field;
@property (weak) IBOutlet NSTextField *Mob8Bonus;
@property (weak) IBOutlet NSButton *Star8Check;

@property (weak) IBOutlet NSTextField *Mob9Label;
@property (weak) IBOutlet NSTextField *Mob9Field;
@property (weak) IBOutlet NSTextField *Mob9Bonus;
@property (weak) IBOutlet NSButton *Star9Check;

@property (weak) IBOutlet NSTextField *Mob10Label;
@property (weak) IBOutlet NSTextField *Mob10Field;
@property (weak) IBOutlet NSTextField *Mob10Bonus;
@property (weak) IBOutlet NSButton *Star10Check;

@property (weak) IBOutlet NSTextField *Mob11Label;
@property (weak) IBOutlet NSTextField *Mob11Field;
@property (weak) IBOutlet NSTextField *Mob11Bonus;
@property (weak) IBOutlet NSButton *Star11Check;

@property (weak) IBOutlet NSTextField *Mob12Label;
@property (weak) IBOutlet NSTextField *Mob12Field;
@property (weak) IBOutlet NSTextField *Mob12Bonus;
@property (weak) IBOutlet NSButton *Star12Check;

@property (weak) IBOutlet NSTextField *Mob13Label;
@property (weak) IBOutlet NSTextField *Mob13Field;
@property (weak) IBOutlet NSTextField *Mob13Bonus;
@property (weak) IBOutlet NSButton *Star13Check;

@property (weak) IBOutlet NSTextField *Mob14Label;
@property (weak) IBOutlet NSTextField *Mob14Field;
@property (weak) IBOutlet NSTextField *Mob14Bonus;
@property (weak) IBOutlet NSButton *Star14Check;

@property (weak) IBOutlet NSTextField *Mob15Label;
@property (weak) IBOutlet NSTextField *Mob15Field;
@property (weak) IBOutlet NSTextField *Mob15Bonus;
@property (weak) IBOutlet NSButton *Star15Check;

@property (weak) IBOutlet NSTextField *Mob16Label;
@property (weak) IBOutlet NSTextField *Mob16Field;
@property (weak) IBOutlet NSTextField *Mob16Bonus;
@property (weak) IBOutlet NSButton *Star16Check;

@property (weak) IBOutlet NSTextField *Hero1Label;
@property (weak) IBOutlet NSTextField *Hero1Field;
@property (weak) IBOutlet NSButton *Hero1Active;

@property (weak) IBOutlet NSTextField *Hero2Label;
@property (weak) IBOutlet NSTextField *Hero2Field;
@property (weak) IBOutlet NSButton *Hero2Active;

@property (weak) IBOutlet NSTextField *Hero3Label;
@property (weak) IBOutlet NSTextField *Hero3Field;
@property (weak) IBOutlet NSButton *Hero3Active;

@property (weak) IBOutlet NSTextField *Hero4Label;
@property (weak) IBOutlet NSTextField *Hero4Field;
@property (weak) IBOutlet NSButton *Hero4Active;

@property (weak) IBOutlet NSTextField *Hero5Label;
@property (weak) IBOutlet NSTextField *Hero5Field;
@property (weak) IBOutlet NSButton *Hero5Active;

@property (weak) IBOutlet NSTextField *Hero6Label;
@property (weak) IBOutlet NSTextField *Hero6Field;
@property (weak) IBOutlet NSButton *Hero6Active;

@property (weak) IBOutlet NSTextField *Hero7Label;
@property (weak) IBOutlet NSTextField *Hero7Field;
@property (weak) IBOutlet NSButton *Hero7Active;

@property (weak) IBOutlet NSTextField *Hero8Label;
@property (weak) IBOutlet NSTextField *Hero8Field;
@property (weak) IBOutlet NSButton *Hero8Active;

@property (weak) IBOutlet NSTextField *Ally1Label;
@property (weak) IBOutlet NSTextField *Ally1Bonus;
@property (weak) IBOutlet NSTextField *Ally1Field;

@property (weak) IBOutlet NSTextField *Ally2Label;
@property (weak) IBOutlet NSTextField *Ally2Bonus;
@property (weak) IBOutlet NSTextField *Ally2Field;

@property (weak) IBOutlet NSTextField *Ally3Label;
@property (weak) IBOutlet NSTextField *Ally3Bonus;
@property (weak) IBOutlet NSTextField *Ally3Field;

@property (weak) IBOutlet NSTextField *Ally4Label;
@property (weak) IBOutlet NSTextField *Ally4Bonus;
@property (weak) IBOutlet NSTextField *Ally4Field;

@property (weak) IBOutlet NSTextField *Order1Num;
@property (weak) IBOutlet NSTextField *Order1Field;
@property (weak) IBOutlet NSButton *Order1Remove;

@property (weak) IBOutlet NSTextField *Order2Num;
@property (weak) IBOutlet NSTextField *Order2Field;
@property (weak) IBOutlet NSButton *Order2Remove;

@property (weak) IBOutlet NSTextField *Order3Num;
@property (weak) IBOutlet NSTextField *Order3Field;
@property (weak) IBOutlet NSButton *Order3Remove;

@property (weak) IBOutlet NSTextField *Order4Num;
@property (weak) IBOutlet NSTextField *Order4Field;
@property (weak) IBOutlet NSButton *Order4Remove;

@property (weak) IBOutlet NSTextField *Order5Num;
@property (weak) IBOutlet NSTextField *Order5Field;
@property (weak) IBOutlet NSButton *Order5Remove;

@property (weak) IBOutlet NSTextField *Order6Num;
@property (weak) IBOutlet NSTextField *Order6Field;
@property (weak) IBOutlet NSButton *Order6Remove;

@property (weak) IBOutlet NSTextField *Order7Num;
@property (weak) IBOutlet NSTextField *Order7Field;
@property (weak) IBOutlet NSButton *Order7Remove;

@property (weak) IBOutlet NSTextField *Order8Num;
@property (weak) IBOutlet NSTextField *Order8Field;
@property (weak) IBOutlet NSButton *Order8Remove;

@property (weak) IBOutlet NSTextField *Order9Num;
@property (weak) IBOutlet NSTextField *Order9Field;
@property (weak) IBOutlet NSButton *Order9Remove;

@property (weak) IBOutlet NSTextField *Order10Num;
@property (weak) IBOutlet NSTextField *Order10Field;
@property (weak) IBOutlet NSButton *Order10Remove;

@property (weak) IBOutlet NSTextField *Order11Num;
@property (weak) IBOutlet NSTextField *Order11Field;
@property (weak) IBOutlet NSButton *Order11Remove;

@property (weak) IBOutlet NSTextField *Order12Num;
@property (weak) IBOutlet NSTextField *Order12Field;
@property (weak) IBOutlet NSButton *Order12Remove;

@property (weak) IBOutlet NSTextField *Order13Num;
@property (weak) IBOutlet NSTextField *Order13Field;
@property (weak) IBOutlet NSButton *Order13Remove;

@property (weak) IBOutlet NSTextField *Order14Num;
@property (weak) IBOutlet NSTextField *Order14Field;
@property (weak) IBOutlet NSButton *Order14Remove;

@property (weak) IBOutlet NSTextField *Order15Num;
@property (weak) IBOutlet NSTextField *Order15Field;
@property (weak) IBOutlet NSButton *Order15Remove;

@property (weak) IBOutlet NSTextField *Order16Num;
@property (weak) IBOutlet NSTextField *Order16Field;
@property (weak) IBOutlet NSButton *Order16Remove;

@property (weak) IBOutlet NSTextField *Order17Num;
@property (weak) IBOutlet NSTextField *Order17Field;
@property (weak) IBOutlet NSButton *Order17Remove;

@property (weak) IBOutlet NSTextField *Order18Num;
@property (weak) IBOutlet NSTextField *Order18Field;
@property (weak) IBOutlet NSButton *Order18Remove;

@property (weak) IBOutlet NSTextField *Order19Num;
@property (weak) IBOutlet NSTextField *Order19Field;
@property (weak) IBOutlet NSButton *Order19Remove;

@property (weak) IBOutlet NSTextField *Order20Num;
@property (weak) IBOutlet NSTextField *Order20Field;
@property (weak) IBOutlet NSButton *Order20Remove;

@property (weak) IBOutlet NSTextField *Order21Num;
@property (weak) IBOutlet NSTextField *Order21Field;
@property (weak) IBOutlet NSButton *Order21Remove;

@property (weak) IBOutlet NSTextField *Order22Num;
@property (weak) IBOutlet NSTextField *Order22Field;
@property (weak) IBOutlet NSButton *Order22Remove;

@property (weak) IBOutlet NSTextField *Order23Num;
@property (weak) IBOutlet NSTextField *Order23Field;
@property (weak) IBOutlet NSButton *Order23Remove;

@property (weak) IBOutlet NSTextField *Order24Num;
@property (weak) IBOutlet NSTextField *Order24Field;
@property (weak) IBOutlet NSButton *Order24Remove;

@property (weak) IBOutlet NSTextField *Order25Num;
@property (weak) IBOutlet NSTextField *Order25Field;
@property (weak) IBOutlet NSButton *Order25Remove;

@property (weak) IBOutlet NSTextField *Order26Num;
@property (weak) IBOutlet NSTextField *Order26Field;
@property (weak) IBOutlet NSButton *Order26Remove;

@property (weak) IBOutlet NSTextField *Order27Num;
@property (weak) IBOutlet NSTextField *Order27Field;
@property (weak) IBOutlet NSButton *Order27Remove;

@property (weak) IBOutlet NSTextField *Order28Num;
@property (weak) IBOutlet NSTextField *Order28Field;
@property (weak) IBOutlet NSButton *Order28Remove;

@property (weak) IBOutlet NSButton *SetOrderButton;

@property (weak) IBOutlet NSButton *AdvanceTurnButton;
@property (weak) IBOutlet NSTextField *CurrentTurnField;

@property (weak) IBOutlet NSTextField *Counter1Label;
@property (weak) IBOutlet NSTextField *Counter1Name;
@property (weak) IBOutlet NSTextField *Counter1Value;
@property (weak) IBOutlet NSButton *Counter1Button;

@property (weak) IBOutlet NSTextField *Counter2Label;
@property (weak) IBOutlet NSTextField *Counter2Name;
@property (weak) IBOutlet NSTextField *Counter2Value;
@property (weak) IBOutlet NSButton *Counter2Button;

@property (weak) IBOutlet NSTextField *Counter3Label;
@property (weak) IBOutlet NSTextField *Counter3Name;
@property (weak) IBOutlet NSTextField *Counter3Value;
@property (weak) IBOutlet NSButton *Counter3Button;

@property (weak) IBOutlet NSTextField *Counter4Label;
@property (weak) IBOutlet NSTextField *Counter4Name;
@property (weak) IBOutlet NSTextField *Counter4Value;
@property (weak) IBOutlet NSButton *Counter4Button;

//
// Party Tab
//

@property (weak) IBOutlet NSComboBox *HeroPicker;

@property (weak) IBOutlet NSTextField *HeroNameLabel;
@property (weak) IBOutlet NSTextField *HeroNameField;

@property (weak) IBOutlet NSTextField *HeroPlayerLabel;
@property (weak) IBOutlet NSTextField *HeroPlayerField;

@property (weak) IBOutlet NSTextField *HeroRaceLabel;
@property (weak) IBOutlet NSTextField *HeroRaceField;

@property (weak) IBOutlet NSTextField *HeroClassLabel;
@property (weak) IBOutlet NSTextField *HeroClassField;

@property (weak) IBOutlet NSTextField *HeroSTRLabel;
@property (weak) IBOutlet NSTextField *HeroSTRField;
@property (weak) IBOutlet NSTextField *HeroSTRBonus;

@property (weak) IBOutlet NSTextField *HeroDEXLabel;
@property (weak) IBOutlet NSTextField *HeroDEXField;
@property (weak) IBOutlet NSTextField *HeroDEXBonus;

@property (weak) IBOutlet NSTextField *HeroCONLabel;
@property (weak) IBOutlet NSTextField *HeroCONField;
@property (weak) IBOutlet NSTextField *HeroCONBonus;

@property (weak) IBOutlet NSTextField *HeroINTLabel;
@property (weak) IBOutlet NSTextField *HeroINTField;
@property (weak) IBOutlet NSTextField *HeroINTBonus;

@property (weak) IBOutlet NSTextField *HeroWISLabel;
@property (weak) IBOutlet NSTextField *HeroWISField;
@property (weak) IBOutlet NSTextField *HeroWISBonus;

@property (weak) IBOutlet NSTextField *HeroCHALabel;
@property (weak) IBOutlet NSTextField *HeroCHAField;
@property (weak) IBOutlet NSTextField *HeroCHABonus;

@property (weak) IBOutlet NSTextField *HeroBABLabel;
@property (weak) IBOutlet NSTextField *HeroBABField;

@property (weak) IBOutlet NSTextField *HeroFortLabel;
@property (weak) IBOutlet NSTextField *HeroFortField;

@property (weak) IBOutlet NSTextField *HeroReflLabel;
@property (weak) IBOutlet NSTextField *HeroReflField;

@property (weak) IBOutlet NSTextField *HeroWillLabel;
@property (weak) IBOutlet NSTextField *HeroWillField;

@end

