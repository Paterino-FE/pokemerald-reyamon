Birthday_Main_Villahe_House2_MapScripts::
	.byte 0


Birthday_Main_Villahe_House2_DogmaticalEvent::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_DOGMATICAL, Birthday_Main_Villahe_House2_Dogmatical_Battle_EventScript
	msgbox Birthday_Main_Villahe_House2_Dogmatical_AfterText, MSGBOX_DEFAULT
	release
	end

Birthday_Main_Villahe_House2_Dogmatical_Battle_EventScript::
	msgbox Birthday_Main_Villahe_House2_Dogmatical_IntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DOGMATICAL, Birthday_Main_Villahe_House2_Dogmatical_DefeatText
	release
	end

Birthday_Main_Villahe_House2_MawileEvent::
	lock
	faceplayer
	msgbox Birthday_Main_Villahe_House2_Mawile_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Main_Villahe_House2_Dogmatical_IntroText:
	.string "I loved working for you on this...\p"
	.string "but now it's time to battle!$"

Birthday_Main_Villahe_House2_Dogmatical_DefeatText:
	.string "I'd win, if I got the time to do a\n"
	.string "correct battle sprite for myself,\p"
	.string "maybe next time?$"

Birthday_Main_Villahe_House2_Dogmatical_AfterText:
	.string "Yes that was me, the artist who\n"
	.string "animated the wiggle tail for VYRAL.$"

Birthday_Main_Villahe_House2_Mawile_Text:
	.string "A sticky note sticks on her head.\p"
	.string "'Why no mega allowed, T-T'$"