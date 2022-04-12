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