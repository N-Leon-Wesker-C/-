#include <iostream>
#include <stack>
using namespace std;

// 二叉树节点结构
struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 按先序遍历建立二叉树
TreeNode* buildTreePreOrder(int preOrder[], int size) {
	if (size == 0) return nullptr;
	
	TreeNode* root = new TreeNode(preOrder[0]);
	stack<TreeNode*> nodeStack;
	nodeStack.push(root);
	
	for (int i = 1; i < size; ++i) {
		TreeNode* node = new TreeNode(preOrder[i]);
		
		if (preOrder[i] < nodeStack.top()->data) {
			nodeStack.top()->left = node;  // 设置左子树
		} else {
			TreeNode* temp = nullptr;
			while (!nodeStack.empty() && preOrder[i] > nodeStack.top()->data) {
				temp = nodeStack.top();
				nodeStack.pop();
			}
			temp->right = node;  // 设置右子树
		}
		nodeStack.push(node);
	}
	return root;
}

// 先序遍历（非递归）
void preOrderTraversal(TreeNode* root) {
	if (!root) return;
	
	stack<TreeNode*> s;
	s.push(root);
	
	while (!s.empty()) {
		TreeNode* node = s.top();
		s.pop();
		
		cout << node->data << " ";
		
		if (node->right) s.push(node->right);
		if (node->left) s.push(node->left);
	}
}

// 先序线索化二叉树
void threadPreOrder(TreeNode* root, TreeNode*& pre) {
	if (!root) return;
	
	if (!root->left) {
		root->left = pre;
	}
	if (pre && !pre->right) {
		pre->right = root;
	}
	
	pre = root;
	threadPreOrder(root->left, pre);
	threadPreOrder(root->right, pre);
}

// 遍历先序线索树
void preOrderThreadTraversal(TreeNode* root) {
	TreeNode* current = root;
	while (current) {
		cout << current->data << " ";
		
		if (current->left) {
			current = current->left;
		} else {
			current = current->right;
		}
	}
}

int main() {
	int preOrder[] = {10, 5, 1, 7, 15, 12, 18};
	int size = sizeof(preOrder) / sizeof(preOrder[0]);
	
	TreeNode* root = buildTreePreOrder(preOrder, size);
	
	cout << "Pre-order traversal (non-recursive): ";
	preOrderTraversal(root);
	cout << endl;
	
	TreeNode* pre = nullptr;
	threadPreOrder(root, pre);
	
	cout << "Pre-order thread traversal: ";
	preOrderThreadTraversal(root);
	cout << endl;
	
	return 0;
}

