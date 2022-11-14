#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
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
    return random_country;
}
int main()
{
    vector <string> vCountries;
    Load_Data_From_File_to_Vector(vCountries);
    string random_country=get_random_country_from_vector(vCountries);
    cout<<random_country<<endl;
    system("pause");
    return 0;
}