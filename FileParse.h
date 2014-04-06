#ifndef FILEPARSE_H_INCLUDED
#define FILEPARSE_H_INCLUDED

#include "FileInfo.h"

class FileParse
{
public:
    FileParse(int _argc, char **_argv);
    ~FileParse();

    int pathStore();
    int fileNum;
    bool parsed;
    miniFileInfo *fileInfo;
    char FullPathPre[MAXLEN];

private:
    int argc;
    char** argv;
    bool dirList(LPCSTR Path, int mode = 0);
    int countNum();
    int *isDir;
};

#endif // FILEPARSE_H_INCLUDED
