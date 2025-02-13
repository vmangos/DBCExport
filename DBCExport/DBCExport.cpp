#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include "SharedDefines.h"
#include "DBCDeclarations.h"
#include "Database\Database.h"

void ExportSkillLineHotfixes(std::set<uint32> entries, std::vector<SkillLineEntry5875*> const& store)
{
    std::ofstream myfile("HotFix_SkillLine.csv");
    if (!myfile.is_open())
        return;

    printf("Writing SkillLine hotfixes...\n");
    uint32 count = 0;

    myfile << "DisplayName,AlternateVerb,Description,HordeDisplayName,NeutralDisplayName,Id,CategoryId,SpellIconFileId,CanLink,ParentSkillLineId,ParentTierIndex,Flags,SpellBookSpellId\n";
    for (auto const& id : entries)
    {
        if (!store[id])
            continue;

        count++;
        if (count > 1)
            myfile << "\n";

        store[id]->WriteToHotfixCsvFile(myfile);
    }

    myfile.close();
    printf("Wrote %u SkillLine hotfix rows.\n", count);
}

void ExportSkillRaceClassInfoHotfixes(std::set<uint32> entries, std::vector<SkillRaceClassInfoEntry5875*> const& store)
{
    std::ofstream myfile("HotFix_SkillRaceClassInfo.csv");
    if (!myfile.is_open())
        return;

    printf("Writing SkillRaceClassInfo hotfixes...\n");
    uint32 count = 0;

    myfile << "Id,RaceMask,SkillId,ClassMask,Flags,Availability,MinLevel,SkillTierId\n";
    for (auto const& id : entries)
    {
        if (!store[id])
            continue;

        count++;
        if (count > 1)
            myfile << "\n";

        store[id]->WriteToHotfixCsvFile(myfile);
    }

    myfile.close();
    printf("Wrote %u SkillRaceClassInfo hotfix rows.\n", count);
}

void ExportSkillLineAbilityHotfixes(std::set<uint32> entries, std::vector<SkillLineAbilityEntry5875*> const& store)
{
    std::ofstream myfile("HotFix_SkillLineAbility.csv");
    if (!myfile.is_open())
        return;

    printf("Writing SkillLineAbility hotfixes...\n");
    uint32 count = 0;

    myfile << "RaceMask,Id,SkillLine,Spell,MinSkillLineRank,ClassMask,SupercedesSpell,AcquireMethod,TrivialSkillLineRankHigh,TrivialSkillLineRankLow,Flags,NumSkillUps,UniqueBit,TradeSkillCategoryID,SkillupSkillLineID,CharacterPoints1,CharacterPoints2\n";
    for (auto const& id : entries)
    {
        if (!store[id])
            continue;

        count++;
        if (count > 1)
            myfile << "\n";

        store[id]->WriteSkillLineAbilityHotfixRow(myfile);
    }

    myfile.close();
    printf("Wrote %u SkillLineAbility hotfix rows.\n", count);
}

void ExportSpellHotfixes(std::set<uint32> entries, std::vector<SpellEntry5875*> const& store)
{
    std::ofstream myfile("HotFix_Spell.csv");
    if (!myfile.is_open())
        return;

    printf("Writing Spell hotfixes...\n");
    uint32 count = 0;

    myfile << "SpellId,NameSubText,Description,AuraDescription\n";
    for (auto const& id : entries)
    {
        if (!store[id])
            continue;

        count++;
        if (count > 1)
            myfile << "\n";

        store[id]->WriteSpellHotfixRow(myfile);
    }

    myfile.close();
    printf("Wrote %u Spell hotfix rows.\n", count);
}

void ExportSpellNameHotfixes(std::set<uint32> entries, std::vector<SpellEntry5875*> const& store)
{
    std::ofstream myfile("HotFix_SpellName.csv");
    if (!myfile.is_open())
        return;

    printf("Writing SpellName hotfixes...\n");
    uint32 count = 0;

    myfile << "SpellId,Name\n";
    for (auto const& id : entries)
    {
        if (!store[id])
            continue;

        count++;
        if (count > 1)
            myfile << "\n";

        store[id]->WriteSpellNameHotfixRow(myfile);
    }

    myfile.close();
    printf("Wrote %u SpellName hotfix rows.\n", count);
}

void ExportSpellLevelsHotfixes(std::set<uint32> entries, std::vector<SpellEntry5875*> const& store)
{
    std::ofstream myfile("HotFix_SpellLevels.csv");
    if (!myfile.is_open())
        return;

    printf("Writing SpellLevels hotfixes...\n");
    uint32 count = 0;

    myfile << "Id,DifficultyId,BaseLevel,MaxLevel,SpellLevel,MaxPassiveAuraLevel,SpellId\n";
    for (auto const& id : entries)
    {
        if (!store[id])
            continue;

        if (!store[id]->baseLevel && !store[id]->maxLevel && !store[id]->spellLevel)
            continue;

        count++;
        if (count > 1)
            myfile << "\n";

        store[id]->WriteSpellLevelsHotfixRow(myfile);
    }

    myfile.close();
    printf("Wrote %u SpellLevels hotfix rows.\n", count);
}

