#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include "raylib.h"

class LoginScreen {
public:
    void Init();
    void Draw();
    int HandleInput();

private:
    // Function to verify login credentials against accounts.txt
    bool VerifyLogin();

    Rectangle accountField = { 310, 240, 180, 40 };
    Rectangle passwordField = { 310, 320, 180, 40 };
    Rectangle loginButton = { 355, 400, 90, 40 };

    char accountText[20] = "";
    char passwordText[20] = "";
    bool isAccountActive = true;
};

#endif // LOGINSCREEN_H
