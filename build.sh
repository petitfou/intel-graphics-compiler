#!/bin/bash

sudo apt-get install -y flex bison libz-dev cmake

# production with llvm/clang 14
# other llvm versions are experimental
sudo apt-get install llvm-14 \
		 llvm-14-dev \
		 clang-14 \
		 liblld-16 \
		 liblld-16-dev \
		 libllvmspirvlib15 \
		 libllvmspirvlib-15-dev

sudo apt-get install -y libopencl-clang-14-dev

sudo apt-get install -y spirv-headers spirv-tools

git clone https://github.com/intel/vc-intrinsics vc-intrinsics
#git clone https://github.com/KhronosGroup/SPIRV-Tools.git SPIRV-Tools
#git clone https://github.com/KhronosGroup/SPIRV-Headers.git SPIRV-Headers
git clone https://github.com/intel/intel-graphics-compiler igc

mkdir build
cd build
cmake ../igc
make -j`nproc`

