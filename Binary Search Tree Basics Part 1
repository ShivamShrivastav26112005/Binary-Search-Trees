// Binary Search Trees (BST) -: 
// Non-linear data structure -: 



// this is very interesting topic like linked list, binary trees or nodes wale data structure 



// Binary search tree -: extension of the binary trees. 
// it is a type of binary tree, made up of binary search + binary trees 


// Node class is also same of binary search tree as binary tree 

// Node -: Node ki value hoti hai 
// left Node and right Node hota hai. 




// Today Checklist -: 
// why binary search tree?
// what is binary search tree?
// advantages and disadvantages
// applications 
// insertion 
// traversal -> inorder, preorder, postorder
// searching 
// Problems on binary search tree (BST).



// what and why -: Binary search Tree (BST) -: 

// the value of the left subtree of the binary search tree is less and 
// the value of the right subtree of the binary search tree is high from the root'value. 


// root node ke value se pure left subtree ke values small hone chahiye 
// and root node ke value se pure right subtree ke values large hone chahiye  
// this is applicable for all the nodes or every nodes present in the tree. 



// -> every node to the left of a node should be smaller and 
// every node to the right should be greater. this is applies for all nodes. 


// every BST(binary search tree) is a BT(binary tree) also but every BT is not a BST.


// as you already know that binary search is applicable for only sorted array 
// similarly, BST is also sorted tree by using inorder traversals. 



// // Q-> Can a BST contain duplicate elements?
// ans -> No, becoz it follows this -> LST < root->val <RST 

// but, some books writes this -> LST <= root->val <RST  
// then ans -> Yes. 

// where, LST-> Left SubTree, RST-> Right SubTree

// overall, generally, NO. 



// Advantages -: 
// 1-: efficient searching 
// 2-: efficient insertion and deletion 
// 3-: usage in implementation of other data structures like 
// sets, maps(TreeMaps), priority queues(heaps) etc. 

// // like linkedlist se stack implement hua and so on. 


// DisAdvantages -: 
// 1-: Lack of support for range queries (like arrays, queues or linear data structures is more better). 
// 2-: Not that efficient in case of Unbalanced Trees or Unbalanced BST. 


// Appliactions -: uses -: 
// 1-: PhoneBook
// 2-: Dictionary
// 3-: Stock Market Analysis



// // Q-> Search in a BST. (Leetcode-700). 


// #include<iostream>
// using namespace std;

// class Node{
// public:
//     int val;
//     Node* left;
//     Node* right;

//     Node(int val){
//         this->val=val;
//         this->left=NULL;
//         this->right=NULL;
//     }

// };


// class Solution {
// public:
//     bool searchBST(Node* root, int val) {
//         if(root==NULL) return false;
//         if(root->val==val) return true;
//         // Check in both left and right subtrees -: 
//         return searchBST(root->left, val) || searchBST(root->right, val);
//     }
// };


// int main(){
//     Node* a=new Node(10);
//     Node* b=new Node(20);
//     Node* c=new Node(30);
//     Node* d=new Node(40);
//     Node* e=new Node(50);
//     Node* f=new Node(60);
//     Node* g=new Node(70);

//     a->left=b;
//     a->right=c;
//     b->left=d;
//     b->right=e;
//     c->left=f;
//     c->right=g;

//     Solution sol;
//     if(sol.searchBST(a,60)){
//         cout<<"Yes"<<endl;
//     }else{
//         cout<<"No"<<endl;
//     }
   
// }

// // T.C. 
// //     best case(balanced tree) = O(logn)~O(height)~O(h) // maximum height tk travel hoga  
// //     worst case = O(n)~O(height)~O(h)
// //     avg case = O(n)~O(height)~O(h)
        
        
// //     S.C. of recursively preorder, inorder and postorder -> O(height)~O(h)
        
// // S.C.
// //     Same as T.C. = O(height)~O(h)





// Q-: Insert into a binary search tree (BST). (Leetcode-701). 


// class Solution {
// public:
//     void insert(Node* root, int val){
//         if(root==NULL) root = new Node(val);

//         else if(root->val > val){ // go left 
//             if(root->left==NULL){ // attached directly in left 
//                 root->left = new Node(val);
//             }
//             else insert(root->left,val);
//         }

