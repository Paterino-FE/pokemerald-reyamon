.set LOCALID_MAGMA_GRUNT_1, 5
.set LOCALID_MAGMA_GRUNT_2, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_AQUA_GRUNT_1, 8
.set LOCALID_AQUA_GRUNT_2, 9

MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_ARCHIE
	addobject LOCALID_AQUA_GRUNT_1
	addobject LOCALID_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_MAGMA_GRUNT_2
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_AQUA_GRUNT_1
	removeobject LOCALID_AQUA_GRUNT_2
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_down
	delay_4
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "I have the shiny rock!\n"
	.string "I have the shiny rock!$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "You don’t have the shiny rock!\n"
	.string "You can’t have the shiny rock!$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "HATZOOME: Sttaaaaahhhhhhpppppp!\p"
	.string "You're going to ruin my plan!\n"
	.string "It was a really good one this time!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "SVELTE: Ah! Scary bad strangers!\p"
	.string "My mummy says I no play with you,\n"
	.string "you take my shinies. I take shiny\l"
	.string "rock to mummy at mo- mo-\l"
	.string "mout kimney now.\p"
	.string "Super secret dragon escape technique.$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "HATZOOME: Oh hey, you’re the one\n"
	.string "from SLATEPORT! Remember?\p"
	.string "I was that lovely trainer trying\n"
	.string "to get you in on the ground floor\l"
	.string "of this timeshare program.\p"
	.string "Nice to formally meet you {PLAYER}.\p"
	.string "I can’t believe you didn’t want to\n"
	.string "invest in a timeshare.\p"
	.string "Oh…you still don't. Well, you\n"
	.string "probably just need to grab your\l"
	.string "checkbook from home, I get it.\p"
	.string "Just be careful around the DRAGON\n"
	.string "GANG. As you can see, they're always\l"
	.string "doing reckless things to increase\l"
	.string "their power.\p"
	.string "Couldn't be me though, am I right?$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "Cast Member: Ma'am, I think we\n"
	.string "should follow them...$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "HATZOOME: That’s a smart idea!\p"
	.string "Well, I’ve got to go. You know,\n"
	.string "DRAGON GANG, Mt. Chimney, all that.$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "HATZOOME: {PLAYER}, we'll talk about\n"
	.string "which suite level you want when you\l"
	.string "bring your checkbook next time.\p"
	.string "Bye forever!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "I… I'm COZMO…\n"
	.string "I'm a PROFESSOR…\p"
	.string "DRAGON GANG asked me to guide them\n"
	.string "to METEOR FALLS…\p"
	.string "But they tricked me.\n"
	.string "They even took my METEORITE away…\p"
	.string "And then another similar bunch,\n"
	.string "TENTACOOL CRUISES showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that DRAGON GANG…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "PROF. COZMO: But that DRAGON GANG…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"
