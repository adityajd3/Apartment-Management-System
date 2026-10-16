#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Bill {
    int flatNo;
    char ownerName[50];
    float maintenance;
    float water;
    float electricity;
    float parking;
    float other;
    float total;
    int paid;
};

struct Bill bills[MAX];
int count = 0;

void addBill();
void displayBills();
void searchBill();
void payBill();
void calculateTotal(struct Bill *b);

int main() {
    int choice;

    while (1) {
        printf("\n========================================\n");
        printf("   APARTMENT MAINTENANCE & BILLING\n");
        printf("========================================\n");
        printf("1. Add Bill\n");
        printf("2. Display All Bills\n");
        printf("3. Search Bill\n");
        printf("4. Pay Bill\n");
        printf("5. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBill();
                break;

            case 2:
                displayBills();
                break;

            case 3:
                searchBill();
                break;

            case 4:
                payBill();
                break;

            case 5:
                printf("\nThank you!\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}

/* Calculate total bill */
void calculateTotal(struct Bill *b) {
    b->total = b->maintenance +
               b->water +
               b->electricity +
               b->parking +
               b->other;
}

/* Add new bill */
void addBill() {

    if (count >= MAX) {
        printf("\nBill storage is full!\n");
        return;
    }

    printf("\nEnter Flat Number: ");
    scanf("%d", &bills[count].flatNo);

    printf("Enter Owner Name: ");
    scanf(" %[^\n]", bills[count].ownerName);

    printf("Enter Maintenance Charge: ");
    scanf("%f", &bills[count].maintenance);

    printf("Enter Water Bill: ");
    scanf("%f", &bills[count].water);

    printf("Enter Electricity Bill: ");
    scanf("%f", &bills[count].electricity);

    printf("Enter Parking Charge: ");
    scanf("%f", &bills[count].parking);

    printf("Enter Other Charges: ");
    scanf("%f", &bills[count].other);

    bills[count].paid = 0;

    calculateTotal(&bills[count]);

    printf("\nBill added successfully!");
    printf("\nTotal Bill = %.2f\n", bills[count].total);

    count++;
}

/* Display all bills */
void displayBills() {
    int i;

    if (count == 0) {
        printf("\nNo bills available.\n");
        return;
    }

    printf("\n=============== ALL BILLS ===============\n");

    for (i = 0; i < count; i++) {

        printf("\nFlat Number       : %d", bills[i].flatNo);
        printf("\nOwner Name        : %s", bills[i].ownerName);
        printf("\nMaintenance       : %.2f", bills[i].maintenance);
        printf("\nWater Bill        : %.2f", bills[i].water);
        printf("\nElectricity       : %.2f", bills[i].electricity);
        printf("\nParking           : %.2f", bills[i].parking);
        printf("\nOther Charges     : %.2f", bills[i].other);
        printf("\n-----------------------------------------");
        printf("\nTOTAL             : %.2f", bills[i].total);
        printf("\nStatus            : %s",
               bills[i].paid ? "PAID" : "UNPAID");

        printf("\n=========================================\n");
    }
}

/* Search bill */
void searchBill() {
    int flatNo;
    int i;
    int found = 0;

    printf("\nEnter Flat Number: ");
    scanf("%d", &flatNo);

    for (i = 0; i < count; i++) {

        if (bills[i].flatNo == flatNo) {

            printf("\n========== BILL DETAILS ==========\n");
            printf("Flat Number   : %d\n", bills[i].flatNo);
            printf("Owner Name    : %s\n", bills[i].ownerName);
            printf("Maintenance   : %.2f\n", bills[i].maintenance);
            printf("Water         : %.2f\n", bills[i].water);
            printf("Electricity   : %.2f\n", bills[i].electricity);
            printf("Parking       : %.2f\n", bills[i].parking);
            printf("Other         : %.2f\n", bills[i].other);
            printf("-------------------------------\n");
            printf("TOTAL         : %.2f\n", bills[i].total);
            printf("STATUS        : %s\n",
                   bills[i].paid ? "PAID" : "UNPAID");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nBill not found!\n");
    }
}

/* Pay bill */
void payBill() {
    int flatNo;
    int i;
    int found = 0;

    printf("\nEnter Flat Number: ");
    scanf("%d", &flatNo);

    for (i = 0; i < count; i++) {

        if (bills[i].flatNo == flatNo) {

            found = 1;

            if (bills[i].paid == 1) {
                printf("\nBill is already paid!\n");
            } else {
                bills[i].paid = 1;

                printf("\nPayment successful!\n");
                printf("Amount Paid: %.2f\n", bills[i].total);
                printf("Flat Number: %d\n", bills[i].flatNo);
            }

            break;
        }
    }

    if (!found) {
        printf("\nBill not found!\n");
    }
}