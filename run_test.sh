#!/BIN/SH

cd ..
make re
gcc test/main.c -o test/test_output -L -lft libft.a
mv test_output ./test/
cd test
./test_output
