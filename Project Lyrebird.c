#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>
#include <windows.h>

#define MAX_SIZE 100


struct Database {
    int dd, mm, yyyy;
    float timefrom, timeto;
    char message[MAX_SIZE];
};

void speakText(const char *text) {
    // PowerShell command to invoke narrator with a male voice
    char cmd[512];
    snprintf(cmd, sizeof(cmd), "powershell -Command \"Add-Type -AssemblyName System.speech; $synthesizer = New-Object System.Speech.Synthesis.SpeechSynthesizer; $synthesizer.SelectVoiceByHints([System.Speech.Synthesis.VoiceGender]::male); $synthesizer.Speak('%s');\"", text);
    system(cmd);
}
///////////////////////////////////////////////////////\ functions to set color/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void black(){
    printf("\033[0;30m");
}
void red(){
    printf("\033[0;31m");
}
void green(){
    printf("\033[0;32m");
}
void yellow(){
    printf("\033[0;33m");
}
void blue(){
    printf("\033[0;34m");
}
void purple(){
    printf("\033[0;35m");
}
void cyan(){
    printf("\033[0;36m");
}
void white(){
    printf("\033[0;37m");
}
///////////////////////////////////////////////////////\ functions to set color/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
---------------------------------------------------------------------------------------------------weclome page-------------------------------------------------------------------------------------------
void welcome_page(){
    char next;

      const char* asciiArt =
"\n _________________________________________________________________________________________________________________\n"
"|                                                                                                                 |\n"
"|                                                                                                                 |\n"
"|                                                                                                                 |\n"
"|                                                                                                                 |\n"
"|                                                                                            ::.  .::::           |\n"
"|     _    _      _                            _                          _           _   .++-..::...-.. .        |\n"
"|    | |  | |    | |                          | |                        (_)         | |  *=:::::...::.:::        |\n"
"|    | |  | | ___| | ___ ___  _ __ ___   ___  | |_ ___    _ __  _ __ ___  _  ___  ___| |_   :::...:::--:=:        |\n"
"|    | |/\\| |/ _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | '_ \\| '__/ _ \\| |/ _ \\/ __| __|  .:-:..:::--==.        |\n"
"|    \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |_) | | | (_) | |  __/ (__| |_   .:-...::::: .         |\n"
"|     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  | .__/|_|  \\___/| |\\___|\\___|\\__| ...:..:.:::.           |\n"
"|                                                        | |            _/ |      ..:.      :.:.::..:::.          |\n"
"|                                                        |_|           |__/        -=--    .:::::-::.::           |\n"
"|                       _                _     _         _                         .+-:    .:::--=:::-.           |\n"
"|                    \" | |              | |   (_)       | | \"                      =+::     -----=-:--            |\n"
"|                      | |_   _ _ __ ___| |__  _ _ __ __| |                       ++-.....  :::-::::-             |\n"
"|                      | | | | | '__/ _ \\ '_ \\| | '__/ _` |                       -=-----===::-::-:-.             |\n"
"|                      | | |_| | | |  __/ |_) | | | | (_| |                        :++----=+--=--=:               |\n"
"|                      |_|\\__, |_|  \\___|_.__/|_|_|  \\__,_|                          :+=-==-==-===                |\n"
"|                          __/ |                                                       :=::-+++=-                 |\n"
"|                                                                                        .+:-:---                 |\n"
"|                                                                                        .  :                     |\n"
"|                                                                                  .::-=---==--:...               |\n"
"|                                                                                --===+--===----===-:.            |\n"
"|                                                                                   ..::::..::...                 |\n"
"|                                                                                                                 |\n"
;

    // Add spaces for right alignment
    const int numSpaces = 40;
    for (int i = 0; i < numSpaces; i++) {
        printf(" ");
    }
    printf("%s", asciiArt);

    printf("|");
   blue();
      printf("                                             Press %c to Continue                                                 ",217);
   white();
   printf("|");
    printf("\n|_________________________________________________________________________________________________________________|\n");

    scanf("%c",&next);
    if(next=='\n')
            current_calender();
}
//---------------------------------------------------------------------------------------------------weclome page-------------------------------------------------------------------------------------------


