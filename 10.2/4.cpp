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


class Queue {
public:
	Node *start;
	Node *end;

	Queue()
		: start(nullptr),
		  end(nullptr)
		{};

	~Queue(){
		Node *curr;
		Node *next;
		curr = start;
		while (curr != nullptr){
			next = curr->next;
			free(curr);
			curr = next;
		}
	}

	void enqueue(int n) {
		Node *newNode = new Node(n);
		newNode->next = nullptr;
		if (end != nullptr){
			end->next = newNode;
		}
		end = newNode;
		if (start == nullptr){
			start = newNode;
		}
	}

	int dequeue(void) {
		if (start != nullptr){
			int value;
			Node *temp;
			value = start->value;
			temp = start;
			start = start->next;
			if (start == nullptr){
				end = nullptr;
			}
			delete temp;
			return value;
		}
		else{
			throw std::logic_error("Empty queue");
		}
	}
};


int main(){
	Queue *queue = new Queue();
	int temp;
	
	queue->enqueue(3);
	queue->enqueue(5);
	queue->enqueue(2);
	std::cout << queue->dequeue();
	std::cout << queue->dequeue();
	std::cout << queue->dequeue();
	delete queue;
}
