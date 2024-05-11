DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* p = llist;
    DoublyLinkedListNode* tmp = new DoublyLinkedListNode(data);
    
    if(data < p->data) {
        tmp->next = p;
        tmp->prev = NULL;
        p->prev = tmp;
        
        return tmp;
    }
    
    while(p->next != NULL) {
        if(data < p->next->data) 
            break;
        p = p->next;
    }
    
    if(p->next == NULL) {
        tmp->next = NULL;
        tmp->prev = p;
        p->next = tmp;
    }
    else {
        tmp->next = p->next;
        tmp->prev = p;
        p->next = tmp;
        tmp->next->prev = tmp;
    }

    return llist;
}