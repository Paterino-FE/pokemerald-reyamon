#include "global.h"
#include "pokemon.h"
#include "../include/constants/species.h"
#include "party_menu.h"
#include "rotom_form_change.h"
#include "string_util.h"
#include "event_data.h"
#include "pokedex.h"
#include "sound.h"
#include "constants/moves.h"

static const u16 sRotomFormChangeMoves[5] =
{
    MOVE_OVERHEAT,
    MOVE_HYDRO_PUMP,
    MOVE_BLIZZARD,
    MOVE_AIR_SLASH,
    MOVE_LEAF_STORM,
};

static bool8 IsRotomSpecies(u16 species)
{
    switch (species)
    {
    case SPECIES_ROTOM:
    case SPECIES_ROTOM_HEAT:
    case SPECIES_ROTOM_WASH:
    case SPECIES_ROTOM_FROST:
    case SPECIES_ROTOM_FAN:
    case SPECIES_ROTOM_MOW:
        return TRUE;
    default:
        return FALSE;
    }
}

static u8 GetRotomPartyIndex(void)
{
    u8 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if(IsRotomSpecies(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG, NULL))){
            return i;
        }
    }
    return PARTY_SIZE;
}

bool8 IsRotomInParty(void)
{
    return GetRotomPartyIndex() != PARTY_SIZE;
}

static void ApplyRotomFormChange(struct Pokemon *mon, u16 newSpecies)
{
    u16 oldSpecies = GetMonData(mon, MON_DATA_SPECIES_OR_EGG, NULL);
    if (oldSpecies == newSpecies)
        return;

    
    SetMonData(mon, MON_DATA_SPECIES, &newSpecies);
    CalculateMonStats(mon);
    EvolutionRenameMon(mon, oldSpecies, newSpecies);
    
    u16 newFormMove = MOVE_NONE;
    switch (newSpecies)
    {
        case SPECIES_ROTOM_HEAT:  newFormMove = MOVE_OVERHEAT;   break;
        case SPECIES_ROTOM_WASH:  newFormMove = MOVE_HYDRO_PUMP; break;
        case SPECIES_ROTOM_FROST: newFormMove = MOVE_BLIZZARD;   break;
        case SPECIES_ROTOM_FAN:   newFormMove = MOVE_AIR_SLASH;  break;
        case SPECIES_ROTOM_MOW:   newFormMove = MOVE_LEAF_STORM; break;
    }

    u32 i;
    for (i = 0; i < ARRAY_COUNT(sRotomFormChangeMoves); i++){
        DeleteMove(mon, sRotomFormChangeMoves[i]);
    }
    if(newFormMove != MOVE_NONE){
        if (GiveMoveToMon(mon, newFormMove) == MON_HAS_MAX_MOVES){
            SetMonData(mon, MON_DATA_MOVE1, &newFormMove);
        }
    }

    GetSetPokedexFlag(SpeciesToNationalPokedexNum(newSpecies), FLAG_SET_SEEN);
    GetSetPokedexFlag(SpeciesToNationalPokedexNum(newSpecies), FLAG_SET_CAUGHT);
    PlayCry_ByMode(newSpecies, 0, CRY_MODE_NORMAL);
}

/**
 * Changes the form of Rotom in the player's party.
 * formId:
 *   0 = Normal
 *   1 = Heat
 *   2 = Wash
 *   3 = Frost
 *   4 = Fan
 *   5 = Mow
 *
 * Returns TRUE if successful, FALSE otherwise.
 */
bool8 TryChangeRotomForm(void)
{
    u8 formId = gSpecialVar_0x8004;
    u8 rotomIndex = GetRotomPartyIndex();
    if (rotomIndex >= PARTY_SIZE)
        return FALSE; // No Rotom in party

    u16 newSpecies;
    switch (formId)
    {
    default:
    case 0: newSpecies = SPECIES_ROTOM; break;
    case 1: newSpecies = SPECIES_ROTOM_HEAT; break;
    case 2: newSpecies = SPECIES_ROTOM_WASH; break;
    case 3: newSpecies = SPECIES_ROTOM_FROST; break;
    case 4: newSpecies = SPECIES_ROTOM_FAN; break;
    case 5: newSpecies = SPECIES_ROTOM_MOW; break;
    }

    struct Pokemon *rotom = &gPlayerParty[rotomIndex];
    if (!IsRotomSpecies(GetMonData(rotom, MON_DATA_SPECIES_OR_EGG, NULL)))
        return FALSE;

    ApplyRotomFormChange(rotom, newSpecies);

    return TRUE;
}