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
	
	void push() {
		Node *newNode;
		newNode = new Node;
		int x;
		cout<<"\nNhap gia tri node: "; 
		cin>>x;
		newNode->val = x;
		if(!head) {
	        head = newNode;
	        tail = newNode;
	    } else {
    		tail->next = newNode;
	    	tail = newNode;
    	}
	    length++;
	}
	
	void unshiftMore() {
		int n;
		cout<<"\nNhap so luong node muon nhap: ";
		cin>>n;
		for (int i = 0; i < n; i++) {
			unshift();
		}
	}
	
	void pushMore() {
		int n;
		cout<<"\nNhap so luong node muon nhap: ";
		cin>>n;
		for (int i = 0; i < n; i++) {
			push();
		}
	}
	
	void findIdx() {
		if (length != 0) {
			int n;
			do {
				cout<<"\nNhap vi tri node muon tim: ";
				cin>>n;
			} while (n > length);
			Node *node = head;
			for (int i = 0; i < n; i++) {
				if (i + 1 == n) cout<<"\nNode thu "<<n<<" la: "<<node->val<<"\n";
				else node = node->next;
			}
		}
	}
	
	int findNodeHelper() {
		if (length != 0) {
			int n;
			cout<<"\nNhap gia tri node muon tim: ";
			cin>>n;
			Node *tmp = head;
			for (int i = 0; i < length; i++) {
				if (tmp->val == n) return 1;
				tmp = tmp->next;
			}
			return 0;
		}
	}
	
	void findNode() {
		int n = findNodeHelper();
		if (n == 1) cout<<"\nCo node\n";
		else cout<<"\nKhong co node\n";
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
		cout<<"\n0 - Thoat\n1 - Them 1 node vao dau danh sach\n2 - Them 1 node vao cuoi danh sach";
		cout<<"\n3 - Them nhieu node vao dau danh sach\n4 - Them nhieu node vao cuoi danh sach";
		cout<<"\n5 - Hien thi gia tri node thu n\n6 - Tim 1 node dua theo gia tri nhap vao";
		cout<<"\n20 - Xuat\n";
		cout<<"Chon: ";
		cin>>choose;
		if (choose == 1) list.unshift();
		else if (choose == 2) list.push();
		else if (choose == 3) list.unshiftMore();
		else if (choose == 4) list.pushMore();
		else if (choose == 5) list.findIdx();
		else if (choose == 6) list.findNode();
		else if (choose == 20) coutNode(list, list.length);
	} while (choose != 0); 
	return 0;
}