#include "common.h"
void games()
{
    srand((unsigned)time(NULL));
    static int num = -1;
    num++;
    if (num == 14)
        num = 0;
    switch (num)
    {
    case 0:
    {
        system("cls");
        printf("\n\n\n\n\n\n\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        printf("                               ��             **������ ����������**             ��\n");
        printf("                               ��                   ���ǽº�                    ��\n");
        printf("                               ��                    3��2��                     ��\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        int x = 45, y = 9, ch;
        while (1)
        {
            gotoxy(x, y);
            printf(">\b");
            ch = _getch();
            if (ch == 224)
            {
                printf(" ");
                ch = _getch();
                switch (ch)
                {
                case UP:
                    if (y > 9)
                        y--;
                    break;
                case DOWN:
                    if (y < 10)
                        y++;
                    break;
                case LEFT:
                case RIGHT:
                    break;
                }
            }
            else if (ch == 13)
                break;
        }
        if (y == 9)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n");
            printf("                       �ڼҿ� �������� ���ϱ� ���� ������ġ���� ���� �ʴ� ���! ���� �����̽ñ���!\n\n");
            Sleep(3000);
            int a, b, c;
            a = rand() % 3;
            printf("                                              ����: 0, ����: 1, ��: 2\n");
            printf("                                         �����������߿� �� ���ڸ� �Է��ϼ���: ");
            scanf("%d", &b);
            getchar();

            if ((a == 0 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 0))
                c = 0;
            else if ((a == 1 && b == 0) || (a == 2 && b == 1) || (a == 0 && b == 2))
                c = 1;
            else
                c = 2;

            system("cls");
            printf("\n\n\n\n\n\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
            printf("                                                Ÿ�뽺�� ����: %d\n", a);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            printf("                                                   ���: %d\n", b);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            switch (c)
            {
            case 0:
                life--;
                printf("                       Ÿ�뽺�� ���ϰ� �̰���ϴ�... ���� �Ѱ��� �����̽��ϴ�...�ƽ��׿�;;\n\n");
                break;
            case 1:
                printf("                                               ��̾��� �̱�̳׿�;;\n");
                Sleep(1000);
                printf("                                   ��� ���ư��� �ڼҿ� �������� �����ϼ���!\n\n");
                break;
            case 2:
                printf("                           �ڼҿ� �������� �츮�ڴٴ� ������ ���� �����ڰ� ������ �Ծ����ϴ� �Ф�. \n                            ���ºθ� �ϼ����� �������� �������� �¸��� ����մϴ�! ��� ���ư�����! \n\n");
                break;
            }
        }
        else
        {
            system("cls");
            int c = 0, d = 0;
            while (1)
            {
                int a, b;
                a = rand() % 3;
                printf("\n\n\n\n");
                printf("                                             ����: 0, ����: 1, ��: 2\n");
                printf("                                        �����������߿� �� ���ڸ� �Է��ϼ���: ");
                scanf("%d", &b);
                getchar();

                if ((a == 0 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 0))
                    c++;
                else if ((a == 1 && b == 0) || (a == 2 && b == 1) || (a == 0 && b == 2))
                    d++;

                system("cls");
                printf("\n\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
                printf("                                                Ÿ�뽺�� ����: %d\n", a);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                printf("                                                   ���: %d\n", b);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                if (c > d)
                    printf("                                          �� �� �� ���� �� ������...\n\n");
                else if (c < d)
                    printf("                                           �ϴ� �� �� ��������\n\n");
                else
                    printf("                                                    ���º�\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                printf("                                          (Ÿ�뽺�� ����) %d : %d (���)", c, d);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                if (c == 2)
                {
                    life--;
                    printf("\n\n                                        3�� 2���ϰ� ����?? �� ������...\n                                         ���� �Ѱ��� ���ҽ�ŵ�ϴ�...");
                    break;
                }
                else if (d == 2)
                {
                    printf("\n                                              �̰��? �ʹ� ������ ^^");
                    break;
                }
            }
        }
        break;
    }
    case 1:
    {
        system("cls");
        int i, a, b, c, d;
        printf("\n\n\n\n\n\n\n\n\n                                        ������ ���� ���ڵ��� ������� ������ּ���\n");
        a = (rand() % 9 + 1);
        c = a;
        Sleep(2000);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n                                                           %d", a);
        Sleep(1000);
        system("cls");

        for (i = 0; i < 4; i++)
        {
            b = rand() % 3;

            switch (b)
            {
            case 0:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n                                                           +");
                break;
            case 1:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n                                                           -");
                break;
            case 2:
                printf("\n\n\n\n\n\n\n\n\n\n\n\n                                                           X");
                break;
            }
            Sleep(500);
            system("cls");

            a = (rand() % 9 + 1);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n                                                           %d", a);

            switch (b)
            {
            case 0:
                c += a;
                break;
            case 1:
                c -= a;
                break;
            case 2:
                c *= a;
                break;
            }
            Sleep(1000);
            system("cls");
        }
        printf("\n\n\n\n\n\n\n\n\n                                                    ��� �����? : ");
        scanf("%d", &d);
        getchar();
        if (c == d)
            printf("\n                                  �̰� ����? ���� �Ǳ����б� �İ��� �ƴϳ�~ ��� ����!!");
        else
        {
            life--;
            printf("\n                                               ...�ƽ����� ��.��.��.��\n                         �ڼҿ� �������� ���� ���߷��� �����ϳ׿�... ���� �� ���� �����ϰ� �ҽ��ϴ�(�Ǹ�)...");
        }
        break;
    }
    case 2:
    {
        system("cls");
        int i, a, b;
        a = (rand() % 100 + 1);
        for (i = 0; i < 7; i++)
        {
            printf("\n\n\n\n\n\n\n\n\n                                 ���ڸ� �Է��ϼ���!!(1~100) 7���� ��ȸ�� �־����ϴ�: ");
            scanf("%d", &b);
            getchar();
            if (a < b)
                printf("\n                                                      �ٿ�ٿ�");
            else if (a == b)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
                printf("\n                                            �̰� ���ߴٴ� õ�簡 �и��ϳ׿�!");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
            }
            else
                printf("\n                                                        ����");
            Sleep(2000);
            system("cls");
        }
        if (i == 7)
        {
            life--;
            printf("\n\n\n\n\n\n\n\n\n                                                7���̳� ��ȸ�� ��µ�...;;\n");
            Sleep(1000);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            printf("\n                                          �ڼҿ� �������� �� ���ϰ� �����Ŵ�!!? \n                                                  ���� �� ���� �ҽ��ϴ�");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        break;
    }
    case 3:
    {
        char player[100];
        char answer[13] = "ĸ���̽�";

        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                  �ͼ��� ���� \n");
        printf("                                         ���� ���� �丸 �Է����ּ��� \n");
        printf("                                       ���� ���� ������ ���̿� �Ź��� �θ�?\n");

        scanf("%s", player);
        getchar();

        if (strcmp(player, answer) == 0)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                       �����Դϴ�! ������� �����ñ���!!");
        }
        else
        {
            system("cls");
            life--;
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                              ��! ���� %s �Դϴ�.\n                                         Ʋ�ȴٰ� ������������� ���ݾƿ� ����\n                                             ���� �Ѱ��� �����մϴ�...", answer);
        }
        break;
    }
    case 4:
    {
        int a, b;
        printf("\n\n\n\n\n\n\n                                   �ֻ��������Դϴ�. ���ڰ� ũ�ų� ������ �¸��մϴ�!\n");
        a = (rand() % 6 + 1);
        printf("\n                                                          (%d)\n\n", a);
        Sleep(2000);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
        printf("                                              ���Ҷ� Ű���带 �����ּ���!!\n\n");
        while (1)
        {
            b = (rand() % 6 + 1);
            printf("                                                          (%d)", b);
            printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            if (_kbhit())
                break;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\n");
        if (a <= b)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
            printf("                                                   �¸��ϼ̽��ϴ�!");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            Sleep(2000);
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
            printf("                                                      ��Ÿ���׿�!");
            life--;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            Sleep(2000);
        }
        getchar();
        break;
    }

    case 5:
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                   c++ ���� \n");
        printf("                                    <stdlib.h> �ȿ� ������ �����ϴ� �Լ���?   \n\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        printf("                               ��                    printf()                   ��\n");
        printf("                               ��                    gets_s()                   ��\n");
        printf("                               ��                     rand()                    ��\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        int x = 45, y = 13, ch;
        while (1)
        {
            gotoxy(x, y);
            printf(">\b");
            ch = _getch();
            if (ch == 224)
            {
                printf(" ");
                ch = _getch();
                switch (ch)
                {
                case UP:
                    if (y > 13)
                        y--;
                    break;
                case DOWN:
                    if (y < 15)
                        y++;
                    break;
                case LEFT:
                case RIGHT:
                    break;
                }
            }
            else if (ch == 13)
            {
                if (y == 15)
                {
                    system("cls");
                    printf("\n");
                    printf("                              �ڼҿ� ������ ������ �����ϼ̱���? ��� ���ư��ּ���!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                             �̰� �ƴ���...���� = rand(), �ʵ��л��� �ƴµ� �Ǽ� �Ѱ���?\n                                       �ϴ� ���� �Ѱ� �������Կ�...\n");
                    Sleep(2000);
                }
                break;
            }
        }
        break;
    }
    case 6:
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                   c++ ���� \n");
        printf("                             ���� �̽������� ������ �� ���� �� ó������ ���ư��� ����? \n\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        printf("                               ��                      \\n                       ��\n");
        printf("                               ��                      \\t                       ��\n");
        printf("                               ��                      \\r                       ��\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        int x = 45, y = 13, ch;
        while (1)
        {
            gotoxy(x, y);
            printf(">\b");
            ch = _getch();
            if (ch == 224)
            {
                printf(" ");
                ch = _getch();
                switch (ch)
                {
                case UP:
                    if (y > 13)
                        y--;
                    break;
                case DOWN:
                    if (y < 15)
                        y++;
                    break;
                case LEFT:
                case RIGHT:
                    break;
                }
            }
            else if (ch == 13)
            {
                if (y == 15)
                {
                    system("cls");
                    printf("\n");
                    printf("                              �ڼҿ� ������ ������ �����ϼ̱���? ��� ���ư��ּ���!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                             �̰� �ƴ���.. �� ù�� = \\t, �ʵ��л��� �ƴµ� �Ǽ� �Ѱ���?\n                                       �ϴ� ���� �Ѱ� �������Կ�...\n");
                    Sleep(2000);
                }
                break;
            }
        }
        break;
    }
    case 7:
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                   c++ ���� \n");
        printf("                       ���� �ð��� �������� �Լ��� ����ϱ� ���� ����� �ϴ� ���̺귯����? \n\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        printf("                               ��                  <stdlib.h>                   ��\n");
        printf("                               ��                  < time.h >                   ��\n");
        printf("                               ��                  < stdio.h>                   ��\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        int x = 45, y = 13, ch;
        while (1)
        {
            gotoxy(x, y);
            printf(">\b");
            ch = _getch();
            if (ch == 224)
            {
                printf(" ");
                ch = _getch();
                switch (ch)
                {
                case UP:
                    if (y > 13)
                        y--;
                    break;
                case DOWN:
                    if (y < 15)
                        y++;
                    break;
                case LEFT:
                case RIGHT:
                    break;
                }
            }
            else if (ch == 13)
            {
                if (y == 14)
                {
                    system("cls");
                    printf("\n");
                    printf("                              �ڼҿ� ������ ������ �����ϼ̱���? ��� ���ư��ּ���!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    printf("\n");
                    printf("                             �̰� �ƴ���.. �ð� = time, �ʵ��л��� �ƴµ� �Ǽ� �Ѱ���?\n                                       �ϴ� ���� �Ѱ� �������Կ�...\n");
                    Sleep(2000);
                }
                break;
            }
        }
        break;
    }
    case 8:
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                 ���ڼ��� ���� \n");
        printf("                     �Ҿȡ��ٽ� ������ �ڸ��� ������ �ɾ� ������ ���ϴ� ���� ���ϴ� ���ڼ����? \n\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        printf("                               ��                   �������                    ��\n");
        printf("                               ��                   ���ʱ���                    ��\n");
        printf("                               ��                   �ºҾȼ�                    ��\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        int x = 45, y = 13, ch;
        while (1)
        {
            gotoxy(x, y);
            printf(">\b");
            ch = _getch();
            if (ch == 224)
            {
                printf(" ");
                ch = _getch();
                switch (ch)
                {
                case UP:
                    if (y > 13)
                        y--;
                    break;
                case DOWN:
                    if (y < 15)
                        y++;
                    break;
                case LEFT:
                case RIGHT:
                    break;
                }
            }
            else if (ch == 13)
            {
                if (y == 15)
                {
                    system("cls");
                    printf("\n");
                    printf("                             �����Դϴ�! �İ����� ������ �����ص� �ջ������� ���׿�!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                                      �߸� �����Ű���? �̰� �� ���⸮��...\n                                      �ϴ� �ϰ� ���� �Ѱ� ���ҽ�ų�Կ�...\n");
                    Sleep(2000);
                }
                break;
            }
        }
        break;
    }
    case 9:
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                 ���ڼ��� ���� \n");
        printf("                             �׾������ ������ ���� �ʰ� ���´ٴ� ���� ���ڼ����? \n\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        printf("                               ��                   ���ʺ���                    ��\n");
        printf("                               ��                   øø����                    ��\n");
        printf("                               ��                   ��������                    ��\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        int x = 45, y = 13, ch;
        while (1)
        {
            gotoxy(x, y);
            printf(">\b");
            ch = _getch();
            if (ch == 224)
            {
                printf(" ");
                ch = _getch();
                switch (ch)
                {
                case UP:
                    if (y > 13)
                        y--;
                    break;
                case DOWN:
                    if (y < 15)
                        y++;
                    break;
                case LEFT:
                case RIGHT:
                    break;
                }
            }
            else if (ch == 13)
            {
                if (y == 13)
                {
                    system("cls");
                    printf("\n");
                    printf("                             �����Դϴ�! �İ����� ������ �����ص� �ջ������� ���׿�!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                                      �߸� �����Ű���? �̰� �� ���⸮��...\n                                      �ϴ� �ϰ� ���� �Ѱ� ���ҽ�ų�Կ�...\n");
                    Sleep(2000);
                }
                break;
            }
        }
        break;
    }
    case 10:
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                 ���ڼ��� ���� \n");
        printf("                            �������� ������ ������ ����� �ϴ� ��Ȳ�� ���� ���ڼ����? \n\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        printf("                               ��                   ��������                    ��\n");
        printf("                               ��                   ����ط�                    ��\n");
        printf("                               ��                   ��������                    ��\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        int x = 45, y = 13, ch;
        while (1)
        {
            gotoxy(x, y);
            printf(">\b");
            ch = _getch();
            if (ch == 224)
            {
                printf(" ");
                ch = _getch();
                switch (ch)
                {
                case UP:
                    if (y > 13)
                        y--;
                    break;
                case DOWN:
                    if (y < 15)
                        y++;
                    break;
                case LEFT:
                case RIGHT:
                    break;
                }
            }
            else if (ch == 13)
            {
                if (y == 13)
                {
                    system("cls");
                    printf("\n");
                    printf("                             �����Դϴ�! �İ����� ������ �����ص� �ջ������� ���׿�!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                                      �߸� �����Ű���? �̰� �� ���⸮��...\n                                      �ϴ� �ϰ� ���� �Ѱ� ���ҽ�ų�Կ�...\n");
                    Sleep(2000);
                }
                break;
            }
        }
        break;
    }
    case 11:
    {
        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                             �ڼҿ� ������ ���� ���� \n");
        printf("                             �Ǳ����б� Ȩ�������� �����ִ� �ڼҿ� ������ �����оߴ�? \n\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        printf("                               ��                 Cryptography                  ��\n");
        printf("                               ��                   Cooking                     ��\n");
        printf("                               ��                  Psychology                   ��\n");
        printf("                               ��������������������������������������������������������������������������������������������������\n");
        int x = 45, y = 13, ch;
        while (1)
        {
            gotoxy(x, y);
            printf(">\b");
            ch = _getch();
            if (ch == 224)
            {
                printf(" ");
                ch = _getch();
                switch (ch)
                {
                case UP:
                    if (y > 13)
                        y--;
                    break;
                case DOWN:
                    if (y < 15)
                        y++;
                    break;
                case LEFT:
                case RIGHT:
                    break;
                }
            }
            else if (ch == 13)
            {
                if (y == 13)
                {
                    system("cls");
                    printf("\n");
                    printf("                        �����Կ� ���� ������ ��ġ�ó׿�! ���� �ڼҿ� �������� ���� ���п���!\n                                           �� �������� �������ּ���!");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                                �İ��� ��Ӵ��� �����о߸� ����? �� ��¥ ������...\n                             ���� �Ѱ��� �ڼҿ� �������� ������ ���� �Ҿ�����ϴ�...");
                    Sleep(2000);
                }
                break;
            }
        }
        break;
    }
    case 12:
    {
        char player[100];
        char answer[11] = "������";

        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                 �ͼ��� ���� \n");
        printf("                                        ���� ���� �丸 �Է����ּ��� \n");
        printf("                                          ���� ���� ������ �ϴ� ����?\n");

        scanf("%s", player);
        getchar();

        if (strcmp(player, answer) == 0)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                       �����Դϴ�! ������� �����ñ���!!");
        }
        else
        {
            system("cls");
            life--;
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                              ��! ���� %s �Դϴ�.\n                                         Ʋ�ȴٰ� ������������� ���ݾƿ� ����\n                                             ���� �Ѱ��� �����մϴ�...", answer);
        }
        break;
    }
    case 13:
    {
        char player[100];
        char answer[20] = "�۱��Ͽɴϴ�";

        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                  �ͼ��� ���� \n");
        printf("                                         ���� ���� �丸 �Է����ּ��� \n");
        printf("                                      ���ϰ� �տ��� ���� �����鼭 �ϴ� ����?\n");

        scanf("%s", player);
        getchar();
        if (strcmp(player, answer) == 0)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                       �����Դϴ�! ������� �����ñ���!!");
        }
        else
        {
            system("cls");
            life--;
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                              ��! ���� %s �Դϴ�.\n                                         Ʋ�ȴٰ� ������������� ���ݾƿ� ����\n                                             ���� �Ѱ��� �����մϴ�...", answer);
        }
    }
    break;
    }
}