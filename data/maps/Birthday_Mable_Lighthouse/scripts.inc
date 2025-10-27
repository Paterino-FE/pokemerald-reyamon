.set LOCALID_OSHAWOTT_1, 4
.set LOCALID_MABLE, 1
.set LOCALID_OSHAWOTT_2, 7
.set LOCALID_SAMUROTT, 9

Birthday_Mable_Lighthouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Birthday_Mable_Lighthouse_EventScript_Samurott_Setup
	.byte 0

Birthday_Mable_Lighthouse_EventScript_Samurott_Setup::
	call_if_eq VAR_MABLE_EVENT_EVOLVE_OSHAWOTT, 1, Birthday_Mable_Lighthouse_HIDE_SAMUROTT_1
	return

Birthday_Mable_Lighthouse_HIDE_SAMUROTT_1::
	removeobject LOCALID_SAMUROTT
	setvar VAR_MABLE_EVENT_EVOLVE_OSHAWOTT, 2
	return

Birthday_Mable_Lighthouse_HIDE_SAMUROTT_2::
	setvar VAR_MABLE_EVENT_EVOLVE_OSHAWOTT, 1
	removeobject LOCALID_SAMUROTT
	setflag FLAG_HIDE_SAMUROTT
	return

Birthday_Mable_Lighthouse_Mablewott::
	lockall
	special StorePlayerCoordsInVars
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_Mablewott_1, MSGBOX_SIGN, MUGSHOT_REYADETAIL, CLEAR_MUGSHOT
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_Mablewott_2, MSGBOX_SIGN, MUGSHOT_MABLEWOTT, CLEAR_MUGSHOT
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Mable_Lighthouse_Movement_Mablewott_Event_1
	waitmovement 0
	special RemoveCameraObject
	delay 60
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_Mablewott_3, MSGBOX_SIGN, MUGSHOT_MABLE, CLEAR_MUGSHOT
	delay 20
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Mable_Lighthouse_Movement_Mablewott_Event_5
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_OSHAWOTT_1, Mable_Lighthouse_Movement_Mablewott_Event_2
	delay 20
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_Mablewott_4, MSGBOX_SIGN, MUGSHOT_MABLE, CLEAR_MUGSHOT
	applymovement LOCALID_MABLE, Mable_Lighthouse_Movement_Mablewott_Event_7
	delay 60
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_ENCOUNTER
	waitmoncry
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	call_if_eq VAR_TEMP_2, 21, Mable_Lighthouse_Movement_Mablewott_Event_RunAwayAlt
	call_if_ne VAR_TEMP_2, 21, Mable_Lighthouse_Movement_Mablewott_Event_RunAway
	waitmovement 0
	removeobject LOCALID_OSHAWOTT_1
	setflag FLAG_HIDE_OSHAWOTT_1
	clearflag FLAG_HIDE_VILLAGE_OSHAWOTT
	releaseall
	end

Mable_Lighthouse_Movement_Mablewott_Event_RunAway:
	applymovement LOCALID_OSHAWOTT_1, Mable_Lighthouse_Movement_Mablewott_Event_3
	waitmovement 0
	return 

Mable_Lighthouse_Movement_Mablewott_Event_RunAwayAlt:
	applymovement LOCALID_OSHAWOTT_1, Mable_Lighthouse_Movement_Mablewott_Event_3_Alt
	waitmovement 0
	return 

Mable_Lighthouse_Movement_Mablewott_Event_1:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_up
	walk_slow_up
	step_end

Mable_Lighthouse_Movement_Mablewott_Event_2:
	jump_in_place_down
	jump_in_place_down
	step_end

Mable_Lighthouse_Movement_Mablewott_Event_3:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Mable_Lighthouse_Movement_Mablewott_Event_3_Alt:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end


Mable_Lighthouse_Movement_Mablewott_Event_5:
	walk_diag_southwest
	walk_diag_southwest
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Mable_Lighthouse_Movement_Mablewott_Event_7:
	jump_in_place_left
	jump_in_place_left
	step_end

Birthday_Mable_Lighthouse_TEXT_Mablewott_1:
	.string "Wow, this Oshawott has some\n"
	.string "beautiful hair!$"

Birthday_Mable_Lighthouse_TEXT_Mablewott_2:
	.string "OSHAWOTT!!\n"
	.string "It jumps around in a cute way.$"

Birthday_Mable_Lighthouse_TEXT_Mablewott_3:
	.string "Hey, what are you holding in your hands?!$"

Birthday_Mable_Lighthouse_TEXT_Mablewott_4:
	.string "She got a knife!$"

Mable_Lighthouse_EventScript_Mable::
	faceplayer
	goto_if_not_defeated TRAINER_MABLE, Mable_Lighthouse_EventScript_DoBattle
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_MableFight_4, MSGBOX_DEFAULT, MUGSHOT_MABLE, CLEAR_MUGSHOT
	release
	end

