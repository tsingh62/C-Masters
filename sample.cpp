#include<iostream>
#include<string>
using namespace std;

// assuming that key is a string and 
// value is random
template <typename T>
struct node
{
    // has a key and a value
    // ke = string | value = random
    string key;
    T value;

    //                     bucket   0   1   2  3
    // node will contain a pointer  []- []-[]-[]
    // pointing to the next pointer     |
    //                                  []

    node<T> *nxt;

    // constructor
    node(string _key, T _value)
    {
        key = _key;
        value = _key;
        nxt = NULL;
    }
};

template <typename T>
struct hash_table // this struct contain 2d array
{   
    int maxSize; // no of rows in bucket
    int curSize; // no of (key, value) pair inserted
    
    node<T> **bucket; // 2 d pointer

    hash_table(int _maxSize)
    {
        maxSize = _maxSize;
        curSize = 0;
        bucket = new node<T> *[maxSize];

        for(int i=0; i<maxSize; i++)
        {
       // bucket[i] is the head of the linked list
       // starting at 0 /i   
            bucket[i] = NULL;
        }
    }
    int hash_func(string key)
        {
            int hash =0;
            int p = 1;
            

            for(int i=0; i< key.size(); i++)
            {
                hash += key[i] + p;
                hash %= maxSize;
                
                p+=31;
                p %= maxSize;
            }
            return hash;
        }

        void insert(string key, T value)
        {
            int index = hash_func(key);

            node <T> *n = new node<T> (key, value);
            n->next = bucket[index];
            bucket[index] = n;

            curSize++;
            return;
        }

        // pointer to a value
        T *search(string key)
        {
            int index = hash_func(key);

            node <T> *temp = bucket[index];
            while(temp != NULL)
            {
                if(temp->key == key)
                {
                    return &(temp->value);
                }
                temp = temp->next;
            }
            return NULL:
        }
};
int main()
{
    hash_table<int> H(7);
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
    return 0;
}