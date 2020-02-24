/* 
 * File:   main.cpp
 * Author: Alex
 *
 * 
 */

#include <cstdlib>
#include <iostream>

int balance = 5000;
int receipt;
int withdrawalLimit = 1000;
int depositLimit = 10000;
int transactions= 0;

int withdrawal(){
    int withdrawalAmount;
    int withdrawalAttempts =1;
    std::cout<< "Your current withdrawal limit is: " << withdrawalLimit <<". ";
    std::cout<< "Enter the amount to withdraw in a multiple of 20: ";
    std::cin >> withdrawalAmount;
    while(withdrawalAttempts <=3)
    {
        if(withdrawalAttempts == 3)
        {
            std::cout<< "Error. Too many invalid tries. Exiting ATM.";
            exit(0);
        }
        else if(withdrawalAmount <= 0){
            std::cout<<"Invalid entry. Please try again:";
            withdrawalAttempts++;
            std::cin>> withdrawalAmount;
        }
        else if(withdrawalAmount % 20 != 0){
            std::cout<<"Invalid entry. Please try again:";
            withdrawalAttempts++;
            std::cin>> withdrawalAmount;
        }
        else if(withdrawalAmount > withdrawalLimit){
            std::cout<<"Invalid entry. Please try again:";
            withdrawalAttempts++;
            std::cin>> withdrawalAmount;
        }
        else if(withdrawalAmount > balance){
            std::cout<<"Invalid entry. Please try again:";
            withdrawalAttempts++;
            std::cin>> withdrawalAmount;
        }
        
        else{
            balance -= withdrawalAmount;
            withdrawalLimit -= withdrawalAmount;
            std::cout<< "Would you like a receipt? \n1. Yes \n2. No\n";
            std::cin >> receipt;
            return balance;
        }
    }
}

int deposit(){
    int depositAmount;
    int depositAttempts =1;
    std::cout<< "Your current deposit limit is " << depositLimit;
    std::cout<< "Enter the amount you would like to deposit: ";
    std::cin>> depositAmount;
    while(depositAttempts <=3){
        if(depositAttempts ==3){
            std::cout<< "Error. Too many invalid tries. Exiting ATM.";
            exit(0);
        }
        else if(depositAmount<= 0){
            std::cout<< "Invalid entry. Please try again:";
            depositAttempts++;
            std::cin>> depositAmount;
        }
        else if(depositAmount > depositLimit){
            std::cout<< "Invalid entry. Please try again:";
            depositAttempts++;
            std::cin>> depositAmount;
        }
        else{
            balance += depositAmount;
            depositLimit -= depositAmount;
            std::cout<< "Would you like a receipt? \n1. Yes \n2. No\n";
            std::cin >> receipt;
            return balance;
        }
    }
}

void checkBalance(int balance){
    std::cout<< "Your current balance is: " << balance << ". ";
    std::cout<< "Would you like a receipt? \n1. Yes \n2. No\n";
    std::cin>> receipt;
    return;
}

void quit()
{
    std::cout<< "Thank you for choosing WCUPA bank. Today you made " << transactions <<
            "transactions.";
    exit(0);
}
int main(int argc, char** argv) {

    int pin = 3014;
    int pinTry;
    int pinTries = 1;
    int options;
    int options2;
    std::cout<< "Welcome to WCUPA Bank. Please enter your PIN:";
    std::cin>> pinTry;
    while(pinTries<= 3){
        if(pin == pinTry){
            std::cout<< "Hello Nana. Which transaction would you like to perform?: \n";
            std::cout<< "1. Balance \n2. Withdrawal\n3. Deposit \n4. Quit\n";
            std::cin>> options;
            while(options <= 4){
                switch(options){
                    case 1:
                        checkBalance(balance);
                        transactions++;
                        break;
                    case 2:
                        withdrawal();
                        transactions++;
                        break;
                    case 3:
                        deposit();
                        transactions++;
                        break;
                    case 4:
                        exit(0);
                        break;
                }
                std::cout << "Would you like to perform another transaction? \n1. Yes"
                    "\n2. No\n";
                std::cin >> options2;
                if(options2 == 1)
                {
                    std::cout << "Which transaction would you like to perform?\n";
                    std::cout << "1. Balance \n2. Withdrawal\n3. Deposit \n4. Quit\n";
                    std::cin >> options;        
                }
                else{
                    exit(0);
                }
            }
        }
    }
    if(pinTries == 3){
        std::cout<< "You have exceeded the number of tries for you PIN.\n"
                    "Your account will be suspended for the day\n";
        exit(0);
    }
    if(pin != pinTry){
        std::cout<< "You have entered an incorrect PIN. Please try again:";
        std::cin >> pinTry;
        pinTries++;
    }
}

