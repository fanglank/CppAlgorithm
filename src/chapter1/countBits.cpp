#include <vector>
#include <iostream>
using namespace std;
vector<int> countBits(int num) {
    vector<int> result (0);
    result.push_back(0);
    for(int i =1; i <=num; ++i) {
        cout<<"result-"<<i<<endl;
        // result[i] = result[i&(i-1)] +1;
        // result[i] = result[i & (i-1)] + 1;
        result.push_back(result[i & (i-1)] + 1);
        // int j = i;
        // while(j!= 0) {
        //     cout<<"result"<<i<<":"<<result[i]<<endl;
        //     result[i]=result[i] + 1;
        //     j = j & (j-1);
        //     cout<<"j:"<<j<<endl;
        // }
    }

// vector<int> ans(0);
//         ans.push_back(0);
//         for (int i = 1; i <= num; ++i) {
//             ans.push_back(ans[i & (i-1)] + 1);
//         }
//         return ans;

//     cout<<"result size:"<<ans.size()<<endl;
    return result;
}
