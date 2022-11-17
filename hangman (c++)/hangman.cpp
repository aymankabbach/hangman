#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <cctype>
using namespace std;
void Load_Data_From_File_to_Vector(vector <string>& vCountries)
{
    fstream file;
    file.open("countries.txt", ios::in);
    if (file.is_open())
    {
        string Line;
        while (getline(file,Line))
        {
            vCountries.push_back(Line);
        }
    }
}
string get_random_country_from_vector(vector <string>& vCountries)
{
    srand (time(NULL));
    int random = rand() % vCountries.size();
    string random_country = vCountries[random];
    random_country[0]=tolower(random_country[0]);
    return random_country;
}
void determine_the_length_of_usercountry(vector <char>& vUserCountry,string random_country)
{
    for (int x=0;x<random_country.size();x++)
    {
        vUserCountry.push_back('_');
    }
}
char get_user_letter()
{
    char letter;
    cout<<"enter a letter"<<endl;
    cin>>letter;
    return letter;
}
int main()
{
    vector <string> vCountries;
    vector <char> vUserCountry;
    bool winner=false;
    bool loser=false;
    int attempts=5;
    Load_Data_From_File_to_Vector(vCountries);
    string random_country=get_random_country_from_vector(vCountries);
    determine_the_length_of_usercountry(vUserCountry,random_country);
    char letter=tolower(get_user_letter());
    system("pause");
    return 0;
}