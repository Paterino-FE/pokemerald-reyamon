.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_MAXIE, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_KYOGRE_SLEEPING, 7

SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	waitstate
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_KYOGRE_SLEEPING
	addobject LOCALID_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "HATZOOME: Oh, you did come to invest!$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "HATZOOME: Fufufu…\n"
	.string "So it was you, after all.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "HATZOOME: You… you still don’t want\n"
	.string "to invest? That’s it! I’m done!\p"
	.string "I am so sick of these stupid\n"
	.string "timeshares and I’m so tired of you\l"
	.string "making me feel even dumber.$"
 
SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "HATZOOME: How was I supposed to know\n"
	.string "the timeshares were a scam and the\l"
	.string "cruise ship sucks!\p"
	.string "But KYOGRE can finally help me fix\n"
	.string "everything! I’ve failed plenty of\l"
	.string "times leading up to this, but now\l"
	.string "it’s my time to win!$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "Well…\n"
	.string "That’s not really what I meant to do…$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "Good job, you beat the resident\n"
	.string "girlfailure. You must be really proud!\p"
	.string "But it doesn’t matter anymore! I have\n"
	.string "this in my possession! With this Red\l"
	.string "Orb, I can finally make Kyogre…$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "The RED ORB suddenly began shining\n"
	.string "by itself!$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "HATZOOME: What?!\p"
	.string "I didn’t do that. I didn’t touch\n"
	.string "anything. Why did the Red Orb…\p"
	.string "Where’s KYOGRE?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "HATZOOME: Uhhhhhh? Oh, it’s from an\n"
	.string "employee outside…$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "HATZOOME: What do you want?\p"
	.string "Oh…\n"
	.string "It’s raining heavily? Finally!\p"
	.string "I finally did something RIGHT!!!.\n"
	.string "That’s why I did it! With KYOGRE\l"
	.string "flooding the world, this timeshare\l"
	.string "might finally be worth something.\p"
	.string "What?!\p"
	.string "There’s more rain than we planned?\n"
	.string "Oh, you’re in danger? Keith got\l"
	.string "swept away? Oh, this is bad…\p"
	.string "This wasn’t my plan…\p"
	.string "Save Keith and I’ll be right out!$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "HATZOOME: The DRAGON GANG must have\n"
	.string "done something…\p"
	.string "The RED ORB should have controlled\n"
	.string "Kyogre…But…Why? Why is KYOGRE doing\l"
	.string "this?\p"
	.string "Why?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "LYRA: HATZOOME no!\p"
	.string "You’re using the wrong orb! You\n"
	.string "imbecile! You’ve unleashed Kyogre!?\p"
	.string "It will bring down rainstorms until\n"
	.string "the whole world is drowned! Your\l"
	.string "timeshares will be worthless and\l"
	.string "my real daughter (real) will perish!\p"
	.string "What have you done?$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "HATZOOME: I didn’t do anything wrong!\p"
	.string "You’re the ones that upset Groudon!\p"
	.string "This has to be the right orb! You’re\n"
	.string "just trying to trick me like always!\p"
	.string "I just need to show KYOGRE their Red\n"
	.string "Orb and everything will be fine again!\p"
	.string "My timeshare won’t be worthless and\n"
	.string "everything will be fine…$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "LYRA: IT’S THE WRONG ORB. KYOGRE IS\n"
	.string "BLUE. BLUE. AND YOU USED A RED ORB\l"
	.string "ON IT? Are you stupid?\p"
	.string "How would any supposedly dangerous,\n"
	.string "intelligent villain get these orbs\l"
	.string "muddled up and let it scupper their\l"
	.string "master plan?\p"
	.string "It doesn’t matter now anyway.\p"
	.string "Step outside. Witness the world you\n"
	.string "(and I guess a little bit me but\l"
	.string "mostly you) have wrought.$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "LYRA: {PLAYER}, come on, you have\n"
	.string "to get out of here, too!$"
