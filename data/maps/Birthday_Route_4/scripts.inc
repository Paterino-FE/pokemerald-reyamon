Birthday_Route_4_MapScripts::
	.byte 0

Birthday_Route_4_OcarinaOfMe_EventScript::
	lock
	faceplayer
	trainerbattle_single TRAINER_OCARINAOFME, Birthday_Route_4_OcarinaOfMeIntro_Text, Birthday_Route_4_OcarinaOfMeDefeat_Text
	msgbox Birthday_Route_4_OcarinaOfMe_Text, MSGBOX_DEFAULT
	release
	end


Birthday_Route_4_Sign1_EventScript::
	msgbox Birthday_Route_3_Sign1_Text, MSGBOX_AUTOCLOSE
	end

Birthday_Route_4_Sign1_Text:
	.string "placeholder$"

Birthday_Route_4_OcarinaOfMeDefeat_Text:
	.string "I caught a DRAGALGE!\n"
	.string "Happy birthday {PLAYER}!\p"
	.string "I hope this battle did not\n"
	.string "DRAG-ON-GE...or something.$"

Birthday_Route_4_OcarinaOfMe_Text:
	.string "I caught a MAGIKARP!\n"
	.string "I hope you have a MAGIKARPLE birthday!\p"
	.string "...like magical... yeah I got nothing\n"
	.string "for MAGIKARP... sorry for the bad\l"
	.string "puns...$"

Birthday_Route_4_OcarinaOfMeIntro_Text:
	.string "{PLAYER} look I caught a RELICANTH!\n"
	.string "Hmm, you RELICANTH win this battle!$"

Birthday_Route_4_Tsunami_EventScript::
	trainerbattle_single TRAINER_TSUNAMI, Birthday_Route_4_TsunamiIntro_Text, Birthday_Route_4_TsunamiDefeat_Text @TSUNAMI needs to be placed in instead of TRAINER_OCARINAOFME
	msgbox Birthday_Route_4_Tsunami_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Route_4_TsunamiDefeat_Text:
	.string "I'm Pissed, I'm Pissed, I'm Pissed,\n"
	.string "I'm Pissed, I'm Pissed!$"

Birthday_Route_4_Tsunami_Text:
	.string "I'm Pissed, I'm Pissed, I'm Pissed,\n"
	.string "I'm Pissed, I'm Pissed!$"

Birthday_Route_4_TsunamiIntro_Text:
	.string "Load up the Blumenkranz.\n"
	.string "Because I'm about to Kill La Kill you!$"
