
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
#include "./src/chapter2/NumMatrix.cpp"
#include "./src/chapter3/checkInclusion.cpp"
#include "./src/chapter3/lengthOfLongestSubstring.cpp"
#include "./src/chapter3/minWindow.cpp"
#include "./src/chapter3/validPalindrome.cpp"
#include "./src/chapter3/countSubStrings.cpp"
#include "./src/chapter4/ListNode.cpp"
#include "./src/chapter5/RandomizedSet.cpp"
#include "./src/chapter5/LRUCache.cpp"
#include "./src/chapter5/isAnagram.cpp"
#include "./src/chapter5/groupAnagrams.cpp"
#include "./src/chapter5/isAlienSorted.cpp"
#include "./src/chapter5/findMinDifference.cpp"
#include "./src/chapter6/evalRPN.cpp"
#include "./src/chapter6/asteroidCollision.cpp"
#include "./src/chapter6/dailyTemperatures.cpp"
#include "./src/chapter6/largestRectangleArea.cpp"

#include "./src/chapter7/MovingAverage.cpp"
#include "./src/chapter7/bfs.cpp"
#include "./src/chapter7/CBTInserter.cpp"
#include "./src/chapter7/largestValues.cpp"
#include "./src/chapter7/findBottomLeftValue.cpp"
#include "./src/chapter8/TreeNode.cpp"
#include "./src/chapter8/BinaryTree.cpp"
using namespace std;
using namespace chapter2;
// using namespace chapter8;
// using namespace chapter5;
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
    
    vector<vector<int> > matrix;//(5, vector<int>(5)); // = {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
    matrix.push_back({3,0,1,4,2});
    matrix.push_back({5,6,3,2,1});
    matrix.push_back({1,2,0,1,5});
    matrix.push_back({4,1,0,1,7});
    matrix.push_back({1,0,3,0,5});
    NumMatrix nMatrix(matrix);
    int res15 = nMatrix.sumRegion(2,1,4,3);
    cout <<"res15:"<<res15<<endl;

    string s1 = "ca";
    string s2 = "dgcaf";
    bool res16 = checkInclusion(s1,s2);
    cout<<"res16:"<<res16<<endl;
    s1 = "cbadabacg";
    s2 = "abc";
    vector<int> res17 = findAnagrams(s1, s2);
    for(auto item:res17) {
        cout <<"items:"<<item<<endl;
    }

    s1="babcca";
    int res18 = lengthOfLongestSubstring(s1);
    cout<<"res18:"<<res18<<endl;
    int res19 = lengthOfLongestSubstring1(s1);
    cout<<"res19:"<<res19<<endl;
    s1 = "ADDBANCAD";
    s2 = "ABC";
    string res20 = minWin(s1, s2);
    cout<<"res20:"<<res20<<endl;
    string res21 = minWin1(s1, s2);
    cout <<"res21:"<<res21<<endl;
    s1 = "abda";
    bool res22 = validPalindrome(s1);
    cout <<"res22:"<<res22<<endl;
    s1 = "abcba";
    int res23 = countSumstrings(s1);
    cout <<"res23:"<<res23<<endl;
    vector<int> list = {1,2,3,4,5,6};
    ListNode *first  = new ListNode(0);
    ListNode * dummy = first;
    for(auto num: list) {
        dummy->next = new ListNode(num);
        dummy = dummy->next;
    }
    ListNode *lN = new ListNode();
    lN->removeNthFromEnd(first,4);

    RandomizedSet rs;
    rs.insert(1);
    rs.insert(2);
    rs.insert(3);

    rs.remove(2);
    int res24 = rs.getRandom();
    cout<<"res24:"<<res24<<endl;
    int res25 = rs.getRandom();
    cout<<"res25:"<<res25<<endl;
    chapter5::LRUCache *lru = new chapter5::LRUCache(4);
    lru->put(1,1);
    lru->put(2,2);
    lru->put(3,3);
    lru->put(4,4);
    lru->put(5,5);
    lru->get(2);
    s1="anagram";
    s2="nagaran";
    bool res26 = isAnagram(s1,s2);
    cout<<"res26:"<<res26<<endl;
    bool res27 = isAnagram1(s1,s2);
    cout<<"res27:"<<res27<<endl;
    s1 = "zyxwvutsrqponmlkjihgfedcba";
    vector<string> strings ={"offer", "is", "yoming"};

    bool res28 = isAlienSorted(strings, s1);
    cout<<"res28:"<<res28<<endl;
    vector<string> ves = {"2", "1", "3", "*", "+"};
    int res29 = evalRPN(ves);
    cout<<"res29:"<<res29<<endl;
    vector<int> ast = {4,5,-6,4,8,-5};
    vector<int> res30 = asteroidCollision(ast);
    cout<<"res30:"<<res30.size()<<endl;
    vector<int> tem = {35,31,33,36,34};
    vector<int> res31 = dailyTemperatures(tem);
    cout<<"res31:"<<res31.size()<<endl;
    vector<int> rec = {3,2,5,4,6,1,4,2};
    int res32 = largestRectangleArea(rec);
    cout<<"res32:"<<res32<<endl;
    rec = {1,2,3,4,5,6,7};
    chapter7::MovingAverage *mag = new chapter7::MovingAverage(3);
    double res34 = mag ->next(3);
    cout<<"res34:"<<res34<<endl;
    return 0;
}