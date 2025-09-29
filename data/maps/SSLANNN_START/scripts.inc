SSLANNN_START_TEST_TALK_MUGSHOT::
	setvar VAR_0x8000, MUGSHOT_ROSUURI
	callnative DrawMugshot
	lock
	faceplayer
	msgbox SomeText, MSGBOX_NPC
	callnative ClearMugshot
	end

SomeText:
.string "Hey Reya, I hope you are doing well!!!.$"

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

