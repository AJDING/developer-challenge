#include <iostream>
#include <cstring>

#include "house.h"

using namespace std;

void modify_house(struct house * pModHouse)
// pass pointer as parameter only 4 bytes
// int modify_house(struct house House) // passing entity as parameter will not carry change back to caller function
{
    char inputString[20];
    // DECLARATION OF ARRAY DATA STRUCTURE VARIABLE
    // inputString of type array

    while(1)
    {
        cout << "1 - Add Room" << endl;
        cout << "2 - Remove Room" << endl;
        cout << "3 - Modify Room" << endl;
        cout << "4 - Display Home" << endl;
        cout << "5 - Exit" << endl;
        cout << "Input a choice: ";

        bool exit = false;
        cin >> inputString;
        // THIS IS POINTER TYPE REFERENCED BY ARRAY NAME
        int input = atoi(inputString);

        switch(input)
        {
            case 1:
                cout << "Add Room" << endl;
                roomAdd(pModHouse);
                break;
            case 2:
                cout << "Remove Room" << endl;
                roomRemove(pModHouse);
                break;
            case 3:
                cout << "Modify Room" << endl;
                roomModify(pModHouse);
                break;
            case 4:
                cout << "Display Home" << endl;
                homeDisplay(pModHouse);
                cout << "------- finish display" << endl;
                break;
            case 5:
                cout << "Exit";
                exit = true; // assignments (initial and re-assignments) are single equals
                break;
            default:
                cout << "Invalid Selection. Please Re-input choice." << endl;
                break;
        }
        if(exit == true) // if equals are double
        {
            break;
        }
    }
}
