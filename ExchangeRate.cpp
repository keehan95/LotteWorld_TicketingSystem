#include <stdio.h> 

/*
�ܾ� ��� �Լ� 
�ܾ� = ��ȭ - ((INT)(ȯ���ݾ�) x ȯ��)
1������ �ݿø� ���
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
�ܾ� ��� �Լ� 
1000,500,100,50,10������ ��� 
*/
void printCharge(int charge){
	int won1000 = charge / 1000;
	int won500 = (charge - won1000*1000) / 500;
	int won100 = (charge - won1000*1000 - won500*500) / 100;
	int won50 = (charge - won1000*1000 - won500*500 - won100*100) / 50;
	int won10 = (charge- won1000*1000 - won500*500 - won100*100 - won50*50) / 10;
	printf("�Ž����� : %d�� ( 1000�� : %d��, 500�� : %d��, 100�� : %d��, 50�� : %d��,  10�� : %d��)\n",charge, won1000, won500, won100, won50, won10);
}

int main(){
	const float RATE_USD = 1233.50; // �̱� ȯ�� 
	const float RATE_JPY = 9.84; // �Ϻ� ȯ�� 
	const float RATE_EUR = 1341.92; // �������� ȯ�� 
	const float RATE_CNY = 193.21; // �߱� ȯ�� 
	const float RATE_GBP = 1602.93; // ���� ȯ��
	 
	 
	int inputWon = 0; // �Է� ��ȭ ���� 
	int choice = 0; // ȯ���� ��ȭ ���� ���� 
 	
 	//ȯ�� �ݾ� 
	float outputUSD = 0;  
	float outputJPY = 0; 
	float outputEUR = 0;
	float outputCNY = 0; 
	float outputGBP = 0;
	
	printf("ȯ���� ���ϴ� �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%d", &inputWon);
	printf("ȯ���� ��ȭ�� �����ϼ��� (1:USD, 2:JPY, 3:EUR, 4:CNY, 5:GBP) : ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1: {
			printf("���� ȯ�� : %.2f\n",RATE_USD);
			printf("ȯ�� ���\n");
			outputUSD = inputWon / RATE_USD; //�޷�  ��� 
			int usdCharge = calculateCharge(inputWon, outputUSD, RATE_USD); // �Ž����� ��� 
			printf("�޷� : %d�޷�\n",(int)outputUSD);
			printCharge(usdCharge);
			break;
		}
		case 2:{
			printf("���� ȯ�� : %.2f\n",RATE_JPY);
			printf("ȯ�� ���\n");
			outputJPY = inputWon / RATE_JPY; // ��ȭ �ݾ� ��� 
			int jpyCharge = calculateCharge(inputWon, outputJPY, RATE_JPY); //�Ž����� ���	
			printf("�� : %d��\n",(int)outputJPY);
			printCharge(jpyCharge);
			break;
		}
		case 3:{
			printf("���� ȯ�� : %.2f\n",RATE_EUR);
			printf("ȯ�� ���\n");
			outputEUR = inputWon / RATE_EUR; //���� ��� 
			int eurCharge = calculateCharge(inputWon, outputEUR, RATE_EUR); //�Ž����� ���	
			printf("���� : %d����\n",(int)outputEUR);
			printCharge(eurCharge);
			break;		
		}
		case 4:{
			printf("���� ȯ�� : %.2f\n",RATE_CNY);
			printf("ȯ�� ���\n");
			outputCNY = inputWon / RATE_CNY; //���� ��� 
			int cnyCharge = calculateCharge(inputWon, outputCNY, RATE_CNY); //�Ž����� ���	
			printf("���� : %d����\n",(int)outputCNY);
			printCharge(cnyCharge);
			break;		
		}
		case 5:{
			printf("���� ȯ�� : %.2f\n",RATE_GBP);
			printf("ȯ�� ���\n");
			outputGBP = inputWon / RATE_GBP; //�Ŀ�� ��� 
			int gbpCharge = calculateCharge(inputWon, outputGBP, RATE_GBP); //�Ž����� ��� 
			printf("�Ŀ�� : %d�Ŀ��\n",(int)outputGBP);
			printCharge(gbpCharge);
			break;	
		}
		default:{
			printf("�߸� �Է��ϼ̽��ϴ�.");
			break;
		}
	}
	return 0;
}




	
	
