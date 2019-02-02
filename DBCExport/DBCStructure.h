#ifndef MANGOS_DBCSTRUCTURE_H
#define MANGOS_DBCSTRUCTURE_H

#include "SharedDefines.h"

#if defined( __GNUC__ )
#pragma pack(1)
#else
#pragma pack(push,1)
#endif

struct AreaTriggerEntry5875
{
    uint32    id;                                           // 0
    uint32    mapid;                                        // 1
    float     x;                                            // 2
    float     y;                                            // 3
    float     z;                                            // 4
    float     radius;                                       // 5
    float     box_x;                                        // 6 extent x edge
    float     box_y;                                        // 7 extent y edge
    float     box_z;                                        // 8 extent z edge
    float     box_orientation;                              // 9 extent rotation by about z axis
};

struct ClassFamilyMask
{
    uint64 Flags;

    ClassFamilyMask() : Flags(0) {}
    explicit ClassFamilyMask(uint64 familyFlags) : Flags(familyFlags) {}

    bool Empty() const { return Flags == 0; }
    bool operator!() const { return Empty(); }
    operator void const* () const { return Empty() ? nullptr : this; } // for allow normal use in if(mask)

    bool IsFitToFamilyMask(uint64 familyFlags) const
    {
        return (Flags & familyFlags) != 0;
    }

    bool IsFitToFamilyMask(ClassFamilyMask const& mask) const
    {
        return (Flags & mask.Flags) != 0;
    }

    uint64 operator& (uint64 mask) const                    // possible will removed at finish convertion code use IsFitToFamilyMask
    {
        return Flags & mask;
    }

    ClassFamilyMask& operator|= (ClassFamilyMask const& mask)
    {
        Flags |= mask.Flags;
        return *this;
    }
};

struct SpellEntry5875
{
    uint32    Id;                                           // 0
    uint32    School;                                       // 1
    uint32    Category;                                     // 2
    uint32    castUI;                                       // 3
    uint32    Dispel;                                       // 4
    uint32    Mechanic;                                     // 5
    uint32    Attributes;                                   // 6
    uint32    AttributesEx;                                 // 7
    uint32    AttributesEx2;                                // 8
    uint32    AttributesEx3;                                // 9
    uint32    AttributesEx4;                                // 10
    uint32    Stances;                                      // 11
    uint32    StancesNot;                                   // 12
    uint32    Targets;                                      // 13
    uint32    TargetCreatureType;                           // 14
    uint32    RequiresSpellFocus;                           // 15
    uint32    CasterAuraState;                              // 16
    uint32    TargetAuraState;                              // 17
    uint32    CastingTimeIndex;                             // 18
    uint32    RecoveryTime;                                 // 19
    uint32    CategoryRecoveryTime;                         // 20
    uint32    InterruptFlags;                               // 21
    uint32    AuraInterruptFlags;                           // 22
    uint32    ChannelInterruptFlags;                        // 23
    uint32    procFlags;                                    // 24
    uint32    procChance;                                   // 25
    uint32    procCharges;                                  // 26
    uint32    maxLevel;                                     // 27
    uint32    baseLevel;                                    // 28
    uint32    spellLevel;                                   // 29
    uint32    DurationIndex;                                // 30
    uint32    powerType;                                    // 31
    uint32    manaCost;                                     // 32
    uint32    manaCostPerlevel;                             // 33
    uint32    manaPerSecond;                                // 34
    uint32    manaPerSecondPerLevel;                        // 35
    uint32    rangeIndex;                                   // 36
    float     speed;                                        // 37
    uint32    modalNextSpell;                               // 38
    uint32    StackAmount;                                  // 39
    uint32    Totem[MAX_SPELL_TOTEMS];                      // 40-41
    int32     Reagent[MAX_SPELL_REAGENTS];                  // 42-49
    uint32    ReagentCount[MAX_SPELL_REAGENTS];             // 50-57
    int32     EquippedItemClass;                            // 58
    int32     EquippedItemSubClassMask;                     // 59
    int32     EquippedItemInventoryTypeMask;                // 60
    uint32    Effect[MAX_EFFECT_INDEX];                     // 61-63
    int32     EffectDieSides[MAX_EFFECT_INDEX];             // 64-66
    uint32    EffectBaseDice[MAX_EFFECT_INDEX];             // 67-69
    float     EffectDicePerLevel[MAX_EFFECT_INDEX];         // 70-72
    float     EffectRealPointsPerLevel[MAX_EFFECT_INDEX];   // 73-75
    int32     EffectBasePoints[MAX_EFFECT_INDEX];           // 76-78
    uint32    EffectMechanic[MAX_EFFECT_INDEX];             // 79-81
    uint32    EffectImplicitTargetA[MAX_EFFECT_INDEX];      // 82-84
    uint32    EffectImplicitTargetB[MAX_EFFECT_INDEX];      // 85-87
    uint32    EffectRadiusIndex[MAX_EFFECT_INDEX];          // 88-90
    uint32    EffectApplyAuraName[MAX_EFFECT_INDEX];        // 91-93
    uint32    EffectAmplitude[MAX_EFFECT_INDEX];            // 94-96
    float     EffectMultipleValue[MAX_EFFECT_INDEX];        // 97-99
    uint32    EffectChainTarget[MAX_EFFECT_INDEX];          // 100-102
    uint32    EffectItemType[MAX_EFFECT_INDEX];             // 103-105
    int32     EffectMiscValue[MAX_EFFECT_INDEX];            // 106-108
    uint32    EffectTriggerSpell[MAX_EFFECT_INDEX];         // 109-111
    float     EffectPointsPerComboPoint[MAX_EFFECT_INDEX];  // 112-114
    uint32    SpellVisual;                                  // 115
    uint32    SpellVisual2;                                 // 116
    uint32    SpellIconID;                                  // 117
    uint32    activeIconID;                                 // 118
    uint32    spellPriority;                                // 119
    char*     SpellName[8];                                 // 120-127
    uint32    SpellNameFlag;                                // 128
    char*     Rank[8];                                      // 129-136
    uint32    RankFlags;                                    // 137
    char*     Description[8];                               // 138-145
    uint32    DescriptionFlags;                             // 146
    char*     ToolTip[8];                                   // 147-154
    uint32    ToolTipFlags;                                 // 155
    uint32    ManaCostPercentage;                           // 156
    uint32    StartRecoveryCategory;                        // 157
    uint32    StartRecoveryTime;                            // 158
    uint32    MaxTargetLevel;                               // 159
    uint32    SpellFamilyName;                              // 160
    ClassFamilyMask SpellFamilyFlags;                       // 161+162
    uint32    MaxAffectedTargets;                           // 163
    uint32    DmgClass;                                     // 164
    uint32    PreventionType;                               // 165
    int32     StanceBarOrder;                               // 166
    float     DmgMultiplier[MAX_EFFECT_INDEX];              // 167-169
    uint32    MinFactionId;                                 // 170
    uint32    MinReputation;                                // 171
    uint32    RequiredAuraVision;                           // 172
};

