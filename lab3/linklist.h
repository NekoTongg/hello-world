/* data struct and its operations */

typedef struct DataNode
{
    char      *cmd;
    char      *desc;
    int(*handler)();
    struct DataNode *next;
} tDataNode;

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tDataNode *head, char *cmd);

/* show all cmds in linklist */
int ShowAllCmd(tDataNode *head);
