.set LOCALID_DIRKLING_RPS, 5

Birthday_Village_Present_MapScripts::
	.byte 0


Birthday_Village_Present_Rock_EventScript::
	setvar VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 0
	delay 16
	msgbox Birthday_Village_Present_Rock_Text, MSGBOX_DEFAULT
	playse SE_FAILURE
	waitse
	msgbox_mugshot Birthday_Village_Present_RockComment_Text, MSGBOX_DEFAULT, MUGSHOT_DIRKLING, CLEAR_MUGSHOT
	goto Birthday_Village_Present_RockPaperScissorsLoop_EventScript
	end


Birthday_Village_Present_PaperAdd1_EventScript::
	msgbox_mugshot Birthday_Village_Present_PaperComment1_Text, MSGBOX_DEFAULT, MUGSHOT_DIRKLING, CLEAR_MUGSHOT
	return 

Birthday_Village_Present_PaperAdd2_EventScript::
	msgbox_mugshot Birthday_Village_Present_PaperComment2_Text, MSGBOX_DEFAULT, MUGSHOT_DIRKLING, CLEAR_MUGSHOT
	return 

Birthday_Village_Present_PaperAdd3_EventScript::
	msgbox_mugshot Birthday_Village_Present_PaperComment3_Text, MSGBOX_DEFAULT, MUGSHOT_DIRKLING, CLEAR_MUGSHOT
	return 

Birthday_Village_Present_PaperAdd4_EventScript::
	msgbox_mugshot Birthday_Village_Present_PaperComment4_Text, MSGBOX_DEFAULT, MUGSHOT_DIRKLING, CLEAR_MUGSHOT
	return 

Birthday_Village_Present_PaperAdd_EventScript::
	playmoncry SPECIES_PIKACHU, CRY_MODE_ENCOUNTER
	call_if_eq VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 1, Birthday_Village_Present_PaperAdd1_EventScript
	call_if_eq VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 2, Birthday_Village_Present_PaperAdd2_EventScript
	call_if_eq VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 3, Birthday_Village_Present_PaperAdd3_EventScript
	call_if_eq VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 4, Birthday_Village_Present_PaperAdd4_EventScript
	waitmoncry
	return

Birthday_Village_Present_Paper_EventScript::
	addvar VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 1
	delay 16
	msgbox Birthday_Village_Present_Paper_Text, MSGBOX_DEFAULT
	call_if_lt VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 5, Birthday_Village_Present_PaperAdd_EventScript
	goto Birthday_Village_Present_RockPaperScissorsLoop_EventScript
	end

Birthday_Village_Present_Scissors_EventScript::
	setvar VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 0
	delay 16
	msgbox Birthday_Village_Present_Scissors_Text, MSGBOX_DEFAULT
	playse SE_FAILURE
	waitse
	msgbox_mugshot Birthday_Village_Present_ScissorsComment_Text, MSGBOX_DEFAULT, MUGSHOT_DIRKLING, CLEAR_MUGSHOT
	goto Birthday_Village_Present_RockPaperScissorsLoop_EventScript
	end

Birthday_Village_Present_ChooseWhich_EventScript::
	msgbox Birthday_Village_Present_ChooseWhich_Text, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_ROCK_PAPER_SCISSORS, TRUE
	switch VAR_RESULT
	case 0, Birthday_Village_Present_Rock_EventScript
	case 1, Birthday_Village_Present_Paper_EventScript
	case 2, Birthday_Village_Present_Scissors_EventScript
	end

Birthday_Village_Present_RockPaperScissorsLoop_EventScript::
	goto_if_lt VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 5, Birthday_Village_Present_ChooseWhich_EventScript
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 12  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	waitstate
	waitmoncry
	resetweather
	doweather
	fadedefaultbgm
	msgbox_mugshot Birthday_Village_Present_WonRockPaperScissors_Text, MSGBOX_DEFAULT, MUGSHOT_DIRKLING, CLEAR_MUGSHOT
	setflag FLAG_WON_ROCKPAPERSCISSORS
	release
	end

Birthday_Village_Present_DoRockPaperScissors_EventScript::
	setweather WEATHER_DOWNPOUR
	doweather
	playbgm MUS_CYNTHIA_ENCOUNTER, FALSE
	setvar VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 0
	msgbox Birthday_Village_Present_RockPaperScissors_Text, MSGBOX_DEFAULT
	call Birthday_Village_Present_RockPaperScissorsLoop_EventScript
	end

