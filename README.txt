g++ MatrixGauss.cpp -I C:/Users/peta/Desktop/cake/armadillo-7.500.2/include -I c:/Users/peta/Desktop/cake/include -lopenblas -L C:/Users/peta/Desktop/cake
g++ MatrixGauss.cpp -I C:/Users/peta/Desktop/cake/armadillo-7.500.2/include -I c:/Users/peta/Desktop/cake/include -I c:/Users/peta/Desktop/cake/hdf5_include -lopenblas -lhdf5 -L C:/Users/peta/Desktop/cake

start a.exe -r 5000 -ns (��������� ������� � ������ n = 5000, �� ��������� x, A, b)
start a.exe -r 5000 -ns (��������� ������� � ������ n = 5000, �� ��������� x, A, b)
start a.exe -r 5000 -s (��������� ������� � ������ n = 5000, ��������� x, A, b)
start a.exe matrix.txt vector.txt -txt(��� h5 ��� -btxt) -ns (�������, ������, ��������� �� ���������)
start a.exe matrix.txt vector.txt -txt(��� h5 ��� -btxt) -s -t (�������, ������, ��������� ��������� � txt )
start a.exe matrix.txt vector.txt -txt(��� h5 ��� -btxt) -s -h (�������, ������, ��������� ��������� � h5 )(����� ������� ����������!)
start a.exe matrix.txt vector.txt -txt(��� h5 ��� -btxt) -s -all (�������, ������, ��������� ��������� � h5 � � txt )
-txt(��� h5 ��� -btxt) - ������ ������� ������.
-txt - ������� txt c ��������� ascii
-btxt - �������� txt.(� ������ ����� ������ ���� �����, ��������������� ARMA_MAT_TXT_FN008 ���. ����� ���. �������)

� ������ ������� txt ����� ������ ���� ������ ������� ARMA_MAT_TXT_FN008
�� ������ ������� ����� ������ ��� �����: ���. ����� ���. �������.
������ ������ ������� ��� ������� � ����� ����� �������� � �������, �� ��� �� �����������.
hdf5viever - ��� ��������� .h5. h5 ������ ��� �������� ������� ������.

� ��������� ������������ ���������� openblas, armadillo, hdf5.
-I C:/Users/.../armadillo-7.500.2/include - ����������� ��������� armadillo
-I c:/Users/.../cake/include - ����������� ��������� openblas
-I c:/Users/.../cake/hdf5_include - ����������� ��������� hdf5
-lopenblas -lhdf5 - ����������� .lib (.a)
-L C:/Users/.../cake ���� � .lib (.a)

Openblas ������������� ����������� �������������� ������.
������� openblas_set_num_threads(int number_of_threads);
������ ���������� �������. 0 - ���� �������� �����.
4 - ������������ ���������� �������, ������� ������������ ������ ������ ����������, ��������� 2-� ������� ������.
���� �������� openblas �� ������ � ������� ������ ����, �� ����� �������� ������� ����� �������.
4 ���� - 8 ������� � �.�.
 

Windows 10, Intel Core I5 1.7GHz, x64, 4��.
MinGW 64-bit

