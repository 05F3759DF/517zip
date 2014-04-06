#ifndef FILECOMPRESS_H_INCLUDED
#define FILECOMPRESS_H_INCLUDED

#include "FileInfo.h"
class FileCompress
{
public:
    FileCompress(char*, miniFileInfo*, int);
private:
    miniFileInfo *fileInfo;
    int fileNum;
    char bufDir[MAXLEN];
    bool compressMono(char *, int);
};

#endif // FILECOMPRESS_H_INCLUDED
