#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "ru");
    printf("��� ��������� ���� �������� ����� �������.\n\n");
    FILE* f;
    if (fopen_s(&f, "matrix.txt", "r") != 0)// ��������� ���� ��� ������
    {
        printf("������ �������� �����!\n");
        return -1;
    }
    int rows, cols = 0;
    if (fscanf_s(f, "%d %d\n", &rows, &cols) < 2 || rows < 1 || cols < 1)  // ������ ���-�� ����� � ��������
    {
        printf("���-�� ����� ��� �������� �� ����� ���� ������ 1 (��� �� ���)!\n");
        return -1;
    }
    int* matrix = (int*)
        malloc(rows * cols * sizeof(int));  // ������ ������ �� �����

    for (int j = 0; j < rows; ++j)
    {
        for (int i = 0; i < cols; ++i)
        {
            if (fscanf_s(f, "%d", &matrix[i + j * cols]) < 1)
            {
                printf("������ ������ (���� ������?)!\n");
                return -1;
            }
        }
    }
    for (int j = 0; j < rows; ++j)
    {
        int min, max;  // ���\���� �������� � ������
        min = matrix[j * cols];
        max = min;
        for (int i = 1; i < cols; ++i) // �������
        {
            if (matrix[i + j * cols] < min)// ������� � ������
            {
                min = matrix[i + j * cols];
            }
            if (matrix[i + j * cols] > max)// �������� � ������
            {
                max = matrix[i + j * cols];
            }
        }
        for (int i = 0; i < cols; ++i)
        {
            int saddlePoint = 0;  // �������� �����? (1/0)
            if (matrix[i + j * cols] == min)
            {
                saddlePoint = 1;
                for (int k = 0; k < rows; ++k)
                {
                    if (min < matrix[i + k * cols])
                    {
                        saddlePoint = 0;  // �� ������������ � �������
                        break;
                    }
                }
            }
            if (!saddlePoint && matrix[i + j * cols] == max)
            {
                saddlePoint = 1;
                for (int k = 0; k < rows; ++k)
                {
                    if (max > matrix[i + k * cols])
                    {
                        saddlePoint = 0;  // �� ����������� � �������
                        break;
                    }
                }
            }
            if (saddlePoint)
            {
                printf("�������� ����� � ������ %d ������� %d = %d\n", j + 1, i + 1, matrix[i + j * cols]);
            }
        }
    }
}
