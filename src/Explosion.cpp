//
//  Explosion.cpp
//  Some Tank Game
//
//  Created by Damian Balandowski on 03.03.2014.
//  Copyright (c) 2014 Damian Balandowski. All rights reserved.
//

#include "Explosion.h"

void Explosion::initialize()
{
    explGfx.load(frames[0]);
    
    // make explosion bigger
    explGfx().setScale(explScale,explScale);
    
    rot(rand()%360);
    
    frame = 0;
}

void Explosion::update(float dt)
{
    if(animationClock.getElapsedTime().asSeconds() > frameMaxDur)
    {
        frame++;
        explGfx.load(frames[frame]);
        animationClock.restart();
    }
    
    if(frame >= frames.size()-1)
    {
        setShouldBeRemoved(true);
        frame=0;
    }
}

void Explosion::draw(sf::RenderWindow* window)
{
    explGfx().setPosition(pos().x, pos().y);
   // explGfx().setRotation(rot());
    window->draw(explGfx());
}
