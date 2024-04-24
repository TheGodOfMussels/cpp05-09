/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimolin2 <dimolin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:04:50 by dimolin2          #+#    #+#             */
/*   Updated: 2024/02/13 16:04:50 by dimolin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DATA_HPP
# define DATA_HPP

class Data
{
	private:
		const int _num;
	public:
		Data();
		Data(int n);
		Data(Data const &src);
		Data &operator=(Data const &src);
		~Data();

		int getNum() const;
};

#endif