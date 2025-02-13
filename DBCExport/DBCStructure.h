#ifndef MANGOS_DBCSTRUCTURE_H
#define MANGOS_DBCSTRUCTURE_H

#include <iostream>
#include <fstream>
#include "SharedDefines.h"
#include "Utility.h"
#include "DB2Data.h"

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

    AreaTriggerEntry5875* ToLatestStructure() const
    {
        AreaTriggerEntry5875* data = new AreaTriggerEntry5875();
        data->id = id;
        data->mapid = mapid;
        data->x = x;
        data->y = y;
        data->z = z;
        data->radius = radius;
        data->box_x = box_x;
        data->box_y = box_y;
        data->box_z = box_z;
        data->box_orientation = box_orientation;
        return data;
    }

    bool operator==(AreaTriggerEntry5875 const& other) const
    {
        if (other.id != id)
            return false;
        if (other.mapid != mapid)
            return false;
        if (other.x != x)
            return false;
        if (other.y != y)
            return false;
        if (other.z != z)
            return false;
        if (other.radius != radius)
            return false;
        if (other.box_x != box_x)
            return false;
        if (other.box_y != box_y)
            return false;
        if (other.box_z != box_z)
            return false;
        if (other.box_orientation != box_orientation)
            return false;

        return true;
    }

    bool operator!=(AreaTriggerEntry5875 const& other) const
    {
        return !(other == *this);
    }

    void WriteToSqlFile(std::ofstream& myfile, uint16 build) const
    {
        myfile << "(";
        myfile << id << ", ";
        myfile << build << ", ";
        myfile << mapid << ", ";
        myfile << x << ", ";
        myfile << y << ", ";
        myfile << z << ", ";
        myfile << radius << ", ";
        myfile << box_x << ", ";
        myfile << box_y << ", ";
        myfile << box_z << ", ";
        myfile << box_orientation << ")";
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
    char*     SpellName[MAX_DBC_LOCALE];                    // 120-127
    uint32    SpellNameFlag;                                // 128
    char*     Rank[MAX_DBC_LOCALE];                         // 129-136
    uint32    RankFlags;                                    // 137
    char*     Description[MAX_DBC_LOCALE];                  // 138-145
    uint32    DescriptionFlags;                             // 146
    char*     ToolTip[MAX_DBC_LOCALE];                      // 147-154
    uint32    ToolTipFlags;                                 // 155
    uint32    ManaCostPercentage;                           // 156
    uint32    StartRecoveryCategory;                        // 157
    uint32    StartRecoveryTime;                            // 158
    uint32    MaxTargetLevel;                               // 159
    uint32    SpellFamilyName;                              // 160
    uint64    SpellFamilyFlags;                             // 161+162
    uint32    MaxAffectedTargets;                           // 163
    uint32    DmgClass;                                     // 164
    uint32    PreventionType;                               // 165
    int32     StanceBarOrder;                               // 166
    float     DmgMultiplier[MAX_EFFECT_INDEX];              // 167-169
    uint32    MinFactionId;                                 // 170
    uint32    MinReputation;                                // 171
    uint32    RequiredAuraVision;                           // 172

    SpellEntry5875* ToLatestStructure() const
    {
        SpellEntry5875* data = new SpellEntry5875();
        data->Id = Id;
        data->School = School;
        data->Category = Category;
        data->castUI = castUI;
        data->Dispel = Dispel;
        data->Mechanic = Mechanic;
        data->Attributes = Attributes;
        data->AttributesEx = AttributesEx;
        data->AttributesEx2 = AttributesEx2;
        data->AttributesEx3 = AttributesEx3;
        data->AttributesEx4 = AttributesEx4;
        data->Stances = Stances;
        data->StancesNot = StancesNot;
        data->Targets = Targets;
        data->TargetCreatureType = TargetCreatureType;
        data->RequiresSpellFocus = RequiresSpellFocus;
        data->CasterAuraState = CasterAuraState;
        data->TargetAuraState = TargetAuraState;
        data->CastingTimeIndex = CastingTimeIndex;
        data->RecoveryTime = RecoveryTime;
        data->CategoryRecoveryTime = CategoryRecoveryTime;
        data->InterruptFlags = InterruptFlags;
        data->AuraInterruptFlags = AuraInterruptFlags;
        data->ChannelInterruptFlags = ChannelInterruptFlags;
        data->procFlags = procFlags;
        data->procChance = procChance;
        data->procCharges = procCharges;
        data->maxLevel = maxLevel;
        data->baseLevel = baseLevel;
        data->spellLevel = spellLevel;
        data->DurationIndex = DurationIndex;
        data->powerType = powerType;
        data->manaCost = manaCost;
        data->manaCostPerlevel = manaCostPerlevel;
        data->manaPerSecond = manaPerSecond;
        data->manaPerSecondPerLevel = manaPerSecondPerLevel;
        data->rangeIndex = rangeIndex;
        data->speed = speed;
        data->modalNextSpell = modalNextSpell;
        data->StackAmount = StackAmount;
        std::copy(std::begin(Totem), std::end(Totem), std::begin(data->Totem));
        std::copy(std::begin(Reagent), std::end(Reagent), std::begin(data->Reagent));
        std::copy(std::begin(ReagentCount), std::end(ReagentCount), std::begin(data->ReagentCount));
        data->EquippedItemClass = EquippedItemClass;
        data->EquippedItemSubClassMask = EquippedItemSubClassMask;
        data->EquippedItemInventoryTypeMask = EquippedItemInventoryTypeMask;
        std::copy(std::begin(Effect), std::end(Effect), std::begin(data->Effect));
        std::copy(std::begin(EffectDieSides), std::end(EffectDieSides), std::begin(data->EffectDieSides));
        std::copy(std::begin(EffectBaseDice), std::end(EffectBaseDice), std::begin(data->EffectBaseDice));
        std::copy(std::begin(EffectDicePerLevel), std::end(EffectDicePerLevel), std::begin(data->EffectDicePerLevel));
        std::copy(std::begin(EffectRealPointsPerLevel), std::end(EffectRealPointsPerLevel), std::begin(data->EffectRealPointsPerLevel));
        std::copy(std::begin(EffectBasePoints), std::end(EffectBasePoints), std::begin(data->EffectBasePoints));
        std::copy(std::begin(EffectMechanic), std::end(EffectMechanic), std::begin(data->EffectMechanic));
        std::copy(std::begin(EffectImplicitTargetA), std::end(EffectImplicitTargetA), std::begin(data->EffectImplicitTargetA));
        std::copy(std::begin(EffectImplicitTargetB), std::end(EffectImplicitTargetB), std::begin(data->EffectImplicitTargetB));
        std::copy(std::begin(EffectRadiusIndex), std::end(EffectRadiusIndex), std::begin(data->EffectRadiusIndex));
        std::copy(std::begin(EffectApplyAuraName), std::end(EffectApplyAuraName), std::begin(data->EffectApplyAuraName));
        std::copy(std::begin(EffectAmplitude), std::end(EffectAmplitude), std::begin(data->EffectAmplitude));
        std::copy(std::begin(EffectMultipleValue), std::end(EffectMultipleValue), std::begin(data->EffectMultipleValue));
        std::copy(std::begin(EffectChainTarget), std::end(EffectChainTarget), std::begin(data->EffectChainTarget));
        std::copy(std::begin(EffectItemType), std::end(EffectItemType), std::begin(data->EffectItemType));
        std::copy(std::begin(EffectMiscValue), std::end(EffectMiscValue), std::begin(data->EffectMiscValue));
        std::copy(std::begin(EffectTriggerSpell), std::end(EffectTriggerSpell), std::begin(data->EffectTriggerSpell));
        std::copy(std::begin(EffectPointsPerComboPoint), std::end(EffectPointsPerComboPoint), std::begin(data->EffectPointsPerComboPoint));
        data->SpellVisual = SpellVisual;
        data->SpellVisual2 = SpellVisual2;
        data->SpellIconID = SpellIconID;
        data->activeIconID = activeIconID;
        data->spellPriority = spellPriority;
        CopyStringArrays(SpellName, data->SpellName, MAX_DBC_LOCALE);
        data->SpellNameFlag = SpellNameFlag;
        CopyStringArrays(Rank, data->Rank, MAX_DBC_LOCALE);
        data->RankFlags = RankFlags;
        CopyStringArrays(Description, data->Description, MAX_DBC_LOCALE);
        data->DescriptionFlags = DescriptionFlags;
        CopyStringArrays(ToolTip, data->ToolTip, MAX_DBC_LOCALE);
        data->ToolTipFlags = ToolTipFlags;
        data->ManaCostPercentage = ManaCostPercentage;
        data->StartRecoveryCategory = StartRecoveryCategory;
        data->StartRecoveryTime = StartRecoveryTime;
        data->MaxTargetLevel = MaxTargetLevel;
        data->SpellFamilyName = SpellFamilyName;
        data->SpellFamilyFlags = SpellFamilyFlags;
        data->MaxAffectedTargets = MaxAffectedTargets;
        data->DmgClass = DmgClass;
        data->PreventionType = PreventionType;
        data->StanceBarOrder = StanceBarOrder;
        std::copy(std::begin(DmgMultiplier), std::end(DmgMultiplier), std::begin(data->DmgMultiplier));
        data->MinFactionId = MinFactionId;
        data->MinReputation = MinReputation;
        data->RequiredAuraVision = RequiredAuraVision;
        return data;
    }

    bool operator==(SpellEntry5875 const& other) const
    {
        if (other.Id != Id)
            return false;
        if (other.School != School)
            return false;
        if (other.Category != Category)
            return false;
        if (other.castUI != castUI)
            return false;
        if (other.Dispel != Dispel)
            return false;
        if (other.Mechanic != Mechanic)
            return false;
        if (other.Attributes != Attributes)
            return false;
        if (other.AttributesEx != AttributesEx)
            return false;
        if (other.AttributesEx2 != AttributesEx2)
            return false;
        if (other.AttributesEx3 != AttributesEx3)
            return false;
        if (other.AttributesEx4 != AttributesEx4)
            return false;
        if (other.Stances != Stances)
            return false;
        if (other.StancesNot != StancesNot)
            return false;
        if (other.Targets != Targets)
            return false;
        if (other.TargetCreatureType != TargetCreatureType)
            return false;
        if (other.RequiresSpellFocus != RequiresSpellFocus)
            return false;
        if (other.CasterAuraState != CasterAuraState)
            return false;
        if (other.TargetAuraState != TargetAuraState)
            return false;
        if (other.CastingTimeIndex != CastingTimeIndex)
            return false;
        if (other.RecoveryTime != RecoveryTime)
            return false;
        if (other.CategoryRecoveryTime != CategoryRecoveryTime)
            return false;
        if (other.InterruptFlags != InterruptFlags)
            return false;
        if (other.AuraInterruptFlags != AuraInterruptFlags)
            return false;
        if (other.ChannelInterruptFlags != ChannelInterruptFlags)
            return false;
        if (other.procFlags != procFlags)
            return false;
        if (other.procChance != procChance)
            return false;
        if (other.procCharges != procCharges)
            return false;
        if (other.maxLevel != maxLevel)
            return false;
        if (other.baseLevel != baseLevel)
            return false;
        if (other.spellLevel != spellLevel)
            return false;
        if (other.DurationIndex != DurationIndex)
            return false;
        if (other.powerType != powerType)
            return false;
        if (other.manaCost != manaCost)
            return false;
        if (other.manaCostPerlevel != manaCostPerlevel)
            return false;
        if (other.manaPerSecond != manaPerSecond)
            return false;
        if (other.manaPerSecondPerLevel != manaPerSecondPerLevel)
            return false;
        if (other.rangeIndex != rangeIndex)
            return false;
        if (other.speed != speed)
            return false;
        if (other.modalNextSpell != modalNextSpell)
            return false;
        if (other.StackAmount != StackAmount)
            return false;

        if (!std::equal(std::begin(Totem), std::end(Totem), std::begin(other.Totem)))
            return false;
        if (!std::equal(std::begin(Reagent), std::end(Reagent), std::begin(other.Reagent)))
            return false;
        if (!std::equal(std::begin(ReagentCount), std::end(ReagentCount), std::begin(other.ReagentCount)))
            return false;
        if (!std::equal(std::begin(Effect), std::end(Effect), std::begin(other.Effect)))
            return false;
        if (!std::equal(std::begin(EffectDieSides), std::end(EffectDieSides), std::begin(other.EffectDieSides)))
            return false;
        if (!std::equal(std::begin(EffectBaseDice), std::end(EffectBaseDice), std::begin(other.EffectBaseDice)))
            return false;
        if (!std::equal(std::begin(EffectDicePerLevel), std::end(EffectDicePerLevel), std::begin(other.EffectDicePerLevel)))
            return false;
        if (!std::equal(std::begin(EffectRealPointsPerLevel), std::end(EffectRealPointsPerLevel), std::begin(other.EffectRealPointsPerLevel)))
            return false;
        if (!std::equal(std::begin(EffectBasePoints), std::end(EffectBasePoints), std::begin(other.EffectBasePoints)))
            return false;
        if (!std::equal(std::begin(EffectMechanic), std::end(EffectMechanic), std::begin(other.EffectMechanic)))
            return false;
        if (!std::equal(std::begin(EffectImplicitTargetA), std::end(EffectImplicitTargetA), std::begin(other.EffectImplicitTargetA)))
            return false;
        if (!std::equal(std::begin(EffectImplicitTargetB), std::end(EffectImplicitTargetB), std::begin(other.EffectImplicitTargetB)))
            return false;
        if (!std::equal(std::begin(EffectRadiusIndex), std::end(EffectRadiusIndex), std::begin(other.EffectRadiusIndex)))
            return false;
        if (!std::equal(std::begin(EffectApplyAuraName), std::end(EffectApplyAuraName), std::begin(other.EffectApplyAuraName)))
            return false;
        if (!std::equal(std::begin(EffectAmplitude), std::end(EffectAmplitude), std::begin(other.EffectAmplitude)))
            return false;
        if (!std::equal(std::begin(EffectMultipleValue), std::end(EffectMultipleValue), std::begin(other.EffectMultipleValue)))
            return false;
        if (!std::equal(std::begin(EffectChainTarget), std::end(EffectChainTarget), std::begin(other.EffectChainTarget)))
            return false;
        if (!std::equal(std::begin(EffectItemType), std::end(EffectItemType), std::begin(other.EffectItemType)))
            return false;
        if (!std::equal(std::begin(EffectMiscValue), std::end(EffectMiscValue), std::begin(other.EffectMiscValue)))
            return false;
        if (!std::equal(std::begin(EffectTriggerSpell), std::end(EffectTriggerSpell), std::begin(other.EffectTriggerSpell)))
            return false;
        if (!std::equal(std::begin(EffectPointsPerComboPoint), std::end(EffectPointsPerComboPoint), std::begin(other.EffectPointsPerComboPoint)))
            return false;
        if (!std::equal(std::begin(DmgMultiplier), std::end(DmgMultiplier), std::begin(other.DmgMultiplier)))
            return false;

        if (!CompareStringArrays(other.SpellName, SpellName, MAX_DBC_LOCALE))
            return false;
        if (!CompareStringArrays(other.Rank, Rank, MAX_DBC_LOCALE))
            return false;
        if (!CompareStringArrays(other.Description, Description, MAX_DBC_LOCALE))
            return false;
        if (!CompareStringArrays(other.ToolTip, ToolTip, MAX_DBC_LOCALE))
            return false;

        if (other.EquippedItemClass != EquippedItemClass)
            return false;
        if (other.EquippedItemSubClassMask != EquippedItemSubClassMask)
            return false;
        if (other.EquippedItemInventoryTypeMask != EquippedItemInventoryTypeMask)
            return false;
        if (other.SpellVisual != SpellVisual)
            return false;
        if (other.SpellVisual2 != SpellVisual2)
            return false;
        if (other.SpellIconID != SpellIconID)
            return false;
        if (other.activeIconID != activeIconID)
            return false;
        if (other.spellPriority != spellPriority)
            return false;
        /*
        if (other.SpellNameFlag != SpellNameFlag)
        return false;
        if (other.RankFlags != RankFlags)
        return false;
        if (other.DescriptionFlags != DescriptionFlags)
        return false;
        if (other.ToolTipFlags != ToolTipFlags)
        return false;
        */
        if (other.ManaCostPercentage != ManaCostPercentage)
            return false;
        if (other.StartRecoveryCategory != StartRecoveryCategory)
            return false;
        if (other.StartRecoveryTime != StartRecoveryTime)
            return false;
        if (other.MaxTargetLevel != MaxTargetLevel)
            return false;
        if (other.SpellFamilyName != SpellFamilyName)
            return false;
        if (other.SpellFamilyFlags != SpellFamilyFlags)
            return false;
        if (other.MaxAffectedTargets != MaxAffectedTargets)
            return false;
        if (other.DmgClass != DmgClass)
            return false;
        if (other.PreventionType != PreventionType)
            return false;
        if (other.StanceBarOrder != StanceBarOrder)
            return false;
        if (other.MinFactionId != MinFactionId)
            return false;
        if (other.MinReputation != MinReputation)
            return false;
        if (other.RequiredAuraVision != RequiredAuraVision)
            return false;

        return true;
    }

    bool operator!=(SpellEntry5875 const& other) const
    {
        return !(other == *this);
    }

    void WriteToSqlFile(std::ofstream& myfile, uint16 build) const
    {
        SpellEntry5875 const* spellEntry = this;
        myfile << "(";
        myfile << spellEntry->Id << ", "; // 1
        myfile << build << ", ";
        myfile << spellEntry->School << ", "; // 2
        myfile << spellEntry->Category << ", "; // 3
        myfile << spellEntry->castUI << ", "; // 4
        myfile << spellEntry->Dispel << ", "; // 5
        myfile << spellEntry->Mechanic << ", "; // 6
        myfile << spellEntry->Attributes << ", "; // 7
        myfile << spellEntry->AttributesEx << ", "; // 8
        myfile << spellEntry->AttributesEx2 << ", "; // 9
        myfile << spellEntry->AttributesEx3 << ", "; // 10
        myfile << spellEntry->AttributesEx4 << ", "; // 11
        myfile << spellEntry->Stances << ", "; // 12
        myfile << spellEntry->StancesNot << ", "; // 13
        myfile << spellEntry->Targets << ", "; // 14
        myfile << spellEntry->TargetCreatureType << ", "; // 15
        myfile << spellEntry->RequiresSpellFocus << ", "; // 16
        myfile << spellEntry->CasterAuraState << ", "; // 17
        myfile << spellEntry->TargetAuraState << ", "; // 18
        myfile << spellEntry->CastingTimeIndex << ", "; // 19
        myfile << spellEntry->RecoveryTime << ", "; // 20
        myfile << spellEntry->CategoryRecoveryTime << ", "; // 21
        myfile << spellEntry->InterruptFlags << ", "; // 22
        myfile << spellEntry->AuraInterruptFlags << ", "; // 23
        myfile << spellEntry->ChannelInterruptFlags << ", "; // 24
        myfile << spellEntry->procFlags << ", "; // 25
        myfile << spellEntry->procChance << ", "; // 26
        myfile << spellEntry->procCharges << ", "; // 27
        myfile << spellEntry->maxLevel << ", "; // 28
        myfile << spellEntry->baseLevel << ", "; // 29
        myfile << spellEntry->spellLevel << ", "; // 30
        myfile << spellEntry->DurationIndex << ", "; // 31
        myfile << spellEntry->powerType << ", "; // 32
        myfile << spellEntry->manaCost << ", "; // 33
        myfile << spellEntry->manaCostPerlevel << ", "; // 34
        myfile << spellEntry->manaPerSecond << ", "; // 35
        myfile << spellEntry->manaPerSecondPerLevel << ", "; // 36
        myfile << spellEntry->rangeIndex << ", "; // 37
        myfile << spellEntry->speed << ", "; // 38
        myfile << spellEntry->modalNextSpell << ", "; // 39
        myfile << spellEntry->StackAmount << ", "; // 40
        myfile << spellEntry->Totem[0] << ", "; // 41
        myfile << spellEntry->Totem[1] << ", "; // 42
        myfile << spellEntry->Reagent[0] << ", "; // 43
        myfile << spellEntry->Reagent[1] << ", "; // 44
        myfile << spellEntry->Reagent[2] << ", "; // 45
        myfile << spellEntry->Reagent[3] << ", "; // 46
        myfile << spellEntry->Reagent[4] << ", "; // 47
        myfile << spellEntry->Reagent[5] << ", "; // 48
        myfile << spellEntry->Reagent[6] << ", "; // 49
        myfile << spellEntry->Reagent[7] << ", "; // 50
        myfile << spellEntry->ReagentCount[0] << ", "; // 51
        myfile << spellEntry->ReagentCount[1] << ", "; // 52
        myfile << spellEntry->ReagentCount[2] << ", "; // 53
        myfile << spellEntry->ReagentCount[3] << ", "; // 54
        myfile << spellEntry->ReagentCount[4] << ", "; // 55
        myfile << spellEntry->ReagentCount[5] << ", "; // 56
        myfile << spellEntry->ReagentCount[6] << ", "; // 57
        myfile << spellEntry->ReagentCount[7] << ", "; // 58
        myfile << spellEntry->EquippedItemClass << ", "; // 59
        myfile << spellEntry->EquippedItemSubClassMask << ", "; // 60
        myfile << spellEntry->EquippedItemInventoryTypeMask << ", "; // 61
        myfile << spellEntry->Effect[0] << ", "; // 62
        myfile << spellEntry->Effect[1] << ", "; // 63
        myfile << spellEntry->Effect[2] << ", "; // 64
        myfile << spellEntry->EffectDieSides[0] << ", "; // 65
        myfile << spellEntry->EffectDieSides[1] << ", "; // 66
        myfile << spellEntry->EffectDieSides[2] << ", "; // 67
        myfile << spellEntry->EffectBaseDice[0] << ", "; // 68
        myfile << spellEntry->EffectBaseDice[1] << ", "; // 69
        myfile << spellEntry->EffectBaseDice[2] << ", "; // 70
        myfile << spellEntry->EffectDicePerLevel[0] << ", "; // 71
        myfile << spellEntry->EffectDicePerLevel[1] << ", "; // 72
        myfile << spellEntry->EffectDicePerLevel[2] << ", "; // 73
        myfile << spellEntry->EffectRealPointsPerLevel[0] << ", "; // 74
        myfile << spellEntry->EffectRealPointsPerLevel[1] << ", "; // 75
        myfile << spellEntry->EffectRealPointsPerLevel[2] << ", "; // 76
        myfile << spellEntry->EffectBasePoints[0] << ", "; // 77
        myfile << spellEntry->EffectBasePoints[1] << ", "; // 78
        myfile << spellEntry->EffectBasePoints[2] << ", "; // 79
        myfile << spellEntry->EffectMechanic[0] << ", "; // 80
        myfile << spellEntry->EffectMechanic[1] << ", "; // 81
        myfile << spellEntry->EffectMechanic[2] << ", "; // 82
        myfile << spellEntry->EffectImplicitTargetA[0] << ", "; // 83
        myfile << spellEntry->EffectImplicitTargetA[1] << ", "; // 84
        myfile << spellEntry->EffectImplicitTargetA[2] << ", "; // 85
        myfile << spellEntry->EffectImplicitTargetB[0] << ", "; // 86
        myfile << spellEntry->EffectImplicitTargetB[1] << ", "; // 87
        myfile << spellEntry->EffectImplicitTargetB[2] << ", "; // 88
        myfile << spellEntry->EffectRadiusIndex[0] << ", "; // 89
        myfile << spellEntry->EffectRadiusIndex[1] << ", "; // 90
        myfile << spellEntry->EffectRadiusIndex[2] << ", "; // 91
        myfile << spellEntry->EffectApplyAuraName[0] << ", "; // 92
        myfile << spellEntry->EffectApplyAuraName[1] << ", "; // 93
        myfile << spellEntry->EffectApplyAuraName[2] << ", "; // 94
        myfile << spellEntry->EffectAmplitude[0] << ", "; // 95
        myfile << spellEntry->EffectAmplitude[1] << ", "; // 96
        myfile << spellEntry->EffectAmplitude[2] << ", "; // 97
        myfile << spellEntry->EffectMultipleValue[0] << ", "; // 98
        myfile << spellEntry->EffectMultipleValue[1] << ", "; // 99
        myfile << spellEntry->EffectMultipleValue[2] << ", "; // 100
        myfile << spellEntry->EffectChainTarget[0] << ", "; // 101
        myfile << spellEntry->EffectChainTarget[1] << ", "; // 102
        myfile << spellEntry->EffectChainTarget[2] << ", "; // 103
        myfile << spellEntry->EffectItemType[0] << ", "; // 104
        myfile << spellEntry->EffectItemType[1] << ", "; // 105
        myfile << spellEntry->EffectItemType[2] << ", "; // 106
        myfile << spellEntry->EffectMiscValue[0] << ", "; // 107
        myfile << spellEntry->EffectMiscValue[1] << ", "; // 108
        myfile << spellEntry->EffectMiscValue[2] << ", "; // 109
        myfile << spellEntry->EffectTriggerSpell[0] << ", "; // 110
        myfile << spellEntry->EffectTriggerSpell[1] << ", "; // 111
        myfile << spellEntry->EffectTriggerSpell[2] << ", "; // 112
        myfile << spellEntry->EffectPointsPerComboPoint[0] << ", "; // 113
        myfile << spellEntry->EffectPointsPerComboPoint[1] << ", "; // 114
        myfile << spellEntry->EffectPointsPerComboPoint[2] << ", "; // 115
        myfile << spellEntry->SpellVisual << ", "; // 116
        myfile << spellEntry->SpellVisual2 << ", "; // 117
        myfile << spellEntry->SpellIconID << ", "; // 118
        myfile << spellEntry->activeIconID << ", "; // 119
        myfile << spellEntry->spellPriority << ", "; // 120
        myfile << "'" << EscapeString(spellEntry->SpellName[0]) << "', "; // 121
        myfile << spellEntry->SpellNameFlag << ", "; // 129
        myfile << "'" << EscapeString(spellEntry->Rank[0]) << "', "; // 130
        myfile << spellEntry->RankFlags << ", "; // 138
        myfile << "'" << EscapeString(spellEntry->Description[0]) << "', "; // 139
        myfile << spellEntry->DescriptionFlags << ", "; // 147
        myfile << "'" << EscapeString(spellEntry->ToolTip[0]) << "', "; // 148
        myfile << spellEntry->ToolTipFlags << ", "; // 156
        myfile << spellEntry->ManaCostPercentage << ", "; // 157
        myfile << spellEntry->StartRecoveryCategory << ", "; // 158
        myfile << spellEntry->StartRecoveryTime << ", "; // 159
        myfile << "0, "; // minTargetLevel
        myfile << spellEntry->MaxTargetLevel << ", "; // 160
        myfile << spellEntry->SpellFamilyName << ", "; // 161
        myfile << spellEntry->SpellFamilyFlags << ", "; // 162
        myfile << spellEntry->MaxAffectedTargets << ", "; // 163
        myfile << spellEntry->DmgClass << ", "; // 164
        myfile << spellEntry->PreventionType << ", "; // 165
        myfile << spellEntry->StanceBarOrder << ", "; // 166
        myfile << spellEntry->DmgMultiplier[0] << ", "; // 167
        myfile << spellEntry->DmgMultiplier[1] << ", "; // 168
        myfile << spellEntry->DmgMultiplier[2] << ", "; // 169
        myfile << spellEntry->MinFactionId << ", "; // 170
        myfile << spellEntry->MinReputation << ", "; // 171
        myfile << spellEntry->RequiredAuraVision << ", "; // 172
        myfile << "0)"; // customFlags
    }

    void WriteSpellHotfixRow(std::ofstream& myfile) const
    {
        myfile << "\"" << Id << "\",";              // ID
        myfile << "\"" << Rank[0] << "\",";         // NameSubtext
        myfile << "\"" << Description[0] << "\",";  // Description
        myfile << "\"" << ToolTip[0] << "\"";       // AuraDescription
    }

    void WriteSpellNameHotfixRow(std::ofstream& myfile) const
    {
        myfile << "\"" << Id << "\",";              // ID
        myfile << "\"" << SpellName[0] << "\"";     // Name
    }

    void WriteSpellLevelsHotfixRow(std::ofstream& myfile) const
    {
        myfile << 999999 << ",";                    // ID
        myfile << 0 << ",";                         // DifficultyID
        myfile << baseLevel << ",";                 // BaseLevel
        myfile << maxLevel << ",";                  // MaxLevel
        myfile << spellLevel << ",";                // SpellLevel
        myfile << 0 << ",";                         // MasPassiveAuraLevel
        myfile << Id;                               // SpellID
    }

    void WriteSpellAuraOptionsHotfixRow(std::ofstream& myfile) const
    {
        myfile << 999999 << ",";                    // ID
        myfile << 0 << ",";                         // DifficultyID
        myfile << StackAmount << ",";               // CumulativeAura
        myfile << 0 << ",";                         // ProcCategoryRecovery
        myfile << procChance << ",";                // ProcChance
        myfile << procCharges << ",";               // ProcCharges
        myfile << 0 << ",";                         // SpellProcsPerMinuteID
        myfile << procFlags << ",";                 // ProcTypeMask0
        myfile << 0 << ",";                         // ProcTypeMask1
        myfile << Id;                               // SpellID
    }

    void WriteSpellMiscHotfixRow(std::ofstream& myfile) const
    {
        myfile << 999999 << ",";                    // ID
        myfile << 0 << ",";                         // DifficultyID
        myfile << CastingTimeIndex << ",";          // CastingTimeIndex
        myfile << DurationIndex << ",";             // DurationIndex
        myfile << rangeIndex << ",";                // RangeIndex
        myfile << (1 << School) << ",";             // SchoolMask
        myfile << speed << ",";                     // Speed
        myfile << 0 << ",";                         // LaunchDelay
        myfile << 0 << ",";                         // MinDuration
        myfile << "X-" << SpellIconID << ",";       // SpellIconFileDataID
        myfile << "X-" << activeIconID << ",";      // ActiveIconFileDataID
        myfile << Attributes << ",";                // Attributes1
        myfile << AttributesEx << ",";              // Attributes2
        myfile << AttributesEx2 << ",";             // Attributes3
        myfile << AttributesEx3 << ",";             // Attributes4
        myfile << AttributesEx4 << ",";             // Attributes5
        myfile << 0 << ",";                         // Attributes6
        myfile << 0 << ",";                         // Attributes7
        myfile << 0 << ",";                         // Attributes8
        myfile << 0 << ",";                         // Attributes9
        myfile << 0 << ",";                         // Attributes10
        myfile << 0 << ",";                         // Attributes11
        myfile << 0 << ",";                         // Attributes12
        myfile << 0 << ",";                         // Attributes13
        myfile << 0 << ",";                         // Attributes14
        myfile << Id;                               // SpellID
    }

    void WriteSpellEffectHotfixRow(std::ofstream& myfile, uint32 index) const
    {
        myfile << 999999 << ",";                    // ID
        myfile << 0 << ",";                         // DifficultyID
        myfile << index << ",";                     // EffectIndex
        myfile << Effect[index] << ",";             // Effect
        myfile << EffectAmplitude[index] << ",";    // EffectAmplitude
        myfile << 0 << ",";                         // EffectAttributes
        myfile << EffectApplyAuraName[index] << ","; // EffectAura
        myfile << 0 << ",";                         // EffectAuraPeriod
        myfile << EffectBasePoints[index] << ",";   // EffectBasePoints
        myfile << 0 << ",";                         // EffectBonusCoefficient
        myfile << 1 << ",";                         // EffectChainAmplitude
        myfile << EffectChainTarget[index] << ",";  // EffectChainTargets
        myfile << EffectDieSides[index] << ",";     // EffectDieSides
        myfile << EffectItemType[index] << ",";     // EffectItemType
        myfile << EffectMechanic[index] << ",";     // EffectMechanic
        myfile << EffectPointsPerComboPoint[index] << ","; // EffectPointsPerResource
        myfile << 0 << ",";                         // EffectPos_facing
        myfile << EffectRealPointsPerLevel[index] << ","; // EffectRealPointsPerLevel
        myfile << EffectTriggerSpell[index] << ","; // EffectTriggerSpell
        myfile << 0 << ",";                         // BonusCoefficientFromAP
        myfile << 1 << ",";                         // PvPMultiplier
        myfile << 0 << ",";                         // Coefficient
        myfile << 0 << ",";                         // Variance
        myfile << 0 << ",";                         // ResourceCoefficient
        myfile << 0 << ",";                         // GroupSizeBasePointsCoefficient
        myfile << EffectMiscValue[index] << ",";    // EffectMiscValue1
        myfile << 0 << ",";                         // EffectMiscValue2
        myfile << EffectRadiusIndex[index] << ",";  // EffectRadiusIndex1
        myfile << 0 << ",";                         // EffectRadiusIndex2
        myfile << 0 << ",";                         // EffectSpellClassMask1
        myfile << 0 << ",";                         // EffectSpellClassMask2
        myfile << 0 << ",";                         // EffectSpellClassMask3
        myfile << 0 << ",";                         // EffectSpellClassMask4
        myfile << EffectImplicitTargetA[index] << ","; // ImplicitTarget1
        myfile << EffectImplicitTargetB[index] << ","; // ImplicitTarget2
        myfile << Id;                               // SpellID
    }

    void WriteSpellXSpellVisualHotfixRow(std::ofstream& myfile) const
    {
        myfile << DB2Data::GetSpellXSpellVisualId(Id) << ",";   // ID
        myfile << 0 << ",";                         // DifficultyID
        myfile << SpellVisual << ",";               // SpellVisualID
        myfile << 1 << ",";                         // Probability
        myfile << 0 << ",";                         // Flags
        myfile << 1 << ",";                         // Priority
        myfile << 0 << ",";                         // SpellIconFileID
        myfile << 0 << ",";                         // ActiveIconFileID
        myfile << 0 << ",";                         // ViewerUnitConditionID
        myfile << 0 << ",";                         // ViewerPlayerConditionID
        myfile << 0 << ",";                         // CasterUnitConditionID
        myfile << 0 << ",";                         // CasterPlayerConditionID
        myfile << Id;                               // SpellID
    }
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
    char*     SpellName[MAX_DBC_LOCALE];                    // 117-124
    uint32    SpellNameFlag;                                // 125
    char*     Rank[MAX_DBC_LOCALE];                         // 126-133
    uint32    RankFlags;                                    // 134
    char*     Description[MAX_DBC_LOCALE];                  // 135-142
    uint32    DescriptionFlags;                             // 143
    char*     ToolTip[MAX_DBC_LOCALE];                      // 144-151
    uint32    ToolTipFlags;                                 // 152
    uint32    ManaCostPercentage;                           // 153
    uint32    StartRecoveryCategory;                        // 154
    uint32    StartRecoveryTime;                            // 155
    uint32    MaxTargetLevel;                               // 156
    uint32    SpellFamilyName;                              // 157
    uint64    SpellFamilyFlags;                             // 158+159
    uint32    MaxAffectedTargets;                           // 160
    uint32    DmgClass;                                     // 161
    uint32    PreventionType;                               // 162
    int32     StanceBarOrder;                               // 163
    float     DmgMultiplier[MAX_EFFECT_INDEX];              // 164-166
    uint32    AttributesEx3;                                // 167
    uint32    MinFactionId;                                 // 168
    uint32    MinReputation;                                // 169
    uint32    RequiredAuraVision;                           // 170

    SpellEntry5875* ToLatestStructure() const
    {
        SpellEntry5875* data = new SpellEntry5875();
        data->Id = Id;
        data->School = School;
        data->Category = Category;
        data->castUI = castUI;
        data->Dispel = Dispel;
        data->Mechanic = Mechanic;
        data->Attributes = Attributes;
        data->AttributesEx = AttributesEx;
        data->AttributesEx2 = AttributesEx2;
        data->AttributesEx3 = AttributesEx3;
        data->AttributesEx4 = 0;
        data->Stances = Stances;
        data->StancesNot = StancesNot;
        data->Targets = Targets;
        data->TargetCreatureType = TargetCreatureType;
        data->RequiresSpellFocus = RequiresSpellFocus;
        data->CasterAuraState = CasterAuraState;
        data->TargetAuraState = TargetAuraState;
        data->CastingTimeIndex = CastingTimeIndex;
        data->RecoveryTime = RecoveryTime;
        data->CategoryRecoveryTime = CategoryRecoveryTime;
        data->InterruptFlags = InterruptFlags;
        data->AuraInterruptFlags = AuraInterruptFlags;
        data->ChannelInterruptFlags = ChannelInterruptFlags;
        data->procFlags = procFlags;
        data->procChance = procChance;
        data->procCharges = procCharges;
        data->maxLevel = maxLevel;
        data->baseLevel = baseLevel;
        data->spellLevel = spellLevel;
        data->DurationIndex = DurationIndex;
        data->powerType = powerType;
        data->manaCost = manaCost;
        data->manaCostPerlevel = manaCostPerlevel;
        data->manaPerSecond = manaPerSecond;
        data->manaPerSecondPerLevel = manaPerSecondPerLevel;
        data->rangeIndex = rangeIndex;
        data->speed = speed;
        data->modalNextSpell = modalNextSpell;
        data->StackAmount = StackAmount;
        std::copy(std::begin(Totem), std::end(Totem), std::begin(data->Totem));
        std::copy(std::begin(Reagent), std::end(Reagent), std::begin(data->Reagent));
        std::copy(std::begin(ReagentCount), std::end(ReagentCount), std::begin(data->ReagentCount));
        data->EquippedItemClass = EquippedItemClass;
        data->EquippedItemSubClassMask = EquippedItemSubClassMask;
        data->EquippedItemInventoryTypeMask = 0;
        std::copy(std::begin(Effect), std::end(Effect), std::begin(data->Effect));
        std::copy(std::begin(EffectDieSides), std::end(EffectDieSides), std::begin(data->EffectDieSides));
        std::copy(std::begin(EffectBaseDice), std::end(EffectBaseDice), std::begin(data->EffectBaseDice));
        std::copy(std::begin(EffectDicePerLevel), std::end(EffectDicePerLevel), std::begin(data->EffectDicePerLevel));
        std::copy(std::begin(EffectRealPointsPerLevel), std::end(EffectRealPointsPerLevel), std::begin(data->EffectRealPointsPerLevel));
        std::copy(std::begin(EffectBasePoints), std::end(EffectBasePoints), std::begin(data->EffectBasePoints));
        std::copy(std::begin(EffectMechanic), std::end(EffectMechanic), std::begin(data->EffectMechanic));
        std::copy(std::begin(EffectImplicitTargetA), std::end(EffectImplicitTargetA), std::begin(data->EffectImplicitTargetA));
        std::copy(std::begin(EffectImplicitTargetB), std::end(EffectImplicitTargetB), std::begin(data->EffectImplicitTargetB));
        std::copy(std::begin(EffectRadiusIndex), std::end(EffectRadiusIndex), std::begin(data->EffectRadiusIndex));
        std::copy(std::begin(EffectApplyAuraName), std::end(EffectApplyAuraName), std::begin(data->EffectApplyAuraName));
        std::copy(std::begin(EffectAmplitude), std::end(EffectAmplitude), std::begin(data->EffectAmplitude));
        std::copy(std::begin(EffectMultipleValue), std::end(EffectMultipleValue), std::begin(data->EffectMultipleValue));
        std::copy(std::begin(EffectChainTarget), std::end(EffectChainTarget), std::begin(data->EffectChainTarget));
        std::copy(std::begin(EffectItemType), std::end(EffectItemType), std::begin(data->EffectItemType));
        std::copy(std::begin(EffectMiscValue), std::end(EffectMiscValue), std::begin(data->EffectMiscValue));
        std::copy(std::begin(EffectTriggerSpell), std::end(EffectTriggerSpell), std::begin(data->EffectTriggerSpell));
        std::copy(std::begin(EffectPointsPerComboPoint), std::end(EffectPointsPerComboPoint), std::begin(data->EffectPointsPerComboPoint));
        data->SpellVisual = SpellVisual;
        data->SpellVisual2 = SpellVisual2;
        data->SpellIconID = SpellIconID;
        data->activeIconID = activeIconID;
        data->spellPriority = spellPriority;
        std::copy(std::begin(SpellName), std::end(SpellName), std::begin(data->SpellName));
        data->SpellNameFlag = SpellNameFlag;
        std::copy(std::begin(Rank), std::end(Rank), std::begin(data->Rank));
        data->RankFlags = RankFlags;
        std::copy(std::begin(Description), std::end(Description), std::begin(data->Description));
        data->DescriptionFlags = DescriptionFlags;
        std::copy(std::begin(ToolTip), std::end(ToolTip), std::begin(data->ToolTip));
        data->ToolTipFlags = ToolTipFlags;
        data->ManaCostPercentage = ManaCostPercentage;
        data->StartRecoveryCategory = StartRecoveryCategory;
        data->StartRecoveryTime = StartRecoveryTime;
        data->MaxTargetLevel = MaxTargetLevel;
        data->SpellFamilyName = SpellFamilyName;
        data->SpellFamilyFlags = SpellFamilyFlags;
        data->MaxAffectedTargets = MaxAffectedTargets;
        data->DmgClass = DmgClass;
        data->PreventionType = PreventionType;
        data->StanceBarOrder = StanceBarOrder;
        std::copy(std::begin(DmgMultiplier), std::end(DmgMultiplier), std::begin(data->DmgMultiplier));
        data->MinFactionId = MinFactionId;
        data->MinReputation = MinReputation;
        data->RequiredAuraVision = RequiredAuraVision;
        return data;
    }
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
    char*     SpellName[MAX_DBC_LOCALE];                    // 117-124
    uint32    SpellNameFlag;                                // 125
    char*     Rank[MAX_DBC_LOCALE];                         // 126-133
    uint32    RankFlags;                                    // 134
    char*     Description[MAX_DBC_LOCALE];                  // 135-142
    uint32    DescriptionFlags;                             // 143
    char*     ToolTip[MAX_DBC_LOCALE];                      // 144-151
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

    SpellEntry5875* ToLatestStructure() const
    {
        SpellEntry5875* data = new SpellEntry5875();
        data->Id = Id;
        data->School = School;
        data->Category = Category;
        data->castUI = castUI;
        data->Dispel = Dispel;
        data->Mechanic = Mechanic;
        data->Attributes = Attributes;
        data->AttributesEx = AttributesEx;
        data->AttributesEx2 = AttributesEx2;
        data->AttributesEx3 = AttributesEx3;
        data->AttributesEx4 = 0;
        data->Stances = Stances;
        data->StancesNot = StancesNot;
        data->Targets = Targets;
        data->TargetCreatureType = TargetCreatureType;
        data->RequiresSpellFocus = RequiresSpellFocus;
        data->CasterAuraState = CasterAuraState;
        data->TargetAuraState = TargetAuraState;
        data->CastingTimeIndex = CastingTimeIndex;
        data->RecoveryTime = RecoveryTime;
        data->CategoryRecoveryTime = CategoryRecoveryTime;
        data->InterruptFlags = InterruptFlags;
        data->AuraInterruptFlags = AuraInterruptFlags;
        data->ChannelInterruptFlags = ChannelInterruptFlags;
        data->procFlags = procFlags;
        data->procChance = procChance;
        data->procCharges = procCharges;
        data->maxLevel = maxLevel;
        data->baseLevel = baseLevel;
        data->spellLevel = spellLevel;
        data->DurationIndex = DurationIndex;
        data->powerType = powerType;
        data->manaCost = manaCost;
        data->manaCostPerlevel = manaCostPerlevel;
        data->manaPerSecond = manaPerSecond;
        data->manaPerSecondPerLevel = manaPerSecondPerLevel;
        data->rangeIndex = rangeIndex;
        data->speed = speed;
        data->modalNextSpell = modalNextSpell;
        data->StackAmount = StackAmount;
        std::copy(std::begin(Totem), std::end(Totem), std::begin(data->Totem));
        std::copy(std::begin(Reagent), std::end(Reagent), std::begin(data->Reagent));
        std::copy(std::begin(ReagentCount), std::end(ReagentCount), std::begin(data->ReagentCount));
        data->EquippedItemClass = EquippedItemClass;
        data->EquippedItemSubClassMask = EquippedItemSubClassMask;
        data->EquippedItemInventoryTypeMask = 0;
        std::copy(std::begin(Effect), std::end(Effect), std::begin(data->Effect));
        std::copy(std::begin(EffectDieSides), std::end(EffectDieSides), std::begin(data->EffectDieSides));
        std::copy(std::begin(EffectBaseDice), std::end(EffectBaseDice), std::begin(data->EffectBaseDice));
        std::copy(std::begin(EffectDicePerLevel), std::end(EffectDicePerLevel), std::begin(data->EffectDicePerLevel));
        std::copy(std::begin(EffectRealPointsPerLevel), std::end(EffectRealPointsPerLevel), std::begin(data->EffectRealPointsPerLevel));
        std::copy(std::begin(EffectBasePoints), std::end(EffectBasePoints), std::begin(data->EffectBasePoints));
        std::copy(std::begin(EffectMechanic), std::end(EffectMechanic), std::begin(data->EffectMechanic));
        std::copy(std::begin(EffectImplicitTargetA), std::end(EffectImplicitTargetA), std::begin(data->EffectImplicitTargetA));
        std::copy(std::begin(EffectImplicitTargetB), std::end(EffectImplicitTargetB), std::begin(data->EffectImplicitTargetB));
        std::copy(std::begin(EffectRadiusIndex), std::end(EffectRadiusIndex), std::begin(data->EffectRadiusIndex));
        std::copy(std::begin(EffectApplyAuraName), std::end(EffectApplyAuraName), std::begin(data->EffectApplyAuraName));
        std::copy(std::begin(EffectAmplitude), std::end(EffectAmplitude), std::begin(data->EffectAmplitude));
        std::copy(std::begin(EffectMultipleValue), std::end(EffectMultipleValue), std::begin(data->EffectMultipleValue));
        std::copy(std::begin(EffectChainTarget), std::end(EffectChainTarget), std::begin(data->EffectChainTarget));
        std::copy(std::begin(EffectItemType), std::end(EffectItemType), std::begin(data->EffectItemType));
        std::copy(std::begin(EffectMiscValue), std::end(EffectMiscValue), std::begin(data->EffectMiscValue));
        std::copy(std::begin(EffectTriggerSpell), std::end(EffectTriggerSpell), std::begin(data->EffectTriggerSpell));
        std::copy(std::begin(EffectPointsPerComboPoint), std::end(EffectPointsPerComboPoint), std::begin(data->EffectPointsPerComboPoint));
        data->SpellVisual = SpellVisual;
        data->SpellVisual2 = SpellVisual2;
        data->SpellIconID = SpellIconID;
        data->activeIconID = activeIconID;
        data->spellPriority = spellPriority;
        std::copy(std::begin(SpellName), std::end(SpellName), std::begin(data->SpellName));
        data->SpellNameFlag = SpellNameFlag;
        std::copy(std::begin(Rank), std::end(Rank), std::begin(data->Rank));
        data->RankFlags = RankFlags;
        std::copy(std::begin(Description), std::end(Description), std::begin(data->Description));
        data->DescriptionFlags = DescriptionFlags;
        std::copy(std::begin(ToolTip), std::end(ToolTip), std::begin(data->ToolTip));
        data->ToolTipFlags = ToolTipFlags;
        data->ManaCostPercentage = ManaCostPercentage;
        data->StartRecoveryCategory = StartRecoveryCategory;
        data->StartRecoveryTime = StartRecoveryTime;
        data->MaxTargetLevel = MaxTargetLevel;
        data->SpellFamilyName = SpellFamilyName;
        data->SpellFamilyFlags = uint64(SpellFamilyFlags);
        data->MaxAffectedTargets = MaxAffectedTargets;
        data->DmgClass = DmgClass;
        data->PreventionType = PreventionType;
        data->StanceBarOrder = StanceBarOrder;
        std::copy(std::begin(DmgMultiplier), std::end(DmgMultiplier), std::begin(data->DmgMultiplier));
        data->MinFactionId = MinFactionId;
        data->MinReputation = MinReputation;
        data->RequiredAuraVision = RequiredAuraVision;
        return data;
    }
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
    char*     SpellName[MAX_DBC_LOCALE];                    // 117-124
    uint32    SpellNameFlag;                                // 125
    char*     Rank[MAX_DBC_LOCALE];                         // 126-133
    uint32    RankFlags;                                    // 134
    char*     Description[MAX_DBC_LOCALE];                  // 135-142
    uint32    DescriptionFlags;                             // 143
    char*     ToolTip[MAX_DBC_LOCALE];                      // 144-151
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

    SpellEntry5875* ToLatestStructure() const
    {
        SpellEntry5875* data = new SpellEntry5875();
        data->Id = Id;
        data->School = School;
        data->Category = Category;
        data->castUI = castUI;
        data->Dispel = Dispel;
        data->Mechanic = Mechanic;
        data->Attributes = Attributes;
        data->AttributesEx = AttributesEx;
        data->AttributesEx2 = AttributesEx2;
        data->AttributesEx3 = AttributesEx3;
        data->AttributesEx4 = 0;
        data->Stances = Stances;
        data->StancesNot = StancesNot;
        data->Targets = Targets;
        data->TargetCreatureType = TargetCreatureType;
        data->RequiresSpellFocus = RequiresSpellFocus;
        data->CasterAuraState = CasterAuraState;
        data->TargetAuraState = TargetAuraState;
        data->CastingTimeIndex = CastingTimeIndex;
        data->RecoveryTime = RecoveryTime;
        data->CategoryRecoveryTime = CategoryRecoveryTime;
        data->InterruptFlags = InterruptFlags;
        data->AuraInterruptFlags = AuraInterruptFlags;
        data->ChannelInterruptFlags = ChannelInterruptFlags;
        data->procFlags = procFlags;
        data->procChance = procChance;
        data->procCharges = procCharges;
        data->maxLevel = maxLevel;
        data->baseLevel = baseLevel;
        data->spellLevel = spellLevel;
        data->DurationIndex = DurationIndex;
        data->powerType = powerType;
        data->manaCost = manaCost;
        data->manaCostPerlevel = manaCostPerlevel;
        data->manaPerSecond = manaPerSecond;
        data->manaPerSecondPerLevel = manaPerSecondPerLevel;
        data->rangeIndex = rangeIndex;
        data->speed = speed;
        data->modalNextSpell = modalNextSpell;
        data->StackAmount = StackAmount;
        std::copy(std::begin(Totem), std::end(Totem), std::begin(data->Totem));
        std::copy(std::begin(Reagent), std::end(Reagent), std::begin(data->Reagent));
        std::copy(std::begin(ReagentCount), std::end(ReagentCount), std::begin(data->ReagentCount));
        data->EquippedItemClass = EquippedItemClass;
        data->EquippedItemSubClassMask = EquippedItemSubClassMask;
        data->EquippedItemInventoryTypeMask = 0;
        std::copy(std::begin(Effect), std::end(Effect), std::begin(data->Effect));
        std::copy(std::begin(EffectDieSides), std::end(EffectDieSides), std::begin(data->EffectDieSides));
        std::copy(std::begin(EffectBaseDice), std::end(EffectBaseDice), std::begin(data->EffectBaseDice));
        std::copy(std::begin(EffectDicePerLevel), std::end(EffectDicePerLevel), std::begin(data->EffectDicePerLevel));
        std::copy(std::begin(EffectRealPointsPerLevel), std::end(EffectRealPointsPerLevel), std::begin(data->EffectRealPointsPerLevel));
        std::copy(std::begin(EffectBasePoints), std::end(EffectBasePoints), std::begin(data->EffectBasePoints));
        std::copy(std::begin(EffectMechanic), std::end(EffectMechanic), std::begin(data->EffectMechanic));
        std::copy(std::begin(EffectImplicitTargetA), std::end(EffectImplicitTargetA), std::begin(data->EffectImplicitTargetA));
        std::copy(std::begin(EffectImplicitTargetB), std::end(EffectImplicitTargetB), std::begin(data->EffectImplicitTargetB));
        std::copy(std::begin(EffectRadiusIndex), std::end(EffectRadiusIndex), std::begin(data->EffectRadiusIndex));
        std::copy(std::begin(EffectApplyAuraName), std::end(EffectApplyAuraName), std::begin(data->EffectApplyAuraName));
        std::copy(std::begin(EffectAmplitude), std::end(EffectAmplitude), std::begin(data->EffectAmplitude));
        std::copy(std::begin(EffectMultipleValue), std::end(EffectMultipleValue), std::begin(data->EffectMultipleValue));
        std::copy(std::begin(EffectChainTarget), std::end(EffectChainTarget), std::begin(data->EffectChainTarget));
        std::copy(std::begin(EffectItemType), std::end(EffectItemType), std::begin(data->EffectItemType));
        std::copy(std::begin(EffectMiscValue), std::end(EffectMiscValue), std::begin(data->EffectMiscValue));
        std::copy(std::begin(EffectTriggerSpell), std::end(EffectTriggerSpell), std::begin(data->EffectTriggerSpell));
        std::copy(std::begin(EffectPointsPerComboPoint), std::end(EffectPointsPerComboPoint), std::begin(data->EffectPointsPerComboPoint));
        data->SpellVisual = SpellVisual;
        data->SpellVisual2 = SpellVisual2;
        data->SpellIconID = SpellIconID;
        data->activeIconID = activeIconID;
        data->spellPriority = spellPriority;
        std::copy(std::begin(SpellName), std::end(SpellName), std::begin(data->SpellName));
        data->SpellNameFlag = SpellNameFlag;
        std::copy(std::begin(Rank), std::end(Rank), std::begin(data->Rank));
        data->RankFlags = RankFlags;
        std::copy(std::begin(Description), std::end(Description), std::begin(data->Description));
        data->DescriptionFlags = DescriptionFlags;
        std::copy(std::begin(ToolTip), std::end(ToolTip), std::begin(data->ToolTip));
        data->ToolTipFlags = ToolTipFlags;
        data->ManaCostPercentage = ManaCostPercentage;
        data->StartRecoveryCategory = StartRecoveryCategory;
        data->StartRecoveryTime = StartRecoveryTime;
        data->MaxTargetLevel = MaxTargetLevel;
        data->SpellFamilyName = SpellFamilyName;
        data->SpellFamilyFlags = uint64(SpellFamilyFlags);
        data->MaxAffectedTargets = MaxAffectedTargets;
        data->DmgClass = DmgClass;
        data->PreventionType = PreventionType;
        data->StanceBarOrder = StanceBarOrder;
        std::copy(std::begin(DmgMultiplier), std::end(DmgMultiplier), std::begin(data->DmgMultiplier));
        data->MinFactionId = 0;
        data->MinReputation = 0;
        data->RequiredAuraVision = 0;
        return data;
    }
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
    char*     SpellName[MAX_DBC_LOCALE];                    // 114-121
    uint32    SpellNameFlag;                                // 122
    char*     Rank[MAX_DBC_LOCALE];                         // 123-130
    uint32    RankFlags;                                    // 131
    char*     Description[MAX_DBC_LOCALE];                  // 132-139
    uint32    DescriptionFlags;                             // 140
    char*     ToolTip[MAX_DBC_LOCALE];                      // 141-148
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

    SpellEntry5875* ToLatestStructure() const
    {
        SpellEntry5875* data = new SpellEntry5875();
        data->Id = Id;
        data->School = School;
        data->Category = Category;
        data->castUI = castUI;
        data->Dispel = Dispel;
        data->Mechanic = Mechanic;
        data->Attributes = Attributes;
        data->AttributesEx = AttributesEx;
        data->AttributesEx2 = AttributesEx2;
        data->AttributesEx3 = AttributesEx3;
        data->AttributesEx4 = 0;
        data->Stances = Stances;
        data->StancesNot = StancesNot;
        data->Targets = Targets;
        data->TargetCreatureType = TargetCreatureType;
        data->RequiresSpellFocus = RequiresSpellFocus;
        data->CasterAuraState = CasterAuraState;
        data->TargetAuraState = TargetAuraState;
        data->CastingTimeIndex = CastingTimeIndex;
        data->RecoveryTime = RecoveryTime;
        data->CategoryRecoveryTime = CategoryRecoveryTime;
        data->InterruptFlags = InterruptFlags;
        data->AuraInterruptFlags = AuraInterruptFlags;
        data->ChannelInterruptFlags = ChannelInterruptFlags;
        data->procFlags = procFlags;
        data->procChance = procChance;
        data->procCharges = procCharges;
        data->maxLevel = maxLevel;
        data->baseLevel = baseLevel;
        data->spellLevel = spellLevel;
        data->DurationIndex = DurationIndex;
        data->powerType = powerType;
        data->manaCost = manaCost;
        data->manaCostPerlevel = manaCostPerlevel;
        data->manaPerSecond = manaPerSecond;
        data->manaPerSecondPerLevel = manaPerSecondPerLevel;
        data->rangeIndex = rangeIndex;
        data->speed = speed;
        data->modalNextSpell = modalNextSpell;
        data->StackAmount = StackAmount;
        std::copy(std::begin(Totem), std::end(Totem), std::begin(data->Totem));
        std::copy(std::begin(Reagent), std::end(Reagent), std::begin(data->Reagent));
        std::copy(std::begin(ReagentCount), std::end(ReagentCount), std::begin(data->ReagentCount));
        data->EquippedItemClass = EquippedItemClass;
        data->EquippedItemSubClassMask = EquippedItemSubClassMask;
        data->EquippedItemInventoryTypeMask = 0;
        std::copy(std::begin(Effect), std::end(Effect), std::begin(data->Effect));
        std::copy(std::begin(EffectDieSides), std::end(EffectDieSides), std::begin(data->EffectDieSides));
        std::copy(std::begin(EffectBaseDice), std::end(EffectBaseDice), std::begin(data->EffectBaseDice));
        std::copy(std::begin(EffectDicePerLevel), std::end(EffectDicePerLevel), std::begin(data->EffectDicePerLevel));
        std::copy(std::begin(EffectRealPointsPerLevel), std::end(EffectRealPointsPerLevel), std::begin(data->EffectRealPointsPerLevel));
        std::copy(std::begin(EffectBasePoints), std::end(EffectBasePoints), std::begin(data->EffectBasePoints));
        std::fill(std::begin(data->EffectMechanic), std::end(data->EffectMechanic), 0);
        std::copy(std::begin(EffectImplicitTargetA), std::end(EffectImplicitTargetA), std::begin(data->EffectImplicitTargetA));
        std::copy(std::begin(EffectImplicitTargetB), std::end(EffectImplicitTargetB), std::begin(data->EffectImplicitTargetB));
        std::copy(std::begin(EffectRadiusIndex), std::end(EffectRadiusIndex), std::begin(data->EffectRadiusIndex));
        std::copy(std::begin(EffectApplyAuraName), std::end(EffectApplyAuraName), std::begin(data->EffectApplyAuraName));
        std::copy(std::begin(EffectAmplitude), std::end(EffectAmplitude), std::begin(data->EffectAmplitude));
        std::copy(std::begin(EffectMultipleValue), std::end(EffectMultipleValue), std::begin(data->EffectMultipleValue));
        std::copy(std::begin(EffectChainTarget), std::end(EffectChainTarget), std::begin(data->EffectChainTarget));
        std::copy(std::begin(EffectItemType), std::end(EffectItemType), std::begin(data->EffectItemType));
        std::copy(std::begin(EffectMiscValue), std::end(EffectMiscValue), std::begin(data->EffectMiscValue));
        std::copy(std::begin(EffectTriggerSpell), std::end(EffectTriggerSpell), std::begin(data->EffectTriggerSpell));
        std::copy(std::begin(EffectPointsPerComboPoint), std::end(EffectPointsPerComboPoint), std::begin(data->EffectPointsPerComboPoint));
        data->SpellVisual = SpellVisual;
        data->SpellVisual2 = SpellVisual2;
        data->SpellIconID = SpellIconID;
        data->activeIconID = activeIconID;
        data->spellPriority = spellPriority;
        std::copy(std::begin(SpellName), std::end(SpellName), std::begin(data->SpellName));
        data->SpellNameFlag = SpellNameFlag;
        std::copy(std::begin(Rank), std::end(Rank), std::begin(data->Rank));
        data->RankFlags = RankFlags;
        std::copy(std::begin(Description), std::end(Description), std::begin(data->Description));
        data->DescriptionFlags = DescriptionFlags;
        std::copy(std::begin(ToolTip), std::end(ToolTip), std::begin(data->ToolTip));
        data->ToolTipFlags = ToolTipFlags;
        data->ManaCostPercentage = ManaCostPercentage;
        data->StartRecoveryCategory = StartRecoveryCategory;
        data->StartRecoveryTime = StartRecoveryTime;
        data->MaxTargetLevel = MaxTargetLevel;
        data->SpellFamilyName = SpellFamilyName;
        data->SpellFamilyFlags = uint64(SpellFamilyFlags);
        data->MaxAffectedTargets = MaxAffectedTargets;
        data->DmgClass = DmgClass;
        data->PreventionType = PreventionType;
        data->StanceBarOrder = StanceBarOrder;
        std::copy(std::begin(DmgMultiplier), std::end(DmgMultiplier), std::begin(data->DmgMultiplier));
        data->MinFactionId = 0;
        data->MinReputation = 0;
        data->RequiredAuraVision = 0;
        return data;
    }
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
    char*     SpellName[MAX_DBC_LOCALE];                    // 113-120
    uint32    SpellNameFlag;                                // 121
    char*     Rank[MAX_DBC_LOCALE];                         // 122-129
    uint32    RankFlags;                                    // 130
    char*     Description[MAX_DBC_LOCALE];                  // 131-138
    uint32    DescriptionFlags;                             // 139
    char*     ToolTip[MAX_DBC_LOCALE];                      // 140-147
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

    SpellEntry5875* ToLatestStructure() const
    {
        SpellEntry5875* data = new SpellEntry5875();
        data->Id = Id;
        data->School = School;
        data->Category = Category;
        data->castUI = castUI;
        data->Dispel = Dispel;
        data->Mechanic = Mechanic;
        data->Attributes = Attributes;
        data->AttributesEx = AttributesEx;
        data->AttributesEx2 = AttributesEx2;
        data->AttributesEx3 = AttributesEx3;
        data->AttributesEx4 = 0;
        data->Stances = Stances;
        data->StancesNot = 0;
        data->Targets = Targets;
        data->TargetCreatureType = TargetCreatureType;
        data->RequiresSpellFocus = RequiresSpellFocus;
        data->CasterAuraState = CasterAuraState;
        data->TargetAuraState = TargetAuraState;
        data->CastingTimeIndex = CastingTimeIndex;
        data->RecoveryTime = RecoveryTime;
        data->CategoryRecoveryTime = CategoryRecoveryTime;
        data->InterruptFlags = InterruptFlags;
        data->AuraInterruptFlags = AuraInterruptFlags;
        data->ChannelInterruptFlags = ChannelInterruptFlags;
        data->procFlags = procFlags;
        data->procChance = procChance;
        data->procCharges = procCharges;
        data->maxLevel = maxLevel;
        data->baseLevel = baseLevel;
        data->spellLevel = spellLevel;
        data->DurationIndex = DurationIndex;
        data->powerType = powerType;
        data->manaCost = manaCost;
        data->manaCostPerlevel = manaCostPerlevel;
        data->manaPerSecond = manaPerSecond;
        data->manaPerSecondPerLevel = manaPerSecondPerLevel;
        data->rangeIndex = rangeIndex;
        data->speed = speed;
        data->modalNextSpell = modalNextSpell;
        data->StackAmount = StackAmount;
        std::copy(std::begin(Totem), std::end(Totem), std::begin(data->Totem));
        std::copy(std::begin(Reagent), std::end(Reagent), std::begin(data->Reagent));
        std::copy(std::begin(ReagentCount), std::end(ReagentCount), std::begin(data->ReagentCount));
        data->EquippedItemClass = EquippedItemClass;
        data->EquippedItemSubClassMask = EquippedItemSubClassMask;
        data->EquippedItemInventoryTypeMask = 0;
        std::copy(std::begin(Effect), std::end(Effect), std::begin(data->Effect));
        std::copy(std::begin(EffectDieSides), std::end(EffectDieSides), std::begin(data->EffectDieSides));
        std::copy(std::begin(EffectBaseDice), std::end(EffectBaseDice), std::begin(data->EffectBaseDice));
        std::copy(std::begin(EffectDicePerLevel), std::end(EffectDicePerLevel), std::begin(data->EffectDicePerLevel));
        std::copy(std::begin(EffectRealPointsPerLevel), std::end(EffectRealPointsPerLevel), std::begin(data->EffectRealPointsPerLevel));
        std::copy(std::begin(EffectBasePoints), std::end(EffectBasePoints), std::begin(data->EffectBasePoints));
        std::fill(std::begin(data->EffectMechanic), std::end(data->EffectMechanic), 0);
        std::copy(std::begin(EffectImplicitTargetA), std::end(EffectImplicitTargetA), std::begin(data->EffectImplicitTargetA));
        std::copy(std::begin(EffectImplicitTargetB), std::end(EffectImplicitTargetB), std::begin(data->EffectImplicitTargetB));
        std::copy(std::begin(EffectRadiusIndex), std::end(EffectRadiusIndex), std::begin(data->EffectRadiusIndex));
        std::copy(std::begin(EffectApplyAuraName), std::end(EffectApplyAuraName), std::begin(data->EffectApplyAuraName));
        std::copy(std::begin(EffectAmplitude), std::end(EffectAmplitude), std::begin(data->EffectAmplitude));
        std::copy(std::begin(EffectMultipleValue), std::end(EffectMultipleValue), std::begin(data->EffectMultipleValue));
        std::copy(std::begin(EffectChainTarget), std::end(EffectChainTarget), std::begin(data->EffectChainTarget));
        std::copy(std::begin(EffectItemType), std::end(EffectItemType), std::begin(data->EffectItemType));
        std::copy(std::begin(EffectMiscValue), std::end(EffectMiscValue), std::begin(data->EffectMiscValue));
        std::copy(std::begin(EffectTriggerSpell), std::end(EffectTriggerSpell), std::begin(data->EffectTriggerSpell));
        std::copy(std::begin(EffectPointsPerComboPoint), std::end(EffectPointsPerComboPoint), std::begin(data->EffectPointsPerComboPoint));
        data->SpellVisual = SpellVisual;
        data->SpellVisual2 = SpellVisual2;
        data->SpellIconID = SpellIconID;
        data->activeIconID = activeIconID;
        data->spellPriority = spellPriority;
        std::copy(std::begin(SpellName), std::end(SpellName), std::begin(data->SpellName));
        data->SpellNameFlag = SpellNameFlag;
        std::copy(std::begin(Rank), std::end(Rank), std::begin(data->Rank));
        data->RankFlags = RankFlags;
        std::copy(std::begin(Description), std::end(Description), std::begin(data->Description));
        data->DescriptionFlags = DescriptionFlags;
        std::copy(std::begin(ToolTip), std::end(ToolTip), std::begin(data->ToolTip));
        data->ToolTipFlags = ToolTipFlags;
        data->ManaCostPercentage = ManaCostPercentage;
        data->StartRecoveryCategory = StartRecoveryCategory;
        data->StartRecoveryTime = StartRecoveryTime;
        data->MaxTargetLevel = MaxTargetLevel;
        data->SpellFamilyName = SpellFamilyName;
        data->SpellFamilyFlags = uint64(SpellFamilyFlags);
        data->MaxAffectedTargets = MaxAffectedTargets;
        data->DmgClass = DmgClass;
        data->PreventionType = PreventionType;
        data->StanceBarOrder = StanceBarOrder;
        std::copy(std::begin(DmgMultiplier), std::end(DmgMultiplier), std::begin(data->DmgMultiplier));
        data->MinFactionId = 0;
        data->MinReputation = 0;
        data->RequiredAuraVision = 0;
        return data;
    }
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
    char*     SpellName[MAX_DBC_LOCALE];                    // 112-119
    uint32    SpellNameFlag;                                // 120
    char*     Rank[MAX_DBC_LOCALE];                         // 121-128
    uint32    RankFlags;                                    // 129
    char*     Description[MAX_DBC_LOCALE];                  // 130-137
    uint32    DescriptionFlags;                             // 138
    char*     ToolTip[MAX_DBC_LOCALE];                      // 139-146
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

    SpellEntry5875* ToLatestStructure() const
    {
        SpellEntry5875* data = new SpellEntry5875();
        data->Id = Id;
        data->School = School;
        data->Category = Category;
        data->castUI = castUI;
        data->Dispel = Dispel;
        data->Mechanic = 0;
        data->Attributes = Attributes;
        data->AttributesEx = AttributesEx;
        data->AttributesEx2 = AttributesEx2;
        data->AttributesEx3 = AttributesEx3;
        data->AttributesEx4 = 0;
        data->Stances = Stances;
        data->StancesNot = 0;
        data->Targets = Targets;
        data->TargetCreatureType = TargetCreatureType;
        data->RequiresSpellFocus = RequiresSpellFocus;
        data->CasterAuraState = CasterAuraState;
        data->TargetAuraState = TargetAuraState;
        data->CastingTimeIndex = CastingTimeIndex;
        data->RecoveryTime = RecoveryTime;
        data->CategoryRecoveryTime = CategoryRecoveryTime;
        data->InterruptFlags = InterruptFlags;
        data->AuraInterruptFlags = AuraInterruptFlags;
        data->ChannelInterruptFlags = ChannelInterruptFlags;
        data->procFlags = procFlags;
        data->procChance = procChance;
        data->procCharges = procCharges;
        data->maxLevel = maxLevel;
        data->baseLevel = baseLevel;
        data->spellLevel = spellLevel;
        data->DurationIndex = DurationIndex;
        data->powerType = powerType;
        data->manaCost = manaCost;
        data->manaCostPerlevel = manaCostPerlevel;
        data->manaPerSecond = manaPerSecond;
        data->manaPerSecondPerLevel = manaPerSecondPerLevel;
        data->rangeIndex = rangeIndex;
        data->speed = speed;
        data->modalNextSpell = modalNextSpell;
        data->StackAmount = StackAmount;
        std::copy(std::begin(Totem), std::end(Totem), std::begin(data->Totem));
        std::copy(std::begin(Reagent), std::end(Reagent), std::begin(data->Reagent));
        std::copy(std::begin(ReagentCount), std::end(ReagentCount), std::begin(data->ReagentCount));
        data->EquippedItemClass = EquippedItemClass;
        data->EquippedItemSubClassMask = EquippedItemSubClassMask;
        data->EquippedItemInventoryTypeMask = 0;
        std::copy(std::begin(Effect), std::end(Effect), std::begin(data->Effect));
        std::copy(std::begin(EffectDieSides), std::end(EffectDieSides), std::begin(data->EffectDieSides));
        std::copy(std::begin(EffectBaseDice), std::end(EffectBaseDice), std::begin(data->EffectBaseDice));
        std::copy(std::begin(EffectDicePerLevel), std::end(EffectDicePerLevel), std::begin(data->EffectDicePerLevel));
        std::copy(std::begin(EffectRealPointsPerLevel), std::end(EffectRealPointsPerLevel), std::begin(data->EffectRealPointsPerLevel));
        std::copy(std::begin(EffectBasePoints), std::end(EffectBasePoints), std::begin(data->EffectBasePoints));
        std::fill(std::begin(data->EffectMechanic), std::end(data->EffectMechanic), 0);
        std::copy(std::begin(EffectImplicitTargetA), std::end(EffectImplicitTargetA), std::begin(data->EffectImplicitTargetA));
        std::copy(std::begin(EffectImplicitTargetB), std::end(EffectImplicitTargetB), std::begin(data->EffectImplicitTargetB));
        std::copy(std::begin(EffectRadiusIndex), std::end(EffectRadiusIndex), std::begin(data->EffectRadiusIndex));
        std::copy(std::begin(EffectApplyAuraName), std::end(EffectApplyAuraName), std::begin(data->EffectApplyAuraName));
        std::copy(std::begin(EffectAmplitude), std::end(EffectAmplitude), std::begin(data->EffectAmplitude));
        std::copy(std::begin(EffectMultipleValue), std::end(EffectMultipleValue), std::begin(data->EffectMultipleValue));
        std::copy(std::begin(EffectChainTarget), std::end(EffectChainTarget), std::begin(data->EffectChainTarget));
        std::copy(std::begin(EffectItemType), std::end(EffectItemType), std::begin(data->EffectItemType));
        std::copy(std::begin(EffectMiscValue), std::end(EffectMiscValue), std::begin(data->EffectMiscValue));
        std::copy(std::begin(EffectTriggerSpell), std::end(EffectTriggerSpell), std::begin(data->EffectTriggerSpell));
        std::copy(std::begin(EffectPointsPerComboPoint), std::end(EffectPointsPerComboPoint), std::begin(data->EffectPointsPerComboPoint));
        data->SpellVisual = SpellVisual;
        data->SpellVisual2 = SpellVisual2;
        data->SpellIconID = SpellIconID;
        data->activeIconID = activeIconID;
        data->spellPriority = spellPriority;
        std::copy(std::begin(SpellName), std::end(SpellName), std::begin(data->SpellName));
        data->SpellNameFlag = SpellNameFlag;
        std::copy(std::begin(Rank), std::end(Rank), std::begin(data->Rank));
        data->RankFlags = RankFlags;
        std::copy(std::begin(Description), std::end(Description), std::begin(data->Description));
        data->DescriptionFlags = DescriptionFlags;
        std::copy(std::begin(ToolTip), std::end(ToolTip), std::begin(data->ToolTip));
        data->ToolTipFlags = ToolTipFlags;
        data->ManaCostPercentage = ManaCostPercentage;
        data->StartRecoveryCategory = StartRecoveryCategory;
        data->StartRecoveryTime = StartRecoveryTime;
        data->MaxTargetLevel = MaxTargetLevel;
        data->SpellFamilyName = SpellFamilyName;
        data->SpellFamilyFlags = uint64(SpellFamilyFlags);
        data->MaxAffectedTargets = MaxAffectedTargets;
        data->DmgClass = DmgClass;
        data->PreventionType = PreventionType;
        data->StanceBarOrder = StanceBarOrder;
        std::copy(std::begin(DmgMultiplier), std::end(DmgMultiplier), std::begin(data->DmgMultiplier));
        data->MinFactionId = 0;
        data->MinReputation = 0;
        data->RequiredAuraVision = 0;
        return data;
    }
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
    char*       name[MAX_DBC_LOCALE];                       // 19-26    m_name_lang
                                                            // 27 string flags
    char* description[MAX_DBC_LOCALE];                      // 28-35    m_description_lang

    FactionEntry5875* ToLatestStructure() const
    {
        FactionEntry5875* data = new FactionEntry5875();
        data->Id = Id;
        data->reputationListID = reputationListID;
        std::copy(std::begin(BaseRepRaceMask), std::end(BaseRepRaceMask), std::begin(data->BaseRepRaceMask));
        std::copy(std::begin(BaseRepClassMask), std::end(BaseRepClassMask), std::begin(data->BaseRepClassMask));
        std::copy(std::begin(BaseRepValue), std::end(BaseRepValue), std::begin(data->BaseRepValue));
        std::copy(std::begin(ReputationFlags), std::end(ReputationFlags), std::begin(data->ReputationFlags));
        data->team = team;
        CopyStringArrays(name, data->name, MAX_DBC_LOCALE);
        CopyStringArrays(description, data->description, MAX_DBC_LOCALE);
        return data;
    }

    bool operator==(FactionEntry5875 const& other) const
    {
        if (other.Id != Id)
            return false;
        if (other.reputationListID != reputationListID)
            return false;
        if (other.team != team)
            return false;

        if (!std::equal(std::begin(BaseRepRaceMask), std::end(BaseRepRaceMask), std::begin(other.BaseRepRaceMask)))
            return false;
        if (!std::equal(std::begin(BaseRepClassMask), std::end(BaseRepClassMask), std::begin(other.BaseRepClassMask)))
            return false;
        if (!std::equal(std::begin(BaseRepValue), std::end(BaseRepValue), std::begin(other.BaseRepValue)))
            return false;
        if (!std::equal(std::begin(ReputationFlags), std::end(ReputationFlags), std::begin(other.ReputationFlags)))
            return false;

        if (!CompareStringArrays(other.name, name, MAX_DBC_LOCALE))
            return false;
        if (!CompareStringArrays(other.description, description, MAX_DBC_LOCALE))
            return false;

        return true;
    }

    bool operator!=(FactionEntry5875 const& other) const
    {
        return !(other == *this);
    }

    void WriteToSqlFile(std::ofstream& myfile, uint16 build) const
    {
        myfile << "(";
        myfile << Id << ", "; // 1
        myfile << build << ", ";
        myfile << reputationListID << ", ";// 2
        myfile << BaseRepRaceMask[0] << ", "; // 3
        myfile << BaseRepRaceMask[1] << ", "; // 4
        myfile << BaseRepRaceMask[2] << ", "; // 5
        myfile << BaseRepRaceMask[3] << ", "; // 6
        myfile << BaseRepClassMask[0] << ", "; // 7
        myfile << BaseRepClassMask[1] << ", "; // 8
        myfile << BaseRepClassMask[2] << ", "; // 9
        myfile << BaseRepClassMask[3] << ", "; // 10
        myfile << BaseRepValue[0] << ", "; // 11
        myfile << BaseRepValue[1] << ", "; // 12
        myfile << BaseRepValue[2] << ", "; // 13
        myfile << BaseRepValue[3] << ", "; // 14
        myfile << ReputationFlags[0] << ", "; // 15
        myfile << ReputationFlags[1] << ", "; // 16
        myfile << ReputationFlags[2] << ", "; // 17
        myfile << ReputationFlags[3] << ", "; // 18
        myfile << team << ", "; // 19
        myfile << "'" << EscapeString(name[0]) << "', "; // 20
        myfile << "'" << EscapeString(name[1]) << "', "; // 21
        myfile << "'" << EscapeString(name[2]) << "', "; // 22
        myfile << "'" << EscapeString(name[3]) << "', "; // 23
        myfile << "'" << EscapeString(name[4]) << "', "; // 24
        myfile << "'" << EscapeString(name[5]) << "', "; // 25
        myfile << "'" << EscapeString(name[6]) << "', "; // 26
        myfile << "'" << EscapeString(name[7]) << "', "; // 27
        myfile << "'" << EscapeString(description[0]) << "', "; // 28
        myfile << "'" << EscapeString(description[1]) << "', "; // 29
        myfile << "'" << EscapeString(description[2]) << "', "; // 30
        myfile << "'" << EscapeString(description[3]) << "', "; // 31
        myfile << "'" << EscapeString(description[4]) << "', "; // 32
        myfile << "'" << EscapeString(description[5]) << "', "; // 33
        myfile << "'" << EscapeString(description[6]) << "', "; // 34
        myfile << "'" << EscapeString(description[7]) << "')"; // 35
    }
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
    char*       name[MAX_DBC_LOCALE];                       // 19-26    m_name_lang
                                                            // 27 string flags

    FactionEntry5875* ToLatestStructure() const
    {
        FactionEntry5875* data = new FactionEntry5875();
        data->Id = Id;
        data->reputationListID = reputationListID;
        std::copy(std::begin(BaseRepRaceMask), std::end(BaseRepRaceMask), std::begin(data->BaseRepRaceMask));
        std::copy(std::begin(BaseRepClassMask), std::end(BaseRepClassMask), std::begin(data->BaseRepClassMask));
        std::copy(std::begin(BaseRepValue), std::end(BaseRepValue), std::begin(data->BaseRepValue));
        std::copy(std::begin(ReputationFlags), std::end(ReputationFlags), std::begin(data->ReputationFlags));
        data->team = team;
        CopyStringArrays(name, data->name, MAX_DBC_LOCALE);
        std::fill(std::begin(data->description), std::end(data->description), (char*)"");
        return data;
    }
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

    FactionTemplateEntry5875* ToLatestStructure() const
    {
        FactionTemplateEntry5875* data = new FactionTemplateEntry5875();
        data->ID = ID;
        data->faction = faction;
        data->factionFlags = factionFlags;
        data->ourMask = ourMask;
        data->friendlyMask = friendlyMask;
        data->hostileMask = hostileMask;
        std::copy(std::begin(enemyFaction), std::end(enemyFaction), std::begin(data->enemyFaction));
        std::copy(std::begin(friendFaction), std::end(friendFaction), std::begin(data->friendFaction));
        return data;
    }

    bool operator==(FactionTemplateEntry5875 const& other) const
    {
        if (other.ID != ID)
            return false;
        if (other.faction != faction)
            return false;
        if (other.factionFlags != factionFlags)
            return false;
        if (other.ourMask != ourMask)
            return false;
        if (other.friendlyMask != friendlyMask)
            return false;
        if (other.hostileMask != hostileMask)
            return false;

        if (!std::equal(std::begin(enemyFaction), std::end(enemyFaction), std::begin(other.enemyFaction)))
            return false;
        if (!std::equal(std::begin(friendFaction), std::end(friendFaction), std::begin(other.friendFaction)))
            return false;

        return true;
    }

    bool operator!=(FactionTemplateEntry5875 const& other) const
    {
        return !(other == *this);
    }

    void WriteToSqlFile(std::ofstream& myfile, uint16 build) const
    {
        myfile << "(";
        myfile << ID << ", "; // 1
        myfile << build << ", ";
        myfile << faction << ", ";// 2
        myfile << factionFlags << ", "; // 3
        myfile << ourMask << ", "; // 4
        myfile << friendlyMask << ", "; // 5
        myfile << hostileMask << ", "; // 6
        myfile << enemyFaction[0] << ", "; // 7
        myfile << enemyFaction[1] << ", "; // 8
        myfile << enemyFaction[2] << ", "; // 9
        myfile << enemyFaction[3] << ", "; // 10
        myfile << friendFaction[0] << ", "; // 11
        myfile << friendFaction[1] << ", "; // 12
        myfile << friendFaction[2] << ", "; // 13
        myfile << friendFaction[3] << ")"; // 14
    }
};

