#include <stdio.h>
#include <time.h>

int main() {
	
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	 
	printf("now: %d-%d-%d %d:%d:%d\n\n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec); 
	       
	int ticketNumber = 0;
	int personNumber; 
	int birth; 
	int prefer;
	int charge1D[] = {62000, 54000, 47000, 15000};
	int chargeA4[] = {50000, 43000, 36000, 15000};
	int chargeP1D[] = {59000, 52000, 46000, 15000};
	int chargePA4[] = {47000, 41000, 35000, 15000};
	
	int plusCharge = 0;
	int age;
	int charge = 0;
	int saleCharge = 0;
	
	int cntA = 0;
	int cntY = 0;
	int cntC = 0;
	int cntB = 0;
	
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	int cnt4 = 0;
	int cnt5 = 0;
	int cnt6 = 0;
	 
	
	if (tm.tm_hour >21 || tm.tm_hour < 10)
	{
		printf("지금은 영업시간이 아닙니다.\n영업시간: 매일 10:00 ~ 21:00\n");
	 } 
	
	if (tm.tm_hour >= 10 && tm.tm_hour < 21)
	{
		do {
		printf("권종을 선택하세요.\n1. 종합이용권(이용범위: 롯데월드+민속박물관)\n2. 파크이용권(이용범위: 롯데월드)\n");
		scanf("%d", &ticketNumber);
	}while(ticketNumber < 1 || ticketNumber > 2);
	
	printf("\n몇개를 주문하시겠습니까?\n");
	scanf("%d", &personNumber);
	
	if (ticketNumber == 1 && tm.tm_hour >= 10 && tm.tm_hour < 16)
	{
		int index;
		
		for (index = 1; index <= personNumber; index++)
		{
			printf("생년월일 8자리를 입력하세요.  ex) 19950708\n"); 
			scanf("%d", &birth);
			
			int birY = birth / 10000; // 태어난 년도를 추출 
			int birM = (birth % 1000) / 100; // 태어난 월을 추출 
			int birD = birth % 100; // 태어난 날을 추출 
			
			int age = 0;
			
			if ((birM > tm.tm_mon+1) || (birM == tm.tm_mon+1 && birD >= tm.tm_mday)) //오늘이 생일이거나 이미 지났을 경우 
			{
				age = tm.tm_year+1900 - birY;
				
				if (age >= 19 && age < 65)
				{
					charge = charge1D[0];
					cntA++;
				} else if (age >= 13 && age <= 18)
				{
					charge = charge1D[1];
					cntY++;
				} else if (age >= 3 && age <= 12)
				{
					charge = charge1D[2];
					cntC++;
				} else if (age <= 2)
				{
					charge = charge1D[3];
					cntB++;
				} else if (age >= 65)
				{
					charge = charge1D[3];
					cntA++;
				}		
			} else if (birM < tm.tm_mon+1)//아직 생일을 지나지 않았을 경우 
			{
				age = tm.tm_year+1900 - birY -1;
				
				if (age >= 19 && age < 65)
				{
					charge = charge1D[0];
					cntA++;
				} else if (age >= 13 && age <= 18)
				{
					charge = charge1D[1];
					cntY++;
				} else if (age >= 3 && age <= 12)
				{
					charge = charge1D[2];
					cntC++;
				} else if (age <= 2)
				{
					charge = charge1D[3];
					cntB++;
				} else if (age >= 65)
				{
					charge = charge1D[3];
					cntA++;
				}
			}
			
			printf("\n우대사항을 선택하세요.\n");
			printf("1. 없음 (나이 우대는 자동처리)\n2. 장애인\n3. 국가유공자\n4. 휴가장병\n5. 임산부\n6. 다둥이\n");
			scanf("%d", &prefer);
			
			switch (prefer)
			{
			case 1:
				saleCharge = charge;
				plusCharge = plusCharge + saleCharge;
				cnt1++;
				break;
			case 2:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt2++;
				break;
			case 3:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt3++;
				break;
			case 4:
				saleCharge = (int)((float)charge * 0.61);
				plusCharge = plusCharge + saleCharge;
				cnt4++;
				break;
			case 5:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt5++;
				break;
			case 6:
				saleCharge = (int)((float)charge * 0.7);
				plusCharge = plusCharge + saleCharge;
				cnt6++;
				break;
			default:
				printf("default\n");		
				break;
			}
			printf("요금: %d원\n\n", saleCharge);
		} 
	} else if (ticketNumber == 1 && tm.tm_hour >= 16 && tm.tm_hour < 21)
	{
		int index;
		
		for (index = 1; index <= personNumber; index++)
		{
			printf("생년월일 8자리를 입력하세요.  ex) 19950708\n"); 
			scanf("%d", &birth);
			
			int birY = birth / 10000; // 태어난 년도를 추출 
			int birM = (birth % 1000) / 100; // 태어난 월을 추출 
			int birD = birth % 100; // 태어난 날을 추출 
			
			int age = 0;
			
			if ((birM > tm.tm_mon+1) || (birM == tm.tm_mon+1 && birD >= tm.tm_mday)) //오늘이 생일이거나 이미 지났을 경우 
			{
				age = tm.tm_year+1900 - birY;
				
				if (age >= 19 && age < 65)
				{
					charge = chargeA4[0];
					cntA++;
				} else if (age >= 13 && age <= 18)
				{
					charge = chargeA4[1];
					cntY++;
				} else if (age >= 3 && age <= 12)
				{
					charge = chargeA4[2];
					cntC++;
				} else if (age <= 2)
				{
					charge = chargeA4[3];
					cntB++;
				} else if (age >= 65)
				{
					charge = chargeA4[3];
					cntA++;
				}		
			} else if (birM < tm.tm_mon+1)//아직 생일을 지나지 않았을 경우 
			{
				age = tm.tm_year+1900 - birY -1;
				
				if (age >= 19 && age < 65)
				{
					charge = chargeA4[0];
					cntA++;
				} else if (age >= 13 && age <= 18)
				{
					charge = chargeA4[1];
					cntY++;
				} else if (age >= 3 && age <= 12)
				{
					charge = chargeA4[2];
					cntC++;
				} else if (age <= 2)
				{
					charge = chargeA4[3];
					cntB++;
				} else if (age >= 65)
				{
					charge = chargeA4[3];
					cntA++;
				}
			}
			
			printf("\n우대사항을 선택하세요.\n");
			printf("1. 없음 (나이 우대는 자동처리)\n2. 장애인\n3. 국가유공자\n4. 휴가장병\n5. 임산부\n6. 다둥이\n");
			scanf("%d", &prefer);
			
			switch (prefer)
			{
			case 1:
				saleCharge = charge;
				plusCharge = plusCharge + saleCharge;
				cnt1++;
				break;
			case 2:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt2++;
				break;
			case 3:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt3++;
				break;
			case 4:
				saleCharge = (int)((float)charge * 0.61);
				plusCharge = plusCharge + saleCharge;
				cnt4++;
				break;
			case 5:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt5++;
				break;
			case 6:
				saleCharge = (int)((float)charge * 0.7);
				plusCharge = plusCharge + saleCharge;
				cnt6++;
				break;
			default:
				printf("default\n");		
				break;
			}
			printf("요금: %d원\n\n", saleCharge);
		}
	} else if (ticketNumber == 2 && tm.tm_hour >= 10 && tm.tm_hour < 16)
	{
		int index;
		
		for (index = 1; index <= personNumber; index++)
		{
			printf("생년월일 8자리를 입력하세요.  ex) 19950708\n"); 
			scanf("%d", &birth);
			
			int birY = birth / 10000; // 태어난 년도를 추출 
			int birM = (birth % 1000) / 100; // 태어난 월을 추출 
			int birD = birth % 100; // 태어난 날을 추출 
			
			int age = 0;
			
			if ((birM > tm.tm_mon+1) || (birM == tm.tm_mon+1 && birD >= tm.tm_mday)) //오늘이 생일이거나 이미 지났을 경우 
			{
				age = tm.tm_year+1900 - birY;
				
				if (age >= 19 && age < 65)
				{
					charge = chargeP1D[0];
					cntA++;
				} else if (age >= 13 && age <= 18)
				{
					charge = chargeP1D[1];
					cntA++;
				} else if (age >= 3 && age <= 12)
				{
					charge = chargeP1D[2];
					cntA++;
				} else if (age <= 2)
				{
					charge = chargeP1D[3];
					cntA++;
				} else if (age >= 65)
				{
					charge = chargeP1D[3];
					cntA++;
				}		
			} else if (birM < tm.tm_mon+1)//아직 생일을 지나지 않았을 경우 
			{
				age = tm.tm_year+1900 - birY -1;
				
				if (age >= 19 && age < 65)
				{
					charge = chargeP1D[0];
					cntA++;
				} else if (age >= 13 && age <= 18)
				{
					charge = chargeP1D[1];
					cntY++;
				} else if (age >= 3 && age <= 12)
				{
					charge = chargeP1D[2];
					cntC++;
				} else if (age <= 2)
				{
					charge = chargeP1D[3];
					cntB++;
				} else if (age >= 65)
				{
					charge = chargeP1D[3];
					cntA++;
				}
			}
			
			printf("\n우대사항을 선택하세요.\n");
			printf("1. 없음 (나이 우대는 자동처리)\n2. 장애인\n3. 국가유공자\n4. 휴가장병\n5. 임산부\n6. 다둥이\n");
			scanf("%d", &prefer);
			
			switch (prefer)
			{
			case 1:
				saleCharge = charge;
				plusCharge = plusCharge + saleCharge;
				cnt1++;
				break;
			case 2:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt2++;
				break;
			case 3:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt3++;
				break;
			case 4:
				saleCharge = (int)((float)charge * 0.61);
				plusCharge = plusCharge + saleCharge;
				cnt4++;
				break;
			case 5:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt5++;
				break;
			case 6:
				saleCharge = (int)((float)charge * 0.7);
				plusCharge = plusCharge + saleCharge;
				cnt6++;
				break;
			default:
				printf("default\n");		
				break;
			}
			printf("요금: %d원\n\n", saleCharge);
		}
	} else if (ticketNumber == 2 && tm.tm_hour >= 16 && tm.tm_hour < 21)
	{
		int index;
		
		for (index = 1; index <= personNumber; index++)
		{
			printf("생년월일 8자리를 입력하세요.  ex) 19950708\n"); 
			scanf("%d", &birth);
			
			int birY = birth / 10000; // 태어난 년도를 추출 
			int birM = (birth % 1000) / 100; // 태어난 월을 추출 
			int birD = birth % 100; // 태어난 날을 추출 
			
			int age = 0;
			
			if ((birM > tm.tm_mon+1) || (birM == tm.tm_mon+1 && birD >= tm.tm_mday)) //오늘이 생일이거나 이미 지났을 경우 
			{
				age = tm.tm_year+1900 - birY;
				
				if (age >= 19 && age < 65)
				{
					charge = chargePA4[0];
					cntA++;
				} else if (age >= 13 && age <= 18)
				{
					charge = chargePA4[1];
					cntY++;
				} else if (age >= 3 && age <= 12)
				{
					charge = chargePA4[2];
					cntC++;
				} else if (age <= 2)
				{
					charge = chargePA4[3];
					cntB++;
				} else if (age >= 65)
				{
					charge = chargePA4[3];
					cntA++;
				}		
			} else if (birM < tm.tm_mon+1)//아직 생일을 지나지 않았을 경우 
			{
				age = tm.tm_year+1900 - birY -1;
				
				if (age >= 19 && age < 65)
				{
					charge = chargePA4[0];
					cntA++;
				} else if (age >= 13 && age <= 18)
				{
					charge = chargePA4[1];
					cntY++;
				} else if (age >= 3 && age <= 12)
				{
					charge = chargePA4[2];
					cntC++;
				} else if (age <= 2)
				{
					charge = chargePA4[3];		
					cntB++;		
				} else if (age >= 65)
				{
					charge = chargePA4[3];	
					cntA++;		
				}
			}
			
			printf("\n우대사항을 선택하세요.\n");
			printf("1. 없음 (나이 우대는 자동처리)\n2. 장애인\n3. 국가유공자\n4. 휴가장병\n5. 임산부\n6. 다둥이\n");
			scanf("%d", &prefer);
			
			switch (prefer)
			{
			case 1:
				saleCharge = charge;
				plusCharge = plusCharge + saleCharge;
				cnt1++;
				break;
			case 2:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt2++;
				break;
			case 3:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt3++;
				break;
			case 4:
				saleCharge = (int)((float)charge * 0.61);
				plusCharge = plusCharge + saleCharge;
				cnt4++;
				break;
			case 5:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				cnt5++;
				break;
			case 6:
				saleCharge = (int)((float)charge * 0.7);
				plusCharge = plusCharge + saleCharge;
				cnt6++;
				break;
			default:
				printf("default\n");		
				break;
			}
			printf("요금: %d원\n\n", saleCharge);
		}
	}
	printf("\n\n티켓 발권을 종료합니다. 감사합니다.\n\n");
	printf("---------------롯데월드---------------\n");
	printf("어  른 x %d\n청소년 x %d\n어린이 x %d\n베이비 x %d\n\n", cntA, cntY, cntC, cntB);
	printf("입장료 총액은  %d원 입니다.", plusCharge);
	}
}
