.set LOCALID_FELIXR, 1
.set LOCALID_FORTY, 2

SSLANNN_LOWER_MapScripts::
	.byte 0

SSLANNN_LOWER_MoveRight_MovementScript:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SSLANNN_LOWER_ReyaSurprised_MovementScript:
	face_left
	delay_16
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SSLANNN_LOWER_ApproachFromTop_Movement::
	walk_right
	face_down
	step_end

SSLANNN_LOWER_ApproachFromBottom_Movement::
	walk_right
	face_up
	step_end


SSLANNN_LOWER_FelixrApproachTop_EventScript::
	applymovement LOCALID_FELIXR, SSLANNN_LOWER_ApproachFromTop_Movement
	waitmovement 0
	return

SSLANNN_LOWER_FelixrApproachBottom_EventScript::
	applymovement LOCALID_FELIXR, SSLANNN_LOWER_ApproachFromBottom_Movement
	waitmovement 0
	return

SSLANNN_LOWER_FortyApproachTop_EventScript::
	applymovement LOCALID_FORTY, SSLANNN_LOWER_ApproachFromTop_Movement
	waitmovement 0
	return

SSLANNN_LOWER_FortyApproachBottom_EventScript::
	applymovement LOCALID_FORTY, SSLANNN_LOWER_ApproachFromBottom_Movement
	waitmovement 0
	return

SSLANNN_LOWER_MoveToTop_EventScript::
	setobjectxy LOCALID_FORTY, 6, 2
	return

SSLANNN_LOWER_MoveToBottom_EventScript::
	setobjectxy LOCALID_FELIXR, 6, 5
	return


SSLANNN_LOWER_FelixFortyBattle_EventScript::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, SSLANNN_LOWER_ReyaSurprised_MovementScript
	waitmovement 0
	waitse
	playbgm MUS_ENCOUNTER_INTENSE, 0
	addobject LOCALID_FELIXR
	addobject LOCALID_FORTY
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	call_if_eq VAR_TEMP_3, 2, SSLANNN_LOWER_MoveToTop_EventScript
	call_if_eq VAR_TEMP_3, 5, SSLANNN_LOWER_MoveToBottom_EventScript
	applymovement LOCALID_FELIXR, SSLANNN_LOWER_MoveRight_MovementScript
	applymovement LOCALID_FORTY, SSLANNN_LOWER_MoveRight_MovementScript
	waitmovement 0
	call_if_eq VAR_TEMP_3, 2, SSLANNN_LOWER_FelixrApproachBottom_EventScript
	call_if_eq VAR_TEMP_3, 3, SSLANNN_LOWER_FortyApproachBottom_EventScript
	call_if_eq VAR_TEMP_3, 4, SSLANNN_LOWER_FelixrApproachTop_EventScript
	call_if_eq VAR_TEMP_3, 5, SSLANNN_LOWER_FortyApproachTop_EventScript
	msgbox SSLANNN_LOWER_FelixFortyPreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_FELIXR, SSLANNN_LOWER_FelixrDefeat_Text, TRAINER_FORTY, SSLANNN_LOWER_FortyDefeat_Text
	setvar VAR_SSLANN_LOWER_STATE, 1 
	end

SSLANNN_LOWER_Trigger_EventScript::
	goto SSLANNN_LOWER_FelixFortyBattle_EventScript
	end

SSLANNN_LOWER_Forty_EventScript::
	lock
	faceplayer
	msgbox SSLANNN_LOWER_FortyRepeat_Text, MSGBOX_DEFAULT
	release
	end

SSLANNN_LOWER_Felixr_EventScript::
	lock
	faceplayer
	msgbox SSLANNN_LOWER_FelixrRepeat_Text, MSGBOX_DEFAULT
	release
	end

SSLANNN_LOWER_FelixFortyPreBattle_Text:
	.string "FELIX: You were drawn here like a\n"
	.string "moth to a flame!\p"
	.string "FORTY: Tremble before my terrifyingly\n"
	.string "toasty triple torment!\p"
	.string "Also, give me your wallet.$"

SSLANNN_LOWER_FelixrDefeat_Text:
	.string "FELIX: Wait, I'm the one using\n"
	.string "BUTTERFREE, so I would be the\l"
	.string "moth here...$"

SSLANNN_LOWER_FortyDefeat_Text:
	.string "FORTY: Better to burn out than\n"
	.string "fade away...$"

SSLANNN_LOWER_FelixrRepeat_Text:
	.string "FELIX: ...is BUTTERFREE even a moth?$"

SSLANNN_LOWER_FortyRepeat_Text:
	.string "FORTY: Alright, you can keep your\n"
	.string "wallet. Also, I wish you a very\l"
	.string "joyous birthday, REYA!$"


