#include <iostream>
#include <RandomListGenerator.h>
#include <MultiSorter.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::unique_ptr<RandomListGenerator> newList = std::make_unique<RandomListGenerator>(25, 0, 200, false);
    std::unique_ptr<MultiSorter> newSorter = std::make_unique<MultiSorter>(&newList->list);

    std::list<int> insertionSortedList = newSorter->insertion();

    std::vector<int> heapSorted = newSorter->heapSort();

    return 0;
}