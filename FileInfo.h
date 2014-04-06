#ifndef FILEINFO_H_INCLUDED
#define FILEINFO_H_INCLUDED

#define MAXLEN 512

#include <string.h>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <direct.h>
struct miniFileInfo
{
    char fileName[MAXLEN];
    int fileSize;
};

#endif // FILEINFO_H_INCLUDED
