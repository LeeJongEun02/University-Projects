#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGOSIZE 3 // 빙고 3x3으로 사이즈 입력

// 함수 초기화
void reset_bingo(int board[BINGOSIZE][BINGOSIZE]); // 빙고 리셋
void input_bingo(int board[BINGOSIZE][BINGOSIZE]); // 빙고 만들기
void print_board(int board[BINGOSIZE][BINGOSIZE]); // 빙고 출력
void remove_number(int board[BINGOSIZE][BINGOSIZE], int number); // 빙고판 숫자 삭제
int count_bingo_lines(int board[BINGOSIZE][BINGOSIZE]); // 빙고 개수 세기

/*
* 빙고 게임 시작
*/
int start_game_bingo() {
    int isplay = 0; // 계속 실행 여부
    int game_count = 0; // 게임수
    int success_count = 0; // 성공 
    int number = 0; // 빙고 하려는 숫자
    int player_bingo_line = 0; // 사용자 빙고 줄 수
    int computer_bingo_line = 0; // 컴퓨터 빙고 줄 수
    int try_game = 0; // 게임 시도 횟수
    int is_player_turn = 0; // 플레이어 턴 여부

    int random_board[BINGOSIZE][BINGOSIZE]; // 랜덤 빙고판
    int player_board[BINGOSIZE][BINGOSIZE]; // 플레이어 빙고판

    // 게임 시작
    while (isplay == 0)
    {
        game_count++; // 게임 진행 숫자 +1
        player_bingo_line = 0; // 사용자 빙고 줄 수 초기화
        computer_bingo_line = 0; // 컴퓨터 빙고 줄 수 초기화
        try_game = 0; // 게임 시도 횟수 초기화

        printf("********* 숫자 빙고 게임 %d번째 게임입니다. *********\n", game_count);
        printf("0부터 9까지 숫자를 입력하여 빙고를 완성해주세요!\n");
        printf("X는 이미 지워진 숫자를 나타냅니다.\n");
        printf("빙고는 1줄이 되면 종료됩니다..\n");

        // 1. 빙고판 초기화
        srand(time(NULL));
        reset_bingo(random_board); // 랜덤 빙고 생성

        input_bingo(player_board); // 사용자 빙고 입력
        print_board(player_board); // 사용자 빙고 출력

        // 2. 빙고가 1줄이 될때까지 반복하거나 시도 횟수가 10번이 되면 종료
        while (player_bingo_line < 1 && computer_bingo_line < 1 && try_game < 10) {
            int used[10] = { 0 };  // 숫자 중복 방지 배열

            // 3. 숫자 입력
            if (is_player_turn == 1) {
                // 숫자를 제대로 입력할 때까지 실행
                while (1) {
                    printf("숫자를 입력하세요 (0 ~ 9): ");
                    scanf("%d", &number);

                    if (number < 0 || number > 9) { // 0~9 사이의 숫자를 입력했는지 체크
                        printf("잘못된 입력입니다. 0 ~ 9 사이의 숫자를 입력하세요.\n");
                    }
                    else if (used[number] == 1) { // 숫자가 중복되는지 체크
                        printf("숫자가 중복됩니다. 다시 입력해주세요. \n");
                    }
                    else {
                        printf("선택한 숫자 : %d\n", number);
                        break;
                    }
                }
                is_player_turn = 0; // 컴퓨터 턴으로 변경
            }
            else {
                // 숫자를 제대로 입력할 때까지 실행
                while (1) {
                    number = rand() % 10;  // 0 ~ 9 사이 숫자 랜덤 생성

                    if (used[number] == 0) { // 중복되는 숫자가 아닌 경우인지 체크
                        printf("선택한 숫자 : %d\n", number);
                        break;
                    }
                }
                is_player_turn = 1; // 플레이어 턴으로 변경
            }
            
            // 4. 빙고 숫자 제거
            remove_number(player_board, number); // 사용자 빙고 숫자 제거
            remove_number(random_board, number); // 컴퓨터 빙고 숫자 제거
            print_board(player_board); // 사용자 빙고판 출력

            // 5. 빙고 개수 세기
            player_bingo_line = count_bingo_lines(player_board); // 사용자 빙고 개수 세기
            computer_bingo_line = count_bingo_lines(random_board); // 컴퓨터 빙고 개수 세기

            if (player_bingo_line >= 1) { // 사용자 빙고 개수가 1개 이상인지 체크
                printf("%d 빙고로 이겼습니다.\n", player_bingo_line);
                success_count++; // 성공 횟수 추가
            }
            else if (computer_bingo_line >= 1) { // 컴퓨터 빙고 개수가 1개 이상인지 체크
                printf("컴퓨터가 %d 빙고로 이겼습니다.\n", computer_bingo_line);
            }
            try_game++; // 게임 시도 횟수 추가
        }

        printf("\n"); // 한칸 띄우기

        // 게임을 계속 진행할지 체크 후 종료
        while (1) {
            printf("%d번째 게임입니다. 계속 하시겠습니까? (0 예, 1 아니오) : ", game_count);
            scanf("%d", &isplay);

            if (isplay == 0 || isplay == 1) { // 사용자가 제대로 입력했으면 체크 후 while문 종료
                break;
            }
            else {
                printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
            }
        }
    }

    printf("당신의 전적은 %d전 %d승입니다.\n", game_count, success_count);
    printf("당신의 승률은 %.2f%%입니다.\n", ((float)success_count / game_count) * 100);
    printf("게임을 종료하였습니다.\n\n");

    return 0;
}


