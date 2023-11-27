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

    cout << "������� �������� �����: ";
    name = input_string(cin);

    cout << "������� ����� �����: ";
    length = CorrectNumber(cin, 0.0, 10000.);

    cout << "������� ������� �����: ";
    diameter = CorrectNumber(cin, 0, INT_MAX);

    cout << "������� ��������� �����(0 - � �������, 1 - � ������): " << endl;
    in_repairing = CorrectNumber(cin, 0, 1);

}

void Pipe::PrintInfo() {
    cout << "�����: " << name << endl;
    cout << "�����: " << length << endl;
    cout << "�������: " << diameter << endl;
    cout << "���������(0 - � �������, 1 - � ������): " << (in_repairing ? "true" : "false") << endl;
    cout << "ID" << ID << endl;


}

void Pipe::Edit(int status) {
    if (status) in_repairing = !in_repairing;
}

void Pipe::Edit()
{
    PrintInfo();
    cout << "�������� ������� � �������(0 - ��������, 1 - ��������):" << endl;
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
        return ("����� � ������");
    else
        return ("����� � �������");
}
int Pipe::max_id = 0;
istream& operator>> (istream& in, Pipe& p)
{
    cout << "\n ������ �����: " << p.idp;
    cout << "\n������� �������� ����� ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, p.name);
    cout << "\n������� ����� �����  ";
    p.length = correctnumber(0.0, DBL_MAX);
    cout << "\n������� ������� ����� ";
    p.diameter = correctnumber(0.0, DBL_MAX);
    cout << "\n������� ��������� �����(0 - � �������, 1 - � ������) ";
    p.status = correctnumber(0, 1);
    cout << status_check(p.status) << endl;
    return in;
}
ostream& operator<< (ostream& out, Pipe& p) {
    out << "\n������ �����: " << p.idp << endl;
    out << "�����: " << p.name << endl;
    out << "�����: " << p.length << endl;
    out << "�������: " << p.diameter << endl;
    out << "���������(0 - � �������, 1 - � ������): " << status_check(p.status) << endl;

    return out;
}
void Pipe::edit_Pipe() {
    cout << "��������� �����: " << status_check(status) << endl;
    cout << "�������� ��������� ����� (0 - � �������, 1 - � ������)" << endl;
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