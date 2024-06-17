#ifndef FILEIO_H
#define FILEIO_H

#include "bank.h";

void save_accounts(const Bank *bank, const char *filename);
void load_accounts(Bank *bank, const char *filename);

#endif