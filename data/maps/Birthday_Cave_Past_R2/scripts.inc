Birthday_Cave_Past_R2_MapScripts::
	.byte 0

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

Birthday_Cave_Past_R2_GrapeDefeat_Text:

Birthday_Cave_Past_R2_Grape_Text:

Birthday_Cave_Past_R2_GrapeIntro_Text:

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
