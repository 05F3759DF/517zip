#ifndef FILEREVERT_H_INCLUDED
#define FILEREVERT_H_INCLUDED

#include "FileInfo.h"
class FileRevert
{
public:
    FileRevert(char *, char*, miniFileInfo *, int);
    int createAllFile();
    miniFileInfo *fileInfo;
private:
    char parentDir[MAXLEN], bufDir[MAXLEN];
    int fileNum;
    SECURITY_ATTRIBUTES attribute;
    bool makeAllPath(char *);
};

#endif // FILEREVERT_H_INCLUDED
