#include <stdio.h>
#include "game_rock_paper_scissors.h"
#include "game_coin.h"
#include "game_up_and_down.h"
#include "game_num_ball.h"
#include "game_bingo.h"

/*
* 메뉴 선택 함수
*/
void menu() {

	int menu_num = 0; // 메뉴번호
	int menu_result = 0; // 메뉴 선택 성공 여부

	// 메뉴 선택이 될 때까지 반복
	while (menu_result == 0) {
		// 메뉴 선택 출력
		printf("====== 메뉴 선택 ======\n");
		printf("0. 시스템 종료\n");
		printf("1. 가위바위보 게임\n");
		printf("2. 동전 게임\n");
		printf("3. Up & Down 게임\n");
		printf("4. 숫자 야구 게임\n");
		printf("5. 숫자 빙고 게임\n");
		printf("메뉴를 선택해주세요 : ");

		// 메뉴 입력 받기
		scanf("%d", &menu_num);

		// 메뉴 선택
		switch (menu_num) {
		case 0:
			printf("\n게임 메뉴 선택을 종료합니다.\n");
			menu_result = 1; // 메뉴 선택 완료
			break;
		case 1:
			printf("\n====== 가위바위보 게임을 시작합니다. ======\n");
			start_game_scissors_rock_bo(); // 게임시작
			break;
		case 2:
			printf("\n====== 동전 게임을 시작합니다. ======\n");
			start_game_coin(); // 게임시작
			break;
		case 3:
			printf("\n====== Up & Down 게임을 시작합니다. ======\n");
			start_game_up_and_down(); // 게임시작
			break;
		case 4:
			printf("\n====== 숫자 야구 게임을 시작합니다. ======\n");
			start_game_num_ball(); // 게임시작
			break;
		case 5:
			printf("\n====== 숫자 빙고 게임을 시작합니다. ======\n");
			start_game_bingo(); // 게임시작
			break;
		default:
			printf("메뉴를 잘 못 선택하였습니다.\n");
			break;
		}
	}
}