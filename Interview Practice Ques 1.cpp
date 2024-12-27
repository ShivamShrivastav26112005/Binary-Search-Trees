1. Search in a Binary Search Tree -: 
  
Problem -: Search for a given value in a BST. If the value exists, return the node; otherwise, return nullptr.

TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}


// Algo -: 
// Use the properties of BST: left child < root < right child.
// If the current node's value is equal to the target, return it.
// Otherwise, move to the left or right subtree depending on the target value.



  
2. Insert into a Binary Search Tree -: 
  
Problem -: Insert a given value into the BST while maintaining the BST property.

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}


// Key Idea:
// Recursively find the correct position in the BST.
// Create a new node and insert it at the correct position.



  
3. Delete a Node in a Binary Search Tree -: 
  
Problem -: Delete a node from the BST while maintaining the BST property.

TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;

    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == nullptr) return root->right;
        else if (root->right == nullptr) return root->left;

        // Node with two children
        TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}


// Key Idea:
// If the node has no children, remove it directly.
// If it has one child, replace the node with its child.
// If it has two children, replace the node's value with the minimum value from its right subtree, then delete that node.



4. Validate Binary Search Tree -: 
  
Problem -: Check whether a given binary tree is a valid BST.


bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (root == nullptr) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}


// Key Idea:
// Use the properties of BST: all left nodes must be < root, and all right nodes must be > root.
// Pass the valid range (minVal, maxVal) for each recursive call.


5. Lowest Common Ancestor in a Binary Search Tree -:
  
Problem -: Find the lowest common ancestor (LCA) of two given nodes in a BST.

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    return root;
}


// Key Idea:
// If both nodes are smaller than the root, move to the left subtree.
// If both nodes are larger, move to the right subtree.
// Otherwise, the current node is the LCA.

