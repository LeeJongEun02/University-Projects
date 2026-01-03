#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
* 동전 게임 시작
*/
int start_game_coin() {
	int isplay = 0; // 계속 실행 여부
	int game_count = 0; // 게임수
	int success_count = 0; // 성공 
	int player = 0; // 사용자가 입력한 값
	int coin = 0; // 생성된 동전 면

	// 게임 시작
	while (isplay == 0)
	{
		game_count++; // 게임 수 추가
		printf("********* 동전게임 %d번째 게임입니다. *********\n", game_count);
		// 1. 동전 랜덤 생성
		srand(time(NULL));
		coin = rand() % 2; // 0~1

		// 2. 플레이어 입력
		while (1) {
			printf("동전 입력 (0 앞면, 1 뒷면) : ");
			scanf("%d", &player);

			// 동전을 제대로 입력했는지 체크 후 제대로 입력했으면 while문 종료
			if (player >= 0 && player <= 1) {
				break;
			}
			else {
				printf("잘못 입력하였습니다. 다시 입력해주세요.\n");
			}
		}

		// 3. 동전 비교 후 출력
		if (coin == player)
		{
			printf("%d번째 정답입니다!\n", success_count + 1);
			success_count++; // 성공 수 추가
		}
		else
		{
			printf("틀렸습니다.\n");
		}

		printf("\n"); // 한칸 띄우기

		// 게임을 계속 진행할지 체크 후 종료
		while (1) {
			printf("%d번째 게임입니다. 계속 하시겠습니까? (0 예, 1 아니오) : " , game_count);
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