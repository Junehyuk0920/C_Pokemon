//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//struct TYPE
//{
//	char name[50];
//};
//
//struct SKILL
//{
//	char name[50];
//	int damage;
//};
//
//struct POKEMON
//{
//	char name[50];
//	int HP;
//	int LV;
//	TYPE type[2];
//	SKILL skill[4];
//};
//
//struct USER
//{
//	char name[50] = "������";
//	int HP = 500;
//	int LV = 100;
//	SKILL skill[4] = {"HTML �ϱ�", 200, "�ڵ� ���ƾ���", 130, "���߱�", 100, "������Ʈ �ڶ��ϱ�", 150};
//};
//
//void line()
//{
//	printf("\n----------------------------------------\n");
//}
//
//int main()
//{	
//	POKEMON pokemon[10] =
//	{
//		//{"��ī��", 0, 0, "����", "-", "10����Ʈ", 90, "������ȭ", 40, "����", 80, "�Ϸ�Ʈ����", 0},
//		//{"�̻��ؾ�", 0, 0, "Ǯ", "��", "�����Ҹ�", 0, "����ä��", 35, "����", 0, "�ٳ�������", 55},
//		//{"���α�", 0, 0, "��", "-", "�����ġ��", 35, "������", 40, "����", 60, "���̵������", 120},
//		//{"���̸�", 0, 0, "��", "-", "������", 40, "�Ҳɼ���", 40, "�������", 70, "�����Ҹ�", 0},
//		{"�����", 0, 0, "��Ÿ��", "������", "�漶", 100, "��������", 150, "�ȱ� 64��", 130, "����", 100},
//		{"������", 0, 0, "�ΰ�", "-", "���Ƽ�� ����", 130, "���", 150, "����Ž��", 130, "��ġ��", 130},
//		{"������", 0, 0, "����õ��", "-", "���� ������", 150, "�����ϱ�", 130, "�������", 150, "���й��� Ǯ��", 150},
//		{"������", 0, 0, "�ΰ�", "-", "������Ʈ�� ���", 100, "�����", 100, "����Ŭ��", 150, "�����ϱ�", 130},
//	};
//
//	USER player;
//
//	while (1)
//	{
//		int random = rand() % 4;
//		int random2 = rand() % 4;
//		int randomLV = rand() % 50 + 1;
//
//		pokemon[random].LV = randomLV;
//		pokemon[random].HP = randomLV + 30;
//
//		printf("\n\n�߻��� %s(��)�� ��Ÿ����!\n\n", pokemon[random].name);
//
//		for (int cnt = 0;; cnt++)
//		{
//			int select = 0;
//
//			line();
//
//			srand(time(NULL));
//
//			if (*pokemon[random].type[1].name == '-') printf("\n[ %s ] %s Ÿ��\nHP : %d / LV : %d\n", pokemon[random].name, pokemon[random].type[0].name, pokemon[random].HP, pokemon[random].LV);
//			else printf("\n[ %s ] %s, %s Ÿ�� / HP : %d / LV : %d\n", pokemon[random].name, pokemon[random].type[0].name, pokemon[random].type[1].name, pokemon[random].HP, pokemon[random].LV);
//
//			printf("\n\n�߻� %s�� [ %s ]!", pokemon[random].name, pokemon[random].skill[random2].name);
//			printf("\n������ %d", pokemon[random].skill[random2].damage);
//
//			printf("\n\n");
//
//			player.HP -= pokemon[random].skill[random2].damage;
//
//			printf("\n[ �÷��̾� %s ] / HP : %d / LV : %d\n", player.name, player.HP, player.LV);
//
//			printf("\n\n������ �Ͻðڽ��ϱ�? [1] �ο�� [2] ���� [3] �������� ==> ");
//			scanf("%d", &select);
//
//			if (select == 1)
//			{
//				printf("\n\n���� ����� ����Ͻðڽ��ϱ�? [1] %s [2] %s [3] %s [4] %s ==> ", player.skill[0].name, player.skill[1].name, player.skill[2].name, player.skill[3].name);
//				scanf("%d", &select);
//
//				if (select == 4) player.skill[select - 1].damage = pokemon[random].skill[random2].damage * 2;
//
//				printf("\n\n�÷��̾� %s�� [ %s ]!", player.name, player.skill[select - 1].name);
//				printf("\n������ %d", player.skill[select - 1].damage);
//
//				if (player.skill[select - 1].damage >= pokemon[random].HP)
//				{
//					printf("\n\n�߻� %s(��)�� ��������!", pokemon[random].name);
//					player.LV++;
//
//					break;
//				}
//			}
//			else if (select == 2)
//			{
//				printf("\n\n��ó���� ����ߴ�! (HP 250 ȸ��)");
//				player.HP += 250;
//			}
//			else if (select == 3)
//			{
//				printf("\n\n���� ĥ �� ������!");
//			}
//		}
//	}
//}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

