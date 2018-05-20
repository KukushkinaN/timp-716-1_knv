#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *next;
	struct node *prev;
} node;

node *head = NULL;
node *tail = NULL;

int isEmpty(){
	if ((head==NULL)&&(tail==NULL))
		return 1;
	else
		return 0;
}

node *find_number(int k){
	node *tmp = head;
	
	for (int i=1;i<k;i++){
		tmp = tmp->next;
		if (tmp==NULL)
			break;
	}
	return tmp;
}

node *find_value(int k){
	node *tmp = head;
	
	while (tmp != NULL && tmp->value !=k){
		tmp = tmp->next;
	}
	return tmp;
}

void init(int value){
	node *tmp = malloc(sizeof(node));
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	head = tmp;
	tail = tmp;
}

void add(int val){
	if (isEmpty()==1)
		init(val);
	else{
		node *tmp = malloc(sizeof(node));
		tmp->value = val;
		tmp->prev = tail;
		tmp->next = NULL;
		tail = tmp;
		tmp->prev->next = tmp;
	}
}

void append(int num, int data){
	node *tmp = find_number(num);

	if (tmp==NULL || tmp==tail){
		node *temp = malloc(sizeof(node));
		temp->value = data;
		temp->next = NULL;
		temp->prev = tail;
		temp->prev->next = temp;
		tail = temp;
	}
	else{
		node *temp = malloc(sizeof(node));
		temp->value = data;
		temp->next = tmp->next;
		temp->prev = tmp;
		tmp->next->prev = temp;
		tmp->next = temp;
	}
}

void prepend(int num, int data){
	node *tmp = find_number(num);
	
	if (tmp==NULL || tmp==head){
		node *temp = malloc(sizeof(node));
		temp->value = data;
		temp->prev = NULL;
		temp->next = head;
		head = temp;
		temp->next->prev = temp;
	}
	else{
		node *temp = malloc(sizeof(node));
		temp->value = data;
		temp->prev = tmp->prev;
		temp->next = tmp;
		tmp->prev = temp;
		temp->prev->next = temp;
	}
}

void print(){
	node *tmp = head;
	printf("%i", tmp->value);
	printf(" ");

	while (tmp->next != NULL){
		tmp = tmp->next;
		printf("%i", tmp->value);
		printf(" ");
	}
	printf("\n");
}

void destroy(){
	if (isEmpty()==0){
		node *tmp = head;
		node *temp = NULL;
		do{
			temp = tmp->next;
			free(tmp);
			tmp = temp;
		}while (tmp != NULL);
	}
}

void remove_node(node *tmp){
	int flag = 0;
	
	if (tmp==NULL)
		 flag = 1;
	if (tmp==head && tmp==tail && flag==0){
		destroy();
		flag = 1;
	}
	if (tmp==head && flag==0){
		head = tmp->next;
		tmp->next->prev = NULL;
		free(tmp);
		flag = 1;
	}
	if (tmp==tail && flag==0){
		tail = tmp->prev;
		tmp->prev->next = NULL;
		free(tmp);
		flag = 1;
	}
	if (tmp != head && tmp !=tail && flag==0){
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
		flag = 1;
	}
}


int main(){
	int n=0, val=0, k=0;
	scanf("%i", &n);
	
	for (int i=0;i<n;i++){
		scanf("%i", &val);
		add(val);
	}

	if (isEmpty()==0)
		print();
	scanf("%i", &k);
	remove_node(find_number(k));
	
	if (isEmpty()==0)
		print();

	scanf("%i", &k);
	remove_node(find_value(k));

	if (isEmpty()==0)
		print();

	scanf("%i", &k);
	scanf("%i", &val);
 	
	append(k, val);

	if (isEmpty()==0)
		print();

	scanf("%i", &k);
	scanf("%i", &val);

	prepend(k, val);

	if (isEmpty()==0)
		print();

	destroy();

	return 0;

}	 
