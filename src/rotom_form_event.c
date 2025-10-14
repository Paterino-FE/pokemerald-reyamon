// src/rotom_form_event.c
#include "global.h"
#include "pokemon.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/pokedex.h"   // NATIONAL_DEX_ROTOM
#include "event_data.h"

// Script vars:
// VAR_0x8004 -> party slot (set by ChoosePartyMon)
// VAR_0x8006 -> target species (set by the object script)
#define V_SLOT VAR_0x8004
#define V_SPEC VAR_0x8006

// ---------- helpers (placed BEFORE main fn to avoid implicit decls) ----------

static bool8 MonKnowsMove(struct Pokemon *mon, u16 moveId)
{
    for (int i = 0; i < MAX_MON_MOVES; i++)
        if (GetMonData(mon, MON_DATA_MOVE1 + i) == moveId)
            return TRUE;
    return FALSE;
}

static void MonDeleteMove(struct Pokemon *mon, u16 moveId)
{
    u16 moves[MAX_MON_MOVES];
    u8 pps[MAX_MON_MOVES];
    int w = 0;

    for (int i = 0; i < MAX_MON_MOVES; i++) {
        moves[i] = GetMonData(mon, MON_DATA_MOVE1 + i);
        pps[i]   = GetMonData(mon, MON_DATA_PP1   + i);
    }
    for (int i = 0; i < MAX_MON_MOVES; i++) {
        if (moves[i] != moveId && moves[i] != MOVE_NONE) {
            moves[w] = moves[i];
            pps[w]   = pps[i];
            w++;
        }
    }
    while (w < MAX_MON_MOVES) { moves[w] = MOVE_NONE; pps[w] = 0; w++; }

    for (int i = 0; i < MAX_MON_MOVES; i++) {
        SetMonData(mon, MON_DATA_MOVE1 + i, &moves[i]);
        SetMonData(mon, MON_DATA_PP1   + i, &pps[i]);
    }
}

static void RemoveAllRotomSigMoves(struct Pokemon *mon)
{
    MonDeleteMove(mon, MOVE_OVERHEAT);
    MonDeleteMove(mon, MOVE_HYDRO_PUMP);
    MonDeleteMove(mon, MOVE_BLIZZARD);
    MonDeleteMove(mon, MOVE_AIR_SLASH);
    MonDeleteMove(mon, MOVE_LEAF_STORM);
}

static u16 RotomSigMoveForSpecies(u16 species)
{
    switch (species)
    {
    case SPECIES_ROTOM_HEAT:  return MOVE_OVERHEAT;
    case SPECIES_ROTOM_WASH:  return MOVE_HYDRO_PUMP;
    case SPECIES_ROTOM_FROST: return MOVE_BLIZZARD;
    case SPECIES_ROTOM_FAN:   return MOVE_AIR_SLASH;
    case SPECIES_ROTOM_MOW:   return MOVE_LEAF_STORM;
    default:                  return MOVE_NONE;
    }
}

static void TeachMovePreferAddElseReplaceFirst(struct Pokemon *mon, u16 moveId)
{
    if (moveId == MOVE_NONE || MonKnowsMove(mon, moveId))
        return;

    // Try to add (auto-sets PP if a free slot exists)
    GiveMoveToMon(mon, moveId);

    // If still not known (no free slot), overwrite slot 0 silently
    if (!MonKnowsMove(mon, moveId))
        SetMonMoveSlot(mon, moveId, 0);
}

// (Optional) keep MON_DATA_FORM consistent if your fork uses it
#if defined(MON_DATA_FORM)
static s8 FormFromRotomSpecies(u16 species)
{
    switch (species) {
    case SPECIES_ROTOM:       return 0;
    case SPECIES_ROTOM_HEAT:  return 1;
    case SPECIES_ROTOM_WASH:  return 2;
    case SPECIES_ROTOM_FROST: return 3;
    case SPECIES_ROTOM_FAN:   return 4;
    case SPECIES_ROTOM_MOW:   return 5;
    default:                  return -1;
    }
}
#endif

// Robust “is this Rotom?”: direct species OR (fallback) NatDex check.
static bool8 IsSpeciesRotomAnyForm(u16 species)
{
    if (species == SPECIES_ROTOM
     || species == SPECIES_ROTOM_HEAT
     || species == SPECIES_ROTOM_WASH
     || species == SPECIES_ROTOM_FROST
     || species == SPECIES_ROTOM_FAN
     || species == SPECIES_ROTOM_MOW)
        return TRUE;

    #ifdef NATIONAL_DEX_ROTOM
    {
        u16 natdex = SpeciesToNationalPokedexNum(species);
        if (natdex == NATIONAL_DEX_ROTOM)
            return TRUE;
    }
    #endif

    return FALSE;
}

// ---------- main callnative ----------
//
// VAR_0x8004 = party slot from ChoosePartyMon (may be 1..6 or 0..5 depending on fork)
// VAR_0x8006 = target species
// VAR_RESULT = 0 not Rotom, 1 changed, 2 already that form
//
void Rotom_ChangeForm_ToTargetSpecies(void)
{
    u8  slotRaw = VarGet(VAR_0x8004);
    u16 target  = VarGet(VAR_0x8006);

    // Normalize slot: some forks return 1..6
    u8 slot = (slotRaw >= 1 && slotRaw <= PARTY_SIZE) ? (slotRaw - 1) : slotRaw;

    if (slot >= PARTY_SIZE || target == SPECIES_NONE) {
        VarSet(VAR_RESULT, 0);
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];

    // Get current species (SPECIES2 if present; fallback to SPECIES)
    #ifdef MON_DATA_SPECIES2
    u16 cur = GetMonData(mon, MON_DATA_SPECIES2);
    #else
    u16 cur = GetMonData(mon, MON_DATA_SPECIES);
    #endif

    // Optional breadcrumbs for one-time debugging
    VarSet(VAR_0x8005, slot);
    VarSet(VAR_0x8006, cur);

    if (cur == target) {
        VarSet(VAR_RESULT, 2);   // already in that form
        return;
    }

    // Apply species unconditionally (so we can verify the change path works)
    SetMonData(mon, MON_DATA_SPECIES, &target);

    // If your fork has MON_DATA_FORM, keep it aligned (guarded so it compiles everywhere)
    #if defined(MON_DATA_FORM)
    {
        s8 form = -1;
        switch (target) {
        case SPECIES_ROTOM:       form = 0; break;
        case SPECIES_ROTOM_HEAT:  form = 1; break;
        case SPECIES_ROTOM_WASH:  form = 2; break;
        case SPECIES_ROTOM_FROST: form = 3; break;
        case SPECIES_ROTOM_FAN:   form = 4; break;
        case SPECIES_ROTOM_MOW:   form = 5; break;
        }
        if (form >= 0)
            SetMonData(mon, MON_DATA_FORM, &form);
    }
    #endif

    // Refresh signature move
    RemoveAllRotomSigMoves(mon);
    TeachMovePreferAddElseReplaceFirst(mon, RotomSigMoveForSpecies(target));

    CalculateMonStats(mon);

    VarSet(VAR_RESULT, 1);       // changed successfully
}
