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
	
	do {
		printf("������ �����ϼ���.\n1. �����̿��(�̿����: �Ե�����+�μӹڹ���)\n2. ��ũ�̿��(�̿����: �Ե���)\n");
		scanf("%d", &ticketNumber);
	}while(ticketNumber < 1 || ticketNumber > 2);
	
	printf("\n��� �ֹ��Ͻðڽ��ϱ�?\n");
	scanf("%d", &personNumber);
	
	if (ticketNumber == 1 && tm.tm_hour >= 10 && tm.tm_hour < 16)
	{
		int index;
		
		for (index = 1; index <= personNumber; index++)
		{
			printf("������� 8�ڸ��� �Է��ϼ���.\n"); 
			scanf("%d", &birth);
			
			int birY = birth / 10000; // �¾ �⵵�� ���� 
			int birM = (birth % 1000) / 100; // �¾ ���� ���� 
			int birD = birth % 100; // �¾ ���� ���� 
			
			int age = 0;
			
			if ((birM > tm.tm_mon+1) || (birM == tm.tm_mon+1 && birD >= tm.tm_mday)) //������ �����̰ų� �̹� ������ ��� 
			{
				age = tm.tm_year+1900 - birY;
				
				if (age >= 19 && age < 65)
				{
					charge = charge1D[0];
				} else if (age >= 13 && age <= 18)
				{
					charge = charge1D[1];
				} else if (age >= 3 && age <= 12)
				{
					charge = charge1D[2];
				} else if (age <= 2)
				{
					charge = charge1D[3];
				} else if (age >= 65)
				{
					charge = charge1D[3];
				}		
			} else if (birM < tm.tm_mon+1)//���� ������ ������ �ʾ��� ��� 
			{
				age = tm.tm_year+1900 - birY -1;
				
				if (age >= 19 && age < 65)
				{
					charge = charge1D[0];
				} else if (age >= 13 && age <= 18)
				{
					charge = charge1D[1];
				} else if (age >= 3 && age <= 12)
				{
					charge = charge1D[2];
				} else if (age <= 2)
				{
					charge = charge1D[3];
				} else if (age >= 65)
				{
					charge = charge1D[3];
				}
			}
			
			printf("\n�������� �����ϼ���.\n");
			printf("1. ���� (���� ���� �ڵ�ó��)\n2. �����\n3. ����������\n4. �ް��庴\n5. �ӻ��\n6. �ٵ���\n");
			scanf("%d", &prefer);
			
			switch (prefer)
			{
			case 1:
				saleCharge = charge;
				plusCharge = plusCharge + saleCharge;
				break;
			case 2:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 3:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 4:
				saleCharge = (int)((float)charge * 0.61);
				plusCharge = plusCharge + saleCharge;
				break;
			case 5:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 6:
				saleCharge = (int)((float)charge * 0.7);
				plusCharge = plusCharge + saleCharge;
				break;
			default:
				printf("default\n");		
				break;
			}
			printf("���: %d��\n\n", saleCharge);
		} 
	} else if (ticketNumber == 1 && tm.tm_hour >= 16 && tm.tm_hour < 21)
	{
		int index;
		
		for (index = 1; index <= personNumber; index++)
		{
			printf("������� 8�ڸ��� �Է��ϼ���.\n"); 
			scanf("%d", &birth);
			
			int birY = birth / 10000; // �¾ �⵵�� ���� 
			int birM = (birth % 1000) / 100; // �¾ ���� ���� 
			int birD = birth % 100; // �¾ ���� ���� 
			
			int age = 0;
			
			if ((birM > tm.tm_mon+1) || (birM == tm.tm_mon+1 && birD >= tm.tm_mday)) //������ �����̰ų� �̹� ������ ��� 
			{
				age = tm.tm_year+1900 - birY;
				
				if (age >= 19 && age < 65)
				{
					charge = chargeA4[0];
				} else if (age >= 13 && age <= 18)
				{
					charge = chargeA4[1];
				} else if (age >= 3 && age <= 12)
				{
					charge = chargeA4[2];
				} else if (age <= 2)
				{
					charge = chargeA4[3];
				} else if (age >= 65)
				{
					charge = chargeA4[3];
				}		
			} else if (birM < tm.tm_mon+1)//���� ������ ������ �ʾ��� ��� 
			{
				age = tm.tm_year+1900 - birY -1;
				
				if (age >= 19 && age < 65)
				{
					charge = chargeA4[0];
				} else if (age >= 13 && age <= 18)
				{
					charge = chargeA4[1];
				} else if (age >= 3 && age <= 12)
				{
					charge = chargeA4[2];
				} else if (age <= 2)
				{
					charge = chargeA4[3];
				} else if (age >= 65)
				{
					charge = chargeA4[3];
				}
			}
			
			printf("\n�������� �����ϼ���.\n");
			printf("1. ���� (���� ���� �ڵ�ó��)\n2. �����\n3. ����������\n4. �ް��庴\n5. �ӻ��\n6. �ٵ���\n");
			scanf("%d", &prefer);
			
			switch (prefer)
			{
			case 1:
				saleCharge = charge;
				plusCharge = plusCharge + saleCharge;
				break;
			case 2:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 3:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 4:
				saleCharge = (int)((float)charge * 0.61);
				plusCharge = plusCharge + saleCharge;
				break;
			case 5:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 6:
				saleCharge = (int)((float)charge * 0.7);
				plusCharge = plusCharge + saleCharge;
				break;
			default:
				printf("default\n");		
				break;
			}
			printf("���: %d��\n\n", saleCharge);
		}
	} else if (ticketNumber == 2 && tm.tm_hour >= 10 && tm.tm_hour < 16)
	{
		int index;
		
		for (index = 1; index <= personNumber; index++)
		{
			printf("������� 8�ڸ��� �Է��ϼ���.\n"); 
			scanf("%d", &birth);
			
			int birY = birth / 10000; // �¾ �⵵�� ���� 
			int birM = (birth % 1000) / 100; // �¾ ���� ���� 
			int birD = birth % 100; // �¾ ���� ���� 
			
			int age = 0;
			
			if ((birM > tm.tm_mon+1) || (birM == tm.tm_mon+1 && birD >= tm.tm_mday)) //������ �����̰ų� �̹� ������ ��� 
			{
				age = tm.tm_year+1900 - birY;
				
				if (age >= 19 && age < 65)
				{
					charge = chargeP1D[0];
				} else if (age >= 13 && age <= 18)
				{
					charge = chargeP1D[1];
				} else if (age >= 3 && age <= 12)
				{
					charge = chargeP1D[2];
				} else if (age <= 2)
				{
					charge = chargeP1D[3];
				} else if (age >= 65)
				{
					charge = chargeP1D[3];
				}		
			} else if (birM < tm.tm_mon+1)//���� ������ ������ �ʾ��� ��� 
			{
				age = tm.tm_year+1900 - birY -1;
				
				if (age >= 19 && age < 65)
				{
					charge = chargeP1D[0];
				} else if (age >= 13 && age <= 18)
				{
					charge = chargeP1D[1];
				} else if (age >= 3 && age <= 12)
				{
					charge = chargeP1D[2];
				} else if (age <= 2)
				{
					charge = chargeP1D[3];
				} else if (age >= 65)
				{
					charge = chargeP1D[3];
				}
			}
			
			printf("\n�������� �����ϼ���.\n");
			printf("1. ���� (���� ���� �ڵ�ó��)\n2. �����\n3. ����������\n4. �ް��庴\n5. �ӻ��\n6. �ٵ���\n");
			scanf("%d", &prefer);
			
			switch (prefer)
			{
			case 1:
				saleCharge = charge;
				plusCharge = plusCharge + saleCharge;
				break;
			case 2:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 3:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 4:
				saleCharge = (int)((float)charge * 0.61);
				plusCharge = plusCharge + saleCharge;
				break;
			case 5:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 6:
				saleCharge = (int)((float)charge * 0.7);
				plusCharge = plusCharge + saleCharge;
				break;
			default:
				printf("default\n");		
				break;
			}
			printf("���: %d��\n\n", saleCharge);
		}
	} else if (ticketNumber == 2 && tm.tm_hour >= 16 && tm.tm_hour < 21)
	{
		int index;
		
		for (index = 1; index <= personNumber; index++)
		{
			printf("������� 8�ڸ��� �Է��ϼ���.\n"); 
			scanf("%d", &birth);
			
			int birY = birth / 10000; // �¾ �⵵�� ���� 
			int birM = (birth % 1000) / 100; // �¾ ���� ���� 
			int birD = birth % 100; // �¾ ���� ���� 
			
			int age = 0;
			
			if ((birM > tm.tm_mon+1) || (birM == tm.tm_mon+1 && birD >= tm.tm_mday)) //������ �����̰ų� �̹� ������ ��� 
			{
				age = tm.tm_year+1900 - birY;
				
				if (age >= 19 && age < 65)
				{
					charge = chargePA4[0];
				} else if (age >= 13 && age <= 18)
				{
					charge = chargePA4[1];
				} else if (age >= 3 && age <= 12)
				{
					charge = chargePA4[2];
				} else if (age <= 2)
				{
					charge = chargePA4[3];
				} else if (age >= 65)
				{
					charge = chargePA4[3];
				}		
			} else if (birM < tm.tm_mon+1)//���� ������ ������ �ʾ��� ��� 
			{
				age = tm.tm_year+1900 - birY -1;
				
				if (age >= 19 && age < 65)
				{
					charge = chargePA4[0];
				} else if (age >= 13 && age <= 18)
				{
					charge = chargePA4[1];
				} else if (age >= 3 && age <= 12)
				{
					charge = chargePA4[2];
				} else if (age <= 2)
				{
					charge = chargePA4[3];				
				} else if (age >= 65)
				{
					charge = chargePA4[3];			
				}
			}
			
			printf("\n�������� �����ϼ���.\n");
			printf("1. ���� (���� ���� �ڵ�ó��)\n2. �����\n3. ����������\n4. �ް��庴\n5. �ӻ��\n6. �ٵ���\n");
			scanf("%d", &prefer);
			
			switch (prefer)
			{
			case 1:
				saleCharge = charge;
				plusCharge = plusCharge + saleCharge;
				break;
			case 2:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 3:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 4:
				saleCharge = (int)((float)charge * 0.61);
				plusCharge = plusCharge + saleCharge;
				break;
			case 5:
				saleCharge = (int)((float)charge * 0.5);
				plusCharge = plusCharge + saleCharge;
				break;
			case 6:
				saleCharge = (int)((float)charge * 0.7);
				plusCharge = plusCharge + saleCharge;
				break;
			default:
				printf("default\n");		
				break;
			}
			printf("���: %d��\n\n", saleCharge);
		}
	}
	printf("�߱�����\n");
	printf("��ü ���: %d��", plusCharge);
}
