#include "linktable.h"

tLinkTable* CreateLinkTable()
{
    tLinkTable* pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    tLinkTableNode* pNode = (tLinkTableNode*)malloc(sizeof(tLinkTableNode));
    pNode->pNext = NULL;
    pLinkTable->pHead = pNode;
    pLinkTable->pTail = pNode;
    pLinkTable->SumOfNode = 0;
    return pLinkTable;
}

int AddLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    if (pLinkTable->SumOfNode == 0)
    {
        pLinkTable->pHead = pNode;
    }
    pNode->pNext = NULL;
    pLinkTable->pTail->pNext = pNode;
    pLinkTable->pTail = pNode;
    pLinkTable->SumOfNode++;
    return 0;
}

tLinkTableNode* GetLinkTableHead(tLinkTable LinkTable)
{
    return LinkTable.pHead;
}

tLinkTableNode* GetNextLinkTableNode(tLinkTable pLinkTable, tLinkTableNode* pNode)
{
    return pNode->pNext;
}

tLinkTableNode* SearchLinkTableNode(tLinkTable* pLinkTable, int Condition(tLinkTableNode* pNode, void* args), void* args)
{
    if (pLinkTable == NULL || Condition == NULL)
    {
        return NULL;
    }
    tLinkTableNode* pNode = pLinkTable->pHead;
    while (pNode != NULL)
    {
        if (Condition(pNode, args) == SUCCESS)
        {
            return pNode;
        }
        pNode = pNode->pNext;
    }
    return NULL;
}

