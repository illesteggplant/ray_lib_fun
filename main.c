#include "raylib.h"

#define width 800
#define height 600
#define MAX_SNAKE_LENGTH 100

typedef struct SnakeSegment 
{
    Vector2 snake_position;
} SnakeSegment;

int main(void)
{
    // Initialization
    const int screen_width = width;
    const int screen_height = height;
    int snake_size = 30;  // Size of the snake's head and the food
    int food_size = 30;
    int score_counter = 0;

    InitWindow(screen_width, screen_height, "Snake. Written by Samuel");

    // Snake variables
    SnakeSegment snake[MAX_SNAKE_LENGTH] = { 0 };
    int snake_length = 1;  // Initial length of the snake
    snake[0].snake_position = (Vector2){ screen_width / 2, screen_height / 2 };
    
    // Food variables
    Vector2 food_position;
    food_position.x = GetRandomValue(0, (screen_width / food_size) - 1) * food_size;
    food_position.y = GetRandomValue(0, (screen_height / food_size) - 1) * food_size;

    // this is needed to prevent the squares from dissapearing on the screen...
    SetTargetFPS(60);             

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Move the snake's body
        for (int i = snake_length - 1; i > 0; i--)
        {
            snake[i].snake_position = snake[i - 1].snake_position;
        }

        // For example purposes, let's move the snake with arrow keys
        if (IsKeyDown(KEY_RIGHT)) snake[0].snake_position.x += 12.5;
        if (IsKeyDown(KEY_LEFT)) snake[0].snake_position.x -= 12.5;
        if (IsKeyDown(KEY_UP)) snake[0].snake_position.y -= 12.5;
        if (IsKeyDown(KEY_DOWN)) snake[0].snake_position.y += 12.5;

        // Screen wrapping
        if (snake[0].snake_position.x >= screen_width) 
        {
            snake[0].snake_position.x = 0;
        }
        else if (snake[0].snake_position.x < 0) 
        {
            snake[0].snake_position.x = screen_width - food_size;
        }
        if (snake[0].snake_position.y >= screen_height) 
        {
            snake[0].snake_position.y = 0;
        }
        else if (snake[0].snake_position.y < 0) 
        {
            snake[0].snake_position.y = screen_height - food_size;
        }

        // Check for collision with food
        if (CheckCollisionRecs(
           (Rectangle){snake[0].snake_position.x, snake[0].snake_position.y, food_size, food_size},
           (Rectangle){food_position.x, food_position.y, food_size, food_size}))
        {
            // Move food to a new random position
            food_position.x = GetRandomValue(0, (screen_width / food_size) - 1) * food_size;
            food_position.y = GetRandomValue(0, (screen_height / food_size) - 1) * food_size;
            if (snake_length < MAX_SNAKE_LENGTH) snake_length++;
            score_counter++;
        }

        BeginDrawing();

        ClearBackground(BLACK);

        for (int i = 0; i < snake_length; i++)
        {
            DrawRectangleV(snake[i].snake_position, (Vector2){snake_size, snake_size}, GREEN);
        }

        // Draw the food
        DrawRectangleV(food_position, (Vector2){food_size, food_size}, RED);

        DrawText(TextFormat("Score: %d", score_counter), 10, 10, 30, WHITE);

        EndDrawing();
    }

    CloseWindow();  

    return 0;
}
