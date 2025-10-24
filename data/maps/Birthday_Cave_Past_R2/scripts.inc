.set LOCALID_GRAPE, 1

Birthday_Cave_Past_R2_MapScripts::
	.byte 0


Birthday_Cave_Past_R2_Sign1_EventScript::
	msgbox Birthday_Cave_Past_R2_Sign1_Text, MSGBOX_SIGN
	end

Birthday_Cave_Past_R2_Sign1_Text:
	.string "placeholder$"

Birthday_Cave_Past_R2_Sign2_EventScript::
	msgbox Birthday_Cave_Past_R2_Sign2_Text, MSGBOX_SIGN
	end

Birthday_Cave_Past_R2_Sign2_Text:
	.string "placeholder$"

Birthday_Cave_Past_R2_Sign3_EventScript::
	msgbox Birthday_Cave_Past_R2_Sign3_Text, MSGBOX_SIGN
	end

Birthday_Cave_Past_R2_Sign3_Text:
	.string "placeholder$"

Birthday_Cave_Past_R2_Grape_AttackScript::
	applymovement LOCALID_GRAPE, Birthday_Cave_Past_R2_Grape_Movement_1
	waitmovement 0
	setvar VAR_GRAPE_EVENT, 1
	goto Birthday_Cave_Past_R2_Grape_EventScript
	release
	end

Birthday_Cave_Past_R2_Grape_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_GRAPE, Birthday_Cave_Past_R2_GrapeBattle_EventScript
	msgbox Birthday_Cave_Past_R2_Grape_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R2_GrapeBattle_EventScript::
	trainerbattle_single TRAINER_GRAPE, Birthday_Cave_Past_R2_GrapeIntro_Text, Birthday_Cave_Past_R2_GrapeDefeat_Text
	release
	end

Birthday_Cave_Past_R2_GrapeDefeat_Text:
	.string "Jeez, are you 10k MMR or something?!\n"
	.string "That battle was intense!!$"

Birthday_Cave_Past_R2_Grape_Text:
	.string "Girl, you look like you could use a\n"
	.string "little rest!\p"
	.string "You're the hardest worker I know,\n"
	.string "but don't forget to take breaks\l"
	.string "sometimes, ok?$"

Birthday_Cave_Past_R2_GrapeIntro_Text:
	.string "Hey {PLAYER}!! Just because you're my\n"
	.string "friend doesn't mean I'll be going\l"
	.string "easy on you - prepare yourself, GAO!$"

Birthday_Cave_Past_R2_Grape_Movement_1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Birthday_Cave_Past_R2_Grape_Movement_2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

Birthday_Cave_Past_R2_Oldman1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Cave_Past_R2_Oldman1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R2_Oldman1_Text:
	.string "placeholder$"

Birthday_Cave_Past_R2_Oldman2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Cave_Past_R2_Oldman2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R2_Oldman2_Text:
	.string "placeholder$"

Birthday_Cave_Past_R2_Oldwoman1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Cave_Past_R2_Oldwoman1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R2_Oldwoman1_Text:
	.string "placeholder$"



