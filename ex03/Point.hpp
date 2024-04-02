/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 05:36:55 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/03 03:36:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PONT_HPP__
#define __PONT_HPP__

#include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;

public:
	Point(void);
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	Point(const Point &point);
	~Point();

	Point operator=(const Point &point);
	Point operator+(const Point &point) const;
	Point operator-(const Point &point) const;

	Fixed operator*(const Point &point) const;

};

#endif