#include "Account.hpp"

int main(){
	Account::displayAccountsInfos();
	Account a(100);
	Account::displayAccountsInfos();
	Account b(200);
	Account::displayAccountsInfos();
	a.makeDeposit(1000);
	a.displayStatus();
	a.makeWithdrawal(500);
	a.displayStatus();
}
