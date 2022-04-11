#include <iostream>
#include <fstream>
#include "SharedDefines.h"
#include "DBCDeclarations.h"
#include "Database\Database.h"

std::string EscapeString(char* unescapedString)
{
    char* escapedString = new char[strlen(unescapedString) * 2 + 1];
    mysql_escape_string(escapedString, unescapedString, strlen(unescapedString));
    std::string returnString = escapedString;
    delete[] escapedString;
    return returnString;
}

void ExportTaxiNodes(unsigned int build, std::vector<TaxiNodesEntry5875*> const& taxiNodesStore)
{
    std::ofstream myfile("taxi_nodes.sql");
    if (!myfile.is_open())
        return;

    printf("Extracting taxi nodes...\n");
    uint32 count = 0;
    
    myfile << "INSERT INTO `taxi_nodes` VALUES\n";
    for (uint32 i = 0; i < taxiNodesStore.size(); ++i)
    {
        TaxiNodesEntry5875 const* node = taxiNodesStore[i];
        if (!node)
            continue;

        count++;
        if (count > 1)
            myfile << ",\n";

        myfile << "(" << node->ID << ", " << build << ", " << node->map_id << ", " << node->x << ", " << node->y << ", " << node->z << ", '" << EscapeString(node->name[0]) << "', '" << EscapeString(node->name[1]) << "', '" << EscapeString(node->name[2]) << "', '" << EscapeString(node->name[3]) << "', '" << EscapeString(node->name[4]) << "', '" << EscapeString(node->name[5]) << "', '" << EscapeString(node->name[6]) << "', '" << EscapeString(node->name[7]) << "', " << node->MountCreatureID[0] << ", " << node->MountCreatureID[1] << ")";
    }

    myfile << ";";
    myfile.close();
    printf("Extracted %u TaxiNodes.dbc rows.\n", count);
}

