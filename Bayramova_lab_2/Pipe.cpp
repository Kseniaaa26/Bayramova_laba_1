#include "Pipe.h"

using namespace std;

//int Pipe::MaxId = 0;

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
    cin.ignore(INT_MAX, '\n');
    getline(cin, name);

    cout << "������� ����� �����: ";
    length = CorrectNumber(0.0, 10000.);

    cout << "������� ������� �����: ";
    diameter = CorrectNumber(0, INT_MAX);

    cout << "������� ��������� �����(0 - � �������, 1 - � ������): " << endl;
    in_repairing = CorrectNumber(0, 1);
    
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
    Edit(CorrectNumber(0, 1));
    
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
        file >> pipe.name;
        file >> pipe.length;
        file >> pipe.diameter;
        file >> pipe.in_repairing;
        file >> pipe.ID;
    }
    return file;
}