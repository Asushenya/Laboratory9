#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

template<class universalType>
class Array
{
private:
    universalType *array;
    int sizeOfArray = 0;
public:
    class Exeption{};
    class BadIndex:public Exeption{};
    class Little_Index :public BadIndex
        {
        private :
            int index;
        public : 
            Little_Index(int smallindex) : index(smallindex) {};
            void what()
            {
                cerr << "index is very little '" << index << "'"<<endl;
            }
        };
    class Big_Index :public BadIndex
    {
    private:
        int index;
    public:
        Big_Index(int bigindex) : index(bigindex) {};
        void what()
        {
            cerr << "index is very big '" << index << "'"<<endl;
        }
    };
    class Bad_CIN :public Exeption {
    private:
        universalType bad_index;
    public:
        Bad_CIN(char BADINDEX) :bad_index(BADINDEX) {};
        void what()
        {
            cout << "неверно введенные данные :'" << bad_index << "'\n";
            cout << "Введите число или цифру а не символ "<<endl;
           
        }
    };

    class Bad_ptr :public Exeption
    {
        private:
            string location;
    public :

        Bad_ptr(string init) :location(init) {};

        void what()
        {
            cerr <<"Местоположение :"<<location<< ": Null ptr\n";
        }
    };
    class Zero_Division :public Exeption
    {
    public :
        void what()
        {
            cout << "Деление на 0 запрещено\n";
        }
    };

    class Bad_New :public Exeption {
    private:
        int size;
    public :
        Bad_New(int S) :size(S) {};

        void what()
        {
            cout << "Вы выделили слишком много памяти '" << size << "' допустимое значение 1000\n ";
        }
    };

    class Wrong_Symbol :public Exeption {
    private :
        universalType symbol;
        int location;
    public:
        Wrong_Symbol(universalType s, int l) : symbol(s), location(l)
        {

        }

        void what()
        {
            cout << "Введенного символа '" << symbol << "' на позиции '" << location << "' не существует\n";
        }
    };

    class Bad_FILE :public Exeption {
    private :
        char *file;
    public:
        Bad_FILE(char*File) :file(File) {};
        void what(void)
        {
            cerr << "Файл '"<<file<<"' не открыт\n";
        }
    };


   Array()
    {
        array = new universalType[1000];
    }
   Array(int size) {
       if (size > 1000) throw Array<universalType>::Bad_New(size);
       array = new universalType[1000];
   }

   Array(Array *init)
   {
    if (init) throw Array<char>::Bad_ptr("Конструктор класса Array (Array *)")
       this->array = new universalType[1000];
       for (
                   size_t i =0;
               i < init->getSizeOfArray();
                   i++
           )
       {
           this->array[i] = init->array[i];
       }
   }

   Array(const char *init)
   {
    //   if (is_null_pointer<char> &init)
       if (init == NULL) throw Array<char>::Bad_ptr("конструктор Класса Array(const char* ");
       array = new universalType[1000];

   
       for (size_t i = 0; i < strlen(init); i++)
       {
           this->add(init[i]);
       }
      
   }
    void add(universalType element)
    {
        array[sizeOfArray++] = element;
    }

    int getSizeOfArray()
    {
        return this->sizeOfArray;
    }

    void Delete(universalType elem)
    {
        int extraSzeOfArray =sizeOfArray;
        for (int i = 0;i < sizeOfArray;i++)
        {
            if (elem == array[i])
            {
                for (int j = i;j < sizeOfArray;j++)
                {
                    array[j] = array[j + 1];
                }
                sizeOfArray--;
               // return;
            }
        }
        if (sizeOfArray == extraSzeOfArray)
        cout << "i can't find this symbol\n";
    }

    void showArray(void)
    {
        if (sizeOfArray == 0)
        {
            cout << "Array is empty\n";return;
        }

        for (int i = 0;i < sizeOfArray;i++)
        {
            cout << array[i]<< " ";
        }
        cout << endl;
    }

    //overloads        +
    void operator + (universalType element)
    {
       
        this->array[sizeOfArray++] = element;
    }


    void operator+(Array a)
    {
        for (int i(0);i < a.sizeOfArray;i++)
        {
            this->add(a.array[i]);
        }
    }

