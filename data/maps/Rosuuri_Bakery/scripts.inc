Rosuuri_Bakery_MapScripts::
	.byte 0

Birthday_Rosuuri_Bakery_Rosuuri_EventScript::
	lock
	faceplayer
	goto_if_not_defeated TRAINER_ROSUURI, Birthday_Rosuuri_Bakery_RosuuriBattle_EventScript
	msgbox Birthday_Rosuuri_Bakery_Rosuuri_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_RosuuriBattle_EventScript::
	msgbox Birthday_Rosuuri_Bakery_RosuuriPreBattle_Text, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_ROSUURI, Birthday_Rosuuri_Bakery_RosuuriInfo_Text, Birthday_Rosuuri_Bakery_RosuuriDefeat_Text
	release
	end

Birthday_Rosuuri_Bakery_RosuuriPreBattle_Text:

Birthday_Rosuuri_Bakery_RosuuriDefeat_Text:

Birthday_Rosuuri_Bakery_Rosuuri_Text:

Birthday_Rosuuri_Bakery_RosuuriInfo_Text:

Birthday_Rosuuri_Bakery_Agdalek_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Agdalek_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Agdalek_Text:

Birthday_Rosuuri_Bakery_Lilypal1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Lilypal1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Lilypal1_Text:

Birthday_Rosuuri_Bakery_Lilypal2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Lilypal2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Lilypal2_Text:

Birthday_Rosuuri_Bakery_Lilypal3_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Lilypal3_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Lilypal3_Text:

Birthday_Rosuuri_Bakery_Dirkling1_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Dirkling1_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Dirkling1_Text:

Birthday_Rosuuri_Bakery_Dirkling2_EventScript::
	lock
	faceplayer
	msgbox Birthday_Rosuuri_Bakery_Dirkling2_Text, MSGBOX_DEFAULT
	release
	end

Birthday_Rosuuri_Bakery_Dirkling2_Text:
