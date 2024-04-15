#include <bits/stdc++.h>
using namespace std;

int SUDOKU_SIZE = 9;
int SUB_SUDOKU_SIZE = sqrt(SUDOKU_SIZE);

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    unordered_map<int, unordered_set<char>> cols, rows, sub_sudokus;
    bool is_in_column, is_in_row, is_in_sub_sudoku;
    int sub_sudoku_idx;

    for (int curr_row = 0; curr_row < SUDOKU_SIZE; curr_row++)
    {
      for (int curr_col = 0; curr_col < SUDOKU_SIZE; curr_col++)
      {
        char current_char = board[curr_row][curr_col];
        if (current_char == '.')
          continue;

        sub_sudoku_idx = (curr_row / SUB_SUDOKU_SIZE) * SUB_SUDOKU_SIZE + (curr_col / SUB_SUDOKU_SIZE);

        is_in_row = rows[curr_row].count(current_char);
        is_in_column = cols[curr_col].count(current_char);
        is_in_sub_sudoku = sub_sudokus[sub_sudoku_idx].count(current_char);

        if (is_in_row || is_in_column || is_in_sub_sudoku)
          return false;

        rows[curr_row].insert(current_char);
        cols[curr_col].insert(current_char);
        sub_sudokus[sub_sudoku_idx].insert(current_char);
      }
    }

    return true;
  }
};
