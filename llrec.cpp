#include "llrec.h"

using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */

Node* getNext(Node* n);

void llpivothelper(Node *&head, Node *&smaller, Node *&larger, int pivot);
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    smaller = nullptr;
    larger = nullptr;
    if(head==nullptr){
        return;
    }
    llpivothelper(head, smaller,larger, pivot);

}


void llpivothelper(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == nullptr) {
 
        return;
    }

    Node* current = head;
    head = head->next; 

    if (current->val <= pivot) {
        if (smaller == nullptr) {
            smaller = current;
            smaller->next = nullptr;
        } else {
            getNext(smaller)->next = current;
            current->next = nullptr;
        }
    } else {
        if (larger == nullptr) {
            larger = current;
            larger->next = nullptr;
        } else {
            getNext(larger)->next = current;
            current->next = nullptr;
        }
    }

    llpivothelper(head, smaller, larger, pivot);
}


// Given list N, getNext iterates through the list and returns a pointer to the last item
Node* getNext(Node* n) {
    if (n == nullptr) {
        return nullptr;
    }
    if (n->next != nullptr) {
        return getNext(n->next);
    } else {
        return n;
    }
}
