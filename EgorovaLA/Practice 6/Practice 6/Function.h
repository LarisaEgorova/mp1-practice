#pragma once

#include "Journal.h"
#include <Windows.h>

int work_with_base(int klases, string* massfile);
void append_klassmass(string* massfile, Journal& Kmass);
int* sorted_klases(int* support, Journal& Kmass, int choice);
void menu(Journal& Kmass);