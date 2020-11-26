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
void marking(int x, int y, int color);
void print_score();
int is_game_end();
int num_of_games = 0; //define which player moves first
int num_of_moves = 4; // initial BWBW



void init_othello() {
    int middle_value = (int)(N - 1) / 2;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            BOARD[i][j] = BLANK;
        }
    }

    BOARD[middle_value][middle_value] = BLACK;
    BOARD[middle_value + 1][middle_value + 1] = BLACK;
    BOARD[middle_value + 1][middle_value] = WHITE;
    BOARD[middle_value][middle_value + 1] = WHITE;
}

void print_board() {
    for (int i=0; i<N;i++) {
        for (int j=0; j<N;j++) {
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



/**
 * 마킹 할 수 없는 경우의 수
 * 1. 인덱스를 벗어난 경우(0보다 작거나 N 이상인 경우)
 * 2. 이미 돌이 놓여진 곳 위에 돌을 놓으려고 시도하는 경우
 * 3. 놓으려는 위치가 조건에 부합하지 않는 경우(내돌 상대돌 내돌)
 */
int is_markable(int x, int y, int color) {
    // 1번 경우의 수
    if (x < 0 || y < 0 || x >= N || y >= N) {
    	printf("inside is markablecase 1\n");
        return ERROR;
    }

    // 2번 경우의 수
    if (BOARD[x][y] != BLANK) {
    	printf("inside is markable case 2\n");
         return ERROR;
    }

    // 3번 경우의 수
       int row = x-1;
    int col = y-1;
    int row_delta = 0;
    int col_delta = 0;
    int opponent_x = 0;
    int opponent_y = 0;
    int opponent_color = 0;
    if (color == BLACK) {
        opponent_color = WHITE;
    } else {
        opponent_color = BLACK;
    }

    for (row_delta = -1; row_delta <= 1; row_delta++) {
        for (col_delta = -1; col_delta <= 1; col_delta++) {
            printf("inside is markeable\n");
            
         if (row + row_delta < 0 || row + row_delta >= N ||
                col + col_delta < 0 || col + col_delta >= N ||
                row_delta == 0 && col_delta == 0) {
                continue;
            }
              //printf("row %d\n", row);
            //printf("col %d\n", col);
            //printf("row+row_delta %d\n",row+row_delta);
            //printf("col+col_delta %d\n", col+col_delta);
            if (BOARD[row+row_delta][col+col_delta] == opponent_color) {
                //printf("inside opponent color\n");

                opponent_x = row + row_delta;
                opponent_y = col + col_delta;
   for(;;){
                    opponent_x += row_delta;
                    opponent_y += col_delta;

                    if(opponent_x < 0 || opponent_x >= N || opponent_y < 0 || opponent_y >= N){
                        break;
                    }

                    if(BOARD[opponent_x][opponent_y] == BLANK) {
                        break;
                    }

                    if (BOARD[opponent_x][opponent_y] == color) {
                       //printf("the other end : %d, %d\n", opponent_x, opponent_y);
                        markable_count++;
                        //printf("markable position %d\n", markable_count);
                        break;
                    }
                }
            }
        }
    }
    if (markable_count > 0){
        printf("There are %d number of vaild moves\n", markable_count);
        return TRUE;
    } else if(markable_count == 0) {
        printf("No vaild moves\n");
        return FALSE;
    }
    return 0;

}

void marking(int x, int y, int color) {
    int row = x-1;
    int col = y-1;
    int row_delta = 0;
    int col_delta = 0;
    int opponent_x = 0;
    int opponent_y = 0;

    int opponent_color = 0;
    if (color == BLACK) {
        opponent_color = WHITE;
    } else {
        opponent_color = BLACK;
    }

    for (row_delta = -1; row_delta <= 1; row_delta++) {
        for (col_delta = -1; col_delta <= 1; col_delta++) {
            //printf("inside marking\n");

            if (row + row_delta < 0 || row + row_delta >= N ||
                col + col_delta < 0 || col + col_delta >= N ||
                row_delta == 0 && col_delta == 0) {
                continue;
            }
            //printf("row %d\n", row);
            //printf("col %d\n", col);
            //printf("row+row_delta %d\n",row+row_delta);
            //printf("col+col_delta %d\n", col+col_delta);
            if (BOARD[row+row_delta][col+col_delta] == opponent_color) {
                //printf("inside marking\n");

                opponent_x = row + row_delta;
                opponent_y = col + col_delta;

                for(;;){
                    opponent_x += row_delta;
                    opponent_y += col_delta;

                    if(opponent_x < 0 || opponent_x >= N || opponent_y < 0 || opponent_y >= N){
                        break;
                    }

                    if(BOARD[opponent_x][opponent_y] == BLANK) {
                        break;
                    }

                    if (BOARD[opponent_x][opponent_y] == color) {
                        while(BOARD[opponent_x-=row_delta][opponent_y-=col_delta] == opponent_color)
                            BOARD[opponent_x][opponent_y] = color;
                        BOARD[x-1][y-1] = color;
                        break;
                    }
                }
            }
        }
    }
}
              




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

void print_score(int player_1_score, int player_2_score) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (BOARD[row][col] == BLACK){
                player_1_score++;
            } else if (BOARD[row][col] == WHITE) {
                player_2_score++;
            }
        }
    }
    printf("player 1 vs. player 2 \n %d : %d\n", player_1_score, player_2_score);


}

