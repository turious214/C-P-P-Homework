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
//可以考虑加一个反击

char monsterName[10] = "怪物";
int monsterLevel = level;
int monsterHp;
int monsterAtk;
int monsterDef;
int monsterSpd;
int monsterCritRate;
int monsterCritDamage;
int monsterDodgeRate;


int menu() {

	printf("\n1.查看角色属性");
	printf("\n2.进入修炼");
	printf("\n3.进入野外打怪");
	printf("\n4.进入野外挖宝");
	printf("\n5.退出修真\n");

	int choise;
	scanf("%d", &choise);

	return choise;
}

void showProperty() {
	printf("\n角色名：%s", name);
	printf("\n等级：%d", level);
	printf("\n经验值：%d/%d", myExp, requiredExp);
	printf("\n生命值：%d", hp);
	printf("\n魔力值：%d", mp);
	printf("\n攻击力：%d", atk);
	printf("\n防御力：%d\n", def);
}

void updateRequiredExp() {
	requiredExp = (int)(requiredExp * EXP_GROWTH_RATE);
}
//升级属性增加
void upgradeCheck() {
	if (myExp >= requiredExp) {
		while (myExp >= requiredExp) {
			myExp -= requiredExp;
			level += 1;
			updateRequiredExp();
		}

		printf("\n恭喜少侠升到了%d级\n", level);
	}
}

void cultivate() {
	srand((unsigned)time(NULL));
	int getExp = rand() + 5;
	myExp += getExp;

	printf("\n修行中。。。\n");
	Sleep(2000);
	printf("\n本次修行获得了%d点经验值\n", getExp);
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
//暴击播报
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
		printf("怪物躲过了%s的攻击！\n", name);
	}
	else {
		monsterHp -= damage;
		printf("%s对怪物造成了 %d 点伤害，怪物剩余 HP=%d\n", \
			name, damage, monsterHp);
	}
}

void monsterTurnAttack() {
	int damage = critCalculate(monsterCritRate) - def;

	if (isDodged(dodgeRate)) {
		printf("%s躲过了怪物的攻击！\n", name);
	}
	else {
		hp -= damage;
		printf("怪物对%s造成了 %d 点伤害，%s剩余 HP=%d\n", \
			name, damage, name, hp);
	}
}
//分离战斗经验结算
void battle() {
	initialMonster();
	printf("\n遇到了一只怪物！\n");
	printf("\n怪物属性：HP=%d, ATK=%d, DEF=%d, SPD=%d, CR=%d, DR=%d\n\n", \
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
		printf("\n%s倒下了！\n", name);
	}
	else
	{
		printf("\n怪物倒下了！\n");

		int getExp = (int) (MONSTER_BASE_EXP * monsterLevel * \
			(1.0 + (monsterLevel - level) * 0.2));
		printf("\n本次战斗获得了%d点经验值\n", getExp);
		myExp += getExp;
		upgradeCheck();
	}
}

int main() {
	
	printf("欢迎来到修真界\n请问少侠何名？\n");
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
				printf("\n退出修真中。。。\n");
				Sleep(2000);
				return EXIT_SUCCESS;
			}break;
		}
	}
}
