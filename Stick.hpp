#ifndef STICK_HPP
#define STICK_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"

class Stick : public ObjetoDeJogo
{
public:
    Stick(std::string name, unsigned posL, unsigned posC)
        : ObjetoDeJogo(name, Sprite("rsc/stick.img"), posL, posC) {}

    virtual ~Stick() {}

    void moveUp() { ObjetoDeJogo::moveUp(1); }
    void moveDown() { ObjetoDeJogo::moveDown(1); }
    void moveLeft() { ObjetoDeJogo::moveLeft(2); }
    void moveRight() { ObjetoDeJogo::moveRight(2); }

};

#endif // STICK_HPP
