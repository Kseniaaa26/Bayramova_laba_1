/*#include "Pipe.h"

using namespace std;



int Pipe::MaxId = 0;

Pipe::Pipe() {
    name = "Non";
    length = 0.0;
    diameter = 0;
    in_repairing = 0;
    ID = ++MaxId;
}

Pipe::Pipe(string name, float length, int diameter, bool in_repairing) {
    this->name = name;
    this->length = length;
    this->diameter = diameter;
    this->in_repairing = in_repairing;
}

void Pipe::InputInfo() {

    cout << "¬ведите название трубы: ";
    name = input_string(cin);

    cout << "¬ведите длину трубы: ";
    length = CorrectNumber(cin, 0.0, 10000.);

    cout << "¬ведите диаметр трубы: ";
    diameter = CorrectNumber(cin, 0, INT_MAX);

    cout << "¬ведите состо€ние трубы(0 - в ремонте, 1 - в работе): " << endl;
    in_repairing = CorrectNumber(cin, 0, 1);

}

void Pipe::PrintInfo() {
    cout << "“руба: " << name << endl;
    cout << "ƒлина: " << length << endl;
    cout << "ƒиаметр: " << diameter << endl;
    cout << "—осто€ние(0 - в ремонте, 1 - в работе): " << (in_repairing ? "true" : "false") << endl;
    cout << "ID" << ID << endl;


}

void Pipe::Edit(int status) {
    if (status) in_repairing = !in_repairing;
}

void Pipe::Edit()
{
    PrintInfo();
    cout << "»зменить признак в ремонте(0 - оставить, 1 - изменить):" << endl;
    Edit(CorrectNumber(cin, 0, 1));

}

ofstream& operator << (ofstream& file, const Pipe& pipe) {
    if (file.is_open()) {
        file << pipe.name << endl;
        file << pipe.length << endl;
        file << pipe.diameter << endl;
        file << pipe.in_repairing << endl;
        file << pipe.ID << endl;
    }
    return file;
}

ifstream& operator >> (ifstream& file, Pipe& pipe) {
    if (file.is_open()) {
        file >> ws;
        getline(file, pipe.name);
        file >> pipe.length;
        file >> pipe.diameter;
        file >> pipe.in_repairing;
        file >> pipe.ID;
    }
    return file;
}*/

#include "Pipe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <float.h>
#include <unordered_map>
#include <unordered_set>
#include "header.h"
#include "Graph.h"
using namespace std;
System s;
string status_check(bool x)
{
    if (x == true)
        return ("“руба в работе");
    else
        return ("“руба в ремонте");
}
int Pipe::max_id = 0;
istream& operator>> (istream& in, Pipe& p)
{
    cout << "\n »ндекс трубы: " << p.idp;
    cout << "\n¬ведите название трубы ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, p.name);
    cout << "\n¬ведите длину трубы  ";
    p.length = correctnumber(0.0, DBL_MAX);
    cout << "\n¬ведите диаметр трубы ";
    p.diameter = correctnumber(0.0, DBL_MAX);
    cout << "\n¬ведите состо€ние трубы(0 - в ремонте, 1 - в работе) ";
    p.status = correctnumber(0, 1);
    cout << status_check(p.status) << endl;
    return in;
}
ostream& operator<< (ostream& out, Pipe& p) {
    out << "\n»ндекс трубы: " << p.idp << endl;
    out << "“руба: " << p.name << endl;
    out << "ƒлина: " << p.length << endl;
    out << "ƒиаметр: " << p.diameter << endl;
    out << "—осто€ние(0 - в ремонте, 1 - в работе): " << status_check(p.status) << endl;

    return out;
}
void Pipe::edit_Pipe() {
    cout << "—осто€ние трубы: " << status_check(status) << endl;
    cout << "»зменить состо€ние трубы (0 - в ремонте, 1 - в работе)" << endl;
    status = correctnumber(0, 1);
    cout << status_check(status) << endl;;
}
void Pipe::save_pipe(ofstream& file) {
    if (file.is_open()) {
        file << idp << endl;
        file << name << endl;
        file << length << endl;
        file << diameter << endl;
        file << status << endl;
        
    }
}
void Pipe::load_pipe(ifstream& file) {
    if (file.is_open()) {
        file >> idp;
        getline(file, name);
        getline(file, name);
        file >> length;
        file >> diameter;
        file >> status;
    }
}
bool check_p_name(Pipe& p, string name) {
    return (p.name.find(name) != string::npos);
}
bool check_p_status(Pipe& p, bool status) {
    return (p.status == status);
}