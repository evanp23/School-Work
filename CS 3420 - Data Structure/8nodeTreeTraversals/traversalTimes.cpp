//		Name: Evan Phillips
//		Course: CS 3420
//		Program: Program 8 - Binary Tree Basics
//		Date assigned: 11/17/2020
//		Date Due: 11/24/2020
//		Date Handed In: 11/24/2020
//		Remark: Program to test different functions on a templated Binary tree.
//		Struct, inorderDisplay, newNode provided by Dr. Hu.

#include <iostream>
using namespace std;

template <typename T>
struct node
{
	//Templated node class.
	
	T item;
	node<T>* left;
	node<T>* right;
};

template <typename T>
node<T>* newNode(T newItem);
// parameter newItem is used to initialize a new object
// Postcondition: returns the pointer of a new dynamic node initialized with node value newItem

template <typename T>
void inorderDisplay(node<T>* root);
// parameter root references the address of the root node
// Postcondition: displays node values of the BST in LRN order

template <typename T>
void postorderDisplay(node<T>* root);
//Parameter: Root node reference address
//Display node values in postorder

template <typename T>
void preorderDisplay(node<T>* root);
//parameter: Root node reference address
//Display node values in preorder

template <typename T>
int height(node<T>* root);
//parameter: reference address of root node
//returns: height of tree

template <typename T>
bool isLeaf(node<T>* root);
//parameter: root node reference address
//return: 1 if node is leaf and 0 if not

template <typename T>
int countLeaves(node<T>* root);
//parameter: root node reference address
//return: number of leaves in binary tree

template <typename T>
node<T>* newNode(T newItem){
	
	node<T> *temp = new node<T>;
	temp->item = newItem;
	temp->left = temp->right = nullptr;
	return temp;
}

template <typename T>
void inorderDisplay(node<T> *root){
	if (root != NULL)
	{
		inorderDisplay(root->left);
		cout <<root->item <<" ";
		inorderDisplay(root->right);
	}
}

template <typename T>
int height(node<T>* root) {

	if (root == NULL) 
		return 0; 

	if (isLeaf(root)) 
		return 1; 
		
	return 1 
		+ max(height(root->left), 
				height(root->right)); 
} 

template <typename T>
bool isLeaf(node<T>* root) {
	return root->left && root->left->right == root 
		&& root->right && root->right->left == root; 
} 

template <typename T>
void postorderDisplay(node<T>* root) 
{ 
    if (root == NULL){
        return;
	}
  
    postorderDisplay(root->left);
    postorderDisplay(root->right);
    cout << root->item << " ";
} 

template <typename T>
void preorderDisplay(node<T>* root) 
{ 
    if (root == NULL) 
        return; 
  
    cout << root->item << " "; 
    preorderDisplay(root->left);  
    preorderDisplay(root->right); 
}  

template <typename T>
int countLeaves(node<T>* root)  
{  
    if(root == NULL)      
        return 0;  
    if(root->left == NULL && root->right == NULL)  
        return 1;          
    else
        return countLeaves(root->left)+  
            countLeaves(root->right);  
}  

int main(){
	node<char>* root = newNode('a');
	root->left = newNode('b'); 
    root->right = newNode('c'); 
    root->left->left = newNode('d'); 
    root->left->right = newNode('e');
    
    cout<<"Char tree has "<<countLeaves(root)<<" leaf nodes."<<endl;
    cout<<"Char tree's height is "<<height(root)<<"."<<endl;

	cout<<"Preorder traversal: ";
	preorderDisplay(root);
	
	cout<<endl<<"Inorder traversal: ";
	inorderDisplay(root);
	
	cout<<endl;
	
	cout<<"Postorder traversal: ";
	postorderDisplay(root);
	
	cout<<endl;
	
	node<int>* root1 = newNode(16);
	root1->left = newNode(32);
	root1->right = newNode(64);
	root1->left->left = newNode(128);
	root1->left->right = newNode(256);
	root1->right->left = newNode(512);
	root1->right->right = newNode(1024);
	cout<<endl;
	
	cout<<"Int tree has "<<countLeaves(root1)<<" leaf nodes."<<endl;
    cout<<"Int tree's height is "<<height(root1)<<"."<<endl;

	cout<<"Preorder traversal: ";
	preorderDisplay(root1);
	
	cout<<endl<<"Inorder traversal: ";
	inorderDisplay(root1);
	
	cout<<endl;
	
	cout<<"Postorder traversal: ";
	postorderDisplay(root1);
	cout<<endl;
	
}
