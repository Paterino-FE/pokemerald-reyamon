.set LOCALID_DIRKLING_RPS, 5
.set LOCALID_PAT, 7
.set LOCALID_CON, 8

Birthday_Village_Present_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Village_Present_Hide_Pat_Con_Setup
	.byte 0


Birthday_Village_Present_DirklingUpDown1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Village_Present_DirklingUpDown1_Text, MSGBOX_AUTOCLOSE
	release
	end

Birthday_Village_Present_DirklingUpDown2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Village_Present_DirklingUpDown2_Text, MSGBOX_AUTOCLOSE
	release
	end

Birthday_Village_Present_DirklingsKissing_EventScript::
	lock
	playmoncry SPECIES_LICKILICKY, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox Birthday_Village_Present_DirklingsKissing_Text, MSGBOX_AUTOCLOSE
	release
	end

Birthday_Village_Present_DirklingsKissing_Text:
	.string "Mwah mwah mwah mwah!$"

Birthday_Village_Present_DirklingUpDown1_Text:
	.string "placeholder$"

Birthday_Village_Present_DirklingUpDown2_Text:
	.string "placeholder$"


Birthday_Village_Present_Hide_Pat_Con_Setup::
	call_if_eq VAR_BIRTHDAY_HIDE_PAT_CONLAD, 0, Birthday_Village_Present_Hide_Pat_Con_0_Script
	call_if_eq VAR_BIRTHDAY_HIDE_PAT_CONLAD, 1, Birthday_Village_Present_Hide_Pat_Con_1_Script
	return

Birthday_Village_Present_Hide_Pat_Con_0_Script::
	setflag	FLAG_HIDE_PAT_CONLAD
	removeobject LOCALID_PAT
	removeobject LOCALID_CON
	return

Birthday_Village_Present_Hide_Pat_Con_1_Script::
	setflag	FLAG_HIDE_PAT_CONLAD
	removeobject LOCALID_PAT
	removeobject LOCALID_CON
	return

Birthday_Village_Present_Rock_EventScript::
	setvar VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 0
	delay 16
	msgbox_mugshot Birthday_Village_Present_Rock_Text, MSGBOX_DEFAULT, MUGSHOT_ROCK, CLEAR_MUGSHOT
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
	msgbox_mugshot Birthday_Village_Present_Paper_Text, MSGBOX_DEFAULT, MUGSHOT_PAPER, CLEAR_MUGSHOT
	call_if_lt VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 5, Birthday_Village_Present_PaperAdd_EventScript
	goto Birthday_Village_Present_RockPaperScissorsLoop_EventScript
	end

Birthday_Village_Present_Scissors_EventScript::
	setvar VAR_ROCK_PAPER_SCISSORS_WON_IN_ROW, 0
	delay 16
	msgbox_mugshot Birthday_Village_Present_Scissors_Text, MSGBOX_DEFAULT, MUGSHOT_SCISSORS, CLEAR_MUGSHOT
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
	trainerbattle_single TRAINER_ANTLEREDKEY, Birthday_Village_Present_AntleredKeyIntro_Text, Birthday_Village_Present_AntleredKeyDefeat_Text
	msgbox Birthday_Village_Present_AntleredKey_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Village_Present_AntleredKeyDefeat_Text:
	.string "I hope my antlered POKéMON and key\n"
	.string "POKéMON didn't leave you with too\l"
	.string "many bruises...$"

Birthday_Village_Present_AntleredKey_Text:
	.string "... Wait, YOU were {PLAYER}!?\n"
	.string "Well, now this is a bit awkward...\p"
	.string "Happy birthday streamer! I've loved\n"
	.string "being part of this community for at\l"
	.string "least a month now :D!$"

Birthday_Village_Present_AntleredKeyIntro_Text:
	.string "I heard someone cool was coming by...\n"
	.string "Have you seen her around here yet?$"


Birthday_Village_Present_Fight_Against_Pat_Conlad_Script::
	clearflag FLAG_HIDE_PAT_CONLAD
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_PAT
	applymovement LOCALID_PAT, Birthday_Village_Present_Movement_House
	waitmovement 0
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_CON
	applymovement LOCALID_PAT, Birthday_Village_Present_Movement_Fight_Pat
	applymovement LOCALID_CON, Birthday_Village_Present_Movement_Fight_Con
	waitmovement 0
	msgbox_mugshot Birthday_Village_Present_Pat_PreBattle_Text, MSGBOX_DEFAULT, MUGSHOT_PATERINO, CLEAR_MUGSHOT
	msgbox_mugshot Birthday_Village_Present_Con_PreBattle_Text, MSGBOX_DEFAULT, MUGSHOT_LILYPAL, CLEAR_MUGSHOT
	trainerbattle_two_trainers TRAINER_CONLAD_DOUBLE, Birthday_Village_Present_Con_Defeat_Text, TRAINER_PAT_DOUBLE, Birthday_Village_Present_Pat_Defeat_Text
	setvar VAR_BIRTHDAY_HIDE_PAT_CONLAD, 1
	release
	end

Birthday_Village_Present_Movement_House:
	walk_down
	step_end

Birthday_Village_Present_Movement_Fight_Pat:
	walk_down
	walk_left
	walk_left
	face_down
	step_end

Birthday_Village_Present_Movement_Fight_Con:
	walk_down
	walk_down
	walk_left
	face_down
	step_end

