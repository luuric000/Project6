#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"
#include <numeric>

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    // TODO: print the average price and price range

    std::vector<Car> carList = cars;
    std::vector<double> prices;

    for (Car i : carList) {
        prices.push_back(i.price());
    }

    double average = 0;
    average = std::accumulate(std::begin(prices), std::end(prices), 0);
    average /= carList.size();

    double max = 0;
    max = *std::max_element(std::begin(prices), std::end(prices));

    double min = 0;
    min = *std::min_element(std::begin(prices), std::end(prices));

    std::cout << "The average price is: $" << average << "\n";

    std::cout << "The range is: $" << max - min << "\n";
}