struct TaxiNodesEntry5875
{
    uint32    ID;                                           // 0        m_ID
    uint32    map_id;                                       // 1        m_ContinentID
    float     x;                                            // 2        m_x
    float     y;                                            // 3        m_y
    float     z;                                            // 4        m_z
    char*     name[MAX_DBC_LOCALE];                         // 5-12     m_Name_lang
                                                            // 13 string flags
    uint32    MountCreatureID[2];                           // 14-15    m_MountCreatureID[2] horde[14]-alliance[15]

    TaxiNodesEntry5875* ToLatestStructure() const
    {
        TaxiNodesEntry5875* data = new TaxiNodesEntry5875();
        data->ID = ID;
        data->map_id = map_id;
        data->x = x;
        data->y = y;
        data->z = z;
        CopyStringArrays(name, data->name, MAX_DBC_LOCALE);
        std::copy(std::begin(MountCreatureID), std::end(MountCreatureID), std::begin(data->MountCreatureID));
        return data;
    }

    bool operator==(TaxiNodesEntry5875 const& other) const
    {
        if (other.ID != ID)
            return false;
        if (other.map_id != map_id)
            return false;
        if (other.x != x)
            return false;
        if (other.y != y)
            return false;
        if (other.z != z)
            return false;

        if (!CompareStringArrays(other.name, name, MAX_DBC_LOCALE))
            return false;

        if (!std::equal(std::begin(MountCreatureID), std::end(MountCreatureID), std::begin(other.MountCreatureID)))
            return false;

        return true;
    }

