#include <unordered_map>
#include <vector>
using namespace std;
namespace chapter5{
    class ListNode{
        public:
        int key;
        int value;
        ListNode* next;
        ListNode* prev;
        ListNode(int k, int v){
            key =k;
            value =v;
        }
        ~ListNode(){

        }
    };
};