//
// Created by g on 11/26/17.
//

#include <iostream>
#include "Printer.h"

void Printer::printVector(char *title, std::vector<int> listToPrint) {
    printf("%s ", title);
    printf("[");
    for (int i = 0; i < listToPrint.size(); i++) {
        if (i != listToPrint.size() - 1) {
            printf("%i, ", listToPrint[i]);
        } else {
            printf("%i", listToPrint[i]);
        }
    }
    printf("]\n");
}

void Printer::printList(char *title, std::list<int> listToPrint) {

    std::list<int>::iterator i;
    int iterations = 0;

    printf("%s ", title);
    printf("[");
    for (i = listToPrint.begin(); i != listToPrint.end(); i++) {
        if (iterations != (listToPrint.size() - 1)) {
            printf("%i, ", *i);
        } else {
            printf("%i", *i);
        }
        iterations++;
    }
    printf("]\n");
}
