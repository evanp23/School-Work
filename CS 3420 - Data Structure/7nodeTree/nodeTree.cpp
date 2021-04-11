#include <iostream>
using namespace std;

// Node<T> class interface
template<class T>
class Node
{
private:
   T        item; // A data item
   Node<T>* next; // Pointer to next node
public:
   Node();
   Node(const T& anItem);
   Node(const T& anItem, Node<T>* nextNodePtr);
   void setItem(const T& anItem);
   void setNext(Node<T>* nextNodePtr);
   T getItem() const;
   Node<T>* getNext() const;
}; 

// Node<T> class implementation 
// default constructor
template<class T>
Node<T>::Node() : next(nullptr)
{} 

// 2nd constructor
template<class T>
Node<T>::Node(const T& anItem) : item(anItem), next(nullptr)
{} 

// 3rd constructor
template<class T>
Node<T>::Node(const T& anItem, Node<T>* nextNodePtr) : item(anItem), next(nextNodePtr)
{} 

// setItem() function
template<class T>
void Node<T>::setItem(const T& anItem)
{ item = anItem; } 

// setNext() funciton
template<class T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{ next = nextNodePtr; } 

// getItem() function
template<class T>
T Node<T>::getItem() const
{ return item; } 

// getNext() function
template<class T>
Node<T>* Node<T>::getNext() const
{ return next; } 

// external display() function
template <class T>
void display(Node<T> *hdptr);


int main(){
	
	Node<int> * hdptr = new Node<int>;
	Node<int> * temp;
	int nodeCount = 1;
	
	for(int i = 2; i < 6; i++){
		Node<int> * tempNode = new Node<int>;
		tempNode->setItem(i*10);
		tempNode->setNext(nullptr);
		
		temp = tempNode;
		temp->setNext(hdptr);
		cout<<"Node #"<<nodeCount<<": "<<"Item: "<< temp->getItem()<< ": "<<"Next: "<<temp->getNext()<<endl;
		hdptr = temp;
		nodeCount++;
	}
	
}
