// FaseStickman.hpp
#ifndef FASESTICKMAN_HPP
#define FASESTICKMAN_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Stick.hpp"      // Include the Stick class
#include "Dado.hpp"       // Include the Dado class
#include "Indicator.hpp"  // Include the Indicator class
#include <string>

class FaseStickman : public Fase
{
public:
    // Constructor that accepts a name and background sprite
    FaseStickman(std::string name, const Sprite &bkg)
        : Fase(name, bkg), dado(nullptr), stickman(nullptr), indicator(nullptr) {}
    
    // Destructor declared but not defined inline to avoid redefinition
    virtual ~FaseStickman();
    
    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

private:
    ObjetoDeJogo* stickman;    // Pointer to Stickman
    Dado* dado;                 // Pointer to the Dado
    Indicator* indicator;       // Pointer to the Indicator
    
    // Collision Detection
    bool colideComParede() const; // Collision detection with boundaries
};

#endif // FASESTICKMAN_HPP
