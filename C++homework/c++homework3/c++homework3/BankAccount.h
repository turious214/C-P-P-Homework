#pragma once
class BankAccount
{
	double balance;

public:
	inline BankAccount(double balance) {
		this->balance = balance;
	}

	inline void deposit(double num) {
		this->balance += num;
	}

	inline void withdraw(double num) {
		this->balance -= num;
	}

	inline double getBalance() {
		return this->balance;
	}
};

