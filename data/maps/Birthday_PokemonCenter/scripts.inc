.set LOCALID_NURSE, 1

Birthday_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Birthday_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Birthday_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BIRTHDAY_ISLAND_MAIN_VILLAGE
	end

Birthday_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Birthday_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_WantSomeStuff
	waitmessage
	pokemart Birthday_Mart_Pokemart
	msgbox gText_NeverSnitch, MSGBOX_DEFAULT
	release
	end

Birthday_PokemonCenter_1F_EventScript_MapLilypal::
	lock
	msgbox Birthday_PokemonCenter_1F_Text_MapLilypal, MSGBOX_DEFAULT
	release
	end

Birthday_PokemonCenter_1F_EventScript_Lilypal1::
	lock
	faceplayer
	msgbox Birthday_PokemonCenter_1F_Text_Lilypal1, MSGBOX_DEFAULT
	release
	end

Birthday_PokemonCenter_1F_EventScript_Lilypal2::
	lock
	faceplayer
	msgbox Birthday_PokemonCenter_1F_Text_Lilypal2, MSGBOX_DEFAULT
	release
	end

.align 2
Birthday_Mart_Pokemart:
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_SHADOW_MAIL
	.2byte ITEM_MOUTH_WASH
	pokemartlistend

gText_WantSomeStuff::
	.string "Want some good drugs?\p"
	.string "FLP can get you anything!$"

gText_NeverSnitch:
	.string "Don't snitch on me...\n"
	.string "I'll know if you do.$"

Birthday_PokemonCenter_1F_Text_Lilypal1:
	.string "Have you been to ROSUURI's\n"
	.string "BAKERY? I would go every\l"
	.string "day if I could afford it!$"

Birthday_PokemonCenter_1F_Text_Lilypal2:
	.string "There are multiple paths in the\n"
	.string "north of this village.\p"
	.string "But I'm too scared to take any\n"
	.string "of them!$"


Birthday_PokemonCenter_1F_Text_MapLilypal:
	.string "YEP! This MAP does not even have\n"
	.string "BIRTHDAY ISLAND on it!$"
