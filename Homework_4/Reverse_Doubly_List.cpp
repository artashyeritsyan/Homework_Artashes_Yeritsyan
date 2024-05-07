DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* ptr = llist;
    DoublyLinkedListNode* tmp;
    while (ptr->next != NULL) {
        tmp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = tmp;
        
        ptr = ptr->prev;
    }
    
        tmp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = tmp;
    
    return ptr;
}