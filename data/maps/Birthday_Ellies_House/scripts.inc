Birthday_Ellies_House_MapScripts::
    .byte 0

Birthday_Ellies_House_RotomNotInParty::
    lock
    msgbox Birthday_Ellies_House_RotomNotInParty_Text, MSGBOX_DEFAULT
    release
    end

Birthday_Ellies_House_BaseRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 0
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end

Birthday_Ellies_House_HeatRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 1
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end

Birthday_Ellies_House_WashRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 2
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end

Birthday_Ellies_House_FrostRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 3
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end
    
Birthday_Ellies_House_FanRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 4
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end
    
Birthday_Ellies_House_MowRotom::
    specialvar VAR_RESULT, IsRotomInParty
    goto_if_eq VAR_RESULT, FALSE, Birthday_Ellies_House_RotomNotInParty
    setvar VAR_0x8004, 5
	special TryChangeRotomForm
    callnative UpdateFollowingPokemon
    end

Birthday_Ellies_House_RotomNotInParty_Text:
    .string "ROTOM is not in your party!$"


