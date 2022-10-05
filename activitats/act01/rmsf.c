#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <pwd.h>

#define PATH_MAX_LEN 100

char* setupTrash();
void moveToTrash(char *trashDir, char *fileOrDirectory, char baseDir[PATH_MAX_LEN]);

int main(int argc, char const *argv[]) {
    //Get trash directory or create it
    char *trashDirectory = setupTrash();

    //Get current working directory
    char currentDir[PATH_MAX_LEN];
    getcwd(currentDir, sizeof(currentDir));

    //Parse input
    for(int i = 1; i < argc; i++) {
        moveToTrash(trashDirectory, argv[i], currentDir);
    }

    return 0;
}

char* setupTrash(){
    struct passwd *pw = getpwuid(getuid());
    const char *trashDir = pw->pw_dir;
    const char trashName[] = "/.trash/";

    strcat(trashDir, trashName);

    DIR *dir = opendir(trashDir);
    if (!dir && ENOENT == errno)
        if(mkdir(trashDir, 0777) != 0)
            printf("Error ocurred while creating folder!\n");
    else
        printf("Undefined error!");

    return trashDir;
}

void moveToTrash(char *trashDir, char *fileOrDirectory, char baseDir[PATH_MAX_LEN]) {
    printf("Safely deleting %s...\n", fileOrDirectory);
    char newLocation[PATH_MAX_LEN];
    strcpy(newLocation, trashDir);
    strcat(newLocation, fileOrDirectory);
    rename(fileOrDirectory, newLocation);
}