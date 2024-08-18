#!/bin/bash

# Valida uma solução de acordo com os casos de testes da OBI.
#
# Autor: Edson Alves
# Data: 17/08/2024
# Licença: LGPL. Sem copyright.

# Arguments validation
if [ "$#" -lt 2 ]; then
    echo "Usage: $0 solution.[c|cpp|py] tests.zip [time limit in s] [memory limit in Kb]"
    exit
fi

# Local variables
solution=$1
tests=$2
time_limit=1.0
memory_limit=512000

if [ "$#" -gt 2 ]; then
    time_limit=`echo $3 | bc`
fi

if [ "$#" -gt 3 ]; then
    memory_limit=`echo $4 | bc`
fi

# Extracting test cases
echo "Extracting $tests..."

tests_dir="/tmp/obi_tests"

rm -rf $tests_dir
mkdir -p $tests_dir

if ! unzip -q $tests -d $tests_dir; then
    echo "Tests extraction failed: '$tests' invalid of corrupted!"
    exit -1
fi

# Compiling solution
filename=$(basename ${solution})
extension="${filename##*.}"

echo "Compiling $solution..."

if [ $extension == "cpp" ]; then
    if ! g++ -o prog -W -Wall -O2 -std=c++20 -Wextra -Wshadow -Wformat=2 -Wconversion -fsanitize=address,undefined -fno-sanitize-recover -Wfatal-errors -static-libasan $solution; then
        echo "Compilation failed!"
        exit -2
    fi
elif [ $extension == "c" ]; then
    if ! gcc -o prog -W -Wall -pedantic -std=c99 -O2 -Wno-unused-result $solution; then
        echo "Compilation failed!"
        exit -2
    fi
elif [ $extension == "py" ]; then
    rm -rf prog
    echo "#!/usr/bin/python" > prog

    if ! cat $solution >> prog; then
        echo "File '$solution' not found"
        exit -2;
    fi

    chmod u+x prog
else
    echo "Invalid extension: '.$extension'"
    exit -2
fi

# Checking test cases
for dir in `ls $tests_dir`; do
    test_sets=`ls $tests_dir/$dir | sort`

    max_elapsed=0.0
    max_memory=0

    for test_set in $test_sets; do
        echo "Test set #$test_set"
        
        tests=`ls $tests_dir/$dir/$test_set/*.in`

        for t in $tests; do
            test_name=$(basename ${t})
            test_name="${test_name%.*}"

            echo -n "  - Test $test_name: "
            sol=`echo $t | sed s/in$/sol/`

            if ! env time -f "%e %M %x" ./prog < $t > sol 2> report.txt; then
                echo "Runtime Error!"
                exit -3
            fi

            read -a report < report.txt
            elapsed=`echo ${report[0]} | bc`
            memory=`echo ${report[1]} | bc`
            rc=`echo ${report[2]} | bc`

            if [ $rc -ne 0 ]; then
                echo "Runtime Error!"
                exit -3
            fi

            if ! diff -q sol $sol; then
                echo "Wrong Answer"
                exit -3
            fi

            if (( $(echo "$elapsed > $time_limit" | bc -l) )); then
                echo "Time Limit Exceeded!"
                exit -3
            fi

            if (( $(echo "$memory > $memory_limit" | bc -l) )); then
                echo "Memory Limit Exceeded!"
                exit -3
            fi

            if (( $(echo "$elapsed > $max_elapsed" | bc -l) )); then
                max_elapsed=$elapsed
            fi

            if (( $(echo "$memory > $max_memory" | bc -l) )); then
                max_memory=$memory
            fi

            echo "Ok, $elapsed s, $memory Kb"
        done
    done

    echo -e "\nAccepted: $max_elapsed s, $max_memory Kb"
done
