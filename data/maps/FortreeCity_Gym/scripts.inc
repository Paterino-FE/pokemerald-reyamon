FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_RioluNotInterested::
	playmoncry SPECIES_RIOLU, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox Fortree_Gym_Text_RioluNotInterested, MSGBOX_DEFAULT
	closemessage
	release
	end

FortreeCity_Gym_EventScript_RioluWantsToJoin::
	playmoncry SPECIES_RIOLU, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox Fortree_Gym_Text_RioluWantsToJoin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Fortree_Gym_EventScript_RioluRejected
	closemessage
	givemon SPECIES_RIOLU, 20, ITEM_SOOTHE_BELL, ITEM_LUXURY_BALL
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, FortreeCity_Gym_EventScript_ReceiveRioluParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, FortreeCity_Gym_EventScript_ReceiveRioluPC
	release
	end

Fortree_Gym_EventScript_RioluRejected::
	playmoncry SPECIES_RIOLU, CRY_MODE_FAINT
	msgbox Fortree_Gym_Text_RioluRejected, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

FortreeCity_Gym_EventScript_ReceiveRioluParty::
	call FortreeCity_Gym_EventScript_ReceivedRioluFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_Gym_EventScript_HideRiolu
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	call FortreeCity_Gym_EventScript_HideRiolu
	end

FortreeCity_Gym_EventScript_ReceiveRioluPC::
	call FortreeCity_Gym_EventScript_ReceivedRioluFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_Gym_EventScript_EventScript_SendRioluToPC
	call Common_EventScript_NameReceivedBoxMon
	call FortreeCity_Gym_EventScript_EventScript_SendRioluToPC
	end

FortreeCity_Gym_EventScript_EventScript_SendRioluToPC::
	call Common_EventScript_TransferredToPC
	goto FortreeCity_Gym_EventScript_HideRiolu
	end

FortreeCity_Gym_EventScript_ReceivedRioluFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message FortreeCity_Gym_Text_PlayerReceivedRiolu
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_RIOLU
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_RIOLU
	return

.set LOCALID_RIOLU, 9

FortreeCity_Gym_EventScript_HideRiolu::
	lockall  
	playmoncry SPECIES_RIOLU, CRY_MODE_ENCOUNTER
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_RIOLU
	removeobject LOCALID_RIOLU
	waitmoncry
	delay 16
	fadescreen FADE_FROM_BLACK
	release
	return

FortreeCity_Gym_Text_PlayerReceivedRiolu:
	.string "{PLAYER} received RIOLU!$"

FortreeCity_Gym_EventScript_Riolu::
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_RioluNotInterested
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_RioluWantsToJoin
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

Fortree_Gym_Text_RioluNotInterested:
	.string "RIOLU seems to be a bit sceptical\n"
	.string "of you...$"

Fortree_Gym_Text_RioluWantsToJoin:
	.string "RIOLU wants to join you on you\n"
	.string "on your adventure!\p"
	.string "Do you accept it?$"

Fortree_Gym_Text_RioluRejected:
	.string "RIOLU is saddened by your rejection.\n"
	.string "How can you be so heartless?$"

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Yo, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "FORTREE GYM LEADER THEA is a\n"
	.string "master of being friends with POKéMON.\p"
	.string "She's waiting at the back of this GYM,\n"
	.string "behind the rotating doors.\p"
	.string "She's waiting for new challengers\n"
	.string "who are trying to take wing!\p"
	.string "Okay, go for it!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "You did it!\n"
	.string "You've achieved liftoff!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "My POKéMON and I are the bestest of\n"
	.string "friends and I'll never leave their\p" 
	.string "side!$"


FortreeCity_Gym_Text_JaredDefeat:
	.string "Oh no, since you defeated my POKéMON,\n"
	.string "they lost some of their\p"
	.string "friendship value...$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Oh no, since you defeated my POKéMON,\n"
	.string "they lost some of their\p"
	.string "friendship value...$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Hi Reya, meet my friends!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "You're a pretty good trainer I guess...\n"
	.string "Woweez!$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "WOWEEZ$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Brat VYRAL was not a dream!\n"
	.string "Brat VYRAL is cannon!!!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "When life gives you lemons -\n"
	.string "you really stomp the hell out of\l"
	.string "them to make lemonade…$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "Fun Fact No.1: Lemon trees can produce\n"
	.string "up to 600lbs of lemons every year.\p"
	.string "Fun Fact No.2: Lemon’s tree,\n"
	.string "SUDOWOODO, was brutally murdered by\l"
	.string "Reya during the Nuzlocke.$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "If not friend, why friend shaped?$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "My peepo...My bwethwen...My fwiends...$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "My peepo...My bwethwen...My fwiends...$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Nigma invited me here!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Oh no...I'll....get....banned.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Oh no...I'll....get....banned.$"

FortreeCity_Gym_Text_DariusIntro:
	.string "We meet again, {PLAYER}! Have you\n"
	.string "been making good use of SOLAR BEAM?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Oh man, you're better than I thought!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "I only use cute Pokémon here,\n"
	.string "just like THEA!$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "AAAAAAAAAAAH!\p"
	.string "Why are you here?!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "To be honest, I didn't think\n"
	.string "you would make it this far, AYAYA!$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} received the\n"
	.string "FRIENDSHIP BADGE from THEA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "You have not just impressed me,\n"
	.string "Riolu there also seems to have\l"
	.string "taken a liking to you!$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM27 contains RETURN.\p"
	.string "...\n"
	.string "...\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Registered GYM LEADER THEA\n"
	.string "in the POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Leave now, before I start\n"
	.string "talking about Armenia!$"

FortreeCity_Gym_Text_GymStatue:
	.string "FORTREE CITY POKéMON GYM$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "FORTREE CITY POKéMON GYM\p"
	.string "THEA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning CHAMPION.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "I failed to reach your height again…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA: Even though I have lost,\n"
	.string "the wings of my heart remain unbroken.\p"
	.string "I can rise and soar again and\n"
	.string "yet again.\p"
	.string "I am convinced of it!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning CHAMPION.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!\p"
	.string "Oh, no… Do you have but one\n"
	.string "POKéMON with you?\p"
	.string "Please return with two POKéMON\n"
	.string "at the very least.$"
