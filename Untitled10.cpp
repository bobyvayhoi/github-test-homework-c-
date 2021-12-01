#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

struct Node {
	int val;
	Node *next;
};

struct SinglyLinkList {
	Node *head;
	Node *tail;
	int length;	
	
	void init() {
		head = NULL;
		tail = NULL;
		length = 0;
	}
	
	void unshift() {
		Node *newNode;
		newNode = new Node;
		int x;
		cout<<"\nNhap gia tri node: "; 
		cin>>x;
		newNode->val = x;
		if(!head) {
	        head = newNode;
	        tail = newNode;
	    }
	    newNode->next = head;
	    head = newNode;
	    length++;
	}
};

void coutNode(SinglyLinkList list, int n) {
	Node *tmp = list.head;
	for (int i = 0; i < n; i++) {
		cout<<tmp->val<<" ";
		tmp = tmp->next;
	}
}

int main() { 
	SinglyLinkList list;
	list.init();
	int choose;
	do {
		cout<<"\n0 - Thoat\n1 - Nhap node\n2 - Xuat\n";
		cout<<"Chon: ";
		cin>>choose;
		if (choose == 1) list.unshift();
		else if (choose == 2) coutNode(list, list.length);
	} while (choose != 0); 
	return 0;
}