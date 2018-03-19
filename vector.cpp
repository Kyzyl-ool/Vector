#include <stdlib.h>
#include <string>
#include <cassert>
#include <iostream>

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
	vector(uint size);
	~vector();
	uint length();
	vector_error_code append(data_T value);
	data_T operator[](uint n);
	void dump(string destination);
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
	data = (data_T* )calloc(size, sizeof(data_T));
	
}

template <typename data_T>
vector <data_T>::~vector()
{
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
void vector <data_T>::dump(string destination)
{
	if (destination == "stdout")
	{
		cout << "Vector dump [" << vector_convert_error_code_to_string(check()) << "].\n{\n";
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
