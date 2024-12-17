#include <iostream>
#include <windows.h>
#include <vector>
#include <chrono>
#include <algorithm>
#include <list>
#include <iomanip>

using namespace std;

// class lampu lalu lintar simpang 4
class TrafficLight{
    private:
        bool jalan1 = false;
        bool jalan2 = false;
        int light1, light2;
    public:
       /* 3 digit dari nim terakhir 241011402178
        merah: 1
        kuning: 7
        hijau: 8
       */
        
        //method untuk memvisualisasikan lampu lalu lintas simpang 4
        void drawTraf(string jalan1,string jalan2){
            system("cls");
            string visual = "";
            string traff1 = "";
            string traff2 = "";

            // menggambar jalan 1 atau jalan utara dan selatan
            for (int i = 0; i < 10; i++) {
                traff1 += "                        |           |            |\n";
                if (i == 5) {
                    traff1 += "                        |   %s  |   %s   |\n"; // Placeholders
                }else if(i==3){
                    traff1 += "                        |     ^     |     V      |\n";
                }
            }

            // menggambar jalan 2 atau jalan barat dan timur
            for (int i = 0; i < 10; i++) {
                if (i < 1) {
                    traff2 += "------------------------                          ------------------------";
                } else if (i > 0) {
                    traff2 += "\n";
                    if (i == 3) {
                        traff2 += "            %s                                          %s           \n";
                        traff2 += "            -->                                         -->          ";
                    } else if (i == 7) {
                        traff2 += "            %s                                          %s           \n";
                        traff2 += "            <--                                         <--          ";
                    }
                    if (i == 5) {
                        traff2 += "------------------------                          ------------------------";
                    }
                }
                if (i == 9) {
                    traff2 += "------------------------                          ------------------------\n";
                }
            }

            // mengganti variable pada variable traff1 dengan parameter jalan1
            size_t pos1 = traff1.find("%s");
            if (pos1 != string::npos) {
                traff1.replace(pos1, 2, jalan1); // Replace first %s
            }

            size_t pos2 = traff1.find("%s");
            if (pos2 != string::npos) {
                traff1.replace(pos2, 2, jalan1); // Replace second %s
            }

            //mengganti variable pada variable traff2 dengan parameter jalan2
            size_t pos3;
            int counter = 0;
            while ((pos3 = traff2.find("%s")) != string::npos){
                counter = counter+1;
                traff2.replace(pos3, 6, jalan2); // Replace first %s
            }
            visual += traff1 += traff2 += traff1;
            cout << visual << endl;
        }

        //method utama yang mengatur logic lampu lalu lintas simpang 4
        vector<bool> traffic(int light1){
            switch (light1)
            {
            case 1:
                //merah
                jalan1 = false;
                jalan2 = !jalan1;
                break;
            case 7:
                //kuning
                jalan1 = false;
                jalan2 = !jalan1;
                break;
            case 8:
                //hijau
                jalan1 = true;
                jalan2 = !jalan1;
                break;
            default:
                break;
            }
            return {jalan1,jalan2};
        };
};

//fungsi utama yang mengimplementasi method dari class TrafficLight
void lampu_persimpangan(){
    TrafficLight trf;
    int trafficCode;
    list<int> nim_akhir = {1,7,8};
    cout << "Program Simulasi lampu merah simpang 4" << endl;
    cout << "---------------------" << endl;
    cout << "Masukan kode traffic light: 1: merah, 7: kuning, 8: hijau. ";
    cin >> trafficCode;
    auto found = find(nim_akhir.begin(),nim_akhir.end(),trafficCode);
    if (found==nim_akhir.end()){
        cout << "Kode tidak ada dalam list!\n";
        exit(0);
    }
    int currTrafic = trafficCode;
    while (true)
    {
        if (currTrafic==1){
            vector<bool> result = trf.traffic(currTrafic);
            if(result[0]){
                trf.drawTraf("\033[32mHIJAU\033[0m ","\033[31mMERAH\033[0m ");
            }else{
                trf.drawTraf("\033[31mMERAH\033[0m ","\033[32mHIJAU\033[0m ");
            }
            currTrafic = currTrafic+6;
            cout <<"\n"<<endl;
            Sleep(5000);
        }else if (currTrafic==7)
        {
            vector<bool> result = trf.traffic(currTrafic);
            if(result[0]){
                trf.drawTraf("\033[32mHIJAU\033[0m","\033[31mMERAH\033[0m ");
            }else{
                trf.drawTraf("\033[33mKUNING\033[0m","\033[31mMERAH\033[0m ");
            }
            currTrafic = currTrafic+1;
            cout <<"\n"<<endl;
            Sleep(3000);
        }else if(currTrafic == 8){  
            vector<bool> result = trf.traffic(currTrafic);
            if(result[0]){
                trf.drawTraf("\033[32mHIJAU\033[0m ","\033[31mMERAH\033[0m ");
            }else{
                trf.drawTraf("\033[31mMERAH\033[0m ","\033[32mHIJAU\033[0m ");
            }
            currTrafic = currTrafic-7;            
            cout <<"\n"<<endl;
            Sleep(5000);
        }   
    }
}

