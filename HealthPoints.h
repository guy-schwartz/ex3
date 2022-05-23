//
// Created by Guy Schwartz on 19/05/2022.
//

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H
#include <iostream>

class HealthPoints
{
public:
    /**
     * HealthPoints c'tor
     * initializes health points to the maximum value
     * @param points - 100 is to be set in case no other input was entered
     * non-positive numbers will lead to an error occurrence
     */
    HealthPoints(int maxPoints = 100);

    /**
     * adds up a number to current health point value of current object
     * any way - health points value will not decrease down below zero or up above max healthpoints
     * @param points
     * @return - calculated vale
     */
    HealthPoints& operator+=(int points);

    /**
    * adds up a number to current health point value of a third-party object
    * any way - health points value will not decrease down below zero or up above max healthpoints
    * @param points
    * @return - calculated value
    */
    HealthPoints operator+(int pointsToAdd) const;

    /**
     * deducts a number from current health point value of current object
     * any way - health points value will not decrease down below zero or up above max healthpoints
     * @param points
     * @return - calculated vale
     */
    HealthPoints& operator-=(int points);

    /**
     * deducts a number from current health point value of a third-party object
     * any way - health points value will not decrease down below zero or up above max healthpoints
     * @param object1, object2
     * @return - calculated value
     */
    HealthPoints operator-(int points) const;

    /**
     * compares health points value between two objects
     * @param object1 -
     * @param object2
     * @return true if value is the same, false otherwise
     */
    friend bool operator==(const HealthPoints& object1, const HealthPoints& object2);

    /**
     * compares health points value between two objects
     * @param object
     * @return true if value is smaller than object, false otherwise
     */
    bool operator<(const HealthPoints& object) const;

    /**
     * compares health points value between two objects
     * @param object
     * @return true if value is greater than object, false otherwise
     */
    bool operator>(const HealthPoints& object) const;

    /**
     * printing function - follows the format: <currentValue>(<maxValue>)
     * @param os - current ostream
     * @param points - object to be printed
     * @return modified ostream
     */
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& points);

    /**
     * an exception meant to notify in case an invalid argument was sent to a function
     */
    class InvalidArgument {};


//private:
    int m_maxValue;
    int m_currentValue;
};


/**
 * compares health points value between two objects
 * @param object1 -
 * @param object2
 * @return true if value is not the same, false otherwise
 */
bool operator!=(const HealthPoints& object1, const HealthPoints& object2);

/**
 * compares health points value between two objects
 * @param object1, object2
 * @return true if value is greater or equal to object, false otherwise
 */
bool operator>=(const HealthPoints& object1, const HealthPoints& object2);

/**
 * compares health points value between two objects
 * @param object1, object2
 * @return true if value is smaller or equal to object, false otherwise
 */
bool operator<=(const HealthPoints& object1, const HealthPoints& object2);


#endif //EX3_HEALTHPOINTS_H
