// Inimigo.hpp
#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include <iostream>

class Inimigo : public ObjetoDeJogo {
public:
    Inimigo(std::string name, const Sprite &sprite, unsigned posL, unsigned posC)
        : ObjetoDeJogo(name, sprite, posL, posC) {}

    virtual ~Inimigo() {}

    void kill() {
        ondeath();
        this->desativarObj();
    }

    virtual void ondeath() {
        std::cout << getName() << " has died." << std::endl;
    }

};

#endif // INIMIGO_HPP
