#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "bank.h"

typedef struct
{
    int account_number;
    char name[100];
    double balance;
} Account;

typedef struct Bank Bank; // Forward declaration

void deposit(Bank *bank, int account_number, double amount);
void withdraw(Bank *bank, int account_number, double amount);
void transfer(Bank *bank, int from_account, int to_account, double amount);
int get_account_index(const Bank *bank, int account_number);

#endif

