// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include "FaseStickman.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include <iostream> // For console output
#include <exception> // For exception handling

class Game
{
public:
    Game() {}
    ~Game() {}
    
    static void run()
    {
        try
        {
            // Load the box sprite located in rsc/caixa.img
            Sprite caixa("rsc/caixa.img");

            // Create a SpriteBuffer (screen buffer) to draw the game
            SpriteBuffer buffer(caixa.getLargura(), caixa.getAltura()); // Match buffer size to background sprite

            // Instantiate the Stickman phase
            FaseStickman faseStickman("FaseStickman", caixa);
            faseStickman.init();
            unsigned result = faseStickman.run(buffer); // Pass the phase's buffer

            if (result == Fase::END_GAME)
                std::cout << "Saindo do jogo..." << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "An error occurred during game execution: " << e.what() << std::endl;
        }
    }
};

#endif // GAME_HPP
