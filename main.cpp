#include <iostream>

template<class T, class U> 
class Item{
public:
	T key;
	U value;
	Item *next;
};

template<class T, class U>
class LinkedList{

private:
	Item<T, U> *head;

public:
	LinkedList():head(0){}
	U& operator[](T key);
	void insertItem(T key, U value);
	void printContents();
};


template<class T, class U>
U& LinkedList<T,U>::operator[](T key){
	Item<T, U> *temp = head;
	while(temp && temp->key != key){
		temp = temp->next;
	}

	if(temp)
		return temp->value;
	else{
		insertItem(key, "");
		temp = head;
		while(temp->next)
			temp = temp->next;
		return temp->value;
	}
}

template<class T, class U>
void LinkedList<T, U>::insertItem(T key, U value){
	Item<T, U> *item = new Item<T, U>;
	item->key = key;
	item->value = value;
	item->next = NULL;

	if(!head){
		head = item;
	}
	else{
		Item<T, U> *temp = head;
		while(temp->next)
			temp = temp->next;
		temp->next = item;
	}
}

template<class T, class U>
void LinkedList<T, U>::printContents(){
	Item<T, U> *temp = head;
	while(temp){
		std::cout << "[" << temp->key << ":" << temp->value << "]\t";
		temp = temp->next;
	}
}



template<class T, class U>
class HashTable{

private:
	int hash(T key);
	LinkedList<T, U> *bucket;

public:
	HashTable();
	U& operator[](T key);
	void display();
};


#include <typeinfo>

template<class T, class U>
HashTable<T, U>::HashTable(){
	bucket = new LinkedList<T, U>[10];
}

template<class T, class U>
int HashTable<T, U>::hash(T key){
	int len = key.length(), hash_value = 0;
	for(int i = 0; i < len; i++){
		hash_value ^= key[i];
	}
	
	return hash_value*len;
}

template<class T, class U>
U& HashTable<T, U>::operator[](T key){
	std::cout << "key [" << key << "] hash [" << hash(key) << "]" << std::endl;
	std::cout << typeid(bucket[0]).name() << std::endl;
	return bucket[hash(key)%10][key];//(key);
}

template<class T, class U>
void HashTable<T, U>::display(){
	std::cout << "HashTable of size 10 is as follows:" << std::endl;
	for(int i = 0; i < 10; i++){
		std::cout << "Level " << i+1 << ":";
		bucket[i].printContents();
		std::cout << std::endl;
	}
}


int main(){
	HashTable<std::string, std::string> hash_table;
	hash_table["laugh"] = "yes";
	hash_table["sad"] = "no";
	hash_table["angry"] = "really_don't_know";
	hash_table["foolish"] = "haha";
	hash_table.display();

	std::cout << "Are you laughing? ... " << hash_table["laugh"] << std::endl;
}

