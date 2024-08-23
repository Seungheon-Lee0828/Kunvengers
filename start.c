#include "common.h"
void printTypingEffect(const char* text, int delay, int* stopFlag)
{
    while (*text) {
        if (*stopFlag) {
            printf("%s", text);
            break;
        }
        if (_kbhit()) {
            int ch = _getch();
            if (ch == 13) { // Enter 키 입력
                *stopFlag = 1;
                printf("%s", text);
                break;
            }
            else if (ch == 27) { // Esc 키 입력
                *stopFlag = 2;
                return;
            }
        }
        putchar(*text++);
        fflush(stdout);
        Sleep(delay);
    }
    printf("\n");
}

void showStory1(int* skipFlag)
{
    int ch;
    int stopFlag = 0;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                                                   ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_BLUE);
    printTypingEffect("건벤져스\n", 50, &stopFlag);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }
    printf("\n                                  ");
    printTypingEffect("Press 'Enter' to continue or 'Esc' to skip...\n", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }

    while (1) {
        ch = _getch();
        if (ch == 13) { // Enter 키 입력
            if (stopFlag) return; // 이미 출력된 상태면 다음 화면으로
            stopFlag = 1; // 스토리 전체 출력
        }
        else if (ch == 27) { // Esc 키 입력
            *skipFlag = 1;
            return;
        }
    }
}

void showStory2(int* skipFlag)
{
    int ch;
    int stopFlag = 0;
    system("cls");
    printf("\n- 구원의 손길: 건국대학교의 영웅들\n\n");
    printTypingEffect("건국대학교의 평화로운 캠퍼스에 어느 날 갑자기 엄청난 변화가 일어났다.     \n봄바람이 살랑거리던 그날, 학생들은 평소와 다름없이 강의실로, 도서관으로, 카페로 향하고 있었다.\n하지만 그날의 평화는 오래가지 않았다. 타노스....  그는 그저 영화 속 악당일 뿐이라 생각했다. \n그러나 어벤져스 세계관이 현실로 들어온 순간, 모든 것은 뒤집혔다. \n타노스가 손가락을 튕기는 순간, 캠퍼스는 말 그대로 난리가 났다. \n교수님들과 학생들이 순식간에 사라졌고, 건국대학교의 반이 사라진 것이다. 소영 교수님도 그 중 한 분이었다. \n그녀는 C 프로그래밍 과목을 가르치며 많은 학생들에게 영감을 주던 인물이었다.\n타노스의 손가락 튕김으로 인해 사라진 이들을 되찾기 위한 시간이 다가오고 있었다. 건국대학교의 학생들은 절망에 빠졌다. \n그들은 모두 C 프로그래밍을 통해 졸업 요건을 충족해야 했고, 학점을 받지 못하면 졸업은 불가능했다.\n그것은 단순한 학점 문제가 아니었다.졸업을 하지 못하면 그들의 꿈도, 미래도 사라지는 것이었다.\n캠퍼스에는 긴장감이 감돌았다. 학생들은 서로를 바라보며 무언가를 해야 한다는 것을 느끼고 있었다. \n바로 그때, 한 무리의 학생들이 모여 결의를 다졌다. \n그들은 소영 교수님과 사라진 학생들을 되찾아야 했다. 그렇지 않으면 모두 F 학점을 받게 될 것이었다. ", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }
    printTypingEffect("\nPress 'Enter' to continue or 'Esc' to skip...\n", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }

    while (1) {
        ch = _getch();
        if (ch == 13) { // Enter 키 입력
            if (stopFlag) return; // 이미 출력된 상태면 다음 화면으로
            stopFlag = 1; // 스토리 전체 출력
        }
        else if (ch == 27) { // Esc 키 입력
            *skipFlag = 1;
            return;
        }
    }
}

