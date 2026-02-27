#include <iostream>
#include <cstring>

// typedef
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

int avail[5]; // slots available for bank accounts

struct person *pBankCustomer; // global variable
// pBankCustomer pointer of struct person, representing an entity of struct person pointing being pointed to by pBankCustomer (which also represents an array that's memory allocated)
// going to be memory allocated entities

// int availableIndex;

// Add Customer
int customerAdd() // parenthesis only for functions
{
    struct person *pNewPerson;
	// pNewPerson a null pointer until assigned to an entity
    // availableIndex++;
    // = &pBankCustomer[availableIndex]; **

    char inputString[10]; // string unlimited at 256 bytes (each character 8-bits), max can crash program in embedded systems

    // increment for available indexes from [0] to [4]
    for(int j = 0; j < 5; j++)
    {
        // == is evaluation
        // =  is assignment
        if (avail[j] == 0)
        {
            pNewPerson = &pBankCustomer[j]; // &pointer to reference pBankCustomer[] **
            // pBankCustomer[j] with index is an entity of type struct or whatever entity type, which means it needs to be referenced
            avail[j] = 1;
            cout << "Slot Index: " << j << endl;

            cout << "Enter First Name: ";
            cin >> inputString;
            strcpy(pNewPerson->firstName, inputString); // pointer reference needs to be arrow for reference in memory allocation in internal data // no arrow space, depends on compiler

            cout << "Enter Last Name: ";
            cin >> inputString;
            strcpy(pNewPerson->lastName, inputString);

            cout << "Hello " << pNewPerson->firstName << " " << pNewPerson->lastName << endl;
            pNewPerson->bankaccountNum = rand();
            cout << "Your account number is " << pNewPerson->bankaccountNum << endl;

            cout << "Enter Date of Birth (DOB)(MMDDYYYY): ";
            cin >> inputString;
            strcpy(pNewPerson->DOB, inputString); // pointer reference needs to be arrow for reference in memory allocation in internal data // no arrow space, depends on compiler

            cout << "Deposit Amount: ";
            cin >> inputString;
            pNewPerson->amount = atoi(inputString);

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

// Remove Customer
int customerRemove()
{
    char inputString[10];
    cout << "Enter Bank Account Number: ";
    cin >> inputString;
    int inputBankAccount = atoi(inputString);

    struct person *pExistingPerson;

    for(int i = 0; i < 5; i++)
    {
        pExistingPerson = &pBankCustomer[i]; // ** // & // either pointer works

        // understand logic if statements and where to put them
        if (avail[i] == 1 && pExistingPerson->bankaccountNum == inputBankAccount) // make sure account is valid && existing account is equal to bank account entered
        {
            cout << "Hello " << pExistingPerson->firstName << " " << pExistingPerson->lastName << endl;
            cout << "Your Bank Account Number is " << pExistingPerson->bankaccountNum;
            cout << "Amount: " << pExistingPerson->amount << endl;
            cout << "Are you sure you wish to remove account?" << endl;
            cout << "1 - Yes" << endl;
            cout << "2 - No" << endl;
            cout << "Input a choice: ";
            cin >> inputString;
            int input = atoi(inputString); // separate int input variable from main

            switch(input)
            {
                case 1:
                    cout << "Yes" << endl;
                    avail[i] = 0;
                    break;
                case 2:
                    cout << "No" << endl;
                    break;
                default:
                    cout << "Invalid Selection";
                    break;
            }
            break;
        }
    }
}

// Deposit
int deposit()
{
    char inputString[10];
    cout << "Enter Bank Account Number: ";
    cin >> inputString;
    int inputBankAccount = atoi(inputString);

    struct person *pExistingPerson;

    cout << "Hello " << pExistingPerson->firstName << " " << pExistingPerson->lastName << endl;
    cout << "Your Bank Account Number is " << pExistingPerson->bankaccountNum;

    cout << "Deposit Amount: ";
    cin >> inputString;
    int depositAmount = atoi(inputString);

    for(int i = 0; i < 5; i++)
    {
        pExistingPerson = &pBankCustomer[i];

        if(pBankCustomer[i].bankaccountNum == inputBankAccount)
        {
            pBankCustomer[i].amount += depositAmount;
            cout << "Amount: " << pBankCustomer->amount << endl;
            break;
        }
    }
}

// Withdraw
int withdraw()
{
    char inputString[10];
    cout << "Enter Bank Account Number: ";
    cin >> inputString;
    int inputBankAccount = atoi(inputString);
    struct person *pExistingPerson;

    cout << "Hello " << pExistingPerson->firstName << " " << pExistingPerson->lastName << endl;
    cout << "Your Bank Account Number is " << pExistingPerson->bankaccountNum;

    cout << "Withdraw Amount: ";
    cin >> inputString;
    int withdrawAmount = atoi(inputString);

    for(int i = 0; i < 5; i++)
    {
        pExistingPerson = &pBankCustomer[i];

        if(pBankCustomer[i].bankaccountNum == inputBankAccount)
        {
            pBankCustomer[i].amount -= withdrawAmount;
            cout << "Amount: " << pBankCustomer->amount << endl;
            break;
        }
    }
}

int admin()
{
    struct person *pCustomer;

    for (int c = 0; c < 5; c++)
    {
        if (avail[c] = 1)
        {
            pCustomer = &pBankCustomer[c];
            cout
                << pCustomer->firstName << " "
                << pCustomer->lastName << " :: "
                // << pCustomer->DOB << " :: "
                << pCustomer->bankaccountNum << " :: "
                << pCustomer->amount << endl;
        }
    }
}

int main(int argc, char**argv)
{
    // cout << "argc = " << argc << endl;
    // cout << "argv[1] = " << argv[1] << endl;
    // int choice = atoi(argv[1]); // convert character to integer

    char inputString[10]; // define initial inputString parameters

    // create database
    pBankCustomer = (struct person*) malloc(5 * sizeof(struct person));
    // guarantees memory allocation for function
    // malloc always returns void pointers (can be casted to anything)
    // casting to allocated in heap the datatype, ensure user knows how memory is being allocated and used

    for (int i = 0; i < 5; i++) avail[i] = 0;

    while(1)
    {
        cout << "1 - Create Account" << endl;
        cout << "2 - Remove Account" << endl;
        cout << "3 - Deposit" << endl;
        cout << "4 - Withdraw" << endl;
        cout << "5 - Exit" << endl;
        cout << "6 - Administrative View" << endl;
        cout << "Input a choice: ";

        bool exit = false;
        cin >> inputString;
        int input = atoi(inputString);

        switch(input)
        {
            case 1:
                cout << "Create Account" << endl;
                customerAdd(); // all functions must have (parameters)
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
                cout << "Exit";
                exit = true; // assignments (initial and re-assignments) are single equals
                break;
            case 6:
                cout << "Administrative View" << endl;
                admin();
                break;
            default:
                cout << "Invalid Selection" << endl;
                cout << "Re-input choice: ";
                break;
        }
        if(exit == true)
        {
            break; // exists while loop // exits program
        }
    }

    free(pBankCustomer); // struct pBankCustomer must lead to free pBankCustomer

    return 0;
}
