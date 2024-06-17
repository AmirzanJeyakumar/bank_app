#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bank.h"
#include "account.h"

void init_bank(Bank *bank) {
    bank->accounts = NULL;
    bank->account_count = 0;
}

void list_accounts(const Bank *bank) {
    if (bank->account_count == 0) {
        perror("no accounts to list");
    }
    for (int i=0; i<bank->account_count; i++) {
        printf("Account number: %d \n Name: %s \n Balance: %.2f\n",
        bank->accounts[i].account_number,
        bank->accounts[i].name,
        bank->accounts[i].balance);
    }
}

void create_account(Bank *bank, const char *name, double initial_balance) {
    bank->accounts = realloc(bank->accounts, (bank->account_count + 1) * sizeof(Account));

    Account *new_account = &bank->accounts[bank->account_count++];
    new_account->account_number = bank->account_count;
    strcpy(new_account->name, name);
    new_account->balance = initial_balance;
}

void delete_account(Bank *bank, int account_number) {
    int index = get_account_index(bank, account_number);

    for (int i = index; i < bank->account_count - 1; i++) {
        bank->accounts[i] = bank->accounts[i + 1];
    }

    bank->account_count--;
    bank->accounts = realloc(bank->accounts, bank->account_count * sizeof(Account));
    if (bank->account_count > 0 && bank->accounts == NULL) {
        perror("Failed to reallocate memory");
        exit(EXIT_FAILURE);
    }

    printf("Account number %d deleted successfully.\n", account_number);
}

void display_account(const Bank *bank, int account_number) {
    int index = get_account_index(bank, account_number);
    printf("Account number: %d \n Name: %s \n Balance: %.2f\n",
        bank->accounts[index].account_number,
        bank->accounts[index].name,
        bank->accounts[index].balance);
}