void ExportSpellAuraOptionsHotfixes(std::set<uint32> entries, std::vector<SpellEntry5875*> const& store)
{
    std::ofstream myfile("HotFix_SpellAuraOptions.csv");
    if (!myfile.is_open())
        return;

    printf("Writing SpellAuraOptions hotfixes...\n");
    uint32 count = 0;

    myfile << "Id,DifficultyId,CumulativeAura,ProcCategoryRecovery,ProcChance,ProcCharges,SpellProcsPerMinuteId,ProcTypeMask0,ProcTypeMask1,SpellId\n";
    for (auto const& id : entries)
    {
        if (!store[id])
            continue;

        if (!store[id]->StackAmount && !store[id]->procChance && !store[id]->procCharges && !store[id]->procFlags)
            continue;

        count++;
        if (count > 1)
            myfile << "\n";

        store[id]->WriteSpellAuraOptionsHotfixRow(myfile);
    }

    myfile.close();
    printf("Wrote %u SpellAuraOptions hotfix rows.\n", count);
}

void ExportSpellMiscHotfixes(std::set<uint32> entries, std::vector<SpellEntry5875*> const& store)
{
    std::ofstream myfile("HotFix_SpellMisc.csv");
    if (!myfile.is_open())
        return;

    printf("Writing SpellMisc hotfixes...\n");
    uint32 count = 0;

    myfile << "Id,DifficultyId,CastingTimeIndex,DurationIndex,RangeIndex,SchoolMask,Speed,LaunchDelay,MinDuration,SpellIconFileDataId,ActiveIconFileDataId,Attributes1,Attributes2,Attributes3,Attributes4,Attributes5,Attributes6,Attributes7,Attributes8,Attributes9,Attributes10,Attributes11,Attributes12,Attributes13,Attributes14,SpellId\n";
    for (auto const& id : entries)
    {
        if (!store[id])
            continue;

        count++;
        if (count > 1)
            myfile << "\n";

        store[id]->WriteSpellMiscHotfixRow(myfile);
    }

    myfile.close();
    printf("Wrote %u SpellMisc hotfix rows.\n", count);
}

void ExportSpellEffectHotfixes(std::set<uint32> entries, std::vector<SpellEntry5875*> const& store)
{
    std::ofstream myfile("HotFix_SpellEffect.csv");
    if (!myfile.is_open())
        return;

    printf("Writing SpellEffect hotfixes...\n");
    uint32 count = 0;

    myfile << "Id,DifficultyId,EffectIndex,Effect,EffectAmplitude,EffectAttributes,EffectAura,EffectAuraPeriod,EffectBasePoints,EffectBonusCoefficient,EffectChainAmplitude,EffectChainTargets,EffectDieSides,EffectItemType,EffectMechanic,EffectPointsPerResource,EffectPosFacing,EffectRealPointsPerLevel,EffectTriggerSpell,BonusCoefficientFromAP,PvpMultiplier,Coefficient,Variance,ResourceCoefficient,GroupSizeBasePointsCoefficient,EffectMiscValue1,EffectMiscValue2,EffectRadiusIndex1,EffectRadiusIndex2,EffectSpellClassMask1,EffectSpellClassMask2,EffectSpellClassMask3,EffectSpellClassMask4,ImplicitTarget1,ImplicitTarget2,SpellId\n";
    for (auto const& id : entries)
    {
        if (!store[id])
            continue;

        for (int i = 0; i < MAX_EFFECT_INDEX; i++)
        {
            if (!store[id]->Effect[i])
                continue;

            count++;
            if (count > 1)
                myfile << "\n";

            store[id]->WriteSpellEffectHotfixRow(myfile, i);
        }
        
    }

    myfile.close();
    printf("Wrote %u SpellEffect hotfix rows.\n", count);
}

void ExportSpellXSpellVisualHotfixes(std::set<uint32> entries, std::vector<SpellEntry5875*> const& store)
{
    std::ofstream myfile("HotFix_SpellXSpellVisual.csv");
    if (!myfile.is_open())
        return;

    printf("Writing SpellXSpellVisual hotfixes...\n");
    uint32 count = 0;

    myfile << "Id,DifficultyId,SpellVisualId,Probability,Flags,Priority,SpellIconFileId,ActiveIconFileId,ViewerUnitConditionId,ViewerPlayerConditionId,CasterUnitConditionId,CasterPlayerConditionId,SpellId\n";
    for (auto const& id : entries)
    {
        if (!store[id])
            continue;

        if (!store[id]->SpellVisual)
            continue;

        count++;
        if (count > 1)
            myfile << "\n";

        store[id]->WriteSpellXSpellVisualHotfixRow(myfile);
    }

    myfile.close();
    printf("Wrote %u SpellXSpellVisual hotfix rows.\n", count);
}
