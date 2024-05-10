#include <iostream>
using namespace std;

struct bst_node {
	string userId;
	string password;
	int userNumber;
	bst_node* left;
	bst_node* right;
};
bst_node* createNode(string userId, string password,int userNumber) {
	bst_node* root = new bst_node();
	root->userId = userId;
	root->password = password;
	root->userNumber = userNumber;
	root->left = NULL;
	root->right = NULL;
	return root;
}
bst_node* insertUser(bst_node* root, string userId, string password, int userNumber) {
	if (root == NULL) {
		bst_node* root = createNode(userId, password, userNumber);
		return root;
	}
	else if (root->userNumber > userNumber) {
		root->left = insertUser(root->left, userId, password, userNumber);
		return root;
	}
	else {
		root->right = insertUser(root->right, userId, password, userNumber);
		return root;
	}
}

void preorderTraversal(bst_node* root) {
	if (root == NULL) {
		return;
	}
	else {
		cout << "userId : " << root->userId << endl
			<< "password : " << root->password << endl
			<< "userNumber : " << root->userNumber << endl;
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void inorderTraversal(bst_node* root) {
	if (root == NULL)
		return;
	else {
		inorderTraversal(root->left);
		cout << "userId : " << root->userId << endl
			<< "password : " << root->password << endl
			<< "userNumber : " << root->userNumber << endl;
		inorderTraversal(root->right);
	}
}

void postorderTraversal(bst_node* root) {
	if (root == NULL)
		return;
	else {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		cout << "userId : " << root->userId << endl
			<< "password : " << root->password << endl
			<< "userNumber : " << root->userNumber << endl;
	}
}

bst_node* findMinimumPrice(bst_node* root) {
	bst_node* temp = root;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}
bst_node* findMaximumPrice(bst_node* root) {
	bst_node* temp = root;
	while (root->right != NULL)
		temp = temp->right;
	return root;
}
bst_node* searchUser(bst_node* root, int userNumber) {
	if (root == NULL) {
		cout << "user doesn't exist...\n";
		return root;
	}
	else if (root->userNumber == userNumber) {
		cout << "Userfound...\nuserId : " << root->userId << endl
			<< "userPassword : " << root->password << endl
			<< "userNumber : " << root->userNumber << endl;
	}
	else if (root->userNumber > userNumber) {
		searchUser(root->left, userNumber);

	}
	else {
		searchUser(root->right, userNumber);
	}
}
bst_node* deleteNode(bst_node* root, int key) {
	if (root == NULL)
		return root;

	if (key < root->userNumber)
		root->left = deleteNode(root->left, key);
	else if (key > root->userNumber)
		root->right = deleteNode(root->right, key);
	else {
		// Case 1: bst_node with only one child or no child
		if (root->left == NULL) {
			bst_node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			bst_node* temp = root->left;
			delete root;
			return temp;
		}

		// Case 2: bst_node with two children
		bst_node* temp = findMinimumPrice(root->right);
		root->userNumber = temp->userNumber;
		root->right = deleteNode(root->right, temp->userNumber);
	}
	return root;
}

int main() {
	cout << "==================== Insert Users ====================\n";
	bst_node*root = createNode("21128", "dbuaksefi99", 10);
	insertUser(root, "32872", "sjdhsd83e8", 64);
	insertUser(root, "23998", "3ennsyd8y", 22);
	insertUser(root, "33983", "rdjs3343", 83);
	insertUser(root, "30293", "fhdru383",3);
	insertUser(root, "923874", "cnsori39843", 9);
	cout << "==================== Preorder Traversal ====================\n";
	preorderTraversal(root);
	cout << "==================== Search Users ====================\n";
	searchUser(root, 22);
	searchUser(root, 3);
	searchUser(root, 2112);
	cout << "==================== Delete Users ====================\n";
	deleteNode(root, 83);
	preorderTraversal(root);
	return 0;
}