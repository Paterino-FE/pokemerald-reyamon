SSLANNN_START_R3_MapScripts::
	.byte 0

SSLANNN_START_R3_MagicalKohaku_EventScript::
	trainerbattle_single TRAINER_MAGICALKOHAKU, SSLANNN_START_R3_MagicalKohakuIntro_Text, SSLANNN_START_R3_MagicalKohakuDefeat_Text
	msgbox SSLANNN_START_R3_MagicalKohakuPostBattle_Text, MSGBOX_DEFAULT
	release
	end

SSLANNN_START_R3_MagicalKohakuIntro_Text:
	.string "GAH?! It's YOU! You beat up my\n"
	.string "sunflowers and you think just\l"
	.string "because it's your birthday, you\l"
	.string "can do it again?!\p"
	.string "This time I have a fun surprise\n"
	.string "in store!$"
	
SSLANNN_START_R3_MagicalKohakuDefeat_Text:
	.string "Okay fine, happy birthday to you.\n"
	.string "You already are gonna rob me of my\l"
	.string "money so I don't need to buy you a\l"
	.string "present! Hmph!$"

SSLANNN_START_R3_MagicalKohakuPostBattle_Text:
	.string "Hmph!$"

