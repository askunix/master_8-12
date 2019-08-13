#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "my_string.h"
#include <cstdbool>

myString::myString(const myString &other)
{
	m_size = other.m_size;
	m_capacity = other.m_capacity;
	m_str = new char[m_size + 1];
	memcmp(m_str, other.m_str, m_size);
}

myString::~myString()
{
	if (NULL != m_str)
	{
		delete[]m_str;
		m_str = NULL;
		m_size = 0;
		m_capacity = 0;
	}
}

char *myString::c_str()
{
	return m_str;
}

size_t myString::Size() const
{
	return m_size;
}

size_t myString::Capacity() const
{
	return m_capacity;
}

void myString::Reserve(int newCapacity)
{
	if (newCapacity > m_capacity) {
		char *str = new char[newCapacity + 1];
		strcpy(str, m_str);
		//�ͷžɿռ�
		delete[] m_str;
		m_str = str;
		m_capacity = newCapacity;
	}
}

void myString::myPushBack(char ch)
{
	if (m_size == m_capacity) {
		Reserve(m_capacity * 2);
	}
	m_str[m_size++] = ch;
	m_str[m_size] = '\0';
}

void myString::Append(int size, char c)
{
	for (int i = 0; i < size; ++i) {
		myPushBack(c);
	}
}

void myString::Append(const char *dest, int size)
{
	const char *temp = dest;
	char ch = '\0';
	for (int i = 0; i < size; ++i) {
		ch = *(temp);
		myPushBack(ch);
		temp += 1;
	}
}

void myString::Prepend(const char *dest, int size)
{
	//cout << "m_size : " << m_size << endl;
	const char *pos = dest;
	if (m_capacity < (m_size + size)) {
		Reserve(size + m_size);
	}
	int temp = m_size;
	if (NULL != m_str) {
		for (int i = size + m_size; i > size; --i) {
			m_str[i] = m_str[temp--];
		}

		for (int j = 0; j < size; ++j) {
			m_str[j] = pos[j];
			++m_size;
		}
	}
}

void myString::Chop(int size)
{
	if (size <= m_size)
	{
		memset(m_str + (m_size - size), '\0', size);
	}
	m_size -= size;
}

int myString::Contains(const char *data, int size)
{
	if (m_str == NULL || m_size < size)
		return -1;

	int begin = 0;
	int len = size;
	while (begin < m_size)
	{
		int i = 0;
		int start = begin;
		while (m_str[start] == data[i])
		{
			++i;
			++start;
			if (i == len) {
				return begin;
			}
		}
		++begin;
	}
	return -1;
}

list<string> myString::Split(const char *delim)
{
	static list <string> List;
	char *tok;
	if (m_str == NULL || m_size <= 0 || delim == NULL)
		return List;

	const char *flag = delim;
	tok = strtok(m_str, flag);
	while (tok != NULL) {
		string temp = tok;
		//cout << temp << endl;
		List.push_back(temp);
		tok = strtok(NULL, flag);
	}
	return List;
}

ostream &operator<<(ostream &os, const myString &c)
{
	/*for (int i = 0; i < c.m_size; ++i) {
		os << c.m_str[i];
	}*/
	int i = 0;
	while (c.m_str[i] != ' ' && i < c.m_size) {   //os << c.m_str[i];
		/*if (c.m_str[i] != '\0' || c.m_str[i] != '\\0') {
			os << "\\0";
		}*/
		os << c.m_str[i];
		i++;
	}
	os << "    " << "size:" << c.m_size << " " << "capicity:" << c.m_capacity << endl;
	os << endl;
	return os;
}