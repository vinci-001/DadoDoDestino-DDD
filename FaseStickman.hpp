// FaseStickman.hpp
#ifndef FASESTICKMAN_HPP
#define FASESTICKMAN_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Inimigo.hpp"
#include "Stick.hpp"
#include "Dado.hpp"
#include <string>

class FaseStickman : public Fase
{
public:
    // Constructor that accepts a name and background sprite
    FaseStickman(std::string name, const Sprite &bkg)
        : Fase(name, bkg), dado(nullptr), stickman(nullptr) {}
    
    // Destructor declared but not defined inline to avoid redefinition
    virtual ~FaseStickman();
    
    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

private:
    ObjetoDeJogo* stickman;    // Pointer to Stickman
    Dado* dado;                 // Pointer to the Dado
    Inimigo* inimigo1;         // Pointer to Inimigo 1
    Inimigo* inimigo2;         // Pointer to Inimigo 2
    Inimigo* inimigo3;         // Pointer to Inimigo 3

    std::list<Inimigo*> inimigos; // Separate list to store all enemy objects
    // Collision Detection
    bool colideComParede() const; // Collision detection with boundaries
};

#endif // FASESTICKMAN_HPP
