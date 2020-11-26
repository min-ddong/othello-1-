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

