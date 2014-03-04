//
//  Item.h
//  Some Tank Game
//
//  Created by Damian Balandowski on 03.03.2014.
//  Copyright (c) 2014 Damian Balandowski. All rights reserved.
//

#ifndef __Some_Tank_Game__Item__
#define __Some_Tank_Game__Item__

#include "GameObject.h"

class Item : public GameObject
{
public:
    void initialize();
    void update(float dt);
    void draw(sf::RenderWindow* window);
    
    void setGfx(std::string g) { gfx = g; }
    
    Vec2 size() { return Vec2(itemGfx.width(), itemGfx.height()); }
protected:
    Drawable itemGfx;
    std::string gfx;
};

#endif /* defined(__Some_Tank_Game__Item__) */
