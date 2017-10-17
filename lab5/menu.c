#include "linktable.h"
#include <string.h>
#include <stdlib.h>

#define CMD_MAX_LEN 128

typedef struct DataNode 
{
    tLinkTableNode *pNext;
    char *cmd;
    char *desc;
    int(*handler)();
} tDataNode;

int Help();
int Quit();
int Go();
int Pain();

int SearchCondition(tLinkTableNode * pLinkTableNode, void * args)
{
    char * cmd = (char *)args;
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if (strcmp(pNode->cmd, cmd) == 0)
    {
        return SUCCESS;
    }
    return FAILURE;
}

int InitMenuData(tLinkTable ** ppLinkTable)
{
    *ppLinkTable = CreateLinkTable();

    tDataNode * pNode = (tDataNode *)malloc(sizeof(tDataNode));

    pNode->cmd = "help";
    pNode->desc = "Menu List:";
    pNode->handler = Help;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "version";
    pNode->desc = "Menu Program V1.0";
    pNode->handler = NULL;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode); 

    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "Quit from Menu Program V1.0";
    pNode->handler = Quit;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "go";
    pNode->desc = "go time traveling with grandpa rick";
    pNode->handler = Go;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "pain";
    pNode->desc = "rick is in a lot of pain";
    pNode->handler = Pain;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "time";
    pNode->desc = "you don't mess with time";
    pNode->handler = NULL;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "get-shwifty";
    pNode->desc = "shit on the floor, I'm mr Bulldops";
    pNode->handler = NULL;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    pNode = (tDataNode *)malloc(sizeof(tDataNode));
    pNode->cmd = "school";
    pNode->desc = "not a place for smart people";
    pNode->handler = NULL;
    AddLinkTableNode(*ppLinkTable, (tLinkTableNode *)pNode);

    return 0;
}

tDataNode * FindCmd(tLinkTable * pLinkTable, char * cmd)
{
    return (tDataNode *)SearchLinkTableNode(pLinkTable, SearchCondition, cmd);
}

int ShowAllCmd(tLinkTable LinkTable)
{
    tDataNode * pNode = (tDataNode *)GetLinkTableHead(LinkTable);

    while (pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode *)GetNextLinkTableNode(LinkTable, (tLinkTableNode *)pNode);
    }
    return 0;
}

tLinkTable * pLinkTable = NULL;

int main()
{
    InitMenuData(&pLinkTable);
	while (1)
	{
        char cmd[CMD_MAX_LEN];
		printf("Input a cmd > ");
		scanf("%s", cmd);
        tDataNode * p = FindCmd(pLinkTable, cmd);
        if (p == NULL)
        {
            printf("This is a wrong cmd!\n");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc);
        if (p->handler != NULL)
        {
            p->handler();
        }
	}
    return 0;
}

int Help()
{
    ShowAllCmd(*pLinkTable);
    return 0;
}

int Quit()
{
    exit(0);
}

int Go() 
{
    printf("And the waaay we go\n");
    return 0;
}

int Pain() 
{
    printf("Wubb lub dubb dubbs\n");
    return 0;
}

