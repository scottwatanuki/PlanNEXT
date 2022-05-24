//Import libraries from CS50
#include <stdio.h> // printf
#include <cs50.h> // get_char, get_float, get_string, get_int
#include <string.h> // strlen
#include <math.h> // round
#include <ctype.h> // isalpha

// Declaration of a new function that'll calculate the necessary amount of sleep needed according to the user's age.
void sleep(string name, int age, int sleepHours);

// Declaration of a new function that will create the schedule and the assignment sheet.
void schedule(string name, int age, int wakeH, int wakeM, int bedH, int bedM);

// Main function definition.
int main(int argc, string argv[])
{
    // Checks to see if there are two arguments inputted into the command line argument
    string name = argv[1];

    // Prints the proper usage and return error if there aren't 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./plan name\n");
        return 1;
    }
    // Checks for all of the characters in the command line input to be alphabets.
    // If not, print the proper usage and return error
    else if (argc == 2)
    {
            for (int i = 0; i < strlen(name); i++)
            {
                if (!isalpha(name[i]))
                {
                    printf("Usage: ./plan name\n");
                    return 1;
                }
            }
        printf("\nHello %s!\n", name); // Prints greeting.
    }
    printf("Answer these questions so we can create a personalized schedule for you!\n\n");

    // Asks for the age of the user and evaluates the how much sleep is needed accordingly.
    float age = get_float("What's your age?: ");
    age = (int) round(age); // Rounds the age if needed.
    int sleepHours = 0; // Initialization of variable for recommended hours of sleep.
    // If the user's age is 6-13, then set sleepHours variable to 9.
    if ((6 <= age) && (age <= 13))
    {
        sleepHours = 9;
    }
    // If the user's age is 14-17, then set sleepHours variable to 8.
    else if ((14 <= age) && (age <= 17))
    {
        sleepHours = 8;
    }
    // If the user's age is 18+, then set sleepHours variable to 7.
    else if (age >= 18)
    {
        sleepHours = 7;
    }
    // If the inputted age is not between 6+, then print proper usage and ask for age again.
    else
    {
        printf("Usage: enter your age");
        age = get_float("\nWhat's you age?: ");
        age = (int) round(age);
    }

    // Calls the sleep function.
    sleep(name, age, sleepHours);
}

// Sleep function definition.
void sleep(string name, int age, int sleepHours)
{
    // Variables to ask for wakeup and bed time of the user.
    int wakeH = get_int("Enter the time you wakeup in the hours place: (ex: enter 6 for 6am): ");
    int wakeM = get_int("Enter the time you wake up in the minutes place: (ex: enter 30 for 6:30am): ");
    int bedH = get_int("Enter your bed time in the hours place: (ex: enter 22 for 10pm): ");
    int bedM = get_int("Enter your bed time in minutes place: (ex: enter 30 for 10:30pm): ");

    // If the wakeup minutes is greater than the bedtime minutes,
    // subtract one from the wake-up hours and add 60 to the wake-up minutes so it can be subtracted properly
    if (wakeM > bedM)
    {
    	wakeH = wakeH - 1;
    	wakeM = wakeM + 60;
    }

    // **The sleep criteria used below were derived from the National Sleep Foundation.

    // Otherwise, if the amount of sleep calculated from the wake-up and bedtime is less than
    // the minimum recommended sleep hours for the user's age,
    // then ask for an adjusted bedtime that'll meet the minimum amount of sleep
    // as recommended by the National Sleep Foundation.
    if (24 - (bedH - wakeH) < sleepHours)
    {
        // A do-while loop is used to ask for a new bedtime until the amount of sleep hours exceeds
        // the minimum amount of sleep required for the user's age group.
        do
        {
        	if (sleepHours == 9)
        	{
        		bedH = get_int("A minimum of 9 hours of sleep is recommended for ages 6-13. \nEnter the hours place for your new bed time: ");
        		bedM = get_int("Enter the minutes for your new bed time: ");
        	}
        	else if (sleepHours == 8)
        	{
        		bedH = get_int("A minimum of 8 hours of sleep is recommended for ages 14-17. \nEnter the hours place for your new bed time: ");
        		bedM = get_int("Enter the minutes for your new bed time: ");
        	}
        	else if (sleepHours == 7)
        	{
        		bedH = get_int("A minimum of 7 hours of sleep is recommended for ages 18+. \nEnter the hours place for your new bed time: ");
        		bedM = get_int("Enter the minutes for your new bed time: ");
        	}
        }
        while (24- (bedH - wakeH) < sleepHours);
    }
    schedule(name, age, wakeH, wakeM, bedH, bedM);
}

