#include <iostream>
#include <RandomListGenerator.h>
#include <memory>

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::unique_ptr<RandomListGenerator> newList = std::make_unique<RandomListGenerator>(10, 0, 200, false);
    return 0;
}