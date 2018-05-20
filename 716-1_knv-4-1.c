#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int value;
	struct list *next;
	struct list *prev;
}list;

list *head = NULL;
list *tail = NULL;

int init(int date){
	list *tmp = (list*)malloc(sizeof(list));
	tmp->value = date;
	tmp->next = NULL;
	tmp->prev = NULL;
	head = tmp;
	tail = tmp;
}

int isEmpty(){
	if (head == NULL && tail == NULL)  return 1;
	else  return 0;
}

void insertEnd(int date){
	if (isEmpty() == 1)  init(date);
	else{
		list *tmp = (list*)malloc(sizeof(list));
		tmp->value = date;
		tmp->next = NULL;
		tmp->prev = tail;
		tail = tmp;
		tmp->prev->next = tmp;
	}
}

void insertList(){
	list *tmp = head;
	while (tmp != NULL){
		printf("%d", tmp->value);
		tmp = tmp->next;
	}
}

int del(){
	if (isEmpty()) return 0;
	list *tmp = head;
	if (tmp == tail){
		head = NULL;
		tail = NULL;
		free(tmp);
		return 1;
	}
	list *tmp1 = NULL;
	tmp1 = tmp->next;
	free(tmp);
	head = tmp1;
	return 1;
}

int main(){
	int n, val;

	scanf("%d", &n);		
	scanf("%d", &val);
	init(val);
	
	for(int i = 0; i < n-1; i++){
		scanf("%d", &val);
		insertEnd(val);
	}

	insertList();
	printf("\n");

	for(int i=0; i < n; i++){
		del();
		insertList();
		printf("\n");
	}

	return 0;
}	 
