#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

template <typename T>
class Tag {
public:
    Tag(bool isTagged, T value) : _tagged{ isTagged }, _value{ value } {}

    bool isTagged() const { return _tagged; }
    T item() const { return _value; }

private:
    bool _tagged;
    T _value;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Tag<T>& tag) {
    out << "TAG: tagged(" << (tag.isTagged() ? "true" : "false") << "), item(" << tag.item() << ")";
    return out;
}

bool isCarTagged(Tag<Car> tag) {
    return tag.isTagged();
}

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    std::vector<Car> carV = cars;
    std::vector<Tag<Car>> taggedCars;


    // TODO: populate 'taggedCars' with elements of type Tag<Car> where the tag is set to true
    //  only if the price < 10,000 or if the vin starts with a letter in A...F

    for (Car car : carV) {
        if (car.price() < 10000 || (car.vin().at(0) >= 'A' && car.vin().at(0) <= 'F')) {
            Tag<Car> tag = Tag<Car>(true, car);
            taggedCars.push_back(tag);
        }
    }

    // TODO: arrange `taggedCars` so that the elements tagged `true` are at the beginning
    //  and `false` elements are at the ened

    std::partition(std::begin(taggedCars), std::end(taggedCars), isCarTagged);

    std::cout << "Tagged Cars: " << taggedCars << "\n";
}