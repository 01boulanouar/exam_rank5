/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:10:57 by moboulan          #+#    #+#             */
/*   Updated: 2025/08/25 13:02:16 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP

# define VECT2_HPP

# include <iostream>

class vect2
{
    private:
        int _x;
        int _y;
    public:
        vect2(void);
        vect2(int x, int y);
        vect2(const vect2 &obj);
        vect2 &operator=(const vect2 &obj);
        ~vect2(void);


        const int &operator[](int n) const;
        int &operator[](int n);

        vect2 operator-(const vect2 &obj) const;
        vect2 operator+(const vect2 &obj) const;
        vect2 operator*(const vect2 &obj) const;
        vect2 operator-() const;

        vect2 operator-(int n) const;
        vect2 operator+(int n) const;
        vect2 operator*(int n) const;

        vect2 operator+=(const vect2 &obj);
        vect2 operator-=(const vect2 &obj);
        vect2 operator*=(const vect2 &obj);
        vect2 operator+=(int n);
        vect2 operator-=(int n);
        vect2 operator*=(int n);


        bool operator==(const vect2 &obj);
        bool operator!=(const vect2 &obj);

        vect2 operator--();
        vect2 operator--(int);
        
        vect2 operator++();
        vect2 operator++(int);

        int getX(void) const;
        int getY(void) const;

};

vect2 operator*(int n, const vect2 &obj);
std::ostream &operator<<(std::ostream &str, const vect2 &obj);

#endif