/*
 * Course: COEN 2220 - Programming 2
 * Name: Luis D. Cruz Medina
 * Lab: Lab 5 - Week 5 Practice: OOP and Function Templates
 * Description: Inheritance, polymorphism, and function template practice
 * Due date: [9/22/2026]
 */

#include <iostream>
#include <string>
using namespace std;

class CampusEvent
{
private:
    string name;

public:
    CampusEvent(string eventName)
    {
        name = eventName;
    }

    string getName() const
    {
        return name;
    }

    virtual void printDetails() const
    {
        cout << name << ": open attendance" << endl;
    }
};

class LimitedEvent : public CampusEvent
{
private:
    int availableSeats;

public:
    LimitedEvent(string eventName, int seats) : CampusEvent(eventName)
    {
        availableSeats = seats;
    }

    void printDetails() const override
    {
        cout << getName() << ": "
             << availableSeats << " seats available" << endl;
    }
};

// Part D will go here later
    template <class T>
    T largerValue(const T &value1, const T &value2)
    {
        if (value1 > value2)
        {
            return value1;
        }
        else
        {
        return value2;
        }
    }

int main()
{
    CampusEvent openEvent("Coding Club Meeting");

    cout << "--- Base event ---" << endl;
    openEvent.printDetails();

    // Part E will go here later
    LimitedEvent limitedEvent("Robotics Workshop", 18);

    CampusEvent *event1 = &openEvent;
    CampusEvent *event2 = &limitedEvent;

    cout << "--- Polymorphism ---" << endl;
    event1->printDetails();
    event2->printDetails();

    int attendance1 = 45;
    int attendance2 = 80;

    double rating1 = 4.2;
    double rating2 = 4.7;

    cout << "--- Function template ---" << endl;
    cout << "Higher attendance estimate: "
     << largerValue(attendance1, attendance2) << endl;

    cout << "Higher event rating: "
     << largerValue(rating1, rating2) << endl;
    return 0;
}