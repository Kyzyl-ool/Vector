#include <stdlib.h>
#include <string>
#include <cassert>
#include <iostream>

#define VECTOR_POISON -99999
#define VECTOR_DEFAULT_SIZE 256

using std::string;
using std::cout;
using std::endl;

typedef unsigned int uint;

typedef enum vector_error_codes
{
	VECTOR_OK = 0,
} vector_error_code;


template <typename data_T>
class vector
{
private:
	data_T* data;
	uint len;

public:
	vector();
	explicit vector(uint size);
	vector(const vector& v);
	
	~vector();
	
	
	uint length();
	vector_error_code append(data_T value);
	void swap(vector& that);
	
	data_T operator[](uint n);
	
	vector <data_T>& operator=(const vector <data_T>& that);
	//~ vector <data_T>& operator=(const vector <data_T>&& that);
	
	void dump(string name, string destination);
	vector_error_code check();
};

string vector_convert_error_code_to_string(vector_error_code code)
{
	switch (code)
	{
		#define _RET_CODE(code) case code: return #code;
		_RET_CODE(VECTOR_OK)
		default: return "VECTOR_UNKNOWN_ERROR"; 
		#undef _RET_CODE
	}
}

template <typename data_T>
vector <data_T>::vector(uint size)
{
	data = (data_T* )malloc(size*sizeof(data_T));
	for (uint i = 0; i < size; i++) data[i] = VECTOR_POISON;
	len = size;
}

template <typename data_T>
vector <data_T>::vector()
{
	data = (data_T* )malloc(VECTOR_DEFAULT_SIZE*sizeof(data_T));
	for (uint i = 0; i < VECTOR_DEFAULT_SIZE; i++) data[i] = VECTOR_POISON;
	len = VECTOR_DEFAULT_SIZE;
}

template <typename data_T>
vector <data_T>::vector(const vector <data_T>& v)
{
	len = v.len;
	data = (data_T* )malloc(len*sizeof(data_T));
	for (uint i = 0; i < len; i++) data[i] = v.data[i];
}



template <typename data_T>
vector <data_T>::~vector()
{
	for (uint i = 0; i < len; i++) data[i] = VECTOR_POISON;
	free(data);
}

template <typename data_T>
uint vector <data_T>::length()
{
	return len;
}

template <typename data_T>
vector_error_code vector <data_T>::check()
{
	return VECTOR_OK;
}

template <typename data_T>
void vector <data_T>::dump(string name, string destination)
{
	if (destination == "stdout")
	{
		cout << "Vector \"" << name << "\" dump [" << vector_convert_error_code_to_string(check()) << "].\n{\n";
		cout << "	length = " << len << "\n";
		cout << "	data:\n";
		for (uint i = 0; i < len; i++)
			cout << "		data[" << i << "] = " << data[i] << endl;
		cout << "}\n\n";
		
	}
	else
	{
		assert(!"Not implemented.");
	}
}

template <typename data_T>
vector_error_code vector <data_T>::append(data_T value)
{
	data[len++] = value;
}

template <typename data_T>
data_T vector <data_T>::operator[](uint n)
{
	return data[n];
}

template <typename data_T>
void vector <data_T>::swap(vector& that)
{
	std::swap(len, that.len);
	std::swap(data, that.data);
}

//~ template <typename data_T>
//~ template <typename data_U>
//~ vector <data_T>& vector <data_T>::operator=(const vector <data_U>&& that)
//~ {
	//~ swap(that);
//~ }

template <typename data_T>
vector <data_T>& vector <data_T>::operator=(const vector <data_T>& that)
{
	vector <data_T> tmp (that);
	tmp.swap(*this);

	//~ swap(that);
	return *this;
}
