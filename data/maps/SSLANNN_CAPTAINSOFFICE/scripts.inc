SSLANNN_CAPTAINSOFFICE_MapScripts::
	.byte 0


SSLANNN_CAPTAINSOFFICE_LANNN_Script::
	lock
	faceplayer
	trainerbattle_single TRAINER_LANNN, SSLANNN_CAPTAINSOFFICE_Text_LANNNIntro, SSLANNN_CAPTAINSOFFICE_Text_LANNNDefeat, SSLANNN_CAPTAINSOFFICE_LANNN_Script_PostDefeat, NO_MUSIC
	goto SSLANNN_CAPTAINSOFFICE_LANNN_Script_PostDefeat
	release
	end

SSLANNN_CAPTAINSOFFICE_LANNN_Script_PostDefeat::
	msgbox SSLANNN_CAPTAINSOFFICE_Text_LANNNPostBattle, MSGBOX_DEFAULT
	setflag FLAG_FINISHED_SSLANN
	setvar VAR_SSLANNN_DOOR_STATE, 1
	release
	end

SSLANNN_CAPTAINSOFFICE_Text_LANNNIntro:
	.string "Is that... the false EMPRESS?!\p"			
	.string "Get ready to face the wrath\n"
	.string "of THE BOAT!$"

SSLANNN_CAPTAINSOFFICE_Text_LANNNDefeat:
	.string "Aww shucks, guess I'll get\n"
	.string "demoted to clipper again$"
	
SSLANNN_CAPTAINSOFFICE_Text_LANNNPostBattle:
	.string "Happy Birthday Reya! You're\n"
	.string "the best boss I could ask for.\p"
	.string "Thank you for giving me the\n"
	.string "opportunity to work with you!$"
	
