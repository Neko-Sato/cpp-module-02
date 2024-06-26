/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:36:23 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/25 17:36:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed(void) : _raw(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value) {
  std::cout << "Copy constructor called" << std::endl;
  *this = value;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  _raw = value << _fixed_point;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;

  const unsigned int &temp = reinterpret_cast<const unsigned int &>(value);
  int result = 0;
  bool isnegative = value < 0;
  int exp = temp >> 23 & 0xFF;
  if (exp == 0x0 && !(temp & ((1 << 23) - 1))) {
    _raw = 0;
    return;
  } else if (exp == 0xFF)
    throw std::runtime_error("Fixed initialize error");
  {
    bool do_roundup = false;
    size_t i = 0, j = 0;
    if (exp - 0x7F - 23 < -_fixed_point) {
      j = -_fixed_point - (exp - 0x7F - 23);
      do_roundup = temp >> (j - 1) & 1;
    }
    for (; i < 32 - 1 && j < 23; i++, j++) result |= (temp >> j & 1) << i;
    if (i < 32 - 1) result |= 1 << i;
    if (do_roundup) isnegative ? result-- : result++;
  }
  if (isnegative) result = -result;
  _raw = result;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &value) {
  std::cout << "Copy assignment operator called" << std::endl;
  _raw = value._raw;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _raw;
}

void Fixed::setRawBFits(int const raw) {
  std::cout << "setRawBFits member function called" << std::endl;
  _raw = raw;
}

int Fixed::toInt(void) const {
  return (_raw >> _fixed_point) +
         (_raw < 0 && _raw & ((1 << _fixed_point) - 1) ? 1 : 0);
}

float Fixed::toFloat(void) const {
  if (!_raw) return 0;
  int temp = _raw;
  bool isnegative = temp < 0;
  if (isnegative) temp = -temp;
  int exp;
  {
    size_t i = 30;
    while (i && !(temp >> i & 1)) i--;
    temp = 23 < i ? temp >> (i - 23) : temp << (23 - i);
    temp &= (1 << 23) - 1;
    exp = 0x7F - _fixed_point + i;
  }
  temp |= (exp & 0xFF) << 23;
  if (isnegative) temp |= 1 << 31;
  return reinterpret_cast<float &>(temp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
  return out << value.toFloat();
}
