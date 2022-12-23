#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "ru");// ������ ��������� �� 
    const char* rome[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    const int arab[13] = { 1000, 900, 500, 400,  100, 90,   50,  40,   10,  9,    5,    4,   1 };
    printf("��� ��������� ��������� ������� ����� � ���������.\n");
    printf("������� ������� ����� ����� ���  M, CM, D, CD, C, XC, L, XL, X, IX, V, IV, I \n");
    char size[256];
    gets_s(size, 256);
    int indexResult = 0, i = 0;  // ��������� � ������ �������� �����
    char* positionOfLine = size;  // ��������� �� ������� ������� ������
    while (*positionOfLine && i < 13)
    {
        while (1) //1 ��� true
        {
            int remainedLenght = strlen(positionOfLine);  // ����� ������� ������
            int romeLength = strlen(rome[i]);  // ����� �������� �����
            if (remainedLenght < romeLength || _strnicmp(positionOfLine, rome[i], romeLength) != 0) { break; }  // ���� ������� ������ ������ ��� � ����� �� ����� ������� �����, ��������� ���� while
            indexResult += arab[i];
            positionOfLine += romeLength;
        }
        ++i;  // � ���������� �������� �����!
    }
    if (*positionOfLine != '\0')
    {
        printf("�������� ����!\n");
    }
    else
    {
        printf("��������� = %d\n", indexResult);
    }
}

