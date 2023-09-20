#include "shell.h"

/**
 * noha_list_len - determine lenght of linked list
 *
 * @list: pointer to first
 *
 * Return: size of the list
*/

size_t noha_list_len(const list_t *list)
{
	size_t count = 0;

	while (list)
	{
		list = list->next;
		count++;
	}
	return count;
}

/**
 * noha_list_to strings - return array of string from list
 *
 * @head: pointer to first
 *
 * Return: array of string
*/

char **noha_list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t list size = noha_list_len(head);
	char **strings = NULL;

	if (!head || list_size == 0)
		return NULL;

	strings = malloc(sizeof(char *) * (list_size + 1));
	if (!strings)
		return NULL;

	for (size_t i = 0; node; node = node->next, i++)
	{
		strings[i] = noha_strdup(node->str_value);
		if (!strings[i])
		{
			for (size_t j = 0; j < i; j++)
				free(strings[j]);
			free(strings);
			return NULL;
		}
	}
	strings[list_size] = NULL;
	return strings;
}

/**
 * noha_print_list - print all elements of the linked list
 *
 * @list: pointer to first node
 *
 * Return: size of list
*/
size_t noha_print_list(const list_t *list)
{
	size_t count = 0;

	while (list)
	{
		noha_puts(noha_convert_number(list->num, 10, 0));
		noha_putchar(':');
		noha_putchar(' ');
		noha_puts(list->str_value ? list->str_value : "(nil)");
		noha_puts("\n");
		list = list->next;
		count++;
	}
	return count;
}

/**
 * noha_node_starts_with - return a node whose string starts with the prefix
 *
 * @list: ptr to list head
 * @prefix: string to match
 * @c: next charachter after prefix to match
 *
 * Return: matching or null
*/

list_t *noha_node_starts_with(list_t *list, char *prefix, char c)
{
	char *p = NULL;

	while (list)
	{
		p = noha_starts_with(list->str_value, prefix);
		if (p && ((c == -1) || (*p == c)))
			return list;
		list = list->next;
	}
	return NULL;
}

/**
 * noha_get_node_index - gets index of a node in lnked list
 *
 * @head: pointer to list
 * @node: pointer to node
 *
 * Return: index or -1
*/

ssize_t noha_get_node_index(list_t *head, list_t *node)
{
	size_t index = 0;

	while (head)
	{
		if (head == node)
			return (ssize_t)index;
		head = head->next;
		index++;
	}
	return -1;
}
