#include "Global.h"
#include "DPLL.cpp"
extern void CreateSudokuProblem(int empty_number);

using namespace std;
int main() {
  std::cout << "Hello, CNF!" << std::endl;
  cout << "Please choose the function u want to use." << endl;
  cout << "����" << "<1> : sudoku solving (generated by random, u only need to enter the number of the empty blocks)"
       << "����" << endl;
  cout << "����" << "<2> : DPLL for SAT (the content u need to input, such as test.cnf)" << "����" << endl;
  cout << "����" << "<0> : quit." << "����" << endl;
  char commend;
  clock_t StartTime, EndTime;
  scanf("%c", &commend);
  getchar();
  if (commend == '1') {
    int number;
    printf("input the the number of the empty blocks.\n");
    scanf("%d", &number);
    CreateSudokuProblem(number);
    SATSolverDPLL dpll;
    dpll.init2();
    StartTime = clock();
    dpll.solve();
    EndTime = clock();
    cout << "T " << (double) (EndTime - StartTime) / CLOCKS_PER_SEC * 1000.0 << " ms\n";
    dpll.show_sudoku();
  } else if (commend == '2') {
    SATSolverDPLL dpll;
    dpll.init1();
    StartTime = clock();
    dpll.solve();
    EndTime = clock();
    cout << "T " << (double) (EndTime - StartTime) / CLOCKS_PER_SEC * 1000.0 << " ms\n";
  } else {
    cout << "Please try again." << endl;
  }
  return 0;
}