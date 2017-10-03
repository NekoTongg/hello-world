// ConsoleApplication1.cpp : Defines the entry point for the console application.

/****************************************************************************************/
/* Copyright (C) XT, 2017                                                               */
/* FILE NAME                      :  menu.c                                             */
/* PRINCIPAL AUTHOR               :  XT                                                 */
/* SUBSYSTEM NAME                 :  menu                                               */
/* MODULE NAME                    :  menu                                               */
/* LANGUAGE                       :  C                                                  */
/* TARGET ENVIRONMENT             :  ANY                                                */
/* DATE OF FIRST RELEASE          :  2017/10/                                           */
/* DESCRIPTION                    : This is a menu program                              */
/****************************************************************************************/

/*
 * Revision log
 * 
 * Created by XT, 2017/10/1
 */

//#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

#define CMD_MAX_LEN 128
//#define DESC_LEN    1024
//#define CMD_NUM     10

int Help();
int Quit();
int Yoo();

static tDataNode head[] = 
{
    {"help", "this is the help cmd!", Help, &head[1]},
    {"version", "menu program v1.0", NULL, &head[2]},
    {"quit", "quit this program", Quit, &head[3]},
    {"boynextdoor", "you like that ah", NULL, &head[4]},
    {"van", "boy♂next♂door", NULL, &head[5]},
    {"Van", "the deep♂dark♂fantasies", NULL, &head[6]},
    {"Van-Darkholme", "oh♂swallow my", NULL, &head[7]},
    {"billy", "you got me mad now", NULL, &head[8]},
    {"Billy", "oh my♂shoulder", NULL, &head[9]},
    {"Billy-Herrington", "ASS♂WE♂CAN", NULL, &head[10]},
    {"Mark-Wolff", "I'll show you who's the boss of this qym", NULL, &head[11]},
    {"others", "nuh nuh nuh", Yoo, NULL}
};

int main()
{
    /* cmd line begins */
    while (1) 
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if (p == NULL)
        {
            printf("This is a wrong cmd!\n");
        }
    }
    return 0;
}

int Help() 
{
    ShowAllCmd(head);
    return 0;
}

int Quit()
{
    exit(0);
}

int Yoo()
{
    printf("YOOOOOOOOOOOOOOOOOO\n");
    return 0;
}
