// InimigoLow.hpp
#ifndef INIMIGO_LOW_HPP
#define INIMIGO_LOW_HPP

#include "Inimigo.hpp"
#include <iostream>

class InimigoLow : public Inimigo
{
public:
    InimigoLow(const std::string& name, const Sprite& sprite, unsigned posL, unsigned posC)
        : Inimigo(name, sprite, posL, posC) {}
    
    virtual ~InimigoLow() {}
    
    virtual void update() override {
        // No movement; enemies are stationary
    }
    
    virtual void attack() override {
        std::cout << name << " attacks you swiftly!" << std::endl;
        // Implement attack logic here (e.g., reduce player health moderately)
    }
    
    virtual bool shouldDie(int lastRoll, int currentRoll) override {
        if (currentRoll < 2) {
            std::cout << name << " has been defeated by rolling below two!" << std::endl;
            return true;
        }
        return false;
    }
};

#endif // INIMIGO_LOW_HPP
