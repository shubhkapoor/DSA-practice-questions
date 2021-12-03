/*         Add two numbers represented by linked lists

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).

Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).

*/

class Solution
{
public:
    //Function to add two numbers represented by linked list.

    struct Node* reverse(struct Node* head)
    {
        struct Node* prev = NULL;
        struct Node* cur = head;
        struct Node* nextnode;

        while(cur!=NULL)
        {
            nextnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextnode;
        }

        return prev;
    }

    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here

        first = reverse(first);
        second = reverse(second);

        struct Node* temp;
        struct Node* res = NULL;
        struct Node* cur = NULL;

        int sum=0, carry=0;

        while(first!=NULL ||second!=NULL)
        {
            sum = carry + (first?first->data:0) + (second?second->data:0);
            carry = (sum>=10)?1:0;
            sum = sum%10;

            temp = new Node(sum);

            if(res == NULL)
            {
                res = temp;
                cur = temp;
            }
            else
            {
                cur->next = temp;
                cur = temp;
            }

            if(first)
            {
                first = first->next;
            }
            if(second)
            {
                second = second->next;
            }
        }

        if(carry>0)
        {
            temp = new Node(carry);
            cur->next = temp;
            cur = temp;
        }

        res = reverse(res);

        return res;
    }
};
