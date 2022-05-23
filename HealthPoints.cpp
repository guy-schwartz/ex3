//
// Created by Guy Schwartz on 19/05/2022.
//
#include "HealthPoints.h"

HealthPoints::HealthPoints(int maxPoints):m_maxValue(maxPoints), m_currentValue(maxPoints)
{
    if(maxPoints <= 0)
    {
        throw InvalidArgument();
    }
}

HealthPoints& HealthPoints::operator+=(const int points)
{
    int temp=m_currentValue+points;
    m_currentValue=temp;
    if(temp>m_maxValue)
    {
        m_currentValue=m_maxValue;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(const int points)
{
    int temp=m_currentValue-points;
    m_currentValue=temp;
    if(temp<0)
    {
        m_currentValue=0;
    }
    return *this;
}

HealthPoints HealthPoints::operator+(const int pointsToAdd) const
{
    HealthPoints result(*this);
    return (result+=pointsToAdd);
}

static HealthPoints operator+(const int points, const HealthPoints &addTo)
{
    return (addTo+points);
}

HealthPoints HealthPoints::operator-(const int points) const
{
    HealthPoints result(*this);
    return (result-=points);
}

HealthPoints operator-(int points, HealthPoints &a)
{
    int temp=points-a.m_currentValue;
    if(temp<0)
    {
        temp=0;
    }
    HealthPoints b=temp;
    return b;
}

int main(){
    HealthPoints b=250;
    b=200-b;
    std::cout<<b.m_currentValue;
    return 0;
}