#include <iostream>

class node {
	public:
		node* left;
		node* right;
		int data;
		node(int i): data(i) , left(NULL), right(NULL) {}
};

class BST {
	private:
		node *root;
		void _print(node *ptr){
			if (root != NULL) {
				if (ptr->left != NULL) {
					_print(ptr->left);
				}
				std::cout << ptr->data << " ";
				if (ptr->right != NULL){
					_print(ptr->right);
				}
			}
			else
				std::cout << "empty tree\n";
		}
		void _CreateNode(int val, node **root){
			if (root == NULL){
				*root = new node(val);
			}
			else if (val < (*root)->data){
				if ((*root)->left != NULL){
					_CreateNode(val, &(*root)->left);
				}
				else
					(*root)->left = new node(val);
			}
			else if ((*root)->data < val){
				if ((*root)->right != NULL){
					_CreateNode(val, &(*root)->right);
				}
				else
					(*root)->right = new node(val);
			}
			else
				std::cout << "the key " << val << "already been added to the tree \n";
		}
	public:
	BST() {
		root = NULL;
	}
	void CreateNode(int val){
		_CreateNode(val, &root);
	}
	void print(){
		_print(root);
	}

};

int main(){
	BST tree;
	tree.CreateNode(10);
	tree.CreateNode(20);
	tree.CreateNode(30);
	tree.CreateNode(40);
	tree.CreateNode(50);
	tree.print();
}
