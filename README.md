# Tubes-IF2111-2021-2022-Kel-22

Program dibuat menggunakan bahasa C dengan memanfaatkan ADT yang sudah dipelajari pada mata kuliah IF2111 Algoritma dan Struktur Data STI. Pada awal permainan, pemain akan dimunculkan dengan dua pilihan, yaitu start game dan quit. Jika memilih start game dan memasukan jumlah serta nama pemain, pemain akan memberikan masukan yang akan menjadi command secara bergiliran jika turn telah berakhir. Command yang valid pada permainan ini adalah BUFF, ENDTURN, UNDO, INSPECT, MAP, ROLL, dan SKILL. Permainan akan terus berlangsung sesuai dengan jumlah pemain yang dimasukkan di awal hingga salah satu pemain telah mencapai petak terakhir.

Kelompok 22
1. Pavita Andrea                (18220014)
2. Haje Noorjamani              (18220085)
3. Michel Vito Adinugroho       (18220066)
4. Siti Adira Ramadhani         (18220094)
5. Natasha Tiovanny Silaban     (18220101)

Cara menjalankan permainan:

gcc ./src/adt/Array/array.c ./src/adt/Command/command.c ./src/adt/Impskill/impskill.c ./src/adt/Inspect/inspect.c ./src/adt/Listdp/listdp.c ./src/adt/Listskill/listskill.c ./src/adt/Map/map.c ./src/adt/Mesin_KataMesin_Karakter/mesin_kar.c ./src/adt/Mesin_KataMesin_Karakter/mesin_kata.c ./src/adt/Player/player.c ./src/adt/Rolldadu/rolldadu.c ./src/adt/Stack/stack.c ./src/main.c -o main

./main
