#include <iostream>

using std::cout;

class node {
	public:
		int data;
		node *left;
		node *right;
		node(int val) : data(val) , left(NULL), right(NULL) {}
};

class BST{
	private:
		node *root;
	void _Print_tree(node *ptr){
		if (root == NULL){
			cout << "tree is empty\n";
		}
		if (ptr->left != NULL ){
			_Print_tree(ptr->left);
		}
		cout << ptr->data  << " ";
		if (ptr->right != NULL ){
			_Print_tree(ptr->right);
		}
	}
	void _AddNode(int val, node *ptr){
		if (root == NULL){
			root = new node(val);
		}
		else if (val < ptr->data) {
			if (ptr->left == NULL){
				ptr->left = new node(val);
			}
			else {
				_AddNode(val, ptr->left);
			}
		}
		else if (val > ptr->data) {
			if (ptr->right == NULL){
				ptr->right = new node(val);
			}
			else {
				_AddNode(val, ptr->right);
			}
		}
		else
			cout << "a node wiht the key " << val << " already exists in the tree\n";

	}
	node *_ReturnNode(int val , node* ptr){
		if (root == NULL)
			cout << "tree is empty\n";
		else if (val < ptr->data){
			if (ptr->left != NULL)
				return _ReturnNode(val, ptr->left);
			else
				return NULL;
		}
		else if (val > ptr->data){
			if (ptr->right != NULL)
				return _ReturnNode(val, ptr->right);
			else
				return NULL;
		}
		else if( val == ptr->data)
			return ptr;
		return NULL;
	}
	int _FindSmallest(node *ptr){
		if (root == NULL){
			cout << "tree is empty\n";
			throw;
		}
		else{
			if (ptr->left != NULL)
				return _FindSmallest(ptr->left);
			else
				return ptr->data;
		}
	}
	public:
	BST(): root(NULL) {}
	void AddNode(int val){
		_AddNode(val, root);
	}
	void Print_tree(){
		_Print_tree(root);
		cout << "\n";
	}
	node *ReturnNode(int val){
		return _ReturnNode(val , root);
	}
	int FindSmallest(){
		return _FindSmallest(root);
	}
};



int main(){
	BST tree;
	tree.AddNode(10);
	tree.AddNode(122);
	tree.AddNode(99);
	tree.AddNode(-65);
	tree.AddNode(0);
	tree.Print_tree();

	if (tree.ReturnNode(100) == NULL)
		cout << "not found\n";
	else
		cout << "found\n";
	cout << "the smallest number in the tree is " << tree.FindSmallest() << "\n";
}
