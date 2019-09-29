#include <iostream>

using namespace std;

class ListException {};

class List {

	struct Node {
		int data_;
		Node *next_, *prev_;
		
		Node(int data)
				: data_(data), next_(nullptr), prev_(nullptr) {}
	};

	Node* head_;
	
public:

	List() : head_(new Node(0)) {
		head_ -> next_ = head_;
		head_ -> prev_ = head_;
	}

	List(const List& other) : List() {
		cout << "Copy constructor" << endl;
		Node* node = other.head_ -> next_;
		while (node != other.head_) {
			push_back(node -> data_);
			node = node -> next_;
		}
	}
	
	~List() {
		cout << "Destructor" << endl;
		clear();
		delete head_;
	}
	
	List& operator=(const List& other) {
		if (this != &other) {
			clear();
			Node* node = other.head_ -> next_;
			while (node != other.head_) {
				push_back(node -> data_);
				node = node -> next_;
			}
		}
		return *this;
	}
	
	bool clear() {
		while (!empty()) {
			pop_back();
		}
	}
	
	bool empty() const {
		return head_ -> prev_ == head_;
	}
	
	void push_back(int value) {
		Node* new_node = new Node(value);
		Node* last = head_ -> prev_;

		last -> next_ = new_node;
		new_node -> prev_ = last;
		
		head_ -> prev_ = new_node;
		new_node -> next_ = head_;
	}
	
	int pop_back() {
		if (empty()) {
			throw ListException();
		}
		Node* last = head_ -> prev_;
		Node* new_last = last -> prev_;
		
		new_last -> next_ = head_;
		head_ -> prev_ = new_last;
		
		int result = last -> data_;
		delete last;
		return result;
	}
	
	int back() const {
		if (empty()) {
			throw ListException();
		}
		return head_->prev_->data_;
	}
	
	

};

int main() {
	List l1;
	try {
		List l2;
		cout << l2.back() << endl;
	} catch (ListException e) {
		cout << "The list is empty!" << endl;
	}
	l1.push_back(10);
	l1.push_back(20);
	cout << l1.back() << endl;
	
	List l2 = l1;

	List l3;
	l3 = l1;	
	return 0;
}





