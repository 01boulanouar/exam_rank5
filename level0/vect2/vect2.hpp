/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:46:43 by moboulan          #+#    #+#             */
/*   Updated: 2025/08/27 18:05:08 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP

#define VECT2_HPP

#include <iostream>

class vect2
{
    private:
        int _x;
        int _y;
    public:
        vect2(void);
        vect2(const vect2 &obj);
        vect2 &operator=(const vect2 &obj);
        ~vect2(void);

        vect2(int x, int y);

        int getX() const;
        int getY() const;
        
        vect2 &operator++();
        vect2 operator++(int);
        
        vect2 &operator--();
        vect2 operator--(int);

        vect2 &operator+=(const vect2 &obj);
        vect2 &operator-=(const vect2 &obj);
        vect2 &operator*=(const vect2 &obj);
        vect2 &operator*=(int n);

        vect2 operator-(const vect2 &obj) const;
        vect2 operator+(const vect2 &obj) const;
        vect2 operator*(const vect2 &obj) const;
        vect2 operator*(int n) const;

        vect2 operator-(void) const;

        int &operator[](int index);
        const int &operator[](int index) const;

        bool operator==(const vect2 &obj) const;
        bool operator!=(const vect2 &obj) const;
};

vect2 operator*(int n, const vect2 &obj);
std::ostream &operator<<(std::ostream &str, const vect2 &obj);

#endif