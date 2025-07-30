using p_int = unsigned long int;
void check_valid_arg(int argc, char* argv[],int valid_arg_no, std::string_view valid_argument);
char chech_operation(char* argv[]);
void calculate (double n1, double n2, char opt);
void password_analysis(std::string_view username,std::string_view pass);
p_int count_Uppercase(std::string_view text);
int count_digit(std::string_view str);
int count_special_charecter(std::string_view str);