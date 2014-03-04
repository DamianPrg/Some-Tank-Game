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

class BaseTank : public GameObject
{
public:
protected:
  float turretRot;
  
  const float smoothRot=0.01f;
  const float speedRot =10.0f;
};

#endif /* defined(__Some_Tank_Game__BaseTank__) */
