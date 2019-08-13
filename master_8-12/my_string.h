#include <iostream>
#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <assert.h>
#include <stack>
#include <list>
#include <iterator>

using  std::string;
using  std::wstring;
using namespace std;

const int MAX_LENGTH = 1024 * 1024;

class myString
{
public:
	myString(const char *str = "")
	{
		if (NULL == str) {
			assert(false);
			return;
		}
		m_size = strlen(str);
		m_capacity = m_size;
		//cout << m_size << endl;
		m_str = new char[m_capacity + 1];
		memcpy(m_str, str, m_size + 1);
	}

	myString(char *str, int size = 0) :
		m_str(str),
		m_size(size)
	{
		if (str == NULL || size <= 0) {
			return;
		}
		m_size = size;
		m_capacity = m_size;
		m_str = new char[m_capacity + 1];
		memcpy(m_str, str, m_size + 1);
	}

	~myString();

	char *begin() {
		return m_str;
	}

	char *end() {
		return m_str + m_size;
	}

	myString(const myString &other);

	char *c_str();
	size_t Size()const;
	size_t Capacity() const;
	void myPushBack(char ch);
	void Reserve(int newCapacity);
	void Append(int size, char c);
	void Append(const char *dest, int size);
	void Prepend(const char *dest, int size);
	void Chop(int size);
	int Contains(const char *data, int size);
	list<string> Split(const char *delim);
	friend ostream &operator<<(ostream &os, const myString &c);

private:
	char *m_str;
	int m_size;
	int m_capacity;
};

#endif