    bool operator!=(TaxiNodesEntry5875 const& other) const
    {
        return !(other == *this);
    }

    void WriteToSqlFile(std::ofstream& myfile, uint16 build) const
    {
        myfile << "(";
        myfile << ID << ", ";
        myfile << build << ", ";
        myfile << map_id << ", ";
        myfile << x << ", ";
        myfile << y << ", ";
        myfile << z << ", '";
        myfile << EscapeString(name[0]) << "', '";
        myfile << EscapeString(name[1]) << "', '";
        myfile << EscapeString(name[2]) << "', '";
        myfile << EscapeString(name[3]) << "', '";
        myfile << EscapeString(name[4]) << "', '";
        myfile << EscapeString(name[5]) << "', '";
        myfile << EscapeString(name[6]) << "', '";
        myfile << EscapeString(name[7]) << "', ";
        myfile << MountCreatureID[0] << ", ";
        myfile << MountCreatureID[1] << ")";
    }
};

struct TaxiNodesEntry5302
{
    uint32    ID;                                           // 0        m_ID
    uint32    map_id;                                       // 1        m_ContinentID
    float     x;                                            // 2        m_x
    float     y;                                            // 3        m_y
    float     z;                                            // 4        m_z
    char*     name[MAX_DBC_LOCALE];                         // 5-12     m_Name_lang
                                                            // 13 string flags

