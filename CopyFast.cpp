#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include "CopyFast.h"

using namespace std;

FILE *tmp_file = fopen("tmpfile.tmp", "w");

int size_origin_file = 0;
int size_target_file = 0;

int strsize(char *str)
{
  int i = 0;
  while(str[i++] != '\0'){}
  return (i);
}

int filesize(char *f_name)
{
  char c[100];
  FILE* f = fopen(f_name, "r");
  int k = 0;
  while(fgets(c, sizeof c, f))
    {
      k++;
    }
  return (k);
}

// x^y
int pow(int x, int y)
{
  int i = 1, k = x;
  for(i; i < y; i++)
    {
      x*= k;
    }
  return x;
}

int StrToInt(char *str)
{
  if(str[0] == '\0')
    {
      return (-1);
    }
  int k = 0;
  int i = 0;
  int p = pow(10, strsize(str) - 1); 
  while(str[i] != '\0'){
    if(str[i] > 47 && str[i] < 58)
      {
	k += (str[i++] - 48) * p;
	p /= 10;
      }
    else
      {
	cout << "'" << str << "' isn't a number" << endl;
	return -1;
      }
  }
  return (k/10);
}

//write the content of filename from x to y to tmpfile 
void write_file(FILE *f, int x, int y)
{
  char line[1000];
  int k = 0;
  for(k; k < x && fgets(line, sizeof line, f); k++);
  for(k; k < y && fgets(line, sizeof line, f); k++)
    {
      printf("%s\n", line);
      fputs(line, tmp_file);
    }
}

int error(FILE *origin_f, FILE *target_f, int l1, int l2, int l3)
{
  if(l1 == -1 || l2 == -1 || l3 == -1)
    return -1;
  if(l1 > size_origin_file || l2 > size_origin_file || l3 > size_target_file)
    { 
      printf("lines must not be out of the files");
      return -1;
    }
  if(l1 > l2)
    {
      cout << "'" << l2 << "' doesn't be sup than '" << l1 << "'" << endl;
      return -1;
    }
  if(origin_f == NULL)
    {
      std::cout << "origin file doesnt exist" << endl;
      return -1;
    }
  if(target_f == NULL)
    {
      std::cout << "target file doesnt exist" << endl;
      return -1;
    }
  return 0;
}

//Algorithm
//make tmp file
//write in tmpfile: read target_f [0; l3[
//write in tmpfile: read origin_f [l1; l2]
//write in tmpfile: read target_f [l3; EoF[
//rename tmp file: target_f
void file_copy(char *origin_f, char *l_1, char *l_2, char *target_f, char *l_3)
{     
  int l1 = StrToInt(l_1), l2 = StrToInt(l_2), l3 = StrToInt(l_3); 
  FILE *origin_file = fopen(origin_f, "r");
  FILE *target_file = fopen(target_f, "r");
  size_origin_file = filesize(origin_f);
  size_target_file = filesize(target_f);
  if(error(origin_file, target_file, l1, l2, l3) == -1)
    return;
  write_file(target_file, 0, l3);
  write_file(origin_file, l1, l2);
  write_file(target_file, l3+1,  size_target_file);
  rename("tmpfile.tmp", target_f);
  fclose(origin_file);
  fclose(target_file);
  fclose(tmp_file);
}
