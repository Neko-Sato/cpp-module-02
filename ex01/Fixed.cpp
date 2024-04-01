/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By;: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:27:52 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/30 10:36:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_raw = value << _fixed_point;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

	int result;
	unsigned int temp;
	bool isnegative;
	int exp;

	result = 0;
	temp = *(unsigned int *)&value;
	isnegative = !!(temp & (1 << 31));
	exp = temp >> 23 & 0xFF;
	if (exp == 0x0 && !(temp & ~(-1u << 22)))
		return;
	else if (exp == 0xFF)
		throw std::runtime_error("Fixed initialize error");
	{
		bool do_roundup;
		size_t i, j;

		do_roundup = false;
		i = j = 0;
		if (exp - 0x7F - 23 < -_fixed_point)
		{
			j = -_fixed_point - (exp - 0x7F - 23);
			if (j && (temp >> (j - 1) & 1))
				do_roundup = true;
		}
		for (; i < 32 - 1 && j < 23; i++, j++)
			result |= (temp >> j & 1) << i;
		if (i < 32 - 1)
			result |= 1 << i++;
		if (do_roundup)
		{
			result += isnegative ? -1 : 1;
			result &= -1u >> 1;
		}
	}
	if (isnegative)
		result = ~(unsigned int)result + 1;
	_raw = result;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_raw = value._raw;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _raw;
}

void Fixed::setRawBFits(int const raw)
{
	std::cout << "setRawBFits member function called" << std::endl;
	_raw = raw;
}

int Fixed::toInt(void) const
{
	return (_raw >> _fixed_point) + (_raw & (1u << 31) ? (_raw & (~(-1u << _fixed_point)) ? 1 : 0) : 0);
}

float Fixed::toFloat(void) const
{
	unsigned int temp;
	bool isnegative;
	int exp;

	*(int *)&temp = _raw;
	isnegative = !!(temp & (1 << 31));
	if (isnegative)
		temp = ~temp + 1;
	{
		size_t i;

		i = 30;
		while (1 < i && !(temp >> i & 1))
			i--;
		i--;
		if (22 < i)
			temp = temp >> (i - 22);
		else
			temp = temp << (22 - i);
		temp &= -1u >> (32 - 23);
		exp = i - _fixed_point - 0x7F - 1;
	}
	temp |= (exp & 0xFF) << 23;
	if (isnegative)
		temp |= 1 << 31;
	return *(float *)&temp;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	return out << value.toFloat();
}