//
// Created by g on 10/27/17.
//

#ifndef BINARY_SEARCH_RANDOMLISTGENERATOR_H
#define BINARY_SEARCH_RANDOMLISTGENERATOR_H

#include <memory>
#include <vector>

class RandomListGenerator {
public:
    RandomListGenerator(int numOfListEntries, int min, int max, bool sort = true);
    std::vector<int> list;
    void printList();
private:
    int returnRandomIntInRange(int min = 0, int max = 10);

};


#endif //BINARY_SEARCH_RANDOMLISTGENERATOR_H