void live_time(){
        // Get the current time
        time_t currentTime;
        struct tm *localTime;
        currentTime = time(NULL);
        localTime = localtime(&currentTime);

        // Set the text color to red
 //       printf(ANSI_COLOR_RED);

        // Format and print the current time
        printf("|                      \t                     Current time:");
red();
        printf(" %02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
white();
        printf("                                               |\n");


        // Reset the text color
//        printf(ANSI_COLOR_RESET);

        // Flush the output buffer to ensure immediate display
        fflush(stdout);

        // Wait for 1 second (1000 milliseconds)
        // The `usleep` function is OS-dependent, and in this example, I'll use the POSIX-compliant function for Unix-like systems.
        // For Windows, you can use Sleep() from the Windows API.
        // If you are using Windows, include <windows.h> and replace "usleep(1000000);" with "Sleep(1000);".
       usleep(1000000);

}
void print_calendar(int year, int month, int current_day) {
    struct tm first_day;
    first_day.tm_sec = 0;
    first_day.tm_min = 0;
    first_day.tm_hour = 0;
    first_day.tm_mday = 1;
    first_day.tm_mon = month - 1;
    first_day.tm_year = year - 1900;

    time_t first_day_time = mktime(&first_day);

    struct tm *current_date = localtime(&first_day_time);

    // Get the weekday of the first day of the month (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
    int first_weekday = current_date->tm_wday;

    // Print the header with weekday names
    printf("|                                       Su   Mo   Tu   We   Th   Fr   Sa                                          |\n");
            printf("|                                     ");
    // Print spaces for the days before the first day of the month
    for (int i = 0; i < first_weekday; ++i) {
        printf("     ");
    }

    // Print the days of the month
    while (current_date->tm_mon == month - 1) {
        int day = current_date->tm_mday;

        if (day == current_day) {
            printf("\x1b[31m%4d\x1b[0m", day); // Set text color to red for the current day
        } else {
            printf("%4d", day);
        }

        if (current_date->tm_wday == 6) {
            printf("                                          |\n|                                     ");

        } else {
            printf(" ");
        }

        current_date->tm_mday++;
        mktime(current_date); // Update current_date to the next day
    }
     printf("                                                                  |");
}

//=========================================================================================================
int current_calender(){
    system("cls");
    char next,press;


        time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);

    int current_year = local_time->tm_year + 1900;
    int current_month = local_time->tm_mon + 1;
    int current_day = local_time->tm_mday;
    printf(" _________________________________________________________________________________________________________________\n");
     printf("|                  \t                     Current Date:");

red();
        printf("%02d-%02d-%04d", current_day, current_month, current_year);
white();
 printf("                                              |\n");

    live_time();  //function for live time
     printf("|                                                                                                                 |\n");

    printf("|                                            Calendar for %02d-%04d:                                                |\n", current_month, current_year);
    printf("|                                           -----------------------                                               |\n", current_month, current_year);

    print_calendar(current_year, current_month, current_day);



    printf("\n|_________________________________________________________________________________________________________________|\n");




    printf("|                                       To schedule an event  press = ");
   blue();
    printf("S");
white();
     printf("                                           |\n");

    printf("|                                       To simulate a  call   press = ");
   blue();
    printf("C");
white();
     printf("                                           |\n");


    printf("|                                       To simulate a message press = ");
   blue();
    printf("M");
white();
     printf("                                           |\n");


     printf("|");
   blue();
      printf("                                             Press 'Q' to Quit                                                   ");
   white();
   printf("|");
    printf("\n|_________________________________________________________________________________________________________________|\n");


    scanf("%c",&press);
    switch(press){
        case 'S':
                schedule_event();
                break;
        case 's':
            schedule_event();
            break;

        case 'C':
                check_schedule_event();
                break;
        case 'c':
                check_schedule_event();
                break;
        case 'M':
                    message();
            break;
        case 'm':
            message();
            break;
        case 'Q':
                speakText( "Thanks for using me. sayonara");
                return 0;
            break;
        case 'q':
                  speakText( "Thanks for using me. sayonara");
                return 0;
            break;
        default:
                printf("Enter the Write Keyword");
                 scanf("%c",&next);
                if(next=='\n')
                    current_calender();
    }

//======================================================================================================================



}

