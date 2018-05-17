//
// Created by bamdres16 on 14/05/18.
//

#ifndef ODISSEY_BUBBLESORT_H
#define ODISSEY_BUBBLESORT_H

#include <vector>
#include <string>
#include "mayusConvert.h"
using namespace std;
class BubbleSort : public mayusConvert{
public:
    void bubbleSort (vector<string> &str);
private:
    void bubbleSort(vector<string> &str, int n);

};


#endif //ODISSEY_BUBBLESORT_H
