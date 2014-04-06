#include "FileCompress.h"

FileCompress :: FileCompress(char *_buf, miniFileInfo *_fileInfo, int _fileNum)
{
    strcpy(bufDir, _buf);
    fileInfo = _fileInfo;
    fileNum = _fileNum;
    SECURITY_ATTRIBUTES attribute;
    attribute.nLength = sizeof(attribute);
    attribute.lpSecurityDescriptor = NULL;
    attribute.bInheritHandle = FALSE;
    CreateDirectory(bufDir, &attribute);
    for (int i = 0; i < fileNum; i++)
    {
        printf("~%s\n", fileInfo[i].fileName);
        compressMono(fileInfo[i].fileName, i);
    }
}

bool FileCompress :: compressMono(char *fileName, int n)
{
    FILE *fin, *fout;
    char bufName[MAXLEN], ss[MAXLEN];
    strcpy(bufName, bufDir);
    sprintf(ss, "%d", n);
    strcat(bufName, ss);
    fin = fopen(fileName, "rb");
    fout = fopen(bufName, "wb");
    char t;
    while (fread(&t, sizeof(char), 1, fin))
        fwrite(&t, sizeof(char), 1, fout);
    fclose(fin);
    fclose(fout);
	return true;
}