struct SpellEntry5464
{
    uint32    Id;                                           // 0
    uint32    School;                                       // 1
    uint32    Category;                                     // 2
    uint32    castUI;                                       // 3
    uint32    Dispel;                                       // 4
    uint32    Mechanic;                                     // 5
    uint32    Attributes;                                   // 6
    uint32    AttributesEx;                                 // 7
    uint32    AttributesEx2;                                // 8
    uint32    Stances;                                      // 9
    uint32    StancesNot;                                   // 10
    uint32    Targets;                                      // 11
    uint32    TargetCreatureType;                           // 12
    uint32    RequiresSpellFocus;                           // 13
    uint32    CasterAuraState;                              // 14
    uint32    TargetAuraState;                              // 15
    uint32    CastingTimeIndex;                             // 16
    uint32    RecoveryTime;                                 // 17
    uint32    CategoryRecoveryTime;                         // 18
    uint32    InterruptFlags;                               // 19
    uint32    AuraInterruptFlags;                           // 20
    uint32    ChannelInterruptFlags;                        // 21
    uint32    procFlags;                                    // 22
    uint32    procChance;                                   // 23
    uint32    procCharges;                                  // 24
    uint32    maxLevel;                                     // 25
    uint32    baseLevel;                                    // 26
    uint32    spellLevel;                                   // 27
    uint32    DurationIndex;                                // 28
    uint32    powerType;                                    // 29
    uint32    manaCost;                                     // 30
    uint32    manaCostPerlevel;                             // 31
    uint32    manaPerSecond;                                // 32
    uint32    manaPerSecondPerLevel;                        // 33
    uint32    rangeIndex;                                   // 34
    float     speed;                                        // 35
    uint32    modalNextSpell;                               // 36
    uint32    StackAmount;                                  // 37
    uint32    Totem[MAX_SPELL_TOTEMS];                      // 38-39
    int32     Reagent[MAX_SPELL_REAGENTS];                  // 40-47
    uint32    ReagentCount[MAX_SPELL_REAGENTS];             // 48-55
    int32     EquippedItemClass;                            // 56
    int32     EquippedItemSubClassMask;                     // 57
    uint32    Effect[MAX_EFFECT_INDEX];                     // 58-60
    int32     EffectDieSides[MAX_EFFECT_INDEX];             // 61-63
    uint32    EffectBaseDice[MAX_EFFECT_INDEX];             // 64-66
    float     EffectDicePerLevel[MAX_EFFECT_INDEX];         // 67-69
    float     EffectRealPointsPerLevel[MAX_EFFECT_INDEX];   // 70-72
    int32     EffectBasePoints[MAX_EFFECT_INDEX];           // 73-75
    uint32    EffectMechanic[MAX_EFFECT_INDEX];             // 76-78
    uint32    EffectImplicitTargetA[MAX_EFFECT_INDEX];      // 79-81
    uint32    EffectImplicitTargetB[MAX_EFFECT_INDEX];      // 82-84
    uint32    EffectRadiusIndex[MAX_EFFECT_INDEX];          // 85-87
    uint32    EffectApplyAuraName[MAX_EFFECT_INDEX];        // 88-90
    uint32    EffectAmplitude[MAX_EFFECT_INDEX];            // 91-93
    float     EffectMultipleValue[MAX_EFFECT_INDEX];        // 94-96
    uint32    EffectChainTarget[MAX_EFFECT_INDEX];          // 97-99
    uint32    EffectItemType[MAX_EFFECT_INDEX];             // 100-102
    int32     EffectMiscValue[MAX_EFFECT_INDEX];            // 103-105
    uint32    EffectTriggerSpell[MAX_EFFECT_INDEX];         // 106-108
    float     EffectPointsPerComboPoint[MAX_EFFECT_INDEX];  // 109-111
    uint32    SpellVisual;                                  // 112
    uint32    SpellVisual2;                                 // 113
    uint32    SpellIconID;                                  // 114
    uint32    activeIconID;                                 // 115
    uint32    spellPriority;                                // 116
    char*     SpellName[8];                                 // 117-124
    uint32    SpellNameFlag;                                // 125
    char*     Rank[8];                                      // 126-133
    uint32    RankFlags;                                    // 134
    char*     Description[8];                               // 135-142
    uint32    DescriptionFlags;                             // 143
    char*     ToolTip[8];                                   // 144-151
    uint32    ToolTipFlags;                                 // 152
    uint32    ManaCostPercentage;                           // 153
    uint32    StartRecoveryCategory;                        // 154
    uint32    StartRecoveryTime;                            // 155
    uint32    MaxTargetLevel;                               // 156
    uint32    SpellFamilyName;                              // 157
    ClassFamilyMask SpellFamilyFlags;                       // 158+159
    uint32    MaxAffectedTargets;                           // 160
    uint32    DmgClass;                                     // 161
    uint32    PreventionType;                               // 162
    int32     StanceBarOrder;                               // 163
    float     DmgMultiplier[MAX_EFFECT_INDEX];              // 164-166
    uint32    AttributesEx3;                                // 167
    uint32    MinFactionId;                                 // 168
    uint32    MinReputation;                                // 169
    uint32    RequiredAuraVision;                           // 170
};

