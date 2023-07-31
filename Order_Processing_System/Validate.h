#ifndef VALIDATE_H
#define VALIDATE_H
#include<iostream>
#include<string>

using namespace std;

        int is_valid_name(string name)
        {   int is_valid=1;
            for(int i=0;i<name.length();i++)
            {
                if(!isalpha(name[i]))
                {
                    is_valid=0;
                    break;
                }
            }
            return is_valid;
        }
        int is_valid_choice(string choice)
        {
            int is_valid=1;
            if(choice.length()>1)
                return 0;
            if(choice.length()==1)
            {
                if(!isdigit(choice[0]))
                    is_valid=0;
            }
            return is_valid;
        }
        int is_valid_num(string num)
        {  
            int is_valid=1;
            for(int i=0;i<=num.length();i++)
            { 
                if(!isdigit(num[i]))
                {
                    is_valid=0;
                    break;
                }
               
            }
            return is_valid;
        }

#endif
