#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cmath>
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
			cout<<"\nNhap gia tri node: ";
			cin>>n;
			Node *tmp = head;
			for (int i = 0; i < length; i++) {
				if (tmp->val == n) return n;
				tmp = tmp->next;
			}
			return 0;
		}
	}
	
	void findNode() {
		if (length != 0) {
			int n = findNodeHelper();
			if (n != 0) cout<<"\nCo node\n";
			else cout<<"\nKhong co node\n";
		}
	}
	
	void insertNode() {
		if (length != 0) {
			int n = findNodeHelper();
			if (n != 0) {
				Node *node = head;
				for (int i = 0; i < length; i++) {
					if (node->val == n) {
						int x;
						cout<<"\nNhap gia tri node: ";
						cin>>x;
						Node *tmp;
						tmp = new Node;
						tmp->val = x;
						tmp->next = node->next;
						node->next = tmp;
						length++;
						break;
					}
					node = node->next;
				}
			}
			else cout<<"\nKhong co node\n";
		}
	}
	
	void showLength() {
		cout<<"\nCo "<<length<<" node trong xau\n";
	}
	
	int primeNum(int n) {
		if (n <= 1) return 0;
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) return 0;
		}
		return 1;
	}
	
	void showNode(int choose = 0) {
		if (length != 0) {
			cout<<"\n";
			Node *node = head;
			for (int i = 0; i < length; i++) {
				if (choose == 0) {
					cout<<node->val<<" ";
				} else {
					if (primeNum(node->val)) cout<<node->val<<" ";
				}
				node = node->next;
			}
			cout<<"\n";
		} else cout<<"\nKhong co node\n";
		
	}
	
	void deleteNode(int num = 0) {
		if (length != 0) {
			int n;
			if (num == 0) n = findNodeHelper();
			else n = num;
			if (n != 0) {
				Node *node = head;
				for (int i = 0; i < length; i++) {
					if (head->val == n) {
						head = head->next;
						length--;
						break;
					}
					if (node->next->val	 == n) {
						node->next = node->next->next;
						length--;
						break;
					}
					node = node->next;
				}
			}
			else cout<<"\nKhong co node\n";
		}
	}
	
	void sumAll() {
		if (length != 0) {
			int sum = 0;
			Node *node = head;
			for (int i = 0; i < length; i++) {
				sum += node->val;
				node = node->next;
			}
			cout<<"\nTong gia tri la: "<<sum<<"\n";
		}
	}
	
	void minMax() {
		if (length != 0) {
			Node *node = head;
			int min = node->val, max = node->val;
			for (int i = 0; i < length; i++) {
				node = node->next;
				if (node->val < min) min = node->val;
				if (node->val > max) max = node->val;
			}
			cout<<"\nMin la: "<<min<<"\nMax la: "<<max<<"\n";
		}
	}
	
	void changeValue(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	
	void sort() {
		if (length != 0) {
			int l = length;
			do {
				Node *node = head;
				for (int i = 0; i < l - 1; i++) {
					if (node->val > node->next->val) changeValue(node->val, node->next->val);
					node = node->next;
				}
				l--;
			} while(l > 0);
		}
	}
	
	void showEndToStart() {
		if (length != 0) {
			int l = length;
			cout<<"\n";
			do {
				Node *node = head;
				for (int i = 0; i < l; i++) {
					if (i == l - 1) cout<<node->val<<" ";
					node = node->next;
				}
				l--;
			} while(l > 0);
		}
	}
	
	int countNode(int x) {
		int count = 0;
		Node *node = head;
		for (int i = 0; i < length; i++) {
			if (node->val == x) count++;
			node = node->next;
		}
		return count;
	}
	
	void deletePrimeNode() {
		if (length != 0) {
			Node *node = head;
			for (int i = 0; i < length; i++) {
				if (primeNum(node->val)) deleteNode(node->val);
				node = node->next;
			}
		}
	}
	
	void addTwo() {
		if (length != 0) {
			Node *node = head;
			for (int i = 0; i < length; i++) {
				node->val += 2;
				node = node->next;
			}
		}
	}
};

void countNode(SinglyLinkList list) {
	if (list.length != 0) {
		do {
			int headVal = list.head->val;
			int count = list.countNode(headVal);
			cout<<"\nSo "<<headVal<<" co "<<count;
			for (int i = 0; i < count; i++) {
				list.deleteNode(headVal);
			}
		} while (list.length > 0);
		cout<<"\n";
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
		cout<<"\n7 - Them 1 node vao sau 1 node nao do\n8 - Dem so luong node trong xau";
		cout<<"\n9 - Hien thi danh sach cac node trong xau\n10 - Huy 1 node (nhap gia tri can tim)";
		cout<<"\n11 - Huy toan bo danh sach\n12 - Tinh tong gia tri toan bo danh sach";
		cout<<"\n13 - Tim gia tri lon nhat va nho nhat trong danh sach\n14 - Sap xep danh sach voi gia tri tang dan";
		cout<<"\n15 - Hien thi gia tri toan bo danh sach theo thu tu tu cuoi den dau\n17 - Dem so lan xuat hien cua mot node trong danh sach";
		cout<<"\n18 - Hien thi cac node la so nguyen to\n19 - Huy tat ca cac node la so nguyen to";
		cout<<"\n20 - Tang gia tri moi node len 2";
		cout<<"\nChon: ";
		cin>>choose;
		if (choose == 1) list.unshift();
		else if (choose == 2) list.push();
		else if (choose == 3) list.unshiftMore();
		else if (choose == 4) list.pushMore();
		else if (choose == 5) list.findIdx();
		else if (choose == 6) list.findNode();
		else if (choose == 7) list.insertNode();
		else if (choose == 8) list.showLength();
		else if (choose == 9) list.showNode();
		else if (choose == 10) list.deleteNode();
		else if (choose == 11) list.init();
		else if (choose == 12) list.sumAll();
		else if (choose == 13) list.minMax();
		else if (choose == 14) list.sort();
		else if (choose == 15) list.showEndToStart();
		else if (choose == 17) countNode(list);
		else if (choose == 18) list.showNode(1);
		else if (choose == 19) list.deletePrimeNode();
		else if (choose == 20) list.addTwo();
	} while (choose != 0); 
	return 0;
}