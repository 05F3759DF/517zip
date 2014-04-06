#include "FilePack.h"

FilePack :: FilePack(char *_buf, miniFileInfo *_fileInfo, int _fileNum)
{
	strcpy(bufName, _buf);
    fileInfo = _fileInfo;
    fileNum = _fileNum;
}


bool FilePack :: packAll(char *targetName)
{
    FILE *fin, *fout;
    char t;
    int fsize;
    fout = fopen(targetName, "wb");

    fwrite(&fileNum, sizeof(int), 1, fout);
    for (int i = 0; i < fileNum; i++)
    {
        fin = fopen(fileInfo[i].fileName, "rb");
        fseek(fin, 0, SEEK_END);
        fsize = ftell(fin);
        fseek(fin, 0, SEEK_SET);
#ifdef DEBUG
        printf("%d\n", fsize);
#endif
        fileInfo[i].fileSize = fsize;
        fwrite(&fileInfo[i], sizeof(miniFileInfo), 1, fout);
        for (int j = 0; j < fsize; j++)
        {
            fread(&t, sizeof(char), 1, fin);
            fwrite(&t, sizeof(char), 1, fout);
        }
        fclose(fin);
    }
    fclose(fout);
	return true;
}

bool FilePack::unpackAll(char *sourceName)
{
    FILE *fin, *fout;
	char outputName[MAXLEN];
    char t, ss[10];
    fin = fopen(sourceName, "rb");
    fread(&fileNum, sizeof(int), 1, fin);
    printf("%d\n", fileNum);
    for (int i = 0; i < fileNum; i++)
    {
        fread(&fileInfo[i], sizeof(miniFileInfo), 1, fin);
		strcpy(outputName, bufName);
		sprintf(ss, "&%d", i);
		strcat(outputName, ss);
		fout = fopen(outputName, "wb");
        for (int j = 0; j < fileInfo[i].fileSize; j++)
		{
            fread(&t, sizeof(char), 1, fin);
			fwrite(&t, sizeof(char), 1, fout);
		}
#ifdef DEBUG
		printf("=%s %d =\n", fileInfo[i].fileName, fileInfo[i].fileSize);
#endif
    }
    fclose(fin);
	return true;
}
