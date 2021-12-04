/*         Intersection Point in Y Shapped Linked Lists

Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List

Example 2:

Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL      

*/

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    
    if(head1==NULL || head2==NULL)
    {
        return -1;
    }
    
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    
    while(ptr1!=ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        
        if(ptr1 == NULL)
        {
            ptr1 = head2;
        }
        
        if(ptr2 == NULL)
        {
            ptr2 = head1;
        }
    }
    
    return -1;
}
