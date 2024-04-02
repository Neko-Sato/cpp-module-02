/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:27:40 by hshimizu          #+#    #+#             */
/*   Updated: 2024/04/03 03:38:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	std::cout << bsp(Point(0.f, -1.f), Point(1.f, 1.f), Point(-1.f, 1.f), Point(0.f, 0.f)) << std::endl;
	std::cout << bsp(Point(0.f, -1.f), Point(1.f, 1.f), Point(-1.f, 1.f), Point(0.f, -1.f)) << std::endl;
	std::cout << bsp(Point(0.f, -1.f), Point(1.f, 1.f), Point(-1.f, 1.f), Point(0.f, 1.f)) << std::endl;
	std::cout << bsp(Point(0.f, -1.f), Point(1.f, 1.f), Point(-1.f, 1.f), Point(0.f, 0.99f)) << std::endl;
	std::cout << bsp(Point(0.f, -1.f), Point(1.f, 1.f), Point(-1.f, 1.f), Point(0.f, -2.f)) << std::endl;
}
