#include "raylib.h"
#include "MainMenu.h"
#include "LoginScreen.h"
#include "SignUpScreen.h"
#include "BalanceScreen.h"

enum Screen { MAIN_MENU, LOGIN_SCREEN, SIGNUP_SCREEN, BALANCE_SCREEN };

int main() {
    InitWindow(800, 600, "PGKPAY");

    MainMenu mainMenu;
    mainMenu.Init();

    LoginScreen loginScreen;
    loginScreen.Init();

    SignUpScreen signUpScreen;
    signUpScreen.Init();

    BalanceScreen balanceScreen;
    balanceScreen.Init();

    Screen currentScreen = MAIN_MENU;

    while (!WindowShouldClose()) {
        switch (currentScreen) {
        case MAIN_MENU: {
            int action = mainMenu.HandleInput();
            if (action == 1) currentScreen = LOGIN_SCREEN;
            else if (action == 2) currentScreen = SIGNUP_SCREEN;
            break;
        }
        case LOGIN_SCREEN: {
            int result = loginScreen.HandleInput();
            if (result == 0) currentScreen = MAIN_MENU;
            else if (result == 2) currentScreen = BALANCE_SCREEN;
            break;
        }
        case SIGNUP_SCREEN: {
            int result = signUpScreen.HandleInput();
            if (result == 0) currentScreen = MAIN_MENU;
            else if (result == 2) currentScreen = BALANCE_SCREEN;
            break;
        }
        case BALANCE_SCREEN: {
            int result = balanceScreen.HandleInput();
            if (result == 0) currentScreen = MAIN_MENU;
            break;
        }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the current screen
        switch (currentScreen) {
        case MAIN_MENU:
            mainMenu.Draw();
            break;
        case LOGIN_SCREEN:
            loginScreen.Draw();
            break;
        case SIGNUP_SCREEN:
            signUpScreen.Draw();
            break;
        case BALANCE_SCREEN:
            balanceScreen.Draw();
            break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}