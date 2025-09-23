SSLANNN_START_MapScripts::
	.byte 0

SSLANNMUSICTEST::
	playbgm MUS_KARAGOLSHIP, FALSE
	end

SSLANNN_START_Door_Script::
	lock
	warp MAP_BIRTHDAY_HARBOR, 8, 4
	waitstate
	release
	end

