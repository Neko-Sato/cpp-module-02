/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:27:57 by hshimizu          #+#    #+#             */
/*   Updated: 2024/03/30 10:40:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

class Fixed
{
private:
	int _raw;
	static const int _fixed_point = 8;

public:
	Fixed(void);
	Fixed(const Fixed &value);
	~Fixed();

	Fixed& operator=(const Fixed &value);

	int getRawBits(void) const;
	void setRawBFits(int const raw);
};

#endif
