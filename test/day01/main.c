#include "1.h"

int main(){
    struct arg getShow;
    int a[length];
    urand(a,length);
    show(a,length);
    getResult(a,length);
    //getShow = getResult(a,length);
    sort(a,length);
    show(a,length);
    writeData(a,length,randData);
    readData(a,length,randData);
}
