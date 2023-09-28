#include <iostream>
#include <string>
#include <fstream>

#include <filesystem>


using namespace std;
//namespace fs = filesystem;

inline int CorrectNumber(int min, int max) {
    int x;
    while ((cin >> x).fail()
        || cin.peek() != '\n'
        || x < min || x > max)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nНеверный ввод данных!" << endl;
        cout << "Введите число от " << min << "до " << max << endl;
    }
    return x;
}

inline double CorrectNumber(double min, double max) {
    double x;
    while ((cin >> x).fail()
        || cin.peek() != '\n'
        || x < min || x > max)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nНеверный ввод данных!" << endl;
        cout << "Введите число от " << min << "до " << max << endl;
    }
    return x;
}

struct Pipe {
    string name_p;
    double length;
    int diameter;
    bool in_repairing;
};

struct CS {
    string name_CS;
    int number_of_workshops;
    int workshops_in_operation;
    int effectiveness;
};

int flagPipe = 0;
int flagCS = 0;


int inputPipeInfo(Pipe& pipe) {
    
    cout << "Введите название трубы: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, pipe.name_p);

    cout << "Введите длину трубы: ";
    pipe.length = CorrectNumber(0.0, DBL_MAX);

    cout << "Введите диаметр трубы: ";
    pipe.diameter = CorrectNumber(0, INT_MAX);

    cout << "Введите состояние трубы(0 - в ремонте, 1 - в работе): " << endl;
    if (CorrectNumber(0, 1)) {
        pipe.in_repairing = true;
    }
    else {
        pipe.in_repairing = false;
    }
    flagPipe = 1;
    return flagPipe;
}

int inputCSInfo(CS& cs) {

    cout << "Введите название КС: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, cs.name_CS);

    cout << "Введите количество цехов КС: ";
    cs.number_of_workshops = CorrectNumber(0, 50);

    cout << "Введите количество цехов в работе: ";
    cs.workshops_in_operation = CorrectNumber(0, cs.number_of_workshops);

    cout << "Укажите эффективность(1,2,3)" << endl;
    cs.effectiveness = CorrectNumber(1, 3);

    flagCS = 1;
    return flagCS;
}

void printPipeInfo(const Pipe& pipe) {
    cout << "Труба: " << pipe.name_p << endl;
    cout << "Длина: " << pipe.length << endl;
    cout << "Диаметр: " << pipe.diameter << endl;
    cout << "Состояние(0 - в ремонте, 1 - в работе): " << (pipe.in_repairing ? "true" : "false") << endl;
    cout << endl;
}

void printCSInfo(const CS& cs) {
    cout << "КС: " << cs.name_CS << endl;
    cout << "Количество цехов: " << cs.number_of_workshops << endl;
    cout << "Количество цехов в работе: " << cs.workshops_in_operation << endl;
    cout << "Эффективность: " << cs.effectiveness << endl;
    cout << endl;
}

void editInRepairStatus(Pipe& pipe) {
    cout << "Изменить признак в ремонте(0 - оставить, 1 - изменить): " << endl;
    if (CorrectNumber(0, 1)) {
        pipe.in_repairing = !pipe.in_repairing;
    }
    cout << endl;
}

void editCS(CS& cs) {
    cout << "Изменить количество цехов в работе: " << endl;
    cs.workshops_in_operation = CorrectNumber(0, cs.number_of_workshops);
}

void View(Pipe& pipe, CS& cs)
{

    while (1) {
        
        cout << "0. Назад\n" <<
            "1. Просмотр трубы\n" <<
            "2. Просмотр КС" << endl;


        switch (CorrectNumber(0, 2)) {
        case 1: {
            if (flagPipe == 1){
                printPipeInfo(pipe);
                break;
            }
            else {
                cout << "Нет трубы, сначала добавьте её\n" << endl;
                break;
                
            }
        }
        case 2: {
            if (flagCS == 1) {
                printCSInfo(cs);
                break;
            }
            else {
                cout << "Нет КС, сначала добавьте её\n" << endl;
                break;
            }
        }

        case 0: {
            return;
        }

        }
    }
}


void SavePipe(Pipe& pipe) {
    ofstream fout;
    fout.open("pipe_data.txt", ios::out);
    if (fout.is_open()) {
        fout << pipe.name_p << endl << pipe.length << endl << pipe.diameter << endl << pipe.in_repairing << endl;
        fout.close();
    }
}
void SaveCS(CS& cs) {
    ofstream fout;
    fout.open("cs_data.txt", ios::out);
    if (fout.is_open()) {
        fout << cs.name_CS << endl << cs.number_of_workshops << endl << cs.workshops_in_operation << endl << cs.effectiveness << endl;
        fout.close();
    }
}

