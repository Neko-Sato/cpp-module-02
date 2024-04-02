/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:27:40 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/03 03:50:48 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	std::cout << bsp(Point(-4.f, 6.f), Point(2.f, -8.f), Point(14.f, 16.f), Point(0.f, 8.222f)) << std::endl;
	std::cout << bsp(Point(-4.f, 6.f), Point(2.f, -8.f), Point(14.f, 16.f), Point(0.f, 8.223f)) << std::endl;
	std::cout << bsp(Point(0.f, -1.f), Point(1.f, 1.f), Point(-1.f, 1.f), Point(0.f, 0.f)) << std::endl;
	std::cout << bsp(Point(0.f, -1.f), Point(1.f, 1.f), Point(-1.f, 1.f), Point(0.f, -1.f)) << std::endl;
	std::cout << bsp(Point(0.f, -1.f), Point(1.f, 1.f), Point(-1.f, 1.f), Point(0.f, 1.f)) << std::endl;
	std::cout << bsp(Point(0.f, -1.f), Point(1.f, 1.f), Point(-1.f, 1.f), Point(0.f, 0.99f)) << std::endl;
	std::cout << bsp(Point(0.f, -1.f), Point(1.f, 1.f), Point(-1.f, 1.f), Point(0.f, -2.f)) << std::endl;
}