struct SpellEntry5302
{
    uint32    Id;                                           // 0
    uint32    School;                                       // 1
    uint32    Category;                                     // 2
    uint32    castUI;                                       // 3
    uint32    Dispel;                                       // 4
    uint32    Mechanic;                                     // 5
    uint32    Attributes;                                   // 6
    uint32    AttributesEx;                                 // 7
    uint32    AttributesEx2;                                // 8
    uint32    Stances;                                      // 9
    uint32    StancesNot;                                   // 10
    uint32    Targets;                                      // 11
    uint32    TargetCreatureType;                           // 12
    uint32    RequiresSpellFocus;                           // 13
    uint32    CasterAuraState;                              // 14
    uint32    TargetAuraState;                              // 15
    uint32    CastingTimeIndex;                             // 16
    uint32    RecoveryTime;                                 // 17
    uint32    CategoryRecoveryTime;                         // 18
    uint32    InterruptFlags;                               // 19
    uint32    AuraInterruptFlags;                           // 20
    uint32    ChannelInterruptFlags;                        // 21
    uint32    procFlags;                                    // 22
    uint32    procChance;                                   // 23
    uint32    procCharges;                                  // 24
    uint32    maxLevel;                                     // 25
    uint32    baseLevel;                                    // 26
    uint32    spellLevel;                                   // 27
    uint32    DurationIndex;                                // 28
    uint32    powerType;                                    // 29
    uint32    manaCost;                                     // 30
    uint32    manaCostPerlevel;                             // 31
    uint32    manaPerSecond;                                // 32
    uint32    manaPerSecondPerLevel;                        // 33
    uint32    rangeIndex;                                   // 34
    float     speed;                                        // 35
    uint32    modalNextSpell;                               // 36
    uint32    StackAmount;                                  // 37
    uint32    Totem[MAX_SPELL_TOTEMS];                      // 38-39
    int32     Reagent[MAX_SPELL_REAGENTS];                  // 40-47
    uint32    ReagentCount[MAX_SPELL_REAGENTS];             // 48-55
    int32     EquippedItemClass;                            // 56
    int32     EquippedItemSubClassMask;                     // 57
    uint32    Effect[MAX_EFFECT_INDEX];                     // 58-60
    int32     EffectDieSides[MAX_EFFECT_INDEX];             // 61-63
    uint32    EffectBaseDice[MAX_EFFECT_INDEX];             // 64-66
    float     EffectDicePerLevel[MAX_EFFECT_INDEX];         // 67-69
    float     EffectRealPointsPerLevel[MAX_EFFECT_INDEX];   // 70-72
    int32     EffectBasePoints[MAX_EFFECT_INDEX];           // 73-75
    uint32    EffectMechanic[MAX_EFFECT_INDEX];             // 76-78
    uint32    EffectImplicitTargetA[MAX_EFFECT_INDEX];      // 79-81
    uint32    EffectImplicitTargetB[MAX_EFFECT_INDEX];      // 82-84
    uint32    EffectRadiusIndex[MAX_EFFECT_INDEX];          // 85-87
    uint32    EffectApplyAuraName[MAX_EFFECT_INDEX];        // 88-90
    uint32    EffectAmplitude[MAX_EFFECT_INDEX];            // 91-93
    float     EffectMultipleValue[MAX_EFFECT_INDEX];        // 94-96
    uint32    EffectChainTarget[MAX_EFFECT_INDEX];          // 97-99
    uint32    EffectItemType[MAX_EFFECT_INDEX];             // 100-102
    int32     EffectMiscValue[MAX_EFFECT_INDEX];            // 103-105
    uint32    EffectTriggerSpell[MAX_EFFECT_INDEX];         // 106-108
    float     EffectPointsPerComboPoint[MAX_EFFECT_INDEX];  // 109-111
    uint32    SpellVisual;                                  // 112
    uint32    SpellVisual2;                                 // 113
    uint32    SpellIconID;                                  // 114
    uint32    activeIconID;                                 // 115
    uint32    spellPriority;                                // 116
    char*     SpellName[8];                                 // 117-124
    uint32    SpellNameFlag;                                // 125
    char*     Rank[8];                                      // 126-133
    uint32    RankFlags;                                    // 134
    char*     Description[8];                               // 135-142
    uint32    DescriptionFlags;                             // 143
    char*     ToolTip[8];                                   // 144-151
    uint32    ToolTipFlags;                                 // 152
    uint32    ManaCostPercentage;                           // 153
    uint32    StartRecoveryCategory;                        // 154
    uint32    StartRecoveryTime;                            // 155
    uint32    MaxTargetLevel;                               // 156
    uint32    SpellFamilyName;                              // 157
    uint32    SpellFamilyFlags;                             // 158
    uint32    MaxAffectedTargets;                           // 159
    uint32    DmgClass;                                     // 160
    uint32    PreventionType;                               // 161
    int32     StanceBarOrder;                               // 162
    float     DmgMultiplier[MAX_EFFECT_INDEX];              // 163-165
    uint32    AttributesEx3;                                // 166
    uint32    MinFactionId;                                 // 167
    uint32    MinReputation;                                // 168
    uint32    RequiredAuraVision;                           // 169
};

