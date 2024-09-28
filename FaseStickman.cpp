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

    // Instantiate three Inimigo objects with different positions and sprites
    inimigo1 = new Inimigo("Inimigo1", Sprite("rsc/inimigo1.img"), 10, 37);  // Enemy 1
    inimigo2 = new Inimigo("Inimigo2", Sprite("rsc/inimigo2.img"), 8, 52);   // Enemy 2
    inimigo3 = new Inimigo("Inimigo3", Sprite("rsc/inimigo3.img"), 6, 67);   // Enemy 3

    // Add enemies to the objs list
    inimigos.push_back(inimigo1);
    inimigos.push_back(inimigo2);
    inimigos.push_back(inimigo3);

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

    if (posC <= desiredBoundary || (posC + larguraStick) >= (larguraCaixa))
    {
        return true; // Collision detected on the horizontal plane
    }

    if (posL <= 0 || (posL + alturaStick) >= (alturaCaixa - 6))
    {
        return true;
    }

    return false;
}


char getChar() {
    char input;
    std::cout << "W A S D = MOVIMENTO | E = RODAR O DADO | Q = QUIT\nINPUT = ";
    std::cin >> input;  // Capture a single character from user input
    return input;
}

int temp;
int temp2 = -1;

// Main method of the phase, responsible for the execution loop
unsigned FaseStickman::run(SpriteBuffer &screen)
{
    // Draw the initial phase
    draw(screen);
    clearScreen();
    show(screen);

    while (true)
    {

        if (temp == 6)
        {
            inimigo2->kill();
            std::cout<<"6 maligno eliminado."<<std::endl;
        }
        else if (temp <= 2 && temp > 0)
        {
            inimigo1->kill();
            std::cout<<"1 maligno eliminado."<<std::endl;
        }
        else if (temp == temp2)
        {
            inimigo3->kill();
            std::cout<<"gemeos malignos eliminado."<<std::endl;
        }

        std::cout << "Last dice roll: " << temp << std::endl;
        char ch =  getChar(); // Capture the character without echo

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
        else if (ch == 'e' || ch == 'E')
        {
            temp2 = temp;
            int attackRoll = dado->roll();
            temp = attackRoll;
        }
        else if (ch == 'q' || ch == 'Q')
            return Fase::END_GAME;

        if (colideComParede())
        {
            stickman->moveTo(posL, posC);
            std::cout << "Colidiu com a parede!" << std::endl;
        }
        if (inimigos.empty()) 
        {
            std::cout << "All enemies have been eliminated!" << std::endl;
        }


        update();
        draw(screen);
        clearScreen();
        show(screen);
        // Print the attackRoll if it has been updated

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return Fase::END_GAME;
}

