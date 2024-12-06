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
	char name[50] = "수형쌤";
	int money = 3000;
};

struct PLAYER_POKEMON
{
	char name[50] = "이준혁";
	int HP = 500;
	int LV;
	TYPE type[2] = {"영재", "프론트엔드 개발자 (죄송합니다)"};
	SKILL skill[4] = {"HTML 하기", 200, "USB 부수기", 200, "복습 안해오기", 150, "코드 갈아엎기", 150}; //150 150 200 200 A+
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
		//{이름, HP, LV, 타입1, 타입2, 기술1, 데미지, 기술2, 데미지, 기술3, 데미지, 기술4, 데미지}
		{"김민준", HP, LV, "영재", "오타쿠", "흑섬", 150, "영역전개", 200, "팔괘 64장", 150, "하드 날리기", 200}, //150 150 200 200 A+
		{"권지성", HP, LV, "인간", "잠뜰 찐팬", "잠뜰티비 보기", 200, "찌르기", 150, "밀기", 100, "훔치기", 200}, //100 150 200 200 B
		{"이종현", HP, LV, "영재", "수학천재", "수학문제 풀기", 150, "묵언수행", 150, "진도 나가기", 200, "집중하기", 150}, //150 150 150 200 B+
		{"조은찬", HP, LV, "인간", "쪼꼬미", "구경하기", 150, "얼불춤하기", 100, "지메하기", 100, "지터클릭", 200}, //100 100 150 200 B-
		{"정민슈", HP, LV, "슈크림", "쪼꼬미", "발리송돌리기", 200, "딴짓하기", 150, "축구하기", 150, "애교부리기", 150}, //150 150 150 200 A
	};

	PLAYER player;
	PLAYER_POKEMON playerPokemon;
	ITEM item[4] =
	{
		{"상처약", 20, 200},
		{"좋은상처약", 60, 700},
		{"고급상처약", 120, 1500},
		{"풀회복약", 0, 2500},
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

		printf("야생 [ %s ](이)가 나타났다!\n", pokemon[random_pokemon].name);
		printf("HP : %d / LV : %d\n\n", pokemon[random_pokemon].HP, pokemon[random_pokemon].LV);
		Sleep(750);

		printf("플레이어 [ %s ] : 가랏 [ %s ]!\n\n", player.name, playerPokemon.name);
		
		while (1)
		{
			Sleep(750);

			printf("야생 [ %s ]\n", pokemon[random_pokemon].name);
			printf("HP : %d / LV : %d\n\n", pokemon[random_pokemon].HP, pokemon[random_pokemon].LV);
			Sleep(750);

			int random_skill = rand() % 4;
			int answer;

			while (1)
			{
				printf("\n무엇을 하시겠습니까? [1] 싸운다 [2] 도구(치유) [3] 도망간다 ==> ", playerPokemon.name, playerPokemon.HP, playerPokemon.LV);
				scanf("%d", &answer);
				Sleep(750);

				if (answer == 1)
				{
					printf("\n무슨 기술을 사용하시겠습니까? [1] %s [2] %s [3] %s [4] %s [5] 돌아간다 ==> ", playerPokemon.skill[0].name, playerPokemon.skill[1].name, playerPokemon.skill[2].name, playerPokemon.skill[3].name);
					scanf("%d", &answer);
					Sleep(750);

					if (answer == 5) continue;

					printf("\n[ %s ]의 %s!\n", playerPokemon.name, playerPokemon.skill[answer - 1].name);
					Sleep(750);

					printf("야생 [ %s ]의 HP가 %d만큼 깎였다!\n\n", pokemon[random_pokemon].name, playerPokemon.skill[answer - 1].damage);
					pokemon[random_pokemon].HP -= playerPokemon.skill[answer - 1].damage;
					Sleep(750);

					break;
				}
				if (answer == 2)
				{
					printf("\n무슨 도구를 사용하시겠습니까?\n[1] %s ( %d원 ) [2] %s ( %d원 ) [3] %s ( %d원 ) [4] %s ( %d원 ) [5] 돌아간다 ==> ", item[0].name, item[0].price, item[1].name, item[1].price, item[2].name, item[2].price, item[3].name, item[3].price, item[4].name, item[4].price);
					scanf("%d", &answer);
					Sleep(750);

					if (player.money - item[answer - 1].price < 0)
					{
						printf("돈이 부족하다!\n\n");
						continue;
					}

					if (answer == 5) continue;

					printf("\n\n%s를 사용했다!", item[answer - 1].name);
					player.money -= item[answer - 1].price;

					if (answer != 4)
					{
						printf("\n[ %s ]의 HP가 %d만큼 회복됐다!\n\n", playerPokemon.name, item[answer - 1].recoveryAmount);
						playerPokemon.HP += item[answer - 1].recoveryAmount;
					}
					else
					{
						printf("\n[ %s ]의 HP가 가득 찼다!\n\n", playerPokemon.name);
						playerPokemon.HP = 500;
					}

					break;
				}
				else if (answer == 3)
				{
					printf("\n도망 칠 수 없었다!\n\n");

					break;
				}
				else
				{
					printf("\n잘못 입력했다!\n\n");
				}
			}
			if (pokemon[random_pokemon].HP <= 0)
			{
				printf("야생 [ %s ](은)는 쓰러졌다!", pokemon[random_pokemon].name);
				break;
			}

			printf("야생 [ %s ]의 %s!\n", pokemon[random_pokemon].name, pokemon[random_pokemon].skill[random_skill].name);
			Sleep(750);

			printf("[ %s ]의 HP가 %d만큼 깎였다!\n\n", playerPokemon.name, pokemon[random_pokemon].skill[random_skill].damage);
			playerPokemon.HP -= pokemon[random_pokemon].skill[random_skill].damage;
			Sleep(750);

			printf("[ %s ]\n", playerPokemon.name);
			printf("HP : %d / LV : %d\n\n", playerPokemon.HP, playerPokemon.LV);
			Sleep(750);

			if (playerPokemon.HP <= 0)
			{
				printf("[ %s ](은)는 쓰러졌다!", playerPokemon.name);
				break;
			}
			
		}
		Sleep(2000);
		if (playerPokemon.HP <= 0) break;

		player.money += 1000;
		stage++;
	}
}
