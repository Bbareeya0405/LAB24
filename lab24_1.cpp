#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root = nullptr;
		int size = 0;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		if(current -> next == nullptr)return;
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
	size++;
}

void List::show(){
	if(root == nullptr)return;
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

//Write List::remove() here
void List::remove(int index){
    if (root == nullptr || index < 0 || index >= size) return; // ตรวจสอบขอบเขต
    
    Node *toDelete = nullptr;
    if (index == 0) { // ลบโหนดแรก
        toDelete = root;
        root = root->next;
    } else {
        Node *current = root;
        for (int i = 0; i < index - 1; i++) {
            if (current->next == nullptr) return; // ป้องกันการเข้าถึง null pointer
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }
    delete toDelete;
    size--;
}

int main() {
    List myList;
    myList.append(10);
    myList.append(20);
    myList.append(30);
    myList.show();
    myList.remove(1);
    myList.show();
    return 0;
}
