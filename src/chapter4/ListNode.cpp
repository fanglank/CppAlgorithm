using namespace std;
class ListNode
{
private:
    
public:
    int val;
    ListNode *next;
    ListNode *pre;
    ListNode *child;
    ListNode();
    ListNode(int mValue);
    ListNode(int x, ListNode *next);
    ListNode *append(ListNode* head, int value);
    ListNode *deleteNode(ListNode* head, int value);
    ListNode *removeNthFromEnd(ListNode * head, int n);
    ListNode *getNodeInLoop(ListNode * head);
    ListNode *detectCycle(ListNode * head);
    ListNode *detectCycle1(ListNode * head);
    ListNode *getIntersectionNode(ListNode* headA, ListNode* headB);
    ListNode *reverseList(ListNode* head);
    ListNode *addTwoNumbers(ListNode* head1, ListNode* head2);
    ListNode *addReversed(ListNode* head1, ListNode* head2);
    void reorderList(ListNode* head);
    void link(ListNode* node1, ListNode* node2, ListNode* head);
    bool isPalindrome(ListNode * head);
    bool equals(ListNode* head1, ListNode* head2);
    ListNode* flattenGetTail(ListNode* head);
    ListNode* flatten(ListNode* head);
    void insertCore(ListNode *head, ListNode *node);
    ListNode* insert(ListNode* head, int insertVal);
    ~ListNode();
};

ListNode::ListNode(int value)
{
    val = value;
}
ListNode::ListNode(){
    val = 0;
    next = nullptr;
}
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}
ListNode * ListNode::append(ListNode *head,int value){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* newNode = new ListNode(value);
    ListNode* node = dummy;
    while (node->next != nullptr){
        node = node->next;
    }
    node->next = newNode;
    return dummy->next;
    
}
ListNode *ListNode::deleteNode(ListNode* head, int value){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* node = dummy;
    while(node->next !=nullptr){
        if(node->next->val == value){
            node->next = node->next->next;
            break;
        }
        node = node->next;
    }
    return dummy->next;
}
ListNode::~ListNode()
{
    next = nullptr;
    delete next;
}
ListNode *ListNode::removeNthFromEnd(ListNode * head, int n){
    ListNode * dummy = new ListNode(0);
    dummy->next = head;
    ListNode *front = head;
    ListNode *back = dummy;
    for(int i =0; i<n;i++){
        front = front->next;
    }
    while (front != nullptr)
    {
        front = front->next;
        back = back->next;
    }

    back->next = back->next->next;
    return dummy->next;
    
}

ListNode *ListNode:: getNodeInLoop(ListNode * head){
    if(head == nullptr && head->next == nullptr) {
        return nullptr;
    }

    ListNode *slow = head->next;
    ListNode *fast = head->next;
    while (slow!= nullptr && fast!=nullptr)
    {
        if(slow==fast){
            return slow;
        }
 
        slow = slow->next;
        fast = fast->next;
        if(fast != nullptr) {
            fast = fast->next;
        }
    }
    return nullptr;
}

ListNode* ListNode::detectCycle(ListNode * head) {
    ListNode *inLoop = getNodeInLoop(head);
    if(inLoop == nullptr) {
        return nullptr;
    }
    int loopCount =1;
    for(ListNode *n = inLoop; n->next !=inLoop;n=n->next){
        loopCount++;
    }
    ListNode *fast = head;
    for(int i =0;i<loopCount;i++){
        fast = fast->next;
    }
    ListNode *slow = head;
    while (fast!=slow)
    {
        /* code */
        fast =fast->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* ListNode::detectCycle1(ListNode * head){
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast!=nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) {
            break;
        }
    }
    if(fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }

    slow = head;

    while (slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    
    return slow;
}

ListNode* ListNode::getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *p1 = headA, *p2 = headB;
    while (p1 !=p2)
    {
        if(p1->next == nullptr) {
            p1 = headB;
        }else {
            p1 =p1->next;
        }
        if(p2->next == nullptr) {
            p2 = headA;
        }else {
            p2 = p2->next;
        }

    }

    return p1;
    
}
ListNode * ListNode::reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur != nullptr)
    {
        ListNode* next = cur->next;
        prev = cur;
        cur = next;
    }
    return prev;
}

