/* Add two numbers 
 * https://leetcode.com/problems/add-two-numbers/description/
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definition for singly-linked list.
 typedef struct ListNode {
	 int val;
	 struct ListNode *next;
} ListNode;

// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
//	 struct ListNode* result = NULL;
//	 return result;
// }

#define MAX_NUMBER_LEN 100

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
		printf("%d", head->val);
		head->next = NULL;
	}

	// Print the list's values
	// for (head = list; head->next != NULL; head = list->next){
	//	 printf("%d", head->val+'0');
	// }
	printf("\n");
	return list;
}


int is_all_digits(char* string)
/* Check if all chars in a `string` are digits
   Return 1 if true, 0 if false.
 */
{
	for (unsigned i = 0; i<strlen(string); i++)
	{
		if (! isdigit(string[i])){
			return 0;
		}
	}
	return 1;
}


int main(int argc, char** argv)
{
	char n1[MAX_NUMBER_LEN+1];
	char n2[MAX_NUMBER_LEN+1];

	ListNode* l1 = NULL;
	ListNode* l2 = NULL;

	// TODO: Add check argv are digits
	if (argc == 3){
		if (is_all_digits(argv[1]))
			printf("%s is all digits\n", argv[1]);
		else 
		{
			printf("%s is not all digits\n", argv[1]);
			return 1;
		}
		if (is_all_digits(argv[2]))
			printf("%s is all digits\n", argv[2]);
		else 
		{
			printf("%s is not all digits\n", argv[2]);
			return 1;
		}

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
	// printf("n1 = %s, n2 = %s\n", n1, n2);

	l1 = str2list(n1);
	l2 = str2list(n2);

	// 
	int len = (strlen(n1) > strlen (n2))? strlen(n1): strlen(n2);
	ListNode* h1 = l1;
	ListNode* h2 = l2;
	ListNode* res = NULL;
	int sum, xfer;

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
		printf("%d", sum);
		// printf("xfer = %d\n", xfer);

		if (h1 != NULL)
			h1 = h1->next;
		if (h2 != NULL)
			h2 = h2->next;
	}
	if (xfer){
		printf("%d\n", xfer);
	}
	
	// Free memory

	return 0;
}