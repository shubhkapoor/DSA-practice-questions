/*        Print Linked List elements

Given a linked list. Print all the elements of the linked list.

Example 1:

Input:
N=2
LinkedList={1 , 2}
Output:
1 2
Explanation:
The linked list contains two 
elements 1 and 2.The elements 
are printed in a single line.

Example 2:

Input:
N = 3
Linked List = { 49, 10, 30}
Output: 
49 10 30
Explanation:
The linked list contains 3 
elements 49, 10 and 30. The 
elements are printed in a single 
line.

*/

class Solution
{
public:
    void display(Node *head)
    {
        //your code goes here

        Node* temp = head;

        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
