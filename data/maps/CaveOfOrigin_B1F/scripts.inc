.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "EMILIA: Lady {PLAYER}! It is good to\n"
	.string "see you safe.\p"
	.string "After this catastrophe started\n"
	.string "unfolding, I sent for the imperial\l"
	.string "librarians to find a possible way out.\p"
	.string "In ancient texts, there is mention\n"
	.string "of a third POKéMON named RAYQUAZA.\p"
	.string "It is said to have the power to \n"
	.string "suppress the two combatants, as it\l"
	.string "has done so before in the distant\l"
	.string "past.\p"
	.string "Unfortunately, there is no mention of\n"
	.string "its whereabouts…\p"
	.string "I rushed here, as it seemed as likely\n"
	.string "a slumbering place as any other, but\l"
	.string "as you can see, there is nothing here\l"
	.string "but damp air.$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "EMILIA: Does your majesty perhaps have\n"
	.string "any inkling where RAYQUAZA might be?$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "EMILIA: The CAVE OF ORIGIN?\p"
	.string "I beg you, my Lady, to take this\n"
	.string "seriously!\p"
	.string "There is no time for jokes when the\n"
	.string "fate of HOENN is at stake!$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "EMILIA: MT. PYRE?\p"
	.string "It seems unlikely that it would hide\n"
	.string "there, Lady {PLAYER}.\p"
	.string "The old lady guarding that place made\n"
	.string "no mention of it to the emissaries\l"
	.string "that I sent there.$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "EMILIA: That is a problem…\n"
	.string "We really need to find out where\l"
	.string "RAYQUAZA is located.$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "EMILIA: The SKY PILLAR?\n"
	.string "A brilliant idea, mistress {PLAYER}!\p"
	.string "And very fitting for a giant serpent\n"
	.string "that protects the skies!\p"
	.string "We need to get there post haste!$"

