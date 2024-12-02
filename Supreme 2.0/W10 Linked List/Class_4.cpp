#include<iostream>
using namespace std;

// struct for Linked List
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Linked List Cycle II (Leetcode 142)
class Solution{
public:
    ListNode* detectCycle(ListNode *head){
        ListNode* slow = head;
        ListNode* fast = head;
        bool iscycle = false;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                iscycle = true;
                break;
            }
        }
        if(!iscycle){
            return NULL;
        }
        // Replacement of iscycle boolean
        // if(fast == NULL){
        //     return NULL;
        // }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

// Add 1 to a linked list
class Solution2{
public:
    void reverse (ListNode *&head){
        ListNode *prev = NULL, *curr = head, *next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    void addOne(ListNode *&head){
        // reverse L.L 
        reverse(head);
        // add 1
        int carry = 1;
        ListNode *temp = head;
        while(temp->next != NULL){
            int totalsum = temp->val + carry;
            int digit = totalsum % 10;
            carry = totalsum / 10;

            temp->val = digit;
            temp = temp->next;
            if(carry == 0) break;
        }

        // processing the last node
        if(carry != 0){
            int totalsum = temp->val + carry;
            int digit = totalsum % 10;
            carry = totalsum / 10;

            temp->val = digit;
            if(carry != 0){
                ListNode *newNode = new ListNode(carry);
                temp->next = newNode;
            }
        }

        // Reverse again
        reverse(head);
    }

    // BY RECURSION
    int addOneUtil(ListNode *&head){
        if(head == NULL){
            return 1;
        }
        int carry = addOneUtil(head->next);
        int totalsum = head->val + carry;
        head->val = totalsum % 10;
        return totalsum / 10;
    }
    void addOnebyRecursion(ListNode *&head){
        int carry = addOneUtil(head);
        if(carry != 0){
            ListNode *newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
    }
};

// Reverse Nodes in Group of K (Leetcode 25)
class Solution3 {
public:
    int lengthOfLL(ListNode *head){
        ListNode *temp = head;
        int len = 0;
        while(temp){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;

        // 1 case mein solve karunga
        ListNode *prev=NULL, *curr=head;
        ListNode *nextNode = curr->next;
        int pos = 0;

        while(pos < k && curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }

        head->next = (nextNode != NULL && lengthOfLL(nextNode) >= k) ? reverseKGroup(nextNode, k) : nextNode;

        // if(nextNode != NULL && lengthOfLL(nextNode) >= k){
        //     head->next = reverseKGroup(nextNode, k);
        // }
        // else {
        //     head->next = nextNode;
        // }
        return prev;
    }
};

// Remove Duplicates from Sorted List (Leetcode 83)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        while(temp){
            if(temp->next){
                if(temp->val == temp->next->val){
                    ListNode* deltmp = temp->next;
                    temp->next = temp->next->next;
                    delete deltmp;
                }
                else temp = temp->next;
            }
            else temp = temp->next;
        }
        return head;
    }
};

/**
 * @HomeWork
 * 1. Sort in 0's 1's 2's in linked list (Leetcode 75)
 * 2. Add two numbers as linked list (Leetcode 2)
 * 3. Remove Duplicate from Sorted List II (Leetcode 82)
 * 4. Remove Nth Node from end of list (Leetcode 19)
 * 5. Sort linked list -> by Merge Sort (Leetcode 148) (Also, Merge Sort is better for linked list or Array?)
 * 6. Sort linked list -> by Quick Sort (Leetcode 148) (Also, Quick Sort is better for linked list or Array?)
 */