    TaxiNodesEntry5875* ToLatestStructure() const
    {
        TaxiNodesEntry5875* data = new TaxiNodesEntry5875();
        data->ID = ID;
        data->map_id = map_id;
        data->x = x;
        data->y = y;
        data->z = z;
        CopyStringArrays(name, data->name, MAX_DBC_LOCALE);
        std::fill(std::begin(data->MountCreatureID), std::end(data->MountCreatureID), 0);
        return data;
    }
};

struct SkillLineEntry5875
{
    uint32    id;                                           // 0        m_ID
    int32     categoryId;                                   // 1        m_categoryID
    uint32    skillCostID;                                  // 2        m_skillCostsID
    char*     name[MAX_DBC_LOCALE];                         // 3-10     m_displayName_lang
                                                            // 11 string flags
    char*     description[MAX_DBC_LOCALE];                  // 12-19    m_description_lang
                                                            // 20 string flags
    uint32    spellIcon;                                    // 21       m_spellIconID

    SkillLineEntry5875* ToLatestStructure() const
    {
        SkillLineEntry5875* data = new SkillLineEntry5875();
        data->id = id;
        data->categoryId = categoryId;
        data->skillCostID = skillCostID;
        data->spellIcon = spellIcon;

        CopyStringArrays(name, data->name, MAX_DBC_LOCALE);
        CopyStringArrays(description, data->description, MAX_DBC_LOCALE);

        return data;
    }

