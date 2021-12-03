/*        Reverse a linked list

Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.

Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.

*/

class Solution
{
public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list

        struct Node * prev = NULL;
        struct Node * cur = head;
        struct Node * nextnode;

        while(cur!=NULL)
        {
            nextnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextnode;
        }

        return prev;
    }
};
