#include <stdlib.h>

#define SUCCESS 1
#define FAILURE (-1)

/* LinkTable Node Type */
typedef struct LinkTableNode
{
	struct LinkTableNode* pNext;
}tLinkTableNode;

/* LinkTable Type */
typedef struct LinkTable 
{
    tLinkTableNode* pHead;
    tLinkTableNode* pTail;
    int SumOfNode;
} tLinkTable;

/* Create a LinkTable */
tLinkTable* CreateLinkTable();

/* Delete a LinkTable */
int DestroyLinkTable(tLinkTable* pLinkTable);

/* AddLinkTableNode */
int AddLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);

/* Delete a LinkTableNode from LinkTable */
int DelLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode);

/* Get linktable head */
tLinkTableNode* GetLinkTableHead(tLinkTable linkTable);

/* Get next linktablenode */
tLinkTableNode* GetNextLinkTableNode(tLinkTable pLinkTable, tLinkTableNode* pNode);

/* Search a LinkTableNode from LinkTable */
tLinkTableNode* SearchLinkTableNode(tLinkTable* pLinkTable, int Condition(tLinkTableNode* pNode, void* arg), void* arg);

