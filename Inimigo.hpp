#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp" // Include the base class header

class Inimigo : public ObjetoDeJogo {
public:
    // Constructor: Initializes an Inimigo with a name, position (posL, posC), and a sprite
    Inimigo(std::string name, const Sprite &sprite, unsigned posL, unsigned posC)
        : ObjetoDeJogo(name, sprite, posL, posC) {}

    // Method to 'kill' the enemy, which deactivates it
    void kill() {
        this->desativarObj(); // Calls the inherited method to deactivate the object
    }
    
};

#endif // INIMIGO_HPP