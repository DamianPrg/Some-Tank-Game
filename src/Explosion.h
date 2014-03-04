//
//  Explosion.h
//  Some Tank Game
//
//  Created by Damian Balandowski on 03.03.2014.
//  Copyright (c) 2014 Damian Balandowski. All rights reserved.
//

#ifndef __Some_Tank_Game__Explosion__
#define __Some_Tank_Game__Explosion__

#include "GameObject.h"

class Explosion : public GameObject
{
public:
    void initialize();
    void update(float dt);
    void draw(sf::RenderWindow* window);
private:
    // not best way to do animations, but it is good for this game.
    std::vector<std::string> frames = {
        "data/gfx/explosion/expl_01_0000.png",
        "data/gfx/explosion/expl_01_0001.png",
        "data/gfx/explosion/expl_01_0002.png",
        "data/gfx/explosion/expl_01_0003.png",
        "data/gfx/explosion/expl_01_0004.png",
        "data/gfx/explosion/expl_01_0005.png",
        "data/gfx/explosion/expl_01_0006.png",
        "data/gfx/explosion/expl_01_0007.png",
        "data/gfx/explosion/expl_01_0008.png",
        "data/gfx/explosion/expl_01_0009.png",
        "data/gfx/explosion/expl_01_0010.png",
        "data/gfx/explosion/expl_01_0011.png",
        "data/gfx/explosion/expl_01_0012.png",
        "data/gfx/explosion/expl_01_0013.png",
        "data/gfx/explosion/expl_01_0014.png",
        "data/gfx/explosion/expl_01_0015.png",
        "data/gfx/explosion/expl_01_0016.png",
        "data/gfx/explosion/expl_01_0017.png",
        "data/gfx/explosion/expl_01_0018.png",
        "data/gfx/explosion/expl_01_0019.png",
        "data/gfx/explosion/expl_01_0020.png",
        "data/gfx/explosion/expl_01_0021.png",
        "data/gfx/explosion/expl_01_0022.png",
        "data/gfx/explosion/expl_01_0023.png"
    };
    
    int frame;
    const float frameMaxDur = 0.04f;
    const float explScale   = 2.4f;
    
    sf::Clock animationClock;
    
    Drawable explGfx;
};

#endif /* defined(__Some_Tank_Game__Explosion__) */
