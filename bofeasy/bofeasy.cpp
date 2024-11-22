//g++ -g -o bofeasy.exe bofeasy.cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <io.h>

void l33t() {
    puts("Congrat !");
    WinExec("cmd.exe", 0);
}

int main() {
    srand((unsigned int)time(NULL));
    if ((rand() & 0xffff) == 0xddaa) {
        l33t();
    }
    char buf[0x30];
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("main: %p\n", &main);
    printf("Input: ");
    _read(0, buf, 0x100);
    return 0;
}