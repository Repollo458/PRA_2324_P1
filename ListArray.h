#include <ostream>
#include "List.h"
#include <iostream>
using namespace std;

template <typename T>
class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;

	public:
		ListArray(){
			arr = new T[MINSIZE];
			max = 5;
			n = max-1;
		}
		~ListArray(){delete[] arr;}
		T operator[](int pos){
			try{
				if(pos < 0 || pos >this->n){
					throw std::out_of_range("Valor fuera de rango\n");
				}
				else{
					return arr[pos];
				}
			}catch(std::out_of_range& e){
				cerr << e.what();
			}
		}
		void resize(int new_size){
			int* arr_new = new int[new_size];
			for(int i = 0; i < size(); i++){
				arr_new[i] = arr[i];
			}
			delete[] arr;
			max = new_size;
			*arr = *arr_new;
		}
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			out << "[";
			for(int i = 0; i <= list.n; i++){
				out << list.arr[i] << " ";
			}
			out << "]\n";
			return out;
		}
		void append(T e) override{
			insert(max-1,e);
		}
		void prepend(T e) override{
			insert(0,e);
		}
		void insert(int pos, T e) override{
			arr[pos] = e;
		}
		int size() override{
			return max;
		}
		bool empty() override{
			if(size() == 0){
				return true;
			}
			else{
				return false;
			}
		}
		T get(int pos) override{
			return arr[pos];
		}
		T remove(int pos) override{
			T devolver = arr[pos];
			arr[pos] = 0;
			return devolver;
		}
		int search(T e) override{
			for(int i = 0; i < size(); i++){
				if(arr[i] == e){
					return i;
				}
			}
			return -1;
		}

};