    bool operator==(SkillLineEntry5875 const& other) const
    {
        if (other.id != id)
            return false;
        if (other.categoryId != categoryId)
            return false;
        if (other.skillCostID != skillCostID)
            return false;
        if (other.spellIcon != spellIcon)
            return false;

        if (!CompareStringArrays(other.name, name, MAX_DBC_LOCALE))
            return false;
        if (!CompareStringArrays(other.description, description, MAX_DBC_LOCALE))
            return false;

        return true;
    }

    bool operator!=(SkillLineEntry5875 const& other) const
    {
        return !(other == *this);
    }

    void WriteToSqlFile(std::ofstream& myfile, uint16 build) const
    {
        myfile << "(";
        myfile << id << ", ";
        myfile << build << ", ";
        myfile << categoryId << ", ";
        myfile << skillCostID << ", '";
        myfile << EscapeString(name[0]) << "', '";
        myfile << EscapeString(name[1]) << "', '";
        myfile << EscapeString(name[2]) << "', '";
        myfile << EscapeString(name[3]) << "', '";
        myfile << EscapeString(name[4]) << "', '";
        myfile << EscapeString(name[5]) << "', '";
        myfile << EscapeString(name[6]) << "', '";
        myfile << EscapeString(name[7]) << "', '";
        myfile << EscapeString(description[0]) << "', '";
        myfile << EscapeString(description[1]) << "', '";
        myfile << EscapeString(description[2]) << "', '";
        myfile << EscapeString(description[3]) << "', '";
        myfile << EscapeString(description[4]) << "', '";
        myfile << EscapeString(description[5]) << "', '";
        myfile << EscapeString(description[6]) << "', '";
        myfile << EscapeString(description[7]) << "', ";
        myfile << spellIcon << ")";
    }