struct SpellEntry4878
{
    uint32    Id;                                           // 0
    uint32    School;                                       // 1
    uint32    Category;                                     // 2
    uint32    castUI;                                       // 3
    uint32    Dispel;                                       // 4
    uint32    Mechanic;                                     // 5
    uint32    Attributes;                                   // 6
    uint32    AttributesEx;                                 // 7
    uint32    AttributesEx2;                                // 8
    uint32    Stances;                                      // 9
    uint32    StancesNot;                                   // 10
    uint32    Targets;                                      // 11
    uint32    TargetCreatureType;                           // 12
    uint32    RequiresSpellFocus;                           // 13
    uint32    CasterAuraState;                              // 14
    uint32    TargetAuraState;                              // 15
    uint32    CastingTimeIndex;                             // 16
    uint32    RecoveryTime;                                 // 17
    uint32    CategoryRecoveryTime;                         // 18
    uint32    InterruptFlags;                               // 19
    uint32    AuraInterruptFlags;                           // 20
    uint32    ChannelInterruptFlags;                        // 21
    uint32    procFlags;                                    // 22
    uint32    procChance;                                   // 23
    uint32    procCharges;                                  // 24
    uint32    maxLevel;                                     // 25
    uint32    baseLevel;                                    // 26
    uint32    spellLevel;                                   // 27
    uint32    DurationIndex;                                // 28
    uint32    powerType;                                    // 29
    uint32    manaCost;                                     // 30
    uint32    manaCostPerlevel;                             // 31
    uint32    manaPerSecond;                                // 32
    uint32    manaPerSecondPerLevel;                        // 33
    uint32    rangeIndex;                                   // 34
    float     speed;                                        // 35
    uint32    modalNextSpell;                               // 36
    uint32    StackAmount;                                  // 37
    uint32    Totem[MAX_SPELL_TOTEMS];                      // 38-39
    int32     Reagent[MAX_SPELL_REAGENTS];                  // 40-47
    uint32    ReagentCount[MAX_SPELL_REAGENTS];             // 48-55
    int32     EquippedItemClass;                            // 56
    int32     EquippedItemSubClassMask;                     // 57
    uint32    Effect[MAX_EFFECT_INDEX];                     // 58-60
    int32     EffectDieSides[MAX_EFFECT_INDEX];             // 61-63
    uint32    EffectBaseDice[MAX_EFFECT_INDEX];             // 64-66
    float     EffectDicePerLevel[MAX_EFFECT_INDEX];         // 67-69
    float     EffectRealPointsPerLevel[MAX_EFFECT_INDEX];   // 70-72
    int32     EffectBasePoints[MAX_EFFECT_INDEX];           // 73-75
    uint32    EffectMechanic[MAX_EFFECT_INDEX];             // 76-78
    uint32    EffectImplicitTargetA[MAX_EFFECT_INDEX];      // 79-81
    uint32    EffectImplicitTargetB[MAX_EFFECT_INDEX];      // 82-84
    uint32    EffectRadiusIndex[MAX_EFFECT_INDEX];          // 85-87
    uint32    EffectApplyAuraName[MAX_EFFECT_INDEX];        // 88-90
    uint32    EffectAmplitude[MAX_EFFECT_INDEX];            // 91-93
    float     EffectMultipleValue[MAX_EFFECT_INDEX];        // 94-96
    uint32    EffectChainTarget[MAX_EFFECT_INDEX];          // 97-99
    uint32    EffectItemType[MAX_EFFECT_INDEX];             // 100-102
    int32     EffectMiscValue[MAX_EFFECT_INDEX];            // 103-105
    uint32    EffectTriggerSpell[MAX_EFFECT_INDEX];         // 106-108
    float     EffectPointsPerComboPoint[MAX_EFFECT_INDEX];  // 109-111
    uint32    SpellVisual;                                  // 112
    uint32    SpellVisual2;                                 // 113
    uint32    SpellIconID;                                  // 114
    uint32    activeIconID;                                 // 115
    uint32    spellPriority;                                // 116
    char*     SpellName[8];                                 // 117-124
    uint32    SpellNameFlag;                                // 125
    char*     Rank[8];                                      // 126-133
    uint32    RankFlags;                                    // 134
    char*     Description[8];                               // 135-142
    uint32    DescriptionFlags;                             // 143
    char*     ToolTip[8];                                   // 144-151
    uint32    ToolTipFlags;                                 // 152
    uint32    ManaCostPercentage;                           // 153
    uint32    StartRecoveryCategory;                        // 154
    uint32    StartRecoveryTime;                            // 155
    uint32    MaxTargetLevel;                               // 156
    uint32    SpellFamilyName;                              // 157
    uint32    SpellFamilyFlags;                             // 158
    uint32    MaxAffectedTargets;                           // 159
    uint32    DmgClass;                                     // 160
    uint32    PreventionType;                               // 161
    int32     StanceBarOrder;                               // 162
    float     DmgMultiplier[MAX_EFFECT_INDEX];              // 163-165
    uint32    AttributesEx3;                                // 166
};

