#include "funcs.h"
#include <stdio.h>
#include "linktable.h"
#include "menu.h"
#define CMD_MAX_LEN 128

struct DataNode
{
    tLinkTableNode* pNode;
    char* cmd;
    char* desc;
    void(*handler)();
};

int SearchCondition(tLinkTableNode* pLinkTableNode, void* arg)
{
    tDataNode* pNode = (tDataNode*)pLinkTableNode;
    if (strcmp(pNode->cmd, (char*)arg) == 0)
    {
        return SUCCESS;
    }
    return FAILURE;
}

tLinkTable* pLinkTable = NULL;

int main()
{
    MenuConfig("pain", "Rick is in a lot of pain.", Pain);
    MenuConfig("quit", "Quit from menu.", Quit);
    MenuConfig("go", "Go on some adventure with Rick and Morty!", Go);


    ExecuteMenu();
    return 0;
}

void MenuConfig(char* cmd, char* desc, void(*handler)()) 
{
    tDataNode* pNode = NULL;
    if (pLinkTable == NULL)
    {
        pLinkTable = CreateLinkTable();
        pNode = (tDataNode*)malloc(sizeof(tDataNode));
        pNode->cmd = "help";
        pNode->desc = "This is a help cmd.";
        pNode->handler = Help;
        AddLinkTableNode(pLinkTable, (tLinkTableNode*)pNode);
    }
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler;
    AddLinkTableNode(pLinkTable, (tLinkTableNode*)pNode);
    return;
}

void ExecuteMenu()
{
    while (1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd > ");
        scanf("%s", cmd);
        tDataNode* p = (tDataNode*)SearchLinkTableNode(pLinkTable, SearchCondition, cmd);
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
    return;
}

void Help()
{
    printf("Menu List:\n");
    tDataNode* pNode = (tDataNode*)GetLinkTableHead(*pLinkTable);
    while (pNode != NULL)
    {

        printf("%s - %s\n", pNode->cmd, pNode->desc);

        pNode = (tDataNode*)GetNextLinkTableNode(*pLinkTable, (tLinkTableNode*)pNode);

    }
    return;
}

void Quit()
{
    exit(0);
    return;
}

void Go()
{
    printf("And the waaaaaaaay we go~~~\n");
    return;
}

void Pain()
{
    printf("Wubba lubba dub dub.\n");
    return;
}

