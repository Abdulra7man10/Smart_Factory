#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class Step
{
private:
    int id;
    string description;
    int duration;

public:
    Step(int _id, const std::string& _description, int _duration)
        : id(_id), description(_description), duration(_duration)
    { }

    // Getter functions
    int getId() const
    {
        return id;
    }

    string getDescription() const
    {
        return description;
    }

    int getDuration() const
    {
        return duration;
    }

    // Setter functions
    void setId(int _id)
    {
        id = _id;
    }

    void setDescription(const std::string& _description)
    {
        description = _description;
    }

    void setDuration(int _duration)
    {
        duration = _duration;
    }

    //other
    void execution()
    {
        cout << description << endl;
        for (int i = duration; i > 0; i--)
        {
            cout << i << " ";
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
};
