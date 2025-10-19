Birthday_Mountain_Future_Floors_to_peak_MapScripts::
	.byte 0

Birthday_Mountain_Future_Floors_to_peak_GlacialRaven_EventScript::
	trainerbattle_single TRAINER_GLACIAL_RAVEN, Birthday_Mountain_Future_Floors_to_peak_GlacialRavenIntro_Text, Birthday_Mountain_Future_Floors_to_peak_GlacialRavenDefeat_Text
	msgbox Birthday_Mountain_Future_Floors_to_peak_GlacialRaven_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Mountain_Future_Floors_to_peak_GlacialRavenDefeat_Text:
	.string "Sorry, I was busy reading yuri,\n"
	.string "are you ready to start?...\p"
	.string "What do you mean, it's already over?$"

Birthday_Mountain_Future_Floors_to_peak_GlacialRaven_Text:
	.string "Hmm, maybe being nice increases my\n"
	.string "chance of getting DirkCool.\p"
	.string "HAPPY BIRTHDAY REYA!!!$"

Birthday_Mountain_Future_Floors_to_peak_GlacialRavenIntro_Text:
	.string "Oh hey {PLAYER}, Happy birthda-\p"
	.string "WAIT A MINUTE, I'm not supposed to\n"
	.string "be nice to the false EMPRESS!$"

Birthday_Mountain_Future_Floors_to_peak_Colourful_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_COLOURFUL, Birthday_Mountain_Future_Floors_to_peak_ColourfulPebbleHillBattle_EventScript
	msgbox Birthday_Mountain_Future_Floors_to_peak_ColourfulPostBattle_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Mountain_Future_Floors_to_peak_PebbleHill_EventScript::
	lock 
	faceplayer
	goto_if_not_defeated TRAINER_PEBBLE_HILL, Birthday_Mountain_Future_Floors_to_peak_ColourfulPebbleHillBattle_EventScript
	msgbox Birthday_Mountain_Future_Floors_to_peak_PebbleHillPostBattle_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Mountain_Future_Floors_to_peak_ColourfulPebbleHillBattle_EventScript::
	msgbox Birthday_Mountain_Future_Floors_to_peak_ColourfulPreBattle_Text, MSGBOX_DEFAULT
	msgbox Birthday_Mountain_Future_Floors_to_peak_PebbleHillPreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_COLOURFUL, Birthday_Mountain_Future_Floors_to_peak_ColourfulDefeat_Text, TRAINER_PEBBLE_HILL, Birthday_Mountain_Future_Floors_to_peak_PebbleHillDefeat_Text
	release
	end

Birthday_Mountain_Future_Floors_to_peak_ColourfulPostBattle_Text:
	.string "COLOURFUL: We may have just MET, but\n"
	.string "just SOJU know, I hope your birthday\l"
	.string "is full of SUN while you enjoy your\l"
	.string "favourite VODs and FLaPjacks...\l"
	.string "wait put that GUN away!$"

Birthday_Mountain_Future_Floors_to_peak_PebbleHillPostBattle_Text:
	.string "PEBBLEPAD HILL: ...$"

Birthday_Mountain_Future_Floors_to_peak_ColourfulPreBattle_Text:
	.string "COLOURFUL: We've finally MET in the\n"
	.string "arena! Prepare to be sent to the VOiD!$"

Birthday_Mountain_Future_Floors_to_peak_PebbleHillPreBattle_Text:
	.string "PEBBLEPAD HILL: ...$"

Birthday_Mountain_Future_Floors_to_peak_ColourfulDefeat_Text:
	.string "COLOURFUL: GUNned down...$"

Birthday_Mountain_Future_Floors_to_peak_PebbleHillDefeat_Text:
	.string "PEBBLEPAD HILL: ...$"



