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
    WaitForSingleObject(consoleMutex, INFINITE);  // 뮤텍스 잠금
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
    gotoxy(MAX_SIZE_X, 0); // 위쪽 중앙에 시간 출력
    printf("남은 시간: %02d", remainingTime);
    printlifes();
    ReleaseMutex(consoleMutex);  // 뮤텍스 해제
}

void gotoxy(int x, int y)
{
    COORD Cur = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void flagmeet(int id)
{
    WaitForSingleObject(consoleMutex, INFINITE);  // 뮤텍스 잠금
    pauseEnemies = 1;  // 적의 움직임을 멈춤
    gotoxy(1, MAX_SIZE_Y); // 플레이어를 보이지 않는 위치로 이동
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
        printf("타노스의 부하들이 만들어논 함정에 걸리셨습니다...");
        gotoxy(MAX_SIZE_X, 6);
        printf("생명이 감소되었습니다!");
        Sleep(2000);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        gotoxy(MAX_SIZE_X, 5);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b");
        break;
    case 3:
        remainingTime -= 8;
        gotoxy(MAX_SIZE_X, 5);
        printf("타노스의 타임스톤에 의해 시간이 8초 줄었습니다.");
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
        printf("날지못하는 튼튼한 아이언맨 슈트를 획득하셨습니다!!");
        gotoxy(MAX_SIZE_X, 6);
        printf("생명이 증가되었습니다!");
        Sleep(2000);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b");
        gotoxy(MAX_SIZE_X, 5);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        break;
    case 7:
        remainingTime += 10;
        gotoxy(MAX_SIZE_X, 5);
        printf("타노스의 타임스톤에 의해 시간이 10초 늘었습니다.");
        Sleep(2000);
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        break;
    case 8:
    case 9:
        remainingstone--;
        ending(remainingstone);
        break;
    }
    pauseEnemies = 0;  // 적의 움직임을 재개
    ReleaseMutex(consoleMutex);  // 뮤텍스 해제
}

void enemymeet()
{
    WaitForSingleObject(consoleMutex, INFINITE);  // 뮤텍스 잠금
    pauseEnemies = 1;  // 적의 움직임을 멈춤
    gotoxy(1, MAX_SIZE_Y); // 플레이어를 보이지 않는 위치로 이동
    printf(" ");
    system("cls");
    games();
    printf("\n                                     계속하시려면 아무키나 누르세요...");
    getchar(); // 문제를 표시한 후 입력 대기
    system("cls");
    printBoard(); // 보드를 다시 출력
    pauseEnemies = 0;  // 적의 움직임을 재개
    ReleaseMutex(consoleMutex);  // 뮤텍스 해제
}

DWORD WINAPI moveEnemies(LPVOID lpParam) {
    while (1) {
        if (!pauseEnemies) { // 적의 움직임이 멈춰있지 않으면 움직임
            WaitForSingleObject(consoleMutex, INFINITE);  // 뮤텍스 잠금
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
            gotoxy(MAX_SIZE_X, 0); // 위쪽 중앙에 시간 출력
            printf("남은 시간: %2d", remainingTime);

            // Check if time is up
            if (remainingTime <= 0 || life == 0) {
                system("cls");
                printf("\n\n\n\n\n\n\n");
                printf("                                   교수님과 친구들을 구하지 못했습니다...\n");
                Sleep(2000);
                printf("                                          당신의 학점은 F입니다...\n");
                Sleep(1000);
                printf("                                          초기화면으로 돌아갑니다\n\n                                          아무키나 눌러주세요...");
                getchar();
                showStartScreen();
            }
            ReleaseMutex(consoleMutex);  // 뮤텍스 해제
        }
        Sleep(1000);
    }
    return 0;
}

DWORD WINAPI handlePlayer(LPVOID lpParam) {
    int x = 1, y = 1, ch;
    while (1) {
        WaitForSingleObject(consoleMutex, INFINITE);  // 뮤텍스 잠금
        gotoxy(x, y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        printf("&\b");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        ReleaseMutex(consoleMutex);  // 뮤텍스 해제
        if (_kbhit()) {
            ch = _getch();
            if (ch == 224) {
                WaitForSingleObject(consoleMutex, INFINITE);  // 뮤텍스 잠금
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
                        printf(" "); // 플레이어 위치 지우기
                        enemymeet();
                        board[nx][ny] = 0;
                        x = nx;
                        y = ny;
                    }
                    else if (board[nx][ny] == 1) {
                        ;
                        printf(" "); // 플레이어 위치 지우기
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
                            printf("                                           알수 없는 힘이 일어납니다\n                                           다시 처음위치로 돌아갑니다\n");
                            Sleep(2000);
                            printf("\n                                        계속하시려면 아무키나 누르세요...");
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
                        printf(" "); // 플레이어 위치 지우기
                        x = nx;
                        y = ny;
                    }
                }
                ReleaseMutex(consoleMutex);  // 뮤텍스 해제
            }
        }
    }
    return 0;
}

void playGame()
{
    HANDLE hThread1, hThread2;
    initializeObjects();
    consoleMutex = CreateMutex(NULL, FALSE, NULL); // 뮤텍스 생성
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
    CloseHandle(consoleMutex); // 뮤텍스 해제
}
void printlifes()
{
    gotoxy(MAX_SIZE_X, 1);
    printf("남은 생명: ");
    for (int i = 0; i < life; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("♥");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    }
    printf("\t남은 스톤 수: %d", remainingstone);
}
void ending(int num)
{
    score = remainingTime * 100 + life * 1000 + (5 - remainingstone) * 2000;
    pauseEnemies = 1;
    system("cls");
    if (num == 0) {
        if (difficulty == 1 || difficulty == 2)
        {
            WaitForSingleObject(consoleMutex, INFINITE);  // 뮤텍스 잠금
            difficulty++;
            printf("\n\n\n\n\n\n\n");
            printf("                             해당 난이도에서 스톤을 모두 획득하셨습니다! 축하드립니다! \n");
            printf("               하지만 어려움 난이도까지 가셔야 모든 스톤을 모아 박소영 교수님과 친구들을 살릴 수 있습니다.\n");
            printf("                                           다음 난이도로 올라갑니다..\n");
            ReleaseMutex(consoleMutex);  // 뮤텍스 해제
            Sleep(2000);
            printf("\n                                        계속하려면 아무키나 누르세요...");
            getchar();
            pauseEnemies = 0;  // 적의 움직임을 재개
            initializeObjects();
            system("cls");
            printBoard();
        }
        else
        {
            printf("\n\n\n\n\n\n");
            printf("                                   Ending: 성공 - 모든 돌을 먹었습니다!\n                                               점수: %5d", score);
            printf("                              초기 화면으로 가시려면 아무키나 누르세요...\n");
            getchar();
            showStartScreen();
        }
    }
    else
    {
        printf("\n\n\n\n\n\n\n");
        printf("                        스톤을 획득하셨습니다! 머지않아 박소영 교수님을 다시 볼 수 있겠군요!\n\n");
        printf("                                        계속하려면 아무키나 누르세요...\n");
        getchar();
        pauseEnemies = 0;  // 적의 움직임을 재개
    }
}