#pragma once
#include "raylib.h"

class MainMenu {
public:
    void Init();
    void Draw();
    int HandleInput(); // Returns 1 for Login, 2 for Sign Up, 0 for no action

private:
    Rectangle loginButton = { 250, 360, 150, 60 };
    Rectangle signUpButton = { 450, 360, 150, 60 };
};