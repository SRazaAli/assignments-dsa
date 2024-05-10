#include <iostream>
using namespace std;

struct bst_node {
	string productId;
	string productName;
	int productPrice;
	bst_node* left;
	bst_node* right;
};
bst_node* createNode(string productId,string productName,int producePrice) {
	bst_node* root = new bst_node();
	root->productId = productId;
	root->productName = productName;
	root->productPrice = producePrice;
	root->left = NULL;
	root->right = NULL;
	return root;
}
bst_node* insertProduct(bst_node* root, string productId, string productName, int productPrice) {
	if (root == NULL) {
		bst_node* root = createNode(productId, productName, productPrice);
		return root;
	}
	else if (root->productPrice > productPrice) {
		root->left = insertProduct(root->left, productId, productName, productPrice);
		return root;
	}
	else {
		root->right = insertProduct(root->right, productId, productName, productPrice);
		return root;
	}
}

void preorderTraversal(bst_node* root) {
	if (root == NULL) {
		return;
	}
	else {
		cout << "ProductId : " << root->productId << endl
			<< "ProductName : " << root->productName << endl
			<< "ProductPrice : " << root->productPrice << endl;
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void inorderTraversal(bst_node* root) {
	if (root == NULL)
		return;
	else {
		inorderTraversal(root->left);
		cout << "ProductId : " << root->productId << endl
			<< "ProductName : " << root->productName << endl
			<< "ProductPrice : " << root->productPrice << endl;
		inorderTraversal(root->right);
	}
}

void postorderTraversal(bst_node* root) {
	if (root == NULL)
		return;
	else {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		cout << "ProductId : " << root->productId << endl
			<< "ProductName : " << root->productName << endl
			<< "ProductPrice : " << root->productPrice << endl;
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
bst_node* searchProduct(bst_node* root, int productPrice) {
	if (root == NULL) {
		cout << "Product doesn't exist...\n";
		return root;
	}
	else if(root->productPrice == productPrice){
		cout << "Productfound...\nProductId : " << root->productId << endl
			<< "ProductName : " << root->productName << endl
			<< "ProductPrice : " << root->productPrice << endl;
	}
	else if (root->productPrice > productPrice) {
		searchProduct(root->left, productPrice);

	}
	else {
		searchProduct(root->right, productPrice);
	}
}
bst_node* deleteNode(bst_node* root, int key) {
	if (root == NULL)
		return root;

	if (key < root->productPrice)
		root->left = deleteNode(root->left, key);
	else if (key > root->productPrice)
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
		root->productPrice = temp->productPrice;
		root->right = deleteNode(root->right, temp->productPrice);
	}
	return root;
}
int main() {
	cout << "============== Zai Electronics ============== \n";
	bst_node*root = createNode("12199Z", "Speakers", 3400);
	insertProduct(root, "23729V", "Mouse", 1200);
	insertProduct(root, "11198A", "Keyboard", 4500);
	insertProduct(root, "23729X", "Monitor", 7599);
	insertProduct(root, "23729P", "usb", 800);
	cout << "============== Preorder ============== \n";
	preorderTraversal(root);
	cout << "============== Inorder ============== \n";
	inorderTraversal(root);
	cout << "============== Postorder ============== \n";
	postorderTraversal(root);
	cout << "============== Search Product ============== \n";
	searchProduct(root, 4500);
	cout << "============== Delete Product ============== \n";
	deleteNode(root, 1200);
	cout <<"--";
	preorderTraversal(root);
	return 0;
}