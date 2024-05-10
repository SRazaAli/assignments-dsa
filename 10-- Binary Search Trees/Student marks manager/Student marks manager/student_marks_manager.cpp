#include <iostream>
using namespace std;

struct bst_node {
	float marks;
	bst_node* left;
	bst_node* right;
};
bst_node* createNode(float marks) {
	bst_node* root = new bst_node();
	root->marks = marks;
	root->left = NULL;
	root->right = NULL;
	return root;
}
bst_node* insertMarks(bst_node* root,float marks) {
	if (root == NULL) {
		bst_node* root = createNode( marks);
		return root;
	}
	else if (root->marks > marks) {
		root->left = insertMarks(root->left, marks);
		return root;
	}
	else {
		root->right = insertMarks(root->right, marks);
		return root;
	}
}

void preorderTraversal(bst_node* root) {
	if (root == NULL) {
		return;
	}
	else {
			cout << "marks : " << root->marks << endl;
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void inorderTraversal(bst_node* root) {
	if (root == NULL)
		return;
	else {
		inorderTraversal(root->left);
			cout << "marks : " << root->marks << endl;
		inorderTraversal(root->right);
	}
}

void postorderTraversal(bst_node* root) {
	if (root == NULL)
		return;
	else {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
			cout << "marks : " << root->marks << endl;
	}
}
void greaterThanAverage(bst_node* root) {
	if (root == NULL)
		return;
	else {
		if (root->marks > 13.6)
			cout << root->marks << " ";
		
		greaterThanAverage(root->right);
	}
}
void lesserThanAverage(bst_node* root) {
	if (root == NULL)
		return;
	else {
		if(root->marks<13.6)
		cout << root->marks << " ";
		lesserThanAverage(root->left);
	}
}
bst_node* findMinimumMarks(bst_node* root) {
	bst_node* temp = root;
	while (temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}
bst_node* findMaximumMarks(bst_node* root) {
	bst_node* temp = root;
	while (temp->right != NULL)
		temp = temp->right;
	return temp;
}
bst_node* deleteNode(bst_node* root, float key) {
	if (root == NULL)
		return root;

	if (key < root->marks)
		root->left = deleteNode(root->left, key);
	else if (key > root->marks)
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
		bst_node* temp = findMinimumMarks(root->right);
		root->marks = temp->marks;
		root->right = deleteNode(root->right, temp->marks);
	}
	return root;
}

int main() {
	bst_node* root = createNode(13.6);
	insertMarks(root, 10.5);
	insertMarks(root, 14.5);
	insertMarks(root, 9.0);
	insertMarks(root, 12.0);
	insertMarks(root, 14.0);
	insertMarks(root, 16.0);
	insertMarks(root, 8.0);
	insertMarks(root, 10.0);
	insertMarks(root, 11.5);
	insertMarks(root, 13.0);
	insertMarks(root, 15.0);
	insertMarks(root, 18.0);
	insertMarks(root, 17.5);
	insertMarks(root, 19.0);
	insertMarks(root, 17.0);
	cout << "============== Marks in Sorted order ============== \n";
	inorderTraversal(root);
	cout << "============== Highest Marks ============== \n";
	cout <<findMaximumMarks(root)->marks;
	cout << "\n============== Lowest Marks ============== \n";
	cout << findMinimumMarks(root)->marks;
	cout << "\n============== Greater than average ============== \n";
	greaterThanAverage(root);
	cout << "\n============== Lesser than average ============== \n";
	lesserThanAverage(root);
	cout << "\n============== Delete Node ============== \n";
	deleteNode(root, 16.0);
	inorderTraversal(root);
	return 0;
}