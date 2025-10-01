.set LOCALID_NURSE, 1

Birthday_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Birthday_PokemonCenter_1F_OnTransition
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

