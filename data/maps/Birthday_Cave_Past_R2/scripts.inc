.set LOCALID_GRAPE, 1

Birthday_Cave_Past_R2_MapScripts::
	.byte 0

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
	msgbox Birthday_Cave_Past_R2_GrapePreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_GRAPE, Birthday_Cave_Past_R2_GrapeIntro_Text, Birthday_Cave_Past_R2_GrapeDefeat_Text
	release
	end

Birthday_Cave_Past_R2_GrapePreBattle_Text:
	.string "PreBattle.$"

Birthday_Cave_Past_R2_GrapeDefeat_Text:
	.string "Defeat.$"

Birthday_Cave_Past_R2_Grape_Text:
	.string "Text.$"

Birthday_Cave_Past_R2_GrapeIntro_Text:
	.string "Intro.$"

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

Birthday_Cave_Past_R2_Oldman2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Cave_Past_R2_Oldman2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R2_Oldman2_Text:

Birthday_Cave_Past_R2_Oldwoman1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Cave_Past_R2_Oldwoman1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Cave_Past_R2_Oldwoman1_Text:
