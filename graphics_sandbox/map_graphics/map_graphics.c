#include "map_graphics.h"

#include "raylib.h"

Vector2 getCurrentCoordinate() {
    //Todo
    return GetMousePosition();
}

void runMapGraphics(map_graphics_t* info)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = (int)info->WindowSize.x;
    const int screenHeight = (int)info->WindowSize.y;
    int windowposx = (int)info->WindowPos.x;
    int windowposy = (int)info->WindowPos.y;
    Vector2 playerPosition = (Vector2){screenWidth/2,screenHeight/2};

    InitWindow(screenWidth, screenHeight, info->MapTitle);
    SetWindowPosition(windowposx,windowposy);

    Texture2D MapTexture = LoadTexture(info->MapImagePath);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)||IsKeyDown(KEY_D)) playerPosition.x += 1.0f;
        else if (IsKeyDown(KEY_LEFT)||IsKeyDown(KEY_A)) playerPosition.x -= 1.0f;
        else if (IsKeyDown(KEY_DOWN)||IsKeyDown(KEY_S)) playerPosition.y += 1.0f;
        else if (IsKeyDown(KEY_UP)||IsKeyDown(KEY_W)) playerPosition.y -= 1.0f;

        if (playerPosition.x < (screenWidth-MapTexture.width)/2) {
            playerPosition.x = (screenWidth-MapTexture.width)/2;
        }

        if (playerPosition.x > screenWidth - (screenWidth-MapTexture.width)/2) {
            playerPosition.x = screenWidth - (screenWidth-MapTexture.width)/2;
        }
        
        if (playerPosition.y < (screenHeight-MapTexture.height)/2) {
            playerPosition.y = (screenHeight-MapTexture.height)/2;
        }

        if (playerPosition.y > screenHeight - (screenHeight-MapTexture.height)/2) {
            playerPosition.y = screenHeight - (screenHeight-MapTexture.height)/2;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(MapTexture,(screenWidth-MapTexture.width)/2,(screenHeight-MapTexture.height)/2,RAYWHITE);

            DrawCircleV(playerPosition,10,RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}

int main(void) {
    //runMapGraphics();
    map_graphics_t info;
    info.WindowPos = (Vector2){200,200};
    info.WindowSize = (Vector2) {600,600};
    info.MapImagePath = "map_example/simplemap.png";
    info.MapTitle = "Just a simple map";
    runMapGraphics(&info);
    return 0;
}