//#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

tDataNode *FindCmd(tDataNode *head, char* cmd)
{
    tDataNode *p = head;
    while (p != NULL)
    {
        if (strcmp(p->cmd, cmd) == 0)
        {
            printf("%s - %s\n", p->cmd, p->desc);
            if (p->handler != NULL)
            {
                p->handler();
            }
            break;
        }
        p = p->next;
    }
    return p;
}

int ShowAllCmd(tDataNode *head)
{
    printf("Menu List:\n");
    tDataNode *p = head;
    while (p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}
