#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <string>

template <class Generic>
class ArrayList {
	private:
		Generic* _arr;
		int _capacity;
		int _size;

		bool _isFull();
		void _increaseCapacity();
	public:
		ArrayList();
		ArrayList(int);
		ArrayList(const ArrayList&);
		ArrayList& operator=(const ArrayList&);
		~ArrayList();

		int size();
		int capacity();

		void add(Generic);
		void add(int, Generic);
		void set(int, Generic);
		void push_back(Generic);
		Generic pop();
		Generic get(int);
		void del(int);

		// Only implemented for template class <car::Model>.
		std::string print();
		Generic findByID(int);
		Generic* findByMake(std::string, int&);
		Generic* findByModel(std::string, int&);
		Generic* findByColor(std::string, int&);
		void delByID(int);
};

#endif
