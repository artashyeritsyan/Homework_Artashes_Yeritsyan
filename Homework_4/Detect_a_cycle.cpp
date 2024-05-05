#include <unordered_map>

bool has_cycle(Node* head) {
    if (head == NULL) {
        return false;
    }

    unordered_map<Node*, int> umap;
    Node* ptr = head;

    while (ptr->next != NULL) {
        ++umap[ptr];

        if(umap[ptr] >= 2) {
            return true;
        }

        ptr = ptr->next;
    }

    return false;
}