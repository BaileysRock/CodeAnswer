//
// Created by Alienware on 2021/11/12.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> mergeSort(vector<int> vectorInt, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(vectorInt, left, mid);
            mergeSort(vectorInt, mid + 1, right);
            merge(vectorInt, left, mid, right);
        }
        return vectorInt;
    }


    void Swap1(int &a, int &b) {
        a ^= b;
        b ^= a;  //b=b^a^b
        a ^= b;  //a=a^b^a^b
    }

    // 将a写入b
    void writeVector(int &a, int &b) {
        a ^= b;
        b ^= a;
    }

    vector<int> merge(vector<int> vectorInt, int left, int mid, int right) {
        int len = right - left + 1;
        int p1 = left;
        int p2 = mid + 1;
        int p = 0;
        vector<int> vectorsort(len);
        while (p1 <= mid && p2 <= right) {
            if (vectorInt[p1] <= vectorInt[p2]) {
                vectorsort[p] = vectorInt[p1];
                p++;
                p1++;

            } else {
                vectorsort[p] = vectorsort[p2];
                p++;
                p2++;
            }
        }
        while (p1 <= mid) {
            vectorsort[p] = vectorInt[p1];
            p++;
            p1++;
        }
        while (p2 <= right) {
            vectorsort[p] = vectorsort[p2];
            p++;
            p2++;
        }
        for (int i = 0; i < len; i++) {
            writeVector(vectorsort[i], vectorInt[i + left]);
        }
    }


};

int main() {
    vector<int> vector1 = {5, 6, 3, 1, 47, 8, 9, 1, 3, 5, 8, 1, 3, 9, 4, 8};

    vector<int> vectorSort = (new Solution)->mergeSort(vector1, 0, vector1.size());

    return 0;
}