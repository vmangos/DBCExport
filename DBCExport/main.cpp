#include "DBCDeclarations.h"
#include "SharedDefines.h"
#include "ProgressBar.h"
#include <stdio.h>
#include <stdlib.h>
#include "DBCExport.h"
#include "Common.h"
#include <iostream>
#include <fstream>
#include <set>
#include "Database\Database.h"

static bool ReadDBCBuildFileText(const std::string& dbc_path, char const* localeName, std::string& text)
{
    std::string filename = dbc_path + "component.wow-" + localeName + ".txt";

    if (FILE* file = fopen(filename.c_str(), "rb"))
    {
        char buf[100];
        fread(buf, 1, 100 - 1, file);
        fclose(file);

        text = &buf[0];
        return true;
    }
    else
        return false;
}

static uint32 ReadDBCBuild(const std::string& dbc_path, LocaleNameStr const* localeNameStr = nullptr)
{
    std::string text;

    if (!localeNameStr)
    {
        for (LocaleNameStr const* itr = &fullLocaleNameList[0]; itr->name; ++itr)
        {
            if (ReadDBCBuildFileText(dbc_path, itr->name, text))
            {
                localeNameStr = itr;
                break;
            }
        }
    }
    else
        ReadDBCBuildFileText(dbc_path, localeNameStr->name, text);

    if (text.empty())
        return 0;

    size_t pos = text.find("version=\"");
    size_t pos1 = pos + strlen("version=\"");
    size_t pos2 = text.find("\"", pos1);
    if (pos == text.npos || pos2 == text.npos || pos1 >= pos2)
        return 0;

    std::string build_str = text.substr(pos1, pos2 - pos1);

    int build = atoi(build_str.c_str());
    if (build <= 0)
        return 0;

    return build;
}

struct LocalData
{
    LocalData(uint32 build)
        : main_build(build), availableDbcLocales(0xFFFFFFFF), checkedDbcLocaleBuilds(0) {}

    uint32 main_build;

    // bitmasks for index of fullLocaleNameList
    uint32 availableDbcLocales;
    uint32 checkedDbcLocaleBuilds;
};

#if COMPILER == COMPILER_MICROSOFT
#  define SIZEFMTD "%Iu"
#else
#  define SIZEFMTD "%zu"
#endif

#  define snprintf _snprintf

template<class T>
inline void LoadDBCWotlk(LocalData& localeData, BarGoLink& bar, StoreProblemList& errlist, DBCStorage<T>& storage, const std::string& dbc_path, const std::string& filename)
{
    // compatibility format and C++ structure sizes
    //MANGOS_ASSERT(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()) == sizeof(T) || LoadDBC_assert_print(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()), sizeof(T), filename));

    std::string dbc_filename = dbc_path + filename;
    if (storage.Load(dbc_filename.c_str()))
    {
        bar.step();
        for (uint8 i = 0; fullLocaleNameList[i].name; ++i)
        {
            if (!(localeData.availableDbcLocales & (1 << i)))
                continue;

            LocaleNameStr const* localStr = &fullLocaleNameList[i];

            std::string dbc_dir_loc = dbc_path + localStr->name + "/";

            if (!(localeData.checkedDbcLocaleBuilds & (1 << i)))
            {
                localeData.checkedDbcLocaleBuilds |= (1 << i); // mark as checked for speedup next checks

                uint32 build_loc = ReadDBCBuild(dbc_dir_loc, localStr);
                if (localeData.main_build != build_loc)
                {
                    localeData.availableDbcLocales &= ~(1 << i); // mark as not available for speedup next checks

                                                                 // exist but wrong build
                    if (build_loc)
                    {
                        std::string dbc_filename_loc = dbc_path + localStr->name + "/" + filename;
                        char buf[200];
                        snprintf(buf, 200, " (exist, but DBC locale subdir %s have DBCs for build %u instead expected build %u, it and other DBC from subdir skipped)", localStr->name, build_loc, localeData.main_build);
                        errlist.push_back(dbc_filename_loc + buf);
                    }

                    continue;
                }
            }

            std::string dbc_filename_loc = dbc_path + localStr->name + "/" + filename;
            if (!storage.LoadStringsFrom(dbc_filename_loc.c_str()))
                localeData.availableDbcLocales &= ~(1 << i);// mark as not available for speedup next checks
        }
    }
    else
    {
        // sort problematic dbc to (1) non compatible and (2) nonexistent
        FILE* f = fopen(dbc_filename.c_str(), "rb");
        if (f)
        {
            char buf[100];
            snprintf(buf, 100, " (exist, but have %u fields instead " SIZEFMTD ") Wrong client version DBC file?", storage.GetFieldCount(), strlen(storage.GetFormat()));
            errlist.push_back(dbc_filename + buf);
            fclose(f);
        }
        else
            errlist.push_back(dbc_filename);
    }
}

