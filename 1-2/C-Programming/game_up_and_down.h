#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTRYNUMBER  5 // 최대 시도 숫자
#define MAXNUMBER 10 // 게임 입력 최대 숫자

/*
* Up & Down 게임 시작
*/
int start_game_up_and_down() {
	int isplay = 0; // 계속 실행 여부
	int game_count = 0; // 게임수
	int success_count = 0; // 성공 
	int player = 0; // 사용자가 입력한 값
	int number = 0; // 맞춰야할 숫자
	int try_count = 1; // 시도 숫자

	// 게임 시작
	while (isplay == 0)
	{
		game_count++; // 게임 진행 숫자 +1
		try_count = 1; // 시도 횟수 초기화
		printf("********* Up & Down 게임 %d번째 게임입니다. *********\n", game_count);
		printf("한 게임당 %d번의 기회가 존재합니다.\n", MAXTRYNUMBER);

		// 1. 숫자 랜덤 생성
		srand(time(NULL));
		number = (rand() % MAXNUMBER) + 1; // 1~게임 입력 최대숫자까지

		// 시도 횟수가 끝날때까지 반복
		while (MAXTRYNUMBER >= try_count) {
			// 2. 플레이어 입력
			while (1) {
				printf("1~%d까지의 숫자 중 하나를 입력 (%d 번째 시도) : ", MAXNUMBER,  try_count);
				scanf("%d", &player);

				// 입력한 숫자가 1~최대입력수 사이에 있는지 체크 후 맞으면 while문 종료
				if (player >= 1 && player <= MAXNUMBER) {
					break;
				}
				else {
					printf("잘못 입력하였습니다. 다시 입력해주세요.\n");
				}
			}

			// 3. 숫자 비교 후 출력
			if (number == player)
			{
				printf("%d번째 시도에 숫자를 맞추었습니다!\n", try_count);
				success_count++; // 성공 수 추가
				break;
			}
			else if (number > player)
			{ // 맞춰야하는 숫자가 더 큰 경우
				printf("Up !\n");
				try_count++; // 시도 횟수 추가
			}
			else { // 맞춰야 하는 숫자가 더 작은 경우
				printf("Down!\n");
				try_count++; // 시도 횟수 추가
			}
		}

		// 정답을 맞추지 못한 경우 정답 출력
		if (number != player)
		{
			printf("정답은 %d 입니다.\n", number);
		}

		printf("\n"); // 한칸 띄우기

		// 게임을 계속 진행할지 체크 후 종료
		while (1) {
			printf("%d번째 게임입니다. 계속 하시겠습니까? (0 예, 1 아니오) : ", game_count);
			scanf("%d", &isplay);

			if (isplay == 0 || isplay == 1) { // 입력한 숫자가 0, 1인지 체크 후 맞으면 while문 종료
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