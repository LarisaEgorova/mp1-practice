#pragma once

#include "Klass.h"
#include <Windows.h>



void quick_sort(FIO* arrs, int* support, int left, int right);
void selection_sort(FIO* arrs, int* support, int len);
int work_with_base(int klases, string* massfile);
void append_klassmass(string* massfile, int klases, Klass* Kmass);
int check_student(Student& s, int klases);
int* sorted_klases(int* support, Klass* Lib, int choice);
void first_inf_nosort(Klass* Lib, int choice);
void first_inf_sort(Klass* Lib, int* support, int choice);
void menu(Klass* Kmass, int klases);