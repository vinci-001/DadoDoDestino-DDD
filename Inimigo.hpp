// Inimigo.hpp
#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include <string>

class Inimigo : public ObjetoDeJogo
{
public:
    // Constructor to initialize the enemy with a name, sprite, and position
    Inimigo(const std::string& name, const Sprite& sprite, unsigned posL, unsigned posC)
        : ObjetoDeJogo(name, sprite, posL, posC) {}
    
    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Inimigo() {}
    
    // Pure virtual methods to be implemented by derived classes
    virtual void update() = 0;
    virtual void attack() = 0;
    
    // Pure virtual method to determine if the enemy should die based on die rolls
    virtual bool shouldDie(int lastRoll, int currentRoll) = 0;
    
protected:
    // Common attributes or methods for all enemies can be added here
};

#endif // INIMIGO_HPP
