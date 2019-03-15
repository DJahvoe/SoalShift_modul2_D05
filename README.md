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
