#include "global.h"
#include "pokemon.h"
#include "event_data.h"
#include "constants/species.h"
#include "constants/moves.h"

// Script vars:
// VAR_0x8004 = party slot (from ChoosePartyMon)
// VAR_0x8005 = form index: 0=Normal,1=Heat,2=Wash,3=Frost,4=Fan,5=Mow

// DECLARE whichever worker your item uses (adjust the signature/name!)
// Examples you might find in your tree:
//
// extern bool8 TryChangeRotomForm(struct Pokemon *mon, u8 formIndex);
// extern void  SetMonForm(struct Pokemon *mon, u16 targetSpecies);
// extern bool8 FormChange_RotomCatalog(struct Pokemon *mon, u8 formIndex);
//
// If it's a static function, copy its few lines into this file instead.

void OW_RotomCatalog_ApplyForm(void)
{
    u8 slot = VarGet(VAR_0x8004);
    u8 form = VarGet(VAR_0x8005);

    // normalize 1..6 -> 0..5 if your ChoosePartyMon is 1-based
    if (slot >= 1 && slot <= PARTY_SIZE) slot--;

    if (slot >= PARTY_SIZE || form > 5) {
        VarSet(VAR_RESULT, 0);   // invalid args
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];

    // ---- Replace the next block with the SAME call your item uses ----
    // Example if you have a direct form changer:
    // bool8 ok = TryChangeRotomForm(mon, form);
    // VarSet(VAR_RESULT, ok ? 1 : 0);
    //
    // Example if your worker takes a species target:
    static const u16 sFormSpecies[6] = {
        SPECIES_ROTOM, SPECIES_ROTOM_HEAT, SPECIES_ROTOM_WASH,
        SPECIES_ROTOM_FROST, SPECIES_ROTOM_FAN,  SPECIES_ROTOM_MOW
    };
    u16 target = sFormSpecies[form];

    // If your item path uses SetMonForm(mon, targetSpecies):
    // SetMonForm(mon, target);

    // Fallback: do the same as the item (teach signature move, recalc). If the item has a helper for that, call it instead:
    SetMonData(mon, MON_DATA_SPECIES, &target);
    // teach / clean up moves exactly like the item does (or copy that logic verbatim)
    CalculateMonStats(mon);

    VarSet(VAR_RESULT, 1);
}
