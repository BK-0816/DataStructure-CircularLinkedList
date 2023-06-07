#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head) {
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}
ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;  
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;  
	}
	return head;
}
ListNode* delete_first(ListNode* head) {
	if (head == NULL) {
		printf("List is empty.\n");
		return NULL;
	}

	ListNode* removed = head->link;
	if (removed == head) {
		free(removed);
		return NULL;
	}

	head->link = removed->link;
	free(removed);
	return head;
}

ListNode* delete_last(ListNode* head) {
	if (head == NULL) {
		printf("List is empty.\n");
		return NULL;
	}

	ListNode* p = head->link;
	ListNode* prev = NULL;

	while (p->link != head) {
		prev = p;
		p = p->link;
	}

	prev->link = head;
	free(p);
	return head;
}

void free_list(ListNode* head) {
	if (head == NULL) return;

	ListNode* p = head->link;
	while (p != head) {
		ListNode* temp = p;
		p = p->link;
		free(temp);
	}

	free(head);
}

int main() {
	ListNode* head = NULL;
	int menu, num;

	do {
		printf("\n[Menu]\n");
		printf("(1) Insert First\n");
		printf("(2) Insert Last\n");
		printf("(3) Delete First\n");
		printf("(4) Delete Last\n");
		printf("(5) Print List\n");
		printf("(0) Exit\n");
		printf("Enter your menu: ");
		scanf_s("%d", &menu);

		switch (menu) {
		case 1:
			printf("Input a number: ");
			scanf_s("%d", &num);
			head = insert_first(head, num);
			break;
		case 2:
			printf("Input a number: ");
			scanf_s("%d", &num);
			head = insert_last(head, num);
			break;
		case 3:
			head = delete_first(head);
			break;
		case 4:
			head = delete_last(head);
			break;
		case 5:
			printf("List: ");
			print_list(head);
			break;
		case 0:
			printf("Exit the Program.\n");
			break;
		default:
			printf("Invalid Number. Please try again.\n");
			break;
		}
	} while (menu != 0);

	free_list(head);

	return 0;
}