Mable_Lighthouse_EventScript_DoBattle::
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_MableFight_1_1, MSGBOX_DEFAULT, MUGSHOT_MABLE, CLEAR_MUGSHOT
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_OSHAWOTT_2, Mable_Lighthouse_Movement_Oshawott_Evolves
	waitmovement 0
	delay 20
	removeobject LOCALID_OSHAWOTT_2
	setflag FLAG_HIDE_OSHAWOTT_2
	clearflag FLAG_HIDE_SAMUROTT
	addobject LOCALID_SAMUROTT
	playmoncry SPECIES_SAMUROTT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_MableFight_1_2, MSGBOX_DEFAULT, MUGSHOT_SAMUROTT, CLEAR_MUGSHOT
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_MableFight_5, MSGBOX_DEFAULT, MUGSHOT_MABLE, CLEAR_MUGSHOT
	trainerbattle_no_intro TRAINER_MABLE, Birthday_Mable_Lighthouse_TEXT_MableFight_2 
	goto Mable_Lighthouse_EventScript_MableDefeated
	release
	end

Mable_Lighthouse_EventScript_MableDefeated::
	msgbox_mugshot Birthday_Mable_Lighthouse_TEXT_MableFight_3, MSGBOX_DEFAULT, MUGSHOT_MABLE, CLEAR_MUGSHOT
	msgbox Birthday_Mable_Lighthouse_TEXT_MableFight_AcceptOshawott, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, Mable_Lighthouse_EventScript_MableNoOshawott
	case YES, Mable_Lighthouse_EventScript_MableGiveOshawott
	release
	end

Mable_Lighthouse_EventScript_MableGiveOshawott::
	msgbox Mable_Lighthouse_TEXT_MableGiveOshawott, MSGBOX_DEFAULT
	givemon SPECIES_OSHAWOTT, 60, ITEM_EXPERT_BELT, ITEM_LUXURY_BALL
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Mable_Lighthouse_EventScript_ReceiveOshawottParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Mable_Lighthouse_EventScript_ReceiveOshawottPC
	release
	end

Mable_Lighthouse_EventScript_ReceiveOshawottParty::
	call Mable_Lighthouse_EventScript_ReceiveOshawottFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	release
	end

Mable_Lighthouse_EventScript_ReceiveOshawottPC::
	call Mable_Lighthouse_EventScript_ReceiveOshawottFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Mable_Lighthouse_EventScript_SendOshawottToPC
	call Common_EventScript_NameReceivedBoxMon
	call Mable_Lighthouse_EventScript_SendOshawottToPC
	end

Mable_Lighthouse_EventScript_SendOshawottToPC::
	call Common_EventScript_TransferredToPC
	release
	end

Mable_Lighthouse_EventScript_ReceiveOshawottFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message FortreeCity_Gym_Text_PlayerReceivedOshawott
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OSHAWOTT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_OSHAWOTT
	return

Birthday_Lighthouse_OshawottTalk::
	faceplayer
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_ENCOUNTER
	waitmoncry
	release
	end


Birthday_Lighthouse_SamurottTalk::
	faceplayer
	playmoncry SPECIES_SAMUROTT, CRY_MODE_ENCOUNTER
	waitmoncry
	release
	end

FortreeCity_Gym_Text_PlayerReceivedOshawott:
	.string "{PLAYER} received OSHAWOTT!$"

Mable_Lighthouse_EventScript_MableNoOshawott::
	msgbox Mable_Lighthouse_TEXT_MableNoOshawott, MSGBOX_DEFAULT
	release
	end

Mable_Lighthouse_TEXT_MableGiveOshawott:
	.string "Then it shall be yours.\n"
	.string "Raise it well, {PLAYER}, and it will\l"
	.string "grow strong at your side.$"

Mable_Lighthouse_TEXT_MableNoOshawott:
	.string "I understand. When the time is right,\n"
	.string "return to me… and an OSHAWOTT will\l"
	.string "be waiting.$"

Mable_Lighthouse_Movement_Oshawott_Evolves:
	jump_in_place_left
	jump_in_place_left
	emote_heart
	step_end

Birthday_Mable_Lighthouse_TEXT_MableFight_1_1:
	.string "Welcome, traveler. I am Mable,\n"
	.string "the keeper of this lighthouse.\p"
	.string "The light guides sailors home,\n"
	.string "but it also shines on those strong\l"
	.string "enough to face the storm.\p"
	.string "I have dedicated my life to raising\n"
	.string "OSHAWOTTS.\p"
	.string "They are not just partners, they\n"
	.string "are my family.\p"
	.string "With strength and guidance, my\n"
	.string "OSHAWOTTS grow into proud SAMUROTTS,\l"
	.string "guardians of land and sea.\p"
	.string "This one has grown with me since the\n"
	.string "beginning.\p"
	.string "Today, it is ready to stand at my\n"
	.string "side as a SAMUROTT.$"

Birthday_Mable_Lighthouse_TEXT_MableFight_1_2:
	.string "OSHAWOTT EVOLVED!!!$"

Birthday_Mable_Lighthouse_TEXT_MableFight_2:
	.string "I gave everything I had, yet you\n"
	.string "endured. {PLAYER}, your strength\l"
	.string "withstands even the fiercest storm!$"

