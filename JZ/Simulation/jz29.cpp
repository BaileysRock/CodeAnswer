//
// Created by Alienware on 2021/11/13.
//

// JZ29 顺时针打印矩阵

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
//    vector<int> printMatrix(vector<vector<int> > matrix) {
//        int left = 0;
//        int right = matrix[0].size();
//        int up = 0;
//        int down = matrix.size();
//        if(right==1 && down==1)
//            return matrix[0];
//        vector<int> vectortemp;
//        while (left < right) {
//            for (int i = left; i < right - 1; i++)
//                vectortemp.emplace_back(matrix[up][i]);
//            for (int i = up; i < down - 1; i++)
//                vectortemp.emplace_back(matrix[i][right - 1]);
//            for (int i = right - 1; i > 0; i--)
//                vectortemp.emplace_back(matrix[down - 1][i]);
//            for (int i = down - 1; i > 0; i--)
//                vectortemp.emplace_back(matrix[i][left]);
//            left = left + 1;
//            right = right - 1;
//            up = up + 1;
//            down = down - 1;
//            if (left == right - 1 && up == down - 1) {
//                return vectortemp;
//            } else if (left != right - 1 && up == down - 1) {
//                for (int i = left; i < right; i++)
//                    vectortemp.emplace_back(matrix[up][i]);
//                return vectortemp;
//            } else if (left == right - 1 && up != down - 1) {
//                for (int i = up; i < down; i++)
//                    vectortemp.emplace_back(matrix[i][left]);
//                return vectortemp;
//            }
//
//
//        }
//        return vectortemp;
//    }



    vector<int> printMatrix(vector<vector<int> > matrix) {
        int left = 0;
        int right = matrix[0].size();
        int up = 0;
        int down = matrix.size();
        vector<int> vectorInt;
        while (left <= right &&  up <= down) {
            vector<int> vectortemp = printMatrix(matrix,left,right,up,down);
            for (int i =0;i<vectortemp.size();i++)
                vectorInt.emplace_back(vectortemp[i]);
            left = left + 1;
            right = right - 1;
            up = up + 1;
            down = down - 1;
        }
        return vectorInt;

    }

    vector<int> printMatrix(vector<vector<int> > matrix,  int left, int right, int up, int down) {
        vector<int> vectortemp;
        if (left >= right || up >= down) {
            return vectortemp;
        }
        if(left ==right-1 && up==down-1) {
//            int m = matrix[up][down];
            vectortemp.emplace_back(matrix[up][left]);
            return vectortemp;
        }

        if (left == right - 1 && up != down - 1) {
            for (int i = up; i < down; i++) {
                vectortemp.emplace_back(matrix[i][left]);
            }
        } else if (left != right - 1 && up == down - 1) {
            for (int i = left; i < right; i++) {
                vectortemp.emplace_back(matrix[up][i]);
            }
        } else {
            for (int i = left; i < right - 1; i++)
                vectortemp.emplace_back(matrix[up][i]);
            for (int i = up; i < down - 1; i++)
                vectortemp.emplace_back(matrix[i][right - 1]);
            for (int i = right - 1; i > left; i--)
                vectortemp.emplace_back(matrix[down - 1][i]);
            for (int i = down - 1; i > up; i--)
                vectortemp.emplace_back(matrix[i][left]);
        }

        return vectortemp;
    }


};

int main() {

    vector<int> vector1 = {1, 2, 3, 4};
    vector<int> vector2 = {1, 2, 3, 4};
    vector<int> vector3 = {1, 2, 3, 4};
    vector<int> vector4 = {1, 2, 3, 4};
    vector<vector<int>> matrix = {vector1,vector2,vector3,vector4};
    vector<int> vector5 = {1};
    vector<vector<int>> matrix1 = {vector5};
    vector<int> vectortemp = (new Solution)->printMatrix(matrix);

    for(int i =0;i<vectortemp.size();i++)
        cout<<vectortemp[i]<<' ';

    return 0;
}