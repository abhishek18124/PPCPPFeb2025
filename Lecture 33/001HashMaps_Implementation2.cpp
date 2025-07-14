/*

	Implementation of HashMap/HashTable

*/

#include<iostream>

using namespace std;

class node {

public :

	int K;
	int V;
	node* next;

	node(int K, int V) {
		this->K = K;
		this->V = V;
		this->next = NULL;
	}

};

class HashMap {

	int N; //  to store the hash table capacity
	int M; //  to store the hash table size
	double L; // to store the load factor threshold

	node** T; // to store the address of the  dynamic
	// array that represents the hash table

	int hashFn(int K) {
		// transform K into a hash index
		return K % N;
	}

	void transfer(node* head) {
		// 1. rehash (K, V) pairs present in the linkedList represented
		//    by "head" pointer to the updated hashMap

		node* temp = head;
		while (temp != NULL) {
			insert(temp->K, temp->V);
			temp = temp->next;
		}

		// 2. release memory allocated for the linkedList represented
		//    by "head" pointer

		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}

	}

	void rehash() {

		// 1. save pointer to the current hashMap and its capacity

		node** oldT = T;
		int oldN = N;

		// 2. create a hashMap with double capacity

		N = 2 * N;
		T = new node*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
		M = 0; // newly created table is empty

		// 3. transfer (K, V) pairs from old hashMap to the updated hashMap

		for (int i = 0; i < oldN; i++) {
			transfer(oldT[i]);
		}

		// 4. release the memory allocated to the old hashMap

		delete [] oldT;

	}

public :

	HashMap(int N = 5, double L = 0.7) {
		this->N = N;
		this->M = 0; // init there are no key-value pairs in the hashTable
		this->L = L;

		T = new node*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL; // init the linkedList at each bucket is empty
		}
	}

	void insert(int K, int V) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. create a node with the given (K, V) pair and insert it at
		//    head of the linkedList stored at the hash index

		node* n = new node(K, V);

		// 3. update the pointer to the head of the linkedList stored at
		//    the hash index such that it holds the address of the newly
		//    created node

		n->next = T[hashIdx];
		T[hashIdx] = n;

		M++;

		// 4. rehash, if loadFactor exceeds the loadFactor Threshold

		double loadFactor = (double)M / N;
		if (loadFactor > L) {
			// rehash ...
			cout << "rehasing due to LF = " << loadFactor << endl;
			rehash();
		}

	}

	node* find(int K) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. search for the node with the given key in the  linkedList
		//    stored at the hash index

		node* temp = T[hashIdx];
		while (temp != NULL) {
			if (temp->K == K) {
				// you've found the node you were looking for
				break;
			}
			temp = temp->next;
		}

		return temp;


	}

	void erase(int K) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. delete the node with the given key from the linkedList
		//    stored at the hash index

		node* cur = T[hashIdx]; // cur is pointing to the head node

		if (cur == NULL) {
			// linkedList at hashIdx is empty therefore key doesn't exist
			return;
		}

		if (cur->K == K) {
			// delete the head node of the linkedList maintained at the hashIdx
			T[hashIdx] = cur->next;
			delete cur;
			M--;
			return;
		}


		node* prev = NULL;
		// of the linkedList maintained at the hashIdx

		while (cur != NULL) {
			if (cur->K == K) {
				// delete the cur node
				prev->next = cur->next;
				delete cur;
				M--;
				break;
			}
			prev = cur; // move prev one-step fwd
			cur = cur->next; // move cur one-step fwd
		}

	}

	void printLinkedList(node* head) {
		while (head != NULL) {
			cout << "(" << head->K << ", " << head->V << ") ";
			head = head->next;
		}
		cout << endl;
	}

	void printHashMap() {
		// iterate over buckets in the hashMap
		for (int i = 0; i < N; i++) {
			// print the linkedList stored at the ith bucket of the hashMap
			cout << i << " : ";
			printLinkedList(T[i]);
		}
		cout << endl;
	}

	int& operator[](int K) {
		node* n = find(K);
		if (n == NULL) {
			int garbage;
			insert(K, garbage);
			n = find(K);
		}
		return n->V;
	}

};

int main() {

	HashMap hm;

	hm.insert(7, 49);
	hm.insert(2, 4);
	hm.insert(6, 36);

	hm.printHashMap();

	cout << hm[7] << endl; // hm.operator[](7) // 49

	// cout << hm[10] << endl; // hm.operator[](10)

	// hm[10] = 100;

	hm[2] = 0;

	// hm.operator[](2) = 0;

	// 4 = 0;

	hm.printHashMap();

	hm[10] = 100;

	// hm.operator[](10) = 100;

	hm.printHashMap();

	return 0;
}