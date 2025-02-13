#ifndef H_DB2DATA
#define H_DB2DATA

#include "Common.h"
#include "csv.h"
#include <map>

namespace DB2Data
{
    namespace Classic
    {
        extern uint32 g_maxSpellXSpellVisualId;
        extern std::map<uint32, uint32> g_db2SpellXSpellVisual;
    };
    namespace TBC
    {
        extern uint32 g_maxSpellXSpellVisualId;
        extern std::map<uint32, uint32> g_db2SpellXSpellVisual;
    };

    inline void LoadSpellXSpellVisual(std::map<uint32, uint32>& data, uint32& maxId, char const* name)
    {
        io::CSVReader<2> in(name);
        in.read_header(io::ignore_extra_column, "SpellId", "SpellXSpellVisualId");
        uint32 spellId, visualId;
        while (in.read_row(spellId, visualId))
        {
            data.insert(std::make_pair(spellId, visualId));

            if (visualId > maxId)
                maxId = visualId;
        }
    }

    inline uint32 GetSpellXSpellVisualId(uint32 spellId)
    {
        auto itr1 = Classic::g_db2SpellXSpellVisual.find(spellId);
        if (itr1 != Classic::g_db2SpellXSpellVisual.end())
            return itr1->second;

        auto itr2 = TBC::g_db2SpellXSpellVisual.find(spellId);
        if (itr2 != TBC::g_db2SpellXSpellVisual.end())
            return itr2->second;

        uint32 maxId = Classic::g_maxSpellXSpellVisualId;
        Classic::g_db2SpellXSpellVisual.insert(std::make_pair(spellId, maxId + spellId));
        return maxId + spellId;
    }
};

#endif