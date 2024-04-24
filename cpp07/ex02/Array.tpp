/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:49:30 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/20 15:49:31 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _array(new T[0]), _length(0) { }

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _length(n) { }

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
	_length = copy.length();
	_array = new T[_length];
	for (unsigned int i = 0; i < _length; i++)
		_array[i] = copy._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy)
{
	if (this != &copy)
	{
		delete [] _array;
		_length = copy.length();
		_array = new T[_length];
		for (unsigned int i = 0; i < _length; i++)
			_array[i] = copy._array[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](int index)
{
	if (index < 0 || index >= (int)length())
		throw OutOfRangeException();
	return (_array[index]);
}

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template <typename T>
unsigned int Array<T>::length() const
{
	return (_length);
}

template <typename T>
const char* Array<T>::OutOfRangeException::what() const throw()
{
	return ("Index out of range");
}

template <typename T>
std::ostream& operator<<(std::ostream&os, Array<T>& f)
{
	os << "[";
	for (unsigned int i = 0; i < f.length(); i++)
	{
		os << f[i];
		if (i < f.length() - 1)
			os << ", ";
	}
	os << "]";
	return (os);
}