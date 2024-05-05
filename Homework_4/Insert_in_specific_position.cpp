SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* ptr = llist;
    SinglyLinkedListNode* tmpNode = new SinglyLinkedListNode(data);

    for(int i = 0; i < position - 1; ++i) {
        ptr = ptr->next;
    }

    tmpNode->next = ptr->next;
    ptr->next = tmpNode;

    return llist;    
}