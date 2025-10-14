// data/maps/Birthday_Ellies_House/scripts.inc
#include "constants/party_menu.h"
#include "constants/species.h"
.set PARTY_CHOOSE_CANCEL, 255

Birthday_Ellies_House_MapScripts::
    .byte 0

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
    setvar VAR_0x8004, VAR_RESULT  @ party slot
    setvar VAR_0x8005, 3           @ Frost
    callnative OW_RotomCatalog_ApplyForm
    compare VAR_RESULT, 1
    goto_if_eq .changed
    msgbox gText_ChangeFailed, MSGBOX_DEFAULT
    goto .end

.changed:
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
