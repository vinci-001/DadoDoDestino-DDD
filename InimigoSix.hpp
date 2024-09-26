// InimigoSix.hpp
#ifndef INIMIGO_SIX_HPP
#define INIMIGO_SIX_HPP

#include "Inimigo.hpp"
#include <iostream>

class InimigoSix : public Inimigo
{
public:
    InimigoSix(const std::string& name, const Sprite& sprite, unsigned posL, unsigned posC)
        : Inimigo(name, sprite, posL, posC) {}
    
    virtual ~InimigoSix() {}
    
    virtual void update() override {
        // No movement; enemies are stationary
    }
    
    virtual void attack() override {
        std::cout << name << " attacks you with a powerful strike!" << std::endl;
        // Implement attack logic here (e.g., reduce player health significantly)
    }
    
    virtual bool shouldDie(int lastRoll, int currentRoll) override {
        if (currentRoll == 6) {
            std::cout << name << " has been defeated by rolling a six!" << std::endl;
            return true;
        }
        return false;
    }
};

#endif // INIMIGO_SIX_HPP
