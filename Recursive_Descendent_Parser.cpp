/*

Rafiqul Islam



*/


#include<iostream>
#include<cstdio>

using namespace std;

/*
    Given, Grammar
        E->E+F|F
        F->0|1


*/


//Initialization and Function Prototype Declaration
void E();
void F();
bool match(char a);
int res=false;
bool FLAG=false;
char ch;
char arr[1000];
int i=0;



//Main Function
int main()
{
    cout<<"Input a string. At the end of the string press $(dollar) sign for example: 1+1$\n";
    gets(arr);
    //Call Function E()
    E();

    ch=arr[i];

    if(ch=='$' && FLAG==true)
        cout<<"The string Match\n";
    else
        cout<<"The string Does not Match\n";

}

// E() function
void E()
{
    // Take one Character
    ch= arr[i];

   //If First Character is 1
   if(ch=='1')
        {
            //If Match 1 then Check + sign
            res=match('1');
            if(res==true)
            {
                //cout<<"match 1\n";
                i++;
                ch=arr[i];
                res= match('+');

                //If Match + sign
                 if(res==true)
                 {
                    //cout<<"match +\n";
                    i++;
                    ch= arr[i];
                        if( (arr[i]=='1' || arr[i]=='0') && arr[i+1]=='$' )
                        {
                            F();
                        }

                         else
                             E();
                 }


             }
        }

        // If First Character is 0
        else if(ch=='0')
        {
            res=match('0');
            if(res==true)
            {
                //cout<<"match 0\n";
                i++;
                ch=arr[i];
                res= match('+');
                 if(res==true)
                 {
                    //cout<<"match +\n";
                    i++;
                    ch= arr[i];
                        if( (arr[i]=='1' || arr[i]=='0') && arr[i+1]=='$' )
                        {
                            F();
                        }

                        else
                            E();
                 }


             }
        }
}



//Function F()

void F()
{
    ch=arr[i];
        //if character is 1
         if(ch=='1')
        {

        res=match('1');

        if(res==true)
        {
            //cout<<"match 1\n";
            i++;
            FLAG=true;

        }
        else

            FLAG=false;

        }

         else if(ch=='0')
        {

         res=match('0');

        if(res==true)
        {
            //cout<<"match 0\n";
            i++;
            FLAG=true;
        }
        else
            FLAG=false;

        }

        else
        {
            FLAG=false;
        }

}


//Match Function
bool match(char lookahead)
{
    if(lookahead==arr[i])
    {

        return true;
    }
    else
        return false;

}


