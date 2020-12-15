#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto integers = randomIntegers();
    std::cout << "Initial: " << integers << "\n";

    // TODO: make the sequence a bitonic sequence

    std::vector<int> bitonic = integers;

    int half = (bitonic.size() / 2);
    std:sort(std::begin(bitonic), std::begin(bitonic) + half);
    std::sort(std::begin(bitonic) + half, std::end(bitonic));
    std::reverse(std::begin(bitonic) + half, std::end(bitonic));

    std::cout << "Bitonic: " << bitonic << "\n";
}