void ExportSpells(unsigned int build, std::vector<SpellEntry5875*> const& spellStore)
{
    std::ofstream myfile("spell_template.sql");
    if (!myfile.is_open())
        return;

    printf("Extracting spells...\n");
    uint32 count = 0;

    myfile << "INSERT INTO `spell_template` VALUES\n";
    for (uint32 i = 0; i < spellStore.size(); ++i)
    {
        SpellEntry5875 const* spellEntry = spellStore[i];
        if (!spellEntry)
            continue;

        count++;
        if (count > 1)
            myfile << ",\n";

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
        myfile << "'" << EscapeString(spellEntry->SpellName[1]) << "', "; // 122
        myfile << "'" << EscapeString(spellEntry->SpellName[2]) << "', "; // 123
        myfile << "'" << EscapeString(spellEntry->SpellName[3]) << "', "; // 124
        myfile << "'" << EscapeString(spellEntry->SpellName[4]) << "', "; // 125
        myfile << "'" << EscapeString(spellEntry->SpellName[5]) << "', "; // 126
        myfile << "'" << EscapeString(spellEntry->SpellName[6]) << "', "; // 127
        myfile << "'" << EscapeString(spellEntry->SpellName[7]) << "', "; // 128
        myfile << spellEntry->SpellNameFlag << ", "; // 129
        myfile << "'" << EscapeString(spellEntry->Rank[0]) << "', "; // 130
        myfile << "'" << EscapeString(spellEntry->Rank[1]) << "', "; // 131
        myfile << "'" << EscapeString(spellEntry->Rank[2]) << "', "; // 132
        myfile << "'" << EscapeString(spellEntry->Rank[3]) << "', "; // 133
        myfile << "'" << EscapeString(spellEntry->Rank[4]) << "', "; // 134
        myfile << "'" << EscapeString(spellEntry->Rank[5]) << "', "; // 135
        myfile << "'" << EscapeString(spellEntry->Rank[6]) << "', "; // 136
        myfile << "'" << EscapeString(spellEntry->Rank[7]) << "', "; // 137
        myfile << spellEntry->RankFlags << ", "; // 138
        myfile << "'" << EscapeString(spellEntry->Description[0]) << "', "; // 139
        myfile << "'" << EscapeString(spellEntry->Description[1]) << "', "; // 140
        myfile << "'" << EscapeString(spellEntry->Description[2]) << "', "; // 141
        myfile << "'" << EscapeString(spellEntry->Description[3]) << "', "; // 142
        myfile << "'" << EscapeString(spellEntry->Description[4]) << "', "; // 143
        myfile << "'" << EscapeString(spellEntry->Description[5]) << "', "; // 144
        myfile << "'" << EscapeString(spellEntry->Description[6]) << "', "; // 145
        myfile << "'" << EscapeString(spellEntry->Description[7]) << "', "; // 146
        myfile << spellEntry->DescriptionFlags << ", "; // 147
        myfile << "'" << EscapeString(spellEntry->ToolTip[0]) << "', "; // 148
        myfile << "'" << EscapeString(spellEntry->ToolTip[1]) << "', "; // 149
        myfile << "'" << EscapeString(spellEntry->ToolTip[2]) << "', "; // 150
        myfile << "'" << EscapeString(spellEntry->ToolTip[3]) << "', "; // 151
        myfile << "'" << EscapeString(spellEntry->ToolTip[4]) << "', "; // 152
        myfile << "'" << EscapeString(spellEntry->ToolTip[5]) << "', "; // 153
        myfile << "'" << EscapeString(spellEntry->ToolTip[6]) << "', "; // 154
        myfile << "'" << EscapeString(spellEntry->ToolTip[7]) << "', "; // 155
        myfile << spellEntry->ToolTipFlags << ", "; // 156
        myfile << spellEntry->ManaCostPercentage << ", "; // 157
        myfile << spellEntry->StartRecoveryCategory << ", "; // 158
        myfile << spellEntry->StartRecoveryTime << ", "; // 159
        myfile << "0, "; // minTargetLevel
        myfile << spellEntry->MaxTargetLevel << ", "; // 160
        myfile << spellEntry->SpellFamilyName << ", "; // 161
        myfile << spellEntry->SpellFamilyFlags.Flags << ", "; // 162
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

    myfile << ";";
    myfile.close();
    printf("Extracted %u Spell.dbc rows.\n", count);
}

void ExportFactions(unsigned int build, std::vector<FactionEntry5875*> const& factionStore)
{
    printf("Extracting factions...\n");

    uint32 count = 0;
    std::ofstream myfile("faction.sql");
    if (myfile.is_open())
    {
        myfile << "INSERT INTO `faction` VALUES \n";
        for (uint32 i = 0; i < factionStore.size(); ++i)
        {
            if (FactionEntry5875 const* factionEntry = factionStore[i])
            {
                count++;
                if (count > 1)
                    myfile << ",\n";

                myfile << "(";
                myfile << factionEntry->Id << ", "; // 1
                myfile << build << ", ";
                myfile << factionEntry->reputationListID << ", ";// 2
                myfile << factionEntry->BaseRepRaceMask[0] << ", "; // 3
                myfile << factionEntry->BaseRepRaceMask[1] << ", "; // 4
                myfile << factionEntry->BaseRepRaceMask[2] << ", "; // 5
                myfile << factionEntry->BaseRepRaceMask[3] << ", "; // 6
                myfile << factionEntry->BaseRepClassMask[0] << ", "; // 7
                myfile << factionEntry->BaseRepClassMask[1] << ", "; // 8
                myfile << factionEntry->BaseRepClassMask[2] << ", "; // 9
                myfile << factionEntry->BaseRepClassMask[3] << ", "; // 10
                myfile << factionEntry->BaseRepValue[0] << ", "; // 11
                myfile << factionEntry->BaseRepValue[1] << ", "; // 12
                myfile << factionEntry->BaseRepValue[2] << ", "; // 13
                myfile << factionEntry->BaseRepValue[3] << ", "; // 14
                myfile << factionEntry->ReputationFlags[0] << ", "; // 15
                myfile << factionEntry->ReputationFlags[1] << ", "; // 16
                myfile << factionEntry->ReputationFlags[2] << ", "; // 17
                myfile << factionEntry->ReputationFlags[3] << ", "; // 18
                myfile << factionEntry->team << ", "; // 19
                myfile << "'" << EscapeString(factionEntry->name[0]) << "', "; // 20
                myfile << "'" << EscapeString(factionEntry->name[1]) << "', "; // 21
                myfile << "'" << EscapeString(factionEntry->name[2]) << "', "; // 22
                myfile << "'" << EscapeString(factionEntry->name[3]) << "', "; // 23
                myfile << "'" << EscapeString(factionEntry->name[4]) << "', "; // 24
                myfile << "'" << EscapeString(factionEntry->name[5]) << "', "; // 25
                myfile << "'" << EscapeString(factionEntry->name[6]) << "', "; // 26
                myfile << "'" << EscapeString(factionEntry->name[7]) << "', "; // 27
                myfile << "'" << EscapeString(factionEntry->description[0]) << "', "; // 28
                myfile << "'" << EscapeString(factionEntry->description[1]) << "', "; // 29
                myfile << "'" << EscapeString(factionEntry->description[2]) << "', "; // 30
                myfile << "'" << EscapeString(factionEntry->description[3]) << "', "; // 31
                myfile << "'" << EscapeString(factionEntry->description[4]) << "', "; // 32
                myfile << "'" << EscapeString(factionEntry->description[5]) << "', "; // 33
                myfile << "'" << EscapeString(factionEntry->description[6]) << "', "; // 34
                myfile << "'" << EscapeString(factionEntry->description[7]) << "')"; // 35
            }
        }
        myfile << ";";
        myfile.close();
    }
    printf("Extracted %u Faction.dbc rows.\n", count);
}

void ExportFactionTemplates(unsigned int build, std::vector<FactionTemplateEntry5875*> const& factionTemplateStore)
{
    printf("Extracting factions templates...\n");

    uint32 count = 0;
    std::ofstream myfile("faction_template.sql");
    if (myfile.is_open())
    {
        myfile << "INSERT INTO `faction_template` VALUES \n";
        for (uint32 i = 0; i < factionTemplateStore.size(); ++i)
        {
            if (FactionTemplateEntry5875 const* factionEntry = factionTemplateStore[i])
            {
                count++;
                if (count > 1)
                    myfile << ",\n";

                myfile << "(";
                myfile << factionEntry->ID << ", "; // 1
                myfile << build << ", ";
                myfile << factionEntry->faction << ", ";// 2
                myfile << factionEntry->factionFlags << ", "; // 3
                myfile << factionEntry->ourMask << ", "; // 4
                myfile << factionEntry->friendlyMask << ", "; // 5
                myfile << factionEntry->hostileMask << ", "; // 6
                myfile << factionEntry->enemyFaction[0] << ", "; // 7
                myfile << factionEntry->enemyFaction[1] << ", "; // 8
                myfile << factionEntry->enemyFaction[2] << ", "; // 9
                myfile << factionEntry->enemyFaction[3] << ", "; // 10
                myfile << factionEntry->friendFaction[0] << ", "; // 11
                myfile << factionEntry->friendFaction[1] << ", "; // 12
                myfile << factionEntry->friendFaction[2] << ", "; // 13
                myfile << factionEntry->friendFaction[3] << ")"; // 14
            }
        }
        myfile << ";";
        myfile.close();
    }
    printf("Extracted %u FactionTemplate.dbc rows.\n", count);
}

void ExportSkillLineAbilities(unsigned int build, std::vector<SkillLineAbilityEntry5875*> const& skillLineAbilityStore)
{
    std::ofstream myfile("skill_line_ability.sql");
    if (!myfile.is_open())
        return;

    printf("Extracting skill line abilities...\n");
    uint32 count = 0;

    myfile << "INSERT INTO `skill_line_ability` VALUES\n";
    for (uint32 i = 0; i < skillLineAbilityStore.size(); ++i)
    {
        SkillLineAbilityEntry5875 const* skill = skillLineAbilityStore[i];
        if (!skill)
            continue;

        count++;
        if (count > 1)
            myfile << ",\n";

        myfile << "(" << skill->id << ", " << build << ", " << skill->skillId << ", " << skill->spellId << ", " << skill->racemask << ", " << skill->classmask << ", " << skill->req_skill_value << ", " << skill->forward_spellid << ", " << skill->learnOnGetSkill << ", " << skill->max_value << ", " << skill->min_value << ", " << skill->reqtrainpoints << ")";
    }

    myfile << ";";
    myfile.close();
    printf("Extracted %u SkillLineAbility.dbc rows.\n", count);
}

void ExportAreaTriggers(unsigned int build, std::vector<AreaTriggerEntry5875*> const& areaTriggerStore)
{
    std::ofstream myfile("areatrigger_template.sql");
    if (!myfile.is_open())
        return;

    printf("Extracting area triggers...\n");
    uint32 count = 0;

    myfile << "INSERT INTO `areatrigger_template` VALUES\n";
    for (uint32 i = 0; i < areaTriggerStore.size(); ++i)
    {
        AreaTriggerEntry5875 const* trigger = areaTriggerStore[i];
        if (!trigger)
            continue;

        count++;
        if (count > 1)
            myfile << ",\n";

        myfile << "(" << trigger->id << ", " << build << ", " << trigger->mapid << ", " << trigger->x << ", " << trigger->y << ", " << trigger->z << ", " << trigger->radius << ", " << trigger->box_x << ", " << trigger->box_y << ", " << trigger->box_z << ", " << trigger->box_orientation << ")";
    }

    myfile << ";";
    myfile.close();
    printf("Extracted %u AreaTrigger.dbc rows.\n", count);
}

void ExportCreatureSpellData(unsigned int build, std::vector<CreatureSpellDataEntry5875*> const& creatureSpellDataStore)
{
    std::ofstream myfile("pet_spell_data.sql");
    if (!myfile.is_open())
        return;

    printf("Extracting creature spell data...\n");
    uint32 count = 0;

    myfile << "INSERT INTO `pet_spell_data` VALUES\n";
    for (uint32 i = 0; i < creatureSpellDataStore.size(); ++i)
    {
        CreatureSpellDataEntry5875 const* data = creatureSpellDataStore[i];
        if (!data)
            continue;

        count++;
        if (count > 1)
            myfile << ",\n";

        myfile << "(" << data->ID << ", " << build << ", " << data->spellId[0] << ", " << data->spellId[1] << ", " << data->spellId[2] << ", " << data->spellId[3] << ")";
    }

    myfile << ";";
    myfile.close();
    printf("Extracted %u CreatureSpellData.dbc rows.\n", count);
}

void ExportMailTemplates(unsigned int build, std::vector<MailTemplateEntry5875*> const& mailTemplateStore)
{
    std::ofstream myfile("mail_text_template.sql");
    if (!myfile.is_open())
        return;

    printf("Extracting mail templates...\n");
    uint32 count = 0;

    myfile << "INSERT INTO `mail_text_template` VALUES\n";
    for (uint32 i = 0; i < mailTemplateStore.size(); ++i)
    {
        MailTemplateEntry5875 const* data = mailTemplateStore[i];
        if (!data)
            continue;

        count++;
        if (count > 1)
            myfile << ",\n";

        myfile << "(" << data->ID << ", '" << EscapeString(data->subject[0]) << "', '" << EscapeString(data->subject[1]) << "', '" << EscapeString(data->subject[2]) << "', '" << EscapeString(data->subject[3]) << "', '" << EscapeString(data->subject[4]) << "', '" << EscapeString(data->subject[5]) << "', '" << EscapeString(data->subject[6]) << "', '" << EscapeString(data->subject[7]) << "')";
    }

    myfile << ";";
    myfile.close();
    printf("Extracted %u MailTemplate.dbc rows.\n", count);
}