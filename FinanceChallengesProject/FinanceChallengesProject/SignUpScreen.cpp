#include "SignUpScreen.h"
#include "raylib.h"
#include <fstream>

void SignUpScreen::Init() {
    isAccountFieldActive = true;
    isNameFieldActive = false;
    isPasswordFieldActive = false;
    accountText.clear();
    nameText.clear();
    passwordText.clear();
}

void SignUpScreen::Draw() {
    Image pgkPayImage = LoadImage("../assets/PGKPay.png");
    ImageResize(&pgkPayImage, 350, 250);
    Texture2D pgkPayTexture = LoadTextureFromImage(pgkPayImage);
    UnloadImage(pgkPayImage);
    DrawTexture(pgkPayTexture, 250, 0, GREEN);
    DrawText("Account Number :", 110, 220, 20, BLACK);
    DrawText("Full Name :", 180, 280, 20, BLACK);
    DrawText("Password :", 180, 340, 20, BLACK);

    DrawRectangleRec(accountField, isAccountFieldActive ? LIGHTGRAY : GRAY);
    DrawText(accountText.c_str(), accountField.x + 5, accountField.y + 10, 20, BLACK);

    DrawRectangleRec(nameField, isNameFieldActive ? LIGHTGRAY : GRAY);
    DrawText(nameText.c_str(), nameField.x + 5, nameField.y + 10, 20, BLACK);

    DrawRectangleRec(passwordField, isPasswordFieldActive ? LIGHTGRAY : GRAY);
    DrawText(passwordText.c_str(), passwordField.x + 5, passwordField.y + 10, 20, BLACK);

    DrawRectangleRec(signupButton, DARKGRAY);
    DrawText("Sign Up", signupButton.x + 10, signupButton.y + 10, 20, RAYWHITE);

    DrawText("Press ESC to return to Main Menu", 260, 500, 20, GRAY);
}

int SignUpScreen::HandleInput() {
    if (IsKeyPressed(KEY_ESCAPE)) return 0;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePosition = GetMousePosition();
        if (CheckCollisionPointRec(mousePosition, signupButton)) {
            // Save account details to "accounts.txt"
            std::ofstream outFile("../accounts.txt", std::ios::app);
            if (outFile.is_open()) {
                outFile << accountText << "," << passwordText << "\n";
                outFile.close();
            }
            return 2; // Navigate to Balance Screen
        }
        isAccountFieldActive = CheckCollisionPointRec(mousePosition, accountField);
        isNameFieldActive = CheckCollisionPointRec(mousePosition, nameField);
        isPasswordFieldActive = CheckCollisionPointRec(mousePosition, passwordField);
    }

    int maxLength = 19;
    int key = GetCharPressed();

    if (isAccountFieldActive && key >= 32 && key <= 125 && accountText.length() < maxLength) {
        accountText += static_cast<char>(key);
    }
    else if (isNameFieldActive && key >= 32 && key <= 125 && nameText.length() < maxLength) {
        nameText += static_cast<char>(key);
    }
    else if (isPasswordFieldActive && key >= 32 && key <= 125 && passwordText.length() < maxLength) {
        passwordText += static_cast<char>(key);
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        if (isAccountFieldActive && !accountText.empty()) accountText.pop_back();
        else if (isNameFieldActive && !nameText.empty()) nameText.pop_back();
        else if (isPasswordFieldActive && !passwordText.empty()) passwordText.pop_back();
    }

    return 1;
}
