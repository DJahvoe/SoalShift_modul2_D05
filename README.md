# SoalShift_modul2_D05

## 1 <br/>
- Problem : Menambahkan _grey pada bagian belakang file ekstensi .png dipindahkan ke direktori /home/[user]/modul2/gambar <br/>
- Tools :
  - Daemon
  - #include <dirent.h>
  - Fungsi rename() <br/><br/>
- Approach : <br/>
Untuk menyelesaikan persoalan berikut, digunakan `#include <dirent.h>` sebagai Directory Library yang berfungsi agar dapat
membuka directory yang diinginkan dan melakukan trace pada tiap file yang ada di dalam directory tersebut, fungsi ini
adalah fungsi `readdir([directory])`, setelah didapatkan nama dari file di dalam Directory yang tersedia, dilakukan pengecekan
ekstensi `.png`, file yang tidak berekstensi `.png` akan di-skip. Jika file memenuhi syarat, maka dilanjutkan dengan meng-extract
nama file (tanpa ekstensi .png) dan menambahkan bagian belakang dari nama file tersebut dengan format `_gray.png`, setelah itu
dibuat directory lengkap (absolute path) yang menjadi target directory di mana file akan dipindahkan, hal ini dapat dilakukan
dengan menggunakan fungsi `rename([old_directory], [new_directory])` yang fungsionalnya mirip dengan `mv (move)` dalam linux.

## 2
- Problem : Menghapus file elen.ku dalam folder hatiku setiap 3 detik dengan owner dan group www-data <br/>
- Tools :
	- Daemon
	- #include <sys/stat.h>
	- struct stat
	- Fungsi stat([directory])
	- id -u <username>
	- chmod ([directory], [mode]) <br/><br/>
- Approach : <br/>
Untuk menyelesaikan persoalan berikut, digunakan `struct stat` yang berfungsi untuk mengextract detail dari sebuah file tertentu.
ekstraksi bertujuan untuk mendapatkan `owner_id` dan `group_id`, sedangkan untuk memastikan bahwa owner dan group yang dibandingkan
adalah www-data maka perlu dilakukannya pre-compute dengan cara `id -u www-data`, dengan ini akan didapatkan value 33. Setelah itu,
sebelum file dapat dihapus perlu mengubah permission file tersebut menjadi mode `777`, dilakukan dengan menggunakan `chmod([directory], 777)`
setelah mengganti permission, file dapat diremove menggunakan `remove([directory])`.

## 3
- Problem : Membuat daftar file berekstensi .txt dalam sebuah file zip <br/>
- Tools :
	- pipe()
	- read([string],[target string],[size]);
	- FILE
	- dup2(fildes, fildes2);
	- STDOUT_FILENO & STDIN_FILENO <br/> <br/>
- Approach : <br/> 
Langkah pertama dalam menyelesaikan problem ini adalah dengan mengekstrak file campur2.zip dengan `exec`. setelah file terekstrak kita melakukan exec `ls campur2` dengan menyimpan hasil output di suatu parameter `dup2(argv[#],STDOUT_FILENO);` fungsi dup2() sendiri adalah untuk menduplikasi open file descriptor. Selanjutnya mengambil hasil ls yang memiliki ekstensi .txt dengan exec `grep .txt`. Kita menggunakan `STDIN_FILENO` sebagai pengganti inputan. Setelah itu untuk mendapatkan hasil grep kita membaca paramater dengan read() dan menyimpanya pada sebuah string. Terakhir kita membuat file daftar.txt dan mengisinya dengan string yang telah kita siapkan menggunakan `FILE`.

## 4
- Problem : Membuat file makan_sehat#.txt ketika membuka file makanan_enak.txt saat range pengecekan waktu < 30 s <br/>
- Tools :
	- Daemon
	- #include <time.h>
	- FILE
	- struct stat <br/> <br/>
- Approach : <br/> 
Untuk menyelesaikan persoalan berikut, pertama-pertama harus dicari waktu sekarang (now) dan waktu file terakhir dibuka/diedit dengan lib `file.st_atime`. Setelah itu kita membandingkan perbedaan waktu sekarang dengan terakhir file dibuka menggunakan fungsi `difftime()`. Jika perbedaan waktu < 30 s maka akan membuat sebuah makan_sehat#.txt dengan # adalah increment nomor file.
Umntuk membuat file sehat kita menggunakan `FILE` dengan penamaan increment. Kita menyediakan string makan_sehat ditambah # (increment nomor) dan ekstensi .txt
Agar program berjalan tiap 5 detik artinya kita melakukan sleep(5); dalam program

## 5
- Problem : Membuat log tiap menit dari syslog (increment), dan membuat directory per 30 menit <br/>
- Tools :
	- Daemon
	- #include <time.h>
	- mkdir([directory])
	- FILE
	- strftime([target_string], [size], [print], [parameter]) <br/> <br/>
- Approach : <br/> 
Untuk menyelesaikan persoalan berikut, pertama-pertama harus dicari waktu sekarang (now) dari fungsi `localtime(variable)`.
Selanjutnya directory akan dibuat dengan `mkdir` sesuai string waktu yang didapatkan. Di dalam directory yang telah ada,
dibuat file baru tiap menit dengan `sleep(60)` hingga counter mencapai 30, sehingga directory baru akan dibuat setelah 30 menit berikutnya.
untuk mempermudah pembuatan nama file dan directory, dapat digunakan fungsi `strcat`, `strcpy`, dan `sprintf`. Setelah itu dibuka file dengan
mode `read` untuk directory `/var/log/syslog` sebagai source, dan membuka file directory dengan nama `log#.log` (dengan # sebagai increment menit)
dengan mode `write`, meng-copy seluruh isi file `var/log/syslog` ke file `log#.log` menggunakan `fgetc` untuk melakukan `read` pada source, dan `fputc` untuk
`write` pada target.
