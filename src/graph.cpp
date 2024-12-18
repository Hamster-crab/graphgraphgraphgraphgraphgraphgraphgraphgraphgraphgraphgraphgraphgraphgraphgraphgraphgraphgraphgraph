#include "raylib.h"
#include <string>
#include <fstream>
#include <iostream>

void DrawTextInt(const char *text, int drawInt, int posX, int posY, int fontSize, Color color) {
    // textとdrawIntを1つの文字列に結合
    char buffer[256]; // 必要に応じてサイズを調整
    snprintf(buffer, sizeof(buffer), "%s%d", text, drawInt);
    
    // raylibのDrawText関数を使って結合した文字列を描画
    DrawText(buffer, posX, posY, fontSize, color);
}

int main()
{
    const int screenWidth = 650;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "graph");

    SetTargetFPS(60);

    bool settings = false;
    bool hirei = false;
    bool hanpirei = false;
    double x = screenWidth / 2;
    double y = screenHeight / 2;
    double a = 1;

    Rectangle aUP = { 303, 305, 20, 25 };
    Rectangle aDOWN = { 303, 340, 20, 25 };
    Rectangle hireiOn = { 270, 80, 13, 13 };
    Rectangle hanpireiOn = { 270, 200, 13, 13};

    while (!WindowShouldClose())
    {
        Vector2 mousePos = GetMousePosition();
        if (settings)
        {
            if (CheckCollisionPointRec(mousePos, hireiOn))
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    if (hirei) hirei = false;
                    else if (!hirei) hirei = true;
                }
            }
            if (CheckCollisionPointRec(mousePos, hanpireiOn))
            {
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    if (hanpirei) hanpirei = false;
                    else if (!hanpirei) hanpirei = true;
                }
            }
            if (CheckCollisionPointRec(mousePos, aUP)) if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) a+=0.5;
            if (CheckCollisionPointRec(mousePos, aDOWN)) if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) a-=0.5;
        }

        if (IsKeyPressed(KEY_S))
        {
            if (settings) settings = false;
            else if (!settings) settings = true;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(0, y, screenWidth, 3, DARKBLUE);
        DrawRectangle(x, 0, 3, screenHeight, DARKBLUE);

        DrawRectangle(0, y - 10, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 20, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 30, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 40, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 50, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 60, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 70, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 80, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 90, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 100, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 110, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 120, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 130, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 140, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 150, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 160, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 170, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 180, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 190, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 200, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 210, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 220, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 230, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 240, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 250, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 260, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 270, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 280, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 290, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 300, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 310, screenWidth, 2, BLUE);
        DrawRectangle(0, y - 320, screenWidth, 2, BLUE);



        DrawCircle (x + 1, y + 1, 5, BLACK);

        if (hirei)
        {
            DrawCircle (x + 10, x * a, 4, BLACK);
        }

        if (settings)
        {
            DrawRectangle(screenWidth / 100, screenHeight / 100, 630, 580, GRAY);
            DrawText("y = ax", 220, 20, 30, BLACK);
            DrawCircle(hireiOn.x, hireiOn.y, hireiOn.width + 4, BLACK);
            DrawCircle(hireiOn.x, hireiOn.y, hireiOn.width, WHITE);
            if (hirei) DrawCircle(270, 80, 8, GREEN);

            DrawText("a = ", 80, 300, 80, BLACK);
            DrawRectangle(230, 300, 70, 70, BLACK);
            DrawRectangle(235, 305, 60, 60, WHITE);
            DrawTextInt("", a, 240, 305, 60, BLACK);
            DrawRectangle(aUP.x, aUP.y, aUP.width, aUP.height, WHITE);
            DrawRectangle(aDOWN.x, aDOWN.y, aDOWN.width, aDOWN.height, WHITE);

            DrawText("y = a/x", 220, 130, 30, BLACK);
            DrawCircle(hanpireiOn.x, hanpireiOn.y, hanpireiOn.width, BLACK);
            DrawCircle(hanpireiOn.x, hanpireiOn.y, hanpireiOn.width, WHITE);
            if (hanpirei) DrawCircle(650, 80, 8, GREEN);

            DrawRectangle(730, 530, 150, 40, RED);
            DrawText("Done", 750, 538, 33, BLACK);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}