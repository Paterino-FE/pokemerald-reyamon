enum
{
    PAGE_TITLE,
    PAGE_LEAD,
    PAGE_CODING,
    PAGE_SPRITES,
    PAGE_BALANCE,
    PAGE_INSERTING,
    PAGE_STORY,
    PAGE_BUGFINDER,
    PAGE_PLAYTESTING,
    PAGE_PLAYTESTING_2,
    PAGE_CYNTHIA,
    PAGE_INTEL,
    PAGE_SPECIALTHANKS,
    PAGE_COUNT
};

#define ENTRIES_PER_PAGE 5

static const u8 sCreditsText_EmptyString[]                    = _("");
static const u8 sCreditsText_PkmnEmeraldVersion[]             = _("POKéMON EMERALD VERSION");
static const u8 sCreditsText_Credits[]                        = _("Credits");
static const u8 sCreditsText_ProjectLead[]                        = _("Project Lead");
static const u8 sCreditsText_Coding[]                        = _("Coding and Encounters");
static const u8 sCreditsText_Sprites[]                        = _("Sprites");
static const u8 sCreditsText_GameBalance[]                        = _("Game Balance");
static const u8 sCreditsText_InsertingData[]                        = _("Inserting Data");
static const u8 sCreditsText_Story[]                        = _("Story");
static const u8 sCreditsText_TopBugFinder[]                        = _("TopBugFinder");
static const u8 sCreditsText_PlayTester[]                        = _("Play Testers");
static const u8 sCreditsText_CynthiaTheme[]                        = _("Cynthia Theme");
static const u8 sCreditsText_IntelGathering[]                        = _("Intel gathering on Reya");
static const u8 sCreditsText_SpecialThanks[]                        = _("SPECIAL THANKS");

static const u8 sCreditsText_Paterino[]                        = _("Paterino");
static const u8 sCreditsText_Theastraza[]                        = _("Theastraza");
static const u8 sCreditsText_Forty[]                        = _("Forty");
static const u8 sCreditsText_Felixr2[]                        = _("Felixr2");
static const u8 sCreditsText_Luminel[]                        = _("Luminel");
static const u8 sCreditsText_MagicalKohaku[]                        = _("MagicalKohaku");
static const u8 sCreditsText_Lyra[]                        = _("Lyra");
static const u8 sCreditsText_Hatzoome[]                        = _("Hatzoome");
static const u8 sCreditsText_Agdaleks[]                        = _("Agdaleks");
static const u8 sCreditsText_Swordficsh[]                        = _("Swordficsh");
static const u8 sCreditsText_HeiSe[]                        = _("HeiSe");
static const u8 sCreditsText_Quattuor4[]                        = _("Quattuor4");
static const u8 sCreditsText_FireFireFire[]                        = _("FireFireFire");
static const u8 sCreditsText_DogMatical[]                        = _("DogMatical");
static const u8 sCreditsText_Yogurcomics[]                        = _("Yogurcomics");
static const u8 sCreditsText_Kaaaaaarp[]                        = _("Kaaaaaarp");
static const u8 sCreditsText_Zhongbros[]                        = _("The Zhong Bros");
static const u8 sCreditsText_EmeraldComposer[]                        = _("EmeraldComposer");
static const u8 sCreditsText_TheReyaCommunity[]                        = _("The Reya community");

static const struct CreditsEntry sCreditsEntry_EmptyString                      = { 0, FALSE, sCreditsText_EmptyString};
static const struct CreditsEntry sCreditsEntry_PkmnEmeraldVersion               = { 7,  TRUE, sCreditsText_PkmnEmeraldVersion};
static const struct CreditsEntry sCreditsEntry_Credits                          = {11,  TRUE, sCreditsText_Credits};
static const struct CreditsEntry sCreditsEntry_ProjectLead                = { 8,  TRUE, sCreditsText_ProjectLead};
static const struct CreditsEntry sCreditsEntry_Coding                         = {12,  TRUE, sCreditsText_Coding};
static const struct CreditsEntry sCreditsEntry_Sprites                        = {12,  TRUE, sCreditsText_Sprites};
static const struct CreditsEntry sCreditsEntry_GameBalance                         = {12,  TRUE, sCreditsText_GameBalance};
static const struct CreditsEntry sCreditsEntry_InsertingData                        = {12,  TRUE, sCreditsText_InsertingData};
static const struct CreditsEntry sCreditsEntry_Story                        = {12,  TRUE, sCreditsText_Story};
static const struct CreditsEntry sCreditsEntry_TopBugFinder                        = {12,  TRUE, sCreditsText_TopBugFinder};
static const struct CreditsEntry sCreditsEntry_PlayTester                         = {12,  TRUE, sCreditsText_PlayTester};
static const struct CreditsEntry sCreditsEntry_CynthiaTheme                        = {12,  TRUE, sCreditsText_CynthiaTheme};
static const struct CreditsEntry sCreditsEntry_IntelGathering                        = {12,  TRUE, sCreditsText_IntelGathering};
static const struct CreditsEntry sCreditsEntry_SpecialThanks                         = {12,  TRUE, sCreditsText_SpecialThanks};

