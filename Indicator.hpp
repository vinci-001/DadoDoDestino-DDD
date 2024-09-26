// Indicator.hpp
#ifndef INDICATOR_HPP
#define INDICATOR_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include <string>

// Struct to hold position coordinates
struct Position {
    unsigned posL;
    unsigned posC;
};

class Indicator : public ObjetoDeJogo
{
public:
    // Constructor that initializes the indicator with its sprite and initial position
    Indicator(std::string name)
        : ObjetoDeJogo(name, Sprite("rsc/v.img"), 0, 0), currentPositionIndex(0)
    {
        // Initialize fixed positions
        // You can manually alter these coordinates later as needed
        coordL1 = 5;
        coordC1 = 47;
        
        coordL2 = 5;
        coordC2 = 52;
        
        coordL3 = 5;
        coordC3 = 57;
        
        // Store positions in the positions array
        positions[0] = {coordL1, coordC1};
        positions[1] = {coordL2, coordC2};
        positions[2] = {coordL3, coordC3};
        
        // Set initial position
        moveTo(positions[currentPositionIndex].posL, positions[currentPositionIndex].posC);
    }
    
    virtual ~Indicator() {}
    
    // Method to cycle the indicator to the left (pressing 'J')
    void cycleLeft()
    {
        // Decrement the index and wrap around if necessary
        if (currentPositionIndex == 0)
            currentPositionIndex = totalPositions - 1;
        else
            currentPositionIndex--;
        
        // Move to the new position
        moveTo(positions[currentPositionIndex].posL, positions[currentPositionIndex].posC);
    }
    
    // Method to cycle the indicator to the right (pressing 'L')
    void cycleRight()
    {
        // Increment the index and wrap around if necessary
        currentPositionIndex = (currentPositionIndex + 1) % totalPositions;
        
        // Move to the new position
        moveTo(positions[currentPositionIndex].posL, positions[currentPositionIndex].posC);
    }

private:
    // Fixed position coordinates
    unsigned coordL1;
    unsigned coordC1;
    
    unsigned coordL2;
    unsigned coordC2;
    
    unsigned coordL3;
    unsigned coordC3;
    
    // Array to store fixed positions
    Position positions[3];
    static const int totalPositions = 3;
    
    // Current position index
    int currentPositionIndex;
};

#endif // INDICATOR_HPP