struct SpellEntry4695
{
    uint32    Id;                                           // 0
    uint32    School;                                       // 1
    uint32    Category;                                     // 2
    uint32    castUI;                                       // 3
    uint32    Dispel;                                       // 4
    uint32    Mechanic;                                     // 5
    uint32    Attributes;                                   // 6
    uint32    AttributesEx;                                 // 7
    uint32    AttributesEx2;                                // 8
    uint32    Stances;                                      // 9
    uint32    StancesNot;                                   // 10
    uint32    Targets;                                      // 11
    uint32    TargetCreatureType;                           // 12
    uint32    RequiresSpellFocus;                           // 13
    uint32    CasterAuraState;                              // 14
    uint32    TargetAuraState;                              // 15
    uint32    CastingTimeIndex;                             // 16
    uint32    RecoveryTime;                                 // 17
    uint32    CategoryRecoveryTime;                         // 18
    uint32    InterruptFlags;                               // 19
    uint32    AuraInterruptFlags;                           // 20
    uint32    ChannelInterruptFlags;                        // 21
    uint32    procFlags;                                    // 22
    uint32    procChance;                                   // 23
    uint32    procCharges;                                  // 24
    uint32    maxLevel;                                     // 25
    uint32    baseLevel;                                    // 26
    uint32    spellLevel;                                   // 27
    uint32    DurationIndex;                                // 28
    uint32    powerType;                                    // 29
    uint32    manaCost;                                     // 30
    uint32    manaCostPerlevel;                             // 31
    uint32    manaPerSecond;                                // 32
    uint32    manaPerSecondPerLevel;                        // 33
    uint32    rangeIndex;                                   // 34
    float     speed;                                        // 35
    uint32    modalNextSpell;                               // 36
    uint32    StackAmount;                                  // 37
    uint32    Totem[MAX_SPELL_TOTEMS];                      // 38-39
    int32     Reagent[MAX_SPELL_REAGENTS];                  // 40-47
    uint32    ReagentCount[MAX_SPELL_REAGENTS];             // 48-55
    int32     EquippedItemClass;                            // 56
    int32     EquippedItemSubClassMask;                     // 57
    uint32    Effect[MAX_EFFECT_INDEX];                     // 58-60
    int32     EffectDieSides[MAX_EFFECT_INDEX];             // 61-63
    uint32    EffectBaseDice[MAX_EFFECT_INDEX];             // 64-66
    float     EffectDicePerLevel[MAX_EFFECT_INDEX];         // 67-69
    float     EffectRealPointsPerLevel[MAX_EFFECT_INDEX];   // 70-72
    int32     EffectBasePoints[MAX_EFFECT_INDEX];           // 73-75
    uint32    EffectImplicitTargetA[MAX_EFFECT_INDEX];      // 76-78
    uint32    EffectImplicitTargetB[MAX_EFFECT_INDEX];      // 79-81
    uint32    EffectRadiusIndex[MAX_EFFECT_INDEX];          // 82-84
    uint32    EffectApplyAuraName[MAX_EFFECT_INDEX];        // 85-87
    uint32    EffectAmplitude[MAX_EFFECT_INDEX];            // 88-90
    float     EffectMultipleValue[MAX_EFFECT_INDEX];        // 91-93
    uint32    EffectChainTarget[MAX_EFFECT_INDEX];          // 94-96
    uint32    EffectItemType[MAX_EFFECT_INDEX];             // 97-99
    int32     EffectMiscValue[MAX_EFFECT_INDEX];            // 100-102
    uint32    EffectTriggerSpell[MAX_EFFECT_INDEX];         // 103-105
    float     EffectPointsPerComboPoint[MAX_EFFECT_INDEX];  // 106-108
    uint32    SpellVisual;                                  // 109
    uint32    SpellVisual2;                                 // 110
    uint32    SpellIconID;                                  // 111
    uint32    activeIconID;                                 // 112
    uint32    spellPriority;                                // 113
    char*     SpellName[8];                                 // 114-121
    uint32    SpellNameFlag;                                // 122
    char*     Rank[8];                                      // 123-130
    uint32    RankFlags;                                    // 131
    char*     Description[8];                               // 132-139
    uint32    DescriptionFlags;                             // 140
    char*     ToolTip[8];                                   // 141-148
    uint32    ToolTipFlags;                                 // 149
    uint32    ManaCostPercentage;                           // 150
    uint32    StartRecoveryCategory;                        // 151
    uint32    StartRecoveryTime;                            // 152
    uint32    MaxTargetLevel;                               // 153
    uint32    SpellFamilyName;                              // 154
    uint32    SpellFamilyFlags;                             // 155
    uint32    MaxAffectedTargets;                           // 156
    uint32    DmgClass;                                     // 157
    uint32    PreventionType;                               // 158
    int32     StanceBarOrder;                               // 159
    float     DmgMultiplier[MAX_EFFECT_INDEX];              // 160-162
    uint32    AttributesEx3;                                // 163
};

