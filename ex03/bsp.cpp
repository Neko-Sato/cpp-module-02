/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 05:54:57 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/03 03:39:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point ab(b - a), bc(c - b), ca(a - c);
	Point ap(point - a), bp(point - b), cp(point - c);
	Fixed p[] = {ca * ap, ab * bp, bc * cp};

	return (p[0] > 0 && p[1] > 0 && p[2] > 0) || (p[0] < 0 && p[1] < 0 && p[2] < 0);
}