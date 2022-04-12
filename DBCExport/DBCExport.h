#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include "SharedDefines.h"
#include "DBCDeclarations.h"
#include "Database\Database.h"

template <class T>
void ExportToSqlFile(unsigned int build, char const* fileName, char const* tableName, std::vector<T*> const& store)
{
    std::ofstream myfile(fileName);
    if (!myfile.is_open())
        return;

    printf("Writing %s table...\n", tableName);
    uint32 count = 0;

    myfile << "INSERT INTO `" << tableName << "` VALUES\n";
    for (uint32 i = 0; i < store.size(); ++i)
    {
        T const* data = store[i];
        if (!data)
            continue;

        count++;
        if (count > 1)
            myfile << ",\n";

        data->WriteToSqlFile(myfile, build);
    }

    myfile << ";";
    myfile.close();
    printf("Wrote %u %s rows.\n", count, tableName);
}

void ExportSkillLineHotfixes(std::set<uint32> entries, std::vector<SkillLineEntry5875*> const& store);
void ExportSkillRaceClassInfoHotfixes(std::set<uint32> entries, std::vector<SkillRaceClassInfoEntry5875*> const& store);
