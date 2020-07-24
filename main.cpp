#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Membuat function yang dibutuhkan
void cls(){
    system("cls");
}

// Membuat class yang dibutuhkan

// Membuat class dosen
class Dosen
{
public:
    string nama;
    string NIP;
    string jurusan;

    Dosen(string nama, string NIP, string jurusan)
    {
        Dosen::nama = nama;
        Dosen::NIP = NIP;
        Dosen::jurusan = jurusan;
    }

    string stringify()
    {
        return "\n" + nama + " " + NIP + " " + jurusan;
    }
};

// Membuat class mahasiswa
class Mahasiswa
{
public:
    string nama;
    string NIM;
    string jurusan;

    Mahasiswa(string nama, string NIM, string jurusan)
    {
        Mahasiswa::nama = nama;
        Mahasiswa::NIM = NIM;
        Mahasiswa::jurusan = jurusan;
    }

    string stringify()
    {
        return "\n" + nama + " " + NIM + " " + jurusan;
    }
};

// Membuat class DBase
class DBase
{
public:
    ifstream in;
    ofstream out;
    string fileName;

    DBase(const char *fileName)
    {
        DBase::fileName = fileName;
    }

    void saveMhs(Mahasiswa data)
    {
        DBase::out.open(DBase::fileName, ios::app);
        DBase::out << data.stringify();
        DBase::out.close();
    }

    void saveDsn(Dosen data)
    {
        DBase::out.open(DBase::fileName, ios::app);
        DBase::out << data.stringify();
        DBase::out.close();
    }

    void showAllMhs()
    {
        DBase::in.open(DBase::fileName, ios::in);
        string nama, NIM, jurusan;
        int index = 1;

        cout << "ID\tNama\t\tNIM\t\tJurusan" << endl;
        while (!DBase::in.eof())
        {
            DBase::in >> nama;
            DBase::in >> NIM;
            DBase::in >> jurusan;
            cout << index++ << ".\t";
            cout << nama << "\t\t";
            cout << NIM << "\t";
            cout << jurusan << endl;
        }
        DBase::in.close();
    }

    void showAllDsn()
    {
        DBase::in.open(DBase::fileName, ios::in);
        string nama, NIP, jurusan;
        int index = 1;

        cout << "ID\tNama\t\tNIM\t\tMengajar" << endl;
        while (!DBase::in.eof())
        {
            DBase::in >> nama;
            DBase::in >> NIP;
            DBase::in >> jurusan;
            cout << index++ << ".\t";
            cout << nama << "\t\t";
            cout << NIP << "\t";
            cout << jurusan << endl;
        }
        DBase::in.close();
    }
};



int main(int argc, char const *argv[])
{
    DBase databaseMhs = DBase("datamhs.txt");
    DBase databaseDsn = DBase("datadsn.txt");
    string userInput;

    while(true){
        cout << "SELAMAT DATANG DI PENGELOLAAN KAMPUS\n";
        cout << "1. Pengelolaan Mahasiswa\n";
        cout << "2. Pengelolaan Dosen\n";
        cout << "99. Quit\n";
        cout << "Masukkan pilihan 1 / 2 / 99\n";
        cout << "> ";
        cin >> userInput;

        if (userInput == "1"){
            cls();  
            cout << "PENGELOLAAN MAHASIWA\n";
            cout << "1. Daftar Mahasiwa Baru\n";
            cout << "2. Lihat Database Mahasiwa\n";
            cout << "99. Quit\n";
            cout << "Masukkan pilihan 1 / 2 / 99\n";
            cout << "> ";
            cin >> userInput;

            if (userInput == "1"){
                cls();
                
                // input user
                string nama, NIM, jurusan;
                cout << "MASUKKAN DATA MAHASISWA" << endl;
                cout << "Nama : ";
                cin >> nama;
                cout << "NIM : ";
                cin >> NIM;
                cout << "Jurusan : ";
                cin >> jurusan;

                Mahasiswa mahasiswa = Mahasiswa(nama, NIM, jurusan);

                cout << "\n\nApakah data mahasiswa yang anda masukkan sudah benar [y]es/[n]o?";
                cin >> userInput;

                if (userInput == "y" || userInput == "Y"){
                    cls();
                    // save data ke database
                    databaseMhs.saveMhs(mahasiswa);
                    cout << "Data sudah masuk ke database!\n";
                    system("pause");
                    cls();
                } else {
                    cls();
                }


            } else if (userInput == "2"){
                cls();
                databaseMhs.showAllMhs();
                system("pause");
                cls();

            } else if (userInput == "99"){
                cls();
                cout << "Terimakasih sudah menggunakan program kami!\n\n\n";
                break;

            } else {
                cls();
                cout << "Masukkan pilihan yang benar!\n\n\n\n";
            }

        } else if (userInput == "2"){
            cls();  
            cout << "PENGELOLAAN DOSEN\n";
            cout << "1. Daftar Dosen Baru\n";
            cout << "2. Lihat Database Dosen\n";
            cout << "99. Quit\n";
            cout << "Masukkan pilihan 1 / 2 / 99\n";
            cout << "> ";
            cin >> userInput;

            if (userInput == "1"){
                cls();
                
                // input user
                string nama, NIP, mengajar;
                cout << "MASUKKAN DATA DOSEN" << endl;
                cout << "Nama : ";
                cin >> nama;
                cout << "NIP : ";
                cin >> NIP;
                cout << "Mengajar : ";
                cin >> mengajar;

                Dosen dosen = Dosen(nama, NIP, mengajar);

                cout << "\n\nApakah data dosen yang anda masukkan sudah benar [y]es/[n]o?";
                cin >> userInput;

                if (userInput == "y" || userInput == "Y"){
                    cls();
                    // save data ke database
                    databaseDsn.saveDsn(dosen);
                    cout << "Data sudah masuk ke database!\n";
                    system("pause");
                    cls();
                } else {
                    cls();
                }


            } else if (userInput == "2"){
                cls();
                databaseDsn.showAllDsn();
                system("pause");
                cls();

            } else if (userInput == "99"){
                cls();
                cout << "Terimakasih sudah menggunakan program kami!\n\n\n";
                break;

            } else {
                cls();
                cout << "Masukkan pilihan yang benar!\n\n\n\n";
            }

        } else if (userInput == "99"){
            cls();
            cout << "Terimakasih sudah menggunakan program kami!\n\n\n";
            break;

        } else {
            cls();
            cout << "Masukkan pilihan yang benar!\n\n\n\n";
        }
    }

    return 0;
}
