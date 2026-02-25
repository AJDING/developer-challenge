#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED

#define MAX_NUM_ROOMS 25

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
    char houseName[400];
    int houseID;
    int roomTotalNum;
    int houseAddressNum;
    char houseAddressName[400]; // char elements in type struct should be array to hold string[series of characters in array] data type

    struct room * pRooms[MAX_NUM_ROOMS];
    // pVariable is a pointer-type-variable to struct room
    // index is now MAX_NUM_ROOMS as #define above
    // all pointers within the array are initialized to NULL
};

void modify_house(struct house * pModHouse);
//void modify_house(struct house * pModHouse);

void roomAdd(struct house * pHouse);
void roomRemove(struct house * pHouse);
void roomModify(struct house * pHouse);
void homeDisplay(struct house * pHouse);

#endif // HOUSE_H_INCLUDED
