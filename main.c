#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1

#define BLANK -1
#define BLACK 0
#define WHITE 1

#define N 6

int BOARD[N][N];

void init_othello();
void print_board();
int is_game_end();
int is_markable(int x, int y, int color);
void input(int* x, int* y, int flag);
int find_direction(int x_0, int y_0, int x_1, int y_1);
void marking(int x, int y, int color);
void count_score(int* black_score, int* white_score);

int main() {
    // �ʱ� ���� ������ �Ͽ� �ε��� ������ ����� ��.
    int x = -1, y = -1;
    // �������� ����
    int color = BLACK;

    int flag = 0;
    int black_score = 0;
    int white_score = 0;

    int result = -1;

    init_othello();
    print_board();

    while (!is_game_end()) {
        // ���⿡ ���Դٴ� ���� ������ ������ �ʾҴٴ� ���̹Ƿ� �Է��� ����.
        input(&x, &y, 1);

        while (1) {
            flag = is_markable(x, y, color);

            if (flag == TRUE) {
                marking(x, y, color);
                color = !color;
                break;
            }

            input(&x, &y, flag);
        }
    }

    count_score(&black_score, &white_score);
    printf("BLACK[%d]:WHITE[%d]\n", black_score, white_score);

    if (black_score > white_score) {
        printf("BLACK WIN!!\n");
    } else if (black_score < white_score) {
        printf("WHITE WIN!!\n");
    }

    return 0;
}

void init_othello() {
    int temp = 0;
    int middle_value = (int)(N - 1) / 2;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            BOARD[i][j] = BLANK;
        }
    }

    BOARD[middle_value][middle_value] = BLACK;
    BOARD[middle_value + 1][middle_value + 1] = BLACK;
    BOARD[middle_value + 1][middle_value] = WHITE;
    BOARD[middle_value][middle_value + 1] = WHITE;
}

void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            switch (BOARD[i][j]) {
                case BLANK: {
                    printf("N ");
                    break;
                }
                case BLACK: {
                    printf("B ");
                    break;
                }
                case WHITE: {
                    printf("W ");
                    break;
                }
            }
        }
        // �� �ٲ�
        printf("\n");
    }

    // ���� ���峪 ��뱸 ��� ������ ���� �߰� �� �ٲ�
    printf("\n");
}

void input(int* x, int* y, int flag) {
    if (flag == TRUE) {
        printf("���� ���� ��ǥ�� �Է� ���ּ���(x y): ");
        scanf("%d %d", x, y);
    } else {
        printf("�߸��� ��ǥ�Դϴ�. ��ǥ�� �ٽ� �Է� ���ּ���(x y): ");
        scanf("%d %d", x, y);
    }
}

/**
 * ��ŷ �� �� ���� ����� ��
 * 1. �ε����� ��� ���(0���� �۰ų� N �̻��� ���)
 * 2. �̹� ���� ������ �� ���� ���� �������� �õ��ϴ� ���
 * 3. �������� ��ġ�� ���ǿ� �������� �ʴ� ���(���� ��뵹 ����)
 */
int is_markable(int x, int y, int color) {
    // 1�� ����� ��
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return ERROR;
    }

    // 2�� ����� ��
    if (BOARD[x][y] != BLANK) {
        return ERROR;
    }

    // 3�� ����� ��

    return TRUE;
}

int find_direction(int x_0, int y_0, int x_1, int y_1) {
    // �� ��ǥ�� �޾� ������ ��ȯ

    if (x_0 == x_1) {
        // ������ y�� ��, �� �̵�
        if (y_0 > y_1) {
            // y_0 �� y_1���� ũ�Ƿ�
        }

        if (y_0 < y_1) {
            // y_1 �� y_0���� ũ�Ƿ�
        }
    }

    if (y_0 == y_1) {
        // ������ x�� ��, �� �̵�
        if (x_0 > x_1) {
            // x_0 �� x_1���� ũ�Ƿ�
        }

        if (x_0 < x_1) {
            // x_1 �� x_0���� ũ�Ƿ�
        }
    }

    // ��� ����� ���� �������� �����Ƿ� direction�� ã�� �� ���� -1 ����
    return -1;
}

void marking(int x, int y, int color) {
    int x_1 = -1, y_1 = -1;
    // dir(����)�� ���� ���� ĥ��.
    // ���� ����� ��
    // x�� ��, ��
    // y�� ��, ��
    // ��밢 �� ��
    // �´밢 �� ��
    // �� ���� ����
    switch (find_direction(x, y, x_1, y_1)) {}
}

// �� �̻� ���� ���� �� ���� ��� ������ �����ϱ� ���� �÷���
// �� �𸣰ڴ١�..
int is_game_end() { return 0; }


