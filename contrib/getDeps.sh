#!/bin/bash
rm -rf dependencies
mkdir dependencies
git clone --recursive 'https://github.com/zyantific/zydis.git' dependencies/zydis

pushd dependencies

pushd zydis
mkdir build
pushd build
cmake ..
make
popd
popd

popd
