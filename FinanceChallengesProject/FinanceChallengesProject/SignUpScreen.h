#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H

#include "raylib.h"
#include <string>

class SignUpScreen {
public:
    void Init();
    void Draw();
    int HandleInput();

private:
    Rectangle accountField = { 330, 210, 180, 40 };
    Rectangle nameField = { 330, 270, 180, 40 };
    Rectangle passwordField = { 330, 330, 180, 40 };
    Rectangle signupButton = { 370, 390, 100, 40 };

    std::string accountText;
    std::string nameText;
    std::string passwordText;

    bool isAccountFieldActive = true;
    bool isNameFieldActive = false;
    bool isPasswordFieldActive = false;
};

#endif // SIGNUPSCREEN_H