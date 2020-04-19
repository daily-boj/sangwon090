#include <stdio.h>

int main() {
    char keymap[128] = {1, };
    keymap['1'] = '`'; keymap['2'] = '1'; keymap['3'] = '2'; keymap['4'] = '3'; keymap['5'] = '4'; keymap['6'] = '5'; keymap['7'] = '6'; keymap['8'] = '7'; keymap['9'] = '8'; keymap['0'] = '9'; keymap['-'] = '0'; keymap['='] = '-';
    keymap['W'] = 'Q'; keymap['E'] = 'W'; keymap['R'] = 'E'; keymap['T'] = 'R'; keymap['Y'] = 'T'; keymap['U'] = 'Y'; keymap['I'] = 'U'; keymap['O'] = 'I'; keymap['P'] = 'O'; keymap['['] = 'P'; keymap[']'] = '['; keymap['\\'] = ']';
    keymap['S'] = 'A'; keymap['D'] = 'S'; keymap['F'] = 'D'; keymap['G'] = 'F'; keymap['H'] = 'G'; keymap['J'] = 'H'; keymap['K'] = 'J'; keymap['L'] = 'K'; keymap[';'] = 'L'; keymap['\''] = ';';
    keymap['X'] = 'Z'; keymap['C'] = 'X'; keymap['V'] = 'C'; keymap['B'] = 'V'; keymap['N'] = 'B'; keymap['M'] = 'N'; keymap[','] = 'M'; keymap['.'] = ','; keymap['/'] = '.';
    keymap[' '] = ' ';

    char input;
    while((input = getchar()) != EOF) {
        if(input == '\n')
            printf("\n");
        else
            printf("%c", keymap[input]);
    }

    return 0;
}