void schedule_event(){
    system("cls");

    FILE *filePtr;
    struct Database database;
    char next,fileName[] = "database.txt"; // File name to save the data

    // Open the file in append mode
    filePtr = fopen(fileName, "a");

    // Check if the file was opened successfully
    if (filePtr == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }


        // Input information for a person
        printf("Enter Date: ");
        scanf("%d", &database.dd);
        printf("Enter Month: ");
        scanf("%d", &database.mm);
        printf("Enter Year: ");
        scanf("%d", &database.yyyy);
        printf("Time From: ");
        scanf("%f", &database.timefrom);
        printf("Time To: ");
        scanf("%f", &database.timeto);

        printf("Enter Message: ");
        getchar(); // To consume the newline character left by the previous scanf
        fgets(database.message, MAX_SIZE, stdin);

        // Write the data to the file
        fprintf(filePtr, "%d %d %d %f %f %s\n", database.dd, database.mm, database.yyyy, database.timefrom, database.timeto, database.message);

    // Close the file
        fclose(filePtr);

          const char *textToSay = "Gracias! The event has been scheduled";
                speakText(textToSay);


        blue();
            printf("|                                          Press %c to Continue                                                    |",217);
        white();



            scanf("%c",&next);
            if(next=='\n')
                    current_calender();




}
void escapeSingleQuotes(char *text) {
    char *ptr = text;
    while (*ptr != '\0') {
        if (*ptr == '\'') {
            // Replace single quote with two single quotes to escape it
            memmove(ptr + 1, ptr, strlen(ptr) + 1);
            *ptr = '\'';
            ptr += 2;
        } else {
            ptr++;
        }
    }
}

void check_schedule_event(){
    //printf("checked");
      system("cls");



     time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);

    int current_year = local_time->tm_year + 1900;
    int current_month = local_time->tm_mon + 1;
    int current_day = local_time->tm_mday;
    int tm_hour=local_time->tm_hour;
    int tm_min=local_time->tm_min;

    float time=tm_hour+(tm_min/100.0);
  //  printf("%.2f\n",time);

   //

    FILE *filePtr;
    struct Database database;
    char fileName[] = "database.txt"; // File name to save the data


     // Open the file in read mode
    filePtr = fopen(fileName, "r");

    // Check if the file was opened successfully
    if (filePtr == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }

    // Read the first data from the file and print it
    while(!feof(filePtr)){
        if (fscanf(filePtr, "%d %d %d %f %f %[^\n]", &database.dd, &database.mm, &database.yyyy, &database.timefrom, &database.timeto, database.message) == 6)
        {
        if((database.dd==current_day)&&(database.mm==current_month)&&(database.yyyy==current_year)&&(time==database.timefrom||time>database.timefrom)&&(time==database.timeto||time<database.timeto))
         {
              printf("Picked up the call");
               // Escape single quotes in the message
                escapeSingleQuotes(database.message);
                speakText(database.message);
                break;
         }
         else{
          printf("Ringing.....");
           }
        }
    }


    // Close the file
    fclose(filePtr);




}
void message(){
          system("cls");



     time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);

    int current_year = local_time->tm_year + 1900;
    int current_month = local_time->tm_mon + 1;
    int current_day = local_time->tm_mday;
    int tm_hour=local_time->tm_hour;
    int tm_min=local_time->tm_min;

    float time=tm_hour+(tm_min/100.0);
  //  printf("%.2f\n",time);

   //

      FILE *filePtr;
    struct Database database;
    char fileName[] = "database.txt"; // File name to save the data


     // Open the file in read mode
    filePtr = fopen(fileName, "r");

    // Check if the file was opened successfully
    if (filePtr == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }



   // Read the first data from the file and print it
    while(!feof(filePtr)){
        if (fscanf(filePtr, "%d %d %d %f %f %[^\n]", &database.dd, &database.mm, &database.yyyy, &database.timefrom, &database.timeto, database.message) == 6)
        {
        if((database.dd==current_day)&&(database.mm==current_month)&&(database.yyyy==current_year)&&(time==database.timefrom||time>database.timefrom)&&(time==database.timeto||time<database.timeto))
         {
              printf("%s",database.message);
         }

        }
    }

    // Close the file
    fclose(filePtr);

}


int pnt(){



    printf("NEXT FUNCTION NEED TO BE ADDED");

}

int main(){


    welcome_page();
    return 0;
}


/*
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("This line is in red color.\n");
  //  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RESET);

    printf("This line is back to the default color.\n");

    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
   // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);


*/
