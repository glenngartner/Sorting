#include <iostream>
#include <RandomListGenerator.h>
#include <MultiSorter.h>
#include <list>

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::unique_ptr<RandomListGenerator> newList = std::make_unique<RandomListGenerator>(10, 0, 200, false);
    std::unique_ptr<MultiSorter> newSorter = std::make_unique<MultiSorter>(&newList->list);

    std::list<int> sortedList = newSorter->insertion();

    return 0;
}