/*
* 빙고판 초기화
* @param board - 빙고판
*/
void reset_bingo(int board[BINGOSIZE][BINGOSIZE]) {
    int used[10] = { 0 };  // 숫자 중복 방지 배열
    int i, j, num;

    // 이중 for문을 사용하여 빙고판 3x3 확인
    for (i = 0; i < BINGOSIZE; i++) {
        for (j = 0; j < BINGOSIZE; j++) {
            do { // 일단 시작
                num = rand() % 10;  // 0 ~ 9 사이 숫자
            } while (used[num] == 1); // 이미 사용된 숫자이면 다시 실행
            board[i][j] = num; // 중복되지 않는 숫자 빙고판에 넣기
            used[num] = 1;  // 사용된 숫자로 표시
        }
    }
}


/*
* 빙고판 입력
* @param board - 빙고판
*/
void input_bingo(int board[BINGOSIZE][BINGOSIZE]) {
    int used[10] = { 0 };  // 숫자 중복 방지 배열
    int i, j, num;

    // 이중 for문을 사용하여 빙고판 3x3 확인
    for (i = 0; i < BINGOSIZE; i++) {
        for (j = 0; j < BINGOSIZE; j++) {
            while(1) {
                printf("빙고판 %d 번째에 입력할 숫자를 입력해주세요. (0~9 사이의 숫자): ", (i * 3) + j + 1);
                scanf("%d", &num);

                if (num < 0 || num > 9) { // 입력한 숫자가 0~9 사이에 있는지 체크
                    printf("잘못된 입력입니다. 0 ~ 9 사이의 숫자를 입력하세요.\n");
                }else  if (used[num] == 1) { // 숫자가 이미 입력한 숫자인지 체크
                    printf("숫자가 중복됩니다. 다시 입력해주세요.\n");
                }
                else { // 0~9사이의 숫자이며 중복되지 않을 경우 while문 종료
                    break;
                }
            }
            board[i][j] = num; // 빙고판에 숫자 입력
            used[num] = 1;  // 사용된 숫자로 표시
        }
    }
}


/*
* 빙고판  출력
* @param board - 빙고판
*/
void print_board(int board[BINGOSIZE][BINGOSIZE]) {
    int i, j;

    printf("=== 빙고판 ===\n");

    // 이중 for문을 사용하여 빙고판 3x3 확인
    for (i = 0; i < BINGOSIZE; i++) {
        for (j = 0; j < BINGOSIZE; j++) {
            if (board[i][j] == -1) { // 빙고의 숫자가 -1일 경우 체크
                printf(" X ");  // 지워진 숫자는 X로 표시
            }
            else {
                printf(" %d ", board[i][j]);
            }
        }
        printf("\n");
    }
}


/*
* 빙고판  숫자 삭제
* @param board - 빙고판
*/
void remove_number(int board[BINGOSIZE][BINGOSIZE], int number) {
    int i, j;

    // 이중 for문을 사용하여 빙고판 3x3 확인
    for (i = 0; i < BINGOSIZE; i++) {
        for (j = 0; j < BINGOSIZE; j++) {
            if (board[i][j] == number) { // 빙고판의 숫자가 선택한 숫자와 같은지 체크
                board[i][j] = -1;  // 숫자 제거 (-1로 변경)
            }
        }
    }
}


/*
* 빙고 개수 세기
* @param board - 빙고판
* @return lines - 빙고 개수
*/
int count_bingo_lines(int board[BINGOSIZE][BINGOSIZE]) {
    int lines = 0; // 빙고 개수
    int i, count, j; // for문, 빙고 개수 검사시 사용하는 변수
    int count_diagonal1, count_diagonal2; // 대각선 검사시 사용하는 변수

    // 가로 검사
    for (i = 0; i < BINGOSIZE; i++) {
        count = 0; // 빙고 개수 초기화
        for (j = 0; j < BINGOSIZE; j++) {
            if (board[i][j] == -1) { // -1인 삭제된 값인지 체크
                count++; // 빙고 개수 추가Q
            }
        }
        if (count == BINGOSIZE) { // 빙고 개수가 빙고 사이즈와 같은지 체크
            lines++; // 빙고 줄 수 추가
        }
    }

    // 세로 검사
    for (j = 0; j < BINGOSIZE; j++) {
        count = 0; // 빙고 개수 초기화
        for (i = 0; i < BINGOSIZE; i++) {
            if (board[i][j] == -1) { // -1인 삭제된 값인지 체크
                count++; // 빙고 개수 추가
            }
        }
        if (count == BINGOSIZE) { // 빙고 개수가 빙고 사이즈와 같은지 체크
            lines++; // 빙고 줄 수 추가
        }
    }

    // 대각선 검사 (왼쪽 위 -> 오른쪽 아래)
    count_diagonal1 = 0; // 빙고 개수 초기화
    for (i = 0; i < BINGOSIZE; i++) {
        if (board[i][i] == -1) { // -1인 삭제된 값인지 체크
            count_diagonal1++; // 빙고 개수 추가
        }
    }
    if (count_diagonal1 == BINGOSIZE) { // 빙고 개수가 빙고 사이즈와 같은지 체크
        lines++; // 빙고 줄 수 추가
    }

    // 대각선 검사 (오른쪽 위 -> 왼쪽 아래)
    count_diagonal2 = 0; // 빙고 개수 초기화
    for (i = 0; i < BINGOSIZE; i++) {
        if (board[i][BINGOSIZE - 1 - i] == -1) { // -1인 삭제된 값인지 체크
            count_diagonal2++; // 빙고 개수 추가
        }
    }
    if (count_diagonal2 == BINGOSIZE) { // 빙고 개수가 빙고 사이즈와 같은지 체크
        lines++; // 빙고 줄 수 추가
    }

    return lines; // 빙고 줄수 리턴
}