//class konversi suhu
class KonversiSuhu{
    public:
        // Method untuk mengonversi dari Celcius ke Fahrenheit
        double celciusToFahrenheit(double celcius) {
            return (celcius * 9.0 / 5.0) + 32;
        }

        // Method untuk mengonversi dari Fahrenheit ke Celcius
        double fahrenheitToCelcius(double fahrenheit) {
            return (fahrenheit - 32) * 5.0 / 9.0;
        }
};

//fungsi utama implementasi method dalam class KonversiSuhu
void konversi_suhu(){
    KonversiSuhu KS;
    double inputTemperature, convertedTemperature;
    char inputUnit;

    cout << "Program Konversi Suhu" << endl;
    cout << "---------------------" << endl;
    cout << "Masukkan nilai suhu: ";
    cin >> inputTemperature;
    cout << "Masukkan jenis suhu asal (C untuk Celcius, F untuk Fahrenheit): ";
    cin >> inputUnit;

    if (inputUnit == 'C' || inputUnit == 'c') {
        // Konversi dari Celcius ke Fahrenheit
        convertedTemperature = KS.celciusToFahrenheit(inputTemperature);
        cout << fixed << setprecision(2);
        cout << inputTemperature << " derajat Celcius sama dengan " << convertedTemperature << " derajat Fahrenheit." << endl;
    } else if (inputUnit == 'F' || inputUnit == 'f') {
        // Konversi dari Fahrenheit ke Celcius
        convertedTemperature = KS.fahrenheitToCelcius(inputTemperature);
        cout << fixed << setprecision(2);
        cout << inputTemperature << " derajat Fahrenheit sama dengan " << convertedTemperature << " derajat Celcius." << endl;
    } else {
        // Input jenis suhu tidak valid
        cout << "Jenis suhu asal tidak valid. Silakan masukkan 'C' untuk Celcius atau 'F' untuk Fahrenheit." << endl;
    }
}

//fungsi untuk menghitung hari pada bulan dan tahun tertentu
void penghitung_hari(){
    int month, year;

    // Input bulan dan tahun
    cout << "Program Menghitung hari pada bulan dan tahun tertentu" << endl;
    cout << "---------------------" << endl;
    cout << "Masukkan nomor bulan (1-12): ";
    cin >> month;
    cout << "Masukkan tahun: ";
    cin >> year;

    // Validasi input
    if (month < 1 || month > 12) {
        cout << "Nomor bulan tidak valid!" << endl;
        exit(1);
    }

    // Jumlah hari dalam setiap bulan
    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
                daysInMonth = 29;
            }else{
                daysInMonth = 28;
            }
            break;
        default:
            cout << "Kesalahan input!" << endl;
            exit(1);
    }

    // Menampilkan hasil
    cout << "Jumlah hari dalam bulan " << month << " tahun " << year << " adalah " << daysInMonth << " hari." << endl;    
}

