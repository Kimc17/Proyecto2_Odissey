//
// Created by bamdres16 on 14/05/18.
//

#ifndef ODISSEY_QUICKSORT_H
#define ODISSEY_QUICKSORT_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "mayusConvert.h"
using namespace std;

class QuickSort : public mayusConvert{
public:
    void quickSort (vector<string> &str);

private:
    void quickSort(vector<string> &str, int left, int right);

};


#endif //ODISSEY_QUICKSORT_H
