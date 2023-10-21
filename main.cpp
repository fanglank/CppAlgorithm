
#include <iostream>
#include "./src/chapter1/divide.cpp"
#include "./src/chapter1/addBinary.cpp"
#include "./src/chapter1/countBits.cpp"
#include "./src/chapter1/singleNumber.cpp"
#include "./src/chapter1/maxProduct.cpp"
#include "./src/chapter2/twoSum.cpp"
#include "./src/chapter2/threeSum.cpp"
#include "./src/chapter2/minSubArrayLen.cpp"
#include "./src/chapter2/numSubArrayProductLessThanK.cpp"
#include "./src/chapter2/subarraySum.cpp"
#include "./src/chapter2/findMaxLength.cpp"
#include "./src/chapter2/pivotIndex.cpp"
using namespace std;
using namespace chapter2;

int main() {
    int res = divide(15,2);
    std::cout <<"result:" << res <<std::endl;
    string res1 = addBinary("11", "10");
    std::cout <<"result:" << res1 <<std::endl;
    vector<int> res2 = countBits(4);
    for(int i =0;i <res2.size();i++) {
        cout<<"res2:"<<res2[i]<<endl;
    }
    // std::cout <<"result:" << res1 <<std::endl;
    vector<int> num = {1,2,2};
    int res3 = singleNumber(num);
    cout<<"res3:"<<res3<<endl;
    num = {9,10,10,10};
    int res4 = singleNumber1(num);
    cout<<"res4:"<<res4<<endl;
    vector<string> words = {"acbw", "foo", "bar", "fxyz", "abcded"};
    int res5 = maxProduct(words);
     cout<<"res5:"<<res5<<endl;
    vector<int> numbers = {1,2,4,6,10};
    vector<int> res6 = twoSum(numbers, 8);
    for(auto item : res6) {
        cout<<"item:"<<item<<endl;
    }
    numbers = {-1, 0, 1,2,-1,-4};
    vector<vector<int>> res7 = threeSum(numbers);
    for(int i =0; i<res7.size(); i++) {
        for (int j =0; j<res7[i].size();j++){
            cout<<"res:"<<res7[i][j]<<endl;
        }
    }
    numbers = {5,1,4,3};
    int res8 = minSubArrayLen(7, numbers);
    cout << "res8:"<<res8<<endl;

    numbers = {10,5,2,6};
    int res9 = numSubArrayProductLessThanK(numbers, 100);
    cout<<"res9:"<<res9<<endl;
    numbers = {1,1,2};
    int res10 = removeDuplicates(numbers);
    cout <<"res10:"<<res10<<endl;

    int res11 = removeElement(numbers,1);
    cout <<"res11:"<<res11<<endl;
    numbers = {1,1,1};
    int res12 = subarraySum(numbers, 2);
    cout <<"res12:"<<res12<<endl;
    numbers = {0,1,0};
    int res13 = findMaxLength(numbers);
    cout <<"res13:"<<res13<<endl;
    numbers = {1,7,3,6,2,9};
    int res14 = pivotIndex(numbers);
    cout <<"res14:"<<res14<<endl;
    return 0;
}