#include <vector>
using namespace std;
bool isSorted(string word1, string word2, vector<int> order){
    int i =0;
    for(;i<word1.length()&&word2.length();i++){
        char ch1 = word1.at(i);
        char ch2 = word2.at(i);
        if(order[ch1 -'a'] < order[ch2 -'a']){
            return true;
        }
        if(order[ch1 -'a']>order[ch2-'a']){
            return false;
        }
    }

    return i==word1.length();
}
bool isAlienSorted(vector<string> words, string order){
    vector<int> orderArray(order.length());
    for(int i =0;i<order.length();i++){
        orderArray[order.at(i)-'a'] = i;
    }

    for(int i =0;i<words.size()-1;i++){
        if(!isSorted(words[i],words[i+1], orderArray)){return false;}
    }
    return true;
}

