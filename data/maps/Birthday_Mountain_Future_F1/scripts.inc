Birthday_Mountain_Future_F1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Birthday_Mountain_Future_F1_OnResume
	.byte 0

Birthday_Mountain_Future_F1_OnResume:
	setescapewarp MAP_BIRTHDAY_ROUTE_3, 24, 20
	end


Birthday_Mountain_Future_F1_Ciaran_EventScript::
	trainerbattle_single TRAINER_CIARAN, Birthday_Mountain_Future_F1_CiaranIntro_Text, Birthday_Mountain_Future_F1_CiaranDefeat_Text
	msgbox Birthday_Mountain_Future_F1_CiaranPostBattle_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Mountain_Future_F1_CiaranIntro_Text:
	.string "Hello There!$"
	
Birthday_Mountain_Future_F1_CiaranDefeat_Text:
	.string "This battle was dedicated to the\n"
	.string "brave mujahideen fighters of\l"
	.string "Afghanistan!$"

Birthday_Mountain_Future_F1_CiaranPostBattle_Text:
	.string "Goodbye There!$"


