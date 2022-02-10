#!/bin/bash

# benchmark submodule settings
BENCHMARK_DIR=./ext/benchmark
BENCHMARK_REPO=https://github.com/google/benchmark.git
BENCHMARK_RELEASE_TAG=v1.6.1

# googletest submodule settings
GTEST_DIR=./ext/googletest
GTEST_REPO=https://github.com/google/googletest.git
GTEST_RELEASE_TAG=release-1.11.0

echo "Warning: The current repository history/information will be deleted!"
read -p "Are you sure? (y)es/(n)o " -n 1 -r

if [[ $REPLY =~ ^[Yy]$ ]]
then
    # remove external dependencies and git information
    rm -rf $BENCHMARK_DIR
    rm -rf $GTEST_DIR
    rm -rf .git

    # init new repository
    git init

    # re-add submodules 
    git submodule add $BENCHMARK_REPO $BENCHMARK_DIR
    cd $BENCHMARK_DIR
    git checkout -b $BENCHMARK_RELEASE_TAG
    cd -

    git submodule add $GTEST_REPO $GTEST_DIR
    cd $GTEST_DIR
    git checkout -b $GTEST_RELEASE_TAG
    cd -
fi

echo "Exiting ..."



