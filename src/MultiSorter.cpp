//
// Created by glenn on 11/17/2017.
//

#include "MultiSorter.h"
#include <limits>
#include <cmath>

MultiSorter::MultiSorter(std::vector<int> *sourceList) {
    this->sourceList = sourceList;
    this->sortedList = {};
}

std::list<int> MultiSorter::insertion() {
    // create a new, empty list that's the same size as the source list, with max integer values for each index (as placeholders)
    std::list<int> newList(this->sourceList->size(), std::numeric_limits<int>::max());
    // create a new list iterator item, and set the value to the beginning of the list
    std::list<int>::iterator it = newList.begin();

    // iterate over each item in the list, and place it in the correct location in the new list
    for (int i = 0; i < this->sourceList->size(); i++) {
        // store the current source list item value in an easy to write variable
        int currentItem = (*this->sourceList)[i];
        // set the list iterator to the beginning of the sorted list
        it = newList.begin();
        // if this is the first iteration, insert the current item into the first index of the sorted list
        if (i == 0) {
            *it = currentItem;
        } else {
            // if this isn't the first iteration
            // check if the current item is less than the first item in the sorted list
            if (currentItem < *it) {
                // if it is, push the current item to the front of the list
                newList.push_front(currentItem);
                // and delete the last item from the sorted list (a max-int placeholder)
                newList.pop_back();
                // if the current item is greater than teh first item in the sorted list
            } else {
                // crawl through the sorted list, until the current item is less than the sorted list item
                while (currentItem > *it) {
                    it++;
                }
                // if the current list item is a max int (a temporary placeholder)
                if (*it == std::numeric_limits<int>::max()) {
                    // replace the max int directly
                    *it = currentItem;
                } else {
                    // otherwise, insert the new item at this location
                    newList.insert(it, currentItem);
                    // and delete the last item in the list (which will always be a max-int placeholder)
                    newList.pop_back();
                }
            }
        }
    }
    return newList;
}

/**
 * Builds a min-heap from an unsorted list
 * @return
 */
std::vector<int> MultiSorter::heapSort() {
    // create an empty heap vector
    std::vector<int> heapArray(this->sourceList->size(), -1);
    // copy the source list
    std::vector<int> sourceCopy = *this->sourceList;

    // walk through each item in the list
    for (int i = 0; i < sourceCopy.size(); i++) {

        // store the value of the current item
        int currentItem = sourceCopy[i];

        // store the value of the children
        int leftIndex = (2 * i) + 1;
        int righIndex = (2 * i) + 2;

        // if this isn't the root node
        if (i != 0) {

            // store the value of the parent,
            int parentIndex = std::floor((i - 1) / 2);
            int parentValue = heapArray[parentIndex];

            // if the current item is greater than it's parent
            if (currentItem >= parentValue) {
                // push the current item to the back of the heap array
                heapArray[i] = currentItem;

                // it's less than it's parent
            } else {
                // heapify this bad boy
                int j = i;
                int tempParentIndex = std::floor((j-1) / 2);
                int tempParentValue = heapArray[tempParentIndex];
                while (currentItem < tempParentValue) {

                    // put the current value in it's parent's place
                    heapArray[tempParentIndex] = currentItem;

                    // place the parent in this current index position
                    heapArray[j] = tempParentValue;

                    j = tempParentIndex;
                    tempParentIndex = std::floor((tempParentIndex - 1) / 2);
                    tempParentValue = heapArray[tempParentIndex];
                }
            }

            // if this is the root node
        } else {
            // just store the value of the root at the heap root
            heapArray[i] = currentItem;
        }


    }

    return heapArray;
}
