//
//  GameObject.h
//  Some Tank Game
//
//  Created by Damian Balandowski on 03.03.2014.
//  Copyright (c) 2014 Damian Balandowski. All rights reserved.
//

#ifndef __Some_Tank_Game__GameObject__
#define __Some_Tank_Game__GameObject__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>
#include "Vec2.h"

//------------------------------
// Drawable
//------------------------------
class Drawable
{
public:
    void load(std::string filename)
    {
        texture.loadFromFile(filename);
        texture.setSmooth(true);
        sprite.setTexture(texture);
    }
    
    int width() { return texture.getSize().x; }
    int height() { return texture.getSize().y; }
    
    sf::Sprite& operator()() { return sprite; }

private:
    sf::Sprite sprite;
    sf::Texture texture;
};

//------------------------------
// GameObject
//------------------------------
class GameObject
{
public:
    virtual void initialize(){setName("Unknown");rotation=0.0f;}
    virtual void update(float dt){}
    virtual void draw(sf::RenderWindow* window){}
    
    void setName(std::string name){this->name=name;} std::string getName() {return name;}
    
    // cast GameObject to other types
    template<typename T> static T cast(std::shared_ptr<GameObject> obj) {
        return std::dynamic_pointer_cast<T>(obj);
    }
    
    void pos(Vec2 vec) {position=vec;} Vec2 pos() { return position; }
    void vel(Vec2 vec) {velocity=vec;} Vec2 vel() { return velocity; }
    void rot(float r)  {rotation=r;} float rot() { return rotation; }
    
    virtual Vec2 size() { return Vec2(1.0f, 1.0f); }
    
    void setShouldBeRemoved(bool b) { shouldBeRemoved=b; }
    bool getShouldBeRemoved() { return shouldBeRemoved; }
    
    bool getCollidable() { return collidable; } void setCollidable(bool n) { collidable = n; }
protected:
    std::string name;
    Vec2 position, velocity;
    float rotation;
    bool collidable;
    bool shouldBeRemoved;
};

#endif /* defined(__Some_Tank_Game__GameObject__) */
