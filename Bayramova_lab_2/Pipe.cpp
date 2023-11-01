#include "Pipe.h"

int Pipe::MaxId = 0;

Pipe::Pipe() {
    name = "Non";
    length = 0.0;
    diameter = 0;
    in_repairing = 0;
    ID = ++MaxId;
}

Pipe::Pipe(string name, double length, int diameter, bool in_repairing) {
    this->name = name;
    this->length = length;
    this->diameter = diameter;
    this->in_repairing = in_repairing;
}

void Pipe::InputPipeInfo() {
    cout << "������� �������� �����: ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, name);

    cout << "������� ����� �����: ";
    length = CorrectNumber(0.0, DBL_MAX);

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

void Pipe::Edit(const int answer) {
    if (answer) in_repairing = true;
    else in_repairing = false;
}

void Pipe::editInRepairStatus()
{
    PrintInfo();
    cout << "�������� ������� � �������(0 - ��������, 1 - ��������):" << endl;
    Edit(CorrectNumber(0, 1));
}


ostream& operator << (ostream& out, const Pipe& pipe)
{

    return out;
}
istream& operator >> (istream& in, Pipe& pipe)
{
    return in;
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