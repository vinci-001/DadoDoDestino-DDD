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

FaseStickman::~FaseStickman()
{
    for(auto obj : objs)
    {
        delete obj;
    }
}

void FaseStickman::init()
{
    stickman = new Stick("Stickman", 15, 50);
    objs.push_back(stickman);

    dado = new Dado("Dado", 5, 7);
    objs.push_back(dado);

    inimigo1 = new Inimigo("Inimigo1", Sprite("rsc/inimigo1.img"), 10, 37);  // Enemy 1
    inimigo2 = new Inimigo("Inimigo2", Sprite("rsc/inimigo2.img"), 8, 52);   // Enemy 2
    inimigo3 = new Inimigo("Inimigo3", Sprite("rsc/inimigo3.img"), 6, 67);   // Enemy 3

    inimigos.push_back(inimigo1);
    objs.push_back(inimigo1);

    inimigos.push_back(inimigo2);
    objs.push_back(inimigo2);

    inimigos.push_back(inimigo3);
    objs.push_back(inimigo3);

    wizard = new Wizard("O MISTICO MAGO", Sprite("rsc/wizard.img"), 8, 50);
    objs.push_back(wizard);
    wizard->desativarObj();
}

bool FaseStickman::colideComParede() const
{
    unsigned posC = stickman->getPosC();
    unsigned posL = stickman->getPosL(); 

    unsigned larguraStick = stickman->getSprite()->getLargura();
    unsigned alturaStick = stickman->getSprite()->getAltura();

    unsigned larguraCaixa = background->getLargura();
    unsigned alturaCaixa = background->getAltura();

    unsigned desiredBoundary = 29;

    if (posC <= desiredBoundary || (posC + larguraStick) >= (larguraCaixa))
    {
        return true;
    }

    if (posL <= 0 || (posL + alturaStick) >= (alturaCaixa))
    {
        return true;
    }

    return false;
}

bool FaseStickman::areEnemiesAlive() const
    {
    return (inimigo1->isActive() || inimigo2->isActive() || inimigo3->isActive());
    }


char getChar() {
    char input;
    std::cout << "W A S D = MOVIMENTO | E = RODAR O DADO | Q = QUIT\nINPUT = ";
    std::cin >> input;
    return input;
}

int temp;
int temp2 = -1;


unsigned FaseStickman::run(SpriteBuffer &screen)
{
 
    draw(screen);
    clearScreen();
    show(screen);

    while (true)
    {

        if (temp == 6)
        {
            inimigo2->kill();
        }
        else if (temp <= 2 && temp > 0)
        {
            inimigo1->kill();
        }
        else if (temp == temp2)
        {
            inimigo3->kill();
        }
        else if(temp && temp2 == 6 && areEnemiesAlive() == false)
        {
            wizard->kill();
            return Fase::END_GAME;
        }

        std::cout << "Dado: " << temp << std::endl;
        char ch =  getChar();

        int posL = stickman->getPosL();
        int posC = stickman->getPosC();

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
        if (areEnemiesAlive() == false) 
        {
            wizard->ativarObj();
            std::cout << "A luta final começa!"<<std::endl;
        }


        update();
        draw(screen);
        clearScreen();
        show(screen);

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return Fase::END_GAME;
}

