#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 모든 함수 선언
void play_game(); // 게임 진행

// 여러 함수에서 사용하는 변수 선언
int game_count = 0; // 게임수
int win_count = 0; // 성공 

/*
* 가위바위보 게임 시작 함수
*/
void start_game_scissors_rock_bo() {
	int isplay = 0; // 계속 실행 여부

	// 게임 시작
	while (isplay == 0)
	{
		game_count++; // 게임 진행 숫자 +1
		printf("********* 가위바위보 %d번째 게임입니다. *********\n", game_count);

		play_game(); // 게임 시작

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

	// 종료 후 전적과 승률 출력
	printf("당신의 전적은 %d전 %d승입니다.\n", game_count, win_count);
	printf("당신의 승률은 %.2f%%입니다.\n", ((float)win_count / game_count) * 100);
	printf("\n게임을 종료하였습니다.\n\n");
}

/*
* 가위바위보 게임 진행
*/
void play_game()
{
	int computer_result = 0; // 컴퓨터 가위바위보 결과
	int player_result = 0; // 사용자 가위바위보 결과

	// 1. 가위바위보 랜덤 생성
	srand(time(NULL));
	computer_result = rand() % 3; // 0~2

	// 2. 플레이어 입력
	while (1) {
		printf("가위바위보를 입력 해주세요 (0 가위, 1 바위, 2 보) : ");
		scanf("%d", &player_result);

		// 플레이어가 입력한 숫자가 0~2 사이인지 체크 후 맞으면 while문 종료
		if (player_result >= 0 && player_result <= 2) {
			break;
		}
		else {
			printf("잘못 입력하였습니다. 다시 입력해주세요.\n");
		}
	}

	// 3. 가위바위보 비교 후 출력
	if (computer_result == player_result) {
		printf("비겼습니다.\n");
		printf("컴퓨터는 %d를 선택했고, 당신은 %d를 선택했습니다.\n", computer_result, player_result);
	}
	else if ((computer_result < player_result && !(computer_result == 0 && player_result == 2))
		|| (computer_result == 2 && player_result == 0))
	{ // 가위 < 바위 < 보 순서로 이기지만, 가위 > 보가 이기는 경우를 추가하기 위한 코드
		printf("%d번째로 이겼습니다!\n", win_count + 1);
		printf("컴퓨터는 %d를 선택했고, 당신은 %d를 선택했습니다.\n", computer_result, player_result);
		win_count++; // 성공 수 추가
	}
	else
	{
		printf("졌습니다.\n");
		printf("컴퓨터는 %d를 선택했고, 당신은 %d를 선택했습니다.\n", computer_result, player_result);
	}

	printf("\n"); // 한칸 띄우기
}