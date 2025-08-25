/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:25:25 by moboulan          #+#    #+#             */
/*   Updated: 2025/08/25 20:33:43 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "bigint.hpp"


static std::string convert(unsigned int n)
{
    std::stringstream ss;

    ss << n;
       
    return (ss.str());
}

bigint::bigint(void) : _n("0")
{
    
}

bigint::bigint(const bigint &obj) : _n(obj._n)
{
    
}

bigint &bigint::operator=(const bigint &obj)
{
    if (this != &obj)
        _n = obj._n;
    return (*this);
}

bigint::~bigint(void)
{
    
}

bigint::bigint(unsigned int n)
{
    _n = convert(n);
}


std::string bigint::getN(void) const
{
    return (_n);
}

static std::string reverse(const std::string &str)
{
    std::string rev = str;

    std::reverse(rev.begin(), rev.end());
    return (rev);
}

static std::string addition(const std::string &num1, const std::string &num2)
{

    std::string first = reverse(num1), second = reverse(num2), sum = "";
    int carry = 0;

    for (int i = 0, j = 0; carry || i < first.length() || j < second.length(); i++, j++)
    {
        int first_n = 0;
        if (i < first.length())
            first_n = first[i] - '0';
        
        int second_n = 0;
        if (j < second.length())
            second_n = second[j] - '0';
        
        int current = first_n + second_n + carry;
        
        sum += (current % 10) + '0';
        carry = current / 10;
    }

    return (reverse(sum));
}


bigint bigint::operator+(const bigint &obj) const
{
    bigint tmp;

    tmp._n = addition(_n, obj._n);
    return(tmp);
}

bigint bigint::operator+(int n) const
{
    bigint tmp;

    tmp._n = addition(_n, convert(n));
    return(tmp);
}

bigint &bigint::operator++(void)
{
    _n = addition(_n, "1");
    return (*this);
}

bigint bigint::operator++(int)
{
    bigint tmp = *this;

    ++(*this);
    return (tmp);
}

bigint &bigint::operator+=(const bigint &obj)
{
    _n = addition(_n, obj._n);
    return (*this);    
}

bigint bigint::operator<<(int n) const
{
    bigint tmp = *this;

    if (_n != "0" && n > 0)
        tmp._n.append(n, '0');
    return (tmp);
    
}
bigint &bigint::operator<<=(int n)
{
    if (_n != "0" && n > 0)
        _n.append(n, '0');
    return (*this); 
}

bigint &bigint::operator>>=(int n)
{
    if (n > 0)
    {
        if (n >= _n.length())
            _n = "0";
        else
            _n.erase(_n.length() - n);
    }
    return (*this);
}
bigint &bigint::operator>>=(const bigint &obj)
{
    std::stringstream ss;

    unsigned int n;

    ss << obj._n;
    
   
    if (!(ss >> n))
        throw  std::runtime_error("too big");
    *this >>= n;
    return (*this);
}

bool bigint::operator==(const bigint &obj) const
{
    return (_n == obj._n);
}

bool bigint::operator!=(const bigint &obj) const
{
    return (!(*this == obj));
}

bool bigint::operator<(const bigint &obj) const
{
    if (_n.length() < obj._n.length())
        return (true);
    else if (_n.length() > obj._n.length())
        return (false);
    else
        return (_n < obj._n);
}

bool bigint::operator<=(const bigint &obj) const
{
    return (*this < obj || *this == obj);
}

bool bigint::operator>(const bigint &obj) const
{
    return (!(*this < obj) && !(*this == obj));
}

bool bigint::operator>=(const bigint &obj) const
{
    return (!(*this < obj));
}

std::ostream &operator<<(std::ostream &str, const bigint &obj)
{
    str << obj.getN();
    return (str);
}