    void WriteToHotfixCsvFile(std::ofstream& myfile) const
    {
        myfile << "\"" << name[0] << "\",";        // DisplayName_lang
        myfile << "\"\",";                         // AlternateVerb_lang
        myfile << "\"" << description[0] << "\","; // Description_lang
        myfile << "\"\",";                         // HordeDisplayName_lang
        myfile << "\"\",";                         // NeutralDisplayName
        myfile << "\"" << id << "\",";             // ID
        myfile << "\"" << categoryId << "\",";     // CategoryID
        myfile << "\"" << 0 << "\",";              // SpellIconFileID
        myfile << "\"" << 0 << "\",";              // CanLink
        myfile << "\"" << 0 << "\",";              // ParentSkillLineID
        myfile << "\"" << 0 << "\",";              // ParentTierIndex
        myfile << "\"" << 0 << "\",";              // Flags
        myfile << "\"" << 0 << "\"";                // SpellBookSpellID
    }
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

    SkillLineAbilityEntry5875* ToLatestStructure() const
    {
        SkillLineAbilityEntry5875* data = new SkillLineAbilityEntry5875();
        data->id = id;
        data->skillId = skillId;
        data->spellId = spellId;
        data->racemask = racemask;
        data->classmask = classmask;
        data->req_skill_value = req_skill_value;
        data->forward_spellid = forward_spellid;
        data->learnOnGetSkill = learnOnGetSkill;
        data->max_value = max_value;
        data->min_value = min_value;
        data->reqtrainpoints = reqtrainpoints;
        return data;
    }

