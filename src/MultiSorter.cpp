//
// Created by glenn on 11/17/2017.
//

#include "MultiSorter.h"
#include <list>
#include <limits>

MultiSorter::MultiSorter(std::vector<int> *sourceList) {
    this->sourceList = sourceList;
    this->sortedList = {};
}

std::list<int> MultiSorter::insertion() {
    // create a new, empty list
    std::list<int> newList(this->sourceList->size(), std::numeric_limits<int>::max());
    std::list<int>::iterator it = newList.begin();

    // iterate over each item in the list, and place it in the correct location in the new list
    for (int i = 0; i < this->sourceList->size(); i++) {
        int currentItem = (*this->sourceList)[i];
        it = newList.begin();
        // insert the first item from the source list into the new list
        if (i == 0) {
            *it = currentItem;
        } else {
            if (currentItem < *it) {
                // add this item to the front, and shift all other items backwards
                newList.push_front(currentItem);
                newList.pop_back(); // remove the last item, so the list doesn't grow
            } else {
                while (currentItem > *it) {
                    it++;
                }
                if (*it == std::numeric_limits<int>::max()) {
                    *it = currentItem;
                } else {
                    newList.insert(it, currentItem);
                    newList.pop_back();
                }
            }
        }
    }
    return newList;
}