ListNode * ListNode::addReversed(ListNode* head1, ListNode* head2){
    ListNode *dummy = new ListNode(0);
    ListNode *sumNode = dummy;
    int carry =0;
    while(head1 != nullptr || head2 !=nullptr) {
        int sum = (head1 == nullptr ?0:head1->val)+(head2 == nullptr ?0:head2->val)+carry;
        carry = sum >= 10?1:0;
        sum = sum >=10?sum-10:sum;
        ListNode * newNode = new ListNode(sum);
        sumNode->next = newNode;
        sumNode = sumNode->next;
        head1 = head1==nullptr?nullptr:head1->next;
        head2 = head2==nullptr?nullptr:head2->next;

    }
    if(carry > 0){
        sumNode->next = new ListNode(carry);
    }
    return dummy->next;
}

ListNode* ListNode::addTwoNumbers(ListNode* head1, ListNode* head2) {
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    ListNode* reverseHead = addReversed(head1, head2);
    return reverseList(reverseHead);
}

void ListNode::reorderList(ListNode* head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow =dummy;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next;
        if(fast->next!=nullptr){
            fast = fast->next;
        }
    }
    ListNode *temp = slow->next;
    slow->next = nullptr;
    link(head, reverseList(temp), dummy);
}
void ListNode::link(ListNode* node1, ListNode* node2, ListNode* head){
    ListNode* prev = head;
    while(node1 != nullptr && node2!=nullptr){
        ListNode* temp = node1->next;
        prev->next = node1;
        node1->next = node2;
        prev = node2;
        node1 = temp;
        node2 = node2->next;
    }
    if(node1 !=nullptr){
        prev->next = node1;
    }
}

bool ListNode::isPalindrome(ListNode * head){
    if(head == nullptr || head->next == nullptr){
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast->next !=nullptr && fast->next->next !=nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *secondHalf = slow->next;
    if(fast->next !=nullptr){
        secondHalf = slow->next->next;
    }
    slow->next = nullptr;
    return equals(secondHalf, reverseList(head));
}
bool ListNode::equals(ListNode* head1, ListNode* head2){
    while (head1!=nullptr && head1!=nullptr)
    {
        if(head1->val != head2->val){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == nullptr && head2==nullptr;
}

ListNode* ListNode::flattenGetTail(ListNode* head) {
    ListNode* node = head;
    ListNode* tail = nullptr;
    while(node!=nullptr){
        ListNode* next = node->next;
        if(node->child!=nullptr){
            ListNode* child = node->child;
            ListNode* childTail = flattenGetTail(node->child);

            node->child = nullptr;
            node->next = child;
            child->pre = node;
            childTail->next = next;
            if(next != nullptr){
                next->pre = childTail;
            }
            tail = childTail;
        }else {
            tail = node;
        }
        node = next;
    }
    return tail;
}

ListNode* ListNode::flatten(ListNode* head) {
    flattenGetTail(head);
    return head;
}

void ListNode::insertCore(ListNode *head, ListNode *node) {
    ListNode* cur = head;
    ListNode* next = head->next;
    ListNode* biggest = head;
    while(!(cur->val <= node->val && next->val >=node->val) && next!=head){
        cur = next;
        next = next->next;
        if(cur->val >=biggest->val){
            biggest = cur;
        }
    }
    if(cur->val <=node->val && next->val>=node->val){
        cur->next = node;
        node->next = next;
    }else {
        node->next = biggest->next;
        biggest->next = node;
    }
}
ListNode* ListNode::insert(ListNode* head, int insertVal) {
    ListNode* node = new ListNode(insertVal);
    if(head == nullptr){
        head = node;
        head->next = head;
    }else if (head->next == head)
    {
        head->next =node;
        node->next = head;
    }else{
        insertCore(head, node);
    }
    return head;
    
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
