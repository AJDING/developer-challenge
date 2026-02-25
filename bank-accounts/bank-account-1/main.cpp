#include <iostream>
#include <cstring>

using namespace std;

struct person
{
    int bankaccountNum;
    // int bankaccountRoute;
    char firstName[20];
    char lastName[20];
    int amount;
};

int availableIndex[5];

struct person *pBankCustomer; // global variable

int customerAdd()
{
    struct person * pNewPerson;

    char inputString[10];

    for(int i = 0; i < 5; i++)
    {
        if (availableIndex[i] == 0)
        {
            pNewPerson = &pBankCustomer[i];
            availableIndex[i] = 1;
            cout << "Slot Index: " << i << endl;

            cout << "Enter First Name: ";
            cin >> inputString;
            strcpy(pNewPerson->firstName, inputString);

            cout << "Enter Last Name: ";
            cin >> inputString;
            strcpy(pNewPerson->lastName, inputString);

            cout << "Hello " << pNewPerson->firstName << " " <<pNewPerson->lastName << endl;
            pNewPerson->bankaccountNum = rand();
            cout << "Your account number is " << pNewPerson->bankaccountNum << endl;

            cout << "Enter Date of Birthday (DOB)(MMDDYYYY): ";
            cin >> inputString;
            strcpy(pNewPerson->DOB, inputString);

            cout << "Deposit Amount: ";
            cin >> inputString;
            pNewPerson->amount = atoi(inputString);

            cout << "Amount: " << pNewPerson->amount << endl;

            break;
        }
    }
}

int customerRemove()
{
    struct person * pExistingPerson;

    char inputString[10];
    cout << "Enter Bank Account Number: ";
    cin >> inputString;
    int inputBankAccount = atoi(inputString);

    for(int i = 0; i < 5; i++)
    {
        pExistingPerson = &pBankCustomer[i];

        if (availableIndex[i] == 1 && pExistingPerson->bankaccountNum == inputBankAccount)
        {

        }
    }
}

int deposit()
{

}

int withdraw()
{

}

int admin()
{

}


int main()
{
    char inputString[10]; // define initial inputString parameters

    while(1)
    {
        cout << "1 - Create Account" << endl;
        cout << "2 - Remove Account" << endl;
        cout << "3 - Deposit Account" << endl;
        cout << "4 - Withdraw Account" << endl;
        cout << "5 - Exit" << endl;
        cout << "6 - Administrative View" << endl;
        cout << "1 - Input a choice: ";

        cin >> inputString;

        int input;

        switch(input)
        {
            case 1:
                cout << "Create Account" << endl;
                customerAdd();
                break;
            case 2:
                cout << "Remove Account" << endl;
                customerRemove();
                break;
            case 3:
                cout << "Deposit" << endl;
                deposit();
                break;
            case 4:
                cout << "Withdraw" << endl;
                withdraw();
                break;
            case 5:
                cout << "Exit" << endl;
                exit = true;
                break;
            case 6:
                cout << "Administrative View" << endl;
                admin();
                break;
            default:
                break;
        }
        if(exit == true)
        {
            break;
        }
    }

    free(pBankCustomer);

    return 0;
}
