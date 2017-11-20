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

};


#endif //SORTING_MULTISORTER_H
