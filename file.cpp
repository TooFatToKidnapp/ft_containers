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
			if (root != NULL) {
				if (root->data == key)
					RemoveRoot();
				else {
					if (key < ptr->data && ptr->left != NULL){
						if (ptr->left->data == key){
							RemoveElm(ptr, ptr->left, true); // true == passing left child , false == passing right child
						}
						else
							_RemoveNode(key, ptr->left);
					}
					else if (key > ptr->data && ptr->right != NULL){
						if (ptr->right->data == key){
							RemoveElm(ptr, ptr->right, false); // true == passing left child , false == passing right child
						}
						else
							_RemoveNode(key, ptr->right);
					}
					else
						std::cout << "the key " << key << "was not found in the tree\n";
				}
			}
			else
				std::cout << "empty tree\n";
		}
		void RemoveElm(node * parent, node *target, bool is_left){
			if (root != NULL) {
				int target_data = target->data;
				int Smallest_right_subtree;
				// target got no children
				if (!target->left && !target->right){
					if (is_left == true){
						parent->left = NULL;
					}
					else
						parent->right = NULL;
					delete target;
				}
				// target got one child
				else if (!target->left && target->right){
					if (is_left == true)
						parent->left = target->right;
					else
						parent->right = target->right;
					target->right = NULL;
					delete target;
				}
				else if (target->left && !target->right){
					if (is_left == true)
						parent->left = target->left;
					else
						parent->right = target->left;
					target->left = NULL;
					delete target;
				}
				// target got 2 children
				else {
					Smallest_right_subtree = _FinedSmallest(target->right);
					_RemoveNode(Smallest_right_subtree, target);
					target->data = Smallest_right_subtree;
				}
			}
		}
		void RemoveRoot() {
			if (root != NULL){
				node *tmp = root;
				int smallest_right_subtree;
				// root got no children
				if (!root->left && !root->right) {
					delete root;
					root = NULL;
				}
				// root got only one child
				else if (!root->left && root->right){
					root = root->right;
					delete tmp;
				}
				else if (root->left && !root->right){
					root = root->left;
					delete tmp;
				}
				// root has 2 children
				else {
					smallest_right_subtree = _FinedSmallest(root->right);
					_RemoveNode(smallest_right_subtree, root);
					root->data = smallest_right_subtree;

				}
			}
		}
		void _RemoveSubTree(node *ptr){
			if (ptr != NULL){
				if (ptr->left != NULL)
					_RemoveSubTree(ptr->left);
				if (ptr->right != NULL)
					_RemoveSubTree(ptr->right);
				std::cout << ptr->data << "\n";
				delete ptr;
			}
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
	~BST() {
		_RemoveSubTree(root);
	}
};

int main(){
	BST tree;
	int tab [10] = {10 , -251 , -2 , 122 , 356, 98, 1, 0, 99, 69};
	for (int i = 0 ; i < 10; i++){
		tree.AddNode(tab[i]);
	}
	tree.print();
	tree.RemoveNode(10);
	std::cout << tree.ReturnRootKey() << "\n";
	tree.~BST();
	tree.print();

}
