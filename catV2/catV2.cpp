#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 5
#define HME_POS    1
#define BWL_PO     (ROOM_WIDTH - 2)

int main(void) {
    printf("****야옹이와 수프****\n");
    printf("      /\\_/\\ \n");
    printf(" /\\  / o o \\ \n");
    printf("//\\\\ \\~(*)~/\n");
    printf("`  \\/     /\n");
    printf("   | \\|| ||\n");
    printf("   \\ '|| ||\n");
    printf("    \\)()-())");

    char str[100];
    printf("야옹이의 이름을 지어 주세요: ");
    scanf_s("%s", &str, 100);
    printf("야옹이의 이름은 %s입니다\n", str);

    Sleep(1000);
    system("cls");

    int x = 0, y = 2;
    int cat = 2;

    while (1) {
        printf(" ==================== 현재 상태 ===================\n");
        printf(" 현재까지 만든 수프: %d개\n", x);
        printf(" 집사와의 관계(0~4): %d\n", y);

        if (y == 0) {
            printf("  곁에 오는 것조차 싫어합니다.\n");
        }
        else if (y == 1) {
            printf("  간식 자판기 취급입니다.\n");
        }
        else if (y == 2) {
            printf("  그럭저럭 쓸 만한 집사입니다.\n");
        }
        else if (y == 3) {
            printf("  훌륭한 집사로 인정 받고 있습니다.\n");
        }
        else if (y == 4) {
            printf("  집사 껌딱지 입니다.\n");
        }
        printf(" ==================================================\n");

        Sleep(500);

        int z = 0;
        int soup = rand() % 3;

        printf("\n%s 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n", str);
        printf(" 주사위 눈이 3 이상이면 냄비쪽으로 이동합니다.\n");

        srand((unsigned int)time(NULL));

        z = rand() % 6 + 1;
        printf(" 주사위를 굴립니다. 또르륵...\n");
        printf(" %d이(가) 나왔습니다!\n", z);

        if (z >= 6 - y) {
            printf("냄비 쪽으로 이동합니다.\n");
            if (cat < BWL_PO) cat++;

            if (cat == BWL_PO) {
                switch (soup) {
                case 0:
                    printf("감자수프를 만들었습니다!\n");
                    break;
                case 1:
                    printf("양송이수프를 만들었습니다!\n");
                    break;
                case 2:
                    printf("브로콜리수프를 만들었습니다!\n");
                    break;
                }
            }

            x++;
        }
        else {
            printf("집 쪽으로 이동합니다.\n");
            if (cat > HME_POS) cat--;
        }

        printf("현재까지 만든 수프: %d개\n", x);
        printf("\n #####\n");
        printf(" #H B#\n");
        printf(" #");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == cat) {
                printf("C");
            }
            else if (i == HME_POS) {
                printf("H");  // 집 위치
            }
            else if (i == BWL_PO) {
                printf("B");  // 냄비 위치
            }
            else {
                printf(" ");  // 빈 공간
            }
        }

        printf("#\n");
        printf(" #####\n");


        Sleep(500);

        int a = 0;
        while (1) {
            printf("\n 어떤 상호작용을 하시겠습니까?  0. 아무것도 하지 않음 1. 긁어 주기\n >> ");
            scanf_s("%d", &a);

            if (a == 0 || a == 1) {
                break;
            }
            else {
                printf("올바른 선택을 입력하세요.\n");
            }
        }

        if (a == 0) {
            printf(" 아무것도 하지 않습니다.\n");
            printf(" 4/6의 확률로 친밀도가 떨어집니다.\n");
            z = rand() % 6 + 1;
            printf(" 주사위를 굴립니다. 또르륵...\n");
            printf(" %d이(가) 나왔습니다!\n", z);
            if (z <= 4) {
                printf(" 친밀도가 떨어집니다.\n");
                if (y > 0) {
                    y--;
                }
            }
            else {
                printf(" 다행히 친밀도가 떨어지지 않았습니다.\n");
            }
        }
        else if (a == 1) {
            printf(" %s의 턱을 긁어주었습니다.\n", str);
            printf(" 2/6의 확률로 친밀도가 높아집니다.\n");
            z = rand() % 6 + 1;
            printf(" 주사위를 굴립니다. 또르륵...\n");
            printf(" %d이(가) 나왔습니다!\n", z);
            if (z >= 5) {
                printf(" 친밀도가 높아집니다.\n");
                if (y < 4) {
                    y++;
                }
            }
            else {
                printf(" 친밀도는 그대로입니다.\n");
            }
        }

        printf(" 현재 친밀도: %d\n", y);

        Sleep(500);
        Sleep(2500);
        system("cls");
    }

    return 0;
}