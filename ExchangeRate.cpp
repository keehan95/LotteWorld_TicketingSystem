#include <stdio.h> 
/*
환전 금액 계산 함수
엔화는 100엔 단위 환전
*/ 
float calculateOutput(int won, float output, float rate, int choice){
	if(choice == 2){
		output = (won / rate) - (int)(won / rate)%100;
	} else {
	output = won / rate;
	}
}

/*
잔액 계산 함수 
잔액 = 원화 - ((INT)(환전금액) x 환율)
1원단위 반올림 계산
*/ 
int calculateCharge(int won, float output, float rate ){
	int charge = won - ((int)output*rate);
	if(charge %10 >=5){
		charge = charge-(charge%10)+10;
	}else{
		charge = charge-(charge%10);
	}
	return charge;
}

/*
잔액 출력 함수 
1000,500,100,50,10원단위 출력 
*/
void printCharge(int charge){
	int won1000 = charge / 1000;
	int won500 = (charge - won1000*1000) / 500;
	int won100 = (charge - won1000*1000 - won500*500) / 100;
	int won50 = (charge - won1000*1000 - won500*500 - won100*100) / 50;
	int won10 = (charge- won1000*1000 - won500*500 - won100*100 - won50*50) / 10;
	printf("거스름돈 : %d원 ( 1000원 : %d개, 500원 : %d개, 100원 : %d개, 50원 : %d개,  10원 : %d개)\n",charge, won1000, won500, won100, won50, won10);
} 

/*
결과 출력 함수 
*/
void printResult(int won, float output, float rate, int choice){
	printf("기준 환율 : %.2f\n",rate);
	printf("환전 결과\n");
	output = calculateOutput(won, output, rate, choice);
	int charge = calculateCharge(won, output, rate);
	switch(choice){
		case 1:{
			printf("달러 : %d달러\n",(int)output);
			break;
		}
		case 2:{
			printf("엔 : %d엔\n",(int)output);
			break;
		}
		case 3:{
			printf("유로 : %d유로\n",(int)output);
			break;
		}
		case 4:{
			printf("위안 : %d위안\n",(int)output);
			break;
		}
		case 5:{
			printf("파운드 : %d파운드\n",(int)output);
			break;
		}
		default:{
			break;
		}
	}
	printCharge(charge);
}	




int main(){
	const float RATE_USD = 1233.50; // 미국 환율 
	const float RATE_JPY = 9.84; // 일본 환율 
	const float RATE_EUR = 1341.92; // 유럽연합 환율 
	const float RATE_CNY = 193.21; // 중국 환율 
	const float RATE_GBP = 1602.93; // 영국 환율
	 
	 
	int inputWon = 0; // 입력 원화 변수 
	int choice = 0; // 환전할 외화 단위 변수 
 	
 	//환전 금액 
	float outputUSD = 0;  
	float outputJPY = 0; 
	float outputEUR = 0; 
	float outputCNY = 0; 
	float outputGBP = 0;
	
	printf("환전을 원하는 금액을 입력하세요(원화) : ");
	scanf("%d", &inputWon);
	
	do {
	printf("환전할 외화를 선택하세요 (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
	scanf("%d", &choice);
	} while (choice < 1 || choice > 5);

	if (choice == 1){
		printResult(inputWon, outputUSD, RATE_USD, choice);
	} else if (choice == 2){
		printResult(inputWon, outputJPY, RATE_JPY, choice);
	} else if (choice == 3){
		printResult(inputWon, outputEUR, RATE_EUR, choice);
	} else if (choice == 4){
		printResult(inputWon, outputCNY, RATE_CNY, choice);
	} else {
		printResult(inputWon, outputGBP, RATE_GBP, choice);
	} 

	return 0;
}
