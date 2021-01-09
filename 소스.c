#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996)
#define MAX_NUM 100
struct tel {
	char name[21], num[16], birth[9];
};
int insert(struct tel* tel_list, int count);
void print_all(struct tel* tel_list, int count);
int delete_tel(struct tel* tel_list, int count);
void find_by_birth(struct tel* tel_list, int count);
int main() {
	struct tel tel_list[MAX_NUM];
	int count = 0, n;
	while (1) {
		// 메뉴 출력
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");
		// 원하는 메뉴 선택 입력
		scanf("%d", &n);
		getchar();
		// 해당하는 메뉴 기능을 하는 함수 호출
		switch (n)
		{
		case 1:
			count = insert(tel_list, count);
			break;
		case 2:
			print_all(tel_list, count);
			break;
		case 3:
			count = delete_tel(tel_list, count);
			break;
		case 4:
			find_by_birth(tel_list, count);
			break;
		case 5:
			return 0;
		}

	}
	return 0;
}
int insert(struct tel* tel_list, int count) {
	int i, j;
	struct tel tmp;
	if (count == MAX_NUM) {
		printf("OVERFLOW\n");
		return count;
	}
	printf("Name:");
	gets(tmp.name);
	printf("Phone_number:");
	gets(tmp.num);
	printf("Birth:");
	gets(tmp.birth);
	count++;
	tel_list[count - 1] = tmp;
	for (i = 0; i < count - 1; i++) {
		if (strcmp(tel_list[i].name, tmp.name )> 0) {
			for (j = count - 2; j >= i; j--) {
				tel_list[j + 1] = tel_list[j];
			}
			tel_list[i] = tmp;
			
			break;
		}
	}
	printf("<<%d>>\n", count);
	return count;
}
void print_all(struct tel* tel_list, int count) {
	int i;
	for (i = 0; i < count; i++) {
		printf("%s %s %s\n", tel_list[i].name, tel_list[i].num, tel_list[i].birth);
	}
}
int delete_tel(struct tel* tel_list, int count) {
	char name[21];
	int i, j;
	if (count == 0) {
		printf("NO MEMBER\n");
		return count;
	}
	printf("Name:"); scanf("%s", name);
	for (i = 0; i < count; i++) {
		if (strcmp(tel_list[i].name, name) == 0) {
			for (j = i; j < count - 1; j++) {
				tel_list[j] = tel_list[j + 1];
			}
			return --count;
		}
	}
	return count;
}
void find_by_birth(struct tel* tel_list, int count) {
	int birth;
	int i;
	printf("Birth:"); scanf("%d", &birth);
	for (i = 0; i < count; i++) {
		if ((tel_list[i].birth[4] - '0') * 10 + tel_list[i].birth[5] - '0' == birth) {
			printf("%s %s %s\n", tel_list[i].name, tel_list[i].num, tel_list[i].birth);
		}
	}
}
