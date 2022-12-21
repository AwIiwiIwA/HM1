#include <string.h>
#include <stdio.h>

#define binarySize 256


int transformation2ndWay(char* binary, char* octale)	//https://calcus.ru/perevod-sistem-schisleniya/iz-dvoichnoy-v-vosmerichnuyu here i took a way to transformation (2nd way)
{
int result = 0;
int length = strlen(binary);
if (length != 3) 
{
    return -1;
}
for (int i = 2; i >= 0; --i)
{
    if (binary[i] != '1' && binary[i] != '0')
    {
        return -1;
    }
    if (binary[2 - i] == '1')
    {
        int exponent = i;
        int sum = 1;
        while (exponent > 0)
        {
            sum *= 2;
            --exponent;
        }
        result += sum;
    }
    *octale = result + 48;
}
return 0;
}
int binaryToOctale(char* binary, char* octale) //next step i am transformation binary to oactale
{
int length = strlen(binary);
int currentPosition = length % 3;
int currentIndex = 1;
char secondWay[4] = "000";
int error = 0;
switch (currentPosition)
{
case 1:
{
    secondWay[2] = binary[0];
    error = transformation2ndWay(secondWay, &(octale[0]));
    break;
}
case 2:
{
    secondWay[1] = binary[0];
    secondWay[2] = binary[1];
    error = transformation2ndWay(secondWay, &(octale[0]));
    break;
}
default:
    currentIndex = 0;
    break;
}

if (error != 0)
{
    printf("Wrong input value.\n Try again...");
    return -1;
}

for (currentPosition; currentPosition < length; currentPosition += 3)
{
    secondWay[0] = binary[currentPosition];
    secondWay[1] = binary[currentPosition + 1];
    secondWay[2] = binary[currentPosition + 2];
    error = transformation2ndWay(secondWay, &(octale[currentIndex]));
    if (error != 0)
    {
        printf("Wrong input\n");
        return -1;
    }
    ++currentIndex;
}
return 0;
}

int main()
{
    char binaryNumber[257] = { 0 };
    char octalNumber[33] = { 0 };
    printf("Hi, please enter a binary number(no longer than %d):\n", binarySize - 1);
    scanf_s("%s", binaryNumber); //scanf dont working in my VS

    int error = binaryToOctale(binaryNumber, octalNumber);

    if (error != 0)
    {
        return -1;
    }

    printf("\nOctale number is: %s\n", octalNumber);
}
