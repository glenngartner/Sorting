//
// Created by glenn on 11/17/2017.
//

#include "MultiSorter.h"
#include <limits>
#include <cmath>
#include <limits>
#include <algorithm>

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
    // copy the source list (this may not be necessary, but I originally intended to edit the contents)
    std::vector<int> sourceCopy = *this->sourceList;
    // store values for the sorted array
    std::vector<int> heapSorted(this->sourceList->size(), -1);

    // walk through each item in the list
    for (int i = 0; i < sourceCopy.size(); i++) {

        // store the value of the current item
        int currentItem = sourceCopy[i];

        // store the value of the children
//        int leftIndex = (2 * i) + 1;
//        int righIndex = (2 * i) + 2;

        // if this isn't the root node
        if (i != 0) {

            // store the value of the parent,
            int parentIndex = std::floor((i - 1) / 2);
            int parentValue = heapArray[parentIndex];

            // if the current item is greater than it's parent
            if (currentItem >= parentValue) {
                // add the current item to the current index in the heap array
                heapArray[i] = currentItem;

                // it's less than it's parent
            } else {
                // heapify this bad boy
                int j = i;
                int tempParentIndex = std::floor((j - 1) / 2);
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

    // now that everything is heaped, sort the array
    for (int i = 0; i < heapSorted.size(); i++) {
        // assign the root node of the heap to the sorted array, because it's always the smallest
        heapSorted[i] = heapArray[0];
        // once the root node is transferred, assign a max value to it
        heapArray[0] = std::numeric_limits<int>::max();
        // heapify the heap array again, since a max int value is at the top of the min heap
        heapArray = this->heapify(heapArray);
    }

    // return the sorted heap list
    return heapSorted;
}

/**
 * create's a min heap, assuming the root node in the argument is wrong
 * @param listToHeapify
 * @return a min heap vector
 */
std::vector<int> MultiSorter::heapify(std::vector<int> listToHeapify) {

    // create some variables
    int i = 0;
    bool doLoop = true;
    int currentValue;

    int leftChildIndex;
    int rightChildIndex;
    int leftChildValue;
    int rightChildValue;

    int min; // holds the minimum value, when the left and right child values are compared
    bool hasChildren;

    while (doLoop) {
        // find the indices of the left and right child of the current index item
        leftChildIndex = (2 * i) + 1;
        rightChildIndex = (2 * i) + 2;

        // if the left index value is within the vector size range
        if (leftChildIndex < listToHeapify.size()) {
            // assign the left child value from the heap array
            leftChildValue = listToHeapify[leftChildIndex];
            // if the left index value is outside of the vector size range
        } else {
            // assign the max int value. This prevents the occassional garbage int value being assigned with an out of range vector index is accessed
            leftChildValue = std::numeric_limits<int>::max();
        }

        // if the right index value is within the vector size range
        if (rightChildIndex < listToHeapify.size()) {
            //ass teh right child value from the heap array
            rightChildValue = listToHeapify[rightChildIndex];
            // if the right index value is outside of the vector size range
        } else {
            // assign the max int value. This prevents the occassional garbage int value being assigned with an out of range vector index is accessed
            rightChildValue = std::numeric_limits<int>::max();
        }

        // store the current int value of the heap index we're working with
        currentValue = listToHeapify[i];
        // compare the left and right child values of the current node. return the least of the two
        min = std::min(leftChildValue, rightChildValue);

        // if both the left and right child node indices are out of range (meaning, there are not actual children in this vector)
        if (leftChildIndex > (listToHeapify.size() - 1) && rightChildIndex > (listToHeapify.size()) - 1) {
            // set the hasChildren flag to false
            hasChildren = false;
            // if the left and right child indices are within range
        } else {
            // set the has children flag to true
            hasChildren = true;
        }

        // if the current value is greater than the value of one of its children, they should be swapped
        if (currentValue > min && hasChildren) {
            // if the left child value is smaller
            if (min == leftChildValue) {
                // swap the current value
                listToHeapify[i] = leftChildValue;
                listToHeapify[leftChildIndex] = currentValue;
                i = leftChildIndex;
                // otherwise, swap the right child values
            } else {
                listToHeapify[i] = rightChildValue;
                listToHeapify[rightChildIndex] = currentValue;
                i = rightChildIndex;
            }
            // if the current value is less than both of it's children
        } else {
            // stop looping, you're done heapifying
            doLoop = false;
        }
    }

    return listToHeapify;
}
