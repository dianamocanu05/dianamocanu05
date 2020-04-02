#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
ifstream fin("data.in");


template<typename T>
class Vct
{
private:
    static const int capacity=10000;
    T vec[capacity];
    int length=0;
public:
    Vct()
    {
        //capacity=cap;
        T*vec=new T[capacity];
    }
    int GetLength()
    {
        return length;
    }
    void Push(T val)
    {
        /*if(length>=capacity)
            capacity*=2;*/
        vec[length]=val;
        length++;
    }
    void Insert(int index,T val)
    {
        length++;
        for(int i=length; i>index; i--)
            vec[i]=vec[i-1];
        vec[index]=val;
        /*if(length>=capacity)
            capacity*=2;*/

    }
    void Print()
    {
        for(int i=0; i<length; i++)
            cout<<vec[i]<<' ';
        cout<<endl;
    }
    void Sort()
    {
        for(int i=0; i<length-1; i++)
            for(int j=i+1; j<length; j++)
            {
                if(vec[i]>vec[j])
                    swap(vec[i],vec[j]);
            }
    }
    int FindFirstOf(T val)
    {
        for(int i=0; i<length; i++)
            if(vec[i]==val)
            {
                return i;
            }
        return -1;
    }
    void Remove(int index)
    {
        if(length>=1)
        {
            for(int i=index;i<length;i++)
                vec[i]=vec[i+1];
            length--;
        }
    }


};


int main()
{
    //reading the input
    Vct<int> arr;
    int n;
    char command[50];
    int number=0;
    fin>>n; //to be transformed to cin
    fin.get();
    for(int i=0; i<n; i++)
    {
        fin.getline(command,'/n');
        //cout<<command<<endl;
        if(command[0]=='i') //insert
        {
            int i1,i2;
            int ok=0;
            for(int i=0; i<strlen(command); i++)
            {
                if(command[i]==' ')
                {
                    if(ok==0)
                    {
                        i1=i;
                        ok++;
                    }
                    else if(ok==1)
                        i2=i;
                }
            }
            int number1=0,number2=0;;
            int p10=1;
            for(int k=i2-1; k>i1; k--)
            {
                int c=command[k]-'0';
                number1+=c*p10;
                p10*=10;
            }
            p10=1;
            for(int k=strlen(command)-1; k>i2; k--)
            {
                int c=command[k]-'0';
                number2+=c*p10;
                p10*=10;
            }
            arr.Insert(number1,number2);

        }
        else
        {
            for(int i=0; i<strlen(command); i++)
            {

                if(command[i]==' ')
                {
                    int p10=1;
                    number=0;
                    for(int j=strlen(command)-1; j>i; j--)
                    {

                        int c=command[j]-'0';
                        number+=c*p10;
                        p10*=10;
                    }
                    break;
                }
            }
            if(command[0]=='p' && command[1]=='u')
            {
                arr.Push(number);
            }
            else if(command[0]=='p' && command[1]=='r')
            {
                arr.Print();
            }
            else if(command[0]=='s')
            {
                arr.Sort();
            }
            else if(command[0]=='f')
            {
                cout<<arr.FindFirstOf(number)<<endl;
            }
            else if(command[0]=='r')
            {
                arr.Remove(number);
            }
        }
    }



    return 0;

}
