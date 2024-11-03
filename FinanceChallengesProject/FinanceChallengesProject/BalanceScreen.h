#pragma once
#include "raylib.h"
#include <string>

class BalanceScreen {
public:
    void Init();
    void Draw();
    int HandleInput();

private:
    float balance = 1000.0f;  // Starting balance
    std::string inputText;    // For the deposit/withdraw amount
    bool isInputActive = false;

    Rectangle inputField = { 310, 280, 180, 40 };
    Rectangle depositButton = { 270, 360, 110, 40 };
    Rectangle withdrawButton = { 420, 360, 110, 40 };
};