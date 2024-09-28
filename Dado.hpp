// Dado.hpp
#ifndef DADO_HPP
#define DADO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include <random>
#include <string>
#include <iostream>
#include <vector>

class Dado : public ObjetoDeJogo
{
public:
    // Constructor that initializes the die with its initial sprite and position
    Dado(std::string name, unsigned posL, unsigned posC)
        : ObjetoDeJogo(name, Sprite("rsc/dado1.img"), posL, posC), rng(std::random_device{}()), dist(1, 6)
    {
        // Load all six die face sprites
        for(int i = 1; i <=6; ++i){
            std::string filename = "rsc/dado" + std::to_string(i) + ".img";
            Sprite sprite(filename);
            dieSprites.push_back(sprite);
        }
        std::cout << "All die face sprites loaded." << std::endl;
    }
    
    virtual ~Dado() {}
    
    // Method to simulate rolling the die and updating the sprite
    int roll()
    {
        int result = dist(rng);
        updateSprite(result);
        
        return result;
    }
    
    // Optionally, override the update method if the die has dynamic behavior
    virtual void update() override {
        // Implement any dynamic behavior for the die here
    }

private:
    std::mt19937 rng; // Mersenne Twister RNG
    std::uniform_int_distribution<int> dist; // Uniform distribution [1, 6]
    std::vector<Sprite> dieSprites; // Vector holding all die face sprites

    // Method to update the sprite based on the rolled number
    void updateSprite(int rollNumber)
    {
        if(rollNumber <1 || rollNumber >6){
            std::cerr << "Invalid roll number: " << rollNumber << std::endl;
            return;
        }

        // Assuming getSprite() returns a pointer to SpriteBase
        // We need to cast it to Sprite* to modify it
        const SpriteBase* constSpriteBase = getSprite();
        // Attempt to cast to Sprite* using dynamic_cast for safety
        Sprite* mutableSprite = nullptr;

        // First, cast away constness to get SpriteBase*
        SpriteBase* spriteBaseMutable = const_cast<SpriteBase*>(constSpriteBase);
        // Now, dynamic_cast to Sprite*
        mutableSprite = dynamic_cast<Sprite*>(spriteBaseMutable);
        if(mutableSprite){
            std::string newSpriteFile = "rsc/dado" + std::to_string(rollNumber) + ".img";
            mutableSprite->loadFromFile(newSpriteFile);
            std::cout << "Dado sprite updated to " << newSpriteFile << std::endl;
        }
        else{
            std::cerr << "Failed to cast SpriteBase* to Sprite*. Sprite not updated." << std::endl;
        }
    }
};

#endif // DADO_HPP
