#include <stdio.h> 

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
	
	do{
	printf("환전을 원하는 금액을 입력하세요(원화) : ");
	scanf("%d", &inputWon);
	printf("환전할 외화를 선택하세요 (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
	scanf("%d", &choice);
	if(choice == 1){
		printf("기준 환율 : %.2f\n",RATE_USD);
		printf("환전 결과\n");
		outputUSD = inputWon / RATE_USD; //달러  계산 
		int usdCharge = calculateCharge(inputWon, outputUSD, RATE_USD); // 거스름돈 계산 
		printf("달러 : %d달러\n",(int)outputUSD);
		printCharge(usdCharge);
	} else if (choice == 2){
		printf("기준 환율 : %.2f\n",RATE_JPY);
		printf("환전 결과\n");
		outputJPY = (inputWon / RATE_JPY)-(int)(inputWon / RATE_JPY)%100; // 엔화 금액 계산 
		int jpyCharge = calculateCharge(inputWon, outputJPY, RATE_JPY); //거스름돈 계산	
		printf("엔 : %d엔\n",(int)outputJPY);
		printCharge(jpyCharge);
	} else if (choice == 3){
		printf("기준 환율 : %.2f\n",RATE_EUR);
		printf("환전 결과\n");
		outputEUR = inputWon / RATE_EUR; //유로 계산 
		int eurCharge = calculateCharge(inputWon, outputEUR, RATE_EUR); //거스름돈 계산	
		printf("유로 : %d유로\n",(int)outputEUR);
		printCharge(eurCharge);
	} else if (choice == 4){
		printf("기준 환율 : %.2f\n",RATE_CNY);
		printf("환전 결과\n");
		outputCNY = inputWon / RATE_CNY; //위안 계산 
		int cnyCharge = calculateCharge(inputWon, outputCNY, RATE_CNY); //거스름돈 계산	
		printf("위안 : %d위안\n",(int)outputCNY);
		printCharge(cnyCharge);
	} else if (choice == 5){
		printf("기준 환율 : %.2f\n",RATE_GBP);
		printf("환전 결과\n");
		outputGBP = inputWon / RATE_GBP; //파운드 계산 
		int gbpCharge = calculateCharge(inputWon, outputGBP, RATE_GBP); //거스름돈 계산 
		printf("파운드 : %d파운드\n",(int)outputGBP);
		printCharge(gbpCharge);
	} else {
		printf("메뉴를 잘못 선택하셨습니다. (입력 : %d)\n", choice);
	}
}while(choice < 1 || choice > 5);
	 

/*	
switch ~ case문 연습
 
	switch(choice){
		case 1: {
			printf("기준 환율 : %.2f\n",RATE_USD);
			printf("환전 결과\n");
			outputUSD = inputWon / RATE_USD; //달러  계산 
			int usdCharge = calculateCharge(inputWon, outputUSD, RATE_USD); // 거스름돈 계산 
			printf("달러 : %d달러\n",(int)outputUSD);
			printCharge(usdCharge);
			break;
		}
		case 2:{
			printf("기준 환율 : %.2f\n",RATE_JPY);
			printf("환전 결과\n");
			outputJPY = (inputWon / RATE_JPY)-(int)(inputWon / RATE_JPY)%100; // 엔화 금액 계산 
			int jpyCharge = calculateCharge(inputWon, outputJPY, RATE_JPY); //거스름돈 계산	
			printf("엔 : %d엔\n",(int)outputJPY);
			printCharge(jpyCharge);
			break;
		}
		case 3:{
			printf("기준 환율 : %.2f\n",RATE_EUR);
			printf("환전 결과\n");
			outputEUR = inputWon / RATE_EUR; //유로 계산 
			int eurCharge = calculateCharge(inputWon, outputEUR, RATE_EUR); //거스름돈 계산	
			printf("유로 : %d유로\n",(int)outputEUR);
			printCharge(eurCharge);
			break;		
		}
		case 4:{
			printf("기준 환율 : %.2f\n",RATE_CNY);
			printf("환전 결과\n");
			outputCNY = inputWon / RATE_CNY; //위안 계산 
			int cnyCharge = calculateCharge(inputWon, outputCNY, RATE_CNY); //거스름돈 계산	
			printf("위안 : %d위안\n",(int)outputCNY);
			printCharge(cnyCharge);
			break;		
		}
		case 5:{
			printf("기준 환율 : %.2f\n",RATE_GBP);
			printf("환전 결과\n");
			outputGBP = inputWon / RATE_GBP; //파운드 계산 
			int gbpCharge = calculateCharge(inputWon, outputGBP, RATE_GBP); //거스름돈 계산 
			printf("파운드 : %d파운드\n",(int)outputGBP);
			printCharge(gbpCharge);
			break;	
		}
		default:{
			printf("잘못 입력하셨습니다.");
			break;
		}
	}
	*/
	return 0;
}
