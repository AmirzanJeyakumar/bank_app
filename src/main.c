#include <stdio.h>
#include <stdlib.h>
#include "bank.h"
#include "account.h"



int main(void) {
    Bank bank;
    init_bank(&bank);

    // Main menu loop
    int choice;
    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Delete Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Transfer Money\n");
        printf("6. Display Account Details\n");
        printf("7. List All Accounts\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int account_number, from_account, to_account;
        double amount;
        char name[100];

  switch (choice) {
            case 1:
                printf("Enter account holder's name: ");
                scanf("%s", name);
                printf("Enter initial deposit amount: ");
                scanf("%lf", &amount);
                create_account(&bank, name, amount);
                break;
            case 2:
                printf("Enter account number to delete: ");
                scanf("%d", &account_number);
                delete_account(&bank, account_number);
                break;
            case 3:
                printf("Enter account number to deposit into: ");
                scanf("%d", &account_number);
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);
                deposit(&bank, account_number, amount);
                break;
            case 4:
                printf("Enter account number to withdraw from: ");
                scanf("%d", &account_number);
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);
                withdraw(&bank, account_number, amount);
                break;
            case 5:
                printf("Enter source account number: ");
                scanf("%d", &from_account);
                printf("Enter destination account number: ");
                scanf("%d", &to_account);
                printf("Enter transfer amount: ");
                scanf("%lf", &amount);
                transfer(&bank, from_account, to_account, amount);
                break;
            case 6:
                printf("Enter account number to display: ");
                scanf("%d", &account_number);
                display_account(&bank, account_number);
                break;
            case 7:
                list_accounts(&bank);
                break;
            case 8:
                // save_accounts(&bank, "data/accounts.dat");
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
}}