void showStory3(int* skipFlag)
{
    int ch;
    int stopFlag = 0;
    system("cls");
    printf("\n- 미션: 인피니티 스톤을 찾아서\n\n");
    printTypingEffect("학생들은 소영 교수님을 되찾기 위해 '어벤져스'가 되어야 했다. \n그들은 캠퍼스 곳곳에 흩어져 있는 인피니티 스톤을 찾아야만 했다.\n각 스톤에는 강력한 힘이 깃들어 있었고, 그것들을 모두 모아야 타노스의 손가락 튕김을 되돌릴 수 있었다.\n\n시간의 스톤 : 학생들은 학교의 오래된 시계탑에서 시간을 되돌릴 수 있는 스톤을 찾아야 했다.\n이 스톤은 과거로 돌아가 타노스의 계획을 막을 수 있는 힘을 가지고 있었다.\n\n공간의 스톤 : 이 스톤은 캠퍼스 지하 비밀 연구실에 숨겨져 있었다.연구실은 오랫동안 봉인되어 있었고, \n그곳에 접근하려면 복잡한 퍼즐을 풀어야 했다.\n\n영혼의 스톤 : 영혼의 스톤은 캠퍼스의 가장 깊은 곳에 위치한, 숲 속의 작은 연못에 있었다.\n이곳에서 스톤을 얻기 위해서는 자신이 가장 소중하게 생각하는 것을 희생해야 했다.\n\n현실의 스톤 : 도서관의 금서 코너에 숨겨진 이 스톤은 현실을 왜곡시킬 수 있었다.\n도서관의 깊은 곳, 금서 코너에 도달하려면 여러 지식을 시험하는 퀴즈를 통과해야 했다.\n\n힘의 스톤 : 체육관의 지하에 있는 이 스톤은 강력한 방어 메커니즘으로 보호되고 있었다.\n힘의 스톤을 얻으려면 엄청난 힘과 용기를 가져야 했다.\n\n마음의 스톤 : 마음의 스톤은 학내의 모든 사람들과 연결된 공동체의 중심에 있었다.\n이 스톤을 얻기 위해서는 서로 협력하고, 신뢰를 쌓아야 했다.", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }
    printTypingEffect("\nPress 'Enter' to continue or 'Esc' to skip...\n", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }

    while (1) {
        ch = _getch();
        if (ch == 13) { // Enter 키 입력
            if (stopFlag) return; // 이미 출력된 상태면 다음 화면으로
            stopFlag = 1; // 스토리 전체 출력
        }
        else if (ch == 27) { // Esc 키 입력
            *skipFlag = 1;
            return;
        }
    }
}

void showStory4(int* skipFlag)
{
    int ch;
    int stopFlag = 0;
    system("cls");
    printf("\n- 모험의 시작\n\n");
    printTypingEffect("학생들은 각기 다른 팀으로 나뉘어 각 스톤을 찾기 위한 모험을 시작했다.\n그들은 각 스톤을 찾기 위해 많은 어려움과 도전을 겪었지만, 서로의 힘을 합쳐 극복해 나갔다.\n\n시간의 스톤을 찾기 위해 시계탑에 오른 팀은 과거로 돌아가 타노스의 첫 번째 침공을 막는 방법을 연구했다. \n\n공간의 스톤을 찾기 위해 지하 연구실에 들어간 팀은 복잡한 퍼즐을 풀며 지하의 비밀을 밝혀냈다.\n\n영혼의 스톤을 찾기 위해 숲 속 연못에 도달한 팀은 자신들이 가장 소중히 여기는 것을 희생하며 진정한 용기를 보여주었다.\n\n현실의 스톤을 찾기 위해 도서관의 금서 코너로 향한 팀은 지식의 시험을 통과하며 현실을 바꿀 수 있는 힘을 얻었다.\n\n힘의 스톤을 찾기 위해 체육관 지하로 내려간 팀은 강력한 방어 메커니즘을 무찌르고 스톤을 손에 넣었다.\n\n마지막으로 마음의 스톤을 찾기 위해 공동체의 중심으로 향한 팀은 서로의 신뢰와 협력을 통해 마음의 스톤을 얻어냈다.", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }
    printTypingEffect("\nPress 'Enter' to continue or 'Esc' to skip...\n", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }

    while (1) {
        ch = _getch();
        if (ch == 13) { // Enter 키 입력
            if (stopFlag) return; // 이미 출력된 상태면 다음 화면으로
            stopFlag = 1; // 스토리 전체 출력
        }
        else if (ch == 27) { // Esc 키 입력
            *skipFlag = 1;
            return;
        }
    }
}

void showStory5(int* skipFlag)
{
    int ch;
    int stopFlag = 0;
    system("cls");
    printf("\n- 최후의 대결\n\n");
    printTypingEffect("모든 스톤을 모은 학생들은 타노스와의 최후의 대결을 준비했다.\n그들은 힘을 합쳐 타노스의 손가락 튕김을 되돌리고, 사라진 소영 교수님과 학생들을 되찾기 위해 결의를 다졌다.\n결국, 학생들의 노력과 희생 덕분에 타노스의 힘은 약해졌고, 손가락 튕김은 되돌아갔다.\n소영 교수님과 사라진 학생들은 다시 돌아왔고, 캠퍼스는 평화를 되찾았다.\n학생들은 모두 A + 학점을 받았고, C 프로그래밍 과목을 성공적으로 이수할 수 있었다.\n그들은 이번 모험을 통해 진정한 용기와 협력의 의미를 배웠고, \n어떤 어려움이 닥쳐도 함께 이겨낼 수 있다는 자신감을 얻게 되었다.", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }
    printTypingEffect("\nPress 'Enter' to continue or 'Esc' to skip...\n", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }

    while (1) {
        ch = _getch();
        if (ch == 13) { // Enter 키 입력
            if (stopFlag) return; // 이미 출력된 상태면 다음 화면으로
            stopFlag = 1; // 스토리 전체 출력
        }
        else if (ch == 27) { // Esc 키 입력
            *skipFlag = 1;
            return;
        }
    }
}

