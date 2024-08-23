#include "common.h"

void initializeObjects()
{
    for (int a = 0; a < MAX_SIZE_X; a++)
    {
        for (int b = 0; b < MAX_SIZE_Y; b++)
        {
            board[a][b] = 0;
        }
    }
    srand((unsigned)time(NULL));
    int num_obstacles = 50 * difficulty;
    int num_flags = 3 * difficulty + 1;
    int num_enemy = 10 * difficulty;
    if (difficulty == 1)
    {
        remainingstone = 1;
        remainingTime = 70;
    }
    else if (difficulty == 2)
    {
        remainingstone = 3;
        remainingTime = 50;
    }
    else
    {
        remainingstone = 5;
        remainingTime = 30;
    }
    {
        int x = rand() % (MAX_SIZE_X - 2) + 1;
        int y = rand() % (MAX_SIZE_Y - 2) + 1;
        board[x][y] = -1;
    }
    for (int i = 0; i < num_obstacles; i++)
    {
        int x = rand() % (MAX_SIZE_X - 2) + 1;
        int y = rand() % (MAX_SIZE_Y - 2) + 1;
        board[x][y] = -1;
    }
    for (int i = 0; i < num_flags; i++)
    {
        int x = rand() % (MAX_SIZE_X - 2) + 1;
        int y = rand() % (MAX_SIZE_Y - 2) + 1;
        if (board[x][y] == -1)
            i--;
        else
        {
            board[x][y] = 1;
            flagID[x][y] = i;
        }
    }
    for (int i = 0; i < num_enemy; i++)
    {
        int x = rand() % (MAX_SIZE_X - 2) + 1;
        int y = rand() % (MAX_SIZE_Y - 2) + 1;

        if (board[x][y] == -1 || board[x][y] == 1)
            i--;
        else
        {
            board[x][y] = 2;
        }
    }
}

