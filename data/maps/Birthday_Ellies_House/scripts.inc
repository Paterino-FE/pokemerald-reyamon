// data/maps/Birthday_Ellies_House/scripts.inc

Birthday_Ellies_House_MapScripts::
    .byte 0

// -----------------------------------------------------------------------------
// Fridge -> Rotom Frost (form index 3)
// -----------------------------------------------------------------------------
Fridge_EventScript::
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
    setvar VAR_0x8005, 3               @ Frost
    callnative Rotom_ApplyForm_CatalogStyle

    compare VAR_RESULT, 1
    goto_if_eq .ok

    msgbox gText_ChangeFailed, MSGBOX_DEFAULT
    goto .end

.ok:
    msgbox gText_RotomChangedForm, MSGBOX_DEFAULT
.end:
    releaseall
    end

// ---------- Text ----------
gText_ApplianceUsePrompt:     
	.string "Use this appliance to change Rotom’s form?$"	

gText_RotomAlreadyThisForm:   
	.string "Rotom is already in that form.$"

gText_RotomChangedForm:       
	.string "Rotom changed form!$"

gText_ChangeFailed:           
	.string "Couldn’t change the form.$"
