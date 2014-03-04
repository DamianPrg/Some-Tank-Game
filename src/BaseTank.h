//
//  BaseTank.h
//  Some Tank Game
//
//  Created by Damian Balandowski on 03.03.2014.
//  Copyright (c) 2014 Damian Balandowski. All rights reserved.
//

#ifndef __Some_Tank_Game__BaseTank__
#define __Some_Tank_Game__BaseTank__

#include "GameObject.h"

// State machine
class FSM
{
public:
  FSM() {
    state = nullptr;
  }

  struct State {
    State(std::string n, std::function<void()> _cb) {
      name = n;
      cb = _cb;
    }
    
    std::string name;
    std::function<void()> cb;
  };
  
  std::vector<State> states;
  
  void addState(State state) {
    states.push_Back(state);
  }
  
  void setState(std::string name) {
    for(int i = 0; i < states.size(); i++)
    {
      if(states[i].name == name) {
        state = &states[i];
        break;
      }
    }
  }
  
  State* state;
  
  void update() {
    assert(state);
    state->cb();
  }
};

// vehicle/tank
class IVehBaseTank : public GameObject
{
public:
protected:
  float turretRot;
  
  const float smoothRot=0.01f;
  const float speedRot =10.0f;
  
  FSM aiFSM;//only to be used by AI tank
};

class EnemyTank : public IVehBaseTank
{
  
};

class PlayerTank : public IVehBaseTank
{
  
};

#endif /* defined(__Some_Tank_Game__BaseTank__) */
