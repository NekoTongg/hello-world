typedef struct DataNode tDataNode;
/* add cmd to menu */
void MenuConfig(char* cmd, char* desc, void(*handler)());

/* Menu Engine Execute */
void ExecuteMenu();
