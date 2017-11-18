//
// Created by glenn on 11/17/2017.
//

#include "MultiSorter.h"

MultiSorter::MultiSorter(std::vector<int> *sourceList) {
    this->sourceList = sourceList;
    this->sortedList = {};
}

void MultiSorter::insertion() {
    // clear the sorted list
    this->sortedList = {};
    // add the first element of the source list to the sorted list
    this->sortedList.push_back((*this->sourceList)[0]);

    // for every item in the sorted list collection (skip the first one)
    for (int i = 1; i < this->sourceList->size(); i++) {
        // initialize the sorted list index to 0 (the beginning)
        int sortedIndex = 0;

        while (sortedIndex < this->sortedList.size()) {
            // if the current item in the source list is less than the current item in the sorted list
            if ((*this->sourceList)[i] <= this->sortedList[sortedIndex]){
                // insert the source list item before the sorted list item
//                this->sortedList.insert()
            }
        };
    }
}