    bool operator==(SkillLineAbilityEntry5875 const& other) const
    {
        if (other.id != id)
            return false;
        if (other.skillId != skillId)
            return false;
        if (other.spellId != spellId)
            return false;
        if (other.racemask != racemask)
            return false;
        if (other.classmask != classmask)
            return false;
        if (other.req_skill_value != req_skill_value)
            return false;
        if (other.forward_spellid != forward_spellid)
            return false;
        if (other.learnOnGetSkill != learnOnGetSkill)
            return false;
        if (other.max_value != max_value)
            return false;
        if (other.min_value != min_value)
            return false;
        if (other.reqtrainpoints != reqtrainpoints)
            return false;

        return true;
    }

    bool operator!=(SkillLineAbilityEntry5875 const& other) const
    {
        return !(other == *this);
    }

    void WriteToSqlFile(std::ofstream& myfile, uint16 build) const
    {
        myfile << "(";
        myfile << id << ", ";
        myfile << build << ", ";
        myfile << skillId << ", ";
        myfile << spellId << ", ";
        myfile << racemask << ", ";
        myfile << classmask << ", ";
        myfile << req_skill_value << ", ";
        myfile << forward_spellid << ", ";
        myfile << learnOnGetSkill << ", ";
        myfile << max_value << ", ";
        myfile << min_value << ", ";
        myfile << reqtrainpoints << ")";
    }