void printBoard()
{
    WaitForSingleObject(consoleMutex, INFINITE);  // ���ؽ� ���
    system("cls");
    for (int y = 0; y < MAX_SIZE_Y; y++)
    {
        for (int x = 0; x < MAX_SIZE_X; x++)
        {
            if (y == 0 || y == MAX_SIZE_Y - 1 || x == 0 || x == MAX_SIZE_X - 1)
                printf("#");
            else if (board[x][y] == -1)
                printf("X");
            else if (board[x][y] == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                printf("@");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else if (board[x][y] == 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("?");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    gotoxy(MAX_SIZE_X, 0); // ���� �߾ӿ� �ð� ���
    printf("���� �ð�: %02d", remainingTime);
    printlifes();
    ReleaseMutex(consoleMutex);  // ���ؽ� ����
}

void gotoxy(int x, int y)
{
    COORD Cur = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void flagmeet(int id)
{
    WaitForSingleObject(consoleMutex, INFINITE);  // ���ؽ� ���
    pauseEnemies = 1;  // ���� �������� ����
    gotoxy(1, MAX_SIZE_Y); // �÷��̾ ������ �ʴ� ��ġ�� �̵�
    printf(" ");
    switch (id)
    {
    case 0:
        remainingstone--;
        ending(remainingstone);
        break;
    case 1:
        break;
    case 2:
        life--;
        gotoxy(MAX_SIZE_X, 5);
        printf("Ÿ�뽺�� ���ϵ��� ������ ������ �ɸ��̽��ϴ�...");
        gotoxy(MAX_SIZE_X, 6);
        printf("������ ���ҵǾ����ϴ�!");
        Sleep(2000);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        gotoxy(MAX_SIZE_X, 5);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b");
        break;
    case 3:
        remainingTime -= 8;
        gotoxy(MAX_SIZE_X, 5);
        printf("Ÿ�뽺�� Ÿ�ӽ��濡 ���� �ð��� 8�� �پ����ϴ�.");
        Sleep(2000);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        break;
    case 4:
        remainingstone--;
        ending(remainingstone);
        break;
    case 5:
        remainingstone--;
        ending(remainingstone);
        break;
    case 6:
        life++;
        gotoxy(MAX_SIZE_X, 5);
        printf("�������ϴ� ưư�� ���̾�� ��Ʈ�� ȹ���ϼ̽��ϴ�!!");
        gotoxy(MAX_SIZE_X, 6);
        printf("������ �����Ǿ����ϴ�!");
        Sleep(2000);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b");
        gotoxy(MAX_SIZE_X, 5);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        break;
    case 7:
        remainingTime += 10;
        gotoxy(MAX_SIZE_X, 5);
        printf("Ÿ�뽺�� Ÿ�ӽ��濡 ���� �ð��� 10�� �þ����ϴ�.");
        Sleep(2000);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        break;
    case 8:
    case 9:
        remainingstone--;
        ending(remainingstone);
        break;
    }
    pauseEnemies = 0;  // ���� �������� �簳
    ReleaseMutex(consoleMutex);  // ���ؽ� ����
}

void enemymeet()
{
    WaitForSingleObject(consoleMutex, INFINITE);  // ���ؽ� ���
    pauseEnemies = 1;  // ���� �������� ����
    gotoxy(1, MAX_SIZE_Y); // �÷��̾ ������ �ʴ� ��ġ�� �̵�
    printf(" ");
    system("cls");
    games();
    printf("\n                                     ����Ͻ÷��� �ƹ�Ű�� ��������...");
    getchar(); // ������ ǥ���� �� �Է� ���
    system("cls");
    printBoard(); // ���带 �ٽ� ���
    pauseEnemies = 0;  // ���� �������� �簳
    ReleaseMutex(consoleMutex);  // ���ؽ� ����
}

DWORD WINAPI moveEnemies(LPVOID lpParam) {
    while (1) {
        if (!pauseEnemies) { // ���� �������� �������� ������ ������
            WaitForSingleObject(consoleMutex, INFINITE);  // ���ؽ� ���
            for (int x = 1; x < MAX_SIZE_X - 1; x++) {
                for (int y = 1; y < MAX_SIZE_Y - 1; y++) {
                    if (board[x][y] == 2) { 
                        int dx = (rand() % 3) - 1; // -1, 0, or 1
                        int dy = (rand() % 3) - 1; // -1, 0, or 1

                        if (x + dx > 0 && x + dx < MAX_SIZE_X - 1 && y + dy > 0 && y + dy < MAX_SIZE_Y - 1 &&
                            board[x + dx][y + dy] != -1 && board[x + dx][y + dy] != 2 && board[x + dx][y + dy] != 1) {
                            board[x][y] = 0;
                            gotoxy(x, y);
                            printf(" ");
                            board[x + dx][y + dy] = 2;
                            gotoxy(x + dx, y + dy);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                            printf("?");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        }
                    }
                }
            }
            remainingTime--;
            gotoxy(MAX_SIZE_X, 0); // ���� �߾ӿ� �ð� ���
            printf("���� �ð�: %2d", remainingTime);

            // Check if time is up
            if (remainingTime <= 0 || life == 0) {
                system("cls");
                printf("\n\n\n\n\n\n\n");
                printf("                                   �����԰� ģ������ ������ ���߽��ϴ�...\n");
                Sleep(2000);
                printf("                                          ����� ������ F�Դϴ�...\n");
                Sleep(1000);
                printf("                                          �ʱ�ȭ������ ���ư��ϴ�\n\n                                          �ƹ�Ű�� �����ּ���...");
                getchar();
                showStartScreen();
            }
            ReleaseMutex(consoleMutex);  // ���ؽ� ����
        }
        Sleep(1000);
    }
    return 0;
}

DWORD WINAPI handlePlayer(LPVOID lpParam) {
    int x = 1, y = 1, ch;
    while (1) {
        WaitForSingleObject(consoleMutex, INFINITE);  // ���ؽ� ���
        gotoxy(x, y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        printf("&\b");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        ReleaseMutex(consoleMutex);  // ���ؽ� ����
        if (_kbhit()) {
            ch = _getch();
            if (ch == 224) {
                WaitForSingleObject(consoleMutex, INFINITE);  // ���ؽ� ���
                printf(" ");
                ch = _getch();
                int nx = x, ny = y;
                switch (ch) {
                case 72: // UP
                    ny--;
                    break;
                case 80: // DOWN
                    ny++;
                    break;
                case 75: // LEFT
                    nx--;
                    break;
                case 77: // RIGHT
                    nx++;
                    break;
                }
                if (nx > 0 && nx < MAX_SIZE_X - 1 && ny > 0 && ny < MAX_SIZE_Y - 1 && board[nx][ny] != -1) {
                    if (board[nx][ny] == 2) {
                        printf(" "); // �÷��̾� ��ġ �����
                        enemymeet();
                        board[nx][ny] = 0;
                        x = nx;
                        y = ny;
                    }
                    else if (board[nx][ny] == 1) {
                        ;
                        printf(" "); // �÷��̾� ��ġ �����
                        flagmeet(flagID[nx][ny]);
                        board[nx][ny] = 0;
                        if (flagID[nx][ny] == 1) {
                            system("cls");
                            printf("\n\n");

                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED);
                            printf("                                                     * * *      \n");
                            printf("                                                   *      *      \n");
                            printf("                                                  *        *       \n");
                            printf("                                                          *      \n");
                            printf("                                                         *        \n");
                            printf("                                                        *\n");
                            printf("                                                       *\n");
                            printf("                                                       *\n\n");
                            printf("                                                       *\n");
                            printf("                                                      * *\n");

                            printf("\n\n\n");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                            printf("                                           �˼� ���� ���� �Ͼ�ϴ�\n                                           �ٽ� ó����ġ�� ���ư��ϴ�\n");
                            Sleep(2000);
                            printf("\n                                        ����Ͻ÷��� �ƹ�Ű�� ��������...");
                            getchar();
                            x = 1;
                            y = 1;
                        }
                        else {
                            x = nx;
                            y = ny;
                        }
                        printBoard();
                    }
                    else {
                        gotoxy(x, y);
                        printf(" "); // �÷��̾� ��ġ �����
                        x = nx;
                        y = ny;
                    }
                }
                ReleaseMutex(consoleMutex);  // ���ؽ� ����
            }
        }
    }
    return 0;
}

void playGame()
{
    HANDLE hThread1, hThread2;
    initializeObjects();
    consoleMutex = CreateMutex(NULL, FALSE, NULL); // ���ؽ� ����
    printBoard();
    hThread1 = CreateThread(NULL, 0, moveEnemies, NULL, 0, NULL);
    hThread2 = CreateThread(NULL, 0, handlePlayer, NULL, 0, NULL);
    if (hThread1 == NULL || hThread2 == NULL)
    {
        printf("Error creating threads.\n");
        return;
    }

    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    CloseHandle(hThread1);
    CloseHandle(hThread2);
    CloseHandle(consoleMutex); // ���ؽ� ����
}
void printlifes()
{
    gotoxy(MAX_SIZE_X, 1);
    printf("���� ����: ");
    for (int i = 0; i < life; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("��");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    printf("\t���� ���� ��: %d", remainingstone);
}
void ending(int num)
{
    score = remainingTime * 100 + life * 1000 + (5 - remainingstone) * 2000;
    pauseEnemies = 1;
    system("cls");
    if (num == 0) {
        if (difficulty == 1 || difficulty == 2)
        {
            WaitForSingleObject(consoleMutex, INFINITE);  // ���ؽ� ���
            difficulty++;
            printf("\n\n\n\n\n\n\n");
            printf("                             �ش� ���̵����� ������ ��� ȹ���ϼ̽��ϴ�! ���ϵ帳�ϴ�! \n");
            printf("               ������ ����� ���̵����� ���ž� ��� ������ ��� �ڼҿ� �����԰� ģ������ �츱 �� �ֽ��ϴ�.\n");
            printf("                                           ���� ���̵��� �ö󰩴ϴ�..\n");
            ReleaseMutex(consoleMutex);  // ���ؽ� ����
            Sleep(2000);
            printf("\n                                        ����Ϸ��� �ƹ�Ű�� ��������...");
            getchar();
            pauseEnemies = 0;  // ���� �������� �簳
            initializeObjects();
            system("cls");
            printBoard();
        }
        else
        {
            printf("\n\n\n\n\n\n");
            printf("                                   Ending: ���� - ��� ���� �Ծ����ϴ�!\n                                               ����: %5d", score);
            printf("                              �ʱ� ȭ������ ���÷��� �ƹ�Ű�� ��������...\n");
            getchar();
            showStartScreen();
        }
    }
    else
    {
        printf("\n\n\n\n\n\n\n");
        printf("                        ������ ȹ���ϼ̽��ϴ�! �����ʾ� �ڼҿ� �������� �ٽ� �� �� �ְڱ���!\n\n");
        printf("                                        ����Ϸ��� �ƹ�Ű�� ��������...\n");
        getchar();
        pauseEnemies = 0;  // ���� �������� �簳
    }
}