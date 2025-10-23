Birthday_Route_2_MapScripts::
	.byte 0

Birthday_Route_2_Swordficsh_EventScript::
	trainerbattle_single TRAINER_SWORDFICSH, Birthday_Route_2_SwordficshIntro_Text, Birthday_Route_2_SwordficshDefeat_Text
	msgbox Birthday_Route_2_Swordficsh_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_2_SwordficshDefeat_Text:
	.string "Drat. Happy Birthday REYA!!!\n"
	.string "Your creativity and work is genuinely\l"
	.string "inspiring! Woweez$"		

Birthday_Route_2_Swordficsh_Text:
	.string "WOWEEZ$"

Birthday_Route_2_SwordficshIntro_Text:
	.string "I hope RAYQUAZA doesn't one-shot\n"
	.string "all of my friends again...$"
			
			
			