//         else{ // if(root->val<val) go right 
//             if(root->right==NULL){ // attached directly in right
//                 root->right = new Node(val);;
//             }
//             else insert(root->right,val);
//         }
//     }

//     Node* insertIntoBST(Node* root, int val) {
//         insert(root,val); // helper function ko call kiya and it insert our value/node
//         if(root==NULL) root = new Node(val);
//         return root;
//     }
// };





// Traversals in BST -: same as BT (binary tree).
// by using DFS -> preorder, inorder, postorder 


// very-very imp. concepts -: many ques. of BST is solved by using this concept. 
// inorder of BST is sorted. 


// // PreOrder display / traversals of BT(binary tree) or BST(binary search tree) -: order -> root, left, right 
// void preorder(Node* root){ // 10 20 40 50 30 60 70 
//     if(root==NULL) return; // base case
//     cout<<root->val<<" ";  // kaam / work 
//     preorder(root->left);   // call 1 -> left call 
//     preorder(root->right);  // call 2 -> right call 
// }






// // Q-: 235. Lowest Common Ancestor of a Binary Search Tree

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root->val == p->val || root->val == q->val) return root;
//         else if(root->val > p->val && root->val < q->val) return root;
//         else if(root->val < p->val && root->val > q->val) return root;
//         else if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q); // go left 
//         else return lowestCommonAncestor(root->right, p, q); // go right 
//     }
// };


// OR -:


// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q); // go left 
//         else if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);  // go right 
//         else return root;
//     }
// };





// Q-: Validate BST. (Leetcode-98)
// you are given a binary tree(root).
// you have to tell if the binary tree is a binary search tree or not. 


// algo. -> inorder traversals -: 

// "inorder" traversals of the binary search tree (BST) is always "sorted". 


// if inorder traversal of the given binary tree is not sorted then those tree is not a BST.

// TC of inorder traversal = O(n).


// class Solution { // inorder of BST is always sorted if not sorted then those tree(BT) is not a BST 
// public:

// // inorder traversals
//     void inorder(TreeNode* root,vector<int>& ans){ // inorder traversal-> left, root, right
//         if(root==NULL) return ; // base case 
//         inorder(root->left,ans); // left
//         ans.push_back(root->val); // root
//         inorder(root->right,ans); // right
//     }

//     bool isValidBST(TreeNode* root) {
//         vector<int>ans; // inorder values store in the vector ans 
//         inorder(root,ans);

//         // traverse in the ans vector where we store our inorder traversal values to check
//         // if 1st val is smaller than next/2nd val or not, if not then it is not a BST if yes then it is a BST
//         for(int i=1; i<ans.size(); i++){
//             if(ans[i]<=ans[i-1]) // condition for false case -> if our 1st val is greater than 2nd val
//             // than it is not a BST becoz inorder of BST is always sorted 
//             return false;
//         }
//         return true;
//     }
// };






// Q-: (108). Convert Sorted Array to Binary Search Tree. 


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


class Solution { // use of binary search -> mid, low, high
public:

    // Preorder traversal of BST -:
    void preorder(Node* root){ 
        if(root==NULL) return; // base case
        cout<<root->val<<" ";  // kaam / work 
        preorder(root->left);   // call 1 -> left call 
        preorder(root->right);  // call 2 -> right call 
    }

    Node* helper(vector<int>& nums, int low, int high){
            if(low>high) return NULL; // base case
            // Binary search 
            int mid=low+(high-low)/2;
            Node* root = new Node(nums[mid]); // new node which is root node 
            // call left and right subtree 
            root->left = helper(nums,low,mid-1); // magic -> recursion 
            root->right = helper(nums,mid+1,high); // magic -> recursion 
            return root;
    }

    Node* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,n-1); // we return helper fun becoz its returntype is TreeNode(which return root node of BST)
    }

};

int main(){
    vector<int> nums = {10, 20, 30, 40, 50, 60, 70};

    Solution sol;
    cout<<"Before converted : ";
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    // we have to given return type Node* 
    Node* root=sol.sortedArrayToBST(nums);

    cout<<"Afer converted, Preorder traversal of BST : ";
    sol.preorder(root);
        
}

// Before converted : 10 20 30 40 50 60 70 
// Afer converted, Preorder traversal of BST : 40 20 10 30 60 50 70 

// left nodes are small and right nodes are large of BST. 
