#include <stdexcept>
#include "PhoneticFinder.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

namespace phonetic{

    std::string toLowerCase(std::string s)
    {
        for (size_t i = 0; i < s.length(); i++)
        {
            s[i] = std::tolower(s[i]);
        }
        return s;
    }

    bool mistakes(char a,char b)
    {
        a = std::tolower(a);
        b = std::tolower(b);
        if (a == b)
        {
            return true;
        }
        if (a == 'q' && (b == 'k'|| b == 'c'))
        {
            return true;
        }
        if (a == 'w' && b == 'v')
        {
            return true;
        }
        if (a == 't' && b == 'd')
        {
            return true;
        }
        if (a == 'y' && b == 'i')
        {
            return true;
        }
        if (a == 'u'&& b =='o')
        {
            return true;
        }
        if (a == 'i' && b == 'y')
        {
            return true;
        }
        if (a == 'o' && b == 'u')
        {
            return true;
        }
        if (a == 'p' && (b == 'f' || b == 'b'))
        {
            return true;
        }
        if (a == 'o' && b =='u')
        {
            return true;
        }
        if (a == 'd' && b == 't')
        {
            return true;
        }
        if (a == 'f' && (b == 'p'||b == 'b'))
        {
            return true;
        }
        if (a == 'g' && b == 'j')
        {
            return true;
        }
        if (a == 'j' && b == 'g')
        {
            return true;
        }
        if (a == 'k' && (b == 'c' || b == 'q'))
        {
            return true;
        }
        if (a == 'c' && (b == 'k' || b == 'q'))
        {
            return true;
        }
        if (a == 'v' && b == 'w')
        {
            return true;
        }
        if (a == 'b' && (b == 'f' || b == 'p'))
        {
            return true;
        }
        if (a == 's' && b == 'z')
        {
            return true;
        }
        if (a == 'z' && b == 's')
        {
            return true;
        }
        return false;
    }
    bool mistakes(std::string s1,std::string s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }
        for (size_t i = 0; i < s1.length(); i++)
        {
            if (!(mistakes(s1[i],s2[i]) || mistakes(s2[i],s1[i])))
            {
                return false;
            }
        }
        return true;
    }

    std::string getword(int start,int end, std::string s)
    {
        std::string ans = "";
        for (size_t i = start; i < end; i++)
        {
            if (i == end - 1 && s[i]==' ')
                return ans;
            ans += s[i];
        }
        return ans;
    }

    std::string find(std::string s1, std::string s2)
    {
        if(s2.compare(" ") == 0)
        {
            throw std::runtime_error("error");
        }
        int start = 0;
        int end = 0;


        for (size_t i = 0; i < s1.length(); i++)
        {
            if (i == s1.length() - 1)
            {
                end = i+1;
                if(s1[i+1] == ' ')
                {
                    end = i;
                }
                std::string temp = getword(start,end,s1);
                if (mistakes(temp,s2))
                {
                    return temp;
                }
                i++;
            }


            if (s1[i] == ' ' && i < s1.length())
            {
                end = i;
                std::string temp = getword(start,end,s1);

                if (mistakes(temp,s2))
                {
                    return temp;
                }

                if (i+1<s1.length())
                {
                    start = i+1;
                }
            }
        }
        throw std::runtime_error(("the word ")+s2+(" is not in the text"));
    }
};