/**
  * File Comparer using C++
  * Take two files and outputs their comparison with "ok" or "wrong"
  * No Copyright
  * Author: Md. Nabid Imteaj
  * Open Project
  * Courtesy: Zobayer Vai [zobayer.blogspot.com]
  */
#include <ctime>
#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main( int argc, char **argv ) {
	if(argc < 3) {
        printf("Usage: $ %s <file1> <file2>\n", argv[0]);
        return 1;
    }
    // status file
    ofstream fout("Cmpr");
    // inserting current time
    time_t timer = time(NULL);
    fout << ctime(&timer) << "==========================" << endl;
    fout << "Line#~Verditct~File1~File2" << endl;
    fout << "==========================" << endl;
    // adding clock
     clock_t start=clock();
    // -----------------------------------------------------
    ifstream fin1(argv[1]); // file1 output
    ifstream fin2(argv[2]); // file2 output
    // checking both files are present or not
    if(!fin1) { cerr<<"file "<<argv[1]<<" can't open"<<endl; return 2; }
	if(!fin2) { cerr<<"file "<<argv[2]<<" can't open"<<endl; return 3; }

    // declaring string
    string sf1, sf2;
    int line(0); // line count
    while( getline (fin1,sf1)) {
        getline (fin2,sf2);
        // comparing
        if (sf1.compare(sf2) != 0) {
            fout << ++line <<"."<< "~wrong~" << sf2 << "~" << sf1 << endl;
        }
        else { fout << ++line <<"."<< "~ok " << endl; }
    }
    // checking extra line
    while( getline (fin2,sf2) ) fout << "~Extra Line" << endl;
    // -------------------------------------------------------------
    // end of clock
    fout << "Runtime: "<< ((double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}