// Scheduler function definition
void schedule(string name, int age, int wakeH, int wakeM, int bedH, int bedM)
{
    // Declare variables used for asking and saving event information. Then ask if the user has an event after school.
    string yes = ("yes");
    string no = ("no");
    string eventName, startTime, endTime;
    string event = get_string("\nDo you have an event after school?\n(yes/no): ");

    // If the user has an event, then ask for the name, start, and end time of the event.
    if (strcmp(event, yes) == 0)
    {
        eventName = get_string("What is the name of the event?: ");
        startTime = get_string("Please enter the start time for your event (ex. 15:10): ");
        endTime = get_string("Please enter the end time for your event (ex. 16:00): ");
    }

    // If not, then break out of the while loop and move on to the rest of the program.
    else if (strcmp(event, no) == 0)
    {
        while (strcmp(event, no) == 0)
        {
            break;
        }
    }

    // Otherwise, print the proper usage and ask for input again.
    else
    {
        printf("Usage: yes or no");
        event = get_string("\nDo you have an event after school?\n(yes/no): ");
    }

    // Declaration of an array (list) that stores questions that'll be asked in a for-loop below.
    string question[] = {
        "\n#1: Do you have a period 1 class? ",
        "\n#2: Do you have a period 2 class? ",
        "\n#3: Do you have a period 3 class? ",
        "\n#4: Do you have a period 4 class? ",
        "\n#5: Do you have a period 5 class? ",
        "\n#6: Do you have a period 6 class? ",
        "\n#7: Do you have a period 7 class? ",
        "\n#8: Do you have a period 8 class? ", };

    // Declaration of two arrays that will be used in the for-loop below to store data.
    string period[8];
    string taskPeriod[8];
    string answer = "error";

    // For-loop that will ask if the user has a class for the corresponding periods.
    for (int i = 0; i < 8; i++)
    {
        // Ask if the user has a class for the given period.
        answer = get_string("%s\n(yes/no): ", question[i]);

        // If the user has a class for a given period, then ask for the name of the class and the assignments from that class.
        if (strcmp(answer, yes) == 0)
        {
            period[i] = get_string("Enter the name of the class: ");
            taskPeriod[i] = get_string("Enter the assignments from %s: ", period[i]);
        }

        // If a user doesn't have a class for a given period, then save the class as a free period and save none for assignments.
        else if (strcmp(answer, no) == 0)
        {
            period[i] = ("Free");
            taskPeriod[i] = ("none");
        }

        // Otherwise, print the proper usage and ask for input again.
        else
        {
            printf("Usage: yes/no");
            answer = get_string("%s\n(yes/no): ", question[i]);
        }
    }

    // Ask the user for the bell schedule of the day. Then print the according schedule.
    char day = get_char("\nWhat's today's bell schedule?\nA. A Day\nB. B Day\nC. C Day\nD. D Day\n(A/B/C/D): ");
    if (day == 'A')
    {
        printf("\n~ %s's Classes ~\nHomeroom\n    7:40 - 8:10\n%s\n    8:20 - 9:12\n%s\n    9:20 - 10:12\n%s\n    10:20 - 11:12\n%s\n    11:20 - 12:12\nLunch\n    12:12 - 13:00\n%s\n    13:08 - 14:00\n%s\n    14:08 - 15:00\n", name, period[0], period[1], period[2], period[3], period[4], period[5]);
    }
    else if (day == 'B')
    {
        printf("\n~ %s's Classes ~\nHomeroom\n    7:40 - 8:10\n%s\n    8:20 - 9:12\n%s\n    9:20 - 10:12\n%s\n    10:20 - 11:12\n%s\n    11:20 - 12:12\nLunch\n    12:12 - 13:00\n%s\n    13:08 - 14:00\n%s\n    14:08 - 15:00\n", name, period[6], period[7], period[0], period[1], period[2], period[3]);
    }
    else if (day == 'C')
    {
        printf("\n~ %s's Classes ~\nHomeroom\n    7:40 - 8:10\n%s\n    8:20 - 9:12\n%s\n    9:20 - 10:12\n%s\n    10:20 - 11:12\n%s\n    11:20 - 12:12\nLunch\n    12:12 - 13:00\n%s\n    13:08 - 14:00\n%s\n    14:08 - 15:00\n", name, period[4], period[5], period[6], period[7], period[0], period[1]);
    }
    else if (day == 'D')
    {
        printf("\n~ %s's Classes ~\nHomeroom\n    7:40 - 8:10\n%s\n    8:20 - 9:12\n%s\n    9:20 - 10:12\n%s\n    10:20 - 11:12\n%s\n    11:20 - 12:12\nLunch\n    12:12 - 13:00\n%s\n    13:08 - 14:00\n%s\n    14:08 - 15:00\n", name, period[2], period[3], period[4], period[5], period[6], period[7]);
    }
    else
    {
        printf("\nUsage: A/B/C/D\n");
        day = get_char("\nWhat's today's bell schedule?\nA. A Day\nB. B Day\nC. C Day\nD. D Day\n(A/B/C/D): ");
    }

    // Print the assignment sheet according to what the user answered earlier in the program.
    printf("\n~ %s's Assignment Sheet ~\n    %s: %s\n  \n    %s: %s\n  \n    %s: %s\n  \n    %s: %s\n  \n    %s: %s\n  \n    %s: %s\n  \n    %s: %s\n  \n    %s: %s\n", name, period[0], taskPeriod[0], period[1], taskPeriod[1], period[2], taskPeriod[2], period[3], taskPeriod[3], period[4], taskPeriod[4], period[5], taskPeriod[5], period[6], taskPeriod[6], period[7], taskPeriod[7]);

    // Print a personalized schedule for the user. If the user has an event after school, then input the event into the schedule.
    if (strcmp(event, yes) == 0)
    {
        printf("\n~ %s's Schedule ~\nWakeup\n    %i:%02d\nSchool: %c Day\n    7:40 - 15:00\n%s\n    %s - %s\nSleep\n    %i:%02d\n", name, wakeH, wakeM, day, eventName, startTime, endTime, bedH, bedM);
    }
    else if (strcmp(event, no) == 0)
    {
        printf("\n~ %s's Schedule ~\nWakeup\n    %i:%02d\nSchool: %c Day\n    7:40 - 15:00\nSleep\n    %i:%02d\n", name, wakeH, wakeM, day, bedH, bedM);
    }

    printf("\nA special thanks to %s for using PlanNEXT!\n", name); // Print thank you message.
}