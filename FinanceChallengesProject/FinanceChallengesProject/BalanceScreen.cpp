#include "BalanceScreen.h"
#include "raylib.h"
#include <iostream>

void BalanceScreen::Init() {
    balance = 1000.0f;
    inputText = "";
    isInputActive = false;
}

void BalanceScreen::Draw() {
    // Load the image once and convert it to a texture
    Image pgkPayImage = LoadImage("../assets/PGKPay.png");
    ImageResize(&pgkPayImage, 400, 300);  // Resize if needed
    Texture2D pgkPayTexture = LoadTextureFromImage(pgkPayImage);
    UnloadImage(pgkPayImage); // Unload from RAM after uploading to VRAM
    // Logo
    DrawTexture(pgkPayTexture, 200, 0, GREEN);
    DrawText(TextFormat("Account Balance: $%.2f", balance), 260, 240, 20, DARKGREEN);

    // Draw input field
    DrawRectangleRec(inputField, isInputActive ? LIGHTGRAY : GRAY);
    DrawText(inputText.c_str(), inputField.x + 5, inputField.y + 10, 20, BLACK);

    // Draw deposit and withdraw buttons
    DrawRectangleRec(depositButton, DARKGRAY);
    DrawText("Deposit", depositButton.x + 10, depositButton.y + 10, 20, RAYWHITE);

    DrawRectangleRec(withdrawButton, DARKGRAY);
    DrawText("Withdraw", withdrawButton.x + 10, withdrawButton.y + 10, 20, RAYWHITE);

    DrawText("Press ESC to return to Main Menu", 200, 520, 20, GRAY);
}

int BalanceScreen::HandleInput() {
    if (IsKeyPressed(KEY_ESCAPE)) return 0;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePosition = GetMousePosition();

        // Check if input field is clicked
        isInputActive = CheckCollisionPointRec(mousePosition, inputField);

        // Check if Deposit button is clicked
        if (CheckCollisionPointRec(mousePosition, depositButton)) {
            if (!inputText.empty()) {
                float amount = std::stof(inputText);
                balance += amount;
                inputText.clear();  // Clear input after depositing
            }
        }

        // Check if Withdraw button is clicked
        if (CheckCollisionPointRec(mousePosition, withdrawButton)) {
            if (!inputText.empty()) {
                float amount = std::stof(inputText);
                if (amount <= balance) {
                    balance -= amount;
                    inputText.clear();  // Clear input after withdrawing
                }
            }
        }
    }

    // Handle text input for the active input field
    if (isInputActive) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= '0' && key <= '9') || key == '.') {
                inputText += static_cast<char>(key); // Append key to inputText
            }
            key = GetCharPressed();
        }

        // Handle backspace for input field
        if (IsKeyPressed(KEY_BACKSPACE) && !inputText.empty()) {
            inputText.pop_back();
        }
    }

    return 1;
}