/*
# wc -l /path/to/file(s) 
# Принимает несколько aргументов-путей к файлам
# Выдаёт текст-ошибку если не удалось открыть файл(ы)
# В остальном вывод как у wc
*/


#include <stdio.h>

int main (int argc, char* argv[]) {
    if (argc == 1) {
        puts ("Error: enter filename(s) as argument(s)\n");
        return 1;   
    }
    int total=0;
    for (int i=1; i<argc; i++) {
        FILE *iFile;
        iFile = fopen (argv[i], "r");
        if (!iFile) {
            printf ("Error: %s: Can't open file\n", argv[i]);
            continue;
        }
        int Lines = 0;
        char buf = 'c';
        do {
            buf = fgetc (iFile);
            if (buf == '\n')
                ++Lines;
        }
        while (buf != EOF);
        printf ("%d %s\n", Lines, argv[i]);
        total+=Lines;
    }
    if (argc>2)
        printf ("%d total\n", total);
    return 0;    	
}
