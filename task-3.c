#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int check(const char* s)
{
    char symbol = toupper(s[0]);// ��������� ������ ������. 
    if ((!isdigit(symbol) || symbol == '0') && (symbol < 'A' || symbol > 'E'))
    {
        return 0;
    }

    const char* p = &s[1];  // ��������� �� ������ ������
    int badch = 0, okAfterBadch = 0;  // ��� �� ������ ������ (.), ��� �� ������ ������ ����� ����
    while (*p) {
        symbol = toupper(*p++);  // ��������� ������
        if (!isdigit(symbol) && (symbol < 'A' || symbol > 'E')) // ������ ������
        {
            if (badch) { return 0; }
            badch = 1;
            okAfterBadch = 0;
        }
        else
        {
            okAfterBadch = 1;
        }
    }
    return okAfterBadch;
}

int main()
{
    setlocale(LC_ALL, "ru");
    printf("��� ��������� ��������� �������� ������� , ���������� ��������� ���������� ���������� \n [1-9 A-E a-e][0-9 A-E a-e]*.[0-9 A-E a-e]+ \n");
    printf("������� ������:");
    char s[256];
    gets_s(s, 256);  // ���� ������
    printf("1 - ��� �����!\n");
    printf("0 - �� �����!\n\n");
    printf("��������� = %d", check(s));
}
