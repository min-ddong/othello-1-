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
        // �� �ٲ�
        printf("\n");
    }

    // ���� ���峪 ��뱸 ��� ������ ���� �߰� �� �ٲ�
    printf("\n");
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
    	printf("inside is markablecase 1\n");
        return ERROR;
    }

    // 2�� ����� ��
    if (BOARD[x][y] != BLANK) {
    	printf("inside is markable case 2\n");
         return ERROR;
    }

    // 3�� ����� ��
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



