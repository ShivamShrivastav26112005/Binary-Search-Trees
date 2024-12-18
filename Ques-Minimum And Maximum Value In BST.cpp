// // Revision Basics -: 

// #include <iostream>
// using namespace std;

// // Node structure or Node Class -: 
// struct Node {
//     int val;
//     Node* left;
//     Node* right;
//     Node(int val){
//         this->val=val;
//         this->left=NULL;
//         this->right=NULL;
//     }
// };

// // Insert a node into the BST
// Node* insert(Node* root, int value) {
//     if (root == nullptr) return new Node(value);

//     if (value < root->val)
//         root->left = insert(root->left, value);
//     else if (value > root->val)
//         root->right = insert(root->right, value);

//     return root;
// }

// // Search for a value in the BST
// bool search(Node* root, int value) {
//     if (root == nullptr) return false;
//     if (root->val == value) return true;
//     if (value < root->val) return search(root->left, value);
//     return search(root->right, value);
// }

// // Inorder traversal (sorted output)
// void inorder(Node* root) {
//     if (root == nullptr) return;
//     inorder(root->left);
//     cout << root->val << " ";
//     inorder(root->right);
// }

// // Delete a node in the BST
// Node* findMin(Node* root) {
//     while (root->left != nullptr) root = root->left;
//     return root;
// }

// Node* deleteNode(Node* root, int value) {
//     if (root == nullptr) return root;

//     if (value < root->val)
//         root->left = deleteNode(root->left, value);
//     else if (value > root->val)
//         root->right = deleteNode(root->right, value);
//     else {
//         if (root->left == nullptr)
//             return root->right;
//         else if (root->right == nullptr)
//             return root->left;

//         Node* minNode = findMin(root->right);
//         root->val = minNode->val;
//         root->right = deleteNode(root->right, minNode->val);
//     }

//     return root;
// }

// // Main Function
// int main() {
//     Node* root = nullptr;
//     root = insert(root, 50);
//     insert(root, 30);
//     insert(root, 70);
//     insert(root, 20);
//     insert(root, 40);
//     insert(root, 60);
//     insert(root, 80);

//     cout << "Inorder Traversal: ";
//     inorder(root);
//     cout << endl;

//     cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;

//     root = deleteNode(root, 30);
//     cout << "After Deletion (30): ";
//     inorder(root);
//     cout << endl;

//     return 0;
// }





// // Q-: Find the nodes with minimum and maximum value in a BST. 

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

// void display(Node* root){
//     if(root==NULL) return ;
//     cout<<root->val<<" ";
//     display(root->left);
//     display(root->right);
// }

// void mini(Node* root){
//     if(root==NULL) return ;
//     if(root->left==NULL && root->right==NULL){
//         cout<<root->val;
//     }
//     mini(root->left); 
// }

// void maxi(Node* root){
//     if(root==NULL) return ;
//     if(root->left==NULL && root->right==NULL){
//         cout<<root->val;
//     }
//     maxi(root->right); 
// }

// int main(){
//     Node* a=new Node(70);
//     Node* b=new Node(60); 
//     Node* c=new Node(80);
//     Node* d=new Node(50);
//     Node* e=new Node(65);
//     Node* f=new Node(75);
//     Node* g=new Node(85);

//     a->left=b;
//     a->right=c;
//     b->left=d;
//     b->right=e;
//     c->left=f;
//     c->right=g;

//     display(a); 
//     cout<<endl;
//     mini(a); // recursion calling -> than makes stack -> it takes TC=SC=O(n)
//     cout<<endl;
//     maxi(a); 

// }

// // 70 60 50 65 80 75 85 
// // 50
// // 85

// // recursion calling -> than makes stack -> it takes TC=SC=O(n)




// Q-: Given a BST, count subtrees in it whose nodes lie within a given range. 
// you have to given root of the BST, low, high. 



#include<iostream>
using namespace std;

// Make a BST node class -: 
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

void nthlevel(Node* root, int current, int level){
    if(root==NULL) return ;
    if(current==level){
        cout<<root->val<<" ";
    }
    nthlevel(root->left, current+1, level);
    nthlevel(root->right, current+1, level);
}

int levels(Node* root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left), levels(root->right));
}

// display using level order traversals -: 
void display(Node* root){
    if(root==NULL) return ;
    int level=levels(root);
    for(int i=1; i<=level; i++){
        nthlevel(root,1,i);
    }
}

bool countsubtrees(Node* root, int low, int high, int& count){
    if(root==NULL) return true;
    
    bool left=countsubtrees(root->left, low, high, count);
    bool right=countsubtrees(root->right, low, high, count);

    if(left && right && (root->val>=low && root->val<=high)){
        count++;
        return true;
    }

    return false;

}

int main(){
    Node* a=new Node(40);
    Node* b=new Node(25);
    Node* c=new Node(50);
    Node* d=new Node(20);
    Node* e=new Node(30);
    Node* f=new Node(45);
    Node* g=new Node(60);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    // cout<<levels(a)<<endl;

    // display(a); 

    int low=15;
    int high=47;
    int count=0;
    countsubtrees(a, low, high, count); // 4 subtrees -> ans. 
    cout<<count;
}



