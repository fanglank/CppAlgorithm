// struct priorityItem {
//     int 
// }
#include <queue>
#include <vector>
#include <limits>
using namespace std;

struct cmpSmall {
    bool operator() ( const vector<int> p1 , const vector<int> p2 ){//默认是less函数
        //返回true时，a的优先级低于b的优先级（a排在b的后面）
        return p2[0] + p2[1] - p1[0] - p1[1];
    }
};

vector<vector<int> > kSmallEstPairs(vector<int> nums1, vector<int> nums2, int k){
    priority_queue<vector<int>  ,vector<vector<int> > , cmpSmall> maxHeap;
    for(int i = 0; i < min(k, static_cast<int>(nums1.size())); i++){
        for(int j =0 ;j < min(k,  static_cast<int>(nums2.size())); j++){
            vector<int> he;
            
            he.push_back(nums1[i]);
            he.push_back(nums2[j]);

            if(maxHeap.size() >=k){
                vector<int> root = maxHeap.top();
                // maxHeap.pop();
                
                if(root[0]+root[1]>nums1[i] + nums2[j]) {
                    maxHeap.pop();
                    
                    maxHeap.push(he);
                }
            }else {
                    maxHeap.push(he);
            }
        }
    }
    vector<vector<int> > result;
    while (!maxHeap.empty())
    {
        vector<int> vals = maxHeap.top();
        maxHeap.pop();
        result.push_back(vals);
    }
    return result;
}

struct cmpSmall1 {
    bool operator() ( const vector<vector<int> > p1 , const vector<vector<int> > p2 ){//默认是less函数
        //返回true时，a的优先级低于b的优先级（a排在b的后面）
        return p1[0][p1[0][0]] + p2[1][p1[0][1]] -p2[1][p1[0][0]] - p1[0][p1[0][1]]; //+ p2[1] - p1[0] - p1[1];
    }
};
vector<vector<int> > kSmallEstPairs1(vector<int> nums1, vector<int> nums2, int k){
    priority_queue<vector<int>  ,vector<vector<int> > , cmpSmall1> maxHeap;

}