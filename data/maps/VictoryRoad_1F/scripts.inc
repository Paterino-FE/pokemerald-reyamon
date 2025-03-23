.set LOCALID_WALLY_ENTRANCE, 4

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 31, 3
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 31, 3
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	goto VictoryRoad_1F_EventScript_WallyMoveAside
	end

VictoryRoad_1F_EventScript_WallyMoveAside::
	lockall
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyMoveAside
	waitmovement 0
	applymovement LOCALID_WALLY_ENTRANCE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	releaseall
	end

VictoryRoad_1F_EventScript_Nurse::
	lockall
	faceplayer
	msgbox VictoryRoad_1F_Text_Nurse, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

VictoryRoad_1F_Movement_WallyMoveAside:
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Thea::
	trainerbattle_single TRAINER_THEA, VictoryRoad_1F_Text_TheaIntro, VictoryRoad_1F_Text_TheaDefeat
	msgbox VictoryRoad_1F_Text_TheaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Lumi::
	trainerbattle_single TRAINER_LUMI, VictoryRoad_1F_Text_LumiIntro, VictoryRoad_1F_Text_LumiDefeat
	msgbox VictoryRoad_1F_Text_LumiPostBattle, MSGBOX_AUTOCLOSE
	end


VictoryRoad_1F_Text_Nurse:
	.string "Your POKéMON deserve rest.\n"
	.string "Let me heal them.$"

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "LILYPAD: Hi! {PLAYER}!\p"
	.string "I bet you're surprised to see me here!\p"
	.string "I made it all the way here, and it's\n"
	.string "all thanks to you!\p"
	.string "{PLAYER}, losing to you that time\n"
	.string "made me stronger!\p"
	.string "But I'm not going to lose anymore!\p"
	.string "I'm going to win! For the POKéMON who\n"
	.string "gave me courage and strength!\p"
	.string "Okay… Here I come!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "LILYPAD: I couldn't beat you today,\n"
	.string "{PLAYER}, but one of these days, I'll\l"
	.string "catch up to you!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "LILYPAD: Hi! {PLAYER}!\p"
	.string "I've gotten stronger since that last\n"
	.string "time! I wanted to show you, {PLAYER}!\p"
	.string "Okay… Here I come!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "LILYPAD: I couldn't beat you this\n"
	.string "time, too… But one of these days,\l"
	.string "{PLAYER}, I'm going to catch up...\p"
	.string "And challenge the POKéMON LEAGUE!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "You again? I... ... ...\n"
	.string "Greetings, insert customer name,\l"
	.string "honorific or title here.\p"
	.string "Whomst I have definitely never met\n"
	.string "before. I hope you are having a\l"
	.string "wonderful day. I am Joan Mcdonalds.\p"
	.string "Not a former eco terrorist in hiding.\p"
	.string "and this is your remote McDonald’s\n"
	.string "pitstop. Can I take your order today?\p"
	.string "A battle? Really? Do we have to?\n"
	.string "Fine, let’s get this over with.$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Yeah, that went about how I expected.$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "It’s not easy being a single mother\n"
	.string "you know. It just really gets to you\l"
	.string "sometimes, and before you know it,\l"
	.string "you’ve almost caused an apocalypse.\p"
	.string "Hey Reya? Kick Vyral’s ass for me \n"
	.string "when you see her. And thanks for that\l"
	.string "whole saving the world thing I guess.$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Losing a battle isn't going to slow\n"
	.string "my roll. I'll take you down this\l"
	.string "time, TRAINER! Let's exchange\l"
	.string "superhot moves in another battle!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Whew!\n"
	.string "On the verge of eruption!$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "I lost the match, but I still\n"
	.string "had fun giving it my all.\p"
	.string "I don't often I get to enjoy\n"
	.string "a battle this heated.\p"
	.string "Let's have another one like\n"
	.string "this sometime!$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Ok I have it this time!\p"
	.string "Himastillahugefan!$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Maybe I will just go back\n"
	.string "to playing Dota.$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "You think I can get your\n"
	.string "autograph?$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "Ahaha, after experimenting on my lovely\n"
	.string "assistant, I now have mastered the\l"
	.string "sunflower lasers! Ready for a rematch?$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "Guh...\n"
	.string "oh no, I will have to experiment more...$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "When I asked Shiki-sama if he was\n"
	.string "available, he ran away so I guess\l"
	.string "I will have to wait...$"   

VictoryRoad_1F_Text_KatelynnIntro:
	.string "If not friend, why friend shaped?$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "My peepo... My bwethwen...\n"
	.string "My fwiends...$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "My peepo... My bwethwen...\n"
	.string "My fwiends...$"

VictoryRoad_1F_Text_TheaIntro:
	.string "Thea: It's time to sink\n"
	.string "this Friendship.$"

VictoryRoad_1F_Text_TheaDefeat:
	.string "Thea: I am genuinely ....\n"
	.string "empressed!$"

VictoryRoad_1F_Text_TheaPostBattle:
	.string "Thea: Go away, you made\n"
	.string "Lumi cry!$"

VictoryRoad_1F_Text_LumiIntro:
	.string "Lumi: WE'RE BACK!\p"
	.string "Wanna see photos of a drunken\n"
	.string "NanamiBear scaring tourists?$"

VictoryRoad_1F_Text_LumiDefeat:
	.string "Lumi: I can't believe Thea threw\n"
	.string "the match.$"

VictoryRoad_1F_Text_LumiPostBattle:
	.string "Lumi: Thea? More like Theaiga...Heh$"