void showStory6(int* skipFlag)
{
    int ch;
    int stopFlag = 0;
    system("cls");
    printf("\n- 에필로그\n\n");
    printTypingEffect("건국대학교의 학생들은 이번 사건을 통해 한층 더 성장했다.\n그들은 단순한 학점을 넘어 진정한 협력과 용기의 중요성을 깨달았다.\n타노스와의 싸움은 끝났지만, 앞으로도 많은 도전이 기다리고 있었다.\n그러나 그들은 이제 서로를 믿고 함께 나아갈 준비가 되어 있었다.\n그리고 그들의 이야기는 오랫동안 건국대학교의 전설로 남아, 후배들에게 영감을 주는 이야기가 되었다.\n이 이야기는 단순한 영화 속 영웅들의 이야기가 아니라, \n현실 속에서도 우리가 함께 힘을 합쳐 이겨낼 수 있다는 믿음을 심어주는 이야기로 남았다.", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }
    printTypingEffect("\nPress 'Enter' to continue or 'Esc' to skip...\n", 50, &stopFlag);
    if (stopFlag == 2) {
        *skipFlag = 1;
        return;
    }

    while (1) {
        ch = _getch();
        if (ch == 13) { // Enter 키 입력
            if (stopFlag) return; // 이미 출력된 상태면 다음 화면으로
            stopFlag = 1; // 스토리 전체 출력
        }
        else if (ch == 27) { // Esc 키 입력
            *skipFlag = 1;
            return;
        }
    }
}

