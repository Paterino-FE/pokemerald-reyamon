#include "global.h"
#include "blit.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "constants/mugshots.h"

#define MUGSHOT_PALETTE_NUM 13

struct Mugshot{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32* image;
    const u16* palette;
};

void DrawMugshot(void); //VAR_0x8000 = mugshot id
void DrawMugshotAtPos(void); //VAR_0x8000 = mugshot id, VAR_0x8001 = x, VAR_0x8002 = y
void ClearMugshot(void);

static const u32 sMugshotImg_Reya[] = INCBIN_U32("graphics/mugshots/reya.4bpp.lz");
static const u16 sMugshotPal_Reya[] = INCBIN_U16("graphics/mugshots/reya.gbapal");
static const u32 sMugshotImg_Rosuuri[] = INCBIN_U32("graphics/mugshots/rosuuri.4bpp.lz");
static const u16 sMugshotPal_Rosuuri[] = INCBIN_U16("graphics/mugshots/rosuuri.gbapal");
static const u32 sMugshotImg_Lilypad[] = INCBIN_U32("graphics/mugshots/wally.4bpp.lz");
static const u16 sMugshotPal_Lilypad[] = INCBIN_U16("graphics/mugshots/wally.gbapal");
static const u32 sMugshotImg_Vyral[] = INCBIN_U32("graphics/mugshots/brendan.4bpp.lz");
static const u16 sMugshotPal_Vyral[] = INCBIN_U16("graphics/mugshots/brendan.gbapal");
static const u32 sMugshotImg_Lilypal[] = INCBIN_U32("graphics/mugshots/lilypal.4bpp.lz");
static const u16 sMugshotPal_Lilypal[] = INCBIN_U16("graphics/mugshots/lilypal.gbapal");
static const u32 sMugshotImg_Dirkling[] = INCBIN_U32("graphics/mugshots/dirkling.4bpp.lz");
static const u16 sMugshotPal_Dirkling[] = INCBIN_U16("graphics/mugshots/dirkling.gbapal");
static const u32 sMugshotImg_Emilia[] = INCBIN_U32("graphics/mugshots/emilia.4bpp.lz");
static const u16 sMugshotPal_Emilia[] = INCBIN_U16("graphics/mugshots/emilia.gbapal");
static const u32 sMugshotImg_Atsui[] = INCBIN_U32("graphics/mugshots/salon_maiden_anabel.4bpp.lz");
static const u16 sMugshotPal_Atsui[] = INCBIN_U16("graphics/mugshots/salon_maiden_anabel.gbapal");
static const u32 sMugshotImg_Hams[] = INCBIN_U32("graphics/mugshots/leader_brawly.4bpp.lz");
static const u16 sMugshotPal_Hams[] = INCBIN_U16("graphics/mugshots/leader_brawly.gbapal");
static const u32 sMugshotImg_Clor[] = INCBIN_U32("graphics/mugshots/leader_clor.4bpp.lz");
static const u16 sMugshotPal_Clor[] = INCBIN_U16("graphics/mugshots/leader_clor.gbapal");
static const u32 sMugshotImg_Dalek[] = INCBIN_U32("graphics/mugshots/leader_wattson.4bpp.lz");
static const u16 sMugshotPal_Dalek[] = INCBIN_U16("graphics/mugshots/leader_wattson.gbapal");
static const u32 sMugshotImg_Gabe[] = INCBIN_U32("graphics/mugshots/leader_flannery.4bpp.lz");
static const u16 sMugshotPal_Gabe[] = INCBIN_U16("graphics/mugshots/leader_flannery.gbapal");
static const u32 sMugshotImg_Ange[] = INCBIN_U32("graphics/mugshots/leader_norman.4bpp.lz");
static const u16 sMugshotPal_Ange[] = INCBIN_U16("graphics/mugshots/leader_norman.gbapal");
static const u32 sMugshotImg_Thea[] = INCBIN_U32("graphics/mugshots/leader_winona.4bpp.lz");
static const u16 sMugshotPal_Thea[] = INCBIN_U16("graphics/mugshots/leader_winona.gbapal");
static const u32 sMugshotImg_Skyward[] = INCBIN_U32("graphics/mugshots/leader_tate_and_liza.4bpp.lz");
static const u16 sMugshotPal_Skyward[] = INCBIN_U16("graphics/mugshots/leader_tate_and_liza.gbapal");
static const u32 sMugshotImg_Lumi[] = INCBIN_U32("graphics/mugshots/leader_juan.4bpp.lz");
static const u16 sMugshotPal_Lumi[] = INCBIN_U16("graphics/mugshots/leader_juan.gbapal");
static const u32 sMugshotImg_Arle[] = INCBIN_U32("graphics/mugshots/elite_four_sidney.4bpp.lz");
static const u16 sMugshotPal_Arle[] = INCBIN_U16("graphics/mugshots/elite_four_sidney.gbapal");
static const u32 sMugshotImg_Astarion[] = INCBIN_U32("graphics/mugshots/elite_four_phoebe.4bpp.lz");
static const u16 sMugshotPal_Astarion[] = INCBIN_U16("graphics/mugshots/elite_four_phoebe.gbapal");
static const u32 sMugshotImg_Cynthia[] = INCBIN_U32("graphics/mugshots/elite_four_glacia.4bpp.lz");
static const u16 sMugshotPal_Cynthia[] = INCBIN_U16("graphics/mugshots/elite_four_glacia.gbapal");
static const u32 sMugshotImg_Satsuki[] = INCBIN_U32("graphics/mugshots/elite_four_drake.4bpp.lz");
static const u16 sMugshotPal_Satsuki[] = INCBIN_U16("graphics/mugshots/elite_four_drake.gbapal");
static const u32 sMugshotImg_Forty[] = INCBIN_U32("graphics/mugshots/blaine_front_pic.4bpp.lz");
static const u16 sMugshotPal_Forty[] = INCBIN_U16("graphics/mugshots/blaine_front_pic.gbapal");
static const u32 sMugshotImg_Hatzoome[] = INCBIN_U32("graphics/mugshots/aqua_leader_archie.4bpp.lz");
static const u16 sMugshotPal_Hatzoome[] = INCBIN_U16("graphics/mugshots/aqua_leader_archie.gbapal");
static const u32 sMugshotImg_Hastings[] = INCBIN_U32("graphics/mugshots/aqua_admin_m.4bpp.lz");
static const u16 sMugshotPal_Hastings[] = INCBIN_U16("graphics/mugshots/aqua_admin_m.gbapal");
static const u32 sMugshotImg_DP[] = INCBIN_U32("graphics/mugshots/aqua_admin_f.4bpp.lz");
static const u16 sMugshotPal_DP[] = INCBIN_U16("graphics/mugshots/aqua_admin_f.gbapal");
static const u32 sMugshotImg_Lyra[] = INCBIN_U32("graphics/mugshots/magma_leader_maxie.4bpp.lz");
static const u16 sMugshotPal_Lyra[] = INCBIN_U16("graphics/mugshots/magma_leader_maxie.gbapal");
static const u32 sMugshotImg_Svelte[] = INCBIN_U32("graphics/mugshots/magma_admin.4bpp.lz");
static const u16 sMugshotPal_Svelte[] = INCBIN_U16("graphics/mugshots/magma_admin.gbapal");
static const u32 sMugshotImg_Magma_Grunt[] = INCBIN_U32("graphics/mugshots/magma_grunt_f.4bpp.lz");
static const u16 sMugshotPal_Magma_Grunt[] = INCBIN_U16("graphics/mugshots/magma_grunt_f.gbapal");
static const u32 sMugshotImg_Frieren[] = INCBIN_U32("graphics/mugshots/frieren.4bpp.lz");
static const u16 sMugshotPal_Frieren[] = INCBIN_U16("graphics/mugshots/frieren.gbapal");
static const u32 sMugshotImg_Reyabs[] = INCBIN_U32("graphics/mugshots/may.4bpp.lz");
static const u16 sMugshotPal_Reyabs[] = INCBIN_U16("graphics/mugshots/may.gbapal");
static const u32 sMugshotImg_Mablewott[] = INCBIN_U32("graphics/mugshots/mablewott.4bpp.lz");
static const u16 sMugshotPal_Mablewott[] = INCBIN_U16("graphics/mugshots/mablewott.gbapal");
static const u32 sMugshotImg_Ellie[] = INCBIN_U32("graphics/mugshots/ellie.4bpp.lz");
static const u16 sMugshotPal_Ellie[] = INCBIN_U16("graphics/mugshots/ellie.gbapal");
static const u32 sMugshotImg_Mable[] = INCBIN_U32("graphics/mugshots/mable.4bpp.lz");
static const u16 sMugshotPal_Mable[] = INCBIN_U16("graphics/mugshots/mable.gbapal");
static const u32 sMugshotImg_BoWall[] = INCBIN_U32("graphics/mugshots/bowall.4bpp.lz");
static const u16 sMugshotPal_BoWall[] = INCBIN_U16("graphics/mugshots/bowall.gbapal");

