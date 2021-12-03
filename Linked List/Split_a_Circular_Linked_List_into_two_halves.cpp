/*      Split a Circular Linked List into two halves 

Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting 
two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

Example 1:

Input:
Circular LinkedList: 1->5->7
Output:
1 5
7
 

Example 2:

Input:
Circular LinkedList: 2->6->1->5
Output:
2 6
1 5

*/

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast!=head && (fast->next)!=head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *head1_ref = head;
    *head2_ref = slow->next;
    
    // connect last element of first half with first element
    slow->next = *head1_ref;
    
    // connect last element of second half with first element of second half
    Node* temp = *head2_ref;
    
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    
    temp->next = *head2_ref;
}
