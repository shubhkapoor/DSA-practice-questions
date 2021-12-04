/*        Circular Linked List Delete at Position

Given a linked list of size n, you have to delete the node at position pos of the linked list and return the new head. The position of initial node is 1.
The tail of the circular linked list is connected to the head using next pointer.

Example 1:

Input:
LinkedList: 1->2->3->4->5
(the first and last node are connected,
i.e. 5 --> 1)
position: 4
Output: 1 2 3 5

Example 2:

Input:
LinkedList: 2->5->7->8->99->100
(the first and last node are connected,
i.e. 5 --> 1)
position: 6
Output: 2 5 7 8 99

*/

Node * deleteAtPosition(Node *head,int pos)
{
    //Your code here
    
    if(head==NULL)
    {
        return head;
    }
    
    Node* prev;
    Node* temp = head;
    int i=1;
    
    if(pos==1)
    {
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        
        temp->next = head->next;
        head = head->next;
        
        return head;
    }
    
    while(temp->next!=head && i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    
    temp->next = temp->next->next;
    
    return head;
}