static const struct Mugshot sMugshots[] = {
    //ADD YOUR MUGSHOTS HERE
    [MUGSHOT_REYADETAIL] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Reya, .palette = sMugshotPal_Reya},
    [MUGSHOT_ROSUURI] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Rosuuri, .palette = sMugshotPal_Rosuuri},
    [MUGSHOT_LILYPAD] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Lilypad, .palette = sMugshotPal_Lilypad},
    [MUGSHOT_VYRAL] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Vyral, .palette = sMugshotPal_Vyral},
    [MUGSHOT_LILYPAL] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Lilypal, .palette = sMugshotPal_Lilypal},
    [MUGSHOT_DIRKLING] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Dirkling, .palette = sMugshotPal_Dirkling},
    [MUGSHOT_EMILIA] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Emilia, .palette = sMugshotPal_Emilia},
    [MUGSHOT_ATSUI] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Atsui, .palette = sMugshotPal_Atsui},
    [MUGSHOT_HAMS] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Hams, .palette = sMugshotPal_Hams},
    [MUGSHOT_CLOR] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Clor, .palette = sMugshotPal_Clor},
    [MUGSHOT_DALEK] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Dalek, .palette = sMugshotPal_Dalek},
    [MUGSHOT_GABE] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Gabe, .palette = sMugshotPal_Gabe},
    [MUGSHOT_ANGE] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Ange, .palette = sMugshotPal_Ange},
    [MUGSHOT_THEA] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Thea, .palette = sMugshotPal_Thea},
    [MUGSHOT_SKYWARD] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Skyward, .palette = sMugshotPal_Skyward},
    [MUGSHOT_LUMI] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Lumi, .palette = sMugshotPal_Lumi},
    [MUGSHOT_ARLE] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Arle, .palette = sMugshotPal_Arle},
    [MUGSHOT_ASTARION] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Astarion, .palette = sMugshotPal_Astarion},
    [MUGSHOT_CYNTHIA] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Cynthia, .palette = sMugshotPal_Cynthia},
    [MUGSHOT_SATSUKI] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Satsuki, .palette = sMugshotPal_Satsuki},
    [MUGSHOT_FORTY] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Forty, .palette = sMugshotPal_Forty},
    [MUGSHOT_HATZOOME] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Hatzoome, .palette = sMugshotPal_Hatzoome},
    [MUGSHOT_HASTINGS] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Hastings, .palette = sMugshotPal_Hastings},
    [MUGSHOT_DP] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_DP, .palette = sMugshotPal_DP},
    [MUGSHOT_LYRA] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Lyra, .palette = sMugshotPal_Lyra},
    [MUGSHOT_SVELTE] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Svelte, .palette = sMugshotPal_Svelte},
    [MUGSHOT_GRUNT_MAGMA] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Magma_Grunt, .palette = sMugshotPal_Magma_Grunt},
    [MUGSHOT_FRIEREN] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Frieren, .palette = sMugshotPal_Frieren},
    [MUGSHOT_REYABS] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Reyabs, .palette = sMugshotPal_Reyabs},
    [MUGSHOT_MABLEWOTT] = {.x = 6, .y = -1, .width = 128, .height = 128, .image = sMugshotImg_Mablewott, .palette = sMugshotPal_Mablewott},
    [MUGSHOT_ELLIE] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Ellie, .palette = sMugshotPal_Ellie},
    [MUGSHOT_MABLE] = {.x = 20, .y = 6, .width = 64, .height = 64, .image = sMugshotImg_Mable, .palette = sMugshotPal_Mable},
    [MUGSHOT_BOWALL] = {.x = 3, .y = 0, .width = 192, .height = 128, .image = sMugshotImg_BoWall, .palette = sMugshotPal_BoWall},
}; 


//WindowId + 1, 0 if window is not open
static EWRAM_DATA u8 sMugshotWindow = 0;

void ClearMugshot(void){
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

static void DrawMugshotCore(const struct Mugshot* const mugshot, int x, int y){
    struct WindowTemplate t;
    u16 windowId;
    
    if(sMugshotWindow != 0){
        ClearMugshot();
    }
    
    #if GAME_VERSION==VERSION_EMERALD
    SetWindowTemplateFields(&t, 0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #else
    t = SetWindowTemplateFields(0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    #endif
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
    
    LoadPalette(mugshot->palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    CopyToWindowPixelBuffer(windowId, (const void*)mugshot->image, 0, 0);
    PutWindowRectTilemap(windowId, 0, 0, mugshot->width/8, mugshot->height/8);
    CopyWindowToVram(windowId, 3);
}

void DrawMugshot(void){
    const struct Mugshot* const mugshot = sMugshots + VarGet(VAR_0x8000);
    DrawMugshotCore(mugshot, mugshot->x, mugshot->y);
}

void DrawMugshotAtPos(void){
    DrawMugshotCore(sMugshots + VarGet(VAR_0x8000), VarGet(VAR_0x8001), VarGet(VAR_0x8002));
}