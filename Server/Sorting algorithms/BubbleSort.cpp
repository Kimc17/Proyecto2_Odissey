//
// Created by bamdres16 on 14/05/18.
//

#include "BubbleSort.h"
void BubbleSort ::bubbleSort(vector<string> &str) {
    for (int i = 0 ; i < str.size(); i++) {
        str[i] = mayusConvert::mayus(str[i]);
    }
    bubbleSort(str,str.size());
}
void BubbleSort ::bubbleSort(vector <string> &str, int n) {
    bool swapped = true;

    int j = 0;

    string tmp;

    while (swapped) {

        swapped = false;

        j++;

        for (int i = 0; i < n - j; i++) {

            if (str[i] > str[i + 1]) {

                tmp = str[i];

                str[i] = str[i + 1];

                str[i + 1] = tmp;

                swapped = true;

            }

        }

    }


}