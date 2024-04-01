/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:27:57 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/02 00:12:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
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
	friend std::ostream &operator<<(std::ostream &out, const Fixed &value);

	int getRawBits(void) const;
	void setRawBFits(int const raw);

	int toInt(void) const;
	float toFloat(void) const;
};

#endif
