/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) 
            return NULL;
        queue<Node*> curr,next;
        curr.push(root);
        while(!curr.empty()){
            Node* temp = curr.front();
            curr.pop();
            if(temp->left) 
                next.push(temp->left);
            if(temp->right) 
                next.push(temp->right);
            if(curr.empty()){
                curr = next;
                next = {};
                temp->next = NULL;
            }
            else
                temp->next = curr.front();
        }
        return root;
    }
};