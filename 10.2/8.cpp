/***
Explain how to implement doubly linked lists using only one pointer value np[x]
per item instead of the usual two (next and prev). Assume that all pointer values
can be interpreted as k-bit integers, and define np[x] to be np[x] = next[x] XOR
prev[x], the k-bit "exclusive-or" of next[x] and prev[x]. (The value NIL is
represented by 0.) Be sure to describe what information is needed to access the
head of the list. Show how to implement the SEARCH, INSERT, and DELETE operations
on such a list. Also show how to reverse such a list in O(1) time.
***/

#include <cstddef>
#include <iostream>

class Node {
public:
	int value;
	Node *np;

	Node(int n)
		: np(nullptr),
		  value(n)
		{};
};


class DoublyLinkedList {
public:
	Node	*head;
	Node	*tail;
	int		reversed;

	DoublyLinkedList():
		head(nullptr),
		tail(nullptr),
		reversed(0)
		{};

	void insert(int n){
		if (head == nullptr){
			head = new Node(n);
			tail = head;
			std::cout << "value: " << n << " - addr: " << head << std::endl;
		}
		else{
			Node *prev;
			Node *curr;
			Node *tmp;
			Node *newNode;
			prev = nullptr;
			curr = head;
			while ((Node *)((long)curr->np ^ (long)prev) != nullptr){
				tmp = curr;
				curr = (Node*)((long)curr->np ^ (long)prev);
				prev = tmp;
			}
			newNode = new Node(n);
			curr->np = (Node*)((long)curr->np ^ (long)newNode);
			newNode->np = curr;
			tail = newNode;
			std::cout << "value: " << n << " - addr: " << newNode << std::endl;
		}
	}

	Node *search(int n){
		if (head == nullptr){
			return nullptr;
		}
		Node *prev;
		Node *curr;
		Node *tmp;
		prev = nullptr;
		curr = head;
		while (curr != nullptr && curr->value != n){
			tmp = curr;
			curr = (Node*)((long)curr->np ^ (long)prev);
			prev = tmp;
		}
		return curr;
	}

	void reverse(){
		//its a doubly linked list where the prev and next arent distinct variables
		// so all we gotta do is change what it thinks is the head and the tail
		Node *tmp;
		tmp = head;
		head = tail;
		tail = tmp;
	}
};

int main(){
	DoublyLinkedList list = DoublyLinkedList();
	Node *n;

	list.insert(5);
	list.insert(1);
	list.insert(3);
	list.insert(2);
	list.insert(1);
	list.insert(1);
	list.insert(1);

	n = list.search(1);
	std::cout << "search value: 1 - addr: " <<  n << std::endl;

	list.reverse();
	n = list.search(1);
	std::cout << "search value: 1 - addr: " <<  n << std::endl;

	list.insert(1);
	
	list.reverse();
	n = list.search(1);
	std::cout << "search value: 1 - addr: " <<  n << std::endl;
}
