// FaseStickman.hpp
#ifndef FASESTICKMAN_HPP
#define FASESTICKMAN_HPP

#include "ASCII_Engine/Fase.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Inimigo.hpp"
#include "Wizard.hpp"
#include "Stick.hpp"
#include "Dado.hpp"
#include <string>

class FaseStickman : public Fase
{
public:
    FaseStickman(std::string name, const Sprite &bkg)
        : Fase(name, bkg), dado(nullptr), stickman(nullptr) {}
    
    virtual ~FaseStickman();
    
    virtual void init();
    virtual unsigned run(SpriteBuffer &screen);

     bool areEnemiesAlive() const;

private:
    ObjetoDeJogo* stickman;   
    Dado* dado;              
    Inimigo* inimigo1;      
    Inimigo* inimigo2;     
    Inimigo* inimigo3;      
    Wizard* wizard;      

    std::list<Inimigo*> inimigos;
    bool colideComParede() const;
};

#endif // FASESTICKMAN_HPP