int is_game_end(int color){
    printf("sacn if there are vaild moves\n");
    int x = 0;
    int y = 0;
    int row_delta = 0;
    int col_delta = 0;
    int markable_count = 0;
    int opponent_color = 0;
    int blank_count = 0;
    
       if (color == BLACK) {

        opponent_color = WHITE;
    } else {

        opponent_color = BLACK;
    }

    for(int row = 0; row < N; row++){
        for(int col=0; col < N; col++){
            if(BOARD[row][col] != BLANK){
                continue;
            } else if (BOARD[row][col] == BLANK) {
                blank_count++;
            }
     int opponent_x = 0;
     int opponent_y = 0;

            for (row_delta = -1; row_delta <= 1; row_delta++) {
                for (col_delta = -1; col_delta <= 1; col_delta++) {


                    if (row + row_delta < 0 || row + row_delta >= N ||
                        col + col_delta < 0 || col + col_delta >= N ||
                        row_delta == 0 && col_delta == 0) {
                        continue;
                    }
                    //printf("row %d\n", row);
                    //printf("col %d\n", col);
                    //printf("row+row_delta %d\n",row+row_delta);
                    //printf("col+col_delta %d\n", col+col_delta);
                    if (BOARD[row+row_delta][col+col_delta] == opponent_color) {
                        //printf("inside opponent color\n");

                        opponent_x = row + row_delta;
                        opponent_y = col + col_delta;

                        for(;;){
                            opponent_x += row_delta;
                            opponent_y += col_delta;

                            if(opponent_x < 0 || opponent_x >= N || opponent_y < 0 || opponent_y >= N){
                                break;
                            }

                            if(BOARD[opponent_x][opponent_y] == BLANK) {
                                break;
                            }

                            if (BOARD[opponent_x][opponent_y] == color) {
                                //printf("the other end : %d, %d\n", opponent_x, opponent_y);
                                markable_count++;
                                //printf("markable position %d\n", markable_count);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    if (markable_count > 0){
        printf("There are %d number of vaild moves\n", markable_count);
        return TRUE;
    } else if(markable_count == 0) {
        printf("No vaild moves remain\n");

        if (blank_count > 0) {
            printf("cannot make move, skip turn\n");
            num_of_moves++;
            return TRUE;
        } else if (blank_count == 0) {
            return FALSE;
        }


    }
    return 0;

}



