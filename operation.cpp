#include <iostream>
#include <string>
#include <cstring>
#include <windows.h>
using p_int = unsigned long int;
using namespace std;
#define BBLACK "\033[1;30m"
#define BRED "\033[1;31m"
#define BGREEN "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE "\033[1;34m"
#define BMAGENTA "\033[1;35m"
#define BCYAN "\033[1;36m"
#define BWHITE "\033[1;37m"
#define RESET "\033[0m"
void check_valid_arg(int argc, char *argv[], int valid_arg_no, string_view valid_argument)
{
    if (argc != valid_arg_no)
    {
        cerr << BRED << "Error: " << RESET << "You are only allowed to use " << valid_arg_no << " arguments.\n";
        cerr << "You are using " << argc << " arguments.\n";
        cerr << "Example of a valid Programme: .\\rooster.exe " << valid_argument;
        exit(EXIT_FAILURE);
    }
}
bool isSpecialchar(char ch)
{
    return !isalnum(static_cast<unsigned char>(ch));
}
p_int count_Uppercase(string_view text)
{
    p_int uppercase{};
    for (size_t i = 0; i < text.size(); i++)
    {
        char temp = text[i];
        if (toupper(temp) == text[i] && !isdigit(text[i]) && !isSpecialchar(text[i]))
        {
            uppercase++;
        }
    }
    return uppercase;
}
int count_digit(string_view str)
{
    int digit{};
    for (size_t i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
        {
            digit++;
        }
    }
    return digit;
}
int count_special_charecter(string_view str)
{
    int sc{};
    for (size_t i = 0; i < str.size(); i++)
    {
        if ((isSpecialchar(str[i])))
        {
            sc++;
        }
    }
    return sc;
}
int count_Lowecase(string_view str)
{
    int lc = str.size() - count_Uppercase(str) - count_special_charecter(str) - count_digit(str);
    return lc;
}
void password_score(string_view usrnm, string_view password)
{
    double length_score = 0.25 * password.size();
    double uc_score{};
    double dc_score{};
    double sc_score = 1 * count_special_charecter(password);
    if (count_Uppercase(password) <= password.size() / 2)
    {
        uc_score = 1 * count_Uppercase(password);
    }
    else
    {
        uc_score = 0.5 * count_Uppercase(password);
    }
    if (count_digit(password) <= password.size())
    {
        dc_score = 0.5 * count_digit(password);
    }
    float pass_score = length_score + uc_score + dc_score + sc_score;
    if (usrnm == password)
    {
        pass_score = 0;
        cout << BYELLOW << "You are using Username as your password this is extremely vulnerable" << RESET << pass_score << endl;
    }
    else if (sc_score == 0 && pass_score >= 2)
    {
        pass_score -= 2;
    }
    else if (dc_score == 0 && pass_score >= 2)
    {
        pass_score -= 2;
    }
    // cout << BYELLOW << "Length Score: " << RESET << length_score << endl;
    // cout << BYELLOW << "UC Score: " << RESET << uc_score << endl;
    // cout << BYELLOW << "Dc Score: " << RESET << dc_score << endl;
    // cout << BYELLOW << "Sc Score: " << RESET << sc_score << endl;
    cout << BYELLOW << "Password Score: " << RESET << pass_score << endl;
    if (pass_score == 0)
    {
        cout << BRED << "Your password is extremely vulnerable please change your password." << RESET << endl;
    }
    else if (pass_score > 0 && pass_score <= 5)
    {
        cout << BRED << "Your password is Weak. " << RESET << endl;
    }
    else if (pass_score > 5 && pass_score <= 7)
    {
        cout << BYELLOW << "Your password is Medium Strong. " << RESET << endl;
    }
    else if (pass_score > 7 && pass_score <= 9)
    {
        cout << BGREEN << "Your password is Strong " << RESET << endl;
    }
    else if (pass_score > 9)
    {
        cout << BCYAN << "Your password is Very Strong." << RESET << endl;
    }
    // Recomendation:
    if (pass_score < 9 && length_score < 2||dc_score < 1||sc_score < 1||uc_score < 2 )
    {
        cout << BRED << "Recommendations:" << RESET << endl;
        if (length_score < 2)
        {
            cout << BYELLOW << "Your password length " << password.size() << "Reccomended Using atleast 8" << RESET << endl;
        }

        if (dc_score < 1)
        {
            cout << BYELLOW << "Your are using " << count_digit(password) << " digits, Reccomended Using atleast 2" << RESET << endl;
        }
        if (sc_score < 1)
        {
            cout << BYELLOW << "Your are using " << count_special_charecter(password) << " Special characters, Reccomended Using atleast 1" << RESET << endl;
        }
        if (uc_score < 2)
        {
            cout << BYELLOW << "Your are using " << count_Uppercase(password) << " Uppercase character, Reccomended Using atleast 2" << RESET << endl;
        }
    }
}
void password_analysis(string_view username, string_view pass)
{
    int uppercase = count_Uppercase(pass);
    cout << BMAGENTA << "Analizing Your Password..." << RESET << endl;
    Sleep(2000);
    cout << BYELLOW << "Password Length: " << RESET << pass.size() << endl;
    cout << BYELLOW << "Uppercase Characters: " << RESET << count_Uppercase(pass) << endl;
    cout << BYELLOW << "Lowecase Charecters: " << RESET << count_Lowecase(pass) << endl;
    cout << BYELLOW << "Special  Charecters: " << RESET << count_special_charecter(pass) << endl;
    cout << BYELLOW << "Digits: " << RESET << count_digit(pass) << endl;
    cout << BMAGENTA << "Getting password score..." << RESET << endl;
    Sleep(2000);
    password_score(username, pass);
    // unsigned int p_score=password_score(username, pass);
    // if (password_score==0)
    // {
    //     cout << BRED << "Your password is extremely vulnerable please change your " << RESET << endl;
    // }
}