struct SKILL
{
	char name[50];
	int damage;
};

struct ITEM
{
	char name[50];
	int recoveryAmount;
	int price;
};

struct TYPE
{
	char name[50];
};

struct POKEMON
{
	char name[50];
	int HP;
	int LV;
	TYPE type[2];
	SKILL skill[4];
};

struct PLAYER
{
	char name[50] = "������";
	int money = 3000;
};

struct PLAYER_POKEMON
{
	char name[50] = "������";
	int HP = 500;
	int LV;
	TYPE type[2] = {"����", "����Ʈ���� ������ (�˼��մϴ�)"};
	SKILL skill[4] = {"HTML �ϱ�", 200, "USB �μ���", 200, "���� ���ؿ���", 150, "�ڵ� ���ƾ���", 150}; //150 150 200 200 A+
};

void line()
{
	printf("\n\n-----------------------------------------------------------------------\n\n");
}

int main()
{
	int LV = 0;
	int HP = 0;

	POKEMON pokemon[5] =
	{
		//{�̸�, HP, LV, Ÿ��1, Ÿ��2, ���1, ������, ���2, ������, ���3, ������, ���4, ������}
		{"�����", HP, LV, "����", "��Ÿ��", "�漶", 150, "��������", 200, "�ȱ� 64��", 150, "�ϵ� ������", 200}, //150 150 200 200 A+
		{"������", HP, LV, "�ΰ�", "��� ����", "���Ƽ�� ����", 200, "���", 150, "�б�", 100, "��ġ��", 200}, //100 150 200 200 B
		{"������", HP, LV, "����", "����õ��", "���й��� Ǯ��", 150, "�������", 150, "���� ������", 200, "�����ϱ�", 150}, //150 150 150 200 B+
		{"������", HP, LV, "�ΰ�", "�ɲ���", "�����ϱ�", 150, "������ϱ�", 100, "�����ϱ�", 100, "����Ŭ��", 200}, //100 100 150 200 B-
		{"���ν�", HP, LV, "��ũ��", "�ɲ���", "�߸��۵�����", 200, "�����ϱ�", 150, "�౸�ϱ�", 150, "�ֱ��θ���", 150}, //150 150 150 200 A
	};

	PLAYER player;
	PLAYER_POKEMON playerPokemon;
	ITEM item[4] =
	{
		{"��ó��", 20, 200},
		{"������ó��", 60, 700},
		{"��޻�ó��", 120, 1500},
		{"Ǯȸ����", 0, 2500},
	};

	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		printf("[ %s ] HP : ??? / LV : ??? / TYPE 1 : %s / TYPE 2 : %s\n", pokemon[i].name, pokemon[i].type[0], pokemon[i].type[1]);
		for (int j = 0; j < 4; j++)
		{
			printf("\n[%d] %s / %d", j + 1, pokemon[i].skill[j].name, pokemon[i].skill[j].damage);
		}
		printf("\n\n");
	}

	int playerPokemonLV = rand() % 50 + 1;
	playerPokemon.LV = playerPokemonLV;

	printf("[ %s ] HP : %d / LV : %d / TYPE 1 : %s / TYPE 2 : %s", playerPokemon.name, playerPokemon.HP, playerPokemon.LV, playerPokemon.type[0], playerPokemon.type[1]);
	for (int i = 0; i < 4; i++)
	{
		printf("\n[%d] %s / %d", i + 1, playerPokemon.skill[i].name, playerPokemon.skill[i].damage);
	}

	bool playerFirst = true;
	int stage = 1;


	while (1)
	{
		line();

		printf("STAGE : %d / MONEY : %d\n\n", stage, player.money);

		int random_pokemon = rand() % 5;

		LV = rand() % 50 + 1; //1 ~ 50
		HP = LV + 450;

		pokemon[random_pokemon].LV = LV;
		pokemon[random_pokemon].HP = HP;

		printf("�߻� [ %s ](��)�� ��Ÿ����!\n", pokemon[random_pokemon].name);
		printf("HP : %d / LV : %d\n\n", pokemon[random_pokemon].HP, pokemon[random_pokemon].LV);
		Sleep(750);

		printf("�÷��̾� [ %s ] : ���� [ %s ]!\n\n", player.name, playerPokemon.name);
		
		while (1)
		{
			Sleep(750);

			printf("�߻� [ %s ]\n", pokemon[random_pokemon].name);
			printf("HP : %d / LV : %d\n\n", pokemon[random_pokemon].HP, pokemon[random_pokemon].LV);
			Sleep(750);

			int random_skill = rand() % 4;
			int answer;

			while (1)
			{
				printf("\n������ �Ͻðڽ��ϱ�? [1] �ο�� [2] ����(ġ��) [3] �������� ==> ", playerPokemon.name, playerPokemon.HP, playerPokemon.LV);
				scanf("%d", &answer);
				Sleep(750);

				if (answer == 1)
				{
					printf("\n���� ����� ����Ͻðڽ��ϱ�? [1] %s [2] %s [3] %s [4] %s [5] ���ư��� ==> ", playerPokemon.skill[0].name, playerPokemon.skill[1].name, playerPokemon.skill[2].name, playerPokemon.skill[3].name);
					scanf("%d", &answer);
					Sleep(750);

					if (answer == 5) continue;

					printf("\n[ %s ]�� %s!\n", playerPokemon.name, playerPokemon.skill[answer - 1].name);
					Sleep(750);

					printf("�߻� [ %s ]�� HP�� %d��ŭ �𿴴�!\n\n", pokemon[random_pokemon].name, playerPokemon.skill[answer - 1].damage);
					pokemon[random_pokemon].HP -= playerPokemon.skill[answer - 1].damage;
					Sleep(750);

					break;
				}
				if (answer == 2)
				{
					printf("\n���� ������ ����Ͻðڽ��ϱ�?\n[1] %s ( %d�� ) [2] %s ( %d�� ) [3] %s ( %d�� ) [4] %s ( %d�� ) [5] ���ư��� ==> ", item[0].name, item[0].price, item[1].name, item[1].price, item[2].name, item[2].price, item[3].name, item[3].price, item[4].name, item[4].price);
					scanf("%d", &answer);
					Sleep(750);

					if (player.money - item[answer - 1].price < 0)
					{
						printf("���� �����ϴ�!\n\n");
						continue;
					}

					if (answer == 5) continue;

					printf("\n\n%s�� ����ߴ�!", item[answer - 1].name);
					player.money -= item[answer - 1].price;

					if (answer != 4)
					{
						printf("\n[ %s ]�� HP�� %d��ŭ ȸ���ƴ�!\n\n", playerPokemon.name, item[answer - 1].recoveryAmount);
						playerPokemon.HP += item[answer - 1].recoveryAmount;
					}
					else
					{
						printf("\n[ %s ]�� HP�� ���� á��!\n\n", playerPokemon.name);
						playerPokemon.HP = 500;
					}

					break;
				}
				else if (answer == 3)
				{
					printf("\n���� ĥ �� ������!\n\n");

					break;
				}
				else
				{
					printf("\n�߸� �Է��ߴ�!\n\n");
				}
			}
			if (pokemon[random_pokemon].HP <= 0)
			{
				printf("�߻� [ %s ](��)�� ��������!", pokemon[random_pokemon].name);
				break;
			}

			printf("�߻� [ %s ]�� %s!\n", pokemon[random_pokemon].name, pokemon[random_pokemon].skill[random_skill].name);
			Sleep(750);

			printf("[ %s ]�� HP�� %d��ŭ �𿴴�!\n\n", playerPokemon.name, pokemon[random_pokemon].skill[random_skill].damage);
			playerPokemon.HP -= pokemon[random_pokemon].skill[random_skill].damage;
			Sleep(750);

			printf("[ %s ]\n", playerPokemon.name);
			printf("HP : %d / LV : %d\n\n", playerPokemon.HP, playerPokemon.LV);
			Sleep(750);

			if (playerPokemon.HP <= 0)
			{
				printf("[ %s ](��)�� ��������!", playerPokemon.name);
				break;
			}
			
		}
		Sleep(2000);
		if (playerPokemon.HP <= 0) break;

		player.money += 1000;
		stage++;
	}
}