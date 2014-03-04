//
//  Game.cpp
//  Some Tank Game
//
//  Created by Damian Balandowski on 03.03.2014.
//  Copyright (c) 2014 Damian Balandowski. All rights reserved.
//

#include "Game.h"

// to do:
// - tank ai and player
// - train
// - map
// - airplane (shadow + bombing)
// - some tasks (destroy train, destory trucks) etc..)


void CGame::addState( State state )
{
    states.push_back(state);
}

void CGame::setState(std::string name)
{
    state = nullptr;
    
    for(auto it = states.begin(); it != states.end(); it++)
    {
        if((*it).name == name) {
            state = &(*it);
            state->_func_init(); // always initialize state which is beign set.
            break;
        }
    }
    
    // if state is not found, set state to first state in container
    if(!state)
        state = &states[0];

    assert( state );
}

void CGame::initialize()
{
    view.setSize(window.getSize().x,
                 window.getSize().y);
    
    view.setCenter(0.0f, 0.0f);
    
    window.setView(view);
    
    // load game
    load("data/game.txt");
    
    background.load("data/gfx/env/grass.png");
    
    addGameObject(std::make_shared<Explosion>());
    
    font.loadFromFile("data/fonts/sansation.ttf");
}

void CGame::update()
{
    // check for objects which want to be removed
    for(int i = 0; i < gameObjects.size(); i++)
    {
        if(gameObjects[i]->getShouldBeRemoved())
        {
            gameObjects.erase(gameObjects.begin() + i);
        }
    }
    
    // check for collisions
    for(int i = 0; i < gameObjects.size(); i++) {
        for(int j = 0; j < gameObjects.size(); j++)
        {
            if(i != j)
            {
                
            }
        }
    }
    
    for(auto it = gameObjects.begin(); it != gameObjects.end(); it++)
    {
        (*it)->update(dt);
    }
}

void CGame::draw()
{
    for(int x = -20; x < 20; x++)
    {
        for(int y = -20; y < 20; y++)
        {
            float _fx = x * background.width();
            float _fy = y * background.height();
            
            background().setPosition(_fx, _fy);
            window.draw(background());
        }
    }
    
    for(auto it = gameObjects.begin(); it != gameObjects.end(); it++)
    {
        (*it)->draw(&window);
    }
    
    WriteText("Find way to train, and destory it!",Vec2(100.0f,100.0f),0.5f);
}

void CGame::menuInitialize()
{
    window.setView(window.getDefaultView());
    font.loadFromFile("data/fonts/sansation.ttf");
}

void CGame::menuUpdate()
{
    
}


void CGame::menuDraw()
{
    WriteText("Not finished menu, not yet started :)");
}

void CGame::run(int width, int height, const char* title, bool fullscreen)
{
    addState(State("Game",
                   std::bind(&CGame::initialize, this),
                   std::bind(&CGame::update, this),
                   std::bind(&CGame::draw, this)));
    
    addState(State("Menu",
                   std::bind(&CGame::menuInitialize, this),
                   std::bind(&CGame::menuUpdate, this),
                   std::bind(&CGame::menuDraw, this)));
    
    setState("Game");
    //setState("Menu");
    
    // sfml
    window.create(sf::VideoMode(width,height), title);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    
    while( window.isOpen() )
    {
        state->_func_update();
        
        sf::Event e;
        window.pollEvent(e);
        
        if(e.type == sf::Event::Closed) window.close();
        
        window.clear(sf::Color(30.0f, 30.0f, 30.0f));
    
        state->_func_draw();
        
        window.display();
        
        dt = gameClock.restart().asSeconds();
    }
}

// called when there is collision between two objects
void CGame::collision (std::shared_ptr<GameObject> gameObject1,
                       std::shared_ptr<GameObject> gameObject2)
{
    
}

void CGame::load(std::string filename)
{
    // loading
    std::ifstream input(filename.c_str());
    std::vector<std::string> contents;
    while (!input.eof()) {
        std::string tmp ="";
        input >> tmp;
        contents.push_back(tmp);
    }
    input.close();
    
    // parsing
    for(int i = 0; i < contents.size(); i++)
    {
        if(contents[i] == "item") // item path pos_yx pos_y rot collidable
        {
            std::string path = contents[i+1];
            float       x    = atof(contents[i+2].c_str());
            float       y    = atof(contents[i+3].c_str());
            float       rot  = atof(contents[i+4].c_str());
            int         c    = atoi(contents[i+5].c_str());
            
            std::shared_ptr<Item> item = std::make_shared<Item>();
            item->setGfx(path);
            item->pos(Vec2(x,y));
            item->rot(rot);
            item->setCollidable(static_cast<bool>(c));
            addGameObject(item);
        }
        
        if(contents[i] == "train")
        {
            
        }
        
        if(contents[i] == "road")
        {
            std::string path = contents[i+1];
            float       x    = atof(contents[i+2].c_str());
            float       y    = atof(contents[i+3].c_str());
            float       rot  = atof(contents[i+4].c_str());
            int         repeat=atoi(contents[i+5].c_str());
        }
        
        if(contents[i] == "player") // player pos_x pos_y rot
        {
            
        }
        
        if(contents[i] == "enemy_tank") // enemy_tank pos_x pos_y rot state
        {
            
        }
        
        if(contents[i] == "enemy_truck") // enemy_truck pos_x pos_y rot state
        {
            
        }
        
        if(contents[i] == "train")
        {
            
        }
        
        if(contents[i] == "info") // info MESSAGE ; pos_x pos_y size_x size_y
        {
            
        }
    }
}

CGame Game;
