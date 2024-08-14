#include <iostream>
#include <cmath>
#include <list>
using namespace std;
int main()
{
    cout << "*******************************************";
    cout <<"\n******** Number System Conversions ********\n";
    cout << "*******************************************\n\n";
    
    int repeat = 0;
    while(repeat==0)
    {
    int Choice1;
    int Choice2;
    cout << "\nConvert from :" << "\n";
    cout << "1. Binary" << "\n";
    cout << "2. Octal" << "\n";
    cout << "3. Decimal" << "\n";
    cout << "4. Hexadecimal" << "\n";
    cout << "5. Exit Program" << "\n";
    cout << "-->";
    cin >> Choice1;
    
    switch (Choice1)
    {
    case 1:  
        cout << "To" << "\n";
        cout << "1. Octal" << "\n";
        cout << "2. Decimal" << "\n";
        cout << "3. Hexadecimal" << "\n";
        cout << "-->";
        cin >> Choice2;    
        break;
    case 2:    
        cout << "To" << "\n";
        cout << "1. Binary" << "\n";
        cout << "2. Decimal" << "\n";
        cout << "3. Hexadecimal" << "\n";
        cout << "-->";
        cin >> Choice2;    
        break;
    case 3:
        cout << "To" << "\n";
        cout << "1. Binary" << "\n";
        cout << "2. Octal" << "\n";
        cout << "3. Hexadecimal" << "\n";
        cout << "-->";
        cin >> Choice2;    
        break;
    case 4:
        cout << "To " << "\n";
        cout << "1. Binary" << "\n";
        cout << "2. Octal" << "\n";
        cout << "3. Decimal" << "\n";
        cout << "-->";
        cin >> Choice2;    
        break;
    case 5:
        repeat++;
        break;
    default:
        cout << "\nUnavailable Choice please try again.\n\n";
        break;
    }

    // BINARY //
    if(Choice1==1)
    {
        long long Binary_Value;
        list<int> list_Binary;
        cout << "Enter Binary Value: ";
        cin >> Binary_Value;
        int length = log(Binary_Value) / log(10);
        for (int i = 0; i <= length; i++)
        {
            list_Binary.push_front(Binary_Value % 10);
            Binary_Value /= 10;
        }
        // Check Binary Number
        try
        { 
            for(auto i : list_Binary){
                if(i>1 || i<0){
                    cout << "Error!! You didn't enter a binary value or maybe it's too long." << '\n';
                    throw(101);
                }
            }   
        }
        catch(const exception& Error)
        {
            cerr << Error.what() << '\n';
        }
        
        /*1.Binary to Octal*/
        if(Choice2==1)
        {
            list<int> result;
            if((length+1)%3 != 0)
            {
                if((length+1)%3 == 1)
                   {list_Binary.push_front(0);
                    list_Binary.push_front(0);}
                else
                    list_Binary.push_front(0);
            }
            int Distributor = 0;
            int d1, d2;
            for(auto q: list_Binary){
              if(Distributor==0){
                d1 = q*4;
                Distributor++;
              }
              else if(Distributor==1){
                d2 = q*2;
                Distributor++;
              }
              else{
                result.push_back(d1+d2+q);
                Distributor-=2;
              }
            }
            cout << "\nResult In Octal = ( ";
            for(auto r:result)
                cout << r;
            cout << " )Base8\n";
        }
    
        /*2.Binary To Decimal*/
        else if(Choice2==2)
        {
            int sum = 0;
            for(auto a:list_Binary)
            {
                sum += a*pow(2,length);
                if(length==0)
                    cout << "\nResult In Decimal = ( " << sum << " )Base10\n" << '\n';
                else
                    length--;
            }
        }

        /*3.Binary To Hexadecimal*/
        else if(Choice2==3)
        {
            if((length+1)%4 != 0)
            {
                if((length+1)%4 == 1)
                   {list_Binary.push_front(0);
                    list_Binary.push_front(0);
                    list_Binary.push_front(0);}
                else if((length+1)%4 == 2)
                    {list_Binary.push_front(0);
                     list_Binary.push_front(0);}
                else
                    list_Binary.push_front(0);
            }
            int Distributor = 0;
            int d1 , d2 , d3;
            cout << "\nResult In Hexadecimal = ( ";
            for(auto i :list_Binary)
            {
                if(Distributor==0)
                    {d1 = i*8;
                     Distributor++;}
                else if(Distributor==1)
                    {d2 = i*4;
                     Distributor++;}
                else if(Distributor==2)
                    {d3 = i*2;
                     Distributor++;}
                else
                {
                    if((d1+d2+d3+i)>=10 && (d1+d2+d3+i)<16)
                    {
                        switch (d1+d2+d3+i)
                        {
                        case 10:
                            cout << 'A';
                            break;
                        case 11:
                            cout << 'B';
                            break;
                        case 12:
                            cout << 'C';
                            break;
                        case 13:
                            cout << 'D';
                            break;
                        case 14:
                            cout << 'E';
                            break;
                        case 15:
                            cout << 'F';
                            break;
                        default:
                            break;
                        }
                    }
                    else
                        cout << d1+d2+d3+i;
                    
                    Distributor -=3;
                }       
            }
            cout << " )Base16\n";
        }
        else
            cout << "\nUnavailable choice please try again.\n";
    }

    // OCTAL //
    else if(Choice1==2)
    {                
        long long Octal_Value;
        list<int> list_Octal;
        cout << "Enter Octal Value: ";
        cin >> Octal_Value;
        int length2 = log(Octal_Value) / log(10);
        for (int i = 0; i <= length2; i++)
        {
            list_Octal.push_front(Octal_Value % 10);
            Octal_Value /= 10;
        }
        // Check Octal Number
        try
        {
            for(auto i : list_Octal)
            {
                if(i>7 || i<0)
                {   
                    cout << "Error!! You didn't enter an octal value or maybe it's too long." << '\n';
                    throw(66);
                }
            }
        }
        catch(const exception& o)
        {
            cerr << o.what() << '\n';
        }
        
        /*1.Octal To Binary*/
        /*3.Octal To Hexadecimal*/
        if(Choice2==1 || Choice2==3)
        {    
            list<int> Binary_List;
            int c = 4;
            int skip = 0;
            while(true)
            {
                for(auto i:list_Octal)
                {
                    for(int r=0; r<3 ; r++)
                    {
                        if(i/c==1)
                        {
                            Binary_List.push_back(1);
                            i-=c;
                            c/=2;
                            skip++;
                        }
                        else
                        {
                            if(skip!=0)
                                Binary_List.push_back(0);
                            c/=2;
                        }
                    }
                    c=4;
                }
                break;
            }
            
            if(Choice2==1)
            {
                cout << "\nResult In Binary = ( ";
                for(auto l:Binary_List)
                    cout << l;
                cout << " )Base2\n";
            }
            
            else if(Choice2==3)
            {
                int lengthOH = Binary_List.size();
                if((lengthOH)%4 != 0)
                {
                    if((lengthOH)%4 == 1)
                       {Binary_List.push_front(0);
                        Binary_List.push_front(0);
                        Binary_List.push_front(0);}
                    else if((lengthOH)%4 == 2)
                        {Binary_List.push_front(0);
                         Binary_List.push_front(0);}
                    else
                        Binary_List.push_front(0);
                }
                int Distributor = 0;
                int d1 , d2 , d3;
                cout << "\nResult In Hexadecimal = ( ";
                for(auto i :Binary_List)
                {
                    if(Distributor==0)
                        {d1 = i*8;
                         Distributor++;}
                    else if(Distributor==1)
                        {d2 = i*4;
                         Distributor++;}
                    else if(Distributor==2)
                        {d3 = i*2;
                         Distributor++;}
                    else
                    {
                        if((d1+d2+d3+i)>=10 && (d1+d2+d3+i)<16)
                        {
                            switch (d1+d2+d3+i)
                            {
                            case 10:
                                cout << 'A';
                                break;
                            case 11:
                                cout << 'B';
                                break;
                            case 12:
                                cout << 'C';
                                break;
                            case 13:
                                cout << 'D';
                                break;
                            case 14:
                                cout << 'E';
                                break;
                            case 15:
                                cout << 'F';
                                break;
                            default:
                                break;
                            }
                        }
                        else
                            cout << d1+d2+d3+i;
                        
                        Distributor -=3;
                    }       
                }
                cout << " )Base16\n";
            }
        }
        
        /*2.Octal To Decimal*/
        else if(Choice2==2)
        {
            int sum = 0;
            for(auto a:list_Octal)
            {
                sum += a*pow(8,length2);
                if(length2==0)
                    cout << "\nResult In Decimal = ( " << sum << " )Base10\n" << '\n';
                else
                    length2--;
            }
        }
        else
            cout << "\nUnavailable choice please try again.\n";
    }

    // DECIMAL //
    else if(Choice1==3)
    {
        long long Decimal_Value;
        cout << "Enter Decimal Value: ";
        cin >> Decimal_Value;
        int length = log(Decimal_Value) / log(10);
        try
        {
            if(Decimal_Value<0)
            {
                cout << "Error!! Enter Positive number please." << '\n';
                throw(15);
            }
            
            else if(length>16)
            {
                cout << "Error!! Number is too long." << '\n';
                throw(14);
            }  
        }
        catch(const exception& de)
        {
            cerr << de.what() << '\n';
        }
        
        /*1.Decimal To Binary*/
        if(Choice2==1)
        {
            cout << "\nResult In Binary = ( ";
            int power = 0;
            while(true)
            {
                if(Decimal_Value>=pow(2,power))
                    power++;

                else if(power==0)
                    break;

                else if(Decimal_Value<=pow(2,power))
                {
                    power--;
                    
                    if(Decimal_Value>=pow(2,power))
                    {
                        cout << 1;
                        Decimal_Value -= pow(2,power);
                    }
                    else
                        cout << 0;
                }
                
            }
            cout << " )Base2\n" << '\n';
        }

        /*2.Decimal To Octal*/
        else if(Choice2==2)
        {
            int DivResult = Decimal_Value / 8;
            int Reminder = Decimal_Value % 8;
            list<int> Result;
            while(true)
            {
                if(DivResult>=8)
                {
                    Result.push_front(Reminder);
                    Reminder = DivResult % 8;
                    DivResult /= 8;
                }
                else
                {
                    Result.push_front(Reminder);
                    Result.push_front(DivResult);
                    break;
                }
            }

            cout << "\nResult In Octal = ( ";
            for(auto i: Result)
                cout << i;
           cout << " )Base8\n";
        }

        /*3.Decimal To Hexadecimal*/
        else if(Choice2==3)
        {
            int DivResult = Decimal_Value / 16;
            int Reminder = Decimal_Value % 16;
            list<int> Result;
            while(true)
            {
                if(DivResult>=16)
                {
                    Result.push_front(Reminder);
                    Reminder = DivResult % 16;
                    DivResult /= 16;
                }
                else
                {
                    Result.push_front(Reminder);
                    Result.push_front(DivResult);
                    break;
                }
            }

            cout << "\nResult In Hexadecimal = ( ";
            for(auto i: Result)
            {
                if(i>=10 && i<=15)
                {
                    switch (i)
                        {
                        case 10:
                            cout << 'A';
                            break;
                        case 11:
                            cout << 'B';
                            break;
                        case 12:
                            cout << 'C';
                            break;
                        case 13:
                            cout << 'D';
                            break;
                        case 14:
                            cout << 'E';
                            break;
                        case 15:
                            cout << 'F';
                            break;
                        default:
                            break;
                        }
                }
                else
                    cout << i;
            }
            cout << " )Base16\n";
        }
        else
            cout << "\nUnavailable choice please try again.\n";
    }

    // HEXADECIMAL //
    else if(Choice1==4)
    {
        char Hexa_Value[6];
        list<int> List_Hexa;
        cout << "Enter Hexadecimal Value: ";
        cin >> Hexa_Value;
        
        // Check Hexa Number
        try
        {
            for(int i =0;i<=6;i++)
            {
                for(char w ='G'; w <='Z'; w++)
                {
                    if(toupper(Hexa_Value[i])==w)
                    {
                        cout << "Error!! Letters from G to Z not included in hexa." << '\n';
                        throw(70);
                    }
                }
            }
        }
        catch(const exception& e)
        {
            cerr << e.what() << '\n';
        }

        for(int f = 0; f<=6; f++)
        {
            switch (Hexa_Value[f])
            {
            case 48:
                List_Hexa.push_back(0);
                break;
            case 49:
                List_Hexa.push_back(1);
                break;
            case 50:
                List_Hexa.push_back(2);
                break;
            case 51:
                List_Hexa.push_back(3);
                break;
            case 52:
                List_Hexa.push_back(4);
                break;
            case 53:
                List_Hexa.push_back(5);
                break;
            case 54:
                List_Hexa.push_back(6);
                break;
            case 55:
                List_Hexa.push_back(7);
                break;
            case 56:
                List_Hexa.push_back(8);
                break;
            case 57:
                List_Hexa.push_back(9);
                break;
            case 'A':
            case 'a':
                List_Hexa.push_back(10);
                break;
            case 'B':
            case 'b':
                List_Hexa.push_back(11);
                break;
            case 'C':
            case 'c':
                List_Hexa.push_back(12);
                break;
            case 'D':
            case 'd':
                List_Hexa.push_back(13);
                break;
            case 'E':
            case 'e':
                List_Hexa.push_back(14);
                break;
            case 'F':
            case 'f':
                List_Hexa.push_back(15);
                break;
            default:
                break;
            }
        }
         
        /*1.Hexadecimal To Binary*/
        /*2.Hexadecimal To Octal*/
        if(Choice2==1 || Choice2==2)
        {
            list<int> Binary;
            int c = 8;
            int skip = 0;
            while(true)
            {
                for(auto i:List_Hexa)
                {
                    for(int r=0; r<4 ; r++)
                    {
                        if(i/c==1)
                        {
                            Binary.push_back(1);
                            i-=c;
                            c/=2;
                            skip++;
                        }
                        else
                        {
                            if(skip!=0)
                                Binary.push_back(0);
                            c/=2;
                        }
                    }
                    c=8;
                }
                break;
            }
            
            if(Choice2==1)
            {
                cout << "\nResult In Binary = ( ";
                for(auto h:Binary)
                    cout << h;
                cout << " )Base2\n";
            }
            
            else if(Choice2==2)
            {
                list<int> result;
                int length = Binary.size();
                if((length)%3 != 0)
                {
                    if((length)%3 == 1)
                       {Binary.push_front(0);
                        Binary.push_front(0);}
                    else
                        Binary.push_front(0);
                }
                int Distributor = 0;
                int d1, d2;
                cout << "\nResult In Octal = ( ";
                for(auto q: Binary)
                {
                  if(Distributor==0){
                    d1 = q*4;
                    Distributor++;
                  }
                  else if(Distributor==1){
                    d2 = q*2;
                    Distributor++;
                  }
                  else{
                    cout << d1+d2+q;
                    Distributor-=2;
                  }
                }
                cout << " )Base8\n";
            }
        }

        /*3.Hexadecimal To Decimal*/
        else if(Choice2==3)
        {
            int sum = 0;
            int length = List_Hexa.size() - 1;
            for(auto a:List_Hexa)
            {
                sum += a*pow(16,length);
                if(length==0)
                    cout << "\nResult In Decimal = ( " << sum << " )Base10\n" << '\n';
                else
                    length--;
            }
        }
        else
            cout << "\nUnavailable choice please try again.\n";    
    }
    }
}