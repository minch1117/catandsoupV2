#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 5
#define HME_POS    1
#define BWL_PO     (ROOM_WIDTH - 2)

int main(void) {
    printf("****�߿��̿� ����****\n");
    printf("      /\\_/\\ \n");
    printf(" /\\  / o o \\ \n");
    printf("//\\\\ \\~(*)~/\n");
    printf("`  \\/     /\n");
    printf("   | \\|| ||\n");
    printf("   \\ '|| ||\n");
    printf("    \\)()-())");

    char str[100];
    printf("�߿����� �̸��� ���� �ּ���: ");
    scanf_s("%s", &str, 100);
    printf("�߿����� �̸��� %s�Դϴ�\n", str);

    Sleep(1000);
    system("cls");

    int x = 0, y = 2;
    int cat = 2;

    while (1) {
        printf(" ==================== ���� ���� ===================\n");
        printf(" ������� ���� ����: %d��\n", x);
        printf(" ������� ����(0~4): %d\n", y);

        if (y == 0) {
            printf("  �翡 ���� ������ �Ⱦ��մϴ�.\n");
        }
        else if (y == 1) {
            printf("  ���� ���Ǳ� ����Դϴ�.\n");
        }
        else if (y == 2) {
            printf("  �׷����� �� ���� �����Դϴ�.\n");
        }
        else if (y == 3) {
            printf("  �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n");
        }
        else if (y == 4) {
            printf("  ���� ������ �Դϴ�.\n");
        }
        printf(" ==================================================\n");

        Sleep(500);

        int z = 0;
        int soup = rand() % 3;

        printf("\n%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n", str);
        printf(" �ֻ��� ���� 3 �̻��̸� ���������� �̵��մϴ�.\n");

        srand((unsigned int)time(NULL));

        z = rand() % 6 + 1;
        printf(" �ֻ����� �����ϴ�. �Ǹ���...\n");
        printf(" %d��(��) ���Խ��ϴ�!\n", z);

        if (z >= 6 - y) {
            printf("���� ������ �̵��մϴ�.\n");
            if (cat < BWL_PO) cat++;

            if (cat == BWL_PO) {
                switch (soup) {
                case 0:
                    printf("���ڼ����� ��������ϴ�!\n");
                    break;
                case 1:
                    printf("����̼����� ��������ϴ�!\n");
                    break;
                case 2:
                    printf("����ݸ������� ��������ϴ�!\n");
                    break;
                }
            }

            x++;
        }
        else {
            printf("�� ������ �̵��մϴ�.\n");
            if (cat > HME_POS) cat--;
        }

        printf("������� ���� ����: %d��\n", x);
        printf("\n #####\n");
        printf(" #H B#\n");
        printf(" #");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == cat) {
                printf("C");
            }
            else if (i == HME_POS) {
                printf("H");  // �� ��ġ
            }
            else if (i == BWL_PO) {
                printf("B");  // ���� ��ġ
            }
            else {
                printf(" ");  // �� ����
            }
        }

        printf("#\n");
        printf(" #####\n");


        Sleep(500);

        int a = 0;
        while (1) {
            printf("\n � ��ȣ�ۿ��� �Ͻðڽ��ϱ�?  0. �ƹ��͵� ���� ���� 1. �ܾ� �ֱ�\n >> ");
            scanf_s("%d", &a);

            if (a == 0 || a == 1) {
                break;
            }
            else {
                printf("�ùٸ� ������ �Է��ϼ���.\n");
            }
        }

        if (a == 0) {
            printf(" �ƹ��͵� ���� �ʽ��ϴ�.\n");
            printf(" 4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
            z = rand() % 6 + 1;
            printf(" �ֻ����� �����ϴ�. �Ǹ���...\n");
            printf(" %d��(��) ���Խ��ϴ�!\n", z);
            if (z <= 4) {
                printf(" ģ�е��� �������ϴ�.\n");
                if (y > 0) {
                    y--;
                }
            }
            else {
                printf(" ������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
            }
        }
        else if (a == 1) {
            printf(" %s�� ���� �ܾ��־����ϴ�.\n", str);
            printf(" 2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
            z = rand() % 6 + 1;
            printf(" �ֻ����� �����ϴ�. �Ǹ���...\n");
            printf(" %d��(��) ���Խ��ϴ�!\n", z);
            if (z >= 5) {
                printf(" ģ�е��� �������ϴ�.\n");
                if (y < 4) {
                    y++;
                }
            }
            else {
                printf(" ģ�е��� �״���Դϴ�.\n");
            }
        }

        printf(" ���� ģ�е�: %d\n", y);

        Sleep(500);
        Sleep(2500);
        system("cls");
    }

    return 0;
}