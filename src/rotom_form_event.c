// src/rotom_form_event.c
#include "global.h"
#include "pokemon.h"
#include "constants/species.h"
#include "event_data.h"                 // << VarGet / VarSet
#include "rotom_catalog_common.h"       // ApplyRotomCatalogToMon

// VAR_0x8004 = party slot (from ChoosePartyMon)  [0..5 or 1..6]
// VAR_0x8005 = form index: 0=Normal,1=Heat,2=Wash,3=Frost,4=Fan,5=Mow
// VAR_RESULT = 0 failed | 1 changed/ok
void Rotom_ApplyForm_CatalogStyle(void)
{
    u8 slot = VarGet(VAR_0x8004);
    u8 form = VarGet(VAR_0x8005);

    if (slot >= 1 && slot <= PARTY_SIZE)
        slot--;                        // normalize 1-based -> 0-based

    if (slot >= PARTY_SIZE || form > 5) {
        VarSet(VAR_RESULT, 0);
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];
    bool8 ok = ApplyRotomCatalogToMon(mon, form);
    VarSet(VAR_RESULT, ok ? 1 : 0);
}

/* --- DEBUG SMOKE TEST (optional): writes friendship=123 and tries species swap.
   Keep this only while diagnosing; remove when done. ------------------------ */

// VAR_0x8006 sentinel = 123 if we actually ran
void Rotom_ForceSetForm_ForDebug(void)
{
    static const u16 sFormToSpecies[6] = {
        SPECIES_ROTOM, SPECIES_ROTOM_HEAT, SPECIES_ROTOM_WASH,
        SPECIES_ROTOM_FROST, SPECIES_ROTOM_FAN, SPECIES_ROTOM_MOW
    };

    u8 slotRaw = VarGet(VAR_0x8004);
    u8 form    = VarGet(VAR_0x8005);
    u8 slot    = (slotRaw >= 1 && slotRaw <= PARTY_SIZE) ? (u8)(slotRaw - 1) : slotRaw;

    if (slot >= PARTY_SIZE || form > 5) {
        VarSet(VAR_RESULT, 99);
        return;
    }

    struct Pokemon *mon = &gPlayerParty[slot];

    VarSet(VAR_0x8006, 123);           // sentinel
    {
        u8 friendship = 123;
        SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
    }

    u16 target = sFormToSpecies[form];
    SetMonData(mon, MON_DATA_SPECIES, &target);
    #ifdef MON_DATA_SPECIES2
    SetMonData(mon, MON_DATA_SPECIES2, &target);
    #endif

    CalculateMonStats(mon);
    VarSet(VAR_RESULT, 1);
}
