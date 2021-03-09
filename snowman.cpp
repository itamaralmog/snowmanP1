#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <array>
#include <exception>
#include "snowman.hpp"
#include <algorithm>
using namespace std;
namespace ariel{
string snowmanp(int arrsnow[],int l){
    const int o0=0,o1=1,o2=2,o3=3;
    const int o4=4,o5=5,o6=6,o7=7;
    array<string,o4> h ={"_===_\n"," ___\n .....\n","  _  \n  /_\\ \n"," ___ \n (_*_)\n"};
    array<string,o4> n ={",",".","_"," "};
    array<string,o4> le={".","o","O","-"};
    array<string,o4> re={".","o","O","-"};
    array<string,o4> la={">","/","\\",""};
    array<string,o4> ra={"<","\\","/",""};
    array<string,o4> t ={" : ","] [","> <","   "};
    array<string,o4> b ={" : ","\" \"","___","   "};
    string hat = h[arrsnow[o0]-1];
    string nose = n[arrsnow[o1]-1];
    string leye = le[arrsnow[o2]-1];
    string reye = re[arrsnow[o3]-1];
    string rarm = ra[arrsnow[o4]-1];
    string larm = la[arrsnow[o5]-1];
    string tors = t[arrsnow[o6]-1];
    string base = b[arrsnow[o7]-1];
    string sm;
    if(arrsnow[o4]==4&&arrsnow[o5]==4){// no right arm and left
       sm = hat+"("+leye+nose+reye+")"+"\n"+"("+tors+")"+"\n"+"("+base+")";
    }
    if(arrsnow[o4]==4&&arrsnow[o5]!=4){// no right arm 
        if(arrsnow[o5]==2){
           sm = hat+"("+leye+nose+reye+")"+larm+"\n"+"("+tors+")"+"\n"+"("+base+")"; 
        }
        else{
            sm = hat+"("+leye+nose+reye+")"+"\n"+"("+tors+")"+larm+"\n"+"("+base+")";
        }
    }
    if(arrsnow[o4]!=4&&arrsnow[o5]==4){// no left arm
        if(arrsnow[o4]==2){
            sm = " "+hat+rarm+"("+leye+nose+reye+")"+"\n"+" "+"("+tors+")"+"\n"+" "+"("+base+")";
        }
        else {
            sm = " "+hat+" "+"("+leye+nose+reye+")"+"\n"+rarm+"("+tors+")"+"\n"+" "+"("+base+")";
        }
    }
    if(arrsnow[o4]!=4&&arrsnow[o5]!=4){//there is 2 hands
        if(arrsnow[o4]==2&&arrsnow[o5]==2){//2 hands up
           sm = " "+hat+rarm+"("+leye+nose+reye+")"+larm+"\n"+" "+"("+tors+")"+"\n"+" "+"("+base+")"; 
        }
        if(arrsnow[o4]==2&&arrsnow[o5]!=2){//right up
            sm = " "+hat+rarm+"("+leye+nose+reye+")"+"\n"+" "+"("+tors+")"+larm+"\n"+" "+"("+base+")";
        }
        if(arrsnow[o4]!=2&&arrsnow[o5]==2){//left up
            sm = " "+hat+" "+"("+leye+nose+reye+")"+larm+"\n"+rarm+"("+tors+")"+"\n"+" "+"("+base+")";
        }
        if(arrsnow[o4]!=2&&arrsnow[o5]!=2){//no up
            sm = " "+hat+" "+"("+leye+nose+reye+")"+"\n"+rarm+"("+tors+")"+larm+"\n"+" "+"("+base+")";
        }
    }
    return sm;
}

string snowmann(int forsnow){
    const int ACTION=8,o10=10;//just becous magic numbers
    int arrsnow[ACTION];
    int n = forsnow;
    for(int i = 0 ; i < ACTION ; ++i){
        int s = n%o10;
        n/=o10;
        if(s == 0 || s > 4 ){
            throw std::out_of_range{"every digit must be bitween 1 and 4"};
            cout << "cant make snowman " << endl;
            return "cant make snowman"; 
        }
        arrsnow[ACTION-1-i]=s;
    }
    return snowmanp(arrsnow,ACTION);
}
string snowman(int forsnow){
    const int SNSTART=11111111,SNSEND=44444444;//the limit of the numbers else throw exeption.
    if(forsnow < SNSTART || forsnow > SNSEND ){
        throw std::out_of_range{"number must be bitween 1111111 and 4444444"};
        return "cant make snowman";
    }
    return snowmann(forsnow);
}
}