static const struct CreditsEntry sCreditsEntry_Paterino                        = {12,  FALSE, sCreditsText_Paterino};
static const struct CreditsEntry sCreditsEntry_Theastraza                         = {12,  FALSE, sCreditsText_Theastraza};
static const struct CreditsEntry sCreditsEntry_Forty                       = {12,  FALSE, sCreditsText_Forty};
static const struct CreditsEntry sCreditsEntry_Felixr2                        = {12,  FALSE, sCreditsText_Felixr2};
static const struct CreditsEntry sCreditsEntry_Luminel                         = {12,  FALSE, sCreditsText_Luminel};
static const struct CreditsEntry sCreditsEntry_MagicalKohaku                         = {12,  FALSE, sCreditsText_MagicalKohaku};
static const struct CreditsEntry sCreditsEntry_Lyra                         = {12,  FALSE, sCreditsText_Lyra};
static const struct CreditsEntry sCreditsEntry_Hatzoome                         = {12,  FALSE, sCreditsText_Hatzoome};
static const struct CreditsEntry sCreditsEntry_Agdaleks                         = {12,  FALSE, sCreditsText_Agdaleks};
static const struct CreditsEntry sCreditsEntry_Swordficsh                         = {12,  FALSE, sCreditsText_Swordficsh};
static const struct CreditsEntry sCreditsEntry_HeiSe                         = {12,  FALSE, sCreditsText_HeiSe};
static const struct CreditsEntry sCreditsEntry_Quattuor4                         = {12,  FALSE, sCreditsText_Quattuor4};
static const struct CreditsEntry sCreditsEntry_FireFireFire                         = {12,  FALSE, sCreditsText_FireFireFire};
static const struct CreditsEntry sCreditsEntry_DogMatical                         = {12,  FALSE, sCreditsText_DogMatical};
static const struct CreditsEntry sCreditsEntry_Kaaaaaarp                         = {12,  FALSE, sCreditsText_Kaaaaaarp};
static const struct CreditsEntry sCreditsEntry_Yogurcomics                        = {12,  FALSE, sCreditsText_Yogurcomics};
static const struct CreditsEntry sCreditsEntry_Zhongbros                         = {12,  FALSE, sCreditsText_Zhongbros};
static const struct CreditsEntry sCreditsEntry_EmeraldComposer                         = {12,  FALSE, sCreditsText_EmeraldComposer};
static const struct CreditsEntry sCreditsEntry_TheReyaCommunity                         = {12,  FALSE, sCreditsText_TheReyaCommunity};


#define _ &sCreditsEntry_EmptyString
static const struct CreditsEntry *const sCreditsEntryPointerTable[PAGE_COUNT][ENTRIES_PER_PAGE] =
{
    [PAGE_TITLE] = {
        _,
        &sCreditsEntry_PkmnEmeraldVersion,
        &sCreditsEntry_Credits,
        _,
        _
    },
    [PAGE_LEAD] = {
        _,
        &sCreditsEntry_ProjectLead,
        &sCreditsEntry_Paterino,
        &sCreditsEntry_Theastraza,
        _,
    },
    [PAGE_CODING] = {
        _,
        &sCreditsEntry_Coding,
        &sCreditsEntry_Paterino,
        &sCreditsEntry_Forty,
        _,
    },
    [PAGE_SPRITES] = {
        &sCreditsEntry_Sprites,
        &sCreditsEntry_Paterino,
        &sCreditsEntry_DogMatical,
        &sCreditsEntry_Yogurcomics,
        &sCreditsEntry_Kaaaaaarp,

    },
    [PAGE_BALANCE] = {
        &sCreditsEntry_GameBalance,
        &sCreditsEntry_Theastraza,
        &sCreditsEntry_Felixr2,
        &sCreditsEntry_Forty,
        &sCreditsEntry_Luminel,
    },
    [PAGE_INSERTING] = {
        &sCreditsEntry_InsertingData,
        &sCreditsEntry_Forty,
        &sCreditsEntry_Felixr2,
        &sCreditsEntry_MagicalKohaku,
        &sCreditsEntry_Paterino,
    },
    [PAGE_STORY] = {
        &sCreditsEntry_Story,
        &sCreditsEntry_Forty,
        &sCreditsEntry_Theastraza,
        &sCreditsEntry_Lyra,
        &sCreditsEntry_Hatzoome,
    },

    
    [PAGE_BUGFINDER] = {
        _,
        &sCreditsEntry_TopBugFinder,
        &sCreditsEntry_Lyra,
        _,
        _,
    },

    [PAGE_PLAYTESTING] = {
        &sCreditsEntry_PlayTester,
        &sCreditsEntry_Lyra,
        &sCreditsEntry_Agdaleks,
        &sCreditsEntry_Forty,
        &sCreditsEntry_Felixr2,
    },

    [PAGE_PLAYTESTING_2] = {
        &sCreditsEntry_PlayTester,
        &sCreditsEntry_MagicalKohaku,
        &sCreditsEntry_Swordficsh,
        &sCreditsEntry_HeiSe,
        &sCreditsEntry_Quattuor4,
    },

    [PAGE_CYNTHIA] = {
        _,
        &sCreditsEntry_CynthiaTheme,
        &sCreditsEntry_Zhongbros,
        &sCreditsEntry_EmeraldComposer,
        _,
    },

    [PAGE_INTEL] = {
        _,
        &sCreditsEntry_IntelGathering,
        &sCreditsEntry_Theastraza,
        _,
        _,
    },

    [PAGE_SPECIALTHANKS] = {
        _,
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_TheReyaCommunity,
        _,
        _,
    },

};
#undef _
