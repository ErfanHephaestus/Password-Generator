// Password-Generator.cpp 
// Created by ErfanHephaestus

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include<ctime>
#include<cstdlib>

using namespace std;

void initilizer(vector <string>& x); 
int greeting();
string passGenerator(const vector<string>& passVec, int plength);

int main()
{
    srand(time(0)); //seeding random number
    int passLength;
    vector<string> pass;
    initilizer(pass);   //Initilizing vector containing characters
    passLength = greeting(); //greeting user and asking the length of password he/she wants
    random_shuffle(pass.begin(), pass.end()); //randomizing vector
    cout << "your password is:\t" << passGenerator(pass, passLength) << endl;   //generating password and displaying it
}
//function definitions
void initilizer(vector <string>& x)
{
    x.push_back("abcdefghijklmnopqrstuvwxyz");
    x.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    x.push_back(" !@#$%^&*()_-+=~[]{}\|:;<>.,?/'");
    x.push_back("0123456789");
}
int greeting()
{
    int y;
    cout << "Hi , weclome to password generating programme\n\n";
    do
    {
       
        cout << "How many character do you want your password to be?\n";
        cin >> y;
        if (y != 0)
            break;
    } while (true);
    return y;
}
string passGenerator(const vector<string>& passVec, int plength)
{
    string password = " ";
    int xSize , ySize = 0;
   
    for (int i = 0; i < plength; i++)
    {
        int xrand = rand();
        ySize = xrand % (passVec.size());
        xSize = (passVec[ySize]).size();
        password += (passVec[ySize])[(xrand % xSize)];
    }
    return password;
}
