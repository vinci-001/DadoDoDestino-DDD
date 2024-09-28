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
    Dado(std::string name, unsigned posL, unsigned posC)
        : ObjetoDeJogo(name, Sprite("rsc/dado1.img"), posL, posC), rng(std::random_device{}()), dist(1, 6)
    {
        for(int i = 1; i <=6; ++i){
            std::string filename = "rsc/dado" + std::to_string(i) + ".img";
            Sprite sprite(filename);
            dieSprites.push_back(sprite);
        }
        std::cout << "All die face sprites loaded." << std::endl;
    }
    
    virtual ~Dado() {}
    
    int roll()
    {
        int result = dist(rng);
        updateSprite(result);
        
        return result;
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

        const SpriteBase* constSpriteBase = getSprite();
        Sprite* mutableSprite = nullptr;

        SpriteBase* spriteBaseMutable = const_cast<SpriteBase*>(constSpriteBase);
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
