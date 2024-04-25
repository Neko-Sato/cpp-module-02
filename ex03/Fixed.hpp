/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:27:57 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/25 17:31:07 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
 private:
  int _raw;
  static const int _fixed_point = 8;

 public:
  Fixed(void);
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &value);
  ~Fixed();

  Fixed &operator=(const Fixed &value);

  int getRawBits(void) const;
  void setRawBFits(int const raw);

  int toInt(void) const;
  float toFloat(void) const;

  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);

  static const Fixed &max(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &min(Fixed &a, Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
