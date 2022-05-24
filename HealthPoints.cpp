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

bool operator==(const HealthPoints& object1, const HealthPoints& object2)
{
    return object1.m_currentValue==object2.m_currentValue;
}

bool operator!=(const HealthPoints& object1, const HealthPoints& object2)
{
    return !(object1==object2);
}

bool HealthPoints::operator<(const HealthPoints& object) const
{
    return m_currentValue<object.m_currentValue;
}

bool HealthPoints::operator>(const HealthPoints& object) const
{
    return m_currentValue>object.m_currentValue;
}

bool operator>=(const HealthPoints& object1, const HealthPoints& object2)
{
    return (object1>object2)||(object1==object2);
}

bool operator<=(const HealthPoints& object1, const HealthPoints& object2)
{
    return (object1<object2)||(object1==object2);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& points)
{
    os<<points.m_currentValue<<"("<<points.m_maxValue<<")";
    return os;
}
