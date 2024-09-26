#ifndef STICK_HPP
#define STICK_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"

class Stick : public ObjetoDeJogo
{
public:
    // Constructor that initializes the sprite directly
    Stick(std::string name, unsigned posL, unsigned posC)
        : ObjetoDeJogo(name, Sprite("rsc/stick.img"), posL, posC) {} // Ensure the sprite file name is correct

    virtual ~Stick() {}

    // Movement methods inherited from ObjetoDeJogo
    void moveUp() { ObjetoDeJogo::moveUp(1); }
    void moveDown() { ObjetoDeJogo::moveDown(1); }
    void moveLeft() { ObjetoDeJogo::moveLeft(2); }
    void moveRight() { ObjetoDeJogo::moveRight(2); }

    virtual void update() override {
        // Stickman has no special behavior in update, just moves.
    }
};

#endif // STICK_HPP
