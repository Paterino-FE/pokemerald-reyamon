.set LOCALID_TRASHDIRK1, 1
.set LOCALID_TRASHDIRK2, 2

SSLANNN_2F_MapScripts::
	.byte 0


SSLANNN_2F_HatzoomeFirst_EventScript::
	msgbox_mugshot SSLANNN_2F_Hatzoome_Text, MSGBOX_AUTOCLOSE, MUGSHOT_HATZOOME, CLEAR_MUGSHOT
	setflag FLAG_TALKED_HATZOOME_LANNN
	release
	end

SSLANNN_2F_Hatzoome_EventScript::
	lock
	faceplayer
	goto_if_unset FLAG_TALKED_HATZOOME_LANNN, SSLANNN_2F_HatzoomeFirst_EventScript
	msgbox_mugshot SSLANNN_2F_HatzoomeRepeat_Text, MSGBOX_AUTOCLOSE, MUGSHOT_HATZOOME, CLEAR_MUGSHOT
	release
	end

SSLANNN_2F_Hatzoome_Text:
	.string "Oh hey there {PLAYER}, fancy seeing\n"
	.string "you here!\p"
	.string "I don't know if you'd believe it but\n"
	.string "I've been out of trouble since we\l"
	.string "last saw each other.\p"
	.string "I even got a job!\p"
	.string "They only needed me to put down\n"
	.string "100,000¥ to buy into the company and\l"
	.string "now they gave me all these special\l"
	.string "crystals that can help heal you with\l"
	.string "their aura!\p"
	.string "... wha... what do you mean that\n"
	.string "sounds like a pyramid scheme?\p"
	.string "I think I would know if I got roped\n"
	.string "into another scam...$"

SSLANNN_2F_HatzoomeRepeat_Text:
	.string "It's not a scam...\p"
	.string "They had a powerpoint and\n"
	.string "everything...$"

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

SSLANNN_2F_CirclesLilypal_EventScript::
	lock
	faceplayer
	msgbox SSLANNN_2F_CirclesLilypal_Text, MSGBOX_DEFAULT
	release
	end

SSLANNN_2F_Movement_JumpAway:
	jump_down
	face_up
	delay_16
	step_end

SSLANNN_2F_CirclesLilypal_Text:	
	.string "I'm on a BOAT! I'm on a BOAT!$"

SSLANNN_2F_TrashDirkling1_Text:
	.string "Go away, stupid EMPRESS!\n"
	.string "Me busy!\p"
	.string "Chomp... chomp...$"

SSLANNN_2F_TrashDirkling2_Text:
	.string "Tasty!$"

SSLANNN_2F_OurTrash_Text:
	.string "OUR TRASH!!!$"
	
