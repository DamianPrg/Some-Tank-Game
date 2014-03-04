//
//  Game.h
//  Some Tank Game
//
//  Created by Damian Balandowski on 03.03.2014.
//  Copyright (c) 2014 Damian Balandowski. All rights reserved.
//

#ifndef __Some_Tank_Game__Game__
#define __Some_Tank_Game__Game__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <cassert>
#include <fstream>

#include "GameObject.h"
#include "Item.h"
#include "Explosion.h"

//------------------------------
// State
//------------------------------
class State {
public:
    State(std::string _name,
                std::function<void()> init,
                std::function<void()> update,
                std::function<void()> draw) {
        name = _name;
        
        _func_init = init;
        _func_update = update;
        _func_draw = draw;
    }
    
    std::string name;
    std::function<void()> _func_init, _func_update, _func_draw;
};

//------------------------------
// CGame
//------------------------------
class CGame
{
public:
    void initialize();
    void update();
    void draw();
    
    void menuInitialize();
    void menuUpdate();
    void menuDraw();
    
    void addState( State state );
    void setState( std::string name );
    
    void addGameObject(std::shared_ptr<GameObject> gameObject)
    {
        gameObject->initialize();
        gameObjects.push_back(gameObject);
    }
    
    void run(int width = 800, int height = 600, const char* title = "App", bool fullscreen=false);
    
    void collision (std::shared_ptr<GameObject> gameObject1,
                    std::shared_ptr<GameObject> gameObject2);
    

    void load(std::string filename);
    
    void WriteText(std::string text, Vec2 pos=Vec2(0.0f,0.0f), float size=1.0f)
    {
        static sf::Text t;
        t.setFont(font);
        t.setString(text);
        t.setPosition(pos.x, pos.y);
        t.setScale(size, size);
        
        window.draw(t);
    }
private:
    std::vector<State> states;
    State* state;
    sf::RenderWindow window;
    sf::View         view;
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    float dt;
    sf::Clock        gameClock;
    
    Drawable         background;
    sf::Font         font;
};

extern CGame Game;

#endif /* defined(__Some_Tank_Game__Game__) */