struct SpellEntry4449
{
    uint32    Id;                                           // 0
    uint32    School;                                       // 1
    uint32    Category;                                     // 2
    uint32    castUI;                                       // 3
    uint32    Dispel;                                       // 4
    uint32    Mechanic;                                     // 5
    uint32    Attributes;                                   // 6
    uint32    AttributesEx;                                 // 7
    uint32    AttributesEx2;                                // 8
    uint32    Stances;                                      // 9
    uint32    Targets;                                      // 10
    uint32    TargetCreatureType;                           // 11
    uint32    RequiresSpellFocus;                           // 12
    uint32    CasterAuraState;                              // 13
    uint32    TargetAuraState;                              // 14
    uint32    CastingTimeIndex;                             // 15
    uint32    RecoveryTime;                                 // 16
    uint32    CategoryRecoveryTime;                         // 17
    uint32    InterruptFlags;                               // 18
    uint32    AuraInterruptFlags;                           // 19
    uint32    ChannelInterruptFlags;                        // 20
    uint32    procFlags;                                    // 21
    uint32    procChance;                                   // 22
    uint32    procCharges;                                  // 23
    uint32    maxLevel;                                     // 24
    uint32    baseLevel;                                    // 25
    uint32    spellLevel;                                   // 26
    uint32    DurationIndex;                                // 27
    uint32    powerType;                                    // 28
    uint32    manaCost;                                     // 29
    uint32    manaCostPerlevel;                             // 30
    uint32    manaPerSecond;                                // 31
    uint32    manaPerSecondPerLevel;                        // 32
    uint32    rangeIndex;                                   // 33
    float     speed;                                        // 34
    uint32    modalNextSpell;                               // 35
    uint32    StackAmount;                                  // 36
    uint32    Totem[MAX_SPELL_TOTEMS];                      // 37-38
    int32     Reagent[MAX_SPELL_REAGENTS];                  // 39-46
    uint32    ReagentCount[MAX_SPELL_REAGENTS];             // 47-54
    int32     EquippedItemClass;                            // 55
    int32     EquippedItemSubClassMask;                     // 56
    uint32    Effect[MAX_EFFECT_INDEX];                     // 57-59
    int32     EffectDieSides[MAX_EFFECT_INDEX];             // 60-62
    uint32    EffectBaseDice[MAX_EFFECT_INDEX];             // 63-65
    float     EffectDicePerLevel[MAX_EFFECT_INDEX];         // 66-68
    float     EffectRealPointsPerLevel[MAX_EFFECT_INDEX];   // 69-71
    int32     EffectBasePoints[MAX_EFFECT_INDEX];           // 72-74
    uint32    EffectImplicitTargetA[MAX_EFFECT_INDEX];      // 75-77
    uint32    EffectImplicitTargetB[MAX_EFFECT_INDEX];      // 78-80
    uint32    EffectRadiusIndex[MAX_EFFECT_INDEX];          // 81-83
    uint32    EffectApplyAuraName[MAX_EFFECT_INDEX];        // 84-86
    uint32    EffectAmplitude[MAX_EFFECT_INDEX];            // 87-89
    float     EffectMultipleValue[MAX_EFFECT_INDEX];        // 90-92
    uint32    EffectChainTarget[MAX_EFFECT_INDEX];          // 93-95
    uint32    EffectItemType[MAX_EFFECT_INDEX];             // 96-98
    int32     EffectMiscValue[MAX_EFFECT_INDEX];            // 99-101
    uint32    EffectTriggerSpell[MAX_EFFECT_INDEX];         // 102-104
    float     EffectPointsPerComboPoint[MAX_EFFECT_INDEX];  // 105-107
    uint32    SpellVisual;                                  // 108
    uint32    SpellVisual2;                                 // 109
    uint32    SpellIconID;                                  // 110
    uint32    activeIconID;                                 // 111
    uint32    spellPriority;                                // 112
    char*     SpellName[8];                                 // 113-120
    uint32    SpellNameFlag;                                // 121
    char*     Rank[8];                                      // 122-129
    uint32    RankFlags;                                    // 130
    char*     Description[8];                               // 131-138
    uint32    DescriptionFlags;                             // 139
    char*     ToolTip[8];                                   // 140-147
    uint32    ToolTipFlags;                                 // 148
    uint32    ManaCostPercentage;                           // 149
    uint32    StartRecoveryCategory;                        // 150
    uint32    StartRecoveryTime;                            // 151
    uint32    MaxTargetLevel;                               // 152
    uint32    SpellFamilyName;                              // 153
    uint32    SpellFamilyFlags;                             // 154
    uint32    MaxAffectedTargets;                           // 155
    uint32    DmgClass;                                     // 156
    uint32    PreventionType;                               // 157
    int32     StanceBarOrder;                               // 158
    float     DmgMultiplier[MAX_EFFECT_INDEX];              // 159-161
    uint32    AttributesEx3;                                // 162
};

