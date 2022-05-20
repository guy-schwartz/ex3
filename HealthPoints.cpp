//
// Created by Guy Schwartz on 19/05/2022.
//
#include "HealthPoints.h"

HealthPoints::HealthPoints(int maxPoints):m_maxValue(maxPoints), m_currentValue(maxPoints)
{
    if(maxPoints <= 0)
    {

    }
}