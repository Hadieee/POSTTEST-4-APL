#include <iostream> // Untuk penggunaan fungsi cout, cin, dan endl
#include<conio.h>   // Untuk penggunaan fungsi getch
using namespace std; // Agar tidak perlu menuliskan "std::"

struct data // Terdapat sebuah struct untuk mendeklarasi array dari nama, jenis kelamin, umur dan ketersediaan raket
{
    string nama;
    string kelamin;
    int umur;
    int ketersediaan;
};

struct data batas[50]; // Untuk mendeklarasikan sebuah array batas yang bertipe struct data
int a, b, c, i, j, ditemukan = 0, pilih; // Untuk keperluan pertambahan indeks array, nomor, pilihan dan perulangan
char tanya; // Untuk tanya saat ingin keluar dari program
string Nama; // Untuk variabel saat mencari nama



void inputdata() // Prosedur untuk input data
{
    system("color 5A");
    cout<<"Nama Panggilan\t\t\t\t: "; getline(cin,batas[a].nama);fflush(stdin);
    cout<<"Jenis Kelamin (Laki-laki / Perempuan)\t: ";cin>>batas[a].kelamin;fflush(stdin);
    cout<<"Umur\t\t\t\t\t: ";cin>>batas[a].umur;fflush(stdin);
    cout<<"Jumlah Ketersediaan Raket\t\t: ";cin>>batas[a].ketersediaan;fflush(stdin);

    a++; // Untuk penambahan indeks array
    cout<<"\n=========================== Data Berhasil Ditambahkan ===========================";
    getch();system("cls");
}


void lihatdata() // Prosedur untuk lihat data
{
    system("color 5A");
    cout<<"\n======================================================== Menampilkan Data ========================================================\n\n";
    cout<<"==================================================================================================================================\n";
    cout<<"||\tNO\t||\t\tNama Panggilan\t\t\t||\tJenis Kelamin\t||\tUmur\t||\tKetersediaan\t||";
    cout<<"\n==================================================================================================================================";

    j = 0; // Untuk penomoran dalam tabel
    for(i=0;i<a;i++)
    {
        j=j+1;
        cout<<"\n";
        cout<<"||\t"<<j<<"\t||";
        cout<<"\t\t"<<batas[i].nama<<"\t\t||";
        cout<<"\t"<<batas[i].kelamin<<"\t||";
        cout<<"\t"<<batas[i].umur<<"\t||";
        cout<<"\t   "<<batas[i].ketersediaan<<"\t\t||";
        cout<<"\n==================================================================================================================================";
    }
    getch();system("cls");
}

void editdata() // Prosedur untuk edit data
{
    apa: // goto yang berfungsi untuk melompat ke baris label
    system("color 5A");
    cout<<"Masukan nama yang ingin diedit\t\t: "; getline(cin, Nama);

    for( b = 0; b < 50 - 1; b++)
    {
        if (batas[b].nama == Nama){ditemukan++;break;}
        else
        {
            cout<<"Nama tidak ditemukan";
            cout<<"\nApakah anda ingin mengedit kembali ? (Y / T) : "<< endl; // Untuk menanyakan user apakah ingin mengedit data lagi
            tanya = getch();
            switch (tanya)
            {
                case('y'):
                case('Y'):
                    system("cls");goto apa;

                case('t'):
                case('T'):
                    goto langsung;
                
                default: // Untuk kesalahan dalam memilih
                    cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto apa;
            }
        }
    }

    cout<<"Nama Panggilan\t\t\t\t: "; getline(cin,batas[b].nama);fflush(stdin);
    cout<<"Jenis Kelamin (Laki-laki / Perempuan)\t: ";cin>>batas[b].kelamin;fflush(stdin);
    cout<<"Umur\t\t\t\t\t: ";cin>>batas[b].umur;fflush(stdin);
    cout<<"Jumlah Ketersediaan Raket\t\t: ";cin>>batas[b].ketersediaan;fflush(stdin);
    cout<<"\n======================================================== Data berhasil diedit ========================================================\n";
    langsung:
    lihatdata();
}

void hapusdata() // Prosedur untuk hapus data
{
    iya: // goto yang berfungsi untuk melompat ke baris label
    system("color 5A");
    cout<<"Masukan nama yang ingin dihapus\t\t: "; getline(cin, Nama);

    for( c = 0; c < 50 - 1; c++)
    {
        if (batas[c].nama == Nama){ditemukan++;break;}
        else
        {
            cout<<"Nama tidak ditemukan";
            cout<<"\nApakah anda ingin mengedit kembali ? (Y / T) : "<< endl; // Untuk menanyakan user apakah ingin menghapus data lagi
            tanya = getch();
            switch (tanya)
            {
                case('y'):
                case('Y'):
                    system("cls");goto iya;

                case('t'):
                case('T'):
                    goto langsungg;
                
                default: // Untuk kesalahan dalam memilih
                    cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto iya;
            }
        }
    }

    a--; // Untuk indeks di data
    for(int i=c;i<a;i++)
    {
        batas[i] = batas[i+1];
    }

    system("cls");
    cout<<"\n======================================================== Data berhasil dihapus ========================================================\n";
    langsungg: // goto yang berfungsi untuk melompat ke baris label
    lihatdata();
}


int main() // Fungsi utama
{
    awal: // Terdapat label awal sebagai tempat untuk kembali ke menu utama setelah melakukan eksekusi data
    system("cls");
    system("color 5A");
    cout<<"\n============================= PROGRAM CRUD DATA ANGGOTA =============================";
    cout<<"\n=================================== PILIHAN MENU ====================================\n";
    cout<<"\n\t\t\t\t1. Masukkan data";
    cout<<"\n\t\t\t\t2. Lihat Data";
    cout<<"\n\t\t\t\t3. Edit Data";
    cout<<"\n\t\t\t\t4. Hapus Data";
    cout<<"\n\t\t\t\t5. Keluar\n";
    cout<<"\n=====================================================================================\n";
    cout<<"\nMasukkan Pilihan : ";
    pilih = getch();
    switch(pilih)
    {
        case'1':
            {system("cls");inputdata();goto awal;break;} // goto yang berfungsi untuk melompat ke baris label
        case'2':
            {system("cls");lihatdata();goto awal;} // goto yang berfungsi untuk melompat ke baris label
        case'3':
            {system("cls");editdata();goto awal;} // goto yang berfungsi untuk melompat ke baris label
        case'4':
            {system("cls");hapusdata();goto awal;} // goto yang berfungsi untuk melompat ke baris label
        case'5':
            {   
                system("cls");
                Tanya: // goto yang berfungsi untuk melompat ke baris label
                cout<<"\nApakah anda ingin keluar dari program ? (Y / T) : "<< endl; // Untuk menanyakan user apakah ingin keluar dari program
                tanya = getch();
                switch (tanya)
                {
                    case('y'):
                    case('Y'):
                        system("cls");
                        cout<<"=======================================================================" << endl;
                        cout << "Terimakasih telah menggunakan program ini :) Semoga harimu menyenangkan" << endl;
                        cout<<"======================================================================="; exit(0);

                    case('t'):
                    case('T'):
                        system("cls");goto awal;
                    
                    default: // Untuk kesalahan dalam memilih
                        cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto Tanya;
                }
                }
        default: // Untuk kesalahan dalam memilih
        {
            cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto awal;
        }
    }
}
