#include "raylib.h"

#define width 800;
#define height 600;

int main(void)
{
    // Initialization
    const int screen_width = width;
    const int screen_height = height;
    InitWindow(screen_width, screen_height, "Snake.  Written by Samuel");

    // square defines
    int square_x_coordinate = screen_width / 2 - 50;
    int square_y_coordinate = screen_height / 2 -50;
    int square_size = 50;
    Color square_color = LIME;

    // ensure the box does not disappear when moving around the screen
    SetTargetFPS(60); 

    // Main game loop
    // Detect window close button or ESC key
    while (!WindowShouldClose())    
    {
        // Detect input and update.  Moves square around the board
        if (IsKeyDown(KEY_RIGHT)) square_x_coordinate += 5;
        if (IsKeyDown(KEY_LEFT)) square_x_coordinate -= 5;
        if (IsKeyDown(KEY_DOWN)) square_y_coordinate += 5;
        if (IsKeyDown(KEY_UP)) square_y_coordinate -= 5;

        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Score", 0, 0, 30, LIME);
        DrawRectangle(square_x_coordinate, square_y_coordinate, square_size, square_size, square_color);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}