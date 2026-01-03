#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXTRYNUMBER  5 // 최대 시도 횟수
#define DIGITS 3 // 숫자 야구 길이

/*
* 숫자 야구 게임 시작
*/
int start_game_num_ball() {
	int isplay = 0; // 계속 실행 여부
	int game_count = 0; // 게임수
	int success_count = 0; // 성공 
	int try_count = 1;  // 시도 숫자

	int player_numbers[DIGITS]; // 사용자가 입력한 값
	int random_numbers[DIGITS]; // 맞춰야할 숫자

	int i = 0; // for문을 위한 i
	int j = 0; // for문을 위한 j
	int new_number = 0; // 새 숫자
	int duplicated = 0; // 사용자 입력 중복 
	int strike = 0; // 스트라이크 개수
	int ball = 0; // 볼 개수

	// 게임 시작
	while (isplay == 0)
	{
		game_count++; // 게임 횟수 추가
		try_count = 1; // 시도 횟수 초기화
		printf("********* 숫자 야구 게임 %d번째 게임입니다. *********\n", game_count);
		printf("한 게임당 %d번의 기회가 존재합니다.\n", MAXTRYNUMBER);

		// 1. 숫자 랜덤 생성
		int used[10] = { 0 };  // 숫자 사용 여부 확인용 배열
		for (i = 0; i < DIGITS; i++) { // 숫자 야구 길이만큼 반복
			do { // 일단 시작
				srand(time(NULL));
				new_number = rand() % 10;  // 0 ~ 9 사이 랜덤 숫자 생성
			} while (used[new_number] == 1);  // 중복 확인
			random_numbers[i] = new_number; // 입력한 숫자 저장
			used[new_number] = 1;  // 사용된 숫자 표시
		}

		printf("컴퓨터가 0~9 사이의 중복되지 않은 3자리 숫자를 생성했습니다.\n");

		// 시도 횟수가 끝날때까지 반복
		while (MAXTRYNUMBER >= try_count) {
			// 사용자 입력 받기
			do { // 일단 시작
				duplicated = 1; // 중복  여부 초기화
				printf("중복되지 않는 3자리 숫자를 입력해주세요 : ");
				for (int i = 0; i < DIGITS; i++) { // 숫자 야구 길이만큼 반복
					scanf("%1d", &player_numbers[i]);  // 한 자리씩 입력받기
				}

				// 중복 확인
				for (int i = 0; i < DIGITS; i++) {
					for (int j = i + 1; j < DIGITS; j++) {
						// 중복 체크
						if (player_numbers[i] == player_numbers[j]) {
							printf("중복된 숫자가 있습니다. 다시 입력하세요.\n");
							duplicated = 0; // 숫자가 중복됨으로
							break;
						}
					}
					if (duplicated == 0) { // 숫자가 중복될 경우 종료
						break;
					}
				}
			} while (duplicated == 0); // 숫자가 중복되면 종료

			strike = 0; // 스트라이크 수 초기화
			ball = 0; /// 볼 수 초기화

			// 스트라이크, 볼 수 세기
			for (i = 0; i < DIGITS; i++) {
				for (j = 0; j < DIGITS; j++) {
					// 정답과 숫자가 같은지 체크
					if (player_numbers[i] == random_numbers[j]) {
						if (i == j) { // 숫자 위치가 동일한지 체크
							(strike)++; // 스트라이크 수 추가
						}
						else { // 숫자 위치가 동일하지 않을 경우
							(ball)++; // 볼 수 추가
						}
					}
				}
			}

			printf("결과: %d 스트라이크, %d 볼\n", strike, ball);

			// 스트라이크 수가 야구 게임 길이와 동일할 경우 게임 종료
			if (strike == DIGITS) {
				printf("축하합니다! 정답을 맞췄습니다! 시도 횟수: %d번\n", try_count);
				success_count++;
				break;
			}

			try_count++; // 시도횟수 추가
		}

		// 스트라이크 수가 게임 길이와 동일하지 않을 경우
		if (strike != DIGITS) {
			printf("게임 오버! 정답은 ");
			// 정답 출력
			for (int i = 0; i < DIGITS; i++) {
				printf("%d", random_numbers[i]);
			}
			printf("였습니다.\n");
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