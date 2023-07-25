#include "deck.h"

/**
* _strcmp - Compares two strings
*
* @s1: string 1
* @s2: string 2
*
* Return: 0 if equal
*/
int _strcmp(char *s1, const char *s2)
{
while (*s1 != '\0')
{
if (*s2 == '\0')
return (*s1);
if (*s2 > *s1)
return (*s1 - *s2);
if (*s1 > *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s2 != '\0')
return (*s2);
return (0);
}
/**
* _swap - Swaps two nodes of doubly linked list
*
* @node: node base to change
* @deck: double link list head
* Return: No Return
*/
void _swap(deck_node_t **node, deck_node_t **deck)
{
deck_node_t *temp = *node, *temp2, *temp3;

if (!(*node)->prev)
*deck = (*node)->next;
temp = temp3 = *node;
temp2 = temp->next;

temp->next = temp2->next;
temp3 = temp->prev;
temp->prev = temp2;
temp2->next = temp;
temp2->prev = temp3;

if (temp2->prev)
temp2->prev->next = temp2;

if (temp->next)
temp->next->prev = temp;

*node = temp2;
}
/**
* CardValue - Obtains poker card Value from node
*
* @cardNode: node of poker card
* Return: Value between 1 and 52
*/
int CardValue(deck_node_t *cardNode)
{
char *cardnum[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
"Jack", "Queen", "King"};
int value, a;
const char *cnum;

cnum = cardNode->card->value;
for (a = 0; a < 13; a++)
if (!_strcmp(cardnum[a], cnum))
{
a++;
break;
}

value = a + (cardNode->card->kind) * 13;

return (value);
}
/**
* sort_deck - sorts a poker cards deck
*
* @deck: doubly linked list
*
* Return: No Return
*/
void sort_deck(deck_node_t **deck)
{
deck_node_t *head, *tback, *aux;

if (!deck || !(*deck) || (!((*deck)->prev) && !((*deck)->next)))
return;

head = *deck;
while (head && head->next)
{
if (CardValue(head) > CardValue(head->next))
{
aux = head;

_swap(&aux, deck);
head = aux;
tback = aux;

while (tback && tback->prev)
{
if (CardValue(tback) < CardValue(tback->prev))
{
aux = tback->prev;

_swap(&(aux), deck);

tback = aux->next;
}

tback = tback->prev;
}
}
head = head->next;
}
}
