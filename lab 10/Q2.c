
#include <stdio.h>
#include <string.h>

struct Movie
{
    char title[100];
    char genre[50];
    char director[100];
    int releaseYear;
    float rating;
};

int main()
{
    struct Movie movies[100];
    int choice, count = 0, i;
    char searchGenre[50];
    int found;

    do
    {
      
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                if (count < 100)
                {
                    printf("\nEnter Movie Title: ");
                    fgets(movies[count].title, 100, stdin);
                    movies[count].title[strcspn(movies[count].title, "\n")] = '\0';

                    printf("Enter Genre: ");
                    fgets(movies[count].genre, 50, stdin);
                    movies[count].genre[strcspn(movies[count].genre, "\n")] = '\0';

                    printf("Enter Director Name: ");
                    fgets(movies[count].director, 100, stdin);
                    movies[count].director[strcspn(movies[count].director, "\n")] = '\0';

                    printf("Enter Release Year: ");
                    scanf("%d", &movies[count].releaseYear);

                    printf("Enter Rating: ");
                    scanf("%f", &movies[count].rating);
                    getchar();

                    count++;

                    printf("\nMovie added successfully!\n");
                }
                else
                {
                    printf("\nMovie storage is full!\n");
                }
                break;

            case 2:
                printf("\nEnter Genre to Search: ");
                fgets(searchGenre, 50, stdin);
                searchGenre[strcspn(searchGenre, "\n")] = '\0';

                found = 0;

                for (i = 0; i < count; i++)
                {
                    if (strcmp(movies[i].genre, searchGenre) == 0)
                    {
                      
                        printf("Title: %s\n", movies[i].title);
                        printf("Genre: %s\n", movies[i].genre);
                        printf("Director: %s\n", movies[i].director);
                        printf("Release Year: %d\n", movies[i].releaseYear);
                        printf("Rating: %.1f\n", movies[i].rating);

                        found = 1;
                    }
                }

                if (found == 0)
                {
                    printf("\nNo movies found in this genration\n");
                }
                break;

            case 3:
                if (count == 0)
                {
                    printf("\nNo movies available\n");
                }
                else
                {
                 

                    for (i = 0; i < count; i++)
                    {
                        printf("\nMovie %d\n", i + 1);
                        printf("Title: %s\n", movies[i].title);
                        printf("Genre: %s\n", movies[i].genre);
                        printf("Director: %s\n", movies[i].director);
                        printf("Release Year: %d\n", movies[i].releaseYear);
                        printf("Rating: %f\n", movies[i].rating);
                    }
                }
                break;

            case 4:
                
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while (choice != 4);

    return 0;
}
