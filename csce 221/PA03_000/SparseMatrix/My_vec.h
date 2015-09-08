/*My_vec.h
Your name
Header file for a vector data structure.
*/

#include <ostream>

using namespace std;

template <typename T>
class My_vec {

	//member variables
	int size, capacity;
	T *ptr;

public:
	//member functions
	My_vec();
	My_vec(int);
	~My_vec();
	My_vec(const My_vec& vec);
	My_vec& operator=(const My_vec& vec);
	int get_size() const;
	int get_capacity() const;
	T& operator[](int i) const;
	T& operator[](int i);
	bool is_empty() const;
	T& elem_at_rank(int r) const;
	void insert_at_rank(int r, const T& elem);
	void replace_at_rank(int r, const T& elem);
	void remove_at_rank(int r);

};

template <typename T>
ostream& operator<<(ostream& out, const My_vec<T>& vec);
