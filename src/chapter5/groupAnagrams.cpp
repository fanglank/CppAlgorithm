#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string> > groupAnagrams(vector<string> strs){
    vector<int> hash={1,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    unordered_map<long, vector<string> > groups;

    for(string str: strs) {
        long wordHash = 1;
        for(int i =0;i<str.length();i++){
            wordHash*=hash[str.at(i) -'a'];
        }
        if(groups.count(wordHash) == 0) {
            vector<string> strings;
            groups[wordHash] = strings;
        } 

        groups[wordHash].push_back(str);

    }
    vector<vector<string> > results;
    for (auto it = groups.cbegin(); it != groups.cend(); ++it)
		results.push_back(it->second);
    return results;
}