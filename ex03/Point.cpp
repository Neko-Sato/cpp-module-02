/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 05:43:18 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/03 03:27:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point::~Point(void) {}

Point Point::operator=(const Point &point)
{
	return (point);
}

Point Point::operator+(const Point &point) const
{
	return Point(_x + point._x, _y + point._y);
}

Point Point::operator-(const Point &point) const
{
	return Point(_x - point._x, _y - point._y);
}

Fixed Point::operator*(const Point &point) const
{
	return _x * point._y - _y * point._x;
}