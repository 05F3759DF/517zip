#include "FileRevert.h"

#define DEBUG

FileRevert :: FileRevert(char *_parent, char *_buf, miniFileInfo *_fileInfo, int _fileNum)
{
    strcpy(bufDir, _buf);
    strcpy(parentDir, _parent);
    fileInfo = _fileInfo;
    fileNum = _fileNum;
    printf("Revert: %d %d\n", fileInfo, sizeof(miniFileInfo));
    for (int i = 0; i < fileNum; i++)
        printf("!!%s\n", fileInfo[i].fileName);
}

int FileRevert :: createAllFile()
{
    attribute.nLength = sizeof(attribute);
    attribute.lpSecurityDescriptor = NULL;
    attribute.bInheritHandle = FALSE;
    CreateDirectory(parentDir, &attribute);
    //if (bufDir[strlen(bufDir) - 1] != '\\') strcat(bufDir, "\\");
    char sourceFile[MAXLEN], destFile[MAXLEN];
    char ss[10];
    for (int i = 0; i < fileNum; i++)
    {
        makeAllPath(fileInfo[i].fileName);
        strcpy(sourceFile, bufDir);
        sprintf(ss, "&%d", i);
        strcat(sourceFile, ss);
        strcpy(destFile, parentDir);
        strcat(destFile, "\\");
        strcat(destFile, fileInfo[i].fileName);
#ifdef DEBUG
        printf("%s-%s\n", sourceFile, destFile);
#endif // DEBUG
        bool tmp = true;
        CopyFile(sourceFile, destFile, tmp);
    }
	return 0;
}

bool FileRevert :: makeAllPath(char *_folder)
{
    char path[MAXLEN], folder[MAXLEN];
    strcpy(folder, _folder);
    strcpy(path, parentDir);
    strcat(path, "\\");
    int p = 0, p0 = 0 ;
    int len = strlen(folder);
    while (p < len)
    {
        if (folder[p] == '\\')
        {
            folder[p] ='\0';
            strcat(path, "\\");
            strcat(path, folder + p0);
            CreateDirectory(path, &attribute);
            p0 = p + 1;
        }
        p++;
    }
}
