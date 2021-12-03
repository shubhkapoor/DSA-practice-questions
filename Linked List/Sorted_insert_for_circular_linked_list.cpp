/*        Sorted insert for circular linked list

Given a sorted circular linked list, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

Example 1:

Input:
LinkedList = 1->2->4
(the first and last node is connected,
i.e. 4 --> 1)
data = 2
Output: 1 2 2 4

Example 2:

Input:
LinkedList = 1->4->7->9
(the first and last node is connected,
i.e. 9 --> 1)
data = 5
Output: 1 4 5 7 9

*/

class Solution
{
public:
    Node *sortedInsert(Node* head, int data)
    {
        //Your code here

        Node* newnode;
        newnode = new Node(data);

        if(head==NULL)
        {
            return newnode;
        }

        Node* curr = head;
        Node* prev;

        // If head element is greater than the data

        if(head->data >= data)
        {
            while(curr->next!=head)
            {
                curr = curr->next;
            }

            curr->next = newnode;
            newnode->next = head;

            return newnode;
        }
        else
        {
            while(curr->data <= data)
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = newnode;
            newnode->next = curr;

            return head;
        }
    }
};
