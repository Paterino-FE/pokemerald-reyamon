.set LOCALID_BO, 1

Birthday_Average_Bos_House_MapScripts::
	.byte 0

Birthday_Average_Bos_House_YourAvgBo_EventScript1::
	lock
	applymovement LOCALID_BO, Birthday_Average_Bos_House_Bo_Movement1
	applymovement OBJ_EVENT_ID_PLAYER, Birthday_Average_Bos_House_Reya_Movement
	waitmovement 0
	delay 50
	msgbox_mugshot Birthday_Average_Bos_House_WALLSTARE_Text, MSGBOX_DEFAULT, MUGSHOT_BOWALL, CLEAR_MUGSHOT
	delay 300
	msgbox_mugshot Birthday_Average_Bos_House_BoBored_Text, MSGBOX_DEFAULT, MUGSHOT_BO, CLEAR_MUGSHOT
	applymovement OBJ_EVENT_ID_PLAYER, Birthday_Average_Bos_House_Reya_Movement1
	applymovement LOCALID_BO, Birthday_Average_Bos_House_Reya_Movement2
	waitmovement 0
	goto_if_not_defeated TRAINER_BO, Birthday_Average_Bos_House_YourAvgBoBattle_EventScript
	release
	end

Birthday_Average_Bos_House_YourAvgBo_EventScript2::
	lock
	applymovement LOCALID_BO, Birthday_Average_Bos_House_Bo_Movement2
	applymovement OBJ_EVENT_ID_PLAYER, Birthday_Average_Bos_House_Reya_Movement
	waitmovement 0
	delay 50
	msgbox_mugshot Birthday_Average_Bos_House_WALLSTARE_Text, MSGBOX_DEFAULT, MUGSHOT_BOWALL, CLEAR_MUGSHOT
	delay 300
	msgbox_mugshot Birthday_Average_Bos_House_BoBored_Text, MSGBOX_DEFAULT, MUGSHOT_BO, CLEAR_MUGSHOT
	applymovement OBJ_EVENT_ID_PLAYER, Birthday_Average_Bos_House_Reya_Movement2
	applymovement LOCALID_BO, Birthday_Average_Bos_House_Reya_Movement1
	waitmovement 0
	goto_if_not_defeated TRAINER_BO, Birthday_Average_Bos_House_YourAvgBoBattle_EventScript
	release
	end

Birthday_Average_Bos_House_YourAvgBoBattle_EventScript::
	msgbox_mugshot Birthday_Average_Bos_House_YourAvgBoIntro_Text, MSGBOX_DEFAULT, MUGSHOT_BO, CLEAR_MUGSHOT
	trainerbattle_no_intro TRAINER_BO, Birthday_Average_Bos_House_YourAvgBoDefeat_Text
	setvar VAR_BO_EVENT, 2
	release
	end

Birthday_Average_Bos_House_YourAvgBo_EventScript::
	lock
	faceplayer
	call_if_eq VAR_BO_EVENT, 0, Birthday_Average_Bos_House_YourAvgBoStart_EventScript
	call_if_eq VAR_BO_EVENT, 1, Birthday_Average_Bos_House_YourAvgBoStart_EventScript
	call_if_eq VAR_BO_EVENT, 2, Birthday_Average_Bos_House_YourAvgBoAfterBattle_EventScript
	release
	end

Birthday_Average_Bos_House_YourAvgBoStart_EventScript::
	msgbox_mugshot Birthday_Average_Bos_House_YourAvgBoMeet_Text, MSGBOX_DEFAULT, MUGSHOT_BO, CLEAR_MUGSHOT
	setvar VAR_BO_EVENT, 1
	release
	end

Birthday_Average_Bos_House_YourAvgBoAfterBattle_EventScript::
	msgbox_mugshot Birthday_Average_Bos_House_YourAvgBo_Text, MSGBOX_DEFAULT, MUGSHOT_BO, CLEAR_MUGSHOT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	release
	end

Birthday_Average_Bos_House_YourAvgBoMeet_Text:
	.string "Hey Reya, lets watch the paint dry!$"

Birthday_Average_Bos_House_YourAvgBoDefeat_Text:
	.string "Damn my bad.$"

Birthday_Average_Bos_House_YourAvgBo_Text:
	.string "Watching paint dry is so\n"
	.string "so refreshing!$"

Birthday_Average_Bos_House_YourAvgBoIntro_Text:
	.string "Hopefully you're better at battling\n"
	.string "POKéMON than you are at getting women.$"

Birthday_Average_Bos_House_WALLSTARE_Text:
	.string "Damn, this looks like a content farm.$"

Birthday_Average_Bos_House_BoBored_Text:
	.string "Ok, this is getting SO BORING.\p"
	.string "I will fight you now instead\n"
	.string "because YOU ARE TRASH!$"

Birthday_Average_Bos_House_Bo_Movement1:
	walk_left
	walk_down
	walk_left
	step_end

Birthday_Average_Bos_House_Bo_Movement2:
	walk_left
	walk_left
	step_end

Birthday_Average_Bos_House_Reya_Movement:
	face_left
	step_end

Birthday_Average_Bos_House_Reya_Movement1:
	face_down
	step_end


Birthday_Average_Bos_House_Reya_Movement2:
	face_up
	step_end

