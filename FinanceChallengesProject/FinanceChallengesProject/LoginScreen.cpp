#include "LoginScreen.h"
#include "raylib.h"
#include <fstream>
#include <sstream>

void LoginScreen::Init() {}

void LoginScreen::Draw() {
    Image pgkPayImage = LoadImage("../assets/PGKPay.png");
    ImageResize(&pgkPayImage, 400, 300);
    Texture2D pgkPayTexture = LoadTextureFromImage(pgkPayImage);
    UnloadImage(pgkPayImage);
    DrawTexture(pgkPayTexture, 205, 0, GREEN);
    DrawText("Account Number:", 110, 250, 20, BLACK);
    DrawText("Password:", 180, 330, 20, BLACK);

    DrawRectangleRec(accountField, isAccountActive ? LIGHTGRAY : GRAY);
    DrawText(accountText, accountField.x + 5, accountField.y + 10, 20, BLACK);

    DrawRectangleRec(passwordField, !isAccountActive ? LIGHTGRAY : GRAY);
    DrawText(passwordText, passwordField.x + 5, passwordField.y + 10, 20, BLACK);

    DrawRectangleRec(loginButton, DARKGRAY);
    DrawText("Login", loginButton.x + 20, loginButton.y + 10, 20, RAYWHITE);

    DrawText("Press ESC to return", 300, 520, 20, GRAY);
}

bool LoginScreen::VerifyLogin() {
    std::ifstream inFile("../accounts.txt");
    if (!inFile.is_open()) return false;

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream stream(line);
        std::string fileAccount, filePassword;
        if (std::getline(stream, fileAccount, ',') && std::getline(stream, filePassword)) {
            if (accountText == fileAccount && passwordText == filePassword) {
                return true; // Match found
            }
        }
    }
    return false; // No match found
}

int LoginScreen::HandleInput() {
    if (IsKeyPressed(KEY_ESCAPE)) return 0;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePosition = GetMousePosition();
        if (CheckCollisionPointRec(mousePosition, loginButton)) {
            if (VerifyLogin()) {
                return 2; // Navigate to Balance Screen
            }
        }
        isAccountActive = CheckCollisionPointRec(mousePosition, accountField);
        if (!isAccountActive) {
            isAccountActive = !CheckCollisionPointRec(mousePosition, passwordField);
        }
    }

    int maxLength = 19;
    if (isAccountActive && IsKeyPressed(KEY_BACKSPACE) && strlen(accountText) > 0) {
        accountText[strlen(accountText) - 1] = '\0';
    }
    else if (!isAccountActive && IsKeyPressed(KEY_BACKSPACE) && strlen(passwordText) > 0) {
        passwordText[strlen(passwordText) - 1] = '\0';
    }

    int key = GetCharPressed();
    if (key >= 32 && key <= 125) {
        if (isAccountActive && strlen(accountText) < maxLength) {
            int len = strlen(accountText);
            accountText[len] = (char)key;
            accountText[len + 1] = '\0';
        }
        else if (!isAccountActive && strlen(passwordText) < maxLength) {
            int len = strlen(passwordText);
            passwordText[len] = (char)key;
            passwordText[len + 1] = '\0';
        }
    }

    return 1;
}
