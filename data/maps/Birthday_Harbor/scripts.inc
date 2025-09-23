.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2

Birthday_Harbor_MapScripts::
	.byte 0

BirthdayIsland_Harbor_EventScript_Sailor::
	lock
	faceplayer
	msgbox BirthdayIsland_Harbor_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BirthdayIsland_Harbor_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_BIRTHDAY_HARBOR
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BirthdayIsland_Harbor_Text_SailorReturn:
	.string "What an oddly shaped island, eh?\n"
	.string "Do you want to return to LILYCOVE?$"

BirthdayIsland_Harbor_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

