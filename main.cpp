#pragma warning(disable: 4996)

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main() {
	/***********시작 화면**************/
	cout << " _       ___   ______  ______   ___  ㅣ" << endl;
	cout << "| |     /   ↖|      ||      | /   ↖ㅣ" << endl;
	cout << "| |    |     ||      ||      ||     |ㅣ" << endl;
	cout << "| |    |  O  ||_|  |_||_|  |_||  O  |ㅣ" << endl;
	cout << "| |___ |     |  |  |    |  |  |     |ㅣ" << endl;
	cout << "|     ||     |  |  |    |  |  |     |ㅣ" << endl;
	cout << "|_____|↘___/   |__|    |__|  ↘___/ ㅣ" << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl << endl;

	int iWin[6], iBonus = 0, count = 0, temp = 0, season = 0;  //당첨번호, 보너스 번호, 장수, 오름차순을 위한 temp, 회수
	unsigned int gmoney = 0, smoney = 0;  //번 돈, 쓴 돈

	FILE* fSeason = NULL;  //season.txt에 저장되어있는 값 season에 저장
	fopen_s(&fSeason, "season.txt", "rb");
	fscanf(fSeason, "%d", &season);

	time_t cur_time;  //현재시간을 구하기 위한 구조체 정의
	struct tm* cur_tm;
	cur_time = time(NULL);
	cur_tm = localtime(&cur_time);

	cout << "띄어쓰기로 구분하여 1 ~ 45 사이의 숫자 6개 입력" << endl << "(6개 이상 입력시 앞 6개만 입력된다)" << endl;
	cout << "EX) A 수  동 1 12 23 34 45 6" << endl;
	cout << "중복되는 수 입력 또는 범위에 안맞는 숫자 입력 시 그줄부터 재입력해야돼." << endl << endl;
	cout << "로또 몇장 살래?(숫자만 입력) : ";  // 몇장을 살지 입력받고 사용금액계산후 화면전환 
	cin >> count;
	smoney = count * 1000;
	system("cls");
	/*************입력 화면***************/

	int** iChoose = (int**)malloc(sizeof(int*) * count); //iChoose[count][6]으로 동적할당
	for (int i = 0; i < count; i++) {
		iChoose[i] = (int*)malloc(sizeof(int) * 6);
	}

	srand(static_cast<unsigned int>(time(NULL)));  // iWin값들과 iBonus값들 겹치지 않게 정의
	iBonus = rand() % 45 + 1;
	for (int i = 0; i < 6; i++) {
		iWin[i] = rand() % 45 + 1;
		for (int j = 0; j < i; j++) {
			if (iWin[i] == iWin[j]) {
				while (1) {
					iWin[i] = rand() % 45 + 1;
					if (iWin[i] != iWin[j])
						break;
				}
			}
		}
		if (iBonus == iWin[i]) {
			while (1) {
				iBonus = rand() % 45 + 1;
				if (iBonus != iWin[i])
					break;
			}
		}
	}

	for (int i = 0; i < 6; i++) { //iWin값 오름차순 정렬
		for (int j = 0; j < 5 - i; j++) {
			if (iWin[j] > iWin[j + 1]) {
				temp = iWin[j];
				iWin[j] = iWin[j + 1];
				iWin[j + 1] = temp;
			}
		}
	}

	cout << "            Lotto 6/45" << endl << endl;
	cout << "            제  " << season << "  회" << endl;
	cout << "발 행 일 : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday << "   " << cur_tm->tm_hour << ":" << cur_tm->tm_min << ":" << cur_tm->tm_sec << endl;
	cout << "추 첨 일 : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday << endl;
	cout << "지급기한 : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday + 1 << endl;
	cout << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << endl;
	cout << rand() << rand() << "  " << rand() << rand() << "  " << rand() << rand() << endl;
	cout << "----------------------------------" << endl;

	int i = 0;
	while (i < count) {  //A부터 순서대로 줄 설정후 6개값 입력받기
		int overlap = 0;
		char alphabet = i + 65;
		cout << alphabet << " 수  동 ";
		for (int j = 0; j < 6; j++) {  //겹친 수만큼 overlap에 추가하여 0일시 계속진행, 아닐시 화면 재출력후 재입력받기
			cin >> iChoose[i][j];
			for (int k = 0; k < j; k++) {
				if (iChoose[i][j] == iChoose[i][k]) {
					overlap += 1;
				}
			}
			if (iChoose[i][j] > 45 || iChoose[i][j] < 1) {
				overlap += 1;
			}
		}
		if (overlap == 0)
			i++;
		else {
			system("cls");
			cout << "            Lotto 6/45" << endl << endl;
			cout << "            제  " << season << "  회" << endl;
			cout << "발 행 일 : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday << "   " << cur_tm->tm_hour << ":" << cur_tm->tm_min << ":" << cur_tm->tm_sec << endl;
			cout << "추 첨 일 : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday << endl;
			cout << "지급기한 : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday + 1 << endl;
			cout << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << endl;
			cout << rand() << rand() << "  " << rand() << rand() << "  " << rand() << rand() << endl;
			cout << "----------------------------------" << endl;
			for (int a = 0; a < i; a++) {
				char al = a + 65;
				cout << al << " 수  동 ";
				for (int b = 0; b < 6; b++) {
					cout << iChoose[a][b] << " ";
				}
				cout << endl;
			}
		}
	}

	cout << "----------------------------------" << endl;
	cout << "금액                        " << smoney << "원" << endl << endl;

	cout << "엔터를 누르면 당첨결과가 나옵니다.";
	while (getchar() != '\n');
	getchar();
	system("cls");
	/**************결과 화면*****************/

	cout << "                 " << season << "회차 당첨번호" << endl << endl; //당첨번호 출력
	cout << "            ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl << "           ㅣ";
	for (int i = 0; i < 6; i++) {
		cout.width(2);
		cout.fill('0');
		cout << iWin[i];
		cout << " ";
	}
	cout << "+ ";
	cout.width(2);
	cout.fill('0');
	cout << iBonus;
	cout << "ㅣ " << endl << "            ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl << endl;

	for (int i = 0; i < count; i++) {
		char alphabet = i + 65;
		cout << alphabet << " 수  동 ";
		int bcnt = 0, cnt = 0;
		for (int l = 0; l < 6; l++) {  //입력했던 값 출력
			cout.width(2);
			cout.fill('0');
			cout << iChoose[i][l];
			cout << " ";
		}
		cout << "      // ";

		for (int j = 0; j < 6; j++) {  //bcnt와 cnt를 올려주고 맞춘수는 출력
			if (iChoose[i][j] == iBonus) {
				bcnt++;
			}
			for (int k = 0; k < 6; k++) {
				if (iChoose[i][k] == iWin[j]) {
					cout.width(2);
					cout.fill('0');
					cout << iChoose[i][k];
					cout << " ";
					cnt++;
				}
			}
		}

		for (int i = 0; i < 6 - cnt; i++) {  //틀린 수만큼 X 출력
			cout << "X ";
		}
		if (bcnt > 0) {
			cout << "+ ";
			cout.width(2);
			cout.fill('0');
			cout << iBonus;
		}
		else
			cout << "+ X";

		cout << endl << "=> ";  //cnt와 bcnd의 값으로 결과 계산 후 출력
		if (cnt > 5) {
			cout << "1등 당첨!!!!";
			gmoney += 1000000000;
		}
		else if (cnt > 4) {
			if (bcnt > 0) {
				cout << "2등 당첨";
				gmoney += 50000000;
			}
			else {
				cout << "3등 당첨";
				gmoney += 2000000;
			}
		}
		else if (cnt > 3) {
			cout << "4등 당첨";
			gmoney += 50000;
		}
		else if (cnt > 2) {
			cout << "5등 당첨";
			gmoney += 5000;
		}
		else {
			cout << "꽝";
		}
		cout << endl << endl;
	}

	cout << endl << "              총 사용 액 : " << smoney << "원" << endl;  //돈계산
	cout << "              총 수익 액 : " << gmoney << endl << endl;
	if (smoney > gmoney)
		cout << "              손해본 금액 : " << smoney - gmoney << "원" << endl;
	else
		cout << "              이득본 금액 : " << gmoney - smoney << "원" << endl;

	fclose(fSeason); //season값 1 증가 후 저장
	season++;
	fopen_s(&fSeason, "season.txt", "wb");
	fprintf(fSeason, "%d", season);
	fclose(fSeason);
	getchar();
}