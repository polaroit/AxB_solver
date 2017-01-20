g++ MatrixGauss.cpp -I C:/Users/peta/Desktop/cake/armadillo-7.500.2/include -I c:/Users/peta/Desktop/cake/include -lopenblas -L C:/Users/peta/Desktop/cake
g++ MatrixGauss.cpp -I C:/Users/peta/Desktop/cake/armadillo-7.500.2/include -I c:/Users/peta/Desktop/cake/include -I c:/Users/peta/Desktop/cake/hdf5_include -lopenblas -lhdf5 -L C:/Users/peta/Desktop/cake

start a.exe -r 5000 -ns (рандомна€ матрица и вектор n = 5000, не сохран€ть x, A, b)
start a.exe -r 5000 -ns (рандомна€ матрица и вектор n = 5000, не сохран€ть x, A, b)
start a.exe -r 5000 -s (рандомна€ матрица и вектор n = 5000, сохранить x, A, b)
start a.exe matrix.txt vector.txt -txt(или h5 или -btxt) -ns (матрица, вектор, результат не сохран€ть)
start a.exe matrix.txt vector.txt -txt(или h5 или -btxt) -s -t (матрица, вектор, результат сохранить в txt )
start a.exe matrix.txt vector.txt -txt(или h5 или -btxt) -s -h (матрица, вектор, результат сохранить в h5 )(самое быстрое сохранение!)
start a.exe matrix.txt vector.txt -txt(или h5 или -btxt) -s -all (матрица, вектор, результат сохранить в h5 и в txt )
-txt(или h5 или -btxt) - формат входных файлов.
-txt - обычный txt c символами ascii
-btxt - бинарный txt.(в начале файла должны быть байты, соответствующие ARMA_MAT_TXT_FN008 кол. строк кол. столбов)

¬ начале каждого txt файла должна быть перва€ строчка ARMA_MAT_TXT_FN008
Ќа второй строчке через пробел два числа: кол. строк кол. столбов.
 аждую строку матрицы или вектора в файле лучше начинать с пробела, но это не об€зательно.
hdf5viever - дл€ просмотра .h5. h5 удобен дл€ хранени€ больших данных.

¬ программе использованы библиотеки openblas, armadillo, hdf5.
-I C:/Users/.../armadillo-7.500.2/include - подключение заголовка armadillo
-I c:/Users/.../cake/include - подключение заголовка openblas
-I c:/Users/.../cake/hdf5_include - подключение заголовка hdf5
-lopenblas -lhdf5 - подключение .lib (.a)
-L C:/Users/.../cake путь к .lib (.a)

Openblas предоставл€ет возможность распараллелить расчет.
‘ункци€ openblas_set_num_threads(int number_of_threads);
«адает количество потоков. 0 - один основной поток.
4 - максимальное количество потоков, которое поддерживает данна€ верси€ библиотеки, собранна€ 2-х €дерной машине.
≈сли собирать openblas на машине с большим числом €дер, то можно задавать большее число потоков.
4 €дер - 8 потоков и т.д.
 

Windows 10, Intel Core I5 1.7GHz, x64, 4√б.
MinGW 64-bit

