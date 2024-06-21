#include <iostream>
#include <array>

enum ItemType {
    HealthPotion,
    Torch,
    Arrow,
    MaxTypes
};


int countTotalItems(const std::array<int, ItemType::MaxTypes>& items) {
    int total = 0;
    for (int count : items) {
        total += count;
    }
    return total;
}

int main() {
    
    std::array<int, ItemType::MaxTypes> inventory{ 2, 5, 10 };

    
    std::cout << "Total items: " << countTotalItems(inventory) << '\n';
    std::cout << "Torches: " << inventory[ItemType::Torch] << '\n';

    return 0;
}
