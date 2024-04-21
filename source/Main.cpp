#include <citro2d.h>

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH_TOP 400
#define SCREEN_HEIGHT_TOP 240
#define SCREEN_WIDTH_BOTTOM 320
#define SCREEN_HEIGHT_BOTTOM 240

int main(int argc, char* argv[]) {
	srand(time(NULL));

	// FPS stuff
	float FPS = 0;
	float delta = 0;
	float lastTime = 0;
	float currentTime = 0;

	romfsInit();
	gfxInitDefault();

	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);

	C2D_Prepare();
	//consoleInit(GFX_BOTTOM, NULL); // commented because bottom screen can't be used with C2D functions when using it for printing`
	
	// Create top and bottom screen targets
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	// c2d text stuff
	C2D_TextBuf dynamicBuffer = C2D_TextBufNew(4096);


	while (aptMainLoop()) {
		hidScanInput();

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START) break;

		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

		C2D_TargetClear(top, C2D_Color32(0xFF, 0x00, 0xFF, 0xFF));
		C2D_TargetClear(bottom, C2D_Color32(0x00, 0x00, 0xFF, 0xFF));

		C2D_SceneBegin(top);
			C2D_DrawRectSolid(50, 50, 0, 50, 50, C2D_Color32(0x00, 0x00, 0xFF, 0xFF));
			C2D_DrawRectSolid(150, 50, 0, 50, 50, C2D_Color32(0x00, 0xFF, 0x00, 0xFF));
			C2D_DrawRectSolid(250, 50, 0, 50, 50, C2D_Color32(0xFF, 0x00, 0x00, 0xFF));

		C2D_SceneBegin(bottom);
			C2D_TextBufClear(dynamicBuffer);
			C2D_Text dynamicText;
			C2D_TextParse(&dynamicText, dynamicBuffer, "Hello, world!");
			C2D_TextOptimize(&dynamicText);

			C2D_DrawText(&dynamicText, C2D_WithColor, 10.0f, 10.0f, 0.5f, 0.5f, 0.5f, C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF));
		
		C3D_FrameEnd(0);
	}

	C2D_Fini();
	C3D_Fini();
	gfxExit();
	romfsExit();

	return 0;
}
