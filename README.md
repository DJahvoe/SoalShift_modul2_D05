# SoalShift_modul2_D05

## 1 <br/>
Problem : Menambahkan _grey pada bagian belakang file ekstensi .png dipindahkan ke direktori /home/[user]/modul2/gambar <br/>
Tools :
* Daemon
* #include <dirent.h>
* Fungsi rename() <br/>
Approach :
Untuk menyelesaikan persoalan berikut, digunakan `#include <dirent.h>` sebagai Directory Library yang berfungsi agar dapat
membuka directory yang diinginkan dan melakukan trace pada tiap file yang ada di dalam directory tersebut, fungsi ini
adalah fungsi `readdir([directory])`, setelah didapatkan nama dari file di dalam Directory yang tersedia, dilakukan pengecekan
ekstensi `.png`, file yang tidak berekstensi `.png` akan di-skip. Jika file memenuhi syarat, maka dilanjutkan dengan meng-extract
nama file (tanpa ekstensi .png) dan menambahkan bagian belakang dari nama file tersebut dengan format `_gray.png`, setelah itu
dibuat directory lengkap (absolute path) yang menjadi target directory di mana file akan dipindahkan, hal ini dapat dilakukan
dengan menggunakan fungsi `rename([old_directory], [new_directory])` yang fungsionalnya mirip dengan `mv (move)` dalam linux.
