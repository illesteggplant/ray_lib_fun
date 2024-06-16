#include "raylib.h"

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Simple Raylib Example");

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update

        // Draw
        BeginDrawing();

        ClearBackground(LIME);

        DrawText("Hello, Raylib! This is Sam Speaking", 0, 0, 30, DARKGRAY);

        // Draw a red circle in the center
        int centerX = screenWidth / 2;
        int centerY = screenHeight / 2;
        int radius = 50;
        Color color = RED;

        DrawCircle(centerX, centerY, radius, color);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}