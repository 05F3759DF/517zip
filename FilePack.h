#ifndef FILEPACK_H_INCLUDED
#define FILEPACK_H_INCLUDED
#include "FileInfo.h"
class FilePack
{
public:
    FilePack(char*, miniFileInfo*, int);
    bool packAll(char*);
    bool unpackAll(char*);
private:
    miniFileInfo *fileInfo;
    int fileNum;
	char bufName[MAXLEN];
};

#endif // FILEPACK_H_INCLUDED
