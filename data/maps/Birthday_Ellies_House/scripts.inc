// data/maps/Birthday_Ellies_House/scripts.inc
#include "constants/party_menu.h"
#include "constants/species.h"
.set PARTY_CHOOSE_CANCEL, 255

Birthday_Ellies_House_MapScripts::
    .byte 0

// ===== Fridge -> Rotom Frost =====
Fridge_EventScript::
    lockall
    faceplayer
    msgbox gText_ApplianceUsePrompt, MSGBOX_YESNO
    compare VAR_RESULT, 0              @ 0 = NO in your build
    goto_if_eq .end
    special ChoosePartyMon
    waitstate
    compare VAR_RESULT, PARTY_CHOOSE_CANCEL
    goto_if_eq .end
    setvar VAR_0x8004, VAR_RESULT      @ chosen party slot
    setvar VAR_0x8006, SPECIES_ROTOM_FROST
    callnative Rotom_ChangeForm_ToTargetSpecies
    compare VAR_RESULT, 0              @ not a Rotom
    goto_if_eq .notRotom
    compare VAR_RESULT, 2              @ already that form
    goto_if_eq .already
    msgbox gText_RotomChangedForm, MSGBOX_DEFAULT
    goto .end

// ===== Fan -> Rotom Fan =====
Fan_EventScript::
    lockall
    faceplayer
    msgbox gText_ApplianceUsePrompt, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq .end

    special ChoosePartyMon
    waitstate
    compare VAR_RESULT, PARTY_CHOOSE_CANCEL
    goto_if_eq .end

    setvar VAR_0x8004, VAR_RESULT
    setvar VAR_0x8006, SPECIES_ROTOM_FAN
    callnative Rotom_ChangeForm_ToTargetSpecies

    compare VAR_RESULT, 0
    goto_if_eq .notRotom
    compare VAR_RESULT, 2
    goto_if_eq .already

    msgbox gText_RotomChangedForm, MSGBOX_DEFAULT
    goto .end

// ===== Mower -> Rotom Mow =====
Mower_EventScript::
    lockall
    faceplayer
    msgbox gText_ApplianceUsePrompt, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq .end

    special ChoosePartyMon
    waitstate
    compare VAR_RESULT, 255
    goto_if_eq .end

    setvar VAR_0x8004, VAR_RESULT
    setvar VAR_0x8006, SPECIES_ROTOM_MOW
    callnative Rotom_ChangeForm_ToTargetSpecies

    compare VAR_RESULT, 0
    goto_if_eq .notRotom
    compare VAR_RESULT, 2
    goto_if_eq .already

    msgbox gText_RotomChangedForm, MSGBOX_DEFAULT
    goto .end

.notRotom:
    msgbox gText_NotARotom, MSGBOX_DEFAULT
    goto .end

.already:
    msgbox gText_RotomAlreadyThisForm, MSGBOX_DEFAULT
    goto .end

.end:
    releaseall
    end

// ---------- Text ----------
gText_ApplianceUsePrompt:
    .string "Use this appliance to change Rotom’s form?$"

gText_NotARotom:
    .string "That Pokémon isn’t a Rotom.$"

gText_RotomAlreadyThisForm:
    .string "Rotom is already in that form.$"

gText_RotomChangedForm:
    .string "Rotom changed form!$"
