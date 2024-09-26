// InimigoConsecutive.hpp
#ifndef INIMIGO_CONSECUTIVE_HPP
#define INIMIGO_CONSECUTIVE_HPP

#include "Inimigo.hpp"
#include <iostream>

class InimigoDuasVezes : public Inimigo
{
public:
    InimigoDuasVezes(const std::string& name, const Sprite& sprite, unsigned posL, unsigned posC)
        : Inimigo(name, sprite, posL, posC), lastPlayerRoll(-1) {}
    
    virtual ~InimigoDuasVezes() {}
    
    virtual void update() override {
        // No movement; enemies are stationary
    }
    
    virtual void attack() override {
        std::cout << name << " attacks you!" << std::endl;
        // Implement attack logic here (e.g., reduce player health)
    }
    
    virtual bool shouldDie(int lastRoll, int currentRoll) override {
        if (lastPlayerRoll == currentRoll) {
            std::cout << name << " has been defeated by consecutive rolls!" << std::endl;
            return true;
        }
        lastPlayerRoll = currentRoll;
        return false;
    }
    
private:
    int lastPlayerRoll; // Tracks the player's last die roll
};

#endif // INIMIGO_CONSECUTIVE_HPP
