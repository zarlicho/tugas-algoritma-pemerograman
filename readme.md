# Tugas Algoritma dan Pemrograman

## Deskripsi Proyek
Proyek ini berisi beberapa aplikasi sederhana yang diimplementasikan dalam bahasa C++ untuk menyelesaikan berbagai permasalahan algoritma dan pemrograman. Setiap aplikasi dapat diakses melalui menu utama.

## Fungsi dan Penjelasan
### 1. **Simulasi Lampu Lalu Lintas** (`lampu_persimpangan`)
   - **Deskripsi**: Simulasi lampu lalu lintas simpang 4 menggunakan aturan tertentu berdasarkan kode traffic light (merah, kuning, hijau).
   - **Komponen Utama**:
     - **Class `TrafficLight`**:
       - `drawTraf`: Memvisualisasikan keadaan lampu lalu lintas untuk dua jalan.
       - `traffic`: Mengatur logika perubahan status lampu lalu lintas.
   - **Cara Kerja**:
     - Pengguna memasukkan kode traffic light (1: merah, 7: kuning, 8: hijau).
     - Program menampilkan simulasi lampu lalu lintas dalam konsol.
   - **Durasi Lampu**:
     - Merah: 5 detik.
     - Kuning: 3 detik.
     - Hijau: 5 detik.

---

### 2. **Konversi Suhu** (`konversi_suhu`)
   - **Deskripsi**: Mengonversi suhu antara Celcius dan Fahrenheit.
   - **Class `KonversiSuhu`**:
     - `celciusToFahrenheit`: Mengonversi Celcius ke Fahrenheit.
     - `fahrenheitToCelcius`: Mengonversi Fahrenheit ke Celcius.
   - **Cara Kerja**:
     - Pengguna memasukkan suhu awal dan jenisnya (C/F).
     - Program menampilkan hasil konversi suhu.

---

### 3. **Penghitung Hari dalam Bulan** (`penghitung_hari`)
   - **Deskripsi**: Menghitung jumlah hari dalam bulan tertentu pada tahun tertentu.
   - **Cara Kerja**:
     - Pengguna memasukkan bulan (1-12) dan tahun.
     - Program menampilkan jumlah hari dalam bulan tersebut, termasuk mempertimbangkan tahun kabisat (Februari: 28/29 hari).

---

### 4. **Kalkulator Sederhana** (`kalkulator`)
   - **Deskripsi**: Melakukan operasi matematika dasar (penjumlahan, pengurangan, perkalian, pembagian).
   - **Cara Kerja**:
     - Pengguna memasukkan dua bilangan dan operasi yang diinginkan (`+`, `-`, `*`, `/`).
     - Program menampilkan hasil perhitungan.
     - Membatasi pembagian dengan nol untuk menghindari kesalahan.

---

### 5. **Penentu Bilangan Prima** (`penentu_prima`)
   - **Deskripsi**: Menentukan apakah sebuah bilangan bulat adalah bilangan prima.
   - **Fungsi `checkprima`**:
     - Mengecek apakah bilangan habis dibagi oleh angka lain selain 1 dan dirinya sendiri.
   - **Cara Kerja**:
     - Pengguna memasukkan bilangan bulat.
     - Program menampilkan hasil apakah bilangan tersebut adalah prima atau bukan.

---

### 6. **Pencari Faktor Persekutuan Terbesar (FPB)** (`pencari_fpb`)
   - **Deskripsi**: Mencari FPB dari dua bilangan bulat menggunakan algoritma Euclid.
   - **Cara Kerja**:
     - Pengguna memasukkan dua bilangan bulat.
     - Program menghitung dan menampilkan FPB dari kedua bilangan.

---

### 7. **Penghitung Luas Trapesium** (`luas_trapesium`)
   - **Deskripsi**: Menghitung luas trapesium berdasarkan panjang sisi atas, alas, dan tinggi.
   - **Cara Kerja**:
     - Pengguna memasukkan panjang sisi alas, sisi atas, dan tinggi.
     - Program menghitung dan menampilkan luas trapesium menggunakan rumus:
       \[
       Luas = \frac{1}{2} \times (alas + atas) \times tinggi
       \]

---

## Cara Menjalankan Program
1. **Kompilasi program**:
   ```bash
   g++ main.cpp -o tugas

