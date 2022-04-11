#include <iostream>
#include <fstream>
#include "SharedDefines.h"
#include "DBCDeclarations.h"
#include "Database\Database.h"

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

        spellEntry->WriteToSqlFile(myfile, build);
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