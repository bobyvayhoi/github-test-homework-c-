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
};

void init(SinglyLinkList &list) {
	list.head = list.tail = NULL;
	list.length = 0;
}

void unshift(SinglyLinkList	&list) {
	Node *newNode;
	newNode = new Node;
	int x;
	cout<<"Nhap gia tri node: "; 
	cin>>x;
	newNode->val = x;
	if(!list.head) {
        list.head = newNode;
        list.tail = newNode;
    }
    newNode->next = list.head;
    list.head = newNode;
    list.length++;
}

void coutNode(SinglyLinkList list, int n) {
	Node *tmp = list.head;
	for (int i = 0; i < n; i++) {
		cout<<tmp->val<<" ";
		tmp = tmp->next;
	}
}

int main() { 
	SinglyLinkList list;
	init(list);
	int choose;
	do {
		cout<<"0 - Thoat\n1 - Nhap node\n2 - Xuat";
		cout<<"Chon: ";
		cin>>choose;
		if (choose == 1) unshift(list);
		else if (choose == 2) coutNode(list, list.length);
	} while (choose != 0); 
	return 0;
}