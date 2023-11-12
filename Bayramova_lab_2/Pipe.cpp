#include "Pipe.h"

using namespace std;

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
}