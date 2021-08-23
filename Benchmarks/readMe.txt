******************TO COMPILE, RUN AND OUTPUT DATA IN A FILE********

To compile a code:
g++ "File_name.cpp" -std=c++17 -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -lpthread -o "output_file_name"

To run the output file:
./output_file_name

To save the output in a JSON file:
./output_file_name --benchmark_out="Benchmark_result.json" --benchmark_out_format="json"

To run some sepcific function (it uses regex matching):
./output_file_name --benchmark_filter="function_name_pattern"


*******************TO DISPLAY RESULTS IN WEBPAGE******************

index.html and index.js are the two files responsible for showing results in a webpage.
On a local machine, for security purpose a browser doesn't allow to access file system directly.

Hence one needs to create a local http server.
    In python:python -m http.server
    In node: http-server
    
While being on a remote server Links can be directly attached.

