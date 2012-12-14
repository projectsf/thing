#include <stdio.h>
#include <stdlib.h>


struct list_head
{
	struct list_head* next;
	struct list_head* prev;
	int value;
};

void list_init(struct list_head** head, int value)
{
	struct list_head* entry = malloc(sizeof(struct list_head));
	entry->next = 0;
	entry->prev = 0;
	entry->value = value;
	*head = entry;
}

void list_add_end(struct list_head* head, int value)
{
	//walk to end of list
	struct list_head* current = head;

	//walk to end of list
	while (current->next != 0)
	{
		current = current->next;
	}

	//add entry to end
	struct list_head* entry = malloc(sizeof(struct list_head));
	entry->next = 0;
 	entry->prev = current;
	entry->value = value;
	current->next = entry;
}

void list_print_forward(struct list_head* head)
{
	struct list_head* current = head;

	while (current->next != 0)
	{
		printf("value: %d\n", current->value);
		current = current->next;
	}

	//print last value
	printf("value: %d\n", current->value);
}

void list_print_reverse(struct list_head* head)
{
	struct list_head* current = head;

	//walk to end of list
	while (current->next != 0)
	{
		current = current->next;
	}

	while (current->prev != 0)
	{
		printf("value: %d\n", current->value);
		current = current->prev;
	}

	//print last value
	printf("value: %d\n", current->value);

}

void list_destroy(struct list_head* head)
{
	//walk list deleting next nodes
	struct list_head* current = head;

	//walk list and delete
	while (current->next != 0)
	{
		struct list_head* next = current->next;
		free(current);
		current = next;
	}

	free(current);
}
	

int main(int argc, char* argv[])
{
	//read in command line parameters
    for (unsigned int ii = 0; ii < argc; ++ii)
	{
		printf("argument #%d: %s\n", ii, argv[ii]);
	}

	//initialize first node
	struct list_head** head = malloc(sizeof(struct list_head*));
	int value = 0;
	list_init(head,value);

	//add 10 entries to list
 	for (int ii = 1; ii < 10; ++ii)
	{
		list_add_end(*head, ii);
	}

	//print forward
	printf("Forward print\n");
	printf("===================================\n");
	list_print_forward(*head);
	printf("===================================\n");

	//print reverse 
	printf("Reverse print\n");
	printf("===================================\n");
	list_print_reverse(*head);
	printf("===================================\n");

	list_destroy(*head);

	free(head);
}
