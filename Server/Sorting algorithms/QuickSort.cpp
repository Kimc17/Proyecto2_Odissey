//
// Created by bamdres16 on 14/05/18.
//

#include "QuickSort.h"
void QuickSort ::quickSort(vector<string> &str) {
    for (int i = 0 ; i < str.size(); i++) {
        str[i] = mayusConvert::mayus(str[i]);
    }
    quickSort(str,0,str.size()-1);
}
void QuickSort  :: quickSort(vector<string> &str, int left, int right) {
    int i = left, j = right;
    string mid = str[(left + right) / 2];

    /* partition */

    while (i <= j) {
        while (str[i] < mid)
            i++;
        while (str[j] > mid)
            j--;
        if (i <= j) {
            string temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++; j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(str, left, j);
    if (i < right)
        quickSort(str, i, right);
}

