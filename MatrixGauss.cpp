// MatrixGauss.cpp : Defines the entry point for the console application.
//
//http://arma.sourceforge.net/

#include "armadillo.h"
#include <iostream>
#include <cblas.h>
#include <cstdlib>
#include <hdf5.h>





using arma::sp_mat;
using arma::sprandu;
using arma::vec;
using arma::randu;
using arma::spsolve;
using arma::mat;
using arma::trimatu;
using arma::conv_to;
using std::atoll;
using std::cout;
using std::endl;



int main(int argc, char* argv[])
{
	
	if (strcmp("-r", argv[1]) == 0)
	{
		openblas_set_num_threads(4);
		long long n = atoll(argv[2]);
		sp_mat A = sprandu<sp_mat>(n, n, 1);
		vec b = randu<vec>(n);
		vec x(n);
		x = spsolve(A, b, "lapack");
		cout << "SOLVED!" << endl;

		if (strcmp("-s", argv[3]) == 0)
		{
			cout << "SAVE..." << endl;
			arma::conv_to<mat>::from(A).save("A.h5", arma::hdf5_binary);
			x.save("X.h5", arma::hdf5_binary);
			b.save("B.h5", arma::hdf5_binary);
		}else
		  {}

	}
	else
	{
		openblas_set_num_threads(4);
		mat Buff_matr;
		vec b;
		vec x;

		if (strcmp("-btxt", argv[3]) == 0)
		{
			Buff_matr.load(argv[1], arma::arma_binary);
			b.load(argv[2], arma::arma_binary);
		}

		if (strcmp("-txt", argv[3]) == 0)
		{
			Buff_matr.load(argv[1], arma::arma_ascii);
			b.load(argv[2], arma::arma_ascii);
		}

		if (strcmp("-h5", argv[3]) == 0)
		{
			Buff_matr.load(argv[1], arma::hdf5_binary);
			b.load(argv[2], arma::hdf5_binary);
		}

		sp_mat A = arma::conv_to<sp_mat>::from(Buff_matr);
		
		x = spsolve(A, b, "lapack");
		cout << "SOLVED!" << endl;

		if (strcmp("-s", argv[4]) == 0)
		{
			cout << "SAVE..." << endl;
			if (strcmp("-t", argv[5]) == 0)
			   x.save("result.txt", arma::arma_ascii);
			if (strcmp("-h", argv[5]) == 0)
			   x.save("result.h5", arma::hdf5_binary);
			if (strcmp("-all", argv[5]) == 0)
			{
				x.save("result.txt", arma::arma_ascii);
				x.save("result.h5", arma::hdf5_binary);
			}
		}
		else {}
	}
	
	std::cout << "done!";
	std::cin.get();
	
    return 0;
}


/*пример записи в h5 файл из txt файла (нерабочий)
hsize_t dim1[3];


hid_t file_id;
herr_t status;
file_id = H5Fcreate("fileh.h5", H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

std::ifstream f("matrix.txt");
std::string str;
std::getline(f, str);
std::getline(f, str);
std::stringstream ss(str);

ss >> dim1[0] >> dim1[1];
f.close();
f.open("matrix.txt", std::ios::binary);
hid_t dataspace_id = H5Screate_simple(2, dim1, NULL);
// Create the dataset.
hid_t dataset_id = H5Dcreate(file_id, "/dset", H5T_IEEE_F64BE, dataspace_id,
	H5P_DEFAULT, H5P_DEFAULT,
	H5P_DEFAULT);
//status = H5Dclose(dataset_id);
//status = H5Sclose(dataspace_id);

status = H5Dwrite(dataset_id, H5T_IEEE_F64BE, H5S_ALL, H5S_ALL, H5P_DEFAULT, (const void *)&f);

//status = H5Fclose(file_id);*/