//fungsi kalkulator sederhana
void kalkulator(){
    double num1, num2, result;
    char operation;

    // Input bilangan pertama
    cout << "Program Kalkulator sederhana" << endl;
    cout << "---------------------" << endl;
    cout << "Masukkan bilangan pertama: ";
    cin >> num1;

    // Input operasi
    cout << "Masukkan operasi (+, -, *, /): ";
    cin >> operation;

    // Input bilangan kedua
    cout << "Masukkan bilangan kedua: ";
    cin >> num2;

    // Switch untuk operasi
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Hasil: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Hasil: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Hasil: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Hasil: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Kesalahan: Pembagian dengan nol tidak diperbolehkan!" << endl;
            }
            break;
        default:
            cout << "Operasi tidak valid!" << endl;
    }

}
//fungsi untuk mengecek bilangan prima pada variable n
bool checkprima(int n) {
    if (n <= 1) {
        return false; // Bilangan 1 atau kurang bukan bilangan prima
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Bilangan habis dibagi i, bukan bilangan prima
        }
    }
    return true; // Tidak ada pembagi, bilangan adalah prima
}

void penentu_prima(){
    int number;

    // Input bilangan
    cout << "Program mencari bilangan prima" << endl;
    cout << "---------------------" << endl;
    cout << "Masukkan bilangan bulat: ";
    cin >> number;

    // Menentukan apakah bilangan prima
    if (checkprima(number)) {
        cout << number << " adalah bilangan prima." << endl;
    } else {
        cout << number << " bukan bilangan prima." << endl;
    }
}

//fungsi mencari fpb dari dua variable num1 dan num2
void pencari_fpb(){
    int num1, num2;

    // Input dua bilangan bulat
    cout << "Program Menentukan fpb" << endl;
    cout << "---------------------" << endl;
    cout << "Masukkan bilangan pertama: ";
    cin >> num1;
    cout << "Masukkan bilangan kedua: ";
    cin >> num2;
    cout << "FPB dari " << num1 << " dan " << num2;
    // Mencari FPB
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    // int gcd = findGCD(num1, num2);

    // Menampilkan hasil
    cout <<" adalah " << num1 << "." << endl;

}

//fungsi menghitung luas trapesium dari 4 variable
void luas_trapesium(){
    double alas, atas, tinggi, luas;

    // Input panjang sisi alas
    cout << "Program Menghitung luas trapesium" << endl;
    cout << "---------------------" << endl;
    cout << "Masukkan panjang sisi alas: ";
    cin >> alas;

    // Input panjang sisi atas
    cout << "Masukkan panjang sisi atas: ";
    cin >> atas;

    // Input tinggi trapesium
    cout << "Masukkan tinggi trapesium: ";
    cin >> tinggi;

    // Menghitung luas trapesium
    cout << "Luas trapesium adalah: " << 0.5 * (alas + atas) * tinggi << endl;
}

int main(){
    int pilihan;

    // Menu utama
    cout << "---------------------\n" << endl;
    cout << "TUGAS ALGORITMA DAN PEMROGRAMAN\nNAMA: FATIHUR RISQI\nNIM: 241011402178\nKELAS: 01TPLP007\n\nLIST APLIKASI: \n";
    cout << "1. Simulasi Lampu Merah.\n";
    cout << "2. Konversi Suhu.\n";
    cout << "3. Penghitung Hari.\n";
    cout << "4. Kalkulator.\n";
    cout << "5. Penentu Prima.\n";
    cout << "6. Pencari FPB.\n";
    cout << "7. Penghitung Luas Trapesium.\n" << endl;
    cout << "---------------------" << endl;

    // Input pilihan menu
    cout << "Masukkan pilihan (1-7): ";
    cin >> pilihan;

    // Logika pemilihan aplikasi
    switch (pilihan) {
        case 1:
            lampu_persimpangan();
            break;
        case 2:
            konversi_suhu();
            break;
        case 3:
            penghitung_hari();
            break;
        case 4:
            kalkulator();
            break;
        case 5:
            penentu_prima();
            break;
        case 6:
            pencari_fpb();
            break;
        case 7:
            luas_trapesium();
            break;
        default:
            cout << "Pilihan tidak valid! Silakan pilih antara 1-7." << endl;
    }
    return 0;
};