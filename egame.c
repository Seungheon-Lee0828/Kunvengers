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
        printf("                               ┌───────────────────────────────────────────────┐\n");
        printf("                               │             **죽음의 가위바위보**             │\n");
        printf("                               │                   단판승부                    │\n");
        printf("                               │                    3판2선                     │\n");
        printf("                               └───────────────────────────────────────────────┘\n");
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
            printf("                       박소영 교수님을 구하기 위해 데스매치에도 쫄지 않는 당신! 역시 영웅이시군요!\n\n");
            Sleep(3000);
            int a, b, c;
            a = rand() % 3;
            printf("                                              바위: 0, 가위: 1, 보: 2\n");
            printf("                                         가위바위보중에 낼 숫자를 입력하세요: ");
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
            printf("                                                타노스의 수하: %d\n", a);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            printf("                                                   당신: %d\n", b);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            switch (c)
            {
            case 0:
                life--;
                printf("                       타노스의 수하가 이겼습니다... 생명 한개를 잃으셨습니다...아쉽네요;;\n\n");
                break;
            case 1:
                printf("                                               재미없게 이기셨네요;;\n");
                Sleep(1000);
                printf("                                   계속 나아가서 박소영 교수님을 구출하세요!\n\n");
                break;
            case 2:
                printf("                           박소영 교수님을 살리겠다는 의지를 보고 개발자가 감동을 먹었습니다 ㅠㅠ. \n                            무승부를 하셨지만 개발자의 권한으로 승리로 취급합니다! 계속 나아가세요! \n\n");
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
                printf("                                             바위: 0, 가위: 1, 보: 2\n");
                printf("                                        가위바위보중에 낼 숫자를 입력하세요: ");
                scanf("%d", &b);
                getchar();

                if ((a == 0 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 0))
                    c++;
                else if ((a == 1 && b == 0) || (a == 2 && b == 1) || (a == 0 && b == 2))
                    d++;

                system("cls");
                printf("\n\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
                printf("                                                타노스의 수하: %d\n", a);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                printf("                                                   당신: %d\n", b);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                if (c > d)
                    printf("                                          한 번 더 지면 넌 레전드...\n\n");
                else if (c < d)
                    printf("                                           일단 한 판 가져갔고\n\n");
                else
                    printf("                                                    무승부\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                printf("                                          (타노스의 수하) %d : %d (당신)", c, d);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                if (c == 2)
                {
                    life--;
                    printf("\n\n                                        3판 2선하고 졌어?? 넌 나가라...\n                                         생명 한개를 감소시킵니다...");
                    break;
                }
                else if (d == 2)
                {
                    printf("\n                                              이겼네? 너무 축하해 ^^");
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
        printf("\n\n\n\n\n\n\n\n\n                                        다음에 나올 숫자들을 순차대로 계산해주세요\n");
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
        printf("\n\n\n\n\n\n\n\n\n                                                    계산 결과는? : ");
        scanf("%d", &d);
        getchar();
        if (c == d)
            printf("\n                                  이걸 맞춰? 괜히 건국대학교 컴공이 아니네~ 계속 가자!!");
        else
        {
            life--;
            printf("\n                                               ...아쉬워요 건.대.컴.공\n                         박소영 교수님을 구할 집중력이 부족하네요... 생명 한 개를 비참하게 잃습니다(실망)...");
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
            printf("\n\n\n\n\n\n\n\n\n                                 숫자를 입력하세요!!(1~100) 7번의 기회가 주어집니다: ");
            scanf("%d", &b);
            getchar();
            if (a < b)
                printf("\n                                                      다운다운");
            else if (a == b)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
                printf("\n                                            이걸 맞추다니 천재가 분명하네요!");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
            }
            else
                printf("\n                                                        업업");
            Sleep(2000);
            system("cls");
        }
        if (i == 7)
        {
            life--;
            printf("\n\n\n\n\n\n\n\n\n                                                7번이나 기회를 줬는데...;;\n");
            Sleep(1000);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            printf("\n                                          박소영 교수님을 안 구하고 싶은거니!!? \n                                                  생명 한 개를 잃습니다");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        break;
    }
    case 3:
    {
        char player[100];
        char answer[13] = "캡사이신";

        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                  넌센스 퀴즈 \n");
        printf("                                         띄어쓰기 빼고 답만 입력해주세요 \n");
        printf("                                       모자 매장 진열대 사이에 신발을 두면?\n");

        scanf("%s", player);
        getchar();

        if (strcmp(player, answer) == 0)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                       정답입니다! 아재력이 높으시군요!!");
        }
        else
        {
            system("cls");
            life--;
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                              땡! 답은 %s 입니다.\n                                         틀렸다고 상심하지마세요 젋잖아요 ㅎㅎ\n                                             생명 한개가 감소합니다...", answer);
        }
        break;
    }
    case 4:
    {
        int a, b;
        printf("\n\n\n\n\n\n\n                                   주사위게임입니다. 숫자가 크거나 같으면 승리합니다!\n");
        a = (rand() % 6 + 1);
        printf("\n                                                          (%d)\n\n", a);
        Sleep(2000);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
        printf("                                              원할때 키보드를 눌러주세요!!\n\n");
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
            printf("                                                   승리하셨습니다!");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            Sleep(2000);
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
            printf("                                                      안타깝네요!");
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
        printf("                                                   c++ 퀴즈 \n");
        printf("                                    <stdlib.h> 안에 난수를 생성하는 함수는?   \n\n");
        printf("                               ┌───────────────────────────────────────────────┐\n");
        printf("                               │                    printf()                   │\n");
        printf("                               │                    gets_s()                   │\n");
        printf("                               │                     rand()                    │\n");
        printf("                               └───────────────────────────────────────────────┘\n");
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
                    printf("                              박소영 교수님 수업을 집중하셨군요? 계속 나아가주세요!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                             이건 아니지...난수 = rand(), 초등학생도 아는데 실수 한거죠?\n                                       일단 생명 한개 가져갈게요...\n");
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
        printf("                                                   c++ 퀴즈 \n");
        printf("                             다음 이스케이프 시퀀스 중 줄의 맨 처음으로 돌아가는 것은? \n\n");
        printf("                               ┌───────────────────────────────────────────────┐\n");
        printf("                               │                      \\n                       │\n");
        printf("                               │                      \\t                       │\n");
        printf("                               │                      \\r                       │\n");
        printf("                               └───────────────────────────────────────────────┘\n");
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
                    printf("                              박소영 교수님 수업을 집중하셨군요? 계속 나아가주세요!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                             이건 아니지.. 맨 첫줄 = \\t, 초등학생도 아는데 실수 한거죠?\n                                       일단 생명 한개 가져갈게요...\n");
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
        printf("                                                   c++ 퀴즈 \n");
        printf("                       현재 시간을 가져오는 함수를 사용하기 위해 열어야 하는 라이브러리는? \n\n");
        printf("                               ┌───────────────────────────────────────────────┐\n");
        printf("                               │                  <stdlib.h>                   │\n");
        printf("                               │                  < time.h >                   │\n");
        printf("                               │                  < stdio.h>                   │\n");
        printf("                               └───────────────────────────────────────────────┘\n");
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
                    printf("                              박소영 교수님 수업을 집중하셨군요? 계속 나아가주세요!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    printf("\n");
                    printf("                             이건 아니지.. 시간 = time, 초등학생도 아는데 실수 한거죠?\n                                       일단 생명 한개 가져갈게요...\n");
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
        printf("                                                 사자성어 퀴즈 \n");
        printf("                     불안·근심 등으로 자리에 가만히 앉아 있지를 못하는 것을 뜻하는 사자성어는? \n\n");
        printf("                               ┌───────────────────────────────────────────────┐\n");
        printf("                               │                   어부지리                    │\n");
        printf("                               │                   사필귀정                    │\n");
        printf("                               │                   좌불안석                    │\n");
        printf("                               └───────────────────────────────────────────────┘\n");
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
                    printf("                             정답입니다! 컴공말고 문과로 전향해도 손색없을거 같네요!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                                      잘못 누르신거죠? 이걸 못 맞출리가...\n                                      일단 믿고 생명 한개 감소시킬게요...\n");
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
        printf("                                                 사자성어 퀴즈 \n");
        printf("                             죽어서까지라도 은혜를 잊지 않고 갚는다는 뜻의 사자성어는? \n\n");
        printf("                               ┌───────────────────────────────────────────────┐\n");
        printf("                               │                   결초보은                    │\n");
        printf("                               │                   첩첩산중                    │\n");
        printf("                               │                   이이제이                    │\n");
        printf("                               └───────────────────────────────────────────────┘\n");
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
                    printf("                             정답입니다! 컴공말고 문과로 전향해도 손색없을거 같네요!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                                      잘못 누르신거죠? 이걸 못 맞출리가...\n                                      일단 믿고 생명 한개 감소시킬게요...\n");
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
        printf("                                                 사자성어 퀴즈 \n");
        printf("                            물음과는 딴판인 엉뚱한 대답을 하는 상황에 쓰는 사자성어는? \n\n");
        printf("                               ┌───────────────────────────────────────────────┐\n");
        printf("                               │                   동문서답                    │\n");
        printf("                               │                   백년해로                    │\n");
        printf("                               │                   역지사지                    │\n");
        printf("                               └───────────────────────────────────────────────┘\n");
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
                    printf("                             정답입니다! 컴공말고 문과로 전향해도 손색없을거 같네요!\n");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                                      잘못 누르신거죠? 이걸 못 맞출리가...\n                                      일단 믿고 생명 한개 감소시킬게요...\n");
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
        printf("                                             박소영 교수님 관련 퀴즈 \n");
        printf("                             건국대학교 홈페이지에 적혀있는 박소영 교수님 연구분야는? \n\n");
        printf("                               ┌───────────────────────────────────────────────┐\n");
        printf("                               │                 Cryptography                  │\n");
        printf("                               │                   Cooking                     │\n");
        printf("                               │                  Psychology                   │\n");
        printf("                               └───────────────────────────────────────────────┘\n");
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
                    printf("                        교수님에 대한 애정이 넘치시네요! 역시 박소영 교수님의 예비 대학원생!\n                                           꼭 교수님을 구출해주세요!");
                    Sleep(2000);
                }
                else
                {
                    system("cls");
                    life--;
                    printf("\n");
                    printf("                                컴공의 어머니의 연구분야를 몰라? 넌 진짜 나가라...\n                             생명 한개를 박소영 교수님의 애정과 같이 잃어버립니다...");
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
        char answer[11] = "꼭끼오";

        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                 넌센스 퀴즈 \n");
        printf("                                        띄어쓰기 빼고 답만 입력해주세요 \n");
        printf("                                          닭이 옷이 작으면 하는 말은?\n");

        scanf("%s", player);
        getchar();

        if (strcmp(player, answer) == 0)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                       정답입니다! 아재력이 높으시군요!!");
        }
        else
        {
            system("cls");
            life--;
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                              땡! 답은 %s 입니다.\n                                         틀렸다고 상심하지마세요 젋잖아요 ㅎㅎ\n                                             생명 한개가 감소합니다...", answer);
        }
        break;
    }
    case 13:
    {
        char player[100];
        char answer[20] = "송구하옵니다";

        printf("\n\n\n\n\n\n\n\n\n");
        printf("                                                  넌센스 퀴즈 \n");
        printf("                                         띄어쓰기 빼고 답만 입력해주세요 \n");
        printf("                                      신하가 왕에게 공을 던지면서 하는 말은?\n");

        scanf("%s", player);
        getchar();
        if (strcmp(player, answer) == 0)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                       정답입니다! 아재력이 높으시군요!!");
        }
        else
        {
            system("cls");
            life--;
            printf("\n\n\n\n\n\n\n\n\n");
            printf("                                              땡! 답은 %s 입니다.\n                                         틀렸다고 상심하지마세요 젊잖아요 ㅎㅎ\n                                             생명 한개가 감소합니다...", answer);
        }
    }
    break;
    }
}