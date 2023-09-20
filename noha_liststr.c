#include "shell.h"

/**
 * noha_add_node - add a node to the start of the list
 *
 * @head: address of the pointer to head node
 * @str_value: field of the node
 * @number: node index that have been used by history
 *
 * Return: size of list
*/

list_t *noha_add_node(list_t **head, const char *str_value, int number)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	noha_memset((void *)new_head, 0, sizeof(list_t));
	new_head->number = number;
	if (str_value)
	{
		new_head->str_value = noha_strdup(str_value);
		if (!new_head->str_value)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * noha_add_node_end - add a node in the end of list
 *
 * @head: address of ptr to head node
 * @str_value: field of node
 * @number: node index that have been used by history
 *
 * Return: size of list
*/

list_t *noha_add_node_end(list_t **head, const char *str_value, int number)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	noha_memset((void *)new_node, 0, sizeof(list_t));
	new_node->number = number;
	if (str_value)
	{
		new_node->str_value = noha_strdup(str_value);
		if (!new_node->str_value)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * noha_print_list_str - prints only the value elemnt of list
 *
 * @head: ptr to first node
 *
 * Return: size of list
*/

size_t noha_print_list_str(const list_t *head)
{
	size_t count = 0;

	while (head)
	{
		noha_puts(head->str_value ? head->str_value : "(nil)");
		noha_puts("\n");
		head = head->next;
		count++;
	}
	return (count);
}

/**
 * noha_delete_node_at_index - delete the node at give index
 *
 * @head: address of pointer to first
 * @index: index of node
 *
 * Return: 1 on success if faild then 0
*/

int noha_delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str_value);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str_value);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * noha_free_list - free all node of a list
 *
 * @head_ptr: address of ptr to head
 *
 * Return: the void
*/

void noha_free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str_value);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
