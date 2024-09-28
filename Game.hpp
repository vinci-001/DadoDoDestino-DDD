// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include "FaseStickman.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteBuffer.hpp"
#include <iostream>
#include <exception>

class Game
{
public:
    Game() {}
    ~Game() {}
    
    static void run()
    {
        try
        {
            Sprite caixa("rsc/caixa.img");

            SpriteBuffer buffer(caixa.getLargura(), caixa.getAltura());

            FaseStickman faseStickman("FaseStickman", caixa);
            faseStickman.init();
            unsigned result = faseStickman.run(buffer);

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
