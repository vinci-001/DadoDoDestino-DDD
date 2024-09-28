// Wizard.hpp
#ifndef WIZARD_HPP
#define WIZARD_HPP

#include "Inimigo.hpp"
#include <iostream>

class Wizard : public Inimigo {
public:
    Wizard(std::string name, const Sprite &sprite, unsigned posL, unsigned posC)
        : Inimigo(name, sprite, posL, posC) {}

    virtual ~Wizard() {}

    virtual void ondeath() override {
        std::cout << getName() << " foi derrotado! VocÊ venceu o jogo!" << std::endl;
    }
};

#endif // WIZARD_HPP