void showStory()
{
    int skipFlag = 0;
    showStory1(&skipFlag);
    if (skipFlag) return;
    showStory2(&skipFlag);
    if (skipFlag) return;
    showStory3(&skipFlag);
    if (skipFlag) return;
    showStory4(&skipFlag);
    if (skipFlag) return;
    showStory5(&skipFlag);
    if (skipFlag) return;
    showStory6(&skipFlag);
    if (skipFlag) return;
}
void showStartScreen()
{
    int stopFlag = 0;
    system("cls");
    printf("\n\n\n");
    printf("                                        ********************************\n");
    printf("                                        **                            **\n");
    printf("                                        **          *      *          **\n");
    printf("                                        **          *    *            **\n");
    printf("                                        **          *  *              **\n");
    printf("                                        **          ***               **\n");
    printf("                                        **          *  *              **\n");
    printf("                                        **          *    *            **\n");
    printf("                                        **          *      *          **\n");
    printf("                                        **                            **\n");
    printf("                                        ********************************\n");
    printf("\n");
    printf("                                             건벤져스 - 사라진 교수님\n\n\n");
    printf("                               ┌───────────────────────────────────────────────┐\n");
    printf("                               │                    게임 시작                  │\n");
    printf("                               │                    게임 규칙                  │\n");
    printf("                               │                      종료                     │\n");
    printf("                               └───────────────────────────────────────────────┘\n");
    int x = 50, y = 19, ch;
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
                if (y > 19)
                    y--;
                break;
            case DOWN:
                if (y < 21)
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
    if (y == 19)
    {
        life = 3;
        showStory();
        selectDifficulty();
        playGame();
    }
    else if (y == 20)
        showTutorial();
    else if (y == 21)
        ExitProcess(0);
}
void showTutorial() {
    system("cls");
    printf("게임 튜토리얼\n\n");

    printf("## 1. 게임 개요\n");
    printf("이 게임은 박소영 교수님과 친구들을 구하기 위해 적들과 장애물을 피해 스톤과 플래그를 수집하는 게임입니다.\n");
    printf("난이도가 높아질수록 장애물과 적의 수가 증가하며, 제한된 시간 내에 목표를 달성해야 합니다.\n\n");

    printf("## 2. 게임 목표\n");
    printf("- 스톤 수집: 주어진 모든 스톤을 수집하여 다음 난이도로 진행합니다.\n");
    printf("- 시간 제한: 제한 시간 내에 목표를 달성해야 합니다.\n");
    printf("- 생명 관리: 적에게 게임을 지거나 어떤 깃발을 먹으면 생명이 감소합니다. 생명을 모두 잃으면 게임이 종료됩니다.\n\n");

    printf("## 3. 게임 시작하기\n");
    printf("난이도는 처음 게임을 시작할 때 설정됩니다. 게임이 진행됨에 따라 난이도가 자동으로 상승합니다:\n");
    printf("- 난이도 쉬움: 남은 스톤 1개, 제한 시간 70초\n");
    printf("- 난이도 보통: 남은 스톤 3개, 제한 시간 50초\n");
    printf("- 난이도 어려움: 남은 스톤 5개, 제한 시간 30초\n\n");
    printf("계속보시려면 아무키나 눌러주세요!");
    getchar();
    system("cls");
    printf("## 4. 게임 진행 방법\n");
    printf("플레이어는 '&'로 표시됩니다.\n");
    printf("방향키를 사용하여 상하좌우로 이동할 수 있습니다.\n");
    printf("이동하려는 위치에 장애물이 있으면 이동할 수 없습니다.\n\n");

    printf("적은 '?'로 표시되며, 매초 무작위로 움직입니다.\n");
    printf("적과 부딪히면 생명이 감소하고, 일정 시간이 지나면 게임이 종료됩니다.\n\n");

    printf("플래그에 도달하면 다양한 이벤트가 발생합니다:\n");
    printf("여러 개의 스톤이 숨겨져 있습니다.\n");
    printf("블랙홀: 처음 위치로 돌아갑니다.\n");
    printf("생명 감소되는 깃발이 있습니다.\n");
    printf("시간이 감소(8초)되거나 증가(10초)되는 깃발이 존재합니다.\n");

    printf("## 5. 수명 관리\n");
    printf("생명: 게임 시작 시 기본 생명은 3개입니다. 적과 부딪히거나 특정 플래그에 도달하면 생명이 감소합니다.\n");
    printf("생명 회복: 특정 플래그를 획득하면 생명이 증가할 수 있습니다.\n\n");

    printf("## 6. 화면 설명\n");
    printf("보드의 우측에 남은 시간이 표시되며, 현재 생명과 남은 스톤 수는 남은 시간 밑에 표시됩니다:\n");
    printf("계속보시려면 아무키나 눌러주세요!");
    getchar();
    system("cls");

    printf("## 7. 엔딩 조건\n");
    printf("주어진 모든 스톤을 수집하면 난이도가 상승하며, 최종 난이도까지 도달하면 게임이 종료됩니다.\n");
    printf("남은 시간이 0이 되거나 생명을 모두 잃으면 게임이 종료됩니다.\n\n");

    printf("## 8. 미니 게임 및 문제\n");
    printf("적과 조우하면 미니 게임이나 문제를 풀어야 합니다.\n");
    printf("문제 해결: 문제를 해결하지 못하면 생명이 감소하거나 게임이 일시적으로 중단됩니다.\n\n");

    printf("## 9. 점수 계산\n");
    printf("점수 공식: 남은 시간 * 100 + 생명 * 1000 + (5 - 남은 스톤 수) * 2000\n");
    printf("최종 점수: 모든 스톤을 수집하거나 게임이 종료되면 점수가 계산됩니다.\n\n");

    printf("## 10. 벌칙, 벌점\n");
    printf("적에게 잡힐 경우: 생명이 감소하며, 생명을 모두 잃으면 게임이 종료됩니다.\n");
    printf("시간 초과: 제한 시간이 0이 되면 게임이 종료됩니다.\n\n");

    printf("튜토리얼을 마치셨다면 아무 키나 눌러 초기화면으로 돌아가세요...\n");
    getch();
    showStartScreen();
}
void selectDifficulty()
{
    char diff[10];
    system("cls");
    printf("\n\n\n");
    printf("                                        ********************************\n");
    printf("                                        **                            **\n");
    printf("                                        **          *      *          **\n");
    printf("                                        **          *    *            **\n");
    printf("                                        **          *  *              **\n");
    printf("                                        **          ***               **\n");
    printf("                                        **          *  *              **\n");
    printf("                                        **          *    *            **\n");
    printf("                                        **          *      *          **\n");
    printf("                                        **                            **\n");
    printf("                                        ********************************\n");
    printf("\n");
    printf("                                             건벤져스 - 사라진 교수님\n\n\n");
    printf("                               ┌───────────────────────────────────────────────┐\n");
    printf("                               │                      쉬움                     │\n");
    printf("                               │                      보통                     │\n");
    printf("                               │                     어려움                    │\n");
    printf("                               └───────────────────────────────────────────────┘\n");
    int x = 50, y = 19, ch;
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
                if (y > 19)
                    y--;
                break;
            case DOWN:
                if (y < 21)
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
    if (y == 19)
    {
        strcpy(diff, "쉬움");
        remainingstone = 1;
        difficulty = 1;
    }
    else if (y == 20)
    {
        strcpy(diff, "보통");
        remainingstone = 3;
        difficulty = 2;
    }
    else
    {
        strcpy(diff, "어려움");
        remainingstone = 5;
        difficulty = 3;
    }
    printf("\n\n\n\n                                              %s를 선택하였습니다\n", diff);
    printf("\n                                           계속하려면 아무 키나 누르세요...\n");
    _getch();
}
