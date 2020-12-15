#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Initial: " << cars << "\n";

    // TODO: print out the cars in reverse order
    std::vector<Car> reversedPrice = cars;
    std::reverse(std::begin(reversedPrice), std::end(reversedPrice));
    
    std::cout << "Reversed: " << reversedPrice << "\n";



}