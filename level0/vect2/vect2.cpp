/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:46:42 by moboulan          #+#    #+#             */
/*   Updated: 2025/08/27 18:05:13 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2(void) : _x(0), _y(0)
{

}

vect2::vect2(const vect2 &obj): _x(obj._x), _y(obj._y)
{

}

vect2 &vect2::operator=(const vect2 &obj)
{
    if (this != &obj)
    {
        _x = obj._x;
        _y = obj._y;
    }
    return (*this);
}

vect2::~vect2(void)
{

}

vect2::vect2(int x, int y): _x(x), _y(y)
{
    
}

int vect2::getX(void) const
{
    return (_x);
}

int vect2::getY(void) const
{
    return (_y);
}

std::ostream &operator<<(std::ostream &str, const vect2 &obj)
{
    str << "{" << obj.getX() << ", " << obj.getY() << "}";
    return (str);
}

vect2 &vect2::operator++(void)
{
    _x++;
    _y++;
    return (*this);
}

vect2 vect2::operator++(int)
{
    vect2 tmp = *this;
    ++(*this);
    return (tmp);    
}

vect2 &vect2::operator--(void)
{
    _x--;
    _y--;
    return (*this);
}

vect2 vect2::operator--(int)
{
    vect2 tmp = *this;
    --(*this);
    return (tmp);   
}

vect2 &vect2::operator+=(const vect2 &obj)
{
    _x += obj._x;
    _y += obj._y;
    return (*this);
}

vect2 &vect2::operator-=(const vect2 &obj)
{
    _x -= obj._x;
    _y -= obj._y;
    return (*this);
}

vect2 &vect2::operator*=(const vect2 &obj)
{
    _x *= obj._x;
    _y *= obj._y;
    return (*this);
}

vect2 &vect2::operator*=(int n)
{
    _x *= n;
    _y *= n;
    return (*this);
}

vect2 vect2::operator-(const vect2 &obj) const
{
    vect2 tmp = *this;
    tmp._x -= obj._x;
    tmp._y -= obj._y;
    return (tmp);    
}


vect2 vect2::operator+(const vect2 &obj) const
{
    vect2 tmp = *this;
    tmp += obj;
    return (tmp);    
}

vect2 vect2::operator*(const vect2 &obj) const
{
    vect2 tmp = *this;
    tmp *= obj;
    return (tmp);    
}

vect2 vect2::operator*(int n) const
{
    vect2 tmp = *this;
    tmp *= n;
    return (tmp);    
}

vect2 vect2::operator-(void) const
{

    return (vect2(-_x, -_y));  
}

int &vect2::operator[](int index)
{
    return (index == 0 ? _x : _y);
}

const int &vect2::operator[](int index) const
{
    return (index == 0 ? _x : _y);
}   

bool vect2::operator==(const vect2 &obj) const
{
    return (_x == obj._x && _y == obj._y);
}

bool vect2::operator!=(const vect2 &obj) const
{
    return (!(*this == obj));
}   

vect2 operator*(int n, const vect2 &obj)
{
    vect2 tmp = obj;
    tmp *= n;
    return (tmp);
}
