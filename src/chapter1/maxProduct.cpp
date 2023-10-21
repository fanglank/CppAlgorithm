
#include <vector>
using namespace std;
int maxProduct(vector<string> words){
    vector<vector<bool> > flags(words.size(),vector<bool>(26, false));
    for(int i =0; i<words.size(); i++){
        for(int j =0; j < words[i].size(); j ++ ){
            flags[i][words[i].at(j) -'a'] = true;
        }
    }

    int result = 0;
    for(int i =0; i<words.size(); i++){
        for(int j =i+1;j<words.size();j++){
            int k =0;
            for(;k<26;k++){
                if(flags[i][k] && flags[j][k]){
                    break;
                }
  
            }
                if(k==26){
                    int prod = words[i].size()*words[j].size();
                    result = max(result, prod);
                }
        }
    }
    return result;
}