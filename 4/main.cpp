#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);

int main() {
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";
}

bool Prime(int i) {
    for (int j = 2; j < i; j++) {
        if (i % j == 0) {
            return false;
        }
    }
    return true;
}

bool anyPrime(const std::vector<int>& values) {
    // TODO: return true if any of the values are prime numbers

    auto result = std::any_of(std::begin(values), std::end(values), Prime);

    return result;
}