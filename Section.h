#ifndef SECTION_H
#define SECTION_H

struct section {
    int start_row, start_col, end_row, end_col;
    section() : start_row(0), start_col(0), end_row(0), end_col(0) {}
    section(int start_row, int start_col, int end_row, int end_col): start_row(start_row), start_col(start_col), end_row(end_row), end_col(end_col){}
};

#endif // SECTION_H
