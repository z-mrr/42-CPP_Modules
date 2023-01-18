/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:04:22 by jdias-mo          #+#    #+#             */
/*   Updated: 2023/01/18 16:58:01 by jdias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit) :
_accountIndex(_nbAccounts), _amount(_totalAmount),
_nbDeposits(_totalNbDeposits), _nbWithdrawals(_totalNbWithdrawals)
{
	_nbAccounts += 1;
	_totalAmount += initial_deposit;
}

