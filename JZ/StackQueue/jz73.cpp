//
// Created by Alienware on 2021/11/13.
//




#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {

        if (str.size() == 0)
            return str;
        vector<string> vstring;
        stack<string> stack1;
        int left = 0;
        for (int i = 0; i < str.size(); i++) {

            if (str[i] == ' ') {
                stack1.push(str.substr(left, i - left));
                left = i + 1;
            }

            else if (i == str.size() - 1) {
                stack1.push(str.substr(left, i - left + 1));
                left = i + 1;
            }

        }
        string string1 = "";
        while (!stack1.empty()) {
            string string2 = stack1.top();
            stack1.pop();
            string1 = string1 + string2+' ';
        }

        string1 = string1.substr(0,string1.size()-1);
        return string1;
    }
};

int main() {

    string string1 = "I am a student.";


    string string2 = (new Solution)->ReverseSentence(string1);
    cout << string2 << endl;
    return 0;


}