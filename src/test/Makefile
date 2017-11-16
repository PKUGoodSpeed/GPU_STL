NVCC = /usr/local/cuda-8.0/bin/nvcc
FLAGS = -std=c++11 -arch=sm_35 -O3 -lcudart -lcublas -lcublas_device -lcudadevrt
BIN = apps

all: mkfolder glist gstack lglist

glist: mkfolder glist_test.cu
	$(NVCC) $(FLAGS) glist_test.cu -o $(BIN)/glist
	
gstack: mkfolder gstack_test.cu
	$(NVCC) $(FLAGS) gstack_test.cu -o $(BIN)/gstack

lglist: mkfolder lglist_test.cu
	$(NVCC) $(FLAGS) lglist_test.cu -o $(BIN)/lglist

mkfolder:
	if [ ! -d "./$(BIN)" ];then     \
		mkdir $(BIN);           \
	fi
	
clean:
	rm -rf ./apps