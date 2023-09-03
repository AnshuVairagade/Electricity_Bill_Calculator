#include <stdio.h>

#define MAX_CUSTOMERS 100

struct Customer {
    int customerID;
    float unitsConsumed;
    float billAmount;
    char name[20];
};

void calculateBill(struct Customer* customers, int numCustomers) {
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].unitsConsumed <= 100)
            customers[i].billAmount = customers[i].unitsConsumed * 1.0 + 140.00;
        else if (customers[i].unitsConsumed <= 300)
            customers[i].billAmount = 100 + (customers[i].unitsConsumed - 100) * 2.0 + 140.00;
        else
            customers[i].billAmount = 500 + (customers[i].unitsConsumed - 300) * 3.0 + 140.00 ;
    }
     
}

void displayBills(struct Customer* customers, int numCustomers) {

    for (int i = 0; i < numCustomers; i++) {
        printf("\n");
        printf("\n********************");
        printf("\n| Electricity Bill |\n");
        printf("********************\n");
        printf("\n");
        printf("Billing unit : 3956/HINGANA S/DN/BUTIBORI \n");
        printf("Pole NO. = RK-15\n");
        printf("\n");
        printf("Fixed tax = Rs. 105.00\n");
        printf("Vehicle tax = Rs. 35\n");

        // printf("Customer ID\tUnits Consumed\tBill Amount\n");
        printf("-------------------------------------------------------\n");
        printf("Name of customer : %s \n", customers[i].name);
        printf("Customer ID : %d \n", customers[i].customerID);
        printf("Unit consumed : %.2f \n", customers[i].unitsConsumed);
        printf("Bill amount = %.2f\n", customers[i].billAmount);
        printf("-------------------------------------------------------\n");
        printf("*********************************************************");
        printf("\n");
        printf("\n");

    }
}

int main() {
    struct Customer customers[MAX_CUSTOMERS];
    int numCustomers;

    printf("Enter the number of customers: ");
    scanf("%d", &numCustomers);

    for (int i = 0; i < numCustomers; i++) {

        printf("Enter details of customer %d \n", i+1);
        printf("Customer ID: ");
        scanf("%d", &customers[i].customerID);

        printf("Units Consumed: ");
        scanf("%f", &customers[i].unitsConsumed);
        
        printf("Customer name: ");
        scanf("%s", &customers[i].name);
    }
    printf("\n");

    calculateBill(customers, numCustomers);

    displayBills(customers, numCustomers);

    return 0;
}