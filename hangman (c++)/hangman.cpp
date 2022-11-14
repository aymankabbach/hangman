#include <iostream>
#include <vector>
#include <fstream>
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
int main()
{
    vector <string> vCountries;
    Load_Data_From_File_to_Vector(vCountries);
    
    system("pause");
    return 0;
}