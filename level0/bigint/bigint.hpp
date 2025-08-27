/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:25:13 by moboulan          #+#    #+#             */
/*   Updated: 2025/08/26 11:25:06 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP

# define BIGINT_HPP

# include <iostream>
# include <sstream>

class bigint
{
    private:
       std::string _n;
    public:
        bigint(void);
        bigint(const bigint &obj);
        bigint &operator=(const bigint &obj);
        ~bigint(void);

        bigint(unsigned int n);

        std::string getN(void) const;

        bigint operator+(const bigint &obj) const;
        bigint operator+(int n) const;

        bigint &operator++(void);
        bigint operator++(int);
        
        bigint &operator+=(const bigint &obj);
        bigint &operator<<=(int n);
        bigint &operator>>=(int n);
        bigint &operator>>=(const bigint &obj);
        
        bigint operator<<(int n) const;

        
        bool operator<(const bigint &obj) const;
        bool operator<=(const bigint &obj) const;
        bool operator>(const bigint &obj) const;
        bool operator>=(const bigint &obj) const;
        bool operator==(const bigint &obj) const;
        bool operator!=(const bigint &obj) const;
    
};

std::ostream &operator<<(std::ostream &str, const bigint &obj);

#endif