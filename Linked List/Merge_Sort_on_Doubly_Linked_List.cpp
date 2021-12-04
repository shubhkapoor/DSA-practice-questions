/*          Merge Sort on Doubly Linked List

Given Pointer/Reference to the head of a doubly linked list of N nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and 
non-increasing order.

Example 1:

Input:
N = 8
value[] = {7,3,5,2,6,4,1,8}
Output:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
Explanation: After sorting the given
linked list in both ways, resultant
matrix will be as given in the first
two line of output, where first line
is the output for non-decreasing
order and next line is for non-
increasing order.

Example 2:

Input:
N = 5
value[] = {9,15,0,-1,0}
Output:
-1 0 0 9 15
15 9 0 0 -1
Explanation: After sorting the given
linked list in both ways, the
resultant list will be -1 0 0 9 15
in non-decreasing order and 
15 9 0 0 -1 in non-increasing order.

*/

struct Node *findMid(struct Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while(fast && fast->next)
    {
        fast = fast->next->next;
        if(fast)
        {
            slow = slow->next;
        }
    }

    return slow;
}

struct Node *merge(struct Node *head1, struct Node * head2)
{
    if(!head1)
    {
        return head2;
    }

    if(!head2)
    {
        return head1;
    }

    Node *ptr1 = head1;
    Node *ptr2 = head2;

    Node *reshead = NULL;
    Node *curr = NULL;

    while(ptr1 && ptr2)
    {
        if(ptr1->data <= ptr2->data)
        {
            if(!reshead)
            {
                reshead = ptr1;
                curr = ptr1;
            }
            else
            {
                curr->next = ptr1;
                ptr1->prev = curr;
                curr = curr->next;
            }

            ptr1 = ptr1->next;
        }
        else
        {
            if(!reshead)
            {
                reshead = ptr2;
                curr = ptr2;
            }
            else
            {
                curr->next = ptr2;
                ptr2->prev = curr;
                curr = ptr2;
            }

            ptr2 = ptr2->next;
        }
    }

    while(ptr1)
    {
        curr->next = ptr1;
        ptr1->prev = curr;
        curr = curr->next;
        ptr1 = ptr1->next;
    }

    while(ptr2)
    {
        curr->next = ptr2;
        ptr2->prev = curr;
        curr = curr->next;
        ptr2 = ptr2->next;
    }

    if(!ptr1 && !ptr2)
    {
        curr->next = NULL;
    }

    return reshead;
}

struct Node *sortDoubly(struct Node *head)
{
    // Your code here

    if(head && !head->next)
    {
        return head;
    }

    if(head && head->next)
    {
        Node *mid = findMid(head);
        Node *head1 = (mid!=NULL) ? (mid->next) : NULL;

        mid->next = NULL;
        head1->prev = NULL;

        head = sortDoubly(head);
        head1 = sortDoubly(head1);

        return merge(head,head1);
    }
}