template<class T>
inline void LoadDBC(uint32& availableDbcLocales, BarGoLink& bar, StoreProblemList& errlist, DBCStorage<T>& storage, const std::string& dbc_path, const std::string& filename, bool vanilla)
{
    // compatibility format and C++ structure sizes
    //MANGOS_ASSERT(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()) == sizeof(T) || LoadDBC_assert_print(DBCFileLoader::GetFormatRecordSize(storage.GetFormat()), sizeof(T), filename));

    std::string dbc_filename = dbc_path + filename;
    if (storage.Load(dbc_filename.c_str()))
    {
        bar.step();
        if (vanilla)
        {
            for (uint8 i = 0; fullLocaleNameListVanilla[i].name; ++i)
            {
                if (!(availableDbcLocales & (1 << i)))
                    continue;

                std::string dbc_filename_loc = dbc_path + fullLocaleNameListVanilla[i].name + "/" + filename;
                if (!storage.LoadStringsFrom(dbc_filename_loc.c_str()))
                    availableDbcLocales &= ~(1 << i);           // mark as not available for speedup next checks
            }
        }
        {
            for (uint8 i = 0; fullLocaleNameList[i].name; ++i)
            {
                if (!(availableDbcLocales & (1 << i)))
                    continue;

                std::string dbc_filename_loc = dbc_path + fullLocaleNameList[i].name + "/" + filename;
                if (!storage.LoadStringsFrom(dbc_filename_loc.c_str()))
                    availableDbcLocales &= ~(1 << i);           // mark as not available for speedup next checks
            }
        }
    }
    else
    {
        // sort problematic dbc to (1) non compatible and (2) nonexistent
        FILE* f = fopen(dbc_filename.c_str(), "rb");
        if (f)
        {
            char buf[100];
            snprintf(buf, 100, " (exist, but have %u fields instead " SIZEFMTD ") Wrong client version DBC file?", storage.GetFieldCount(), strlen(storage.GetFormat()));
            errlist.push_back(dbc_filename + buf);
            fclose(f);
        }
        else
            errlist.push_back(dbc_filename);
    }
}

template <class A, class B>
void CopyDbcStoreIntoVector(DBCStorage<A> const& source, std::vector<B*>& destination)
{
    destination.resize(source.GetNumRows());
    for (uint32 i = 0; i < source.GetNumRows(); ++i)
    {
        A const* pRow = source.LookupEntry(i);
        if (!pRow)
            continue;

        destination[i] = pRow->ToLatestStructure();
    }
}

