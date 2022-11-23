/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:29:22 by fporto            #+#    #+#             */
/*   Updated: 2022/11/23 16:36:32 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CPP
#define ARRAY_CPP

#include <iostream>
#include "color.hpp"
#include <exception>
#include <cstdlib>

template<typename T>
class Array {

private:

	unsigned int	_size;
	T				*_arr;

public:

	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator = (const Array& other);
	~Array();

	unsigned int	size() const ;

	T&			operator [] (unsigned int index);
	const T&	operator [] (unsigned int index) const;

};

template<typename T>
Array<T>::Array() : _size(0), _arr(new T[0]) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _arr(new T[n]) {}

template<typename T>
Array<T>::Array(const Array& other) : _size(other._size), _arr(new T[other._size]) {
	for (unsigned int i = 0; i < other._size ; i++)
		this->_arr[i] = other._arr[i];
}

template<typename T>
Array<T>& Array<T>::operator = (const Array& other) {
	this->_size = other._size;
	delete[] this->_arr;
	this->_arr = new T[other._size];

	for (unsigned int i = 0; _size < 4; i++)
		this->_arr[i] = other._arr[i];

	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete[] this->_arr;
}


template<typename T>
unsigned int	Array<T>::size() const {
	return this->_size;
}

template<typename T>
T&	Array<T>::operator [] (unsigned int index) {
	if (index < 0 || index >= this->_size)
		throw std::exception();
	return this->_arr[index];
}

template<typename T>
const T&	Array<T>::operator [] (unsigned int index) const {
	if (index < 0 || index >= this->_size)
		throw std::exception();
	return this->_arr[index];
}

template <typename T>
std::ostream&	operator << (std::ostream& out, const Array<T>& arr) {
	out << "Array of size " << arr.size() << ":" << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++) {
		out << "  arr[" << i << "]: " << arr[i] << std::endl;
	}
	return out;
}

#endif
