#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct 
{
    int category;
    int choice;
    float value;
    float result;
    time_t timestamp;
} Conversion;


typedef struct Node {
    Conversion data;
    struct Node* next;
} Node;

Node* top = NULL;


void push(Conversion conv) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = conv;
    newNode->data.timestamp = time(NULL);
    newNode->next = top;
    top = newNode;
}


void displayHistory() {
    Node* current = top;
    printf("\n--- Conversion History ---\n");
    while (current != NULL) {
        printf("Timestamp: %s", ctime(&(current->data.timestamp)));
        printf("Category: %d, Choice: %d, Value: %.2f, Result: %.2f\n\n",
               current->data.category, current->data.choice, current->data.value, current->data.result);
        current = current->next;
    }
    printf("\n\n");
}

int main() 
{
    int category;    
    int tempChoice;
    int lengthChoice;
    int massChoice;
    float userinputF;
    float userinputC;
    float userinputmeterTocentimeter;
    float userinputcentimeterTometer;
    float userinputkilometerTometer;
    float userinputkilograms;
    float userinputgrams;
    float fahrenheitToCelcius;
    float celciusToFahrenheit;
    float centimeterTometer;
    float meterTocentimeter;
    float kilometerTometer;
    float kilogramstograms;
    float gramsTokilograms;

    printf("WELCOME TO UNIT CONVERTER! \n\n\n");
    while(1)
    {
        
    printf("Unit Converter menu: \n");
    printf("1.Temperature(T)\n");
    printf("2.Length(L) \n"); 
    printf("3.Mass(M) \n");
    printf("4.Display \n");  
    printf("5.Exit \n");  
    printf("Enter your category:");
    scanf(" %d", &category);

    switch(category)
    {
        case 1:
            printf("Welcome to Temperature Converter! \n");
            printf("Here is a list of conversations to choose from: \n");
            printf("Enter 1 for Fahrenheit to Celsius. \n");
            printf("Enter 2 for Celsius to Fahrenheit. \n");
            scanf("%d", &tempChoice);
            if (tempChoice == 1)
            {
                printf("Please enter the Fahrenheit degree: ");
                scanf("%f", &userinputF);
                fahrenheitToCelcius = ((userinputF - 32) * (5.0 / 9.0));
                printf("Celcius: %.2f\n\n", fahrenheitToCelcius);
                Conversion conv = {category, tempChoice, userinputF, fahrenheitToCelcius};
                push(conv);
            }
            else if (tempChoice == 2)
            {
                printf("Please enter the Celsius degree: ");
                scanf("%f", &userinputC);
                celciusToFahrenheit = ((9.0 / 5.0) * userinputC + 32);
                printf("Fahrenheit: %.2f\n\n", celciusToFahrenheit);
                Conversion conv = {category, tempChoice, userinputC, celciusToFahrenheit};
                push(conv);
            }
            else
                printf("Please enter the correct choice. \n\n");
            break;
        case 2:
            printf("Welcome to Length Converter! \n");
            printf("Here is a list of conversations to choose from: \n");
            printf("Enter 1 for Meter to Centimeter. \n");
            printf("Enter 2 for Centimeter to Meter. \n");
            printf("Enter 3 for Kilometer to Meter. \n");
            scanf("%d", &lengthChoice);
            if (lengthChoice == 1) 
            {
                printf("Please enter the length in meter: ");
                scanf("%f", &userinputmeterTocentimeter);
                centimeterTometer = userinputmeterTocentimeter * 100;
                printf("Centimeter: %.2f\n\n", centimeterTometer);
                Conversion conv = {category, lengthChoice, userinputmeterTocentimeter, centimeterTometer};
                push(conv);
            }
            else if (lengthChoice == 2) 
            {
                printf("Please enter the length in centimeter: ");
                scanf("%f", &userinputcentimeterTometer);
                meterTocentimeter = userinputcentimeterTometer / 100;
                printf("Meter: %.2f\n\n", meterTocentimeter);
                Conversion conv = {category, lengthChoice, userinputcentimeterTometer, meterTocentimeter};
                push(conv);
            }
            else if (lengthChoice == 3) 
            {
                printf("Please enter the length in kilometer: ");
                scanf("%f", &userinputkilometerTometer);
                kilometerTometer = userinputkilometerTometer * 1000;
                printf("Meter: %.2f\n\n", kilometerTometer);
                Conversion conv = {category, lengthChoice, userinputkilometerTometer, kilometerTometer};
                push(conv);
            }
            else
                printf("Please enter the correct choice. \n\n");
            break;
        case 3:
            printf("Welcome to Mass Converter! \n");
            printf("Here is a list of conversations to choose from: \n");
            printf("Enter 1 for Kilograms to Grams. \n");
            printf("Enter 2 for Grams to Kilograms. \n");
            scanf("%d", &massChoice);
            if (massChoice == 1) 
            {
                printf("Please enter the mass in kilograms: ");
                scanf("%f", &userinputkilograms);
                kilogramstograms = userinputkilograms * 1000;
                printf("Grams: %.2f\n\n", kilogramstograms);
                Conversion conv = {category, massChoice, userinputkilograms, kilogramstograms};
                push(conv);
            }
            else if (massChoice == 2) 
            {
                printf("Please enter the mass in grams: ");
                scanf("%f", &userinputgrams);
                gramsTokilograms = userinputgrams / 1000;
                printf("Kilograms: %.2f\n\n", gramsTokilograms);
                Conversion conv = {category, massChoice, userinputgrams, gramsTokilograms};
                push(conv);
            }
            else
                printf("Please enter the correct choice. \n\n");
            break;

        case 4:
            displayHistory();
            break;

        case 5:
            printf("Exiting program. \n");
            return 0;

        default:
             printf("Invalid choice. \n");
                  
    }
    }
return 0;
}
