#pragma warning(disable: 4996)

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main() {
	/***********���� ȭ��**************/
	cout << " _       ___   ______  ______   ___  ��" << endl;
	cout << "| |     /   ��|      ||      | /   �ؤ�" << endl;
	cout << "| |    |     ||      ||      ||     |��" << endl;
	cout << "| |    |  O  ||_|  |_||_|  |_||  O  |��" << endl;
	cout << "| |___ |     |  |  |    |  |  |     |��" << endl;
	cout << "|     ||     |  |  |    |  |  |     |��" << endl;
	cout << "|_____|��___/   |__|    |__|  ��___/ ��" << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl << endl;

	int iWin[6], iBonus = 0, count = 0, temp = 0, season = 0;  //��÷��ȣ, ���ʽ� ��ȣ, ���, ���������� ���� temp, ȸ��
	unsigned int gmoney = 0, smoney = 0;  //�� ��, �� ��

	FILE* fSeason = NULL;  //season.txt�� ����Ǿ��ִ� �� season�� ����
	fopen_s(&fSeason, "season.txt", "rb");
	fscanf(fSeason, "%d", &season);

	time_t cur_time;  //����ð��� ���ϱ� ���� ����ü ����
	struct tm* cur_tm;
	cur_time = time(NULL);
	cur_tm = localtime(&cur_time);

	cout << "����� �����Ͽ� 1 ~ 45 ������ ���� 6�� �Է�" << endl << "(6�� �̻� �Է½� �� 6���� �Էµȴ�)" << endl;
	cout << "EX) A ��  �� 1 12 23 34 45 6" << endl;
	cout << "�ߺ��Ǵ� �� �Է� �Ǵ� ������ �ȸ´� ���� �Է� �� ���ٺ��� ���Է��ؾߵ�." << endl << endl;
	cout << "�ζ� ���� �췡?(���ڸ� �Է�) : ";  // ������ ���� �Է¹ް� ���ݾװ���� ȭ����ȯ 
	cin >> count;
	smoney = count * 1000;
	system("cls");
	/*************�Է� ȭ��***************/

	int** iChoose = (int**)malloc(sizeof(int*) * count); //iChoose[count][6]���� �����Ҵ�
	for (int i = 0; i < count; i++) {
		iChoose[i] = (int*)malloc(sizeof(int) * 6);
	}

	srand(static_cast<unsigned int>(time(NULL)));  // iWin����� iBonus���� ��ġ�� �ʰ� ����
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

	for (int i = 0; i < 6; i++) { //iWin�� �������� ����
		for (int j = 0; j < 5 - i; j++) {
			if (iWin[j] > iWin[j + 1]) {
				temp = iWin[j];
				iWin[j] = iWin[j + 1];
				iWin[j + 1] = temp;
			}
		}
	}

	cout << "            Lotto 6/45" << endl << endl;
	cout << "            ��  " << season << "  ȸ" << endl;
	cout << "�� �� �� : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday << "   " << cur_tm->tm_hour << ":" << cur_tm->tm_min << ":" << cur_tm->tm_sec << endl;
	cout << "�� ÷ �� : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday << endl;
	cout << "���ޱ��� : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday + 1 << endl;
	cout << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << endl;
	cout << rand() << rand() << "  " << rand() << rand() << "  " << rand() << rand() << endl;
	cout << "----------------------------------" << endl;

	int i = 0;
	while (i < count) {  //A���� ������� �� ������ 6���� �Է¹ޱ�
		int overlap = 0;
		char alphabet = i + 65;
		cout << alphabet << " ��  �� ";
		for (int j = 0; j < 6; j++) {  //��ģ ����ŭ overlap�� �߰��Ͽ� 0�Ͻ� �������, �ƴҽ� ȭ�� ������� ���Է¹ޱ�
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
			cout << "            ��  " << season << "  ȸ" << endl;
			cout << "�� �� �� : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday << "   " << cur_tm->tm_hour << ":" << cur_tm->tm_min << ":" << cur_tm->tm_sec << endl;
			cout << "�� ÷ �� : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday << endl;
			cout << "���ޱ��� : " << cur_tm->tm_year + 1900 << "/" << cur_tm->tm_mon + 1 << "/" << cur_tm->tm_mday + 1 << endl;
			cout << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << endl;
			cout << rand() << rand() << "  " << rand() << rand() << "  " << rand() << rand() << endl;
			cout << "----------------------------------" << endl;
			for (int a = 0; a < i; a++) {
				char al = a + 65;
				cout << al << " ��  �� ";
				for (int b = 0; b < 6; b++) {
					cout << iChoose[a][b] << " ";
				}
				cout << endl;
			}
		}
	}

	cout << "----------------------------------" << endl;
	cout << "�ݾ�                        " << smoney << "��" << endl << endl;

	cout << "���͸� ������ ��÷����� ���ɴϴ�.";
	while (getchar() != '\n');
	getchar();
	system("cls");
	/**************��� ȭ��*****************/

	cout << "                 " << season << "ȸ�� ��÷��ȣ" << endl << endl; //��÷��ȣ ���
	cout << "            �ѤѤѤѤѤѤѤѤѤѤѤ�" << endl << "           ��";
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
	cout << "�� " << endl << "            �ѤѤѤѤѤѤѤѤѤѤѤ�" << endl << endl;

	for (int i = 0; i < count; i++) {
		char alphabet = i + 65;
		cout << alphabet << " ��  �� ";
		int bcnt = 0, cnt = 0;
		for (int l = 0; l < 6; l++) {  //�Է��ߴ� �� ���
			cout.width(2);
			cout.fill('0');
			cout << iChoose[i][l];
			cout << " ";
		}
		cout << "      // ";

		for (int j = 0; j < 6; j++) {  //bcnt�� cnt�� �÷��ְ� ������� ���
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

		for (int i = 0; i < 6 - cnt; i++) {  //Ʋ�� ����ŭ X ���
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

		cout << endl << "=> ";  //cnt�� bcnd�� ������ ��� ��� �� ���
		if (cnt > 5) {
			cout << "1�� ��÷!!!!";
			gmoney += 1000000000;
		}
		else if (cnt > 4) {
			if (bcnt > 0) {
				cout << "2�� ��÷";
				gmoney += 50000000;
			}
			else {
				cout << "3�� ��÷";
				gmoney += 2000000;
			}
		}
		else if (cnt > 3) {
			cout << "4�� ��÷";
			gmoney += 50000;
		}
		else if (cnt > 2) {
			cout << "5�� ��÷";
			gmoney += 5000;
		}
		else {
			cout << "��";
		}
		cout << endl << endl;
	}

	cout << endl << "              �� ��� �� : " << smoney << "��" << endl;  //�����
	cout << "              �� ���� �� : " << gmoney << endl << endl;
	if (smoney > gmoney)
		cout << "              ���غ� �ݾ� : " << smoney - gmoney << "��" << endl;
	else
		cout << "              �̵溻 �ݾ� : " << gmoney - smoney << "��" << endl;

	fclose(fSeason); //season�� 1 ���� �� ����
	season++;
	fopen_s(&fSeason, "season.txt", "wb");
	fprintf(fSeason, "%d", season);
	fclose(fSeason);
	getchar();
}