int LoadPipe(Pipe& pipe) {

    ifstream fin;
    fin.open("pipe_data.txt", ios::in);
    if (fin.is_open())
    {
        int count = 0;
        char buffer[1024];
        while (!fin.eof() && count < 1024) {
            // Считываем данные из файла
            fin.read(buffer, sizeof(buffer));

            // Увеличиваем значение счетчика на количество считанных байт
            count += fin.gcount();
        }

        fin.close();

        if (count == 0) {
            cout << "Пустой файл, сохраните трубу" << endl;
            return 0;
        }
        else {
            fin.open("pipe_data.txt", ios::in);
            fin >> pipe.name_p;
            fin >> pipe.length;
            fin >> pipe.diameter;
            fin >> pipe.in_repairing;
            fin.close();
            flagPipe = 1;
            return flagPipe;
        }
    }
    flagPipe = 1;
    return flagPipe;
}
int LoadCS(CS& cs) {
    ifstream fin;
    fin.open("cs_data.txt", ios::in);
    if (fin.is_open())
    {
        int count = 0;
        char buffer[1024];
        while (!fin.eof() && count < 1024) {
            // Считываем данные из файла
            fin.read(buffer, sizeof(buffer));

            // Увеличиваем значение счетчика на количество считанных байт
            count += fin.gcount();
        }

        fin.close();

        if (count == 0) {
            cout << "Пустой файл, сохраните КС" << endl;
            return 0;
        }
        else {
            fin.open("cs_data.txt", ios::in);
            fin >> cs.name_CS;
            fin >> cs.number_of_workshops;
            fin >> cs.workshops_in_operation;
            fin >> cs.effectiveness;
            fin.close();

            flagCS = 1;
            return flagCS;
        }
    }
}


int main() {
    
    setlocale(LC_ALL, "ru");

    Pipe pipe;
    CS cs;

    while (true) {
        cout << "\n1. Добавить трубу\n" <<
            "2. Добавить КС\n" <<
            "3. Просмотр всех объектов\n" <<
            "4. Редактировать трубу\n" <<
            "5. Редактировать КС\n" <<
            "6. Сохранить\n" <<
            "7. Загрузить\n" <<
            "0. Выход\n" << endl;

        switch (CorrectNumber(0, 7)) {

        case 1:
            inputPipeInfo(pipe);
            break;

        case 2:
            inputCSInfo(cs);
            break;

        case 3:
            View(pipe, cs);
            break;

        case 4:
            editInRepairStatus(pipe);
            break;

        case 5:
            editCS(cs);
            break;

        case 6:
            
                cout << "\n1. Сохранить трубу и КС\n" <<
                    "2. Сохранить трубу\n" <<
                    "3. Сохранить КС\n" << endl;

                switch (CorrectNumber(0, 3)) {

                case 1:
                    if (flagPipe == 1 && flagCS == 1) {
                        SavePipe(pipe);
                        SaveCS(cs);
                        break;
                    }
                    if (flagPipe == 1 && flagCS == 0) {
                        cout << "\nДобавьте КС";
                        break;
                    }
                    if (flagPipe == 0 && flagCS == 1) {
                        cout << "\nДобавьте трубу";
                        break;
                    }
                    else {
                        cout << "\nДобавьте трубу и КС";
                        break;
                    }

                case 2:
                    if (flagPipe == 1) {
                        SavePipe(pipe);
                        break;
                    }
                    else {
                        cout << "\nДобавьте трубу" << endl;
                        break;
                    }

                case 3:
                    if (flagCS == 1) {
                        SaveCS(cs);
                        break;
                    }
                    else {
                        cout << "\nДобавьте КС" << endl;
                        break;
                    }
                }
            
        case 8:
             cout << "" << endl;
             break;

        case 7:
            cout << "\n1. Загрузить трубу и КС\n" <<
                "2. Загрузить трубу\n" <<
                "3. Загрузить КС\n" << endl;

            switch (CorrectNumber(1, 3)) {

            case 1:
                LoadPipe(pipe);
                LoadCS(cs);
                break;

            case 2:
                LoadPipe(pipe);
                break;
               


            case 3:
                LoadCS(cs);
                break;
              
            }
            break;

        case 0:
            return 0;

        }
    }

    return 0;
}