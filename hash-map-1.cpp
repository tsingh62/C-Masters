
#include<iostream>
#include<vector>
using namespace std;

// assuming that key is a string 
// value is random
template<typename T>
struct node
{
	string key; 
	T value;
	node<T> *next;

	// constructor
	node(string _key, T _value)
	{
		key = _key;
		value = _value;
		next = NULL;
	}

};

template<typename T>
struct hashTable
{
	// number of rows in bucket
	int maxSize;
	// total no of (key,value) pair inserted
	int curSize;

	node<T> **bucket; // double pointer - 2d?

	hashTable(int _maxSize)
	{
		maxSize = _maxSize;
		curSize = 0;
		bucket = new node<T> *[maxSize];
					// new node - pointer of maxSize
		// bucket [i] is a head of a linked list 
		// starung ar i
		for(int i=0; i<maxSize; i++) bucket[i] = NULL;
	}
	int hashFunc(string key)
	{
		int hash =0;
		int p = 1;
		

		for(int i=0; i<key.size(); i++)
		{
			hash += key[i] * p;
			hash %= maxSize;
			p *= 31;
			p %= maxSize;
		}
		// hash will remain < maxsize
		return hash;
	}
	// when load factor is greater than 
	// some value - rehashing
	void rehash()
	{
		node<T> **oldBucket = bucket;
		int oldSize = maxSize;

		curSize = 0;
		maxSize += 2;
		bucket = new node <T> * [maxSize];

		for(int i=0; i<maxSize; i++) bucket [i] = NULL;

		for(int i=0; i<oldSize; i++)
		{
			node<T> *temp= oldBucket[i];
			while(temp != NULL)
			{
				insert(temp->key, temp->value);
				temp = temp->next;
			}
		}

		// delete old bucket
		delete[] oldBucket;
	}

	void insert(string key, T value)
	{
		// when load factor is greater than 
	// some value - rehashing
	
		double load_factor = (double)curSize/maxSize;

		if(load_factor > 0.7)
		{
			rehash();
		}

		int index = hashFunc(key);
		node<T> *n = new node<T> (key, value);
		n->next = bucket[index];
		bucket[index]=n;

		curSize++;
		return;
	}
	// pointer - to a value
	T* serach(string key)
	{
		int index = hashFunc(key);
		node<T> *temp = bucket[index];

		while (temp!= NULL)
		{
			if (temp->key==key)
			{
				return &(temp->value);
			}
			temp = temp->next;
		}
		return NULL;
	}
	void remove(string key)
	{
		int index = hashFunc(key);
		node<T> *temp = bucket [index];

		// not present
		if(temp == NULL) return;

		// check for head
		if(temp->key ==key)
		{
			bucket[index] = bucket[index]->next;
			return;
		}
		while(temp->next != NULL)
		{
			if(temp->next->key == key)
			{
				temp->next = temp->next->next;
				return;
			}
			temp = temp->next;
		}
		return;
	}

};
int main()
{
	hashTable<int> H(3000);
//	cout << H.hashFunc("BB") << '\n';

	H.insert("aA",10);
	H.insert("BB", 20);
	if(H.serach("aA")!=NULL)
	{
		cout << H.serach("aA") << '\n'; 
	}
	if(H.serach("AAA")!=NULL)
	{
		cout << H.serach("AAA") << '\n'; 
	}
	else
	{
		cout << "Not found" << endl;
	}
}
// g++ sample.cpp -std=c++11