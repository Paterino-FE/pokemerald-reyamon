SSLANNN_OUTSIDE_MapScripts::
	.byte 0


SSLANNN_OUTSIDE_Script_Nanami_Bear::
	lock
	faceplayer
	playmoncry SPECIES_BEARTIC, CRY_MODE_FAINT
	waitmoncry
	msgbox SSLANNN_OUTSIDE_Text_NanamiCry, MSGBOX_DEFAULT
	release
	end

SSLANNN_OUTSIDE_Script_Lumi::
	lock
	goto_if_set FLAG_TALKED_TO_LUMI_BOAT, SSLANNN_OUTSIDE_Script_WhoEvenEatsRocks
	fadeoutbgm 0
	delay 32
	msgbox SSLANNN_OUTSIDE_Text_Beware, MSGBOX_DEFAULT
	delay 64
	fadeinbgm 1
	faceplayer
	msgbox_mugshot SSLANNN_OUTSIDE_Text_AhEmpress, MSGBOX_DEFAULT, MUGSHOT_LUMI, CLEAR_MUGSHOT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceDown
	waitmovement 0
	playmoncry SPECIES_BEARTIC, CRY_MODE_ENCOUNTER
	msgbox SSLANNN_OUTSIDE_Text_ScratchesEar, MSGBOX_DEFAULT
	waitmoncry
	faceplayer 
	msgbox_mugshot SSLANNN_OUTSIDE_Text_ThatWillHaveToWait, MSGBOX_DEFAULT, MUGSHOT_LUMI, CLEAR_MUGSHOT
	setflag FLAG_TALKED_TO_LUMI_BOAT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

SSLANNN_OUTSIDE_Script_WhoEvenEatsRocks::
	msgbox SSLANNN_OUTSIDE_Text_WhoEvenEatsRocks, MSGBOX_DEFAULT
	release
	end

SSLANNN_OUTSIDE_Text_Beware:
	.string "Luminel stares out at sea,\n"
	.string "humming a song.\p"
	.string "'Beware, beware, the guardian of\n"
	.string "the sea... ... ... ...'$"

SSLANNN_OUTSIDE_Text_AhEmpress:
	.string "Ah Empress!\n"
	.string "It's good to sea you again.\p"
	.string "Are you out searching for new POKéMON?\p"
	.string "Or maybe a way to deal with this\n"
	.string "DIRKLING infestation that has come\l"
	.string "out of nowhere... Annoying creatures.\p"
	.string "Poor NANAMIBEAR tried to eat one,\n"
	.string "but his claws got broken by their\l"
	.string "craggy interior.$"

SSLANNN_OUTSIDE_Text_ScratchesEar:
	.string "Luminel reaches out and scratches\n"
	.string "NANAMIBEARS ear.$"

SSLANNN_OUTSIDE_Text_ThatWillHaveToWait: 
	.string "So I'm afraid our rematch will have\n"
	.string "to wait.$"

SSLANNN_OUTSIDE_Text_WhoEvenEatsRocks:
	.string "Who even eats rocks...$"

SSLANNN_OUTSIDE_Text_NanamiCry:
	.string "NANAMIBEAR looks at you sadly,\n"
	.string "a bandage around his right paw.$"

