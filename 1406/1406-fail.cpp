#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 이 문제는 문자 입력 및 삭제시마다 밀고 당기기를 하면 시간초과가 나는 문제이다.
// 때문에 단순히 포인터만 추가하는 Doubly linked list를 사용해야한다.

typedef struct node {
	char c;
	struct node *prev;
	struct node *next;
} node;

// head, tail 주소는 고정
// prev, next만 수정해야 함
// head, tail에 메모리는 할당되어 있지만 값은 없는 상태
node *head = NULL;
node *tail = NULL;

int M;
char str[200001];
char input[11];
char output[600001];

void push(struct node **head, struct node **tail, char c);
void init(node **head, node **tail);
void print(struct node **head);
void insert(struct node **cursor, struct node **head, char c);
void erase(struct node **cursor, struct node **head);
void print_addr(struct node **head);

// 리턴을 없애보자
// 없애도 안나오면 스택 두 개 써서 다시구현
// 스택 왼쪽 == 커서보다 왼쪽
// 스택 오른쪽 == 커서보다 오른쪽

// 결국 시간초과 못고쳤다
// 대체 왜 ?

int main(void)
{
	node *cursor;

	//init(&head, &tail);
	//freopen("./input/editor.in1", "r", stdin);
	freopen("input1.txt", "r", stdin);

	head = (node *) malloc (sizeof(node));
	tail = (node *) malloc (sizeof(node));

	head->prev = NULL;
	head->next = tail;

	tail->prev = head;
	tail->next = NULL;

	scanf("%s", str);

	for (int i=0; i<strlen(str); i++)
		push(&head, &tail, str[i]);

	cursor = tail;

	scanf("%d\n", &M);

	for (int i=0; i<M; i++) {
		fgets(input, 10, stdin);

		if (input[0]=='L' && cursor->prev != head) {
			cursor = cursor->prev;
		}
		else if (input[0]=='D' && cursor->next != NULL) {
			cursor = cursor->next;
		}
		else if (input[0]=='B' && cursor != head->next) {
			erase(&cursor, &head);
		}
		else if (input[0]=='P') {
			//scanf(" %c", &input);
			insert(&cursor, &head, input[2]);
		}
	}

	node *tmp = head->next;

	while (tmp != NULL) {
		printf("%c", tmp->c);
		tmp = tmp->next;
	}
	printf("\n");

	//print(&head);

	return 0;
}

void init(node **head, node **tail)
{
	*head = (struct node *) malloc (sizeof(struct node));
	*tail = (struct node *) malloc (sizeof(struct node));

	(*head)->prev = NULL;
	(*head)->next = (*tail);

	(*tail)->prev = (*head);
	(*tail)->next = NULL;
}

void push(struct node **head, struct node **tail, char c)
{
	struct node *tmp = (node *) malloc (sizeof(node));

	tmp->c = c;

	tmp->prev = (*tail)->prev;
	tmp->next = (*tail);

	(*tail)->prev->next = tmp;
	(*tail)->prev = tmp;
}

void print(struct node **head)
{
	struct node *head_tmp = (*head)->next;

	while (head_tmp != NULL) {
		printf("%c", head_tmp->c);
		head_tmp = head_tmp->next;
	}
	printf("\n");
}

void print_addr(struct node **head)
{
	struct node *tmp = (*head);

	while (tmp!=NULL) {
		printf("1. prev : %p\n", tmp->prev);
		printf("2. node : %p\n", tmp);
		printf("3. next : %p\n", tmp->next);
		tmp=tmp->next;
	}
}

void insert(struct node **cursor, struct node **head, char c)
{
	node *tmp = (node *) malloc (sizeof(node));
	node *h = (*head)->next;

	tmp->c = c;

	//while (h != (*cursor))
	//	h = h->next;

	h = (*cursor);

	tmp->prev = h->prev;
	tmp->next = h;

	h->prev->next = tmp;
	h->prev = tmp;

	(*cursor) = tmp->next;
}

void erase(struct node **cursor, struct node **head)
{
	node *h = (*head)->next;

	//while (h != (*cursor))
	//	h = h->next;

	h = (*cursor);

	h = h->prev;

	h->prev->next = h->next;
	h->next->prev = h->prev;

	(*cursor) = h->prev->next;

	//free(h);
}
