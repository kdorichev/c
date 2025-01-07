/* Add two numbers 
 * https://leetcode.com/problems/add-two-numbers/description/
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helper.h"

#ifndef MAX_NUMBER_LEN
#include "add-two-numbers.h"
#endif

 typedef struct ListNode {
	 int val;
	 struct ListNode *next;
} ListNode;


/* Free memory allocated for `list` */
void free_list(ListNode *list)
{
	ListNode *h1 = list;

	do {
		list = list->next;
		free(h1);
		h1 = list;
	} while(list);
}


/**
 * @brief Create a list of digits from a `digitsString`
 * @param digitsString 
 * @return struct ListNode* 
 */
ListNode* str2list(char* digitsString){
	ListNode *head, *prev, *list;

	list = prev = head = NULL;

	for (int i = strlen(digitsString)-1; i >=0; i--){
		head = malloc(sizeof(ListNode));

		if (prev == NULL)
			prev = head;
		else {
			prev->next = head;
			prev = head;
		} 

		if (list == NULL)
			list = head; // Remember the head of the list

		head->val = digitsString[i] - '0';
#ifdef DEBUG		
		printf("%d", head->val);
#endif
		head->next = NULL;
	}

#ifdef DEBUG		
	printf("\n");
#endif
	return list;
}


int main(int argc, char** argv)
{
	char n1[MAX_NUMBER_LEN+1];
	char n2[MAX_NUMBER_LEN+1];

	ListNode *l1 = NULL;
	ListNode *l2 = NULL;

	if (argc == 3){
		strncpy(n1, argv[1], MAX_NUMBER_LEN);
		strncpy(n2, argv[2], MAX_NUMBER_LEN);
		n1[MAX_NUMBER_LEN] = '\0';
		n2[MAX_NUMBER_LEN] = '\0';
	}
	else {
		puts("Enter number 1:");
		fgets(n1, 100, stdin);
		size_t len = strlen(n1);
		if (len > 0 && n1[len-1] == '\n'){
			n1[len-1] = '\0';
		}
		puts("Enter number 2:");
		fgets(n2, 100, stdin);
		len = strlen(n2);
		if (len > 0 && n2[len-1] == '\n'){
			n2[len-1] = '\0';
		}		
	}
	if (!check_inputs(n1, n2)){
		return 1;
	}	
#ifdef DEBUG
	printf("n1 = %s, n2 = %s\n", n1, n2);
#endif
	l1 = str2list(n1);
	l2 = str2list(n2);

	int len = (strlen(n1) > strlen (n2))? strlen(n1): strlen(n2);

	ListNode *h1 = l1;
	ListNode *h2 = l2;
	int sum, xfer = 0;

	for (int i=0; i<len; i++){
		sum = 0;

		if (h1 != NULL){
			sum += h1->val;
			// printf("%d + ", h1->val);
		}
		if (h2 != NULL){
			sum += h2->val;
			// printf("%d = ", h2->val);
		}

		sum += xfer;
		xfer = 0;

		if (sum > 9){
			sum = sum % 10;
			xfer = 1;
		}
		// Print next digit of result (reversed order: right-to-left)
		// TODO: print in normal order (left-to-right)
		printf("%d", sum);

		if (h1 != NULL)
			h1 = h1->next;
		if (h2 != NULL)
			h2 = h2->next;
	}
	
	free_list(l1);
	free_list(l2);

	return 0;
}

