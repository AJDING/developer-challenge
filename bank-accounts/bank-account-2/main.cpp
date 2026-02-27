#include <iostream>
#include <cstring>

using namespace std;

struct person
{
    int bankaccountNum;
    int bankaccountRoute;
    char firstName[20];
    char lastName[20];
    char DOB[20];
    int amount;
};

int availableIndex[5]; // slots available for customer bank accounts

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
            cout << "Slot Index : " << i << endl;

            cout << "Enter First Name: ";
            cin >> inputString;
            strcpy(pNewPerson->firstName, inputString);

            cout << "Enter Last Name: ";
            cin >> inputString;
            strcpy(pNewPerson->lastName, inputString);

            cout << "Hello " << pNewPerson->firstName << " " << pNewPerson->lastName << endl;
            pNewPerson->bankaccountNum = rand();
            cout << "Your account number is " << pNewPerson-bankaccountNum << endl;

            cout << "Enter Date of Birth (DOB)(MMDDYYYY): ";
            cin >> inputString;
            strcpy(pNewPerson->DOB, inputString);

            cout << "Amount: " << pNewPerson->amount << endl;

            break;
        }
        else
        {
            cout << "Sorry. All account slots are taken. Please come back another time." << endl;

            break;
        }
    }
}

int customerRemove()
{
    char inputString[10];
    cout << "Enter Bank Account Number: ";
    cin >> inputString;
    int inputBankAccount = atoi(inputString);

    struct person *pExistingPerson; // QUESTION

    for(int j = 0; j < 5; j++)
    {
        pExistingPerson = &pBankCustomer[i]; // QUESTION

        if (availableIndex[j] == 1 && pExistingPerson->bankaccountNum == inputBankAccount)
        {
            cout << "Hello " << pExistingPerson->firstName << " " << pExistingPerson->lastName << endl;
            cout << "Your Bank Account Number is " << pExistingPerson->bankaccountNum;
            cout << "Amount: " << pExistingPerson->amount << endl;
            cout << "Are you sure you wish to remove account?" << endl;
            cout << "1 - Yes" << endl;
            cout << "2 - No" << endl;
            cout << "Input a choice: ";
            cin >> inputString;
            int input - atoi(inputString);

            swtich(input)
            {
                case 1:
                    cout << "Yes" << endl;
                    availableIndex[i] = 0;
                    break;

            }
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
    cout << "1 - Create Account" << endl;
    cout << "2 - Remove Account" << endl;
    cout << "3 - Deposit Account" << endl;
    cout << "4 - Withdraw Account" << endl;
    cout << "5 - Exit" << endl;
    cout << "6 - Administrative View" << endl;
    cout << "Input a choice: ";

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
            cout << "Deposit" <<endl;
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

    return 0;
}
