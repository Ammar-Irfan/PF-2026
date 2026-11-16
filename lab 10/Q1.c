
#include <stdio.h>
#include <string.h>

struct Flight
{
    int flight_number;
    char departure_city[50];
    char destination_city[50];
    char date[20];
    int available_seats;
};

void displayFlight(struct Flight f)
{
  
    printf("Flight Number: %d\n", f.flight_number);
    printf("Departure City: %s\n", f.departure_city);
    printf("Destination City: %s\n", f.destination_city);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.available_seats);
}

void bookSeat(struct Flight *f)
{
    if ((*f).available_seats > 0)
    {
       (*f).available_seats--;
        printf("\nSeat booked successfully!\n");
        printf("Remaining Seats: %d\n", (*f).available_seats);
    }
    else
    {
        printf("\nSorry! No seats are available.\n");
    }
}

int main()
{
    struct Flight f;
    int choice;

    printf("Enter Flight Number: ");
    scanf("%d", &f.flight_number);
    getchar();

    printf("Enter Departure City: ");
    fgets(f.departure_city, sizeof(f.departure_city), stdin);
    f.departure_city[strcspn(f.departure_city, "\n")] = '\0';

    printf("Enter Destination City: ");
    fgets(f.destination_city, sizeof(f.destination_city), stdin);
    f.destination_city[strcspn(f.destination_city, "\n")] = '\0';

    printf("Enter Date: ");
    fgets(f.date, sizeof(f.date), stdin);
    f.date[strcspn(f.date, "\n")] = '\0';

    printf("Enter Available Seats: ");
    scanf("%d", &f.available_seats);

    do
    {
        
        printf("1. Book a Seat\n");
        printf("2. Display Flight Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                bookSeat(&f);
                break;

            case 2:
                displayFlight(f);
                break;

            case 3:
               
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 3);

    return 0;
}
