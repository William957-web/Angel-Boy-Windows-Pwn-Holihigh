//g++ -g -o Winmagic.exe .\Winmagic.cpp -fpermissive
#include <iostream>
#include <io.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <cstdint>

void get_flag2() {
    const char key[] = "Do_you_know_why_my_teammate_Orange_is_so_angry?";
    char cipher[] = {
        '\x02', '#', '\x1e', '>', '\x14', '"', '6', '\x05', '\n', '\r',
        '\x10', '\x00', '\x1e', '\x1b', '&', 'k', '\x01', '\n', '0', '+',
        '\x13', '\x04', '\x1f', '\x14', '>', '\x1c', '\x00', '3', '?', '4',
        '\x14', '\x02', '8', '#', '0', '\x1b', ',', '-', '@', '\x19',
        'l', '\x13', '\x1d', '\x0e', '\x1c', '\x1e', 'B'
    };

    for (size_t i = 0; i < sizeof(cipher); i++) {
        printf("%c", cipher[i] ^ key[i]);
    }
    getchar();
}

void get_flag3() {
    const char key[] = "Do_you_know_why_my_teammate_jeffxx_is_so_angry??????????";
    char cipher[] = {
        '\x02', '#', '\x1e', '>', '\x14', '6', '0', '\x05', '\n', '\x06',
        '\x03', 'n', '\x18', '\x06', '&', '=', '\x1f', '\x1c', '>', '\x1f',
        '\x15', 'Q', '\x04', '\x03', '\x15', '\x07', ':', 'k', '\x18', 'V',
        '9', '\x05', '\x17', '\x16', ')', '\x0c', '\x1d', '6', '\x16', '\x01',
        '+', '>', '\x07', '\t', '-', '\x0b', 'Z', '^', 'S', '`',
        'H', '\x0f', 'M', 'S', '[', 'B'
    };

    for (size_t i = 0; i < sizeof(cipher); i++) {
        printf("%c", cipher[i] ^ key[i] ^ rand());
    }
    getchar();
}

void get_flag() {
    int password;
    int magic;
    srand((unsigned int)time(NULL));

    const char key[] = "Do_you_know_why_my_teammate_ddaa_is_so_angry??????";
    const char cipher[] = {
        '\x02', '#', '\x1e', '>', '\x14', '"', '6', '\x05', '*', '\r',
        '\x10', '\x00', '\x1e', '\x1b', '&', ')', '\x08', '\x0b', '&', '+',
        '\x0c', '\x0c', '\x1d', '\x02', '\x13', '\x00', '\x04', '1', '\x10', ';',
        'P', '\x0f', '\x00', '\x1e', '\x1a', '1', '\x17', '\x00', '(', '\x12',
        '1', '\x14', 'A', '\x1a', 'J', 'M', 'V', 'K', 'F', 'B'
    };

    password = rand();
    printf("Give me magic: ");
    scanf_s("%d", &magic);

    if (password == magic) {
        printf("Success!!!\n");
        for (size_t i = 0; i < sizeof(cipher); i++) {
            printf("%c", cipher[i] ^ key[i]);
        }
    } else {
        printf("Failed. QQ\n");
    }
    getchar();
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    get_flag();

    if ((std::uintptr_t)&main == 0xddaa) {
        get_flag2();
        get_flag3();
    }

    return 0;
}