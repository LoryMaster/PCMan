//
//  Entity.h
//  HyperPCMan
//
//  Created by Lowy on 27/11/2019.
//  Copyright © 2019 Lowy. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "StatField.h"

NS_ASSUME_NONNULL_BEGIN

#define ST_NUM 3

typedef struct {
    int Bonus[4];
    int num;
} BAB;

typedef struct {
    int Value;
    int AS;
    int Extra;
} Skill;

typedef enum {
    ACROBATICS = 0,
    APPRAISE,
    BLUFF,
    CLIMB,
    CRAFT,
    DIPLOMACY,
    DISABLE_DEVICE,
    DISGUISE,
    ESCAPE_ARTIST,
    FLY,
    HANDLE_ANIMAL,
    HEAL,
    INTIMIDATE,
    KNOWLEDGE_ARCANA,
    KNOWLEDGE_DUNGEONEERING,
    KNOWLEDGE_ENGINEERING,
    KNOWLEDGE_GEOGRAPHY,
    KNOWLEDGE_HISTORY,
    KNOWLEDGE_LOCAL,
    KNOWLEDGE_NATURE,
    KNOWLEDGE_NOBILITY,
    KNOWLEDGE_PLANES,
    KNOWLEDGE_RELIGION,
    LINGUISTICS,
    PERCEPTION,
    PERFORM,
    PROFESSION,
    RIDE,
    INTUITION,
    SLEIGHT_OF_HAND,
    SPELLCRAFT,
    STEALTH,
    SURVIVAL,
    SWIM,
    USE_MAGIC_DEVICE,
    SKILL_NUM
} SkillEnums;

static NSString  * _Nonnull   __strong SkillNames[SKILL_NUM] = {
          @"ACROBATICS", @"APPRAISE", @"BLUFF", @"CLIMB", @"CRAFT",
          @"DIPLOMACY", @"DISABLE_DEVICE", @"DISGUISE", @"ESCAPE_ARTIST", @"FLY", @"HANDLE_ANIMAL",
          @"HEAL", @"INTIMIDATE", @"KNOWLEDGE_ARCANA", @"KNOWLEDGE_DUNGEONEERING", @"KNOWLEDGE_ENGINEERING",
          @"KNOWLEDGE_GEOGRAPHY", @"KNOWLEDGE_HISTORY", @"KNOWLEDGE_LOCAL", @"KNOWLEDGE_NATURE",
          @"KNOWLEDGE_NOBILITY", @"KNOWLEDGE_PLANES", @"KNOWLEDGE_RELIGION", @"LINGUISTICS",
          @"PERCEPTION", @"PERFORM", @"PROFESSION", @"RIDE", @"INTUITION", @"SLEIGHT_OF_HAND",
          @"SPELLCRAFT", @"STEALTH", @"SURVIVAL", @"SWIM", @"USE_MAGIC_DEVICE" };

static NSInteger ASBonus[] = {
    -5, -5, -4, -4, -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2,
    3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11,
    12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17
};

static NSString * _Nonnull __strong STNames[ST_NUM] = {@"Fortitude", @"Reflexes", @"Will"};

@interface Entity : NSObject {
    @public NSString *name;
    @public int      Stats[STATS_NUM];
    @public int      SavingThrows[ST_NUM];
    @public BAB      AttackBonus;
    @public int      CMB;
    @public int      CMD;
    @public Skill    Skills[SKILL_NUM];
};

@end

NS_ASSUME_NONNULL_END
