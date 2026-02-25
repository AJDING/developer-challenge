#include <iostream>
#include <cstring>

#include "house.h"

using namespace std;

#define MAX_NUM_ROOMS 25 // preprocessor directive

// structs are datatypes
// struct furniture

#if 0
struct room // C/C++ compiler is top-down compiler // need to define before the reference
{
    int windows; // maximum int is 2^(32) or 2^(40)
    int doors;
    int roomID;
    char roomFunction[25];
    char furniture[20][30]; // [maximum furniture number][maximum furniture name]
    int furnitureTotalNum;
    int furnitureID;
};

struct house // global variable
{
    char houseName[30];
    int houseID;
    int roomTotalNum;
    int houseAddressNum;
    char houseAddressName[40]; // char elements in type struct should be array to hold string[series of characters in array] data type

    struct room * pRooms[MAX_NUM_ROOMS];
    // pVariable is a pointer-type-variable to struct room
    // index is now MAX_NUM_ROOMS as #define above
};
#endif

// struct house * pHouse;
// another way to pass parameter with global variable
// potentially unsecure, can be accessed by ALL code (even outside main.cpp)

struct house* houseAdd() // houseAdd(struct house * pHouse) if struct house is global variable
{
    char inputString[20];

    struct house * pHouse;

    pHouse = (struct house*) malloc(1 * sizeof(struct house));
    pHouse->roomTotalNum = 0; // this needs to be initialized to zero, to be incremented by roomAdd()
    for (int i = 0; i < MAX_NUM_ROOMS; i++)
    {
        pHouse->pRooms[i] = NULL; // bad practice to be initialized to 0 because zero is an integer
        // == is evaluation
        // =  is assignment
    }

    pHouse->houseID = rand();

    cout << "Enter House Address Number: ";
    cin >> inputString;
    pHouse->houseAddressNum = atoi(inputString);
    cout << "Enter House Address Street/City: ";
    cin >> inputString;
    strcpy(pHouse->houseAddressName, inputString);

    cout << "House Name: ";
    cin >> inputString;
    strcpy(pHouse->houseName, inputString);

    cout << "Congratulations " << pHouse->houseName << "!" << endl;
    cout << "Home Address: " << pHouse->houseAddressNum << " " << pHouse->houseAddressName << endl;
    cout << "House HID: " << "H" << pHouse->houseID << endl;

    return pHouse; // creating house from scratch into memory
}

void houseDemo(struct house * pHouse)
{
    // char inputString[20];
    free(pHouse);

    // return 0;
    // int type functions must return something
    // void type functions, if else not return
}

// these are internal functions
void roomAdd(struct house * pHouse)
// functions must have parameters passed in, even if it's none
// roomAdd(struct house * pHouse) if struct house is global variable
{
    struct room * pNewRoom = new struct room; // memory allocation C++ exclusive
    // struct room * pNewRoom = (struct room*) malloc(1 * sizeof(struct room));
    // this is C-Language version of the code, will still work, but need to be more specific

    char inputString[20];

    // this can go before the user inputs, or after. Depends on your philosophy
    pHouse->pRooms[pHouse->roomTotalNum] = pNewRoom;
    // everything in brackets are arrays/array element(s)
    pHouse->roomTotalNum += 1;
    int rID = pHouse->roomTotalNum; // internal variable for roomID
    pNewRoom->roomID = rID; // assign that rID to room struct

    // ADD WINDOWS
    cout << "Number of Windows: ";
    cin >> inputString;
    int input = atoi(inputString); // first input defined
    pNewRoom->windows = input;

    // ADD DOORS
    cout << "Number of Doors: ";
    cin >> inputString;
    input = atoi(inputString); // second input
    pNewRoom->doors = input;

    cout << "Room Function: ";
    cin >> inputString;
    strcpy(pNewRoom->roomFunction, inputString);

    pNewRoom->furnitureTotalNum = 0;
    /*
    while()
    cout << "Add Furniture: ";
    */

    cout << "Room RID: " << "R" << pNewRoom->roomID << " :: " << pNewRoom->roomFunction << endl;
    cout << "Number of Windows: " << pNewRoom->windows << endl;
    cout << "Number of Doors: " << pNewRoom->doors << endl;

    // not needing a return statement because MAX_NUM_ROOMS already allocated in memory
}

void roomRemove(struct house * pHouse)
{
    char inputString[40];
    cout << "Enter Room RID: ";
    cin >> inputString;
    int input = atoi(inputString);

    // can potentially be while loop as well // need to have counter within while loop
    // while loop evaluating conditions
    // for loop evaluating iterative counts
    for (int i = 0; i < MAX_NUM_ROOMS; i++)
    {
        if (pHouse->pRooms[i] != NULL && pHouse->pRooms[i]->roomID == input)
        {
            free(pHouse->pRooms[i]);
            pHouse->pRooms[i] = NULL;
            pHouse->roomTotalNum -= 1;

            break; // break here, because you have to keep iterating until condition is met
        }
        // break;
    }

    /*
    for (int i = 0; i < pHouse->roomTotalNum; i++)
    {
        if (pHouse->pRooms[i]->roomID == input && pHouse->pRooms[i] != NULL)
        {
            free(pHouse->pRooms[i]);
            pHouse->pRooms[i] == NULL;
            pHouse->roomTotalNum -= 1;
        }
    }
    */
}

