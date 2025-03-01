SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "If you’re here, do you want to hear\n"
	.string "my new sales pitch?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Maybe it needs some more work…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Well how about this pitch:\p"
	.string "Tentacool Cruises:\n"
	.string "Wrap yourself in luxury!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Hey, I’m sorry but you’re not\n"
	.string "allowed back this way!$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Nobody ever listens to me!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "I can’t believe we already\n"
	.string "lost the map to get back…$"

