#pragma once

#include "Klass.h"
#include <Windows.h>

int work_base(Klass** Klassmass);
void first_inf_nosort(Klass* Klassmass, int choice);
void first_inf_sort(Klass* Klassmass, int* support, int choice);
void sorted_klases(int* support, Klass* Klassmass, int choice);
void menu(Klass* Klassmass, int klases);
int work_this_files(int klases, Klass* Klass);
void append_students(Klass* Klass, char* str, FILE* f);