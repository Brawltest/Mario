// Simple citro2d sprite drawing example
// Images borrowed from:
//   https://kenney.nl/assets/space-shooter-redux
#include <citro2d.h>
#include "sprite_animation_manager.c"

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPRITES 12
#define MARIO_SPR_COUNT 136 // 1 to 137
#define SCREEN_WIDTH  400
#define SCREEN_HEIGHT 240

C2D_Sprite Mario[137];

static C2D_SpriteSheet MarioSprSheet;
//---------------------------------------------------------------------------------
static void initSprites() { //Initialization of Mario Sprite by NyankoTear (github)
	static object_2d_info_t mario_object;
	static C2D_Sprite mario_sprite[MAX_SPRITES];
	static sprite_pivot_t mario_pivot = {0.0f, 0.0f};
	static sprite_position_t mario_position = {0.0f, 0.0f};
	static float mario_roation = 0.0f;
	static uint64_t sprite_refresh_ms_time = 33;
	initialize_object(&mario_object, \
					  mario_sprite,	\
					  "romfs:/gfx/sprites.t3x", \
					  mario_pivot, \
					  mario_position, \
					  mario_roation, \
					  sprite_refresh_ms_time, \
					  false);
}
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
static void moveMario(int relative_x, int relative_y,int speed){;}

static void printConsole(int line,int row,const char* text){
	char *message = strcat("\x1b[8;1H",text);
	printf(message);
}

void SceneDraw(){

}

//---------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//---------------------------------------------------------------------------------
	// Init libs
	romfsInit();
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);

	// Create screens
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);

	// Load graphics
	MarioSprSheet = C2D_SpriteSheetLoad("romfs:/gfx/Mario/mariospr.t3x");
	if (!MarioSprSheet) svcBreak(USERBREAK_PANIC);

	// Initialize sprites
	initSprites();

	printf("\x1b[8;1HUse");

	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();

		// Respond to user input
		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		u32 kHeld = hidKeysHeld();


		printf("\x1b[1;1HSprites: %zu/%u\x1b[K", 0, MAX_SPRITES);
		printf("\x1b[2;1HCPU:     %6.2f%%\x1b[K", C3D_GetProcessingTime()*6.0f);
		printf("\x1b[3;1HGPU:     %6.2f%%\x1b[K", C3D_GetDrawingTime()*6.0f);
		printf("\x1b[4;1HCmdBuf:  %6.2f%%\x1b[K", C3D_GetCmdBufUsage()*100.0f);

		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, C2D_Color32f(0.0f, 0.0f, 0.0f, 1.0f));
		C2D_SceneBegin(top);
		SceneDraw();
		C3D_FrameEnd(0);
	}

	// Delete graphics
	C2D_SpriteSheetFree(MarioSprSheet);

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	romfsExit();
	return 0;
}
