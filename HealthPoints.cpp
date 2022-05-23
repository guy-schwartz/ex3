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

HealthPoints& HealthPoints::operator+=(int points)
{
    int temp=m_currentValue+points;
    m_currentValue=temp;
    if(temp>m_maxValue)
    {
        m_currentValue=m_maxValue;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(int points)
{
    int temp=m_currentValue-points;
    m_currentValue=temp;
    if(temp<0)
    {
        m_currentValue=0;
    }
    return *this;
}

HealthPoints HealthPoints::operator+(int pointsToAdd) const
{
    HealthPoints result(*this);
    return (result+=pointsToAdd);
}

HealthPoints HealthPoints::operator-(int points) const
{
    HealthPoints result(*this);
    return (result-=points);
}

int main(){
    HealthPoints a=300;
    HealthPoints b=250;
    a=b+30;
    std::cout<<a;
    return 0;
}