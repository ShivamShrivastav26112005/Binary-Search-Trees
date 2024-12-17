// Morris Traversal  -: SC=O(1)

// Morris Traversal of BST -: 
// Morris Traversal is a type of iterative inorder traversal
// Morris Traversal == iterative inorder traversal
// SC=O(1) TC=(height)~O(h)!O(n)


// inorder traversal is always in sorted order. 

// Morris Traversal -: 


// steps -: 
// 1-: you know how to find "Inorder Predecessor". 


// finding Predecessor.
// go left once and keep going right. 




// current starts from our root node and run below code jb tk current NULL nhi hota hai 
// current hi travel karega tree me inorder wise and print karega nodes ko 

// some algo. not complete -: 

// find the Predecessor of the current only if left of the current is exits 
// otherwise visit (print) root node and go right becoz left of the current is not exits 
// after finding Predecessor we check 1-: kya Predecessor ka right NULL hai if yes then hm ek ferzi 
// connection banayenge ( ferzi connection se hm us node per vapis se ja sakte hai ) aur 
// agar Predecessor ka right current hai to use break karo (unlink) karo and Predecessor ke right 
// ko current per le jayenge aur 2-: current ko hm apne left per le jayenge. 


// ek bar link karte hai ek unlink karte hai 



// ********* Morris Traversal of BST -: *********
// *********    Algorithm -:    *********

// start current from the root of the tree. 
// case-1-: if left of the current exits then find Predecessor and either link or unlink 
// if right of the Predecessor is NULL then link karo agar Predecessor ka right pahle se link 
// hai to unlink karo and visit (print) karo and go right  
// case-2-: if left of the current is not exits or NULL then visit or print your current and 
// current ko current ke right per le jao.


// Code -: Leetcode-94-: Binary tree inorder traversal using morris traversal. Not binary search tree. 


#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }

};


class Solution { // VERY IMP -> inorder traversal iterative algo. is same as -> ** Morris Traversal ** algo. but ans is diff. 
public:
    void inorderTraversal(Node* root) { // void -> return type means we print our ans/inorder trav'val/morris trav'val 
        vector<int>ans;
        Node* curr=root;

        while(curr!=NULL){ 
            // 2 case, case:1- curr->left!=NULL (find pred,link,unlink), case:2- currr->left==NULL
            if(curr->left!=NULL){ // find the inorder predecessor and do some work. 
            // how we find pred-> 1:go left once, 2:keep going right 
            
                // finding inorder predecessor -:
                Node* pred=curr;
                pred=curr->left; // 1- go left once 
                while(pred->right!=NULL && pred->right!=curr){ // 2- keep going right 
                    pred=pred->right; 
                }

                if(pred->right==NULL){ // Link the connection / ferzi connection 
                    pred->right=curr;
                    curr=curr->left;
                }else{  // pred->right==curr  means phle se farzi conn. h  // Unlink the connection 
                    pred->right=NULL;
                    ans.push_back(curr->val); // visit/print
                    curr=curr->right; // go right
                }

            }

            else{ // currr->left==NULL 1->visit/print/store in vector, 2-> go right
                ans.push_back(curr->val); // visit/print 
                curr=curr->right; // go right always
            }
        }

        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }

};


int main(){

    // Manual trees
    Node* a=new Node(10); // this is a root node (a) 
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    Node* e=new Node(50);
    Node* f=new Node(60);
    Node* g=new Node(70);

    // connections
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    Solution sol;
    sol.inorderTraversal(a); 

} // 40 20 50 10 60 30 70  



// Morris Traversal Algorithm Summary -: 

// Objective:
// The Morris Traversal is an efficient method to perform an inorder traversal of a 
// binary tree with O(1) space complexity (excluding the recursion stack) and O(n) time complexity.

// Concept:
// Morris traversal uses a temporary link or "threaded connection" to avoid using recursion or an explicit stack.
// Inorder predecessor is crucial for Morris Traversal.
// The predecessor of a node is the rightmost node in its left subtree.

// Steps:
// Start with the root node as the current node.

// There are two main cases for each node:
// Case 1: curr->left exists
// Find the inorder predecessor of the current node.
// Go left once, and keep moving right until:
// pred->right == NULL ➡ Link the predecessor's right to curr. Move curr to its left child.
// pred->right == curr ➡ Unlink the temporary connection. Visit curr and move to the right child.

// Case 2: curr->left does not exist
// Visit curr (print/store its value).
// Move curr to its right child.
// Repeat until curr becomes NULL.
