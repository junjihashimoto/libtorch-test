
PYTORCH_SRC=/Users/junji.hashimoto/git/pytorch
PYTORCH_BLD=/Users/junji.hashimoto/git/pytorch/build
HEADERS=-I$(PYTORCH_SRC) -I$(PYTORCH_SRC)/aten/src -I$(PYTORCH_SRC)/torch/csrc/api/include -I$(PYTORCH_BLD) -I$(PYTORCH_BLD)/aten/src
LIBS=-L$(PYTORCH_BLD)/lib


all:
	/usr/bin/gcc -c c10dict.cpp -o c10dict.o $(HEADERS) -std=c++20 -O1
	/usr/bin/gcc -c c10list.cpp -o c10list.o $(HEADERS) -std=c++20 -O1
	/usr/bin/g++  c10dict.o c10list.o main.cpp -o main $(HEADERS)  $(LIBS) -lc10 -ltorch -ltorch_cpu -O1 -std=c++20

