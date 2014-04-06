#include "FileParse.h"
#include "FileRevert.h"
#include "FileCompress.h"
#include "FilePack.h"
#define tmpDir "tmp\\\0"

//#define DEBUG
int main(int argc, char **argv)
{
    FileParse file(argc, argv);
    printf("%d argument(s)\n", argc - 1);
    for (int i = 0; i < argc; i++) printf("%s\n", argv[i]);
    file.pathStore();
    printf("%d Files detected.\n", file.fileNum);
#ifdef DEBUG
    printf("Main: %d %d\n", file.fileInfo, sizeof(miniFileInfo));
    for (int i = 0; i < file.fileNum; i++)
        printf("%d: %s %d\n", i, file.fileInfo[i].fileName, file.fileInfo[i].fileSize);
#endif // DEBUG
    //FileCompress cps(tmpDir, file.fileInfo, file.fileNum);

    FilePack cpk(tmpDir, file.fileInfo, file.fileNum);
    cpk.packAll("pack.517");
    //FilePack cpk1(tmpDir, file.fileInfo, file.fileNum);
    //cpk1.unpackAll("pack.517");
    //FileRevert tmp("tt", tmpDir, file.fileInfo, file.fileNum);
    //tmp.createAllFile();
    return 0;
}
