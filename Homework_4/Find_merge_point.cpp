#include <map>

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {    
    SinglyLinkedListNode* ptr1 = head1;
    SinglyLinkedListNode* ptr2 = head2;
    map<SinglyLinkedListNode*, int> m;

    while(ptr1->next != NULL){
        m[ptr1] = ptr1->data;
        ptr1 = ptr1->next;
    }
    
    while(ptr2->next != NULL){
        auto it = m.find(ptr2);
        if (it != m.end()) {
            return it->second;
        }
        ptr2 = ptr2->next;
    }
    
    return ptr1->data;
}