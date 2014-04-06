#include "FileParse.h"

FileParse :: FileParse(int _argc, char **_argv)
{
    argc = _argc;
    argv = _argv;
    parsed = false;
    fileNum = 0;
    _getcwd(FullPathPre, MAXLEN);
    strcat(FullPathPre, "\\");
    isDir = new int[argc];
    printf("Construction: %d\n", sizeof(miniFileInfo));
}
FileParse :: ~FileParse()
{
    delete []isDir;
    delete []fileInfo;
}
bool FileParse :: dirList(LPCSTR Path, int mode)
{
    WIN32_FIND_DATA FindData;
    HANDLE hError;
    char FilePathName[MAXLEN];
    char FullPathName[MAXLEN];
    strcpy(FilePathName, Path);
    strcat(FilePathName, "\\*.*");
    hError = FindFirstFile(FilePathName, &FindData);
    if (hError == INVALID_HANDLE_VALUE) return 0;

    while(::FindNextFile(hError, &FindData))
    {
        if (strcmp(FindData.cFileName, ".") == 0
                || strcmp(FindData.cFileName, "..") == 0 )
            continue;

        wsprintf(FullPathName, "%s\\%s", Path, FindData.cFileName);

        if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            dirList(FullPathName, mode);
        else
        {
            if (mode == 1)
            {
                fileInfo[fileNum].fileSize = 0;
                strcpy(fileInfo[fileNum].fileName, FullPathName);
            }
            fileNum++;
        }
    }
    return 1;
}

int FileParse :: countNum()
{
    if (argc < 2)
    {
        printf("No File!");
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        isDir[i] = 1;
        if (!dirList(argv[i]))
        {
            isDir[i] = 0;
            if (_access(argv[i], 0) != -1) fileNum++;
            else
            {
                isDir[i] = -1;
                printf("No File/Folder: %s\n", argv[i]);
            }
        }
    }
}

int FileParse :: pathStore()
{
    countNum();
    fileInfo = new miniFileInfo[fileNum];
    printf("%d %d\n", fileInfo, sizeof(miniFileInfo));
    fileNum = 0;
    for (int i = 1; i < argc; i++)
        if (isDir[i] >= 0)
        {
            if (isDir[i] == 1) dirList(argv[i], 1);
            else
            {
                if (_access(argv[i], 0) != -1)
                {
                    strcpy(fileInfo[fileNum].fileName, argv[i]);
                    fileNum++;
                }
            }
        }
    return fileNum;
}
