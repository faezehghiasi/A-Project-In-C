#pragma once
#pragma warning(disable:4996)
#include<Windows.h>
#include<stdio.h>
int clrscr()
{
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hndl, &csbi);
	DWORD written;
	DWORD N = csbi.dwSize.X * csbi.dwCursorPosition.Y +
		csbi.dwCursorPosition.X + 1;
	COORD curhome = { 0,0 };

	FillConsoleOutputCharacter(hndl, ' ', N, curhome, &written);
	csbi.srWindow.Bottom -= csbi.srWindow.Top;
	csbi.srWindow.Top = 0;
	SetConsoleWindowInfo(hndl, TRUE, &csbi.srWindow);
	SetConsoleCursorPosition(hndl, curhome);

	return 0;
}
void gotoxy(int x, int y)
{
	COORD pos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		pos.X = x;
		pos.Y = y;

		SetConsoleCursorPosition(hConsole, pos);
	}
}
typedef enum
{
	BLACK = 0, BLUE = 1, GREEN = 2,
	AQUA = 3, RED = 4, PURPLE = 5,
	YELLOW = 6, WHITE = 7, GRAY = 8,
	LIGHT_BLUE = 9, LIGHT_GREEN = 10,
	LIGHT_AQUA = 11, LIGHT_RED = 12,
	LIGHT_PURPLE = 13, LIGHT_YELLOW = 14,
	LIGHT_WHITE = 15
} ConsoleColors;
typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;
short setTextColor(const ConsoleColors foreground)
{
	Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	BufferInfo bufferInfo;
	if (!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
		return 0;
	Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
	SetConsoleTextAttribute(consoleHandle, color);
	return 1;
}
//void jadval(int iddoc, int a) {
//	clrscr();
//	int week;
//	int hweek = 0;
//	char trash;
//	int x = (21 - 8) * 60 / doc[iddoc - 1].timevisit;
//	for (int j = 0; j <= 2 * x + 3; j += 2) {
//		gotoxy(6, j);
//		printf("______________________________________________________________________________________________________");
//	}
//	for (int i = 6; i <= 102; i += 12) {
//		for (int j = 1; j <= 2 * x + 2; j++) {
//			gotoxy(i, j);
//			printf("|");
//		}
//	}
//	for (int j = 1; j <= 2 * x + 2; j++) {
//		gotoxy(108, j);
//		printf("|");
//	}
//	gotoxy(10, 1);
//	printf("SAT");
//	gotoxy(22, 1);
//	printf("SUN");
//	gotoxy(34, 1);
//	printf("MON");
//	gotoxy(46, 1);
//	printf("TUE");
//	gotoxy(58, 1);
//	printf("WED");
//	gotoxy(70, 1);
//	printf("THU");
//	gotoxy(82, 1);
//	printf("FRI");
//	gotoxy(94, 1);
//	printf("Time");
//	int a = 8, b = 0, y = 1;
//	for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//		gotoxy(91, j);
//		printf("%d:%d_", a, b);
//		b += doc[iddoc - 1].timevisit;
//		if (b >= 60) {
//			b %= 60;
//			a++;
//		}
//		printf("%d:%d", a, b);
//		gotoxy(105, j);
//		printf("%d", y);
//		y++;
//
//	}
//	gotoxy(0, 2 * x + 3);
//	printf("\nSelect your intended week:\n1.first week\t2.second week\t3.third week\t4.fourth week\t5.last week\n");
//	scanf("week : %d%c", &week, &trash);
//
//	//peyda kardan tarikh jome avalin hafte...........
//	for (int i = 0;; i++) {
//		if (doc[iddoc - 1].nb[i].day_week == fri) {
//			hweek = doc[iddoc - 1].nb[i].date;
//			break;
//		}
//	}
//	int shart = 1;
//	switch (week) {
//	case 1:
//		for (int i = 0; shart != 0; i++) {
//			if (doc[iddoc - 1].nb[i].check != 1) {
//				switch (doc[iddoc - 1].nb[i].day_week) {
//				case sat:
//					gotoxy(8, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(9, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//
//					}
//					break;
//				case sun:
//					gotoxy(20, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(21, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case mon:
//					gotoxy(34, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(33, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case tue:
//					gotoxy(44, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(45, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case wed:
//					gotoxy(56, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(57, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case thu:
//					gotoxy(68, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(69, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case fri:
//					gotoxy(80, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(81, j); setTextColor(RED);
//						printf("_____");
//						shart = 0;
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				}
//			}
//			else {
//				float t = 8;
//				float w = doc[iddoc - 1].nb[i].lasttime;
//				switch (doc[iddoc - 1].nb[i].day_week) {
//				case sat:
//					gotoxy(8, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i].firsttime) {
//							gotoxy(9, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								//if (t < doc[iddoc - 1].nb[i].lasttime){}
//								gotoxy(9, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(9, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//
//						}
//						else if (t < 21) {
//							gotoxy(9, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case sun:
//					gotoxy(20, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i].firsttime) {
//							gotoxy(21, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i].lasttime) {
//
//							for (int k = 0; k < 60; k++) {
//								gotoxy(21, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(21, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(21, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case mon:
//					gotoxy(32, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i].firsttime) {
//							gotoxy(33, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(33, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(33, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(33, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case tue:
//					gotoxy(44, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i].firsttime) {
//							gotoxy(45, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(45, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(45, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(45, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case wed:
//					gotoxy(56, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i].firsttime) {
//							gotoxy(57, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(57, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(57, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(57, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case thu:
//					gotoxy(68, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i].firsttime) {
//							gotoxy(69, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(69, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(69, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(69, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case fri:
//					gotoxy(80, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i].firsttime) {
//							gotoxy(81, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							shart = 0;
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(81, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(81, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(81, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				}
//			}
//		}
//		break;
//	case 5:
//		if ((hweek + 29) <= daycount) {
//			for (int i = hweek + 29; i < daycount; i++) {
//				if (doc[iddoc - 1].nb[i - 1].check != 1) {
//					switch (doc[iddoc - 1].nb[i - 1].day_week) {
//					case sat:
//						gotoxy(8, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							gotoxy(9, j); setTextColor(RED);
//							printf("_____");
//							setTextColor(LIGHT_WHITE);
//						}
//						break;
//					case sun:
//						gotoxy(20, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							gotoxy(21, j); setTextColor(RED);
//							printf("_____");
//							setTextColor(LIGHT_WHITE);
//						}
//						break;
//					case mon:
//						gotoxy(32, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							gotoxy(33, j); setTextColor(RED);
//							printf("_____");
//							setTextColor(LIGHT_WHITE);
//						}
//						break;
//					case tue:
//						gotoxy(44, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							gotoxy(45, j); setTextColor(RED);
//							printf("_____");
//							setTextColor(LIGHT_WHITE);
//						}
//						break;
//					case wed:
//						gotoxy(56, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							gotoxy(57, j); setTextColor(RED);
//							printf("_____");
//							setTextColor(LIGHT_WHITE);
//						}
//						break;
//					case thu:
//						gotoxy(68, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							gotoxy(69, j); setTextColor(RED);
//							printf("_____");
//							setTextColor(LIGHT_WHITE);
//						}
//						break;
//					case fri:
//						gotoxy(80, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							gotoxy(81, j); setTextColor(RED);
//							printf("_____");
//							setTextColor(LIGHT_WHITE);
//						}
//						break;
//					}
//				}
//				else {
//					float t = 8;
//					switch (doc[iddoc - 1].nb[i - 1].day_week) {
//
//
//					case sat:
//						gotoxy(8, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//								gotoxy(9, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//								for (int k = 0; k < 60; k++) {
//									gotoxy(8, j);
//									if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//										gotoxy(8, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//										if (a == 1) {
//											setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//										}
//										else {
//											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//										}
//									}
//									else {
//										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//										j += 2;
//									}
//								}
//							}
//							else if (t < 21) {
//								gotoxy(9, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//						}
//						break;
//					case sun:
//						gotoxy(20, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//								gotoxy(21, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//								for (int k = 0; k < 60; k++) {
//									gotoxy(21, j);
//									if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//										gotoxy(21, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//										if (a == 1) {
//											setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//										}
//										else {
//											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//										}
//									}
//									else {
//										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//										j += 2;
//									}
//								}
//							}
//							else if (t < 21) {
//								gotoxy(21, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//						}
//						break;
//					case mon:
//						gotoxy(32, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//								gotoxy(33, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//								for (int k = 0; k < 60; k++) {
//									gotoxy(33, j);
//									if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//										gotoxy(33, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//										if (a == 1) {
//											setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//										}
//										else {
//											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//										}
//									}
//									else {
//										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//										j += 2;
//									}
//								}
//
//							}
//							else if (t < 21) {
//								gotoxy(33, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//						}
//						break;
//					case tue:
//						gotoxy(44, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//								gotoxy(45, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//								for (int k = 0; k < 60; k++) {
//									gotoxy(45, j);
//									if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//										gotoxy(45, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//										if (a == 1) {
//											setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//										}
//										else {
//											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//										}
//									}
//									else {
//										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//										j += 2;
//									}
//								}
//							}
//							else if (t < 21) {
//								gotoxy(45, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//						}
//						break;
//					case wed:
//						gotoxy(56, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//								gotoxy(57, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//								for (int k = 0; k < 60; k++) {
//									gotoxy(57, j);
//									if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//										gotoxy(57, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//										if (a == 1) {
//											setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//										}
//										else {
//											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//										}
//									}
//									else {
//										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//										j += 2;
//									}
//								}
//							}
//							else if (t < 21) {
//								gotoxy(57, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//						}
//						break;
//					case thu:
//						gotoxy(68, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//								gotoxy(69, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//								for (int k = 0; k < 60; k++) {
//									gotoxy(69, j);
//									if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//										gotoxy(69, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//										if (a == 1) {
//											setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//										}
//										else {
//											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//										}
//									}
//									else {
//										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//										j += 2;
//									}
//								}
//							}
//							else if (t < 21) {
//								gotoxy(69, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//						}
//						break;
//					case fri:
//						gotoxy(80, 2);
//						printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//						for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//							if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//								gotoxy(81, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//							else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//								for (int k = 0; k < 60; k++) {
//									gotoxy(81, j);
//									if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//										gotoxy(81, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//										if (a == 1) {
//											setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//										}
//										else {
//											setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//										}
//									}
//									else {
//										setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//										j += 2;
//									}
//								}
//							}
//							else if (t < 21) {
//								gotoxy(81, j); setTextColor(RED);
//								printf("_____");
//								t += ((float)doc[iddoc - 1].timevisit / 60);
//								setTextColor(LIGHT_WHITE);
//							}
//						}
//						break;
//					}
//				}
//			}
//		}
//		break;
//	default:
//		week--;
//		for (int i = (7 * week) + (hweek - 6); i < ((7 * week) + (hweek - 6)) + 7; i++) {
//			if (doc[iddoc - 1].nb[i - 1].check != 1) {
//				switch (doc[iddoc - 1].nb[i - 1].day_week) {
//				case sat:
//					gotoxy(8, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(9, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case sun:
//					gotoxy(20, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(21, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case mon:
//					gotoxy(32, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(33, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case tue:
//					gotoxy(44, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(45, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case wed:
//					gotoxy(56, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(57, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case thu:
//					gotoxy(68, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(69, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//					}
//					break;
//				case fri:
//					gotoxy(80, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						gotoxy(81, j); setTextColor(RED);
//						printf("_____");
//						setTextColor(LIGHT_WHITE);
//
//					}
//					break;
//				}
//			}
//			else {
//				float t = 8;
//				switch (doc[iddoc - 1].nb[i - 1].day_week) {
//				case sat:
//					gotoxy(8, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//							gotoxy(9, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(9, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(9, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(9, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case sun:
//					gotoxy(20, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//							gotoxy(21, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(21, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(21, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(21, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case mon:
//					gotoxy(32, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//							gotoxy(33, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(33, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(33, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(33, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case tue:
//					gotoxy(44, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//							gotoxy(45, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(45, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(45, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(45, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case wed:
//					gotoxy(56, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//							gotoxy(57, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(57, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(57, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(57, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case thu:
//					gotoxy(68, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//							gotoxy(69, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(69, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(69, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(69, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				case fri:
//					gotoxy(80, 2);
//					printf("date : %d", doc[iddoc - 1].nb[i - 1].date);
//					for (int j = 3, k = 0; j <= 2 * x + 2; j += 2) {
//						if (t < doc[iddoc - 1].nb[i - 1].firsttime) {
//							gotoxy(81, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//						else if (t < doc[iddoc - 1].nb[i - 1].lasttime) {
//							for (int k = 0; k < 60; k++) {
//								gotoxy(81, j);
//								if (doc[iddoc - 1].nb[i].nob[k].condition == 1) {
//									gotoxy(81, (2 * doc[iddoc - 1].nb[i].nob[k].row) + 3);
//									if (a == 1) {
//										setTextColor(LIGHT_YELLOW); printf("%d", doc[iddoc - 1].nb[i].nob[k].idpatient); setTextColor(LIGHT_WHITE);
//									}
//									else {
//										setTextColor(AQUA); printf("RESERVED"); setTextColor(LIGHT_WHITE);
//									}
//								}
//								else {
//									setTextColor(LIGHT_YELLOW); printf("NOTR"); setTextColor(LIGHT_WHITE);
//									j += 2;
//								}
//							}
//						}
//						else if (t < 21) {
//							gotoxy(81, j); setTextColor(RED);
//							printf("_____");
//							t += ((float)doc[iddoc - 1].timevisit / 60);
//							setTextColor(LIGHT_WHITE);
//						}
//					}
//					break;
//				}
//			}
//		}
//	}
//	setTextColor(LIGHT_WHITE);
//	gotoxy(0, 2 * x + 3);
//}
///***********************