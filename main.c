#include "raylib.h"

#define width 800
#define height 600

int main(void)
{
    // Initialization
    const int screen_width = width;
    const int screen_height = height;
    int snake_size = 30;  // Size of the snake's head and the food
    int food_size = 20;

    InitWindow(screen_width, screen_height, "Snake. Written by Samuel");

    // Snake variables
    Vector2 snake_position = { screen_width / 2, screen_height / 2 };
    
    // Food variables
    Vector2 food_position;
    food_position.x = GetRandomValue(0, (screen_width / food_size) - 1) * food_size;
    food_position.y = GetRandomValue(0, (screen_height / food_size) - 1) * food_size;

    // this is needed to prevent the squares from dissapearing on the screen...
    SetTargetFPS(60);             

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // For example purposes, let's move the snake with arrow keys
        if (IsKeyDown(KEY_RIGHT)) snake_position.x += 10;
        if (IsKeyDown(KEY_LEFT)) snake_position.x -= 10;
        if (IsKeyDown(KEY_UP)) snake_position.y -= 10;
        if (IsKeyDown(KEY_DOWN)) snake_position.y += 10;

        // Check for collision with food
        if ((snake_position.x == food_position.x) && (snake_position.y == food_position.y))
        {
            // Move food to a new random position
            food_position.x = GetRandomValue(0, (screen_width / food_size) - 1) * food_size;
            food_position.y = GetRandomValue(0, (screen_height / food_size) - 1) * food_size;
            snake_size = snake_size + 10;
        }

        BeginDrawing();

        ClearBackground(BLACK);

        // Draw the snake's head
        DrawRectangleV(snake_position, (Vector2){snake_size, snake_size}, GREEN);

        // Draw the food
        DrawRectangleV(food_position, (Vector2){food_size, food_size}, RED);

        EndDrawing();
    }

    CloseWindow();  

    return 0;
}
