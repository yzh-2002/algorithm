<<<<<<< HEAD
#include "linear_table.hpp"
=======
#include "SeqList.hpp"
>>>>>>> 436bcd83a709d152c685c2eb30cce9ff0ef5a578

int main(){
    SeqList<int> seq(10);
    seq.input();
    seq.output();
    int m = 0;
    seq.Remove(2,m);
    seq.output();
}