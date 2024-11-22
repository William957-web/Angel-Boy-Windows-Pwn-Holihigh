//g++ -g -o ret2lib.exe ret2lib.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

void See_something(unsigned long long addr) {
    unsigned long long* address;
    address = (unsigned long long*)addr;
    printf("The content of the address : %p\n", *address);
};

char name[20];

char* getname(char* username) {
    return strdup(name);
}

int main() {
    printf("Main:%p\n", &main);
    setvbuf(stdout, 0, _IONBF, 0);
    char address[20];
    char message[256];
    unsigned long long addr = 0;
    puts("###############################");
    puts("Do you know return to library ?");
    puts("###############################");
    printf("Name:");
    read(0, name, 20);
    puts("What do you want to see in memory?");
    printf("Give me an address (in hex) :");
    read(0, address, 20);
    addr = strtoll(address, 0, 16);
    See_something(addr);
    printf("Leave some message for me :");
    read(0, message, 0x400);
    printf("%s\n", message);
    puts("Thanks you");
    getname(name);
    return 0;
}