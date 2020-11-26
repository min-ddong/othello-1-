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
    // 초기 값을 음수로 하여 인덱스 범위를 벗어나게 함.
    int x = -1, y = -1;
    // 검은색이 선공
    int color = BLACK;

    int flag = 0;
    int black_score = 0;
    int white_score = 0;

    int result = -1;

    init_othello();
    print_board();

    while (!is_game_end()) {
        // 여기에 들어왔다는 것은 게임이 끝나지 않았다는 것이므로 입력을 받음.
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
        // 줄 바꿈
        printf("\n");
    }

    // 다음 보드나 상용구 출력 구분을 위한 추가 줄 바꿈
    printf("\n");
}


