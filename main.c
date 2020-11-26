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

void input(int* x, int* y, int flag) {
    if (flag == TRUE) {
        printf("돌을 놓을 좌표를 입력 해주세요(x y): ");
        scanf("%d %d", x, y);
    } else {
        printf("잘못된 좌표입니다. 좌표를 다시 입력 해주세요(x y): ");
        scanf("%d %d", x, y);
    }
}

/**
 * 마킹 할 수 없는 경우의 수
 * 1. 인덱스를 벗어난 경우(0보다 작거나 N 이상인 경우)
 * 2. 이미 돌이 놓여진 곳 위에 돌을 놓으려고 시도하는 경우
 * 3. 놓으려는 위치가 조건에 부합하지 않는 경우(내돌 상대돌 내돌)
 */
int is_markable(int x, int y, int color) {
    // 1번 경우의 수
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return ERROR;
    }

    // 2번 경우의 수
    if (BOARD[x][y] != BLANK) {
        return ERROR;
    }

    // 3번 경우의 수

    return TRUE;
}

int find_direction(int x_0, int y_0, int x_1, int y_1) {
    // 두 좌표를 받아 방향을 반환

    if (x_0 == x_1) {
        // 무조건 y축 상, 하 이동
        if (y_0 > y_1) {
            // y_0 가 y_1보다 크므로
        }

        if (y_0 < y_1) {
            // y_1 가 y_0보다 크므로
        }
    }

    if (y_0 == y_1) {
        // 무조건 x축 좌, 우 이동
        if (x_0 > x_1) {
            // x_0 가 x_1보다 크므로
        }

        if (x_0 < x_1) {
            // x_1 가 x_0보다 크므로
        }
    }

    // 모든 경우의 수에 부합하지 않으므로 direction을 찾을 수 없는 -1 리턴
    return -1;
}

void marking(int x, int y, int color) {
    int x_1 = -1, y_1 = -1;
    // dir(방향)에 따라 색을 칠함.
    // 방향 경우의 수
    // x축 좌, 우
    // y축 상, 하
    // 우대각 상 하
    // 좌대각 상 하
    // 총 여덟 가지
    switch (find_direction(x, y, x_1, y_1)) {}
}

// 더 이상 돌을 놓을 수 없는 경우 게임을 종료하기 위한 플래그
// 아 모르겠다…..
int is_game_end() { return 0; }


void count_score(int* black_score, int* white_score) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            switch (BOARD[i][j]) {
                case BLACK: {
                    *black_score = *black_score + 1;
                    break;
                }
                case WHITE: {
                    *white_score = *white_score + 1;
                    break;
                }
            }
        }
    }
}

