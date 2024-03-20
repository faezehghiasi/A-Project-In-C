#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include"myfunc.h"
#include<Windows.h>
#pragma execution_character_set("utf-8")
struct doctor
{
	char password[20];
	char name[100];
	int melicode;
	int id;
	int wallet;
	char email[100];
	char date[20];
};
struct ndoctor {
	struct doctor doc;
	struct ndoctor* next;
};
struct prcr {

	char pr[500];
	int id_dr=0;

};
struct patient {
	char name[100];
	int id;
	char password[20];
	int wallet;
	//int visit;
	int melicode;
	char email[100];
	struct prcr pres[50];
};
struct npatient {
	struct patient pt;
	struct npatient* next;
};
enum day{sat,sun,mon,tue,wed,thu,fri};
struct off_day{
	enum day day_week;
	int date = 0;
	char condition[200] = "\0";

}off[31];
struct s {
	int condition;//برای رزرو شده یا نشده
	int idpatient;
	char saat[20];//برای ساعت نوبت گرفته شده
	//int date;
	int row;
};
struct nobat {
	struct s nob[200];
	enum day day_week;
	int date = 0;
	int firsttime;
	//int countnob = 0;
	int lasttime;
	int check;//برای روزایی که دکتر مشخص کرده
};
struct nobat2 {
	struct nobat nb[31];
	int id;
	int timevisit;
	int check2;//واسه دکترایی که برنامه حضور زمانی دادن
	int check3;//واسه قسمتسی که دکتر میخواد اجاره نده و ماه بعد بده
}doc[50];
ndoctor* head;
npatient* head2;
char trash;
//int cday;
int x = 0;
int x2 = 0;
int sexul;
char today[20];
int daycount;
void admin(void);
void push(struct ndoctor** head_ref);
int  tolist(struct ndoctor** head_ref);
int printlist(struct ndoctor* n);
void push2(struct npatient** head_ref);
void printlist2(struct npatient* n);
int  tolist2(struct npatient** head_ref);
void month_schedule(void);
day tomorow(day d);
void saveinfile(int a);
void forgot(void);
int filetoarr(void);
void dr(struct ndoctor*temp);
void to_file_nobt(void);
void file_to_arr_nobat(void);
void bimar(struct npatient*temp);
void jadval(int iddoc,int a);
int main()
{
	head = (ndoctor*)malloc(sizeof(ndoctor*));
	head = 0;
	head2 = (npatient*)malloc(sizeof(npatient*));
	head2 = 0;
	x = tolist(&head);
	x2 = tolist2(&head2);
	daycount = filetoarr();
	file_to_arr_nobat();
	//printf("%d", daycount);
	char chose[10];
	char s[20];
	char trash;
	setTextColor(LIGHT_AQUA);
	printf("\t<< WELCOME >>\n");

	//printlist(head);
	//printlist2(head2);//////
	//printf("%d", doc[0].nb[0].day_week);
	int ch;
	setTextColor(LIGHT_WHITE);
	date:printf("\nenter today's date  (****/**/**) :\n");
	gets_s(today);
	if (strlen(today) != 10) {
		setTextColor(RED);printf("enter date corectly\n");setTextColor(LIGHT_WHITE);
		goto date;
	}
	for (;;) {
		do {

			clrscr();
			setTextColor(LIGHT_AQUA);
			printf("\n\t<< MENU >>");
			setTextColor(LIGHT_WHITE);
			printf("\n1) sign in\n");
			printf("2) forget password\n");
			printf("3) Exit\n");
			printf("enter your select (1-3) :");
			gets_s(chose);
			ch = atoi(chose);
			switch (ch)
			{
			case 1: {
				char us[20];
				char us2[20];
				int ramz;
				char sh[20];
				int s;
				clrscr();
				do {
					printf("\nenter your intended position \n\n1)secretary  2)docter  3)patient\n");
					printf("\nenter your select(1-3):");
					gets_s(sh);
					s = atoi(sh);
					char trash;
					char c;
					sexul = s;
					switch (s)
					{
					case 1: {
					tag:printf("\nenter username :");
						gets_s(us2);
						printf("\nenter password : ");
						int i;
						for (i = 0; us[i-1] != 13; i++)
						{
								us[i] = getch();
								if (us[i] == 8) {
									printf("\b");
									printf(" ");
									printf("\b");
									i -= 2;
								}
								else if (us[i] != 13) {
									printf("*");
								}
						}
						us[i-1] = '\0';
						if (strcmp(us, "Admin") == 0 && strcmp(us2, "Admin") == 0)
							admin();
						else {
							setTextColor(RED); printf("\n\n<< username or password is wrong >>\n"); setTextColor(LIGHT_WHITE);
							goto tag;
						}
					}
						  break;
					case 2: {
						tag2:printf("\nenter username :");
						scanf("%d", &ramz);
						scanf("%c", &trash);
						printf("\nenter password : ");
						int i;
						for (i = 0; us[i - 1] != 13; i++)
						{
							us[i] = getch();
							if (us[i] == 8) {
								printf("\b");
								printf(" ");
								printf("\b");
								i -= 2;
							}
							else if (us[i] != 13) {
								printf("*");
							}
						}
						us[i - 1] = '\0';
						struct ndoctor* temp;
						temp = head;
						int flag = 0;
						while (temp)
						{ 
							if (temp->doc.melicode == ramz && strcmp(temp->doc.password, us) == 0) {
								flag = 1;
								break;
							}
							temp = temp->next;
						}
						if (flag) {
							dr(temp);
						}
						else {
							setTextColor(RED); printf("\npassword or username is wrong...\n"); setTextColor(LIGHT_WHITE);
							printf("\n1_forget password (enter for next) : ");
							char s[9];
							//scanf("%c", &trash);
							gets_s(s);
							if (atoi(s) == 1) {
								forgot();
							}
							else
							goto tag2;
						}
					
					}
						  break;
					case 3: {
						tag3:printf("\nenter username :");
						scanf("%d", &ramz);
						scanf("%c", &trash);////////////////////////////
						printf("\nenter password : ");
						int i;
						for (i = 0; us[i - 1] != 13; i++)
						{
							us[i] = getch();
							if (us[i] == 8) {
								printf("\b");
								printf(" ");
								printf("\b");
								i-=2;
							}
							else if (us[i] != 13) {
								printf("*");
							}
						}
						us[i - 1] = '\0';
						struct npatient* temp;
						temp = head2;
						int flag = 0;
						while (temp)
						{
							if (temp->pt.melicode == ramz && strcmp(temp->pt.password, us) == 0) {
								flag = 1;
								break;
							}
							temp = temp->next;
						}
						if (flag) {
							bimar(temp);
						}
						else {
							setTextColor(RED); printf("\npassword or username is wrong...\n"); setTextColor(LIGHT_WHITE);
							printf("\n1_forget password (enter for next) : ");
							char s[9];
							//scanf("%c", &trash);
							gets_s(s);
							if (atoi(s) == 1) {
								forgot();
							}
							else
							goto tag3;
						}
					}
						  break;
					default:setTextColor(RED); printf("\nWRONG ORDER !!!\n"); setTextColor(LIGHT_WHITE);
					}

				} while (s < 1 || s > 3); }
				  break;
			case 2:forgot();
				printlist2(head2);
				break;
			case 3:exit(0);
			default:setTextColor(RED); printf("\nWRONG ORDER !!!\n"); setTextColor(LIGHT_WHITE);
			}
		} while (ch < 1 || ch > 3);
		//scanf("%c", &trash);
		setTextColor(LIGHT_YELLOW); printf("\n_._._._._._._._._._._._._._._._._._._._._._._._._._._._.\n"); setTextColor(RED);
	}
}
//******************************************************************
void admin(void) {//اکانت ادمین
	clrscr();
	setTextColor(LIGHT_AQUA);
	printf("\t<< WELCOME >>\n\n");
	setTextColor(LIGHT_WHITE);
	int choce;
	char ch[20];
	for (;;)
	{
		do
		{
			printf("\n1-Add Doctor\n");
			printf("\n2-Add patient\n");
			printf("\n3-Monthly Schedule\n");
			printf("\n4-Visits Schedule\n");
			printf("\n5-Exit\n");
			printf("\nenter you'r selection :");
			gets_s(ch);
			choce = atoi(ch);
			switch (choce) 
			{
			case 1:push(&head); break;
			case 2:push2(&head2); break;
			case 3:month_schedule(); break;
			case 4: {
				clrscr();
				char f1[20];
				ni:printf("\n1-ALL\n\n2-Choose Doctor\n");
				printf("\nenter you'r slection : ");
				gets_s(f1);
				int f2 = atoi(f1);
				if (f2 == 1) {
					clrscr();
					int xc;
					for (int i = 0; i <x; i++) {
						xc = 0;
						setTextColor(LIGHT_PURPLE); printf("\ndoctor's id : %d\n\n", i+1); setTextColor(LIGHT_WHITE);
						for (int j = 0; j < 31; j++) {
							for (int k = 0; k < 200; k++) {
								if (doc[i].nb[j].nob[k].idpatient>0)
								{
									printf("Appontment : date : %d   time : %s", doc[i].nb[j].date, doc[i].nb[j].nob[k].saat);
									printf("\n");
									xc++;
								}
							}
						}
						if (xc == 0) {
							setTextColor(LIGHT_RED); printf("\ndoctor does'nt have any appointment"); setTextColor(LIGHT_WHITE);
						}
					
					}
					printf("\npress any key to continu...");
					getch();
				}
				else if (f2 == 2) {
					clrscr();
					printlist(head);
					printf("\nenter doctor's id to see the information (enter to finish) : ");
					char chos[20];
					gets_s(chos);
					int x = atoi(chos);
					if (x == 0) break;
					jadval(x, 2);
				}
				else {
					setTextColor(RED); printf("\nWRONG ORDER !!!\n\n"); setTextColor(LIGHT_WHITE);
					goto ni;
				}
			
			}break;
			case 5:return;
			default:setTextColor(RED); printf("\nWRONG ORDER !!!\n\n"); setTextColor(LIGHT_WHITE);
			}
		} while (choce < 1 || choce>5);
		//setTextColor(LIGHT_YELLOW); printf("\n_._._._._._._._._._._._._._._._._._._._._._._._._._._._.\n"); setTextColor(LIGHT_WHITE);
	}
}
//****************************************************************
void push(struct ndoctor** head_ref)//تابع برای اضافه کردن دکتر ها
{   
	FILE* fp;
	fp = fopen("doctor.bin", "ab");
	if (!fp) {
		printf("erorr can not open the file !!");
		exit(0);
	}
	char trash;
	clrscr();
	struct ndoctor* new_node;
	new_node = (ndoctor*)malloc(sizeof(ndoctor));
	new_node->next = NULL;
	ndoctor* last = (struct ndoctor*)malloc(sizeof(struct ndoctor));
	last = *head_ref;
	struct ndoctor* temp = NULL;
	printf("\t << enter informatoin >>\n");
	printf("\nenter the name :");
	gets_s(new_node->doc.name);
	temp = *head_ref;
	int flag = 1;
	if (x) {
		while (temp) {

			if (strcmp(temp->doc.name,new_node->doc.name)==0)
				flag = 0;
			temp = temp->next;
		}
	}
	if (flag) {
		printf("\nenter National Code :");
		scanf("%d", &new_node->doc.melicode);
		scanf("%c", &trash);
		printf("\nenter Email :");
		gets_s(new_node->doc.email);
		printf("\nenter password :");
		gets_s(new_node->doc.password);
		printf("\nenter today's date  (****/**/**) :");
		date:gets_s(new_node->doc.date);
		if (strlen(new_node->doc.date) != 10) {
			setTextColor(RED);printf("enter date corectly\n");setTextColor(LIGHT_WHITE);
			goto date;
		}
		new_node->doc.wallet = 10;
		new_node->doc.id = x + 1;
		if (*head_ref == NULL) {
			*head_ref = new_node;
		}
		else {
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = new_node;
		}
		struct doctor dr = new_node->doc;
		fwrite(&dr, sizeof(struct doctor),1,fp);
	}
	else {
		setTextColor(RED);
		printf("\nthere is a doctor with this name in the list!!\n");
		setTextColor(LIGHT_WHITE);
	}
	x++;
	fclose(fp);
	setTextColor(LIGHT_YELLOW); printf("\n_._._._._._._._._._._._._._._._._._._._._._._._._._._._.\n\n"); setTextColor(LIGHT_WHITE);
	return;
}
//**************************************************************************
int  tolist(struct ndoctor **head_ref)//تابع لود کردن لینک لیست دکتر از فایل
{
	int count = 0;
	FILE *fp = fopen("doctor.bin", "ab+");
	rewind(fp);
	if (!fp) {
		printf("erorr can not open the file !!");
		exit(0);
	}
	struct doctor temp;
	struct ndoctor* new_node;
	ndoctor* last = (struct ndoctor*)malloc(sizeof(struct ndoctor));
	last = *head_ref;
	while (1) {
		last = *head_ref;
		new_node = (ndoctor*)malloc(sizeof(ndoctor));
		new_node->next = NULL;
		int num;
		num=fread(&temp, sizeof(struct doctor), 1, fp);
		if (ferror(fp)) {
			printf("erorr");
			exit(0);
		}
		if (num == 0)break;
		new_node->doc = temp;
		if (*head_ref == NULL) {
			*head_ref = new_node;
		}
		else {
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = new_node;
		}
		count++;
	}
	fclose(fp);
	//printlist(*head_ref);
	return count;
}
//****************************************************************
void push2(struct npatient**head_ref) //تابع اضافه کردن بیمار ها به لیست
{
	FILE* fp2;
	fp2 = fopen("patient.bin", "ab");
	if (!fp2) {
		printf("erorr can not open the file !!");
		exit(0);
	}
	char trash;
	clrscr();
	struct npatient* new_node;
	new_node = (npatient*)malloc(sizeof(npatient));
	new_node->next = NULL;
	npatient* last = (struct npatient*)malloc(sizeof(struct npatient));
	last = *head_ref;
	printf("\t << enter informatoin >>\n");
	printf("\nenter the name :");
	gets_s(new_node->pt.name);
	printf("\nenter National Code :");
	scanf("%d", &new_node->pt.melicode);
	scanf("%c", &trash);
	printf("\nenter Email :");
	gets_s(new_node->pt.email);
	printf("\nenter password :");
	gets_s(new_node->pt.password);
	new_node->pt.wallet = 100000000;
	new_node->pt.id = x2+1;
	if (*head_ref == NULL) {
		*head_ref = new_node;
	}
	else {
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = new_node;
	}
	struct patient pat;
	pat = new_node->pt;
	fwrite(&pat, sizeof(struct patient), 1, fp2);
	setTextColor(LIGHT_YELLOW); printf("\n_._._._._._._._._._._._._._._._._._._._._._._._._._._._.\n\n"); setTextColor(LIGHT_WHITE);
	x2++;
	fclose(fp2);
	return;
}
//**************************************************************************
int printlist(struct ndoctor* n) {
	int t = 0;
	int j = 0;
	while (n != NULL)
	{
		t++;
		printf("%d-name : %s\tid : %d",t, n->doc.name, n->doc.id);
		printf("\n");
		j++;
		n = n->next;
	}
	return j;
}
//**************************************************************************
int tolist2(struct npatient** head_ref) {
	int x;
	int count = 0;
	FILE* fp = fopen("patient.bin", "ab+");
	rewind(fp);
	if (!fp) {
		printf("erorr can not open the file !!");
		exit(0);
	}
	struct patient temp;
	struct npatient* new_node;
	npatient* last = (struct npatient*)malloc(sizeof(struct npatient));
	last = *head_ref;
	while (1) {
		last = *head_ref;
		new_node = (npatient*)malloc(sizeof(npatient));
		new_node->next = NULL;
		x = fread(&temp, sizeof(struct patient), 1, fp);
		if (ferror(fp)) {
			printf("erorr");
			exit(0);
		}
		if (x==0)break;
		new_node->pt= temp;
		if (*head_ref == NULL) {
			*head_ref = new_node;
		}
		else {
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = new_node;
		}
		count++;
	}
	fclose(fp);
	//printlist(*head_ref);
	return count;
}
//****************************************************************
void printlist2(struct npatient* n) {

	while (n != NULL)
	{
		printf("%s %d  %d\n", n->pt.name, n->pt.id ,n->pt.wallet);
		//puts(n->pt.pres[1].pr);
		n = n->next;
	}
}
//*****************************************************************
void month_schedule(void)//تابع تعیین برنامه زمانی توسط  منشی
{ 
	for (int i = 0; i < 31; i++) {
		off[i].date = 0;
		off[i].day_week = (day)-1;
		strcpy(off[i].condition, "\0");
	}
	char trash;
	clrscr();
	FILE* fp;
	fp = fopen("time.bin", "wb");
	if (!fp)
		printf("erorr");
	printf("\nenter the number of the month :");
	scanf("%d", &daycount);
	scanf("%c", &trash);
	do {
		printf("\n enter the first day of month :");
		printf(" 0_SAT\t1_SON\t2_MON\t3_TUE\t4_WED\t5_THU\t6_FRI : ");
		scanf("%d", &off[0].day_week);
		off[0].date=1;
		scanf("%c", &trash);

	} while (off[0].day_week < 0 || off->day_week > 6);
	char c[10];
	int sh;
	for (;;)
	{
		printf("\nenter offdays and reason (enter to finish):\n");
		printf("date : ");
		gets_s(c);
		sh = atoi(c);
		if (sh == 0)
			break;
		printf("reason : ");
		off[sh - 1].date = sh;
		gets_s(off[sh - 1].condition);
		printf("\n");
	}
	if (strcmp(off[0].condition, "\0") == 0) {
		if (off[0].day_week == fri)
			strcpy(off[0].condition, "closed");
		else
			strcpy(off[0].condition, "open");
	}
	for (int i = 1; i < daycount; i++) {

		if (off[i].date == 0)
		{    
			off[i].date = i + 1;
			off[i].day_week = tomorow(off[i - 1].day_week);
			if (off[i].day_week == fri) {
				strcpy(off[i].condition, "closed");
			}
			else {
				strcpy(off[i].condition, "open");
			}
		
		}
			else off[i].day_week = tomorow(off[i - 1].day_week);
	}
	for (int i = 0; i < daycount; i++) {
		fwrite(&off[i], sizeof(struct off_day), 1, fp);
		if (ferror(fp))
			printf("erorr");
	}
	struct off_day of;
	//rewind(fp);
	/*for (int i = 0; i < cday; i++) {
		fread(&of, sizeof(struct off_day), 1, fp);
		printf("%d %s %d", of.day_week, of.condition, of.date);
		printf("\n");
	}*/
	fclose(fp);

	filetoarr();



	char chose[6];
	tag:printf("Do you want to see the schedule (YES/NO) :");
	gets_s(chose);
	if (strcmp(chose, "YES") == 0 || strcmp(chose, "yes") == 0)
	{
		clrscr();
		gotoxy(9, 1);
		printf("_________________________________________________________________________________________________________");
		gotoxy(9, 4);
		printf("_________________________________________________________________________________________________________");
		gotoxy(9, 7);
		printf("_________________________________________________________________________________________________________");
		gotoxy(9, 10);
		printf("_________________________________________________________________________________________________________");
		gotoxy(9, 13);
		printf("_________________________________________________________________________________________________________");
		gotoxy(9, 16);
		printf("_________________________________________________________________________________________________________");
		gotoxy(9, 19);
		printf("_________________________________________________________________________________________________________");
		gotoxy(9, 22);
		printf("_________________________________________________________________________________________________________");

		for (int i = 9; i <= 114; i += 15) {
			for (int j = 2; j <= 22; j++) {
				gotoxy(i, j);
				printf("|");
			}
		}
		gotoxy(15, 2);
		printf("SAT");
		gotoxy(30, 2);
		printf("SON");
		gotoxy(45, 2);
		printf("MON");
		gotoxy(60, 2);
		printf("TUE");
		gotoxy(75, 2);
		printf("WED");
		gotoxy(90, 2);
		printf("THU");
		gotoxy(105, 2);
		printf("FRI");
		gotoxy(13, 23);
		int i = 0, j = 2;
		gotoxy(13, 22);
		switch (off[0].day_week) {
		case 0: i = 15;
			break;
		case 1:; i = 30;
			break;
		case 2:i = 45;
			break;
		case 3:i = 60;
			break;
		case 4:i = 75;
			break;
		case 5:i = 90;
			break;
		case 6:i = 105;
			break;
		}
		i -= 5;
		j += 3;
		int k = 0;
		for (j; j <= 21; j += 3) {
			for (i; i <= 113; i += 15) {
				if (off[k].date == 0)break;
				gotoxy(i, j);
				if (strcmp(off[k].condition, "open") != 0) {
					setTextColor(RED);
					printf("%d", off[k].date);
					setTextColor(LIGHT_WHITE);
				}
				else {
					printf("%d", off[k].date);
				}
				gotoxy(i, j + 1);
				if (strcmp(off[k].condition, "open") != 0) {
					setTextColor(LIGHT_AQUA);
					printf("%s", off[k].condition);
					setTextColor(LIGHT_WHITE);
				}
				gotoxy(i, j);
				k++;
			}
			if (i >= 113)i = 10;
			if (off[k].date == 0)break;
		}
		gotoxy(1, 23);
	}
	else if (strcmp(chose, "no") == 0 || strcmp(chose, "NO") == 0)return;
	else goto tag;
	setTextColor(LIGHT_YELLOW); printf("\n_._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._.\n\n"); setTextColor(LIGHT_WHITE);
	return;
}
//******************************************************************
day tomorow(day d) {//تابع پیدا کردن فردای ان روز
	switch (d)
	{
	case sat:return sun; break;
	case sun:return mon; break;
	case mon:return tue; break;
	case tue:return wed; break;
	case wed:return thu; break;
	case thu:return fri; break;
	case fri:return sat; break;
	}
}
//********************************************************************
void forgot(void)//تابع فراموش کردن رمزعبور
{
	clrscr();
	char sh[20];
	char trash;
	int s;
	tag:printf("\nenter your intended position \n\n 1)docter  2)patient\n");
	printf("\nenter your select(1-3):");
	gets_s(sh);
	s = atoi(sh);
	char email[100];
	int melicod;
	if (s != 1 && s != 2)goto tag;
	tag2:printf("\nenter you'r nationalcode : ");
	scanf("%d", &melicod);
	scanf("%c", &trash);
	printf("\nenter you'r Email : ");
	gets_s(email);
	if (s == 1) {
		struct ndoctor*temp =head;
		char trash[30];
		int flag = 0;
		while (temp)
		{
			if ((temp)->doc.melicode == melicod && strcmp((temp)->doc.email, email) == 0) {
				flag = 1; break;
			}
			(temp) = (temp)->next;
		}
		if (flag) {
			struct ndoctor** temp2 = &temp;
			printf("\nenter you'r new password : ");
			scanf("%s", &(*temp2)->doc.password);
			printf("\nenter you'r new password again : ");
			scanf("%s", &trash);
			setTextColor(LIGHT_YELLOW); printf("\n you'r password is successfully changed \n\n"); setTextColor(LIGHT_WHITE);
			saveinfile(2);
			printf("press any key to continu...");
			getch();
			return;
		}
		setTextColor(RED); printf("\n\nyou'r email and nationalcode not matched !!\n"); setTextColor(LIGHT_WHITE);
	}
	else {
		struct npatient* temp = head2;
		char trash[30];
		int flag = 0;
		while (temp)
		{
			if ((temp)->pt.melicode == melicod && strcmp((temp)->pt.email, email) == 0) {
				flag = 1; break;
			}
			(temp )=( temp)->next;
		}
		if (flag) {
			struct npatient** temp2 = &temp;
			printf("\nenter you'r new password : ");
			scanf("%s", &(*temp2)->pt.password);
			printf("\nenter you'r new password again : ");
			scanf("%s", &trash);
			printf("\n you'r password is successfully changed \n\n");
			saveinfile(2);
			printf("press any key to continu...");
			getch();
			return;
		}
		setTextColor(RED); printf("\n\nyou'r email and nationalcode not matched !!\n"); setTextColor(LIGHT_WHITE);
		setTextColor(LIGHT_YELLOW); printf("\n_._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._.\n\n"); setTextColor(LIGHT_WHITE);
		goto tag2;
	}
}
//********************************************************************
void saveinfile(int a)//این تابع از لینک لیست به فایل منتقل میکنه
{
	if (a == 1)
	{
		FILE* fp;
		fp = fopen("doctor.bin", "wb");
		if (!fp) {
			printf("can not open the file !!");
		}
		struct ndoctor* temp = head;
		struct doctor temp2;
		while (temp)
		{
			temp2 = temp->doc;
			fwrite(&temp2, sizeof(struct doctor), 1, fp);

			temp = temp->next;
		}
		fclose(fp);
	}
	else
	{
		FILE* fp;
		fp = fopen("patient.bin", "wb");
		if (!fp) {
			printf("can not open the file !!");
		}
		struct npatient* temp = head2;
		struct patient temp2;
		while (temp)
		{
			temp2 = temp->pt;
			fwrite(&temp2, sizeof(struct patient), 1, fp);
			if (ferror(fp)) {
				printf("erorr");
			}
			temp = temp->next;
		}
		fclose(fp);
	}
}
//**********************************************************************
void dr(struct ndoctor* temp)
{
	clrscr();
	doc[temp->doc.id - 1].id = temp->doc.id;//روز ها را با تقویم منشی هماهنگ میکنه
	for (int i = 0; i < daycount; i++) {

		doc[temp->doc.id - 1].nb[i].date = i + 1;
		doc[temp->doc.id - 1].nb[i].day_week = off[i].day_week;

	}
	setTextColor(LIGHT_AQUA);
 	printf("\t<< WELCOME >>\n\n");
	setTextColor(LIGHT_WHITE);
	if (strlen(today) == 10) {
		char* token = strtok(today, "/");
		int sal1 = atoi(token);
		token = strtok(NULL, "/");
		int mah1 = atoi(token);
		char docdate[30];
		strcpy(docdate, temp->doc.date);
		char* token2 = strtok(docdate, "/");
		int sal2 = atoi(token2);
		token2 = strtok(NULL, "/");
		int mah2 = atoi(token2);;
		int a = (sal1 - sal2) * 12 + mah1;
		if (a - mah2>= 3) {
			sik:setTextColor(RED); printf("you have deleted from clinic beacuse of notpaying the payment\n\n"); setTextColor(LIGHT_WHITE);
			struct ndoctor** head_ref = &head;
			for (int i = temp->doc.id ; i < 31; i++) {
				doc[temp->doc.id - 1].nb[i].check = doc[temp->doc.id].nb[i].check;
				doc[temp->doc.id - 1].nb[i].date = doc[temp->doc.id].nb[i].date;
				doc[temp->doc.id - 1].nb[i].day_week = doc[temp->doc.id].nb[i].day_week;
				doc[temp->doc.id - 1].nb[i].firsttime = doc[temp->doc.id].nb[i].firsttime;
				doc[temp->doc.id - 1].nb[i].lasttime = doc[temp->doc.id].nb[i].lasttime;
				for (int j = 0; j < 200; j++) {
					doc[temp->doc.id - 1].nb[i].nob[j].condition = doc[temp->doc.id].nb[i].nob[j].condition;
					doc[temp->doc.id - 1].nb[i].nob[j].idpatient = doc[temp->doc.id].nb[i].nob[j].idpatient;
					doc[temp->doc.id - 1].nb[i].nob[j].row = doc[temp->doc.id].nb[i].nob[j].row;
				}
			}
			doc[temp->doc.id - 1].check2 = doc[temp->doc.id].check2;
			doc[temp->doc.id - 1].check3 = doc[temp->doc.id].check3;
			doc[temp->doc.id - 1].timevisit = doc[temp->doc.id].check3;
			struct ndoctor* tm = (*head_ref)->next;
			if ((*head_ref)->doc.id == temp->doc.id)
			{
				*head_ref = (*head_ref)->next;
				while (tm) {
					tm->doc.id--;
					tm = tm->next;
				}
			}
			else {
				struct ndoctor* temp2;
				struct ndoctor* prev;
				prev = 0;
				temp2 = (ndoctor*)malloc(sizeof(ndoctor));
				temp2 = head;
				while (temp2) {
					if (temp2->doc.id == temp->doc.id)
						break;
					prev = temp2;
					temp2 = temp2->next;
				}
				struct ndoctor* tm = temp2->next;
				while (tm) {
					tm->doc.id--;
					tm = tm->next;
				}
				prev->next = temp2->next;
				free(temp2);	
			}
			saveinfile(1);
			to_file_nobt();
			file_to_arr_nobat();
			exit(0);
		}
		if (a - mah2==2) {
			if (doc[temp->doc.id - 1].check3 == 0) {
				goto sik;
			}
		}
	}
	int choce;
	char ch[20];
	for (;;)
	{
		char trash;
		do
		{
			printf("\n1-Determining the Shifts\n");
			printf("\n2-Reserved Visits\n");
			printf("\n3-Patient Prescription\n");
			printf("\n4-Rent Payment\n");
			printf("\n5-Exit\n");
			printf("\nenter you'r select :");
			//scanf("%c", &trash);
			gets_s(ch);
			choce = atoi(ch);
			switch (choce)
			{
			case 1: {
				
				
				
				clrscr();
				char choce[8];
				int ch;
				printf("\nenter the duration of you'r appointment : ");
				scanf("%d%c", &doc[temp->doc.id - 1].timevisit, &trash);
			tag:printf("\n1-Set for day \n");
				printf("\n2-Recurring days in the month\n");
				printf("\nenter you'r selection : ");
				gets_s(choce);
				if (atoi(choce) == 1) {
					clrscr();
					char c[10];
					int sh;
					for (;;)
					{
					tag3:printf("\nenter you'r intended date (enter to finish):\n");
						printf("date : ");
						gets_s(c);
						sh = atoi(c);
						if (sh == 0)
							break;
						if (strcmp(off[sh - 1].condition, "open") != 0) {
							setTextColor(RED); printf("clinic in this day is close \n"); setTextColor(LIGHT_WHITE);
							goto tag3;
						}
					tag2:printf("\nenter you'r login time : ");
						scanf("%d", &doc[temp->doc.id - 1].nb[sh - 1].firsttime);
						scanf("%c", &trash);
						if ((doc[temp->doc.id - 1].nb[sh - 1].day_week == thu))
						{
							if (doc[temp->doc.id - 1].nb[sh - 1].firsttime > 13 || doc[temp->doc.id - 1].nb[sh - 1].firsttime < 8) {
								setTextColor(RED); printf("clinic in this time is close\n "); setTextColor(LIGHT_WHITE);
								goto tag2;
							}
						}
						else {
							if (doc[temp->doc.id - 1].nb[sh - 1].firsttime > 21 || doc[temp->doc.id - 1].nb[sh - 1].firsttime < 8) {
								setTextColor(RED); printf("clinic in this time is close \n"); setTextColor(LIGHT_WHITE);
								goto tag2;
							}
						}
					tag4:printf("enter you'r logout time : ");
						scanf("%d", &doc[temp->doc.id - 1].nb[sh - 1].lasttime);
						scanf("%c", &trash);
						if ((doc[temp->doc.id - 1].nb[sh - 1].day_week == thu))
						{
							if (doc[temp->doc.id - 1].nb[sh - 1].lasttime > 13 || doc[temp->doc.id - 1].nb[sh - 1].lasttime < 8) {
								setTextColor(RED); printf("clinic in this time is close \n"); setTextColor(LIGHT_WHITE);
								goto tag4;
							}
						}
						else {
							if (doc[temp->doc.id - 1].nb[sh - 1].lasttime > 21 || doc[temp->doc.id - 1].nb[sh - 1].lasttime < 8) {
								setTextColor(RED); printf("clinic in this is time close \n"); setTextColor(LIGHT_WHITE);
								goto tag4;
							}
						}
						printf("\n");
						doc[temp->doc.id - 1].nb[sh - 1].check = 1;
					}
			         
				}
				else if (atoi(choce) == 2) {
					clrscr();
					char c[10];
					int sh;
					int first;
					int last;
					for (;;)
					{
					bag:printf("\nenter the days\n1-SAT\t2_SON\t3-MON\t4-TUE\t5-WED\t6-THU\n(enter to finish)\n");
						printf("enter you'r select :");
						gets_s(c);
						sh = atoi(c);
						if (sh == 0)
							break;
						if (sh > 6 || sh < 1) {
							setTextColor(RED); printf("\nWRONG ORDER !!!\n"); setTextColor(LIGHT_WHITE);
							goto bag;
						}
					sag:printf("\nenter you'r login time : ");
						scanf("%d", &first);
						scanf("%c", &trash);
						if ((sh == 6))
						{
							if (first > 13 || first < 8) {
								setTextColor(RED); printf("clinic in this time is close\n "); setTextColor(LIGHT_WHITE);
								goto sag;
							}
						}
						else {
							if (first > 21 || first < 8) {
								setTextColor(RED); printf("clinic in this time is close \n"); setTextColor(LIGHT_WHITE);
								goto sag;
							}
						}
					man:printf("enter you'r logout time : ");
						scanf("%d", &last);
						scanf("%c", &trash);
						if (sh == 6)
						{
							if (last > 13 || last < 8) {
								setTextColor(RED); printf("clinic in this time is close \n"); setTextColor(LIGHT_WHITE);
								goto man;
							}
						}
						else {
							if (last > 21 || last < 8) {
								setTextColor(RED); printf("clinic in this is time close \n"); setTextColor(LIGHT_WHITE);
								goto man;
							}
						}
						printf("\n");
						switch (sh)
						{
						case 1: {

							for (int i = 0; i < daycount; i++) {
								if (strcmp(off[i].condition, "open") == 0) {
									if (doc[temp->doc.id - 1].nb[i].day_week == sat)
									{
										doc[temp->doc.id - 1].nb[i].firsttime = first;
										doc[temp->doc.id - 1].nb[i].lasttime = last;
										doc[temp->doc.id - 1].nb[i].check = 1;
									}
								}
							}
						}
							  break;
						case 2: {

							for (int i = 0; i < daycount; i++) {
								if (strcmp(off[i].condition, "open") == 0) {
									if (doc[temp->doc.id - 1].nb[i].day_week == sun)
									{
										doc[temp->doc.id - 1].nb[i].firsttime = first;
										doc[temp->doc.id - 1].nb[i].lasttime = last;
										doc[temp->doc.id - 1].nb[i].check = 1;
									}
								}
							}
						}
							  break;
						case 3: {

							for (int i = 0; i < daycount; i++) {
								if (strcmp(off[i].condition, "open") == 0) {
									if (doc[temp->doc.id - 1].nb[i].day_week == mon)
									{
										doc[temp->doc.id - 1].nb[i].firsttime = first;
										doc[temp->doc.id - 1].nb[i].lasttime = last;
										doc[temp->doc.id - 1].nb[i].check = 1;
									}
								}
							}
						}
							  break;
						case 4: {

							for (int i = 0; i < daycount; i++) {
								if (strcmp(off[i].condition, "open") == 0) {
									if (doc[temp->doc.id - 1].nb[i].day_week == tue)
									{
										doc[temp->doc.id - 1].nb[i].firsttime = first;
										doc[temp->doc.id - 1].nb[i].lasttime = last;
										doc[temp->doc.id - 1].nb[i].check = 1;
									}
								}
							}
						}
							  break;
						case 5: {

							for (int i = 0; i < daycount; i++) {
								if (strcmp(off[i].condition, "open") == 0) {
									if (doc[temp->doc.id - 1].nb[i].day_week == wed)
									{
										doc[temp->doc.id - 1].nb[i].firsttime = first;
										doc[temp->doc.id - 1].nb[i].lasttime = last;
										doc[temp->doc.id - 1].nb[i].check = 1;
									}
								}
							}
						}
							  break;
						case 6: {
							for (int i = 0; i < daycount; i++) {
								if (strcmp(off[i].condition, "open") == 0) {
									if (doc[temp->doc.id - 1].nb[i].day_week == thu)
									{
										doc[temp->doc.id - 1].nb[i].firsttime = first;
										doc[temp->doc.id - 1].nb[i].lasttime = last;
										doc[temp->doc.id - 1].nb[i].check = 1;
									}
								}
							}
						}
							  break;
						}
						printf("\n");
					}
				}
				else {
					setTextColor(RED); printf("\nWRONG ORDER !!!\n"); setTextColor(LIGHT_WHITE);
					goto tag;
				}
				doc[temp->doc.id - 1].check2 = 1;
				to_file_nobt();
				file_to_arr_nobat();
			}
			break;
			case 2: {
				clrscr();
				jadval(temp->doc.id, 1);
				setTextColor(LIGHT_BLUE); printf("\n\n\nenter patient's id to see the information (enter to finish) : "); setTextColor(LIGHT_WHITE);
				char idp[30];
				gets_s(idp);
				int pid = atoi(idp);
				if (idp == 0)
					break;
				struct npatient* temp0 = head2;
				while (temp0) {
					if (temp0->pt.id == pid)
						break;
					temp0 = temp0->next;
				}
				printf("\npatient's name : %s   patient's id : %d ", temp0->pt.name, temp0->pt.id);
				if (temp0->pt.pres[temp0->pt.id - 1].id_dr > 0) {
					printf("\npatient's prescription : %s", temp0->pt.pres[temp0->pt.id - 1].pr);
				}
				else {
					setTextColor(LIGHT_RED); printf("\n\npatient dose'nt have prescription"); setTextColor(LIGHT_WHITE);
				}
			
			}break;
			case 3: {
				clrscr();
				struct npatient* tem;
				for (int i = 0; i < 31; i++) {

					for (int j = 0; j < 200; j++) {
						if (doc[temp->doc.id - 1].nb[i].nob[j].idpatient > 0) {
							tem = head2;
							while (temp) {

								if (tem->pt.id == doc[temp->doc.id - 1].nb[i].nob[j].idpatient)
								{
									printf("name : %s\tid : %d", tem->pt.name, tem->pt.id);
									printf("\n");
									break;
								}
								temp = temp->next;
							}

						}
					}
				}
				int id;
				printf("\nenter you'r intended id : ");
				scanf("%d%c", &id, &trash);
				tem = head2;
				while (tem) {
					if (tem->pt.id == id)
						break;
					tem = tem->next;
				}
				printf("\n\nenter you'r intended prescription : ");
				gets_s(tem->pt.pres[temp->doc.id - 1].pr);
				tem->pt.pres[temp->doc.id - 1].id_dr = temp->doc.id;
				tem->pt.wallet -= 50;
				temp->doc.wallet += 50;
				saveinfile(1);
				saveinfile(2);

			
			
			}

				  break;
			case 4: {
				clrscr();
				char s[5];
				file_to_arr_nobat();
				fuc:printf("1-Extension\n");
				printf("\n2-Payment\n");
				printf("\nenter you'r selection : ");
				gets_s(s);
				if (atoi(s) == 1) {
					if (doc[temp->doc.id - 1].check3 == 1) {
						setTextColor(RED); printf("you can not use this option in this time "); setTextColor(LIGHT_WHITE);
					}
					else {
						setTextColor(LIGHT_BLUE);printf("you'r request registered successfuly");setTextColor(LIGHT_WHITE);
						doc[temp->doc.id - 1].check3 = 1;
						to_file_nobt();
					}
				    
				}
				else if (atoi(s) == 2) {
					
					if (doc[temp->doc.id - 1].check3 == 1)
					{
						if (temp->doc.wallet >= 600) {
							temp->doc.wallet -= 600;
							strcpy(temp->doc.date, today);
							doc[temp->doc.id - 1].check3 ==0;
							setTextColor(LIGHT_BLUE);printf("you'r request registered successfuly");setTextColor(LIGHT_WHITE); 
						}
						else {
							setTextColor(RED); printf("you don't have enough money"); setTextColor(LIGHT_WHITE);
						}
					 
					}
					else {

						if (temp->doc.wallet >= 300) {
							temp->doc.wallet -= 300;
							strcpy(temp->doc.date, today);
							setTextColor(LIGHT_BLUE); printf("you'r request registered successfuly"); setTextColor(LIGHT_WHITE);
						}
						else {
							setTextColor(RED); printf("you don't have enough money"); setTextColor(LIGHT_WHITE);
						}
					}
					saveinfile(1);
					to_file_nobt();
					file_to_arr_nobat();
				}
				else
				{
					setTextColor(RED); printf("\nWRONG ORDER !!!\n"); setTextColor(LIGHT_WHITE);
					goto fuc;
				}
			}
				  break;
			case 5:return;
			default:setTextColor(RED); printf("\nWRONG ORDER !!!\n\n"); setTextColor(LIGHT_WHITE);
			}
		} while (choce < 1 || choce>5);
		setTextColor(LIGHT_YELLOW); printf("\n_._._._._._._._._._._._._._._._._._._._._._._._._._._._.\n"); setTextColor(LIGHT_WHITE);
    }
}
///*********************************************************************
int filetoarr(void) {//تابع از فایل تایم به ارایه
	FILE* fp;
	fp = fopen("time.bin", "ab+");
	if (!fp) {
		printf("can not open the file !!");
		exit(0);
	}
	int num = 0;
	int i = 0;
	while (1)
	{
		
		 num = fread(&off[i], sizeof(struct off_day), 1, fp);
		 if (feof(fp))break;
		i++;
	}
	return i;
}
//**********************************************************************
void to_file_nobt(void)// این تابع از ارایه نوبت میریزه تو فایل نوبت
{
	FILE* fp;
	fp = fopen("nobat.bin", "wb");
	if (!fp) {
		printf("can not open the file !!");
	}
	for (int i = 0; i < 50; i++) {
		fwrite(&doc[i], sizeof(struct nobat2), 1, fp);
	}
	if (ferror(fp))
		printf("erorr");
	fclose(fp);
}
//**********************************************************************
void file_to_arr_nobat(void)/// این تابع از فایل نوبت خونده وبه ارایه اضافه میکنه
{
	FILE* fp;
	fp = fopen("nobat.bin", "ab+");
	if (!fp) {
		printf("can not open the file !!");
	}
	for (int i = 0; i < 50; i++)
	{
		fread(&doc[i], sizeof(struct nobat2), 1, fp);
	}
	fclose(fp);
}
//**********************************************************************
void bimar(struct npatient*temp) {//اکانت بیمار
	clrscr();
	setTextColor(LIGHT_AQUA);
	printf("\t<< WELCOME >>\n\n");
	setTextColor(LIGHT_WHITE);
	int choce;
	char ch[20];
	for (;;)
	{
		do
		{
			printf("\n1-Book an Appointment\n");
			printf("\n2-Cancel an Appointment\n");
			printf("\n3-All Appointment\n");
			printf("\n4-Prescription\n");
			printf("\n5-Exit\n");
			printf("\nenter you'r selection :");
			gets_s(ch);
			choce = atoi(ch);
			switch (choce)
			{
			case 1: {
				clrscr();
				int id;
				int j = printlist(head);
				if (j) {
					printf("\nenter you'r intended doctor's id :");
					scanf("%d%c", &id, &trash);
					if (doc[id - 1].check2 != 1) {
						setTextColor(LIGHT_PURPLE); printf("\nthis doctor dosn't have time schedule \n\n"); setTextColor(LIGHT_WHITE);
					}
					else {
						jadval(id, 2);
						char d[10];
						int dat;
						int row;
						char time[30];
					me:printf("\n\nenter you'r intended date(enter to finish) : ");
						gets_s(d);
						dat = atoi(d);
						if (dat == 0)break;
						if (doc[id - 1].nb[dat - 1].check != 1) {
							setTextColor(LIGHT_BLUE); printf("\ndoctor is not in clinic this day...\n"); setTextColor(LIGHT_WHITE);
							goto me;
						}
						printf("\nenter the number of row : ");
						scanf("%d%c", &row, &trash);
						doc[id - 1].nb[dat - 1].nob[row - 1].row = row;
					me2:printf("\nenter you'r intended time (#:#-#:#) : ");
						gets_s(time);
						char time2[30];
						strcpy(time2, time);
						char* token = strtok(time, ":");
						int ftime = atoi(token);
						if (ftime < doc[id - 1].nb[dat - 1].firsttime || ftime >= doc[id - 1].nb[dat - 1].lasttime) {
							setTextColor(LIGHT_RED); printf("\nclinic is closed this time...\n"); setTextColor(LIGHT_WHITE);
							goto me2;
						}
						if (temp->pt.wallet < 55) {
							setTextColor(LIGHT_RED); printf("\nyou don't enough money..\n"); setTextColor(LIGHT_WHITE);
							break;
						}
						else {
							strcpy(doc[id - 1].nb[dat - 1].nob[row - 1].saat, time2);
							doc[id - 1].nb[dat - 1].nob[row - 1].idpatient = temp->pt.id;
							doc[id - 1].nb[dat - 1].nob[row - 1].condition = 1;
							temp->pt.wallet -= 55;
							saveinfile(2);
							tolist2(&head2);
							to_file_nobt();
							file_to_arr_nobat();
							setTextColor(LIGHT_BLUE); printf("\n\nyou'r request registered successfuly"); setTextColor(LIGHT_WHITE);
						}
					}
				}
				else {
					setTextColor(LIGHT_RED); printf("\n\nthere is'n any doctor in clinic"); setTextColor(LIGHT_WHITE);
				}
			}; break;
			case 2: {
				int t = 0;
				clrscr();
				int cv = 0;
				for (int i = 0; i < 50; i++)
				{
					for (int j = 0; j < 31; j++) {
						for (int k = 0; k < 200; k++) {
							if (doc[i].nb[j].nob[k].idpatient == temp->pt.id) {
								t++;
								cv++;
								printf("%d-doctor's id : %d   date : %d  time : %s",t ,doc[i].id, doc[i].nb[j].date, doc[i].nb[j].nob[k].saat);
								printf("\n");
							}
						}
					}

				}
				if (cv) {
					printf("\nenter you'r intended information (enter to finish): \n");
					printf("\nenter doctor's id :");
					char st[30];
					gets_s(st);
					int idc = atoi(st);
					if (idc == 0)
						break;
					printf("\nenter date if appointment : ");
					gets_s(st);
					int dt = atoi(st);
					printf("\nenter time if appointment(#:#-#:#) : ");
					gets_s(st);
					char* token = strtok(st, "-");
					token = strtok(st, ":");
					int sat = atoi(token);
					token = strtok(NULL, "\0");
					int min = atoi(token);
					int row = ((sat - 8) * 60 + min) / doc[idc - 1].timevisit;
					doc[idc - 1].nb[dt - 1].nob[row].idpatient = 0;
					doc[idc - 1].nb[dt - 1].nob[row].row = 0;
					strcpy(doc[idc - 1].nb[dt - 1].nob[row].saat, "\0");
					doc[idc - 1].nb[dt - 1].nob[row].condition = 0;
					temp->pt.wallet -= 25;
					saveinfile(2);
					tolist2(&head2);
					to_file_nobt();
					file_to_arr_nobat();
					setTextColor(LIGHT_BLUE); printf("\n\nyou'r request registered successfuly"); setTextColor(LIGHT_WHITE);
				}
				else {
					setTextColor(LIGHT_RED); printf("\n\nyou dont't have any appointment"); setTextColor(LIGHT_WHITE);
				}
			} break;
			case 3: {
				clrscr();
				int t = 0;
				int fa = 0;
				for (int i = 0; i < 50; i++)
				{
					for (int j = 0; j < 31; j++) {
						for (int k = 0; k < 200; k++) {
							if (doc[i].nb[j].nob[k].idpatient == temp->pt.id) {
								t++;
								fa++;
								printf("%d-doctor's id : %d   date : %d  time : %s", t, doc[i].id, doc[i].nb[j].date, doc[i].nb[j].nob[k].saat);
								printf("\n");
							
							}
						}
					}

				}
				
					char idc[20];
					int ic;
					setTextColor(LIGHT_BLUE); printf("\nenter doctor's id to see the information (enter to finish) : "); setTextColor(LIGHT_WHITE);
					gets_s(idc);
					ic = atoi(idc);
					if (ic == 0)
						break;
					struct ndoctor* temp2 = head;
					while (temp2) {
						if (temp2->doc.id == ic);
						break;
						temp2 = temp2->next;
					}
					printf("\ndoctor's name : %s   doctor's id : %d", temp2->doc.name, temp2->doc.id);
				

				
			
			
			}break;
			case 4 :{
				clrscr();
				int s = 0;
				for (int i = 0; i < 50; i++) {
					if (temp->pt.pres[i].id_dr > 0) {
						printf("doctor's id : %d    doctor's prescription : %s", temp->pt.pres[i].id_dr, temp->pt.pres[i].pr);
						s++;
						printf("\n\n");
					}
			    }
				if (s == 0) {
					setTextColor(LIGHT_RED); printf("\nyou don't have any prescription\n\n"); setTextColor(LIGHT_WHITE);
				}
			}break;
			case 5:return;
			default:setTextColor(RED); printf("\nWRONG ORDER !!!\n\n"); setTextColor(LIGHT_WHITE);
			}
		} while (choce < 1 || choce>5);
		setTextColor(LIGHT_YELLOW); printf("\n\n\n_._._._._._._._._._._._._._._._._._._._._._._._._._._._.\n"); setTextColor(LIGHT_WHITE);
	}
}
//**********************************************************************
void jadval(int iddoc,int a) {
	clrscr();
	int week;
	int hweek = 0;
	char trash;
	int x = (21 - 8) * 60 / doc[iddoc - 1].timevisit;
	for (int j = 0; j <= 2 * x + 3; j += 2) {
		gotoxy(6, j);
		printf("______________________________________________________________________________________________________");
	}
	for (int i = 6; i <= 102; i += 12) {
		for (int j = 1; j <= 2 * x + 2; j++) {
			gotoxy(i, j);
			printf("|");
		}
	}
	for (int j = 1; j <= 2 * x + 2; j++) {
		gotoxy(108, j);
		printf("|");
	}
	gotoxy(10, 1);
	printf("SAT");
	gotoxy(22, 1);
	printf("SUN");
	gotoxy(34, 1);
	printf("MON");
	gotoxy(46, 1);
	printf("TUE");
	gotoxy(58, 1);
	printf("WED");
	gotoxy(70, 1);
	printf("THU");
	gotoxy(82, 1);
	printf("FRI");
	gotoxy(94, 1);
	printf("Time");
	int ab = 8, b = 0, y = 1;
	for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
		gotoxy(91, j);
		printf("%d:%d_", ab, b);
		b += doc[iddoc - 1].timevisit;
		if (b >= 60) {
			b %= 60;
			ab++;
		}
		printf("%d:%d", ab, b);
		gotoxy(105, j);
		printf("%d", y);
		y++;

	}
	gotoxy(0, 2 * x + 3);
	printf("\nSelect your intended week:\n1.first week\t2.second week\t3.third week\t4.fourth week\t5.last week\n");
	printf("week : ");
	scanf("%d%c", &week, &trash);

	//peyda kardan tarikh jome avalin hafte...........
	for (int i = 0;; i++) {
		if (doc[iddoc - 1].nb[i].day_week == fri) {
			hweek = doc[iddoc - 1].nb[i].date;
			break;
		}
	}
	int shart = 1;
	switch (week) {
	case 1:
		for (int i = 0; shart != 0; i++) {
			if (doc[iddoc - 1].nb[i].check != 1) {
				switch (doc[iddoc - 1].nb[i].day_week) {
				case sat:
					gotoxy(8, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(9, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);

					}
					break;
				case sun:
					gotoxy(20, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(21, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case mon:
					gotoxy(34, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(33, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case tue:
					gotoxy(44, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(45, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case wed:
					gotoxy(56, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(57, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case thu:
					gotoxy(68, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(69, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case fri:
					gotoxy(80, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(81, j); setTextColor(RED);
						printf("_____");
						shart = 0;
						setTextColor(LIGHT_WHITE);
					}
					break;
				}
			}
			else {
				float t = 8;
				float w = doc[iddoc - 1].nb[i].lasttime;
				switch (doc[iddoc - 1].nb[i].day_week) {
				case sat:
					gotoxy(8, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i].firsttime) {
							gotoxy(9, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i].lasttime) {
							if (t < doc[iddoc - 1].nb[i].lasttime) {
								
								gotoxy(9, j);
								if (doc[iddoc - 1].nb[i].nob[((j-1)/2)-1].condition == 1) {
									gotoxy(9, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
									
								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						
						}
						else if (t < 21) {
							gotoxy(9, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case sun:
					gotoxy(20, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i].firsttime) {
							gotoxy(21, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i].lasttime) {
					
							if (t < doc[iddoc - 1].nb[i].lasttime) {

								gotoxy(21, j);
								if (doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(21, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(21, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case mon:
					gotoxy(32, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i].firsttime) {
							gotoxy(33, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i].lasttime) {
							if (t < doc[iddoc - 1].nb[i].lasttime) {

								gotoxy(33, j);
								if (doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(33, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(33, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case tue:
					gotoxy(44, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i].firsttime) {
							gotoxy(45, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i].lasttime) {
							if (t < doc[iddoc - 1].nb[i].lasttime) {

								gotoxy(45, j);
								if (doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(45, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(45, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case wed:
					gotoxy(56, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i].firsttime) {
							gotoxy(57, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i].lasttime) {
							if (t < doc[iddoc - 1].nb[i].lasttime) {

								gotoxy(57, j);
								if (doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(57, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(57, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case thu:
					gotoxy(68, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i].firsttime) {
							gotoxy(69, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i].lasttime) {
							if (t < doc[iddoc - 1].nb[i].lasttime) {

								gotoxy(69, j);
								if (doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(69, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(69, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case fri:
					gotoxy(80, 2);
					printf("date : %d", doc[iddoc - 1].nb[i].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i].firsttime) {
							gotoxy(81, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							shart = 0;
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i].lasttime) {
							if (t < doc[iddoc - 1].nb[i].lasttime) {

								gotoxy(81, j);
								if (doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(81, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(81, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				}
			}
		}
		break;
	case 5:
		if ((hweek + 29) <= daycount) {
			for (int i = hweek + 29; i < daycount; i++) {
				if (doc[iddoc - 1].nb[i - 1].check != 1) {
					switch (doc[iddoc - 1].nb[i - 1].day_week) {
					case sat:
						gotoxy(8, 2);
						printf("date : %d", doc[iddoc - 1].nb[i-1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							gotoxy(9, j); setTextColor(RED);
							printf("_____");
							setTextColor(LIGHT_WHITE);
						}
						break;
					case sun:
						gotoxy(20, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							gotoxy(21, j); setTextColor(RED);
							printf("_____");
							setTextColor(LIGHT_WHITE);
						}
						break;
					case mon:
						gotoxy(32, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							gotoxy(33, j); setTextColor(RED);
							printf("_____");
							setTextColor(LIGHT_WHITE);
						}
						break;
					case tue:
						gotoxy(44, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							gotoxy(45, j); setTextColor(RED);
							printf("_____");
							setTextColor(LIGHT_WHITE);
						}
						break;
					case wed:
						gotoxy(56, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							gotoxy(57, j); setTextColor(RED);
							printf("_____");
							setTextColor(LIGHT_WHITE);
						}
						break;
					case thu:
						gotoxy(68, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							gotoxy(69, j); setTextColor(RED);
							printf("_____");
							setTextColor(LIGHT_WHITE);
						}
						break;
					case fri:
						gotoxy(80, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							gotoxy(81, j); setTextColor(RED);
							printf("_____");
							setTextColor(LIGHT_WHITE);
						}
						break;
					}
				}
				else {
					float t = 8;
					switch (doc[iddoc - 1].nb[i - 1].day_week) {


					case sat:
						gotoxy(8, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
								gotoxy(9, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
								if (t < doc[iddoc - 1].nb[i-1].lasttime) {

									gotoxy(9, j);
									if (doc[iddoc - 1].nb[i-1].nob[((j - 1) / 2) - 1].condition == 1) {
										gotoxy(9, j);
										if (a == 1) {
											setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i-1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
										}
										else {
											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
										}
									}
									else {
										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

									}

									t += ((float)doc[iddoc - 1].timevisit / 60);
								}
								else break;
							}
							else if (t < 21) {
								gotoxy(9, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
						}
						break;
					case sun:
						gotoxy(20, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
								gotoxy(21, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
								if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

									gotoxy(21, j);
									if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
										gotoxy(21, j);
										if (a == 1) {
											setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
										}
										else {
											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
										}
									}
									else {
										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

									}

									t += ((float)doc[iddoc - 1].timevisit / 60);
								}
								else break;
							}
							else if (t < 21) {
								gotoxy(21, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
						}
						break;
					case mon:
						gotoxy(32, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
								gotoxy(33, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
								if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

									gotoxy(33, j);
									if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
										gotoxy(33, j);
										if (a == 1) {
											setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
										}
										else {
											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
										}
									}
									else {
										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

									}

									t += ((float)doc[iddoc - 1].timevisit / 60);
								}
								else break;

							}
							else if (t < 21) {
								gotoxy(33, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
						}
						break;
					case tue:
						gotoxy(44, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
								gotoxy(45, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
								if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

									gotoxy(45, j);
									if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
										gotoxy(45, j);
										if (a == 1) {
											setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
										}
										else {
											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
										}
									}
									else {
										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

									}

									t += ((float)doc[iddoc - 1].timevisit / 60);
								}
								else break;
							}
							else if (t < 21) {
								gotoxy(45, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
						}
						break;
					case wed:
						gotoxy(56, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
								gotoxy(57, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
								if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

									gotoxy(57, j);
									if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
										gotoxy(57, j);
										if (a == 1) {
											setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
										}
										else {
											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
										}
									}
									else {
										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

									}

									t += ((float)doc[iddoc - 1].timevisit / 60);
								}
								else break;
							}
							else if (t < 21) {
								gotoxy(57, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
						}
						break;
					case thu:
						gotoxy(68, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
								gotoxy(69, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
								if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

									gotoxy(69, j);
									if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
										gotoxy(69, j);
										if (a == 1) {
											setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
										}
										else {
											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
										}
									}
									else {
										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

									}

									t += ((float)doc[iddoc - 1].timevisit / 60);
								}
								else break;
							}
							else if (t < 21) {
								gotoxy(69, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
						}
						break;
					case fri:
						gotoxy(80, 2);
						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
								gotoxy(81, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
								if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

									gotoxy(81, j);
									if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
										gotoxy(81, j);
										if (a == 1) {
											setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
										}
										else {
											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
										}
									}
									else {
										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

									}

									t += ((float)doc[iddoc - 1].timevisit / 60);
								}
								else break;
							}
							else if (t < 21) {
								gotoxy(81, j); setTextColor(RED);
								printf("_____");
								t += ((float)doc[iddoc - 1].timevisit / 60);
								setTextColor(LIGHT_WHITE);
							}
						}
						break;
					}
				}
			}
		}
		break;
	default:
		week--;
		for (int i = (7 * week) + (hweek - 6); i < ((7 * week) + (hweek - 6)) + 7; i++) {
			if (doc[iddoc - 1].nb[i - 1].check != 1) {
				switch (doc[iddoc - 1].nb[i - 1].day_week) {
				case sat:
					gotoxy(8, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(9, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case sun:
					gotoxy(20, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(21, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case mon:
					gotoxy(32, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(33, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case tue:
					gotoxy(44, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(45, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case wed:
					gotoxy(56, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(57, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case thu:
					gotoxy(68, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(69, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);
					}
					break;
				case fri:
					gotoxy(80, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						gotoxy(81, j); setTextColor(RED);
						printf("_____");
						setTextColor(LIGHT_WHITE);

					}
					break;
				}
			}
			else {
				float t = 8;
				switch (doc[iddoc - 1].nb[i - 1].day_week) {
				case sat:
					gotoxy(8, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
							gotoxy(9, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
							if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

								gotoxy(9, j);
								if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(9, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(9, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case sun:
					gotoxy(20, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
							gotoxy(21, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
							if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

								gotoxy(21, j);
								if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(21, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(21, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case mon:
					gotoxy(32, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
							gotoxy(33, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
							if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

								gotoxy(33, j);
								if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(33, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(33, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case tue:
					gotoxy(44, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
							gotoxy(45, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
							if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

								gotoxy(45, j);
								if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(45, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(45, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case wed:
					gotoxy(56, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
							gotoxy(57, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
							if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

								gotoxy(57, j);
								if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(57, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(57, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case thu:
					gotoxy(68, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
							gotoxy(69, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
							if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

								gotoxy(69, j);
								if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(69, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(69, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				case fri:
					gotoxy(80, 2);
					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
							gotoxy(81, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
							if (t < doc[iddoc - 1].nb[i - 1].lasttime) {

								gotoxy(81, j);
								if (doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].condition == 1) {
									gotoxy(81, j);
									if (a == 1) {
										setTextColor(AQUA); printf("id : %d", doc[iddoc - 1].nb[i - 1].nob[((j - 1) / 2) - 1].idpatient); setTextColor(LIGHT_WHITE);
									}
									else {
										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
									}
								}
								else {
									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);

								}

								t += ((float)doc[iddoc - 1].timevisit / 60);
							}
							else break;
						}
						else if (t < 21) {
							gotoxy(81, j); setTextColor(RED);
							printf("_____");
							t += ((float)doc[iddoc - 1].timevisit / 60);
							setTextColor(LIGHT_WHITE);
						}
					}
					break;
				}
			}
		}
	}
	setTextColor(LIGHT_WHITE);
	gotoxy(0, 2 * x + 7);

	return;
}
///**********************************************************************