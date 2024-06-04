
PYTORCH_SRC=/Users/junji.hashimoto/git/pytorch
PYTORCH_BLD=/Users/junji.hashimoto/git/pytorch/build
HEADERS=-I$(PYTORCH_SRC) -I$(PYTORCH_SRC)/aten/src -I$(PYTORCH_SRC)/torch/csrc/api/include -I$(PYTORCH_BLD) -I$(PYTORCH_BLD)/aten/src
LIBS=-L$(PYTORCH_BLD)/lib


all:
	/usr/bin/gcc -c c10dict.cpp -o c10dict.o $(HEADERS) -std=c++17
	/usr/bin/gcc -c c10list.cpp -o c10list.o $(HEADERS) -std=c++17
	/usr/bin/gcc -dynamiclib  -o libmain.dylib   -undefined dynamic_lookup -single_module -install_name '@rpath/libmain.dylib'c10dict.o c10list.o  $(LIBS) -lc10 -ltorch -ltorch_cpu '-lc++'
	gcc -dynamiclib -o libmain.dylib -undefined dynamic_lookup -single_module -install_name '@rpath/libHSlibtorch-ffi-2.0.0.0-inplace-ghc9.6.3.dylib' c10dict.o c10list.o $(LIBS) -lc10 -ltorch -ltorch_cpu '-lc++'

haskell:
	gcc -dynamiclib -o libmain.dylib -undefined dynamic_lookup -single_module -install_name '@rpath/libHSlibtorch-ffi-2.0.0.0-inplace-ghc9.6.3.dylib' C10Dict.dyn_o C10List.dyn_o $(LIBS) -lc10 -ltorch -ltorch_cpu '-lc++'
