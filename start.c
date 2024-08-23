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
            if (ch == 13) { // Enter Ű �Է�
                *stopFlag = 1;
                printf("%s", text);
                break;
            }
            else if (ch == 27) { // Esc Ű �Է�
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
    printTypingEffect("�Ǻ�����\n", 50, &stopFlag);
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
        if (ch == 13) { // Enter Ű �Է�
            if (stopFlag) return; // �̹� ��µ� ���¸� ���� ȭ������
            stopFlag = 1; // ���丮 ��ü ���
        }
        else if (ch == 27) { // Esc Ű �Է�
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
    printf("\n- ������ �ձ�: �Ǳ����б��� ������\n\n");
    printTypingEffect("�Ǳ����б��� ��ȭ�ο� ķ�۽��� ��� �� ���ڱ� ��û�� ��ȭ�� �Ͼ��.     \n���ٶ��� ����Ÿ��� �׳�, �л����� ��ҿ� �ٸ����� ���ǽǷ�, ����������, ī��� ���ϰ� �־���.\n������ �׳��� ��ȭ�� �������� �ʾҴ�. Ÿ�뽺....  �״� ���� ��ȭ �� �Ǵ��� ���̶� �����ߴ�. \n�׷��� ����� ������� ���Ƿ� ���� ����, ��� ���� ��������. \nŸ�뽺�� �հ����� ƨ��� ����, ķ�۽��� �� �״�� ������ ����. \n�����Ե�� �л����� ���İ��� �������, �Ǳ����б��� ���� ����� ���̴�. �ҿ� �����Ե� �� �� �� ���̾���. \n�׳�� C ���α׷��� ������ ����ġ�� ���� �л��鿡�� ������ �ִ� �ι��̾���.\nŸ�뽺�� �հ��� ƨ������ ���� ����� �̵��� ��ã�� ���� �ð��� �ٰ����� �־���. �Ǳ����б��� �л����� ������ ������. \n�׵��� ��� C ���α׷����� ���� ���� ����� �����ؾ� �߰�, ������ ���� ���ϸ� ������ �Ұ����ߴ�.\n�װ��� �ܼ��� ���� ������ �ƴϾ���.������ ���� ���ϸ� �׵��� �޵�, �̷��� ������� ���̾���.\nķ�۽����� ���尨�� �����Ҵ�. �л����� ���θ� �ٶ󺸸� ���𰡸� �ؾ� �Ѵٴ� ���� ������ �־���. \n�ٷ� �׶�, �� ������ �л����� �� ���Ǹ� ������. \n�׵��� �ҿ� �����԰� ����� �л����� ��ã�ƾ� �ߴ�. �׷��� ������ ��� F ������ �ް� �� ���̾���. ", 50, &stopFlag);
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
        if (ch == 13) { // Enter Ű �Է�
            if (stopFlag) return; // �̹� ��µ� ���¸� ���� ȭ������
            stopFlag = 1; // ���丮 ��ü ���
        }
        else if (ch == 27) { // Esc Ű �Է�
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
    printf("\n- �̼�: ���Ǵ�Ƽ ������ ã�Ƽ�\n\n");
    printTypingEffect("�л����� �ҿ� �������� ��ã�� ���� '�����'�� �Ǿ�� �ߴ�. \n�׵��� ķ�۽� ������ ����� �ִ� ���Ǵ�Ƽ ������ ã�ƾ߸� �ߴ�.\n�� ���濡�� ������ ���� ���� �־���, �װ͵��� ��� ��ƾ� Ÿ�뽺�� �հ��� ƨ���� �ǵ��� �� �־���.\n\n�ð��� ���� : �л����� �б��� ������ �ð�ž���� �ð��� �ǵ��� �� �ִ� ������ ã�ƾ� �ߴ�.\n�� ������ ���ŷ� ���ư� Ÿ�뽺�� ��ȹ�� ���� �� �ִ� ���� ������ �־���.\n\n������ ���� : �� ������ ķ�۽� ���� ��� �����ǿ� ������ �־���.�������� �������� ���εǾ� �־���, \n�װ��� �����Ϸ��� ������ ������ Ǯ��� �ߴ�.\n\n��ȥ�� ���� : ��ȥ�� ������ ķ�۽��� ���� ���� ���� ��ġ��, �� ���� ���� ������ �־���.\n�̰����� ������ ��� ���ؼ��� �ڽ��� ���� �����ϰ� �����ϴ� ���� ����ؾ� �ߴ�.\n\n������ ���� : �������� �ݼ� �ڳʿ� ������ �� ������ ������ �ְ��ų �� �־���.\n�������� ���� ��, �ݼ� �ڳʿ� �����Ϸ��� ���� ������ �����ϴ� ��� ����ؾ� �ߴ�.\n\n���� ���� : ü������ ���Ͽ� �ִ� �� ������ ������ ��� ��Ŀ�������� ��ȣ�ǰ� �־���.\n���� ������ �������� ��û�� ���� ��⸦ ������ �ߴ�.\n\n������ ���� : ������ ������ �г��� ��� ������ ����� ����ü�� �߽ɿ� �־���.\n�� ������ ��� ���ؼ��� ���� �����ϰ�, �ŷڸ� �׾ƾ� �ߴ�.", 50, &stopFlag);
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
        if (ch == 13) { // Enter Ű �Է�
            if (stopFlag) return; // �̹� ��µ� ���¸� ���� ȭ������
            stopFlag = 1; // ���丮 ��ü ���
        }
        else if (ch == 27) { // Esc Ű �Է�
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
    printf("\n- ������ ����\n\n");
    printTypingEffect("�л����� ���� �ٸ� ������ ������ �� ������ ã�� ���� ������ �����ߴ�.\n�׵��� �� ������ ã�� ���� ���� ������ ������ �޾�����, ������ ���� ���� �غ��� ������.\n\n�ð��� ������ ã�� ���� �ð�ž�� ���� ���� ���ŷ� ���ư� Ÿ�뽺�� ù ��° ħ���� ���� ����� �����ߴ�. \n\n������ ������ ã�� ���� ���� �����ǿ� �� ���� ������ ������ Ǯ�� ������ ����� �����´�.\n\n��ȥ�� ������ ã�� ���� �� �� ������ ������ ���� �ڽŵ��� ���� ������ ����� ���� ����ϸ� ������ ��⸦ �����־���.\n\n������ ������ ã�� ���� �������� �ݼ� �ڳʷ� ���� ���� ������ ������ ����ϸ� ������ �ٲ� �� �ִ� ���� �����.\n\n���� ������ ã�� ���� ü���� ���Ϸ� ������ ���� ������ ��� ��Ŀ������ ����� ������ �տ� �־���.\n\n���������� ������ ������ ã�� ���� ����ü�� �߽����� ���� ���� ������ �ŷڿ� ������ ���� ������ ������ ���´�.", 50, &stopFlag);
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
        if (ch == 13) { // Enter Ű �Է�
            if (stopFlag) return; // �̹� ��µ� ���¸� ���� ȭ������
            stopFlag = 1; // ���丮 ��ü ���
        }
        else if (ch == 27) { // Esc Ű �Է�
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
    printf("\n- ������ ���\n\n");
    printTypingEffect("��� ������ ���� �л����� Ÿ�뽺���� ������ ����� �غ��ߴ�.\n�׵��� ���� ���� Ÿ�뽺�� �հ��� ƨ���� �ǵ�����, ����� �ҿ� �����԰� �л����� ��ã�� ���� ���Ǹ� ������.\n�ᱹ, �л����� ��°� ��� ���п� Ÿ�뽺�� ���� ��������, �հ��� ƨ���� �ǵ��ư���.\n�ҿ� �����԰� ����� �л����� �ٽ� ���ƿ԰�, ķ�۽��� ��ȭ�� ��ã�Ҵ�.\n�л����� ��� A + ������ �޾Ұ�, C ���α׷��� ������ ���������� �̼��� �� �־���.\n�׵��� �̹� ������ ���� ������ ���� ������ �ǹ̸� �����, \n� ������� ���ĵ� �Բ� �̰ܳ� �� �ִٴ� �ڽŰ��� ��� �Ǿ���.", 50, &stopFlag);
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
        if (ch == 13) { // Enter Ű �Է�
            if (stopFlag) return; // �̹� ��µ� ���¸� ���� ȭ������
            stopFlag = 1; // ���丮 ��ü ���
        }
        else if (ch == 27) { // Esc Ű �Է�
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
    printf("\n- ���ʷα�\n\n");
    printTypingEffect("�Ǳ����б��� �л����� �̹� ����� ���� ���� �� �����ߴ�.\n�׵��� �ܼ��� ������ �Ѿ� ������ ���°� ����� �߿伺�� ���޾Ҵ�.\nŸ�뽺���� �ο��� ��������, �����ε� ���� ������ ��ٸ��� �־���.\n�׷��� �׵��� ���� ���θ� �ϰ� �Բ� ���ư� �غ� �Ǿ� �־���.\n�׸��� �׵��� �̾߱�� �������� �Ǳ����б��� ������ ����, �Ĺ�鿡�� ������ �ִ� �̾߱Ⱑ �Ǿ���.\n�� �̾߱�� �ܼ��� ��ȭ �� �������� �̾߱Ⱑ �ƴ϶�, \n���� �ӿ����� �츮�� �Բ� ���� ���� �̰ܳ� �� �ִٴ� ������ �ɾ��ִ� �̾߱�� ���Ҵ�.", 50, &stopFlag);
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
        if (ch == 13) { // Enter Ű �Է�
            if (stopFlag) return; // �̹� ��µ� ���¸� ���� ȭ������
            stopFlag = 1; // ���丮 ��ü ���
        }
        else if (ch == 27) { // Esc Ű �Է�
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
    printf("                                             �Ǻ����� - ����� ������\n\n\n");
    printf("                               ��������������������������������������������������������������������������������������������������\n");
    printf("                               ��                    ���� ����                  ��\n");
    printf("                               ��                    ���� ��Ģ                  ��\n");
    printf("                               ��                      ����                     ��\n");
    printf("                               ��������������������������������������������������������������������������������������������������\n");
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
    printf("���� Ʃ�丮��\n\n");

    printf("## 1. ���� ����\n");
    printf("�� ������ �ڼҿ� �����԰� ģ������ ���ϱ� ���� ����� ��ֹ��� ���� ����� �÷��׸� �����ϴ� �����Դϴ�.\n");
    printf("���̵��� ���������� ��ֹ��� ���� ���� �����ϸ�, ���ѵ� �ð� ���� ��ǥ�� �޼��ؾ� �մϴ�.\n\n");

    printf("## 2. ���� ��ǥ\n");
    printf("- ���� ����: �־��� ��� ������ �����Ͽ� ���� ���̵��� �����մϴ�.\n");
    printf("- �ð� ����: ���� �ð� ���� ��ǥ�� �޼��ؾ� �մϴ�.\n");
    printf("- ���� ����: ������ ������ ���ų� � ����� ������ ������ �����մϴ�. ������ ��� ������ ������ ����˴ϴ�.\n\n");

    printf("## 3. ���� �����ϱ�\n");
    printf("���̵��� ó�� ������ ������ �� �����˴ϴ�. ������ ����ʿ� ���� ���̵��� �ڵ����� ����մϴ�:\n");
    printf("- ���̵� ����: ���� ���� 1��, ���� �ð� 70��\n");
    printf("- ���̵� ����: ���� ���� 3��, ���� �ð� 50��\n");
    printf("- ���̵� �����: ���� ���� 5��, ���� �ð� 30��\n\n");
    printf("��Ӻ��÷��� �ƹ�Ű�� �����ּ���!");
    getchar();
    system("cls");
    printf("## 4. ���� ���� ���\n");
    printf("�÷��̾�� '&'�� ǥ�õ˴ϴ�.\n");
    printf("����Ű�� ����Ͽ� �����¿�� �̵��� �� �ֽ��ϴ�.\n");
    printf("�̵��Ϸ��� ��ġ�� ��ֹ��� ������ �̵��� �� �����ϴ�.\n\n");

    printf("���� '?'�� ǥ�õǸ�, ���� �������� �����Դϴ�.\n");
    printf("���� �ε����� ������ �����ϰ�, ���� �ð��� ������ ������ ����˴ϴ�.\n\n");

    printf("�÷��׿� �����ϸ� �پ��� �̺�Ʈ�� �߻��մϴ�:\n");
    printf("���� ���� ������ ������ �ֽ��ϴ�.\n");
    printf("��Ȧ: ó�� ��ġ�� ���ư��ϴ�.\n");
    printf("���� ���ҵǴ� ����� �ֽ��ϴ�.\n");
    printf("�ð��� ����(8��)�ǰų� ����(10��)�Ǵ� ����� �����մϴ�.\n");

    printf("## 5. ���� ����\n");
    printf("����: ���� ���� �� �⺻ ������ 3���Դϴ�. ���� �ε����ų� Ư�� �÷��׿� �����ϸ� ������ �����մϴ�.\n");
    printf("���� ȸ��: Ư�� �÷��׸� ȹ���ϸ� ������ ������ �� �ֽ��ϴ�.\n\n");

    printf("## 6. ȭ�� ����\n");
    printf("������ ������ ���� �ð��� ǥ�õǸ�, ���� ����� ���� ���� ���� ���� �ð� �ؿ� ǥ�õ˴ϴ�:\n");
    printf("��Ӻ��÷��� �ƹ�Ű�� �����ּ���!");
    getchar();
    system("cls");

    printf("## 7. ���� ����\n");
    printf("�־��� ��� ������ �����ϸ� ���̵��� ����ϸ�, ���� ���̵����� �����ϸ� ������ ����˴ϴ�.\n");
    printf("���� �ð��� 0�� �ǰų� ������ ��� ������ ������ ����˴ϴ�.\n\n");

    printf("## 8. �̴� ���� �� ����\n");
    printf("���� �����ϸ� �̴� �����̳� ������ Ǯ��� �մϴ�.\n");
    printf("���� �ذ�: ������ �ذ����� ���ϸ� ������ �����ϰų� ������ �Ͻ������� �ߴܵ˴ϴ�.\n\n");

    printf("## 9. ���� ���\n");
    printf("���� ����: ���� �ð� * 100 + ���� * 1000 + (5 - ���� ���� ��) * 2000\n");
    printf("���� ����: ��� ������ �����ϰų� ������ ����Ǹ� ������ ���˴ϴ�.\n\n");

    printf("## 10. ��Ģ, ����\n");
    printf("������ ���� ���: ������ �����ϸ�, ������ ��� ������ ������ ����˴ϴ�.\n");
    printf("�ð� �ʰ�: ���� �ð��� 0�� �Ǹ� ������ ����˴ϴ�.\n\n");

    printf("Ʃ�丮���� ��ġ�̴ٸ� �ƹ� Ű�� ���� �ʱ�ȭ������ ���ư�����...\n");
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
    printf("                                             �Ǻ����� - ����� ������\n\n\n");
    printf("                               ��������������������������������������������������������������������������������������������������\n");
    printf("                               ��                      ����                     ��\n");
    printf("                               ��                      ����                     ��\n");
    printf("                               ��                     �����                    ��\n");
    printf("                               ��������������������������������������������������������������������������������������������������\n");
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
        strcpy(diff, "����");
        remainingstone = 1;
        difficulty = 1;
    }
    else if (y == 20)
    {
        strcpy(diff, "����");
        remainingstone = 3;
        difficulty = 2;
    }
    else
    {
        strcpy(diff, "�����");
        remainingstone = 5;
        difficulty = 3;
    }
    printf("\n\n\n\n                                              %s�� �����Ͽ����ϴ�\n", diff);
    printf("\n                                           ����Ϸ��� �ƹ� Ű�� ��������...\n");
    _getch();
}