void LoadAllDbcFiles(uint32 build, std::string dbcPath, std::vector<AreaTriggerEntry5875*>& areaTriggerStore, std::vector<TaxiNodesEntry5875*>& taxiNodesStore,
                     std::vector<FactionEntry5875*>& factionStore, std::vector<FactionTemplateEntry5875*>& factionTemplateStore,
                     std::vector<SpellEntry5875*>& spellStore, std::vector<SkillLineAbilityEntry5875*>& skillLineAbilityStore,
                     std::vector<CreatureSpellDataEntry5875*>& creatureSpellDataStore, std::vector<MailTemplateEntry5875*>& mailTemplateStore,
                     std::vector<SkillLineEntry5875*>& skillLineStore, std::vector<SkillRaceClassInfoEntry5875*>& skillRaceClassInfoStore)
{
    StoreProblemList bad_dbc_files;
    uint32 availableDbcLocales = 0xFFFFFFFF;

    sAreaTriggerStore5875.Clear();
    sTaxiNodeStore5875.Clear();
    sFactionStore5875.Clear();
    sFactionTemplateStore5875.Clear();
    sSpellStore5875.Clear();
    sSkillLineAbilityStore5875.Clear();
    sCreatureSpellDataStore5875.Clear();
    sMailTemplateStore5875.Clear();
    sSkillLineStore5875.Clear();
    sSkillRaceClassInfoStore5875.Clear();

    switch (build)
    {
        case 5875:
        case 5595:
        {
            printf("\nReading data from DBC files...\n");
            const uint32 DBCFilesCount = 10;
            BarGoLink bar(DBCFilesCount);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sAreaTriggerStore5875, dbcPath, "AreaTrigger.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sTaxiNodeStore5875, dbcPath, "TaxiNodes.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionStore5875, dbcPath, "Faction.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionTemplateStore5875, dbcPath, "FactionTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSpellStore5875, dbcPath, "Spell.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineAbilityStore5875, dbcPath, "SkillLineAbility.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sCreatureSpellDataStore5875, dbcPath, "CreatureSpellData.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sMailTemplateStore5875, dbcPath, "MailTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineStore5875, dbcPath, "SkillLine.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillRaceClassInfoStore5875, dbcPath, "SkillRaceClassInfo.dbc", true);

            CopyDbcStoreIntoVector<AreaTriggerEntry5875, AreaTriggerEntry5875>(sAreaTriggerStore5875, areaTriggerStore);
            CopyDbcStoreIntoVector<TaxiNodesEntry5875, TaxiNodesEntry5875>(sTaxiNodeStore5875, taxiNodesStore);
            CopyDbcStoreIntoVector<FactionEntry5875, FactionEntry5875>(sFactionStore5875, factionStore);
            CopyDbcStoreIntoVector<FactionTemplateEntry5875, FactionTemplateEntry5875>(sFactionTemplateStore5875, factionTemplateStore);
            CopyDbcStoreIntoVector<SpellEntry5875, SpellEntry5875>(sSpellStore5875, spellStore);
            CopyDbcStoreIntoVector<SkillLineAbilityEntry5875, SkillLineAbilityEntry5875>(sSkillLineAbilityStore5875, skillLineAbilityStore);
            CopyDbcStoreIntoVector<CreatureSpellDataEntry5875, CreatureSpellDataEntry5875>(sCreatureSpellDataStore5875, creatureSpellDataStore);
            CopyDbcStoreIntoVector<MailTemplateEntry5875, MailTemplateEntry5875>(sMailTemplateStore5875, mailTemplateStore);
            CopyDbcStoreIntoVector<SkillLineEntry5875, SkillLineEntry5875>(sSkillLineStore5875, skillLineStore);
            CopyDbcStoreIntoVector<SkillRaceClassInfoEntry5875, SkillRaceClassInfoEntry5875>(sSkillRaceClassInfoStore5875, skillRaceClassInfoStore);
            break;
        }
        case 5464:
        {
            printf("\nReading data from DBC files...\n");
            const uint32 DBCFilesCount = 10;
            BarGoLink bar(DBCFilesCount);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sAreaTriggerStore5875, dbcPath, "AreaTrigger.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sTaxiNodeStore5875, dbcPath, "TaxiNodes.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionStore5875, dbcPath, "Faction.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionTemplateStore5875, dbcPath, "FactionTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSpellStore5464, dbcPath, "Spell.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineAbilityStore5875, dbcPath, "SkillLineAbility.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sCreatureSpellDataStore5875, dbcPath, "CreatureSpellData.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sMailTemplateStore5875, dbcPath, "MailTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineStore5875, dbcPath, "SkillLine.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillRaceClassInfoStore5875, dbcPath, "SkillRaceClassInfo.dbc", true);

            CopyDbcStoreIntoVector<AreaTriggerEntry5875, AreaTriggerEntry5875>(sAreaTriggerStore5875, areaTriggerStore);
            CopyDbcStoreIntoVector<TaxiNodesEntry5875, TaxiNodesEntry5875>(sTaxiNodeStore5875, taxiNodesStore);
            CopyDbcStoreIntoVector<FactionEntry5875, FactionEntry5875>(sFactionStore5875, factionStore);
            CopyDbcStoreIntoVector<FactionTemplateEntry5875, FactionTemplateEntry5875>(sFactionTemplateStore5875, factionTemplateStore);
            CopyDbcStoreIntoVector<SpellEntry5464, SpellEntry5875>(sSpellStore5464, spellStore);
            CopyDbcStoreIntoVector<SkillLineAbilityEntry5875, SkillLineAbilityEntry5875>(sSkillLineAbilityStore5875, skillLineAbilityStore);
            CopyDbcStoreIntoVector<CreatureSpellDataEntry5875, CreatureSpellDataEntry5875>(sCreatureSpellDataStore5875, creatureSpellDataStore);
            CopyDbcStoreIntoVector<MailTemplateEntry5875, MailTemplateEntry5875>(sMailTemplateStore5875, mailTemplateStore);
            CopyDbcStoreIntoVector<SkillLineEntry5875, SkillLineEntry5875>(sSkillLineStore5875, skillLineStore);
            CopyDbcStoreIntoVector<SkillRaceClassInfoEntry5875, SkillRaceClassInfoEntry5875>(sSkillRaceClassInfoStore5875, skillRaceClassInfoStore);
            break;
        }
        case 5302:
        {
            printf("\nReading data from DBC files...\n");
            const uint32 DBCFilesCount = 10;
            BarGoLink bar(DBCFilesCount);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sAreaTriggerStore5875, dbcPath, "AreaTrigger.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sTaxiNodeStore5302, dbcPath, "TaxiNodes.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionStore5875, dbcPath, "Faction.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionTemplateStore5875, dbcPath, "FactionTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSpellStore5302, dbcPath, "Spell.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineAbilityStore5875, dbcPath, "SkillLineAbility.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sCreatureSpellDataStore5875, dbcPath, "CreatureSpellData.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sMailTemplateStore5875, dbcPath, "MailTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineStore5875, dbcPath, "SkillLine.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillRaceClassInfoStore5875, dbcPath, "SkillRaceClassInfo.dbc", true);

            CopyDbcStoreIntoVector<AreaTriggerEntry5875, AreaTriggerEntry5875>(sAreaTriggerStore5875, areaTriggerStore);
            CopyDbcStoreIntoVector<TaxiNodesEntry5302, TaxiNodesEntry5875>(sTaxiNodeStore5302, taxiNodesStore);
            CopyDbcStoreIntoVector<FactionEntry5875, FactionEntry5875>(sFactionStore5875, factionStore);
            CopyDbcStoreIntoVector<FactionTemplateEntry5875, FactionTemplateEntry5875>(sFactionTemplateStore5875, factionTemplateStore);
            CopyDbcStoreIntoVector<SpellEntry5302, SpellEntry5875>(sSpellStore5302, spellStore);
            CopyDbcStoreIntoVector<SkillLineAbilityEntry5875, SkillLineAbilityEntry5875>(sSkillLineAbilityStore5875, skillLineAbilityStore);
            CopyDbcStoreIntoVector<CreatureSpellDataEntry5875, CreatureSpellDataEntry5875>(sCreatureSpellDataStore5875, creatureSpellDataStore);
            CopyDbcStoreIntoVector<MailTemplateEntry5875, MailTemplateEntry5875>(sMailTemplateStore5875, mailTemplateStore);
            CopyDbcStoreIntoVector<SkillLineEntry5875, SkillLineEntry5875>(sSkillLineStore5875, skillLineStore);
            CopyDbcStoreIntoVector<SkillRaceClassInfoEntry5875, SkillRaceClassInfoEntry5875>(sSkillRaceClassInfoStore5875, skillRaceClassInfoStore);
            break;
        }
        case 5086:
        {
            printf("\nReading data from DBC files...\n");
            const uint32 DBCFilesCount = 9;
            BarGoLink bar(DBCFilesCount);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sAreaTriggerStore5875, dbcPath, "AreaTrigger.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sTaxiNodeStore5302, dbcPath, "TaxiNodes.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionStore5875, dbcPath, "Faction.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionTemplateStore5875, dbcPath, "FactionTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSpellStore5302, dbcPath, "Spell.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineAbilityStore5875, dbcPath, "SkillLineAbility.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sCreatureSpellDataStore5875, dbcPath, "CreatureSpellData.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineStore5875, dbcPath, "SkillLine.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillRaceClassInfoStore5875, dbcPath, "SkillRaceClassInfo.dbc", true);

            CopyDbcStoreIntoVector<AreaTriggerEntry5875, AreaTriggerEntry5875>(sAreaTriggerStore5875, areaTriggerStore);
            CopyDbcStoreIntoVector<TaxiNodesEntry5302, TaxiNodesEntry5875>(sTaxiNodeStore5302, taxiNodesStore);
            CopyDbcStoreIntoVector<FactionEntry5875, FactionEntry5875>(sFactionStore5875, factionStore);
            CopyDbcStoreIntoVector<FactionTemplateEntry5875, FactionTemplateEntry5875>(sFactionTemplateStore5875, factionTemplateStore);
            CopyDbcStoreIntoVector<SpellEntry5302, SpellEntry5875>(sSpellStore5302, spellStore);
            CopyDbcStoreIntoVector<SkillLineAbilityEntry5875, SkillLineAbilityEntry5875>(sSkillLineAbilityStore5875, skillLineAbilityStore);
            CopyDbcStoreIntoVector<CreatureSpellDataEntry5875, CreatureSpellDataEntry5875>(sCreatureSpellDataStore5875, creatureSpellDataStore);
            CopyDbcStoreIntoVector<SkillLineEntry5875, SkillLineEntry5875>(sSkillLineStore5875, skillLineStore);
            CopyDbcStoreIntoVector<SkillRaceClassInfoEntry5875, SkillRaceClassInfoEntry5875>(sSkillRaceClassInfoStore5875, skillRaceClassInfoStore);
            break;
        }
        case 4878:
        {
            printf("\nReading data from DBC files...\n");
            const uint32 DBCFilesCount = 9;
            BarGoLink bar(DBCFilesCount);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sAreaTriggerStore5875, dbcPath, "AreaTrigger.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sTaxiNodeStore5302, dbcPath, "TaxiNodes.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionStore5875, dbcPath, "Faction.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionTemplateStore5875, dbcPath, "FactionTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSpellStore4878, dbcPath, "Spell.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineAbilityStore5875, dbcPath, "SkillLineAbility.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sCreatureSpellDataStore5875, dbcPath, "CreatureSpellData.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineStore5875, dbcPath, "SkillLine.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillRaceClassInfoStore5875, dbcPath, "SkillRaceClassInfo.dbc", true);

            CopyDbcStoreIntoVector<AreaTriggerEntry5875, AreaTriggerEntry5875>(sAreaTriggerStore5875, areaTriggerStore);
            CopyDbcStoreIntoVector<TaxiNodesEntry5302, TaxiNodesEntry5875>(sTaxiNodeStore5302, taxiNodesStore);
            CopyDbcStoreIntoVector<FactionEntry5875, FactionEntry5875>(sFactionStore5875, factionStore);
            CopyDbcStoreIntoVector<FactionTemplateEntry5875, FactionTemplateEntry5875>(sFactionTemplateStore5875, factionTemplateStore);
            CopyDbcStoreIntoVector<SpellEntry4878, SpellEntry5875>(sSpellStore4878, spellStore);
            CopyDbcStoreIntoVector<SkillLineAbilityEntry5875, SkillLineAbilityEntry5875>(sSkillLineAbilityStore5875, skillLineAbilityStore);
            CopyDbcStoreIntoVector<CreatureSpellDataEntry5875, CreatureSpellDataEntry5875>(sCreatureSpellDataStore5875, creatureSpellDataStore);
            CopyDbcStoreIntoVector<SkillLineEntry5875, SkillLineEntry5875>(sSkillLineStore5875, skillLineStore);
            CopyDbcStoreIntoVector<SkillRaceClassInfoEntry5875, SkillRaceClassInfoEntry5875>(sSkillRaceClassInfoStore5875, skillRaceClassInfoStore);
            break;
        }
        case 4695:
        case 4544:
        {
            printf("\nReading data from DBC files...\n");
            const uint32 DBCFilesCount = 8;
            BarGoLink bar(DBCFilesCount);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sAreaTriggerStore5875, dbcPath, "AreaTrigger.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sTaxiNodeStore5302, dbcPath, "TaxiNodes.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionStore5875, dbcPath, "Faction.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionTemplateStore5875, dbcPath, "FactionTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSpellStore4695, dbcPath, "Spell.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineAbilityStore5875, dbcPath, "SkillLineAbility.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineStore5875, dbcPath, "SkillLine.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillRaceClassInfoStore5875, dbcPath, "SkillRaceClassInfo.dbc", true);

            CopyDbcStoreIntoVector<AreaTriggerEntry5875, AreaTriggerEntry5875>(sAreaTriggerStore5875, areaTriggerStore);
            CopyDbcStoreIntoVector<TaxiNodesEntry5302, TaxiNodesEntry5875>(sTaxiNodeStore5302, taxiNodesStore);
            CopyDbcStoreIntoVector<FactionEntry5875, FactionEntry5875>(sFactionStore5875, factionStore);
            CopyDbcStoreIntoVector<FactionTemplateEntry5875, FactionTemplateEntry5875>(sFactionTemplateStore5875, factionTemplateStore);
            CopyDbcStoreIntoVector<SpellEntry4695, SpellEntry5875>(sSpellStore4695, spellStore);
            CopyDbcStoreIntoVector<SkillLineAbilityEntry5875, SkillLineAbilityEntry5875>(sSkillLineAbilityStore5875, skillLineAbilityStore);
            CopyDbcStoreIntoVector<SkillLineEntry5875, SkillLineEntry5875>(sSkillLineStore5875, skillLineStore);
            CopyDbcStoreIntoVector<SkillRaceClassInfoEntry5875, SkillRaceClassInfoEntry5875>(sSkillRaceClassInfoStore5875, skillRaceClassInfoStore);
            break;
        }
        case 4449:
        case 4375:
        {
            printf("\nReading data from DBC files...\n");
            const uint32 DBCFilesCount = 8;
            BarGoLink bar(DBCFilesCount);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sAreaTriggerStore5875, dbcPath, "AreaTrigger.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sTaxiNodeStore5302, dbcPath, "TaxiNodes.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionStore5875, dbcPath, "Faction.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionTemplateStore5875, dbcPath, "FactionTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSpellStore4449, dbcPath, "Spell.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineAbilityStore5875, dbcPath, "SkillLineAbility.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineStore5875, dbcPath, "SkillLine.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillRaceClassInfoStore5875, dbcPath, "SkillRaceClassInfo.dbc", true);

            CopyDbcStoreIntoVector<AreaTriggerEntry5875, AreaTriggerEntry5875>(sAreaTriggerStore5875, areaTriggerStore);
            CopyDbcStoreIntoVector<TaxiNodesEntry5302, TaxiNodesEntry5875>(sTaxiNodeStore5302, taxiNodesStore);
            CopyDbcStoreIntoVector<FactionEntry5875, FactionEntry5875>(sFactionStore5875, factionStore);
            CopyDbcStoreIntoVector<FactionTemplateEntry5875, FactionTemplateEntry5875>(sFactionTemplateStore5875, factionTemplateStore);
            CopyDbcStoreIntoVector<SpellEntry4449, SpellEntry5875>(sSpellStore4449, spellStore);
            CopyDbcStoreIntoVector<SkillLineAbilityEntry5875, SkillLineAbilityEntry5875>(sSkillLineAbilityStore5875, skillLineAbilityStore);
            CopyDbcStoreIntoVector<SkillLineEntry5875, SkillLineEntry5875>(sSkillLineStore5875, skillLineStore);
            CopyDbcStoreIntoVector<SkillRaceClassInfoEntry5875, SkillRaceClassInfoEntry5875>(sSkillRaceClassInfoStore5875, skillRaceClassInfoStore);
            break;
        }
        case 4297:
        case 4222:
        {
            printf("\nReading data from DBC files...\n");
            const uint32 DBCFilesCount = 8;
            BarGoLink bar(DBCFilesCount);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sAreaTriggerStore5875, dbcPath, "AreaTrigger.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sTaxiNodeStore5302, dbcPath, "TaxiNodes.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionStore4297, dbcPath, "Faction.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sFactionTemplateStore5875, dbcPath, "FactionTemplate.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSpellStore4297, dbcPath, "Spell.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineAbilityStore5875, dbcPath, "SkillLineAbility.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillLineStore5875, dbcPath, "SkillLine.dbc", true);
            LoadDBC(availableDbcLocales, bar, bad_dbc_files, sSkillRaceClassInfoStore5875, dbcPath, "SkillRaceClassInfo.dbc", true);

            CopyDbcStoreIntoVector<AreaTriggerEntry5875, AreaTriggerEntry5875>(sAreaTriggerStore5875, areaTriggerStore);
            CopyDbcStoreIntoVector<TaxiNodesEntry5302, TaxiNodesEntry5875>(sTaxiNodeStore5302, taxiNodesStore);
            CopyDbcStoreIntoVector<FactionEntry4297, FactionEntry5875>(sFactionStore4297, factionStore);
            CopyDbcStoreIntoVector<FactionTemplateEntry5875, FactionTemplateEntry5875>(sFactionTemplateStore5875, factionTemplateStore);
            CopyDbcStoreIntoVector<SpellEntry4297, SpellEntry5875>(sSpellStore4297, spellStore);
            CopyDbcStoreIntoVector<SkillLineAbilityEntry5875, SkillLineAbilityEntry5875>(sSkillLineAbilityStore5875, skillLineAbilityStore);
            CopyDbcStoreIntoVector<SkillLineEntry5875, SkillLineEntry5875>(sSkillLineStore5875, skillLineStore);
            CopyDbcStoreIntoVector<SkillRaceClassInfoEntry5875, SkillRaceClassInfoEntry5875>(sSkillRaceClassInfoStore5875, skillRaceClassInfoStore);
            break;
        }
        default:
        {
            printf("Unsupported build.\n");
        }
    }
}