void roomModify(struct house * pHouse)
{
    char inputString[40];
    cout << "Enter Room RID: ";
    cin >> inputString;
    int input = atoi(inputString);
    int fID = 0;

    for (int i = 0; i < MAX_NUM_ROOMS; i++)
    {
        if(pHouse->pRooms[i] != NULL && pHouse->pRooms[i]->roomID == input)
        {
            while(1)
            {
                cout << "Enter Furniture Name: ";
                cout << "Enter 0 if you're finished." << endl;
                cin >> inputString;
                // int fID = pRooms->furnitureTotalNum; // internal variable for roomID
                // furniture->roomID = fID + 100; // assign that rID to room struct

                if (inputString[0] == '0')
                {
                    break;
                }
                strcpy(pHouse->pRooms[i]->furniture[fID], inputString);
                fID++;
                cout << "-----Adding a " << inputString << endl;
                cout << "-----Furniture Count: " << fID << endl;
                // '' single quotes are ASCII char
                // "" double quotes are string types

                /*
                int DONE = strcmp(inputString, "DONE\n");
                cout << inputString << endl;
                if (DONE =- 0)
                {
                    break;
                }
                */
            }

            pHouse->pRooms[i]->furnitureTotalNum = fID;
            cout << "number of furniture " << pHouse->pRooms[i]->furnitureTotalNum << endl;
            break;
            // anything that happens after break is not executed
        }
    }
}

void homeDisplay(struct house * pHouse)
{
    struct room * pRoomSingle;
    // while(1){}
    cout << "You Home has: " << endl;
    for (int i = 0; i < MAX_NUM_ROOMS; i++)
    {
        pRoomSingle = pHouse->pRooms[i];
        if(pRoomSingle != NULL)
        // 0 // -> RoomID != 0
        // Operating System (particularly in embedded systems) is allocated/arranged at the low-level low-address range
        // NULL will not allocate memory at all // 0 will allocate the specific ASCII register in memory
        // bad practice to initialize pointer to 0 becuase of hexadecimal/binary 0000
        // memory address ASCII '0' in register hexadecimal memory
        // embedded systems C-Language doesn't have all these libraries, much simpler compiler
        // embedded systems does not have Memory Management Unit (MMU)
        // embedded systems does not have memory protection layers
        // embedded systems kernel is where your low-level embedded OS/BIOS (Linux included, but not limited to)
        {
            cout << "Room RID: " << "R" << pRoomSingle->roomID << " :: " << pRoomSingle->roomFunction << endl;
            cout << "Room RID: " << "R" << pRoomSingle->roomID << " :: " << pRoomSingle->windows << " Windows" << endl;
            cout << "Room RID: " << "R" << pRoomSingle->roomID << " :: " << pRoomSingle->doors << " Doors" << endl;
            cout << "Room RID: " << "R" << pRoomSingle->roomID << " :: " << pRoomSingle->furnitureTotalNum << " Pieces of Furniture" << endl;
            for(int j = 0; j < pRoomSingle->furnitureTotalNum; j++)
            {
                cout << pRoomSingle->furniture[j] << endl;
            }
        }
        else
        {
            break;
        }
    }
}

//extern int modify_house(struct house * pModHouse);
// house frame is main
int main(int argc, char* argv[])
// char argv  // argv is a variable of char
// char argv[] // argv is a pointer of char to an array
// char* argv[] // means pointer to a 2D array
// char** argv // means pointer to a 2D array
// this is not where you declare the variable for 2D arrays // this is only declaring type
{
    char inputString[20];
    struct house * pHouse;

    while(1)
    {
        cout << "1 - Create House" << endl;
        cout << "2 - Modify House" << endl;
        cout << "3 - Demolish House" << endl;
        cout << "4 - Exit" << endl;
        cout << "Input a choice: ";

        bool exit = false;
        cin >> inputString;
        int input = atoi(inputString);

        switch(input)
        {
            case 1:
                cout << "Create House" << endl;
                pHouse = houseAdd(); // because we need to return value/data from function
                // roomAdd(pHouse);
                break;
            case 2:
                cout << "Modify House" << endl;
                modify_house(pHouse);
                break;
            case 3:
                cout << "Demolish House" << endl;
                houseDemo(pHouse);
                break;
            case 4:
                cout << "Exit" << endl;
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

#if 0
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
            int input = atoi(inputString);

            switch(input)
            {
                case 1:
                    cout << "Add Room" << endl;
                    roomAdd(pHouse);
                    break;
                case 2:
                    cout << "Remove Room" << endl;
                    roomRemove(pHouse);
                    break;
                case 3:
                    cout << "Modify Room" << endl;
                    roomModify(pHouse);
                    break;
                case 4:
                    cout << "Display Home" << endl;
                    homeDisplay(pHouse);
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
#endif

    }

    free(pHouse); // if struct element memory allocated by main, it needs to be freed by main

    return 0;
}