Birthday_Mable_Lighthouse_TEXT_MableFight_3:
	.string "It would be our honor to have one\n"
	.string "of our OSHAWOTT join you.$"

Birthday_Mable_Lighthouse_TEXT_MableFight_AcceptOshawott:
	.string "Will you accept this companion on\n"
	.string "your journey?$"

Birthday_Mable_Lighthouse_TEXT_MableFight_4:
	.string "As the sea is endless, so is my work.\p"
	.string "There will always be OSHAWOTTS here,\n"
	.string "waiting for those brave enough to earn\l"
	.string "their place.$"

Birthday_Mable_Lighthouse_TEXT_MableFight_5:
	.string "If you can defeat me, you will earn\n"
	.string "more than my respect.\p"
	.string "You will prove that you are worthy\n"
	.string "of taking one of my OSHAWOTTS on\l"
	.string "your journey.\p"
	.string "Now… Let us see if you can weather\n"
	.string "the tide!$"

Birthday_Mable_Lighthouse_Lilypal1_EventScript::
	lock
	faceplayer
	goto_if_unset FLAG_TALKED_LIGHTHOUSE_FLEETPAL, Birthday_Mable_Lighthouse_Lilypal1First_EventScript
	msgbox_mugshot Birthday_Mable_Lighthouse_Lilypal1_Text, MSGBOX_DEFAULT, MUGSHOT_LILYPAL, CLEAR_MUGSHOT
	release
	end

Birthday_Mable_Lighthouse_Lilypal1First_EventScript::
	msgbox_mugshot Birthday_Mable_Lighthouse_Lilypal1First_Text, MSGBOX_DEFAULT, MUGSHOT_LILYPAL, CLEAR_MUGSHOT
	setflag FLAG_TALKED_LIGHTHOUSE_FLEETPAL
	release
	end

Birthday_Mable_Lighthouse_Lilypal1First_Text:
	.string "The OSHAWOTTS have been helping us\n"
	.string "build a fishing fleet.\p"
	.string "Soon the DIRKLINGS won't stand\n"
	.string "a chance!$"

Birthday_Mable_Lighthouse_Lilypal1_Text:
	.string "The friendly LILYPAL in the POKéMON\n"
	.string "CENTER sold us some medicine and now\l"
	.string "we've been building boats for 96\l"
	.string "hours straight.\p"
	.string "Isn't that weird hahahaha.$"

Birthday_Mable_Lighthouse_Lilypal2_EventScript::
	lock
	faceplayer
	goto_if_unset FLAG_TALKED_LIGHTHOUSE_LAZYPAL, Birthday_Mable_Lighthouse_Lilypal2First_EventScript
	msgbox_mugshot Birthday_Mable_Lighthouse_Lilypal2_Text, MSGBOX_DEFAULT, MUGSHOT_LILYPAL, CLEAR_MUGSHOT
	release
	end

Birthday_Mable_Lighthouse_Lilypal2First_EventScript::
	msgbox_mugshot Birthday_Mable_Lighthouse_Lilypal2First_Text, MSGBOX_DEFAULT, MUGSHOT_LILYPAL, CLEAR_MUGSHOT
	setflag FLAG_TALKED_LIGHTHOUSE_LAZYPAL
	release
	end

Birthday_Mable_Lighthouse_Lilypal2_Text:
	.string "DOMINION attack? What's that?\n"
	.string "VYRAL? Who's VYRAL?$"

Birthday_Mable_Lighthouse_Lilypal2First_Text:
	.string "Did you ever play this cool fishing\n"
	.string "game called DOMINION?\p"
	.string "You get all sorts of fish. FOR FREE!!$"

Birthday_Mable_Lighthouse_Lilypal3_EventScript::
	lock
	faceplayer
	msgbox_mugshot Birthday_Mable_Lighthouse_Lilypal3_Text, MSGBOX_DEFAULT, MUGSHOT_LILYPAL, CLEAR_MUGSHOT
	release
	end

Birthday_Mable_Lighthouse_Lilypal3_Text:
	.string "So...tired..but...must...hit...\n"
	.string "10000....steps$"

Birthday_Mable_Lighthouse_Oshawott1_EventScript::
	lock
	msgbox_mugshot Birthday_Mable_Lighthouse_Oshawott1_Text, MSGBOX_DEFAULT, MUGSHOT_OSHAWOTT, CLEAR_MUGSHOT
	release
	end

Birthday_Mable_Lighthouse_Oshawott1_Text:
	.string "OSHAWOTT is driving in nails to a\n"
	.string "rhythm.\p"
	.string "O-sha O-sha O-sha O-sha-wott.$"

Birthday_Mable_Lighthouse_Oshawott2_EventScript::
	lock
	faceplayer
	playmoncry SPECIES_OSHAWOTT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox_mugshot Birthday_Mable_Lighthouse_Oshawott2_Text, MSGBOX_DEFAULT, MUGSHOT_OSHAWOTT, CLEAR_MUGSHOT
	release
	end

Birthday_Mable_Lighthouse_Oshawott2_Text:
	.string "OSHAWOTT: OSHAWOTT$"

