#include <stdio.h>
#include <stdlib.h>

#include "bank.h"
#include "account.h"

int get_account_index(const Bank *bank, int account_number) {
    int index = -1;
    for (int i=0; i<bank->account_count; i++) {
        if (bank->accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        perror("could not find account to display");
        exit(EXIT_FAILURE);
    }

    return index;
}


void deposit(Bank *bank, int account_number, double amount) {
    int index = get_account_index(bank, account_number);
    bank->accounts[index].balance += amount;
}

void withdraw(Bank *bank, int account_number, double amount) {
    int index = get_account_index(bank, account_number);
    bank->accounts[index].balance -= amount;
}

void transfer(Bank *bank, int from_account, int to_account, double amount) {
    int from_index = get_account_index(bank, from_account);
    int to_index = get_account_index(bank, to_account);

    bank->accounts[from_index].balance -= amount;
    bank->accounts[to_index].balance += amount;
}