// 27-04-2024

class Solution {
  public:
    Node *mid(Node *head)
    {
        Node *slow = head;
        Node * fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node *merge(Node *left, Node* right)
    {
        if(left == NULL)
            return right;
        
        if(right == NULL)
            return left;
        
        Node *ans = new Node(-1);
        Node *temp = ans;
        
        while(left!=NULL && right!=NULL)
        {
            if(left->data < right->data)
            {
                temp->next = left;
                left->prev = temp;
                temp = left;
                left = left->next;
            }
            
            else
            {
                temp->next = right;
                right->prev = temp;
                temp = right;
                right = right->next;
            }
        }
        
        while(left!=NULL)
        {
            temp->next = left;
            left->prev = temp;
            temp = left;
            left = left->next;
        }
        
        while(right!=NULL)
        {
            temp->next = right;
            right->prev = temp;
            temp = right;
            right = right->next;
        }
        
        ans = ans->next;
        ans->prev = NULL;
        return ans;
    }
    
  
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        Node *middle = mid(head);
        
        Node *left = head;
        Node *right = middle->next;
        
        middle->next = NULL;
        right->prev = NULL;
        
        left = sortDoubly(left);
        right = sortDoubly(right);
        
        Node *result = merge(left, right);
        
        return result;
        
    }
};
