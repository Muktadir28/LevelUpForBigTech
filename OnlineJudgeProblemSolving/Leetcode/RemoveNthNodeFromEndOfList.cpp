//
//  RemoveNthNodeFromEndOfList.cpp
//  
//
//  Created by Md Muktadir on 3/3/24.
//
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* del = nullptr;
        ListNode* next = nullptr;
        collectTheOperationalNode(head, n, nullptr, prev, del, next);

        if(del == head) {
            head = head->next;
        } else {
            prev->next = next;
        }

        delete del;

        return head;
    }

    int collectTheOperationalNode(ListNode *head, int n, ListNode* par, ListNode* &prev, ListNode* &del, ListNode* &next) {
        if(head == nullptr) {
            return 0;
        }

        int reverseNodeNumber = 1 + collectTheOperationalNode(head->next, n, head, prev, del, next);

        if(n == reverseNodeNumber) {
            del = head;
            next = head->next;
            prev = par;
        }

        return reverseNodeNumber;
    }
};

#include <stdio.h>

int main() {
    //Nothing to do here
    return 0;
}
