// Complete Guide to C++ Programming Foundations
// Exercise 07_02
// Data Members, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Inventory{
public:
    Inventory(): capacity(10){
        items = new std::vector<std::string>();
    }

    Inventory(int capacity_i): capacity(capacity_i) {
        items = new std::vector<std::string>();
    }

    ~Inventory() {
        delete items;
    }

    void addItem(const std::string& item){
        if (items->size() < capacity)
            items->push_back(item);
        else
             std::cout << "Inventory is full, cannot add " << item << std::endl;  
    }

    void removeItem(const std::string& item) {
        auto it = std::find(items->begin(), items->end(), item);
        if (it != items->end())
            items->erase(it);
        else
            std::cout << "Item " << item << "not found in inventory" << std::endl;
    }

    std::string getItem(int index) const{
        if (index > 0 && index < items->size())
            return (*items)[index];
        else
            return "Index out of bounds";
    }

    int getItemCount() const {
        return items->size();
    }

    void displayInventory() const{
        std::cout << "Inventory: [ ";
        for(size_t i = 0; i < items->size(); i++) {
            std::cout << (*items)[i] << ", ";
        }
        std::cout << " ]" << std::endl;
    } 

private:
    std::vector<std::string> *items;
    int capacity;
};

int main(){
    Inventory myInventory(5);

    myInventory.addItem("Health Potion");
    myInventory.addItem("Mana Potion");
    myInventory.addItem("Sword");
    myInventory.addItem("Shield");
    myInventory.addItem("Bow"); 

    myInventory.displayInventory();

    myInventory.addItem("Arrow");

    myInventory.removeItem("Mana Potion");

    std::cout << "The inventory now contains: " << myInventory.getItemCount() << " items." << std::endl;

    std::cout << "Item at index 2: " << myInventory.getItem(2) << std::endl;

    myInventory.displayInventory();
    
    std::cout << std::endl << std::endl;
    return 0;
}
