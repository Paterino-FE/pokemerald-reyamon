SSLANNN_START_R1_MapScripts::
	.byte 0


SSLANNN_START_R1_PukingLilyPal_Script::
	lock
	msgbox SSLANNN_START_R1_PukingLilyPal_Text, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_DIGGERSBY, CRY_MODE_ENCOUNTER
	waitmoncry
	release
	end

SSLANNN_START_R1_GarbageCan_Script::
	msgbox SSLANNN_START_R1_GarbageCan_Text, MSGBOX_AUTOCLOSE
	end

SSLANNN_EventScript_Heal::
	lockall
	msgbox SSLANNN_Text_Heal, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	callnative UpdateFollowingPokemon
	releaseall
	end

SSLANNN_START_R1_PukingLilyPal_Text:
	.string "Sorry EMPRESS, I... ... ...\n"
	.string "Uaghablrghblr$"

SSLANNN_START_R1_GarbageCan_Text:
	.string "... ... ... Ew!\n"
	.string "This one is definitely not empty!$"


SSLANNN_Text_Heal:
	.string "This bed is soooo comfortable...$"

