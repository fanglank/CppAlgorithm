#include <vector>
#include <iostream>
using namespace std;
int singleNumber(vector<int> vec) {
    int result = 0;
    for(int i =0 ;i <vec.size(); i++) {
        result ^=vec[i];
    }
    return result;
}

int singleNumber1(vector<int> nums) {
    vector<int> bitSums(32);
    for(auto num: nums){
        cout<<"num:"<<num<<endl;
        for(int i =0; i < 32; i++){
            bitSums[i] += (num >> (31 -i))&1;
        }
    }
    int result = 0;
    for(int i =0;i<32;i++){
        result = (result <<1)+bitSums[i]%3;
    }
    return result;
}