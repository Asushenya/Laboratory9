// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include <time.h>
#include <string>
#include <stdexcept>
#include <limits>
#include <fstream>

using namespace std;

int main()
{

    setlocale(0, "");
    int *p = new int (12);
    *p = 10;

    Array<int> mas(*p);
    mas + 4;
    mas + '3';
    cout << mas;
    /*
    Array<int> mas; //������������ ����� �������
    try{
        mas.getElementFromFile("2.txt");
        cout << mas;
    }
    catch (Array<int>::Bad_FILE error)
    {
        error.what();
    }*/
    
    
    /* Array<char> mas("hello");

    try {
        cout<<mas.concret_Symbol('e', 0);
    }
    catch (Array<char>::Wrong_Symbol error)
    {
        error.what();
    }*/
   

   /* try { // ���������� ��������� � ���������� ������ ��� ������
Array<int> mas(1000);
    }
    
    catch (Array<int>::Bad_New error)
    {
        error.what();
    }*/
   
   /* char * c = "Hello world"; //������� ��������� ��� ������������� �������
    c = NULL;
    try {
        Array<char> mas(c);
        Array<int> mas2;
   
    cout << mas;
    
    }
    catch (Array<char>::Bad_ptr error)
    {
        error.what();
    }*/
    
    



    /*try{  //������������ ���������� ������������� �����
        for (size_t i = 0; i < 10; i++)
        {


            cin >> mas2;
        }
        cout << mas2;
    }
    catch(Array<int>::Bad_CIN error){
        error.what();
    }*/
   
    
    /*try { //������������ ���������� �������
        cout << mas[40];
    }
    catch (Array<char>::Big_Index error)
    {
        error.what();
    }

    catch (Array<char>::Little_Index error)
    {
        error.what();
    }*/


    
    return 0;
}