std::pair<std::string, uint32> GetDbcPathAndBuild()
{
    printf("Path: ");
    std::string dbcPath = GetString("dbc/");

    printf("Build: ");
    std::string buildString = GetString("5875");

    uint32 build = strtoul(buildString.c_str(), NULL, 0);

    return std::make_pair(dbcPath, build);
}

void ExportAllDbcFilesToSql()
{
    std::string dbcPath;
    uint32 build;
    std::tie(dbcPath, build) = GetDbcPathAndBuild();

    std::vector<AreaTriggerEntry5875*> areaTriggerStore;
    std::vector<TaxiNodesEntry5875*> taxiNodesStore;
    std::vector<FactionEntry5875*> factionStore;
    std::vector<FactionTemplateEntry5875*> factionTemplateStore;
    std::vector<SpellEntry5875*> spellStore;
    std::vector<SkillLineAbilityEntry5875*> skillLineAbilityStore;
    std::vector<CreatureSpellDataEntry5875*> creatureSpellDataStore;
    std::vector<MailTemplateEntry5875*> mailTemplateStore;
    std::vector<SkillLineEntry5875*> skillLineStore;
    std::vector<SkillRaceClassInfoEntry5875*> skillRaceClassInfoStore;

    LoadAllDbcFiles(build, dbcPath, areaTriggerStore, taxiNodesStore, factionStore, factionTemplateStore, spellStore, skillLineAbilityStore, creatureSpellDataStore, mailTemplateStore, skillLineStore, skillRaceClassInfoStore);
    ExportToSqlFile(build, "areatrigger_template.sql", "areatrigger_template", areaTriggerStore);
    ExportToSqlFile(build, "faction.sql", "faction", factionStore);
    ExportToSqlFile(build, "faction_template.sql", "faction_template", factionTemplateStore);
    ExportToSqlFile(build, "spell_template.sql", "spell_template", spellStore);
    ExportToSqlFile(build, "skill_line_ability.sql", "skill_line_ability", skillLineAbilityStore);
    ExportToSqlFile(build, "taxi_nodes.sql", "taxi_nodes", taxiNodesStore);
    ExportToSqlFile(build, "pet_spell_data.sql", "pet_spell_data", creatureSpellDataStore);
    ExportToSqlFile(build, "mail_template.sql", "mail_template", mailTemplateStore);
    ExportToSqlFile(build, "skill_line.sql", "skill_line", skillLineStore);
    ExportToSqlFile(build, "skill_race_class_info.sql", "skill_race_class_info", skillRaceClassInfoStore);
}