    void WriteSkillLineAbilityHotfixRow(std::ofstream& myfile) const
    {
        myfile << racemask << ",";          // RaceMask
        myfile << id << ",";                // ID
        myfile << skillId << ",";           // SkillLine
        myfile << spellId << ",";           // Spell
        myfile << req_skill_value << ",";   // MinSkillLineRank
        myfile << classmask << ",";         // ClassMask
        myfile << forward_spellid << ",";   // SupercedesSpell
        myfile << learnOnGetSkill << ",";   // AcquireMethod
        myfile << max_value << ",";         // TrivialSkillLineRankHigh
        myfile << min_value << ",";         // TrivialSkillLineRankLow
        myfile << 0 << ",";                 // Flags
        myfile << 1 << ",";                 // NumSkillUps
        myfile << 0 << ",";                 // UniqueBit
        myfile << 0 << ",";                 // TradeSkillCategoryID
        myfile << 0 << ",";                 // SkillupSkillLineID
        myfile << 0 << ",";                 // CharacterPoints1
        myfile << reqtrainpoints;           // CharacterPoints2
    }
};

struct SkillRaceClassInfoEntry5875
{
    uint32    id;                                           // 0        m_ID
    uint32    skillId;                                      // 1        m_skillID
    uint32    raceMask;                                     // 2        m_raceMask
    uint32    classMask;                                    // 3        m_classMask
    uint32    flags;                                        // 4        m_flags
    uint32    reqLevel;                                     // 5        m_minLevel
    uint32    skillTierId;                                  // 6        m_skillTierID
    uint32    skillCostID;                                  // 7        m_skillCostIndex

    SkillRaceClassInfoEntry5875* ToLatestStructure() const
    {
        SkillRaceClassInfoEntry5875* data = new SkillRaceClassInfoEntry5875();
        data->id = id;
        data->skillId = skillId;
        data->raceMask = raceMask;
        data->classMask = classMask;
        data->flags = flags;
        data->reqLevel = reqLevel;
        data->skillTierId = skillTierId;
        data->skillCostID = skillCostID;
        return data;
    }

    bool operator==(SkillRaceClassInfoEntry5875 const& other) const
    {
        if (other.id != id)
            return false;
        if (other.skillId != skillId)
            return false;
        if (other.raceMask != raceMask)
            return false;
        if (other.classMask != classMask)
            return false;
        if (other.flags != flags)
            return false;
        if (other.reqLevel != reqLevel)
            return false;
        if (other.skillTierId != skillTierId)
            return false;
        if (other.skillCostID != skillCostID)
            return false;

        return true;
    }

    bool operator!=(SkillRaceClassInfoEntry5875 const& other) const
    {
        return !(other == *this);
    }

    void WriteToSqlFile(std::ofstream& myfile, uint16 build) const
    {
        myfile << "(";
        myfile << id << ", ";
        myfile << build << ", ";
        myfile << skillId << ", ";
        myfile << raceMask << ", ";
        myfile << classMask << ", ";
        myfile << flags << ", ";
        myfile << reqLevel << ", ";
        myfile << skillTierId << ", ";
        myfile << skillCostID << ")";
    }

    void WriteToHotfixCsvFile(std::ofstream& myfile) const
    {
        myfile << id << ",";                 // ID
        myfile << raceMask << ",";           // RaceMask
        myfile << skillId << ",";            // SkillID
        myfile << classMask << ",";          // ClassMask
        myfile << flags << ",";              // Flags
        myfile << 0 << ",";                  // Availability
        myfile << reqLevel << ",";           // MinLevel
        myfile << skillTierId;               // SkillTierID
    }
};


struct CreatureSpellDataEntry5875
{
    uint32    ID;                                           // 0        m_ID
    uint32    spellId[4];                                   // 1-4      m_spells[4]
  //uint32    availability[4];                              // 4-7      m_availability[4]

    CreatureSpellDataEntry5875* ToLatestStructure() const
    {
        CreatureSpellDataEntry5875* data = new CreatureSpellDataEntry5875();
        data->ID = ID;
        std::copy(std::begin(spellId), std::end(spellId), std::begin(data->spellId));
        return data;
    }

    bool operator==(CreatureSpellDataEntry5875 const& other) const
    {
        if (other.ID != ID)
            return false;

        if (!std::equal(std::begin(spellId), std::end(spellId), std::begin(other.spellId)))
            return false;

        return true;
    }

    bool operator!=(CreatureSpellDataEntry5875 const& other) const
    {
        return !(other == *this);
    }

    void WriteToSqlFile(std::ofstream& myfile, uint16 build) const
    {
        myfile << "(";
        myfile << ID << ", ";
        myfile << build << ", ";
        myfile << spellId[0] << ", ";
        myfile << spellId[1] << ", ";
        myfile << spellId[2] << ", ";
        myfile << spellId[3] << ")";
    }
};

struct MailTemplateEntry5875
{
    uint32      ID;                                         // 0        m_ID
    char*       subject[MAX_DBC_LOCALE];                    // 1-8      m_subject_lang
                                                            // 9        string flags

    MailTemplateEntry5875* ToLatestStructure() const
    {
        MailTemplateEntry5875* data = new MailTemplateEntry5875();
        data->ID = ID;
        CopyStringArrays(subject, data->subject, MAX_DBC_LOCALE);
        return data;
    }

    bool operator==(MailTemplateEntry5875 const& other) const
    {
        if (other.ID != ID)
            return false;

        if (!CompareStringArrays(other.subject, subject, MAX_DBC_LOCALE))
            return false;

        return true;
    }

    bool operator!=(MailTemplateEntry5875 const& other) const
    {
        return !(other == *this);
    }

    void WriteToSqlFile(std::ofstream& myfile, uint16 build) const
    {
        myfile << "(";
        myfile << ID << ", ";
        myfile << build << ", ";
        myfile << EscapeString(subject[0]) << "', '";
        myfile << EscapeString(subject[1]) << "', '";
        myfile << EscapeString(subject[2]) << "', '";
        myfile << EscapeString(subject[3]) << "', '";
        myfile << EscapeString(subject[4]) << "', '";
        myfile << EscapeString(subject[5]) << "', '";
        myfile << EscapeString(subject[6]) << "', '";
        myfile << EscapeString(subject[7]) << "')";
    }
};

#if defined( __GNUC__ )
#pragma pack()
#else
#pragma pack(pop)
#endif

#endif