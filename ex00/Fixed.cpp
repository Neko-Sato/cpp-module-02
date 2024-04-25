/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:30:16 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/25 17:30:18 by hshimizu         ###   ########.fr       */
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

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &value) {
  std::cout << "Copy assignment operator called" << std::endl;
  _raw = value.getRawBits();
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