template <class T>
void CompareDbcStores(std::vector<T*> store1, std::vector<T*> store2, std::set<size_t>& added, std::set<size_t>& removed, std::set<size_t>& changed)
{
    size_t count = std::min(store1.size(), store2.size());
    for (size_t i = 0; i < count; i++)
    {
        if (store1[i] && !store2[i])
            removed.insert(i);
        else if (!store1[i] && store2[i])
            added.insert(i);
        else if (store1[i] && store2[i] && (*store1[i]) != (*store2[i]))
            changed.insert(i);
    }

    if (store1.size() > store2.size())
    {
        for (size_t i = store2.size(); i < store1.size(); i++)
        {
            if (store1[i])
                removed.insert(i);
        }
    }
    else if (store2.size() > store1.size())
    {
        for (size_t i = store1.size(); i < store2.size(); i++)
        {
            if (store2[i])
                added.insert(i);
        }
    }

    printf("Added: %u\n", (uint32)added.size());
    printf("Removed: %u\n", (uint32)removed.size());
    printf("Changed: %u\n", (uint32)changed.size());
}

void CompareDBCs()
{
    std::string dbcPath1, dbcPath2;
    uint32 build1, build2;
    std::tie(dbcPath1, build1) = GetDbcPathAndBuild();
    std::tie(dbcPath2, build2) = GetDbcPathAndBuild();

    std::vector<AreaTriggerEntry5875*> areaTriggerStore1, areaTriggerStore2;
    std::vector<TaxiNodesEntry5875*> taxiNodesStore1, taxiNodesStore2;
    std::vector<FactionEntry5875*> factionStore1, factionStore2;
    std::vector<FactionTemplateEntry5875*> factionTemplateStore1, factionTemplateStore2;
    std::vector<SpellEntry5875*> spellStore1, spellStore2;
    std::vector<SkillLineAbilityEntry5875*> skillLineAbilityStore1, skillLineAbilityStore2;
    std::vector<CreatureSpellDataEntry5875*> creatureSpellDataStore1, creatureSpellDataStore2;
    std::vector<MailTemplateEntry5875*> mailTemplateStore1, mailTemplateStore2;
    std::vector<SkillLineEntry5875*> skillLineStore1, skillLineStore2;
    std::vector<SkillRaceClassInfoEntry5875*> skillRaceClassInfoStore1, skillRaceClassInfoStore2;

    printf("Loading dbcs from %s\n", dbcPath1.c_str());
    LoadAllDbcFiles(build1, dbcPath1, areaTriggerStore1, taxiNodesStore1, factionStore1, factionTemplateStore1, spellStore1, skillLineAbilityStore1, creatureSpellDataStore1, mailTemplateStore1, skillLineStore1, skillRaceClassInfoStore1);
    printf("Loading dbcs from %s\n", dbcPath2.c_str());
    LoadAllDbcFiles(build2, dbcPath2, areaTriggerStore2, taxiNodesStore2, factionStore2, factionTemplateStore2, spellStore2, skillLineAbilityStore2, creatureSpellDataStore2, mailTemplateStore2, skillLineStore2, skillRaceClassInfoStore2);

    printf("Do you want to write hotfixes? ");
    bool hotfix = GetChar() == 'y';

    printf("Select dbc to compare:\n");
    printf(" 1. AreaTrigger\n");
    printf(" 2. TaxiNodes\n");
    printf(" 3. Faction\n");
    printf(" 4. FactionTemplate\n");
    printf(" 5. Spell\n");
    printf(" 6. SkillLineAbility\n");
    printf(" 7. CreatureSpellData\n");
    printf(" 8. MailTemplate\n");
    printf(" 9. SkillLine\n");
    printf("10. SkillRaceClassInfo\n");
    printf("> ");

    std::set<size_t> added;
    std::set<size_t> removed;
    std::set<size_t> changed;

    uint32 option = GetUInt32();
    switch (option)
    {
        case 1:
            CompareDbcStores(areaTriggerStore1, areaTriggerStore2, added, removed, changed);
            break;
        case 2:
            CompareDbcStores(taxiNodesStore1, taxiNodesStore2, added, removed, changed);
            break;
        case 3:
            CompareDbcStores(factionStore1, factionStore2, added, removed, changed);
            break;
        case 4:
            CompareDbcStores(factionTemplateStore1, factionTemplateStore2, added, removed, changed);
            break;
        case 5:
            CompareDbcStores(spellStore1, spellStore2, added, removed, changed);
            break;
        case 6:
            CompareDbcStores(skillLineAbilityStore1, skillLineAbilityStore2, added, removed, changed);
            break;
        case 7:
            CompareDbcStores(creatureSpellDataStore1, creatureSpellDataStore2, added, removed, changed);
            break;
        case 8:
            CompareDbcStores(mailTemplateStore1, mailTemplateStore2, added, removed, changed);
            break;
        case 9:
            CompareDbcStores(skillLineStore1, skillLineStore2, added, removed, changed);
            if (hotfix)
            {
                std::set<uint32> exports;
                for (auto id : changed)
                    exports.insert(id);
                for (auto id : added)
                    exports.insert(id);
                ExportSkillLineHotfixes(exports, skillLineStore2);
            }
            break;
        case 10:
            CompareDbcStores(skillRaceClassInfoStore1, skillRaceClassInfoStore2, added, removed, changed);
            if (hotfix)
            {
                std::set<uint32> exports;
                for (auto id : changed)
                    exports.insert(id);
                for (auto id : added)
                    exports.insert(id);
                ExportSkillRaceClassInfoHotfixes(exports, skillRaceClassInfoStore2);
            }
            break;
        default:
            printf("Invalid selection.");
            break;
    }
}

int main()
{
    StoreProblemList bad_dbc_files;
    uint32 availableDbcLocales = 0xFFFFFFFF;
    
    printf("This tool converts the needed dbc storages into sql files. \n");
    printf("Please enter the path to the dbc files and the build they are from.\n\n");

    printf("1. Export to SQL\n");
    printf("2. Compare versions\n");
    uint32 option = GetUInt32();

    switch (option)
    {
        case 1:
        {
            ExportAllDbcFilesToSql();
            break;
        }
        case 2:
        {
            CompareDBCs();
            break;
        }
        default:
        {
            printf("Invalid selection.");
            return 1;
        }
    }

    printf("Done.\n");
    GetChar();
    return 0;
}