    void operator+ (universalType *array)
    {
        while (*array)
        {
            this->array[sizeOfArray++] = *array++;
        }
    }
    //////////////   -
    void operator -(universalType elem)
    {
        this->Delete(elem);
    }
    /////////////   <<
    friend __readonly ostream& operator<<(ostream& out, Array& arr)
    {
        if (arr.getSizeOfArray() == 0)
            {
                cout << "array is empty\n"; return out;
            }

        if (sizeof(universalType) == 1) {
            for (int i = 0;i < arr.getSizeOfArray();i++)
            {
                out << *(arr.array + i) << "";
            }
            cout << endl;
            return out;
        }
     
          for (int i = 0;i < arr.getSizeOfArray();i++)
          {
              out << *(arr.array + i) << " ";
          }
      cout << endl;
      return out;
       
    }
    
    /////////////////    >
    bool operator >(Array a)
    {
        if (a.getSizeOfArray() != this->getSizeOfArray())
        {
            cout << "Arrays not equal Reason: SIZE ";
            if (a.getSizeOfArray() < this->getSizeOfArray())
            {
                cout << "a < this" << endl;
            }
            else cout << "this < a" << endl;
            return false;
        }

        int counter = 0;

        for (size_t i = 0; i < this->getSizeOfArray(); i++)
        {
            if (this->array[i] == a.array[counter]) 
            {
                counter++;

                if (counter == this->getSizeOfArray())
                {
                    cout << "Arrays is equal";
                    return true;
                }
            }
            else counter = 0;
        }
        cout << "Arrays is not equal: Reason_character-by-character equal\n";
        return false;
    }

    bool operator !=(Array a)
    {
        if (a.getSizeOfArray() != this->getSizeOfArray())
        {
            cout << "Arrays is not equal: size\n";
            return true;
        }
        else {
            for (size_t i = 0; i < this->getSizeOfArray(); i++)
            {
                if (this->array[i] != a.array[i])
                {
                    cout << "arrays is not equal\n";
                    return true;
                }

            }
        }
        cout << "Arrays is EQUAL\n";
        return false;
    }
    ///////////// |
    int operator | (universalType someSymbol)
    {
        if (this->getSizeOfArray() == 0) return 0;

        int counter = 0;
        for (size_t i = 0; i < this->getSizeOfArray(); i++)
        {
            if (this->array[i] == someSymbol) counter++;
        }
        return counter;
    }
    ////////////  []

    universalType operator [](int index)
    {
        if ((index >= 0) && index <sizeOfArray)
        {
            return this->array[index];
        }
        else if (index < 0) throw Array::Little_Index(index);
        else if (index > sizeOfArray) throw Array::Big_Index(index);
    }

    ///////////// >>
    friend istream& operator>> (istream& input, Array<universalType>& Adder)
    {
        if (sizeof(universalType) > 1)
        {
            int element;
          //  cin >> element;
           // if (element == -858993460) throw Array<int>::Bad_CIN(element);
            if (!(cin >> element))
            {
                cin.clear();
                throw Array<int>::Bad_CIN(element);
            }
            Adder.add(element);
     
            return input;
 }
        universalType element;
            cin >> element;
            if (!element) return input;
            Adder.add(element);
        
        return input;
    }



    template<class universalType> 
 inline  unsigned int __readonly howManySymbols(const universalType symbol) 
    {
        int counter = 0;
        for (size_t i = 0; i < this->getSizeOfArray(); i++)
        {
            if (this->array[i] == symbol) counter++;
        }
        return counter;
    }

    string whatTyeThisArray()
    {
        cout<<"This is array type of "<< typeid(*this->array).name();
       
        return typeid(this->array).name();
    }

    universalType concret_Symbol(universalType symbol, int location)
    {
        if (this->array[location] != symbol) throw Array<universalType>::Wrong_Symbol(symbol, location);
        return symbol;
    }

    void getElementFromFile(char * FILE)
    {
        ifstream Fin;
        Fin.open(FILE);
        if (!Fin) 
            throw Array<universalType>::Bad_FILE(FILE);
       // for (int q = 0;q < 5;q++)
        while(Fin)
        {
            Fin >> this->array[sizeOfArray++];
          
        }
        this->sizeOfArray--;
   }

    void showArrayAtFile(char *FILE)
    {
        ofstream Fout;
        Fout.open(FILE);


        for (size_t i = 0; i < this->sizeOfArray; i++)
        {
            Fout << this->array[i];
        }
    }

    void operator<(char*f) //выгрузка массива в файл
    {
        ofstream Fout;
        Fout.open(f);

       
        for (size_t i = 0; i < this->sizeOfArray; i++)
        {
            Fout << this->array[i];
        }
    }
};

/*template <class universalType> 
class Array<universalType>::bad_Array
{
public: 
    void what()
    {
        cerr<<"you entered wrong index '"<<
};*/