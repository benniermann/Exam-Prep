#ifndef TASK2_BANK_H
#define TASK2_BANK_H

#define MAX_OWNER_LEN 64
#define MAX_ACCOUNTS  100

/*
 * Aufgabe 2: Structs -- Bankkonto-Verwaltung
 *
 * Implementiere die folgenden Funktionen in task2_bank.c
 */

typedef enum {
    ACCOUNT_CHECKING = 0,
    ACCOUNT_SAVINGS  = 1
} AccountType;

typedef struct {
    int         id;
    char        owner[MAX_OWNER_LEN];
    AccountType type;
    double      balance;
} Account;

/*
 * Fuehrt eine Einzahlung durch (amount > 0).
 * Gibt 0 bei Erfolg, -1 bei ungueltigem Betrag oder NULL-Zeiger zurueck.
 */
int account_deposit(Account *a, double amount);

/*
 * Fuehrt eine Auszahlung durch (amount > 0).
 * Schlaegt fehl wenn der Kontostand danach negativ waere.
 * Gibt 0 bei Erfolg, -1 bei Fehler zurueck.
 */
int account_withdraw(Account *a, double amount);

/*
 * Gibt einen Zeiger auf das Konto mit dem hoechsten Kontostand zurueck.
 * Bei Gleichstand: das mit dem niedrigeren Index.
 * n <= 0 oder NULL -> NULL
 */
Account *find_richest(Account *accounts, int n);

/*
 * Berechnet den Gesamtkontostand aller Konten eines bestimmten Typs.
 * NULL -> 0.0
 */
double total_balance_by_type(const Account *accounts, int n, AccountType type);

/*
 * Transferiert 'amount' von Konto 'from' nach Konto 'to'.
 * Schlaegt fehl wenn from oder to NULL sind, amount <= 0,
 * oder der Kontostand von 'from' nicht ausreicht.
 * Gibt 0 bei Erfolg, -1 bei Fehler zurueck.
 * Wichtig: Bei Fehler bleibt der Zustand beider Konten unveraendert.
 */
int account_transfer(Account *from, Account *to, double amount);

#endif /* TASK2_BANK_H */
