#include <stdio.h>
#include <string.h>
typedef struct {
    char accountHolder[50];
    int accountNumber;
    float balance;
} Account;
void createAccount(Account *account);
void displayBalance(const Account *account);
void deposit(Account *account);
void withdraw(Account *account);
void closeAccount(Account *account);
int main() {
    Account userAccount = {"", 0, 0.0};
    int choice;
    printf("=== Welcome to the Online Banking System ===\n");
    do {
        printf("\nMenu:\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Close Account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createAccount(&userAccount);
            break;
        case 2:
            displayBalance(&userAccount);
            break;
        case 3:
            deposit(&userAccount);
            break;
        case 4:
            withdraw(&userAccount);
            break;
        case 5:
            closeAccount(&userAccount);
            break;
        case 6:
            printf("Thank you for using the Online Banking System. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void createAccount(Account *account) {
    if (account->accountNumber != 0) {
        printf("An account already exists. Please close it before creating a new one.\n");
        return;
    }
    printf("Enter account holder's name: ");
    scanf(" %[^\n]%*c", account->accountHolder);
    printf("Enter account number: ");
    scanf("%d", &account->accountNumber);
    account->balance = 0.0;  // Initial balance is zero
    printf("Account created successfully!\n");
}

void displayBalance(const Account *account) {
    if (account->accountNumber == 0) {
        printf("No account found. Please create an account first.\n");
        return;
    }
    printf("Account Holder: %s\n", account->accountHolder);
    printf("Account Number: %d\n", account->accountNumber);
    printf("Current Balance: $%.2f\n", account->balance);
}

void deposit(Account *account) {
    if (account->accountNumber == 0) {
        printf("No account found. Please create an account first.\n");
        return;
    }
    float amount;
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Deposit amount must be greater than zero.\n");
    } else {
        account->balance += amount;
        printf("Deposit successful! New balance: $%.2f\n", account->balance);
    }
}

void withdraw(Account *account) {
    if (account->accountNumber == 0) {
        printf("No account found. Please create an account first.\n");
        return;
    }
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Withdrawal amount must be greater than zero.\n");
    } else if (amount > account->balance) {
        printf("Insufficient balance. Transaction declined.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful! New balance: $%.2f\n", account->balance);
    }
}

void closeAccount(Account *account) {
    if (account->accountNumber == 0) {
        printf("No account found to close.\n");
        return;
    }
    printf("Closing account for %s (Account Number: %d)...\n", account->accountHolder, account->accountNumber);
    strcpy(account->accountHolder, "");
    account->accountNumber = 0;
    account->balance = 0.0;
    printf("Account closed successfully.\n");
}