struct SpellEntry4297
{
    uint32    Id;                                           // 0
    uint32    School;                                       // 1
    uint32    Category;                                     // 2
    uint32    castUI;                                       // 3
    uint32    Dispel;                                       // 4
    uint32    Attributes;                                   // 5
    uint32    AttributesEx;                                 // 6
    uint32    AttributesEx2;                                // 7
    uint32    Stances;                                      // 8
    uint32    Targets;                                      // 9
    uint32    TargetCreatureType;                           // 10
    uint32    RequiresSpellFocus;                           // 11
    uint32    CasterAuraState;                              // 12
    uint32    TargetAuraState;                              // 13
    uint32    CastingTimeIndex;                             // 14
    uint32    RecoveryTime;                                 // 15
    uint32    CategoryRecoveryTime;                         // 16
    uint32    InterruptFlags;                               // 17
    uint32    AuraInterruptFlags;                           // 18
    uint32    ChannelInterruptFlags;                        // 19
    uint32    procFlags;                                    // 20
    uint32    procChance;                                   // 21
    uint32    procCharges;                                  // 22
    uint32    maxLevel;                                     // 23
    uint32    baseLevel;                                    // 24
    uint32    spellLevel;                                   // 25
    uint32    DurationIndex;                                // 26
    uint32    powerType;                                    // 27
    uint32    manaCost;                                     // 28
    uint32    manaCostPerlevel;                             // 29
    uint32    manaPerSecond;                                // 30
    uint32    manaPerSecondPerLevel;                        // 31
    uint32    rangeIndex;                                   // 32
    float     speed;                                        // 33
    uint32    modalNextSpell;                               // 34
    uint32    StackAmount;                                  // 35
    uint32    Totem[MAX_SPELL_TOTEMS];                      // 36-37
    int32     Reagent[MAX_SPELL_REAGENTS];                  // 38-45
    uint32    ReagentCount[MAX_SPELL_REAGENTS];             // 46-53
    int32     EquippedItemClass;                            // 54
    int32     EquippedItemSubClassMask;                     // 55
    uint32    Effect[MAX_EFFECT_INDEX];                     // 56-58
    int32     EffectDieSides[MAX_EFFECT_INDEX];             // 59-61
    uint32    EffectBaseDice[MAX_EFFECT_INDEX];             // 62-64
    float     EffectDicePerLevel[MAX_EFFECT_INDEX];         // 65-67
    float     EffectRealPointsPerLevel[MAX_EFFECT_INDEX];   // 68-70
    int32     EffectBasePoints[MAX_EFFECT_INDEX];           // 71-73
    uint32    EffectImplicitTargetA[MAX_EFFECT_INDEX];      // 74-76
    uint32    EffectImplicitTargetB[MAX_EFFECT_INDEX];      // 77-79
    uint32    EffectRadiusIndex[MAX_EFFECT_INDEX];          // 80-82
    uint32    EffectApplyAuraName[MAX_EFFECT_INDEX];        // 83-85
    uint32    EffectAmplitude[MAX_EFFECT_INDEX];            // 86-88
    float     EffectMultipleValue[MAX_EFFECT_INDEX];        // 89-91
    uint32    EffectChainTarget[MAX_EFFECT_INDEX];          // 92-94
    uint32    EffectItemType[MAX_EFFECT_INDEX];             // 95-97
    int32     EffectMiscValue[MAX_EFFECT_INDEX];            // 98-100
    uint32    EffectTriggerSpell[MAX_EFFECT_INDEX];         // 101-103
    float     EffectPointsPerComboPoint[MAX_EFFECT_INDEX];  // 104-106
    uint32    SpellVisual;                                  // 107
    uint32    SpellVisual2;                                 // 108
    uint32    SpellIconID;                                  // 109
    uint32    activeIconID;                                 // 110
    uint32    spellPriority;                                // 111
    char*     SpellName[8];                                 // 112-119
    uint32    SpellNameFlag;                                // 120
    char*     Rank[8];                                      // 121-128
    uint32    RankFlags;                                    // 129
    char*     Description[8];                               // 130-137
    uint32    DescriptionFlags;                             // 138
    char*     ToolTip[8];                                   // 139-146
    uint32    ToolTipFlags;                                 // 147
    uint32    ManaCostPercentage;                           // 148
    uint32    StartRecoveryCategory;                        // 149
    uint32    StartRecoveryTime;                            // 150
    uint32    MaxTargetLevel;                               // 151
    uint32    SpellFamilyName;                              // 152
    uint32    SpellFamilyFlags;                             // 153
    uint32    MaxAffectedTargets;                           // 154
    uint32    DmgClass;                                     // 155
    uint32    PreventionType;                               // 156
    int32     StanceBarOrder;                               // 157
    float     DmgMultiplier[MAX_EFFECT_INDEX];              // 158-160
    uint32    AttributesEx3;                                // 161
};

