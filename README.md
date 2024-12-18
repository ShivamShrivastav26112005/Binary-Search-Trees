Binary Search Tree (BST) -: 

A Binary Search Tree (BST) is a special type of binary tree where:
Each node has at most two children (left and right).
The left child contains only nodes with values less than the parent.
The right child contains only nodes with values greater than the parent.

Key Properties of BST -: 
The in-order traversal of a BST always gives a sorted sequence.
Efficient for searching, insertion, and deletion with an average time complexity of O(log N).

Operations in BST -: 

1. Insertion in BST -:
   
Steps:

Start at the root node.
Compare the value to be inserted with the current node:
If it's smaller, move to the left subtree.
If it's larger, move to the right subtree.
Repeat until you find an empty spot and insert the value.


Algorithm (Pseudo Code) -: 

Node* insert(Node* root, int value) {
    if (root == nullptr) 
        return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}


2. Searching in BST -:
   
Steps:

Start at the root node.
Compare the target value with the current node:
If it's equal, the value is found.
If it's smaller, search the left subtree.
If it's larger, search the right subtree.
If you reach a nullptr, the value is not in the tree.

Algorithm (Pseudo Code) -: 

bool search(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value < root->data) 
        return search(root->left, value);
    return search(root->right, value);
}


3. Deletion in BST -:
   
Steps:

Locate the node to be deleted.
Handle three cases:
No child: Simply remove the node.
One child: Replace the node with its child.
Two children: Find the in-order successor (smallest value in the right subtree), 
replace the node's value, and delete the successor.

Algorithm (Pseudo Code) -: 

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        Node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

Node* findMin(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}

Traversal in BST -: 

1. In-order Traversal (Left, Root, Right)
   
Produces a sorted order of elements. Algorithm:

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

3. Pre-order Traversal (Root, Left, Right) -:
   
Useful for creating a copy of the tree.

5. Post-order Traversal (Left, Right, Root)
Useful for deleting the tree.

7. Morris Traversal (In-order Without Recursion or Stack)
Uses a threaded binary tree for traversal.

Algorithm:

void morrisTraversal(Node* root) {
    Node* current = root;
    while (current != nullptr) {
        if (current->left == nullptr) {
            cout << current->data << " ";
            current = current->right;
        } else {
            Node* pre = current->left;
            while (pre->right != nullptr && pre->right != current)
                pre = pre->right;
            if (pre->right == nullptr) {
                pre->right = current;
                current = current->left;
            } else {
                pre->right = nullptr;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}


Applications of BST -: 

Databases: For indexing and fast searching.
File Systems: To store hierarchical data.
Auto-Complete: Searching prefixes in dictionaries.
Network Routing: Fast lookups for routing tables.

Real-World Examples -:

Phonebook Directory: Search for names or numbers efficiently.
Search Engines: Organizing search results or indexing data.
Version Control Systems: Managing versions and searching changes.
Games: Decision-making trees like in chess.

Advantages of BST -: 
Faster operations (insertion, deletion, search) compared to linear 
structures like arrays and linked lists.
Can be balanced for optimal performance using AVL trees or Red-Black trees...
