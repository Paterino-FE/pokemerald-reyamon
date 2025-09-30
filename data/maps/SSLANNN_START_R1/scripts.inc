SSLANNN_START_R1_MapScripts::
	.byte 0


SSLANNN_START_R1_PukingLilyPal_Script::
	lock
	msgbox SSLANNN_START_R1_PukingLilyPal_Text, MSGBOX_DEFAULT
	playmoncry SPECIES_DIGGERSBY, CRY_MODE_ENCOUNTER
	waitmoncry
	release
	end

SSLANNN_START_R1_GarbageCan_Script::
	msgbox SSLANNN_START_R1_GarbageCan_Text, MSGBOX_AUTOCLOSE
	end

SSLANNN_START_R1_PukingLilyPal_Text:
	.string "Sorry EMPRESS, I... ... ...\n"
	.string "Uaghablrghblr$"

SSLANNN_START_R1_GarbageCan_Text:
	.string "... ... ... Ew!\n"
	.string "This one is definitely not empty!$"

