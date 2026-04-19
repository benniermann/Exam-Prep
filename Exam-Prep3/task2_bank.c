#include "task2_bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

int account_deposit(Account *a, double amount) 
{
    if(a == NULL || amount < 0) return -1;
    
    a->balance += amount;

    return 0;
}

int account_withdraw(Account *a, double amount) 
{
    if(a == NULL || amount < 0) return -1;
    
    if(a->balance - amount < 0) return -1;

    a->balance -= amount;

    return 0;
}

Account *find_richest(Account *accounts, int n) 
{
    if(n <= 0 || accounts == NULL) return NULL;

    int richest = accounts[0].balance;
    int index = 0;

    for(int i = 1; i < n; i++)
    {
        if(accounts[i].balance > richest)
        {
            richest = accounts[i].balance;
            index = i;
        }
    }
    
    return &accounts[index];
}

double total_balance_by_type(const Account *accounts, int n, AccountType type) 
{
    if(n <= 0 || accounts == NULL) return 0.0;

    double balance = 0;

    for(int i = 0; i < n; i++)
    {
        if(accounts[i].type == type)
        {
            balance += accounts[i].balance;
        }
    }

    return balance;
}

int account_transfer(Account *from, Account *to, double amount) 
{
    if(from == NULL || to == NULL || amount <= 0 || from->balance < amount) return -1;

    from->balance -= amount;
    to->balance += amount;

    return 0;
}