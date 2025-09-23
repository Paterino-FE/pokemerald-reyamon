SSLANNN_CAPTAINSOFFICE_MapScripts::
	.byte 0


SSLANNN_CAPTAINSOFFICE_LANNN_Script::
	lock
	faceplayer
	msgbox SSLANNN_CAPTAINSOFFICE_LANNN_Text, MSGBOX_DEFAULT
	setflag FLAG_FINISHED_SSLANN
	setvar VAR_SSLANNN_DOOR_STATE, 1
	release
	end


SSLANNN_CAPTAINSOFFICE_LANNN_Text:
	.string "Uhm acshually this is just some\n"
	.string "placeholder text!$"
