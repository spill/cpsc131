#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include "GroceryItem.hpp"

int main() {
    std::vector<std::unique_ptr<GroceryItem>> groceryItems;

    while (true) {
        std::string productName;
        std::string brandName;
        std::string upcCode;
        double price = 0.0;  // Initialize 'price' to 0.0


        std::cout << "Enter product Name(Ctrl+D to exit): ";
        if (!(std::cin >> productName)) {
            break;  // Exit the loop on Ctrl+D or any invalid input
        }

        std::cout << "Enter brand name: ";
        std::cin >> brandName;

        std::cout << "Enter UPC code: ";
        std::cin >> upcCode;

        std::cout << "Enter price: ";
        std::cin >> price;

        // Create a unique_ptr to a GroceryItem and add it to the vector
        groceryItems.push_back(std::make_unique<GroceryItem>(productName, brandName, upcCode, price));
    }

for (auto it = groceryItems.crbegin(); it != groceryItems.crend(); ++it) {
    const auto &groceryItem = *it;
    std::cout << "Product: " << groceryItem->productName() << '\n';
    std::cout << "Brand: " << groceryItem->brandName() << '\n';
    std::cout << "UPC: " << groceryItem->upcCode() << '\n';
    std::cout << "Price: $" << groceryItem->price() << '\n';
    std::cout << "-------------------------" << '\n';
}



    // No need to manually delete items, as std::unique_ptr will handle it.

    return 0;
}
