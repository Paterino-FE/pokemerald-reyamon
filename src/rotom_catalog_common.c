// src/rotom_catalog_common.c
#include "global.h"
#include "pokemon.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "rotom_catalog_common.h"

// Returns TRUE if species id is any Rotom form in your build.
static bool8 IsRotomAnyForm(u16 species)
{
    return (species == SPECIES_ROTOM
         || species == SPECIES_ROTOM_HEAT
         || species == SPECIES_ROTOM_WASH
         || species == SPECIES_ROTOM_FROST
         || species == SPECIES_ROTOM_FAN
         || species == SPECIES_ROTOM_MOW);
}

// Teach/cleanup Rotom signature moves for the target species
static void SyncRotomSignatureMove(struct Pokemon *mon, u16 targetSpecies)
{
    // remove signature moves
    for (int i = 0; i < MAX_MON_MOVES; ++i)
    {
        u16 mv = GetMonData(mon, MON_DATA_MOVE1 + i);
        if (mv == MOVE_OVERHEAT || mv == MOVE_HYDRO_PUMP || mv == MOVE_BLIZZARD
         || mv == MOVE_AIR_SLASH || mv == MOVE_LEAF_STORM)
        {
            u16 none = MOVE_NONE;
            u8  zero = 0;
            SetMonData(mon, MON_DATA_MOVE1 + i, &none);
            SetMonData(mon, MON_DATA_PP1   + i, &zero);
        }
    }

    u16 give = MOVE_NONE;
    switch (targetSpecies)
    {
    case SPECIES_ROTOM_HEAT:  give = MOVE_OVERHEAT;   break;
    case SPECIES_ROTOM_WASH:  give = MOVE_HYDRO_PUMP; break;
    case SPECIES_ROTOM_FROST: give = MOVE_BLIZZARD;   break;
    case SPECIES_ROTOM_FAN:   give = MOVE_AIR_SLASH;  break;
    case SPECIES_ROTOM_MOW:   give = MOVE_LEAF_STORM; break;
    default: break;
    }

    if (give != MOVE_NONE)
    {
        GiveMoveToMon(mon, give);      // fills an empty slot, sets PP
        bool8 has = FALSE;
        for (int i = 0; i < MAX_MON_MOVES; ++i)
            if (GetMonData(mon, MON_DATA_MOVE1 + i) == give)
                has = TRUE;
        if (!has)
            SetMonMoveSlot(mon, give, 0);  // overwrite slot 0 if needed
    }
}

// Public helper used by item path and events.
// form: 0=Normal,1=Heat,2=Wash,3=Frost,4=Fan,5=Mow
// Returns TRUE on success, FALSE if not a Rotom or args invalid.
bool8 ApplyRotomCatalogToMon(struct Pokemon *mon, u8 form)
{
    if (mon == NULL || form > 5)
        return FALSE;

    #ifdef MON_DATA_SPECIES2
    u16 cur = GetMonData(mon, MON_DATA_SPECIES2);
    #else
    u16 cur = GetMonData(mon, MON_DATA_SPECIES);
    #endif

    if (!IsRotomAnyForm(cur))
        return FALSE;

    static const u16 sFormSpecies[6] = {
        SPECIES_ROTOM, SPECIES_ROTOM_HEAT, SPECIES_ROTOM_WASH,
        SPECIES_ROTOM_FROST, SPECIES_ROTOM_FAN,  SPECIES_ROTOM_MOW
    };
    u16 target = sFormSpecies[form];

    if (target == cur)
        return TRUE; // already in that form

    #if defined(MON_DATA_FORM)
    {
        s8 f = -1;
        switch (target) {
        case SPECIES_ROTOM:       f = 0; break;
        case SPECIES_ROTOM_HEAT:  f = 1; break;
        case SPECIES_ROTOM_WASH:  f = 2; break;
        case SPECIES_ROTOM_FROST: f = 3; break;
        case SPECIES_ROTOM_FAN:   f = 4; break;
        case SPECIES_ROTOM_MOW:   f = 5; break;
        }
        if (f >= 0)
            SetMonData(mon, MON_DATA_FORM, &f);
    }
    #endif

    SetMonData(mon, MON_DATA_SPECIES, &target);
    SyncRotomSignatureMove(mon, target);
    CalculateMonStats(mon);
    return TRUE;
}
