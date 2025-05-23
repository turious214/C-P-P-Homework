#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#define EXP_GROWTH_RATE 1.5
#define MONSTER_BASE_EXP 50

char name[10];
int level = 1;
int myExp = 0;
int requiredExp = 50;
int	hp = 100;
int mp = 50;
int atk = 15;
int def = 10;
int spd = 20;
int critRate = 5;
int critDamage = 1.5;
int dodgeRate = 5;
//���Կ��Ǽ�һ������

char monsterName[10] = "����";
int monsterLevel = level;
int monsterHp;
int monsterAtk;
int monsterDef;
int monsterSpd;
int monsterCritRate;
int monsterCritDamage;
int monsterDodgeRate;


int menu() {

	printf("\n1.�鿴��ɫ����");
	printf("\n2.��������");
	printf("\n3.����Ұ����");
	printf("\n4.����Ұ���ڱ�");
	printf("\n5.�˳�����\n");

	int choise;
	scanf("%d", &choise);

	return choise;
}

void showProperty() {
	printf("\n��ɫ����%s", name);
	printf("\n�ȼ���%d", level);
	printf("\n����ֵ��%d/%d", myExp, requiredExp);
	printf("\n����ֵ��%d", hp);
	printf("\nħ��ֵ��%d", mp);
	printf("\n��������%d", atk);
	printf("\n��������%d\n", def);
}

void updateRequiredExp() {
	requiredExp = (int)(requiredExp * EXP_GROWTH_RATE);
}
//������������
void upgradeCheck() {
	if (myExp >= requiredExp) {
		while (myExp >= requiredExp) {
			myExp -= requiredExp;
			level += 1;
			updateRequiredExp();
		}

		printf("\n��ϲ����������%d��\n", level);
	}
}

void cultivate() {
	srand((unsigned)time(NULL));
	int getExp = rand() + 5;
	myExp += getExp;

	printf("\n�����С�����\n");
	Sleep(2000);
	printf("\n�������л����%d�㾭��ֵ\n", getExp);
	upgradeCheck();
}

void initialMonster() {
	srand((unsigned)time(NULL));
	int additionalLevel;

	do {
		additionalLevel = rand() % 5 - 2;
	} while (level + additionalLevel < 1);
	monsterLevel = level + additionalLevel;

	monsterHp = 50 + monsterLevel * 10;
	monsterAtk = 5 + monsterLevel * 3;
	monsterDef = 3 + monsterLevel * 2;
	monsterSpd = 10;
	monsterCritRate = 5;
	monsterCritDamage = 1.5;
	monsterDodgeRate = 5;

}
//��������
int critCalculate(int critRate) {
	int randomCritRate = rand() % 101;
	int damage = atk;
	if (randomCritRate <= critRate) {
		int damage = (int)atk * 1.5;
	}

	return damage;
}

bool isDodged(int dodgeRate) {
	int randomDodgeRate = rand() % 101;
	if (randomDodgeRate < dodgeRate) {
		return true;
	}
	else {
		return false;
	}
}

bool isPlayerTurn() {
	if (spd > monsterSpd) {
		return true;
	}
	else {
		return false;
	}
}

bool turnChange(bool playTurn) {
	if (playTurn) {
		return false;
	}
	else
	{
		return true;
	}
}

void playerTurnAttack() {
	int damage = critCalculate(critRate) - monsterDef;

	if (isDodged(monsterDodgeRate)) {
		printf("��������%s�Ĺ�����\n", name);
	}
	else {
		monsterHp -= damage;
		printf("%s�Թ�������� %d ���˺�������ʣ�� HP=%d\n", \
			name, damage, monsterHp);
	}
}

void monsterTurnAttack() {
	int damage = critCalculate(monsterCritRate) - def;

	if (isDodged(dodgeRate)) {
		printf("%s����˹���Ĺ�����\n", name);
	}
	else {
		hp -= damage;
		printf("�����%s����� %d ���˺���%sʣ�� HP=%d\n", \
			name, damage, name, hp);
	}
}
//����ս���������
void battle() {
	initialMonster();
	printf("\n������һֻ���\n");
	printf("\n�������ԣ�HP=%d, ATK=%d, DEF=%d, SPD=%d, CR=%d, DR=%d\n\n", \
		monsterHp,monsterAtk,monsterDef, monsterSpd, monsterCritRate, monsterDodgeRate);

	static int anger = 0;
	bool playTurn = isPlayerTurn();
	while (hp > 0 && monsterHp > 0) {
		switch (playTurn)
		{
		case true:
			playerTurnAttack();
			break;
		case false:
			monsterTurnAttack();
			break;
		}
		playTurn = turnChange(playTurn);
	}

	if (hp == 0) {
		printf("\n%s�����ˣ�\n", name);
	}
	else
	{
		printf("\n���ﵹ���ˣ�\n");

		int getExp = (int) (MONSTER_BASE_EXP * monsterLevel * \
			(1.0 + (monsterLevel - level) * 0.2));
		printf("\n����ս�������%d�㾭��ֵ\n", getExp);
		myExp += getExp;
		upgradeCheck();
	}
}

int main() {
	
	printf("��ӭ���������\n��������������\n");
	scanf("%9s", name);

	while (1) {
		switch (menu()) {
			case 1:
				showProperty();
				break;
			case 2:
				cultivate();
				break;
			case 3:
				battle();
				break;
			case 4:{}break;
			case 5:{
				printf("\n�˳������С�����\n");
				Sleep(2000);
				return EXIT_SUCCESS;
			}break;
		}
	}
}
