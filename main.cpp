#include <iostream>
#include "raylib.h"
#include "Level.h"
int  main () {
    InitWindow(800, 600, "Level Test");
    SetTargetFPS(60);
    Level level("level1.txt");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        level.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
    
}