Birthday_Village_Present_RockPaperScissorsDirkling_EventScript::
	lock
	faceplayer
	goto_if_unset FLAG_WON_ROCKPAPERSCISSORS, Birthday_Village_Present_DoRockPaperScissors_EventScript
	playmoncry SPECIES_MISMAGIUS, CRY_MODE_ENCOUNTER
	msgbox Birthday_Village_Present_Wah_Text, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Birthday_Village_Present_MoveDown_Movement::
	applymovement LOCALID_DIRKLING_RPS, Movement_WalkDown
	waitmovement 0
	return

Birthday_Village_Present_RockPaperScissorsDirklingApproach_EventScript::
	lock
	applymovement LOCALID_DIRKLING_RPS, Common_Movement_ExclamationMark
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_gt VAR_0x8005, 17, Birthday_Village_Present_MoveDown_Movement
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_gt VAR_0x8005, 18, Birthday_Village_Present_MoveDown_Movement
	goto Birthday_Village_Present_RockPaperScissorsDirkling_EventScript
	end

Birthday_Village_Present_RockPaperScissors_Text:
	.string "STOP RIGHT THERE!\p"
	.string "You may go no further, because this\n"
	.string "DIRKLING will crush you!!!\p"
	.string "I forgot to bring my POKéMON, so I\n"
	.string "will destroy you in a game of\l"
	.string "ROCK PAPER SCISSORS.\p"
	.string "I have never lost against my fellow\n"
	.string "DIRKLINGS, but you will have to win\l"
	.string "FIVE games in a row to beat me.\p"
	.string "Or you could run back to your MAID!\n"
	.string "HAHAHAHAHAHA LET'S GO!$"

Birthday_Village_Present_Wah_Text:
	.string "Waaaaah... Waaaaah...\n"
	.string "Moooom! Waaaaah...$"

Birthday_Village_Present_WonRockPaperScissors_Text:
	.string "AAAAAAAAAAAARG!!!!!!!!\p"
	.string "THIS IS NOT POSSIBLE!\n"
	.string "IT'S UNFAIR!\p"
	.string "PAPER IS TOTALLY OVERPOWERED,\n"
	.string "IT NEEDS TO BE NERFED!\p"
	.string "... ... ... ... ... ...\p"
	.string "... ... ... ... ... ...\p"
	.string "FINE, I let you go this time!\n"
	.string "Sniff... Sniff...$"

Birthday_Village_Present_ChooseWhich_Text:
	.string "What will {PLAYER} choose?$"

Birthday_Village_Present_Rock_Text:
	.string "{PLAYER} chose... ROCK!\n"
	.string "And the DIRKLING chose... ROCK!\l"
	.string "It's a DRAW!$"

Birthday_Village_Present_RockComment_Text:
	.string "A good choice! But it's not a\n"
	.string "win for you, HAHAHA!$"

Birthday_Village_Present_Paper_Text:
	.string "{PLAYER} chose... PAPER!\n"
	.string "And the DIRKLING chose... ROCK!\p"
	.string "{PLAYER} WINS!$"

Birthday_Village_Present_PaperComment1_Text:
	.string "WHAT? That's UNFAIR! This was\n"
	.string "pure luck, I will destroy you\l"
	.string "next time!$"

Birthday_Village_Present_PaperComment2_Text:
	.string "WAIT, this is not how it should\n"
	.string "go! Are you cheating???$"

Birthday_Village_Present_PaperComment3_Text:
	.string "STOP! STOP!\n"
	.string "HOW ARE YOU DOING THIS?!$"

Birthday_Village_Present_PaperComment4_Text:
	.string "OH NO, IF I LOSE ONE MORE,\n"
	.string "KING VYRAL WILL EAT ME!$"

Birthday_Village_Present_Scissors_Text:
	.string "{PLAYER} chose... SCISSORS!\n"
	.string "And the DIRKLING chose... ROCK!\p"
	.string "{PLAYER} LOSES!$"

Birthday_Village_Present_ScissorsComment_Text:
	.string "HAHAHA WEAK!\n"
	.string "You got no chance against ME!$"


Birthday_Village_Present_AntleredKey_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_ANTLEREDKEY, Birthday_Village_Present_AntleredKeyBattle_EventScript
	msgbox Birthday_Village_Present_AntleredKey_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Village_Present_AntleredKeyBattle_EventScript::
	msgbox Birthday_Village_Present_AntleredKeyPreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_ANTLEREDKEY, Birthday_Village_Present_AntleredKeyIntro_Text, Birthday_Village_Present_AntleredKeyDefeat_Text
	release
	end

Birthday_Village_Present_AntleredKeyPreBattle_Text:

Birthday_Village_Present_AntleredKeyDefeat_Text:

Birthday_Village_Present_AntleredKey_Text:

Birthday_Village_Present_AntleredKeyIntro_Text:
