#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_ID_LENGTH 20
#define MAX_MEMBERS 100

// Enum for service types
typedef enum {
    BASIC = 1,
    PREMIUM,
    VIP,
    CORPORATE
} ServiceType;

// Structure for club member
typedef struct {
    char name[MAX_NAME_LENGTH];
    char memberID[MAX_ID_LENGTH];
    int membershipFee;
    ServiceType serviceType;
} ClubMember;

// Global array to store members
ClubMember members[MAX_MEMBERS];
int memberCount = 0;

// Function prototypes
void addMember();
void displayAllMembers();
void searchMember();
void updateMember();
void deleteMember();
void displayMenu();
const char* getServiceTypeName(ServiceType type);
ServiceType getServiceTypeFromInput();

int main() {
    int choice;

    printf("=== Club Member Database System ===\n");

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                addMember();
                break;
            case 2:
                displayAllMembers();
                break;
            case 3:
                searchMember();
                break;
            case 4:
                updateMember();
                break;
            case 5:
                deleteMember();
                break;
            case 6:
                printf("Thank you for using Club Member Database!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
    }

    return 0;
}

void displayMenu() {
    printf("\n=================================\n");
    printf("1. Add New Member\n");
    printf("2. Display All Members\n");
    printf("3. Search Member\n");
    printf("4. Update Member\n");
    printf("5. Delete Member\n");
    printf("6. Exit\n");
    printf("=================================\n");
}

void addMember() {
    if (memberCount >= MAX_MEMBERS) {
        printf("Database is full! Cannot add more members.\n");
        return;
    }

    ClubMember newMember;

    printf("\n--- Add New Member ---\n");

    printf("Enter member name: ");
    fgets(newMember.name, MAX_NAME_LENGTH, stdin);
    newMember.name[strcspn(newMember.name, "\n")] = 0; // remove newline

    printf("Enter member ID: ");
    fgets(newMember.memberID, MAX_ID_LENGTH, stdin);
    newMember.memberID[strcspn(newMember.memberID, "\n")] = 0; // remove newline

    // Check for duplicate member ID
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i].memberID, newMember.memberID) == 0) {
            printf("Error: Member ID already exists!\n");
            return;
        }
    }

    printf("Enter membership fee: $");
    scanf("%d", &newMember.membershipFee);
    getchar(); // consume newline

    newMember.serviceType = getServiceTypeFromInput();

    members[memberCount] = newMember;
    memberCount++;

    printf("Member added successfully!\n");
}

void displayAllMembers() {
    if (memberCount == 0) {
        printf("\nNo members found in the database.\n");
        return;
    }

    printf("\n--- All Club Members ---\n");
    printf("%-20s %-15s %-12s %-12s\n", "Name", "Member ID", "Fee", "Service Type");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < memberCount; i++) {
        printf("%-20s %-15s $%-11d %-12s\n",
               members[i].name,
               members[i].memberID,
               members[i].membershipFee,
               getServiceTypeName(members[i].serviceType));
    }
}

void searchMember() {
    if (memberCount == 0) {
        printf("\nNo members found in the database.\n");
        return;
    }

    char searchID[MAX_ID_LENGTH];
    printf("\nEnter member ID to search: ");
    fgets(searchID, MAX_ID_LENGTH, stdin);
    searchID[strcspn(searchID, "\n")] = 0; // remove newline

    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i].memberID, searchID) == 0) {
            printf("\n--- Member Found ---\n");
            printf("Name: %s\n", members[i].name);
            printf("Member ID: %s\n", members[i].memberID);
            printf("Membership Fee: $%d\n", members[i].membershipFee);
            printf("Service Type: %s\n", getServiceTypeName(members[i].serviceType));
            return;
        }
    }

    printf("Member with ID '%s' not found.\n", searchID);
}

void updateMember() {
    if (memberCount == 0) {
        printf("\nNo members found in the database.\n");
        return;
    }

    char searchID[MAX_ID_LENGTH];
    printf("\nEnter member ID to update: ");
    fgets(searchID, MAX_ID_LENGTH, stdin);
    searchID[strcspn(searchID, "\n")] = 0; // remove newline

    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i].memberID, searchID) == 0) {
            printf("\n--- Update Member ---\n");
            printf("Current details:\n");
            printf("Name: %s\n", members[i].name);
            printf("Member ID: %s\n", members[i].memberID);
            printf("Membership Fee: $%d\n", members[i].membershipFee);
            printf("Service Type: %s\n", getServiceTypeName(members[i].serviceType));

            printf("\nEnter new name (or press Enter to keep current): ");
            char tempName[MAX_NAME_LENGTH];
            fgets(tempName, MAX_NAME_LENGTH, stdin);
            if (strlen(tempName) > 1) {
                tempName[strcspn(tempName, "\n")] = 0;
                strcpy(members[i].name, tempName);
            }

            printf("Enter new membership fee (or 0 to keep current): $");
            int tempFee;
            scanf("%d", &tempFee);
            getchar(); // consume newline
            if (tempFee > 0) {
                members[i].membershipFee = tempFee;
            }

            printf("Update service type? (y/n): ");
            char choice;
            scanf("%c", &choice);
            getchar(); // consume newline
            if (choice == 'y' || choice == 'Y') {
                members[i].serviceType = getServiceTypeFromInput();
            }

            printf("Member updated successfully!\n");
            return;
        }
    }

    printf("Member with ID '%s' not found.\n", searchID);
}

void deleteMember() {
    if (memberCount == 0) {
        printf("\nNo members found in the database.\n");
        return;
    }

    char searchID[MAX_ID_LENGTH];
    printf("\nEnter member ID to delete: ");
    fgets(searchID, MAX_ID_LENGTH, stdin);
    searchID[strcspn(searchID, "\n")] = 0; // remove newline

    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i].memberID, searchID) == 0) {
            printf("Are you sure you want to delete member '%s'? (y/n): ", members[i].name);
            char confirm;
            scanf("%c", &confirm);
            getchar(); // consume newline

            if (confirm == 'y' || confirm == 'Y') {
                // Shift all elements after the deleted member
                for (int j = i; j < memberCount - 1; j++) {
                    members[j] = members[j + 1];
                }
                memberCount--;
                printf("Member deleted successfully!\n");
            } else {
                printf("Delete operation cancelled.\n");
            }
            return;
        }
    }

    printf("Member with ID '%s' not found.\n", searchID);
}

const char* getServiceTypeName(ServiceType type) {
    switch (type) {
        case BASIC: return "Basic";
        case PREMIUM: return "Premium";
        case VIP: return "VIP";
        case CORPORATE: return "Corporate";
        default: return "Unknown";
    }
}

ServiceType getServiceTypeFromInput() {
    int choice;

    printf("Select service type:\n");
    printf("1. Basic\n");
    printf("2. Premium\n");
    printf("3. VIP\n");
    printf("4. Corporate\n");
    printf("Enter choice (1-4): ");

    scanf("%d", &choice);
    getchar(); // consume newline

    switch (choice) {
        case 1: return BASIC;
        case 2: return PREMIUM;
        case 3: return VIP;
        case 4: return CORPORATE;
        default:
            printf("Invalid choice! Defaulting to Basic.\n");
            return BASIC;
    }
}
