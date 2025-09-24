.set LOCALID_TRASHDIRK1, 1
.set LOCALID_TRASHDIRK2, 2

SSLANNN_2F_MapScripts::
	.byte 0


SSLANNN_2F_TrashDirkling1_Script::
	lock
	faceplayer 
	msgbox SSLANNN_2F_TrashDirkling1_Text, MSGBOX_DEFAULT
	applymovement LOCALID_TRASHDIRK1, Common_Movement_FaceDown
	waitmovement 0
	release
	end

SSLANNN_2F_TrashDirkling2_Script::
	lock
	faceplayer 
	msgbox SSLANNN_2F_TrashDirkling2_Text, MSGBOX_DEFAULT
	applymovement LOCALID_TRASHDIRK2, Common_Movement_FaceRight
	waitmovement 0
	release
	end

SSLANNN_2F_TrashBucket_Script::
	lock
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_TRASHDIRK2, Common_Movement_FaceDown
	waitmovement 0
	msgbox SSLANNN_2F_OurTrash_Text, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, SSLANNN_2F_Movement_JumpAway
	waitmovement 0
	applymovement LOCALID_TRASHDIRK2, Common_Movement_FaceRight
	waitmovement 0
	release
	end

SSLANNN_2F_Movement_JumpAway:
	jump_down
	face_up
	delay_16
	step_end

SSLANNN_2F_TrashDirkling1_Text:
	.string "Go away, stupid EMPRESS!\n"
	.string "Me busy!\p"
	.string "Chomp... chomp...$"

SSLANNN_2F_TrashDirkling2_Text:
	.string "Tasty!$"

SSLANNN_2F_OurTrash_Text:
	.string "OUR TRASH!!!$"
	
