//
// Created by glenn on 11/17/2017.
//

#include <vector>
#include <list>

#ifndef SORTING_MULTISORTER_H
#define SORTING_MULTISORTER_H


class MultiSorter {
public:
    MultiSorter(std::vector<int> *sourceList);

    std::vector<int>* sourceList;
    std::vector<int> sortedList;

    std::list<int> insertion();

    std::vector<int> heapSort();

    std::vector<int> heapify(std::vector<int> listToHeapify);

    void quickSort(std::vector<int> &listToSort, int startIndex, int arraySize);

    int partition(std::vector<int> &listToSort, int startIndex, int arraySize);

};


#endif //SORTING_MULTISORTER_H
