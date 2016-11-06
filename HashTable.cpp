#include "HashTable.hpp"
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
	//return bucket[hash(key)%10].operator[](key);
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
	//hash_table["laugh"] = "yes";
	hash_table.display();
}





