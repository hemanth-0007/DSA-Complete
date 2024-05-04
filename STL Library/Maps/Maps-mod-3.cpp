#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    myMap[5] = "one";
    myMap[2] = "ten";
    myMap[10] = "six";
    myMap[1] = "five";

    // The elements will be sorted automatically based on the keys
    // after each insertion.
    // The output will be: 1: "one", 2: "two", 5: "five", 10: "ten"
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
