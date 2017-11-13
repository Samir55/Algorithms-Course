#include <iostream>
#include <vector>
#include<algorithm>

#define MAX 1000000000
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

void bst_insert(TreeNode *&root, int element, TreeNode* parent = nullptr) {
    if (root == nullptr) {
        root = new TreeNode;
        root->data = element;
        root->right = nullptr;
        root->left = nullptr;
        root->parent = (parent != nullptr) ? parent : nullptr;
    } else if (element > root->data) {
        bst_insert(root->right, element, root);
    } else {
        bst_insert(root->left, element, root);
    }
}

// ToDo @Samir55
void bst_insert_it(TreeNode *&root, int element) {
    if (root == nullptr) {
        root = new TreeNode;
        root->data = element;
        root->right = nullptr;
        root->left = nullptr;
    } else if (element > root->data) {
        bst_insert(root->right, element);
    } else {
        bst_insert(root->left, element);
    }
}

int bst_find_max(TreeNode *root) {
    if (root == nullptr) return -1;
    return max(bst_find_max(root->right), root->data);
}

int bst_find_max_it(TreeNode *root) {
    int ret = -1;
    while (root != nullptr) {
        ret = root->data;
        root = root->right;
    }
    return ret;
}

int bst_find_min(TreeNode *root) {
    if (root == nullptr) return MAX;
    return min(bst_find_min(root->left), root->data);
}

int bst_find_min_it(TreeNode *root) {
    int ret = MAX;
    while (root != nullptr) {
        ret = root->data;
        root = root->left;
    }
    return ret;
}

void bst_inorder_traverse(TreeNode *root) {
    if (root == nullptr) return;
    bst_inorder_traverse(root->left);
    cout << root->data << endl;
    bst_inorder_traverse(root->right);
}

void bst_preorder_traverse(TreeNode *root) {
    if (root == nullptr) return;
    cout << root->data << endl;
    bst_preorder_traverse(root->left);
    bst_preorder_traverse(root->right);
}

void bst_postorder_traverse(TreeNode *root) {
    if (root == nullptr) return;
    bst_postorder_traverse(root->left);
    bst_postorder_traverse(root->right);
    cout << root->data << endl;
}

void bst_destroy(TreeNode *&root) {
    if (root != nullptr) {
        bst_destroy(root->left);
        bst_destroy(root->right);
        delete root;
        root = nullptr;
    }
}

TreeNode *bst_build(vector<int> arr, bool reverse_read = false) {
    TreeNode *root = nullptr;
    if (!reverse_read) {
        for (auto el : arr) {
            int s = el;
            bst_insert(root, s);
        }
    } else {
        for (int i = int(arr.size()) - 1; i >= 0; i--) {
            int s = arr[i];
            bst_insert(root, s);
        }
    }
    return root;
}

TreeNode *bst_search(TreeNode *root, int data) {
    if (root == nullptr || root->data == data) return root;

    if ((root->data) < data)
        return bst_search(root->right, data);
    else if ((root->data) >= data)
        return bst_search(root->left, data);
}

TreeNode *bst_search_it(TreeNode *root, int data) {
    while (root != nullptr && root->data != data) {
        if (data > root->data) root = root->right;
        else root = root->left;
    }
    return  root;
}

int bst_find_successor(TreeNode* root, int data) {
    TreeNode* node = bst_search(root, data);
    if (node == nullptr) return -1;
    if (node->right != nullptr) return bst_find_min(node);
    TreeNode* parent = node->parent;
    while (parent != nullptr && node != parent->left /* Cause this is the answer*/) {
        node = parent;
        parent = parent->parent;
    }
    return ( (parent != nullptr) ? (parent->data) : -1); // Either nullptr in case of not found or the real value;
}

int bst_find_predecessor(TreeNode* root, int data) {
    TreeNode* node = bst_search(root, data);
    if (node == nullptr) return -1;
    if (node->left != nullptr) return bst_find_max(node);
    TreeNode* parent = node->parent;
    while (parent != nullptr && node != parent->right /* Cause this is the answer*/) {
        node = parent;
        parent = parent->parent;
    }
    return ( (parent != nullptr) ? (parent->data) : -1); // Either nullptr in case of not found or the real value;
}

int main() {
    vector<int> nums;
    int x;
    cin >> x;
    while (x != -1) {
        nums.push_back(x);
        cin >> x;
    }
    TreeNode *root2 = nullptr;
    TreeNode *root3 = nullptr;
    //1 4 2 6 8 9 11 10 -1
    root2 = bst_build(nums);
    root3 = bst_build(nums, true);
    cout << "the correct order" << endl;
    bst_preorder_traverse(root2);
    cout << endl;
    cout << "the reverse order" << endl;
    bst_preorder_traverse(root3);
    cout << endl;
    return 0;
}
