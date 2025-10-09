SSLANNN_START_TEST_TALK_MUGSHOT::
	setvar VAR_0x8000, MUGSHOT_MABLEWOTT
	callnative DrawMugshot
	lock
	faceplayer
	msgbox SomeText, MSGBOX_NPC
	callnative ClearMugshot
	end

SomeText:
.string "Look Mable, I got a knife!!!$"

SSLANNN_START_MapScripts::
	.byte 0

SSLANNMUSICTEST::
	playbgm MUS_KARAGOLSHIP, FALSE
	end

SSLANNN_START_Door_Script::
	lock
	warp MAP_BIRTHDAY_HARBOR, 5, 10
	waitstate
	release
	end

SSLANN_START_Dirkling1_EventScript::
	lock
	faceplayer
	msgbox SSLANNN_START_Dirkling1_Text, MSGBOX_DEFAULT
	release
	end

SSLANNN_Start_Lilypal1_EventScript::
	lock
	faceplayer
	msgbox SSLANNN_START_Lilypal1_Text, MSGBOX_DEFAULT
	release
	end

SSLANNN_DoorIsLocked_EventScript::
	msgbox SSLANNN_Text_DoorIsLocked, MSGBOX_SIGN
	end

SSLANNN_START_Dirkling1_Text:
	.string "Don't worry! I will not use my\n"
	.string "FIRE BREATH (that I totally can do)!\p"
	.string "Fire on a boat is dangerous because\n"
	.string "the electricity bills for the AC\l"
	.string "will skyrocket!$"

SSLANNN_START_Lilypal1_Text:
	.string "I will help you save LILYPAD!\p"
	.string "And knowing my abilities, that means\n"
	.string "I will try to stay out of your way\l"
	.string "and let you do the rescuing.$"

SSLANNN_Text_DoorIsLocked:
	.string "The door is locked.$"