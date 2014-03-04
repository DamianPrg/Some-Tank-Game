//
//  Item.cpp
//  Some Tank Game
//
//  Created by Damian Balandowski on 03.03.2014.
//  Copyright (c) 2014 Damian Balandowski. All rights reserved.
//

#include "Item.h"

void Item::initialize()
{
    std::string itemGfxPath = "data/gfx/items/";
    itemGfxPath += gfx;
    itemGfx.load(itemGfxPath);
    
    name = "Item";//name
}

void Item::update(float dt)
{
    
}

void Item::draw(sf::RenderWindow *window)
{
    itemGfx().setPosition(pos().x, pos().y);
    itemGfx().setRotation(rot());
    window->draw(itemGfx());
}
