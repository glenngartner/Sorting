//
// Created by g on 11/26/17.
//

#ifndef SORTING_PRINTER_H
#define SORTING_PRINTER_H

#include <vector>
#include <list>

class Printer {
public:
    static void printVector(char *title, std::vector<int> listToPrint);

    static void printList(char *title, std::list<int> listToPrint);

};


#endif //SORTING_PRINTER_H
