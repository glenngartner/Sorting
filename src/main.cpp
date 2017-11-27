#include <iostream>
#include <RandomListGenerator.h>
#include <MultiSorter.h>
#include <Printer.h>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

int main() {

    // Generate a random list
    std::unique_ptr<RandomListGenerator> newList = std::make_unique<RandomListGenerator>(25, 0, 200, false);
    // Create a new universal sorting object
    std::unique_ptr<MultiSorter> newSorter = std::make_unique<MultiSorter>(&newList->list);

    // print the unsorted list
    Printer::printVector("Unsorted List: ", *newSorter->sourceList);
    printf("\n");

    // Use insertion sort, print the sorted list, and print the execution time
    auto timeStart = Clock::now();
    std::list<int> insertionSortedList = newSorter->insertion();
    auto timeEnd = Clock::now();
    auto deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
    Printer::printList("Insertion Sorted: ", insertionSortedList);
    printf("Execution time: %lli nanoseconds\n\n", deltaTime);

    // Use heap sort, print the sorted list, and print the execution time
    timeStart = Clock::now();
    std::vector<int> heapSorted = newSorter->heapSort();
    timeEnd = Clock::now();
    deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
    Printer::printVector("Heap Sorted: ", heapSorted);
    printf("Execution time: %lli nanoseconds\n\n", deltaTime);

    // Use quick sort, print the sorted list, and print the execution time
    std::vector<int> quickSortSource = *newSorter->sourceList;

    timeStart = Clock::now();
    newSorter->quickSort(quickSortSource, 0, quickSortSource.size());
    timeEnd = Clock::now();
    deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
    Printer::printVector("Quick Sorted: ", quickSortSource);
    printf("Execution time: %lli nanoseconds\n\n", deltaTime);

    return 0;
}