struct FactionEntry5875
{
    uint32      Id;                                         // 0        m_ID
    int32       reputationListID;                           // 1        m_reputationIndex
    uint32      BaseRepRaceMask[4];                         // 2-5      m_reputationRaceMask
    uint32      BaseRepClassMask[4];                        // 6-9      m_reputationClassMask
    int32       BaseRepValue[4];                            // 10-13    m_reputationBase
    uint32      ReputationFlags[4];                         // 14-17    m_reputationFlags
    uint32      team;                                       // 18       m_parentFactionID
    char*       name[8];                                    // 19-26    m_name_lang
                                                            // 27 string flags
    char* description[8];                                   // 28-35    m_description_lang
};

struct FactionEntry4297
{
    uint32      Id;                                         // 0        m_ID
    int32       reputationListID;                           // 1        m_reputationIndex
    uint32      BaseRepRaceMask[4];                         // 2-5      m_reputationRaceMask
    uint32      BaseRepClassMask[4];                        // 6-9      m_reputationClassMask
    int32       BaseRepValue[4];                            // 10-13    m_reputationBase
    uint32      ReputationFlags[4];                         // 14-17    m_reputationFlags
    uint32      team;                                       // 18       m_parentFactionID
    char*       name[8];                                    // 19-26    m_name_lang
                                                            // 27 string flags
};

struct FactionTemplateEntry5875
{
    uint32      ID;                                         // 0
    uint32      faction;                                    // 1
    uint32      factionFlags;                               // 2 specific flags for that faction
    uint32      ourMask;                                    // 3 if mask set (see FactionMasks) then faction included in masked team
    uint32      friendlyMask;                               // 4 if mask set (see FactionMasks) then faction friendly to masked team
    uint32      hostileMask;                                // 5 if mask set (see FactionMasks) then faction hostile to masked team
    uint32      enemyFaction[4];                            // 6-9
    uint32      friendFaction[4];                           // 10-13
};

struct TaxiNodesEntry5875
{
    uint32    ID;                                           // 0        m_ID
    uint32    map_id;                                       // 1        m_ContinentID
    float     x;                                            // 2        m_x
    float     y;                                            // 3        m_y
    float     z;                                            // 4        m_z
    char*     name[8];                                      // 5-12     m_Name_lang
                                                            // 13 string flags
    uint32    MountCreatureID[2];                           // 14-15    m_MountCreatureID[2] horde[14]-alliance[15]
};

struct TaxiNodesEntry5302
{
    uint32    ID;                                           // 0        m_ID
    uint32    map_id;                                       // 1        m_ContinentID
    float     x;                                            // 2        m_x
    float     y;                                            // 3        m_y
    float     z;                                            // 4        m_z
    char*     name[8];                                      // 5-12     m_Name_lang
                                                            // 13 string flags
};

struct SkillLineAbilityEntry5875
{
    uint32    id;                                           // 0, INDEX
    uint32    skillId;                                      // 1
    uint32    spellId;                                      // 2
    uint32    racemask;                                     // 3
    uint32    classmask;                                    // 4
                                                            //uint32    racemaskNot;                                // 5 always 0 in 2.4.2
                                                            //uint32    classmaskNot;                               // 6 always 0 in 2.4.2
    uint32    req_skill_value;                              // 7 for trade skill.not for training.
    uint32    forward_spellid;                              // 8
    uint32    learnOnGetSkill;                              // 9 can be 1 or 2 for spells learned on get skill
    uint32    max_value;                                    // 10
    uint32    min_value;                                    // 11
                                                            // 12-13, unknown, always 0
    uint32    reqtrainpoints;                               // 14
};

#if defined( __GNUC__ )
#pragma pack()
#else
#pragma pack(pop)
#endif

#endif