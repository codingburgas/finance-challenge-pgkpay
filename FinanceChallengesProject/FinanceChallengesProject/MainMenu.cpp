#include "MainMenu.h"
#include "raylib.h"

void MainMenu::Init() {
    // Initialization code, if needed

}

void MainMenu::Draw() {
    // Background color
    ClearBackground(RAYWHITE);
    // Initialization code, if needed
    // Load the image once and convert it to a texture
    Image pgkPayImage = LoadImage("../assets/PGKPay.png");
    ImageResize(&pgkPayImage, 500, 400);  // Resize if needed
    Texture2D pgkPayTexture = LoadTextureFromImage(pgkPayImage);
    UnloadImage(pgkPayImage); // Unload from RAM after uploading to VRAM
    // Logo
    DrawTexture(pgkPayTexture, 180, 20, GREEN);
    // Draw Login Button
    DrawRectangleRec(loginButton, GRAY);
    DrawText("Login", loginButton.x + 40, loginButton.y + 20, 20, RAYWHITE);

    // Draw Sign Up Button
    DrawRectangleRec(signUpButton, GRAY);
    DrawText("Sign Up", signUpButton.x + 30, signUpButton.y + 20, 20, RAYWHITE);
}

int MainMenu::HandleInput() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePosition = GetMousePosition();

        // Check if Login button is clicked
        if (CheckCollisionPointRec(mousePosition, loginButton)) {
            return 1;  // Indicate login selected
        }

        // Check if Sign Up button is clicked
        if (CheckCollisionPointRec(mousePosition, signUpButton)) {
            return 2;  // Indicate sign-up selected
        }
    }
    return 0;  // No button clicked
}
