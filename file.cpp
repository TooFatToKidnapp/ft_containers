#include <iostream>

class node {
	public:
		node* left;
		node* right;
		int data;
		node(int val): data(val), left(NULL), right(NULL) {}
		node(){}
};

class BST {
	private:
		node* root;
		node *_ReturnNode(int key, node* ptr) {
			if (ptr != NULL) {
				if (ptr->data == key)
					return ptr;
				else {
					if (key < ptr->data)
						return _ReturnNode(key , ptr->left);
					else
						return _ReturnNode(key, ptr->right);
				}
			}
			else
				return NULL;
		}
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
		void _AddNode(int val, node *ptr) {
			if (root == NULL){
				root = new node(val);
			}
			else if (val < ptr->data){
				if (ptr->left != NULL){
					_AddNode(val, ptr->left);
				}
				else
					ptr->left = new node(val);
			}
			else if (ptr->data < val){
				if (ptr->right != NULL){
					_AddNode(val, ptr->right);
				}
				else
					ptr->right = new node(val);
			}
			else
				std::cout << "the key " << val << " already been added to the tree \n";
		}
		int _FinedSmallest(node *ptr) {
			if (root == NULL) {
				std::cout << "the tree is empty\n";
				throw;
			}
			else {
				if (ptr->left != NULL){
					return _FinedSmallest(ptr->left);
				}
				else{
					return ptr->data;
				}
			}

		}
		void _RemoveNode(int key, node *ptr){
			if (ptr != NULL) {
				node *tmp = ReturnNode(key);
				if (tmp == NULL){
					std::cout << "node with the key " << key << " dose not exist\n";
				}
				node *tmp2 = new node();
				tmp2->left = tmp->left;
				tmp2->right = tmp->right;
				delete tmp;
				
			}
			else
				std::cout << "tree is empty\n";
		}
	public:
	BST() {
		root = NULL;
	}
	void AddNode(int val){
		_AddNode(val, root);
	}
	void print(){
		_print(root);
		std::cout << "\n";
	}
	node *ReturnNode(int key) {
		return _ReturnNode(key, root);
	}
	int ReturnRootKey() {
		if (root != NULL)
			return root->data;
		else
			throw;
	}
	void PrintChildren(int key){
		node * ptr = ReturnNode(key);
		if (ptr != NULL){
			std::cout << "parent node = " << ptr->data << "\n";
			if (ptr->left != NULL)
				std::cout << "left child = " << ptr->left->data << "\n";
			else
				std::cout << "left child = NULL\n";
			if (ptr->right != NULL)
				std::cout << "right child = " << ptr->right->data << "\n";
			else
				std::cout << "right child = NULL\n";
		}
		else
			std::cout << "the is not in the tree\n";
	}
	int	FinedSmallest(){
		return _FinedSmallest(root);
	}
	void RemoveNode(int key){
		_RemoveNode(key, root);
	}
};

int main(){
	BST tree;
	int tab [10] = {10 , -251 , -2 , 122 , 356, 98, 1, 0, 99, 69};
	for (int i = 0 ; i < 10; i++){
		tree.AddNode(tab[i]);
	}
	std::cout << tree.FinedSmallest() << "\n";
	tree.print();
}
