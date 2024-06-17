#ifndef BANK_H
#define BANK_H

#include "account.h"
#include <stddef.h>

typedef struct Bank
{
    Account *accounts;
    size_t account_count;

} Bank;

void init_bank(Bank *bank);
void list_accounts(const Bank *bank);
void create_account(Bank *bank, const char *name, double initial_balance);
void delete_account(Bank *bank, int account_number);
void display_account(const Bank *bank, int account_number);

#endif 