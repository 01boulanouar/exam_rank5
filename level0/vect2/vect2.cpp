/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:26:41 by moboulan          #+#    #+#             */
/*   Updated: 2025/08/25 13:12:08 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2(void) : _x(0), _y(0)
{
      
}

vect2::vect2(int x, int y): _x(x), _y(y)
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
    return(*this);
}

vect2::~vect2(void)
{
    
}

const int &vect2::operator[](int n) const
{
    return (n == 0 ? _x : _y);  
}

int &vect2::operator[](int n)
{
    return (n == 0 ? _x : _y);
}

vect2 vect2::operator-(const vect2 &obj) const
{
     return (vect2(_x - obj._x, _y - obj._y));
}

vect2 vect2::operator+(const vect2 &obj) const
{
    return (vect2(_x + obj._x, _y + obj._y));
}

vect2 vect2::operator*(const vect2 &obj) const
{
    return (vect2(_x * obj._x, _y * obj._y));
}


vect2 vect2::operator-(int n) const
{
     return (vect2(_x - n, _y - n));
}

vect2 vect2::operator+(int n) const
{
    return (vect2(_x + n, _y + n));
}

vect2 vect2::operator*(int n) const
{
    return (vect2(_x * n, _y * n));
}

vect2 vect2::operator-() const
{
    return (vect2(-_x, -_y));
}

vect2 vect2::operator+=(const vect2 &obj)
{
    _x += obj._x;
    _y += obj._y;
    
    return (*this);    
}

vect2 vect2::operator-=(const vect2 &obj)
{
    _x -= obj._x;
    _y -= obj._y;
    
    return (*this); 
}

vect2 vect2::operator*=(const vect2 &obj)
{
    _x *= obj._x;
    _y *= obj._y;
    
    return (*this);    
}

vect2 vect2::operator+=(int n)
{
    _x += n;
    _y += n;
    
    return (*this);        
}

vect2 vect2::operator-=(int n)
{
    _x -= n;
    _y -= n;
    
    return (*this);   
}

vect2 vect2::operator*=(int n)
{
    _x *= n;
    _y *= n;
    
    return (*this);   
}



bool vect2::operator==(const vect2 &obj)
{
    return (_x == obj._x && _y == obj._y);
}

bool vect2::operator!=(const vect2 &obj)
{
    return (_x != obj._x || _y != obj._y);  
}


vect2 vect2::operator--()
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


vect2 vect2::operator++()
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

int vect2::getX(void) const
{
    return (_x);
}

int vect2::getY(void) const
{
    return (_y);
}

vect2 operator*(int n, const vect2 &obj)
{
    return (vect2(obj.getX() * n, obj.getY() * n));
}

std::ostream &operator<<(std::ostream &str, const vect2 &obj)
{
    str << "{" << obj.getX() << ", " << obj.getY() << "}";
    return (str); 
}

