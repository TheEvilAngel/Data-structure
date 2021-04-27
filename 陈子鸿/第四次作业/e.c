#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 200
typedef struct data {
	int id;
	int wtime;
}CUST;
CUST queue[MAXSIZE];
int window = 3;
int front=0, rear=MAXSIZE-1, count=0;
int isEmpty() {
	return count == 0;
}
int isFull() {
	return count == MAXSIZE;
}
void enQueue(CUST item) {
	if (isFull()) {
		puts("Full queue!");
		exit(1);
	}
	else {
		rear = (rear + 1) % MAXSIZE;
		queue[rear].id= item.id;
		queue[rear].wtime = item.wtime;
		count++;
	}
}
CUST deQueue() {
	CUST e;
	e = queue[front];
	count--;
	front = (front + 1) % MAXSIZE;
	return e;
}
void updateQueue() {
	int i;
	if (count == 0)
		return;
	for (i = front; i <= rear; i++) {
		queue[i].wtime++;
	}
}
void newCust() {
	int i, n;
	static int countCustom = 1;
	CUST customer;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		customer.id = countCustom++;
		customer.wtime = 0;
		enQueue(customer);
	}
	while ((count / window) >= 7 && window < 5) {
		window++;
	}
}
int service() {
	int i;
	CUST customer;
	for (i = 0; i < window; i++) {
		if (isEmpty())
			return 0;
		else {
			customer = deQueue();
			printf("%d : %d\n", customer.id, customer.wtime);
		}
	}
	while ((count / window) < 7 && window > 3) {
		window--;
	}
	return 1;
}
int main() {
	int clock, time;
	scanf("%d", &time);
	for (clock = 1;; clock++) {
		updateQueue();
		if (clock <= time) {
			newCust();
		}
		if (service() == 0 && clock > time) {
			break;
		}
	}
	return 0;
}