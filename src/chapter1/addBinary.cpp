#include <iostream>
#include <algorithm>
using namespace std;
string addBinary(string a, string b) {
    string result = "";
    int i = a.length() - 1, j = b.length()-1;
    int carry = 0;
    while(i >=0 || j >=0) {
        int digitA = i>=0 ? a.at(i--) - '0':0;
        int digitB = j>=0 ? b.at(j--) - '0':0;
        cout<<"digitA:"<<digitA<<"digitB:"<<digitB<<result<<endl;
        int sum = digitA + digitB + carry;
        carry = sum >= 2 ? 1 : 0;
        sum = sum >= 2 ? sum-2:sum;
        result = result + std::to_string(sum);
    }
    if(carry == 1) {
        result = result + std::to_string(carry);
    }
    cout<<"result before:"<<result<<endl;
    reverse(result.begin(), result.end());
    cout<<"result:"<<result<<endl;
    return result;
}