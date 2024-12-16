// hold -: Deletion of a Node -: but maintaing the property of binary search tree (BST). 




// IMP topic -: 
// Predecessor and Successor for a given key in BST or BT. 

// you have to given tree either BT or BST and given key/node/value.  
// you have to find preorder, inorder, postorder Predecessor and Successor.

// Predecessor -> means just left ele. / just before.  
// Successor -> means just right ele. / just after. 



// ex-: tree's nodes given -: 50,30,20,40,70,60,80
// find the Predecessor of 70 -> 40 
// find the Successor of 70 -> 60 




// Q-1-: how to find inorder Predecessor. 
// steps -:
// 1-: go left once 
// 2-: keep going right 

// Pseudocode for inorder Predecessor-: 
// if(root->left==NULL) return NULL;
// Node* pred=root->left;
// while(pred->right!=NULL) pred=red->right;
// return pred; 

// Q-2-: how to find inorder Successor. 
// steps -:
// 1-: go right once 
// 2-: keep going left 






// ***********  Deletion -: ***********

// 3 cases -: 
// (a)-: The node has 0 child. or it is a leaf node. 
// (b)-: The node has 1 child. or it has only one child node (either left or right)
// (c)-: The node has 2 child. or it has 2 child nodes -> IMP -: 
// you have to given "key" which they want to "delete". 


// Leetcode-450 -: Delete Node in a BST. 



// // (a)-: The node has 0 child. or it is a leaf node. 
// // code for deleting leaf nodes only. key node is given -> jise hme delete karna hai 

// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) { // main fun. 
//         if(root->val==key) return NULL; // left node
//         else if(root->val > key){ // go left
//             root->left = deleteNode(root->left,key);
//         }
//         else{ // (root->val < key) ->  go right
//             root->right = deleteNode(root->right,key);
//         }
//         return root;
//     }
// };



// // (b)-: The node has 1 child. or it has only one child node (either left or right)
// // code for deleting 1 nodes only. key node is given -> jise hme delete karna hai 


// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {

//     // case 1 : no child / leaf node / node has 0 child -> delete 
//         if(root->val == key){
//             // case-1 No child or leaf node -: 
//             if(root->left==NULL && root->right==NULL) return NULL;

//             // case 2 : 1 child node / root has only 1 child -> delete 
//             if(root->left==NULL || root->right==NULL){
//                 if(root->left!=NULL) return root->left;
//                 else return root->right;
//             }
//         }

//         else if(root->val > key){ // go left
//                 root->left = deleteNode(root->left,key);
//             }
//             else{ // (root->val < key) ->  go right
//                 root->right = deleteNode(root->right,key);
//             }
//             return root;
//         }
//     };





// (c)-: The node has 2 child. or it has 2 child nodes -> IMP -: 
// code for deleting 2 nodes only. key node is given -> jise hme delete karna hai 

// hint -: replace the node with its inorder Predecessor or Successor

// jis key/node ko delete karna hai uska inorder Predecessor or Successor 
// me se koi ek nikalo aur usko delete karo. 


// ************ Read It Again *************
// Algorithm (Deleting a Node in a BST) -: 

// Base Case -:
// If the root is NULL, return NULL.

// Find the Node -:
// If key < root->val, search in the left subtree.
// If key > root->val, search in the right subtree.
// Delete the Node:

// Case 1: No Children -: 
// If the node is a leaf, return NULL.
// Case 2: One Child
// Return the non-NULL child (left or right).
// Case 3: Two Children
// Replace the node's value with its inorder predecessor (IOP) or inorder successor (IOS) and recursively delete the IOP or IOS node.  

// Key Functions -: 
// Inorder Predecessor (IOP) -:
// The largest node in the left subtree.
// Go left once.
// Then go right as far as possible.
  
// Inorder Successor (IOS) -:
// The smallest node in the right subtree.
// Go right once.
// Then go left as far as possible. 

// Function Roles -: 
// iop(TreeNode* root)
// Finds the largest value smaller than root->val (left subtree’s max).
// ios(TreeNode* root)
// Finds the smallest value larger than root->val (right subtree’s min).
// deleteNode(TreeNode* root, int key)
// Deletes the node with key from the BST by considering the three cases mentioned above.


class Solution {
public:
        // finding inorder predecessor -> always lies left of the root node
        TreeNode* iop(TreeNode* root){
            TreeNode* pred = root->left; // case 1: go left once 
            while(pred->right!=NULL){ //  case 2: keep going right
                pred=pred->right;  
            }
            return pred;
        }

        // finding inorder successor -> always lies right of the root node 
        TreeNode* ios(TreeNode* root){
            TreeNode* succ = root->right; // go right once 
            while(succ->left!=NULL){ // keep going left if possible 
                succ=succ->left;
            }
            return succ;
        }

        TreeNode* deleteNode(TreeNode* root, int key) { // main fun. 
        if(root==NULL) return NULL;

        // case 1 : no child / leaf node / node has 0 child -> delete 
        if(root->val == key){
            if(root->left==NULL && root->right==NULL)
            return NULL;

        // case 2 : 1 child node / root has only 1 child -> delete 
        if(root->left==NULL || root->right==NULL){
            if(root->left!=NULL) return root->left;
            else return root->right;
        }

        // case 3 : 2 child nodes / root has 2 child (left and right) -> delete 
        if(root->left!=NULL && root->right!=NULL){
            // replace the root with its inorder predecessor or inorder successor
            // after replacing delete the predecessor or predecessor node/key/val
            
            // inorder predecessor ka hmesa 1 child hoga ya vh leaf node hoga, uska 2 child kabhi nhi hoga 
            // same as inorder Successor also have either 1 child or it is leaf node, never have 2 childs 


        //     TreeNode* pred = iop(root);
        //     root->val = pred->val; // change root'value 
        //     // delete permanetely this predecessor -: 
        //     root->left = deleteNode(root->left,pred->val); // pred->val means becoz now we delete our pred->val(which is attached to root value)
        //     }
        // }


        // OR -: 


        TreeNode* succ = ios(root);
            root->val = succ->val; // change root'value 
            // delete permanetely this predecessor -: 
            root->right = deleteNode(root->right,succ->val); // pred->val means becoz now we delete our pred->val(which is attached to root value)
            }
        }

            else if(root->val > key){ // go left
                root->left = deleteNode(root->left,key);
            }
            else{ // (root->val < key) ->  go right
                root->right = deleteNode(root->right,key);
            }
            return root;
        }
};




