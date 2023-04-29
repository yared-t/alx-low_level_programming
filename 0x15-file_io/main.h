#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters);
void check(unsigned char *i);
void m(unsigned char *i);
void fun(unsigned char *i);
void d(unsigned char *i);
int create_file(const char *filename, char *text_content);
void update(unsigned char *i);
void os(unsigned char *i);
void type(unsigned int t, unsigned char *i);
void entyr(unsigned int e, unsigned char *i);
int append_text_to_file(const char *filename, char *text_content);
#endif
