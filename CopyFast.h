#ifndef COPYFAST_H
#define COPYFAST_H
void file_copy(char *origin_f, char *l1, char *l2, char *target_f, char*l3);
int StrToInt(char *str);
int strsize(char *str);
int pow(int x, int y);
int erro(FILE *origin_f, FILE *target_f, int l1, int l2, int l3);
void write_file(char* filename, int x, int y);
#endif
