SSLANNN_OUTSIDE_MapScripts::
	.byte 0


SSLANNN_OUTSIDE_Script_Nanami_Bear::
	lock
	faceplayer
	playmoncry SPECIES_BEARTIC, CRY_MODE_ENCOUNTER
	waitmoncry
	release
	end

SSLANNN_OUTSIDE_Script_Lumi::
	lock
	faceplayer
	msgbox SSLANNN_OUTSIDE_Text_Lumi, MSGBOX_DEFAULT
	release
	end

SSLANNN_OUTSIDE_Text_Lumi:
	.string "Just some placeholder blablabla\n"
	.string "Malaysia btw$"

