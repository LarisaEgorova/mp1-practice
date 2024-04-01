#pragma once

#include "Klass.h"

void quick_sort(Student* arrs, int* support, int len, int left, int right);
void selection_sort(FIO* arrs, int* support, int len);
ifstream work_with_base();
int check_base();
int* append_klassmass(ifstream& in, int count, int klases, Student& s, Klass& Kmass);
void separate_klassmass(int* quantity, Klass* Lib, Klass Kmass, int klases, int count);
int* sorted_klases(int* quantity, int* support, Klass* Lib, int choice);
void first_inf_sort(Klass* Lib, int* quantity, int* support, int choice);
void first_inf_nosort(Klass* Lib, int* quantity, int choice);
void menu(Klass* Lib, int* quantity, int klases);