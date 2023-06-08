#include "linear_table.hpp"

int main(){
    SeqList<int> seq(10);
    seq.input();
    seq.output();
    int m = 0;
    seq.Remove(2,m);
    seq.output();
}