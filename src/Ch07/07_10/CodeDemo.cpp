// Complete Guide to C++ Programming Foundations
// Challenge 07_10
// Design a Person Class, by Eduardo Corpeño 

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <utility>

class Person{
private:
    // Data Members (Private)
    std::string name;
    float energy;
    float happiness;
    float health;

public:
    // Constructor
    Person(const std::string& name, float energy, float happiness, float health) : name(name), energy(energy), happiness(happiness), health(health) {};

    // Eat Function
    void Eat(float calories) {
        energy += (calories * 7.0 / 200.0);
        if(energy > 100) energy = 100;
        
    }

    // Play Function
    void Play(float minutes) {
        happiness += minutes / 2.0;
        energy -= minutes / 3.0;
        if (happiness > 100) happiness = 100;
        if (energy < 0) energy = 0;
    }

    // Sleep Function
    void Sleep(float hours) {
        energy += hours * 3.75;
        health += hours * 2.5;
        if (energy > 100) energy = 100;
        if (health > 100) health = 100;
    }

    // Getter for Energy
    float GetEnergy() const{
        return energy;
    }

    // Getter for Happiness
    float GetHappiness() const {
        return happiness;
    }

    // Getter for Health
    float GetHealth() const{
        return health;
    }
};


int main(){
    // Example 1
    std::string name = "Alice";
    float energy = 40;
    float happiness = 22;
    float health = 80;

    float calories = 300;
    float playMinutes = 120;
    float sleepHours = 5;

    Person sporty(name, energy, happiness, health);
    sporty.Eat(calories);
    sporty.Play(playMinutes);
    sporty.Sleep(sleepHours);

    std::cout << "Your code returned: { ";
    std::cout << "Energy: " << sporty.GetEnergy() << ", ";
    std::cout << "Happiness: " << sporty.GetHappiness() << ", ";
    std::cout << "Health: " << sporty.GetHealth() << " }" << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}