Birthday_Village_Present_Pat_PreBattle_Text:
.string "Reya... a storm is brewing and that\n"
.string "on your birthday, yikes.$"

Birthday_Village_Present_Con_PreBattle_Text:
.string "I hate to RAIN on your parade, but\n" 
.string "it's time for a battle.$"

Birthday_Village_Present_Pat_Defeat_Text:
.string "Happy Birthday Reya! This was a\n" 
.string "splendid display of skill.$"

Birthday_Village_Present_Con_Defeat_Text:
.string "I guess I was out of my DEPTH.$"

Birthday_Village_Present_Pat_EventScript::
	lock
	faceplayer
	msgbox Birthday_Village_Present_Pat_PostBattle_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Village_Present_Con_EventScript::
	lock 
	faceplayer
	msgbox Birthday_Village_Present_Con_PostBattle_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Village_Present_Pat_PostBattle_Text:
.string "I hope you're having fun! Take your time\n"
.string "and enjoy your life. You know you have\p"
.string "a lot of support behind your back.$"

Birthday_Village_Present_Con_PostBattle_Text:
.string "I tried to transcribe Happy Birthday\n"
.string "into the rom, but I wish it to you now.$"

Birthday_Village_Present_Dirkling1_EventScript::
	trainerbattle_single TRAINER_DIRKLING1_PRESENT, Birthday_Village_Present_Dirkling1Intro_Text, Birthday_Village_Present_Dirkling1Defeat_Text
	msgbox Birthday_Village_Present_Dirkling1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Village_Present_Dirkling1Defeat_Text:
	.string "You still can't have any!$"

Birthday_Village_Present_Dirkling1_Text:
	.string "You really ROCK, {PLAYER}!$"

Birthday_Village_Present_Dirkling1Intro_Text:
	.string "Check out my ROCKS!\n"
	.string "The ones i didn't eat at least!$"

Birthday_Village_Present_Dirkling2_EventScript::
	trainerbattle_single TRAINER_DIRKLING2_PRESENT, Birthday_Village_Present_Dirkling2Intro_Text, Birthday_Village_Present_Dirkling2Defeat_Text
	msgbox Birthday_Village_Present_Dirkling2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Village_Present_Dirkling2Defeat_Text:
	.string "Yes, we DIRKLINGS love EMILIA, too!$"

Birthday_Village_Present_Dirkling2_Text:
	.string "We all bet on MET!$"

Birthday_Village_Present_Dirkling2Intro_Text:
	.string "Let us pray together to our three\n"
	.string "DEITIES! FOR VYRAL!$"

Birthday_Village_Present_Dirkling3_EventScript::
	trainerbattle_single TRAINER_DIRKLING3_PRESENT, Birthday_Village_Present_Dirkling3Intro_Text, Birthday_Village_Present_Dirkling3Defeat_Text
	msgbox Birthday_Village_Present_Dirkling3_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Village_Present_Dirkling3Defeat_Text:
	.string "It's only after we've lost everything\n"
	.string "that we're free to do anything.$"

Birthday_Village_Present_Dirkling3_Text:
	.string "Our great depression is our lives.$"

Birthday_Village_Present_Dirkling3Intro_Text:
	.string "The first rule of this fight is:\n"
	.string "You don't talk about this fight,\l"
	.string "should you beat me!$"

Birthday_Village_Present_Dirkling4_EventScript::
	trainerbattle_single TRAINER_DIRKLING4_PRESENT, Birthday_Village_Present_Dirkling4Intro_Text, Birthday_Village_Present_Dirkling4Defeat_Text
	msgbox Birthday_Village_Present_Dirkling4_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Village_Present_Dirkling4Defeat_Text:
	.string "Welp, back to fishing.$"

Birthday_Village_Present_Dirkling4_Text:
	.string "Fishing is almost as fun as watching\n"
	.string "{PLAYER}'s streams!$"

Birthday_Village_Present_Dirkling4Intro_Text:
	.string "I've been fishing since DOMINION\n"
	.string "EPISODE 1!$"

Birthday_Village_Present_Dirkling5_EventScript::
	trainerbattle_single TRAINER_DIRKLING5_PRESENT, Birthday_Village_Present_Dirkling5Intro_Text, Birthday_Village_Present_Dirkling5Defeat_Text
	msgbox Birthday_Village_Present_Dirkling5_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Village_Present_Dirkling5Defeat_Text:
	.string "I will PSN myself because of this\n"
	.string "shameful loss.$"

Birthday_Village_Present_Dirkling5_Text:
	.string "These puns make me want to disappear\n"
	.string "into the VOID. And I haven't even\l"
	.string "said anything about poor SFE!$"

Birthday_Village_Present_Dirkling5Intro_Text:
	.string "Have we MET before? No? Are you SJUre?$"

Birthday_Village_Present_Dirkling6_EventScript::
	trainerbattle_single TRAINER_DIRKLING6_PRESENT, Birthday_Village_Present_Dirkling6Intro_Text, Birthday_Village_Present_Dirkling6Defeat_Text
	msgbox Birthday_Village_Present_Dirkling6_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Village_Present_Dirkling6Defeat_Text:
	.string "I knew I shoulda brought MEEPO...$"

Birthday_Village_Present_Dirkling6_Text:
	.string "One MEEP, two MEEP, time to sleep!$"

Birthday_Village_Present_Dirkling6Intro_Text:
	.string "I got all your favorite HEROES to\n"
	.string "beat you with!$"
