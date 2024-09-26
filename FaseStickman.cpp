// FaseStickman.cpp
#include "FaseStickman.hpp"
#include <conio.h>     // For _kbhit() and _getch() on Windows
#include <windows.h>   // For Windows API functions
#include <iostream>
#include <chrono>
#include <thread>

// Function to clear the screen using WinAPI
void clearScreen()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
        FillConsoleOutputCharacter(hStdOut, ' ', cellCount, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    }
}

// Destructor to clean up dynamically allocated objects
FaseStickman::~FaseStickman()
{
    for(auto obj : objs)
    {
        delete obj;
    }
}

// Method to initialize the phase
void FaseStickman::init()
{
    // Stickman using the Stick class (active by default)
    stickman = new Stick("Stickman", 12, 38);
    objs.push_back(stickman);

    // Instantiate the Dado object and add it last to ensure it's rendered on top
    dado = new Dado("Dado", 5, 7); // Adjusted position for visibility
    objs.push_back(dado);

      // Initialize Indicator
    indicator = new Indicator("Indicator");
    objs.push_back(indicator);
}

// Collision Detection Method: Checks collision with the left and right boundaries
// FaseStickman.cpp

bool FaseStickman::colideComParede() const
{
    // Retrieve current horizontal and vertical positions of the Stickman
    unsigned posC = stickman->getPosC(); // Current Column (Horizontal Position)
    unsigned posL = stickman->getPosL(); // Current Line (Vertical Position)

    unsigned larguraStick = stickman->getSprite()->getLargura(); // Width of Stickman
    unsigned alturaStick = stickman->getSprite()->getAltura();   // Height of Stickman

    unsigned larguraCaixa = background->getLargura(); // Width of Background
    unsigned alturaCaixa = background->getAltura();   // Height of Background

    unsigned desiredBoundary = 29; // You can adjust this value as needed

    if (posC <= desiredBoundary || (posC + larguraStick) >= (larguraCaixa - desiredBoundary))
    {
        return true; // Collision detected on the horizontal plane
    }

    if (posL <= 0 || (posL + alturaStick) >= (alturaCaixa - 6))
    {
        return true;
    }

    return false;
}


// Main method of the phase, responsible for the execution loop
unsigned FaseStickman::run(SpriteBuffer &screen)
{
    // Draw the initial phase
    draw(screen);
    clearScreen();
    show(screen);

    // Debug Message
    std::cout << "FaseStickman run loop started." << std::endl;

    while (true)
    {
        // Capture input without waiting for Enter
        if (_kbhit()) // Check if a key has been pressed
        {
            char ch = _getch(); // Capture the character without echo

            // Save current position
            int posL = stickman->getPosL();
            int posC = stickman->getPosC();

            // Process input
            if (ch == 'w' || ch == 'W')
                stickman->moveUp();
            else if (ch == 's' || ch == 'S')
                stickman->moveDown();
            else if (ch == 'a' || ch == 'A')
                stickman->moveLeft();
            else if (ch == 'd' || ch == 'D')
                stickman->moveRight();
            else if (ch == 'e' || ch == 'E') // Press 'E' to attack
            {
                std::cout << "You attempt to attack!" << std::endl;
                int attackRoll = dado->roll();
                if (attackRoll >= 4)
                {
                    std::cout << "Attack successful! You dealt " << attackRoll << " damage." << std::endl;
                    // Implement damage logic here
                }
                else
                {
                    std::cout << "Attack missed!" << std::endl;
                    // Implement miss logic here
                }
            }
            else if (ch == 'j' || ch == 'J') // Press 'J' to cycle left
            {
                indicator->cycleLeft();
            }
            else if (ch == 'l' || ch == 'L') // Press 'L' to cycle right
            {
                indicator->cycleRight();
            }
            else if (ch == 'q' || ch == 'Q')
                return Fase::END_GAME;

            // Check collision with boundaries
            if (colideComParede())
            {
                stickman->moveTo(posL, posC); // Revert to previous position
                std::cout << "Colidiu com a parede!" << std::endl;
            }

            // Update and draw the phase
            update();
            draw(screen);
            clearScreen();
            show(screen);
        }

        // Small pause to prevent high CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return Fase::END_GAME;
}

