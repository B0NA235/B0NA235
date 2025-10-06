//BullsAndCows.c
/*4자리 숫자를임의로 정한 뒤 플레이어가 예측 숫자를 부른다(최대 9번)
사용되는 숫자는 0에서 9까지 서로 다른 숫자
숫자는 맞지만 위치가 틀렸으면 BALL
숫자와 위치 전부 맞으면 STRIKE
숫자 위치 전부 틀리면 OUT
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void compare(int answer[], int input[]);

int main(){
    srand(time(NULL));
    int input[4];
    int option;
    int answer[4];
    int count = 0;
    char retry;

    while(1)
    {
        for (int i=0;i<4;i++){
            answer[i] = rand()%10;
            for (int j=0;j<i;j++)
            {
                if (answer[i] == answer[j])
                {
                    answer[j] = rand()%10;
                }
            }
        }
        printf("숫자 야구 게임\n1: 룰 설명, 그 외 숫자: 바로 시작\n");
        scanf("%d", &option);
        printf("-------------------------------------------------------------------------");
        if (option == 1)
        {
            printf("컴퓨터가 생성한 \"0에서 9까지의 서로 다른 4자리 숫자\" 맞히기\n");
            printf("숫자는 맞지만 위치가 틀렸으면 BALL\n숫자와 위치 전부 맞으면 STRIKE\n숫자 위치 전부 틀렸다면 OUT");
            printf("-------------------------------------------------------------------------\n");
        }
        for (int i=0;i<9;i++)
        {
            printf("%d번째 시도\n", count+1);
            printf("0부터 9까지의 숫자 중 4개를 입력하세요(띄어쓰기로 구분, 10이상은 종료):");
            for (int j=0;j<4;j++)
            {
                scanf(" %d", &input[j]);
                if (input[j] > 9){
                    printf("프로그램을 종료합니다\n");
                    return 0;
                }
            }
            compare(answer, input);
            count++;
        }
        printf("정답: ");
        for(int i=0;i<4;i++)
        {
            printf("%d", answer[i]);
        }
        printf("\n한 번 더 하시겠습니까? Y or N\n");
        scanf("%c", &retry);
        switch(retry)
        {
            case 'Y':
                count = 0;
                break;
            case 'N':
                printf("프로그램을 종료합니다\n");
                return 0;
            default:
                printf("잘못된 입력입니다. 프로그램을 종료합니다\n");
                return 0;
            }

    }
}

void compare(int answer[], int input[]){
    int strike = 0, ball = 0, out = 0;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (answer[i] == input[j])
            {
                if (i == j)
                {
                    strike++;
                    break;
                }
                else
                {
                    ball++;
                    break;
                }
            }else{
                if (j == 3)
                {
                    out++;
                }
            }
        }
    }
    printf("STRIKE: %d | BALL: %d | OUT: %d\n", strike, ball, out);
    if (strike == 4){
        printf("Win!");
    }
}