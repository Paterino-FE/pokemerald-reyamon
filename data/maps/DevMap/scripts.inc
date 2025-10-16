DevMap_MapScripts::
	.byte 0

DEVMAP_START_TEST_TALK_MUGSHOT1::
	msgbox_mugshot DEV_MAP_SomeText, MSGBOX_NPC, MUGSHOT_BOWALL, CLEAR_MUGSHOT
	msgbox_mugshot DEV_MAP_SomeText2, MSGBOX_NPC, MUGSHOT_ROSUURI, CLEAR_MUGSHOT
	end

DEVMAP_START_TEST_TALK_MUGSHOT2::
	msgbox_mugshot2 DEV_MAP_SomeText2, MSGBOX_NPC, MUGSHOT_ROSUURI, CLEAR_MUGSHOT
	end

DEV_MAP_SomeText:
.string "Damn, this looks like a content farm.$"

DEV_MAP_SomeText2:
.string "Crazy$"
