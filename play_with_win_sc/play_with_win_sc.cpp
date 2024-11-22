// g++ -g -o play_with_win_sc.exe play_with_win_sc.cpp
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <io.h>

void vuln() {
    char buf[0x100];
    void* exec_mem = VirtualAlloc(NULL, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!exec_mem) {
        printf("Memory allocation failed: %lu\n", GetLastError());
        exit(-1);
    }
    printf("Memory allocated at: %p\n", exec_mem);
    printf("Enter your shellcode: ");
    _read(0, buf, sizeof(buf));
    memcpy(exec_mem, buf, sizeof(buf));
    printf("Executing shellcode...\n");
    ((void(*)())exec_mem)();
    Sleep(10000);
    VirtualFree(exec_mem, 0, MEM_RELEASE);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Welcome to the Shellcode Lab!\n");
    vuln();
    return 0;
}