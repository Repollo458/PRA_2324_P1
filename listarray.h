#include <ostream>
#include "list.h"

template <typename T>
class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static sonst int MINSIZE;

	public:
		ListArray();
		~ListArray();
		T operator[](int pos);
		void resize(int new_size);
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);
};

