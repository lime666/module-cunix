#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include <assert.h>


node_t  *list_create(void *data)
{
	node_t *node = ( node_t * )malloc( sizeof( node_t ) );
	node->data = data;
	node->next = NULL;
	return node;
}


void    list_destroy(node_t **head, void (*fp)(void *data))
{
	node_t *node = *head;
	if( node == NULL )
		return;
	node_t *t;
	while( node )
	{
		fp( node->data );
		t = node;
		node = node->next;
		free( t );
	}
	*head = NULL;
}


void    list_push(node_t *head, void *data)
{
	while( head->next != NULL )
		head = head->next;

	node_t *node = ( node_t * )malloc( sizeof( node_t ) );
	node->data = data;
	node->next = NULL;
	head->next = node;
}

void    list_unshift(node_t **head, void *data)
{
	node_t *node = ( node_t * )malloc( sizeof( node_t ) );
	node->data = data;
	node->next = *head;
	*head = node;
}

void    *list_pop(node_t **head)
{
	node_t *node = *head;
	node_t *prev = NULL;
	void *data;
	if( node == NULL )
		return NULL;
	if( node->next == NULL )
	{
		data = node->data;
		free( node );
		*head = NULL;
		return data;
	}
	while( node->next != NULL )
	{
		prev = node;
		node = node->next;
	}

	data = node->data;
	free( node );
	prev->next = NULL;
	return data;
}
void    *list_shift(node_t **head)
{
	node_t *node = *head;
	void *data;	
	if( node == NULL )
		return NULL;
	*head = node->next;
	data = node->data;
	free( node );
	return data;
}
void    *list_remove(node_t **head, int pos)
{
	int i;
	node_t *prev = NULL;
	node_t *node = *head;
	void *data;	
	for( i = 0; i < pos - 1; ++i )
	{
		prev = node;
		node = node->next;
	}
	prev->next = node->next;
	data = node->data;
	free( node );
	return data;
}


void    list_print(node_t *head)
{
	while( head )
	{
		printf( "%s\n", ( char * )head->data );
		head = head->next;
	}
}

void    list_visitor(node_t *head, void (*fp)(void *data))
{
	while( head )
	{
		fp( head->data );
		head = head->next;
	}
}

