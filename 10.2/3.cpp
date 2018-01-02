/***
Implement a stack using a singly linked list L. The operations PUSH
and POP should still take O(1) time.
***/

#include <cstddef>
#include <iostream>
#include <stdexcept>


class Node {
public:
	int value;
	Node *next;

	Node(int n)
		: next(nullptr),
		  value(n)
		{};
};


class Stack {
public:
	Node *top;

	Stack()
		: top(nullptr)
		{};

	~Stack(){
		Node *curr;
		Node *next;
		curr = top;
		while (curr != nullptr){
			next = curr->next;
			free(curr);
			curr = next;
		}
	}

	void push(int n) {
		Node *newNode = new Node(n);
		newNode->next = top;
		top = newNode;
	}

	int pop(void) {
		if (top != nullptr){
			int value;
			Node *temp;
			value = top->value;
			temp = top;
			top = top->next;
			delete temp;
			return value;
		}
		else{
			throw std::runtime_error("Empty stack");
		}
	}
};


int main(){
	Stack *stack = new Stack();
	int temp;
	
	stack->push(3);
	stack->push(5);
	stack->push(2);
	std::cout << stack->pop();
	std::cout << stack->pop();
	std::cout << stack->pop();
	delete stack;
}
