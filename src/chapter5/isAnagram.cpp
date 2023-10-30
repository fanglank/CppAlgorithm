#include <vector>
#include <unordered_map>
using namespace std;
bool isAnagram(string s1, string s2){
    if(s1.length() != s2.length() || s1==s2) {
        return false;
    }

    vector<int> counts(26, 0);
    for(char ch : s1){
        counts[ch -'a']++;
    }

    for(char ch:s2){
        if(counts[ch -'a']==0){
            return false;
        }
        counts[ch -'a']--;
    }

    return true;
}

bool isAnagram1(string s1, string s2){
    if(s1.length() != s2.length() || s1==s2) {
        return false;
    }

    unordered_map<char, int> counts;
    for(char ch:s1){
        counts[ch] = counts[ch] +1;
    }
    for(char ch:s2){
        if(counts[ch]==0){
            return false;
        }

        counts[ch] = counts[ch] -1;
    }
    return true;
}