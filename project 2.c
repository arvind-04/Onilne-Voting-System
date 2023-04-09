#include <stdio.h>
#include <string.h>
int new_reg();
int Vote_posi();
int Log_in();
int login();
char username[50], password[50];
struct User {
   char username[50];
   char password[50];
};
int main(){
    int n;
    printf("\t\t\t\t\t|-----------------------------------|\n");
    printf("\t\t\t\t\t|Welcome to the Online Voting System|\n");
    printf("\t\t\t\t\t|-----------------------------------|\n");
    printf("\n");
    Log_in();
    return 0;
}
int Log_in() {
   char choice;
   struct User user;
   FILE *fp;
   int loggedIn = 0;
   while (1) {
      printf("Enter L to login, R to register, or Q to quit: ");
      scanf(" %c", &choice);

      if (choice == 'L' || choice == 'l') {
         char username[50], password[50];
         printf("Enter username: ");
         scanf("%s", username);
         printf("Enter password: ");
         scanf("%s", password);

         fp = fopen("users.txt", "r");
         while (fread(&user, sizeof(struct User), 1, fp)) {
            if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
               printf("Login successful!\n");
               fclose(fp);
               printf("\nWelcome to the system!\n");
            char choice;
            printf("\nWhat would you like to do?\n");
            printf("1. View profile\n");
            printf("2. Log out\n");
            printf("3. Cast Vote\n");
            printf("Enter your choice (1-3): ");
            scanf(" %c", &choice);

            switch (choice) {
                case '1':
                    printf("\nHere is your profile:\n");
                    printf("Username: %s\t", username);
                    printf("Password: %s", password);
                    break;
                case '2':
                    printf("\nLogging out...\n");
                     // mark user as logged out
                    break;
                case'3':
                    Vote_posi();
                    break;
                default:
                    printf("\nInvalid choice. Please try again.\n");
                    break;
            }
               break;
            }
         }
         if (!feof(fp)) {
            break;
         }
         printf("Invalid username or password. Please try again.\n");
         fclose(fp);
      } 
      else if (choice == 'R' || choice == 'r') {
         char username[50], password[50];
         printf("Enter username: ");
         scanf("%s", username);
         printf("Enter password: ");
         scanf("%s", password);

         fp = fopen("users.txt", "a");
         strcpy(user.username, username);
         strcpy(user.password, password);
         fwrite(&user, sizeof(struct User), 1, fp);
         fclose(fp);

         printf("Registration successful!\n");
        //  login();
         
      } else if (choice == 'Q' || choice == 'q') {
         break;
      } else {
         printf("Invalid choice. Please try again.\n");
         break;
      }
   }
   return 0;
}

int Vote_posi() {
   int option;
   char name[50];

   printf("Select a position for voting:\n");
   printf("1. Member of Parliament\n");
   printf("2. Member of Legislative Assembly\n");
   printf("3. Municipal Councilor\n");
   printf("4. Panchayat Member\n");
   printf("5. President\n");
   printf("6. Vice President\n");
   scanf("%d", &option);

   switch (option) {
      case 1:
         printf("You have chosen to vote for the position of Member of Parliament. The candidates are:\n");
         printf("1. Candidate A\n");
         printf("2. Candidate B\n");
         printf("3. Candidate C\n");
         break;
      case 2:
         printf("You have chosen to vote for the position of Member of Legislative Assembly. The candidates are:\n");
         printf("1. Candidate X\n");
         printf("2. Candidate Y\n");
         printf("3. Candidate Z\n");
         break;
      case 3:
         printf("You have chosen to vote for the position of Municipal Councilor. The candidates are:\n");
         printf("1. Candidate P\n");
         printf("2. Candidate Q\n");
         printf("3. Candidate R\n");
         break;
      case 4:
         printf("You have chosen to vote for the position of Panchayat Member. The candidates are:\n");
         printf("1. Candidate M\n");
         printf("2. Candidate N\n");
         printf("3. Candidate O\n");
         break;
      case 5:
         printf("You have chosen to vote for the position of President. The candidates are:\n");
         printf("1. Candidate Alpha\n");
         printf("2. Candidate Bravo\n");
         printf("3. Candidate Charlie\n");
         break;
      case 6:
         printf("You have chosen to vote for the position of Vice President. The candidates are:\n");
         printf("1. Candidate Delta\n");
         printf("2. Candidate Echo\n");
         printf("3. Candidate Foxtrot\n");
         break;
      default:
         printf("Invalid option.\n");
         return 0;
   }

   printf("Enter the candidate number you wish to vote for: ");
   scanf("%d", &option);

   switch (option) {
      case 1:
         printf("You have voted for Candidate A.\n");
         break;
      case 2:
         printf("You have voted for Candidate B.\n");
         break;
      case 3:
         printf("You have voted for Candidate C.\n");
         break;
      default:
         printf("Invalid option.\n");
   }

   return 0;
}