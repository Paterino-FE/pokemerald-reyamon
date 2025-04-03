MagmaHideout_Sleep_MapScripts::
	.byte 0

MagmaHideout_Sleep_EventScript_Gal::
	msgbox MagmaHideout_Sleep_Text_Svelte_Bed, MSGBOX_NPC
	end

MagmaHideout_Sleep_Text_Svelte_Bed:
	.string "This is SVELTE's room that we\n"
	.string "had to build in a day.\p"
	.string "She mentioned you can use\n"
	.string "her bed to heal up!$"

MagmaHideout_Sleep_EventScript_Heal::
	lockall
	msgbox MagmaHideout_Sleep_Text_Sleepy, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	callnative UpdateFollowingPokemon
	setvar VAR_TEMP_1, 1
	releaseall
	end

MagmaHideout_Sleep_Text_Sleepy:
	.string "{PLAYER}: I feel so...\p"
	.string "Sleepy...$"

MagmaHideout_Sleep_Movement_Player:
	face_down
	step_end
