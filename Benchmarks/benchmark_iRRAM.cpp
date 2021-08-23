#include<benchmark/benchmark.h>
#include<unistd.h>
#include<sys/wait.h>

#include "include/helper.hpp"
#define M 100000
#define precision 40

static void BM_overhead(benchmark:: State& state){

     int n=state.range(0);
     char* ar_a=new char[n+1];
     
	for(auto _:state){
		
		//Pausing timer for variable declaration and constructors.		 
		 state.PauseTiming();
         
		 std::string str_a=randomIntegerOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);

		 state.ResumeTiming();

		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 int status=execl("iRRAM_FUNCTIONS/BM_overhead",ar_a,ar_a,NULL);
			 if(status){
			    std::cerr<<"Error opening BM_overhead\n";
			    exit(127);
             }
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
		 
	 }
	 delete(ar_a);
}
static void BM_add_int(benchmark:: State& state){

     int n=state.range(0);
     char* ar_a=new char[n+1];
     char* ar_b=new char[n+1];
     
	for(auto _:state){
		
		//Pausing timer for variable declaration and constructors.		 
		 state.PauseTiming();
         
		 std::string str_a=randomIntegerOfLen(state.range(0));
		 std::string str_b=randomIntegerOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 toCharArray(str_b,ar_b);
		 

		 state.ResumeTiming();

		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 int status=execl("iRRAM_FUNCTIONS/BM_add_int",ar_a,ar_b,NULL);
			 if(status){
			    std::cerr<<"Error opening BM_add_int\n";
			    exit(127);
             }
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
		 
	 }
	 delete(ar_a);
	 delete(ar_b);
}
static void BM_add_real(benchmark:: State& state){

     int n=state.range(0);
     char* ar_a=new char[n+2];
     char* ar_b=new char[n+2];
     
	for(auto _:state){
		
		//Pausing timer for variable declaration and constructors.		 
		 state.PauseTiming();
         
		 std::string str_a=randomRealOfLen(state.range(0));
		 std::string str_b=randomRealOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 toCharArray(str_b,ar_b);
		 

		 state.ResumeTiming();

		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 int status=execl("iRRAM_FUNCTIONS/BM_add_real",ar_a,ar_b,NULL);
			 
			 if(status){
			    std::cerr<<"Error opening BM_add_real\n";
			    exit(127);
             }
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
	 }
	 delete(ar_a);
	 delete(ar_b);
}
static void BM_multiply_int(benchmark:: State& state){

    int n=state.range(0);
	char* ar_a=new char[n+1];
	char* ar_b=new char[n+1];
	
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomIntegerOfLen(state.range(0));
		 std::string str_b=randomIntegerOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 toCharArray(str_b,ar_b);

		 state.ResumeTiming();
 
		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 int status=execl("iRRAM_FUNCTIONS/BM_multiply_int",ar_a,ar_b,NULL);
			 
			 if(status){
			    std::cerr<<"Error opening BM_multiply_int\n";
			    exit(127);
             }
			 exit(0);
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
		 
	 }
	 delete(ar_a);
	 delete(ar_b);
}
static void BM_multiply_real(benchmark:: State& state){

    int n=state.range(0);
	char* ar_a=new char[n+2];
	char* ar_b=new char[n+2];
	
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomRealOfLen(state.range(0));
		 std::string str_b=randomRealOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 toCharArray(str_b,ar_b);

		 state.ResumeTiming();
 
		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 int status=execl("iRRAM_FUNCTIONS/BM_multiply_real",ar_a,ar_b,NULL);
			 if(status){
			    std::cerr<<"Error opening BM_multiply_real\n";
			    exit(127);
             }
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
		 
	 }
	 delete(ar_a);
	 delete(ar_b);
}
static void BM_divide_int(benchmark:: State& state){

    int n=state.range(0);
	char* ar_a=new char[n+1];
	char* ar_b=new char[n+1];
	
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomIntegerOfLen(state.range(0));
		 std::string str_b=randomIntegerOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 toCharArray(str_b,ar_b);
		 
		 state.ResumeTiming();
		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 int status=execl("iRRAM_FUNCTIONS/BM_divide_int",ar_a,ar_b,NULL);
			 
			 if(status){
			    std::cerr<<"Error opening BM_divide_int\n";
			    exit(127);
             }
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
	 }
	 delete(ar_a);
	 delete(ar_b);
}
static void BM_divide_real(benchmark:: State& state){

    int n=state.range(0);
	char* ar_a=new char[n+2];
	char* ar_b=new char[n+2];
	 
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomRealOfLen(state.range(0));
		 std::string str_b=randomRealOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 toCharArray(str_b,ar_b);

		 state.ResumeTiming();
		 
		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 int status=execl("iRRAM_FUNCTIONS/BM_divide_real",ar_a,ar_b,NULL);
			 if(status){
			    std::cerr<<"Error opening BM_divide_real\n";
			    exit(127);
             }
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
	 }
	 delete(ar_a);
	 delete(ar_b);
}
static void BM_power(benchmark::State& state){

    int n=state.range(0);
	char* ar_a=new char[n+2];
	char* ar_b=new char[n+2];
	 
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomRealOfLen(state.range(0));
		 std::string str_b=randomRealOfLen(state.range(0));
		 toCharArray(str_a,ar_a);
		 toCharArray(str_b,ar_b);
		 
		 state.ResumeTiming();

		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 int status=execl("iRRAM_FUNCTIONS/BM_power",ar_a,ar_b,NULL);
			 if(status){
			    std::cerr<<"Error opening BM_power\n";
			    exit(127);
             }
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
	 }
	 delete(ar_a);
	 delete(ar_b);
}

static void BM_sqrt(benchmark::State& state){

    int n=state.range(0);
	char* ar_a=new char[n+2];
	
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 

		 state.ResumeTiming();
		 
		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 execl("iRRAM_FUNCTIONS/BM_sqrt",ar_a,ar_a,NULL);
			 exit(0);
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
	 }
	 delete(ar_a);
}

static void BM_exp(benchmark::State& state){

    int n=state.range(0);
	char* ar_a=new char[n+2];
	
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
	     
		 state.ResumeTiming();
		 
		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 execl("iRRAM_FUNCTIONS/BM_exp",ar_a,ar_a,NULL);
			 exit(0);
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
	 }
	 delete(ar_a);
}

static void BM_log(benchmark::State& state){
    int n=state.range(0);
	char* ar_a=new char[n+2];
	
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 

		 state.ResumeTiming();
		 
		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 execl("iRRAM_FUNCTIONS/BM_log",ar_a,ar_a,NULL);
			 exit(0);
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
	 }
	 delete(ar_a);
}

static void BM_sin(benchmark::State& state){
    int n=state.range(0);
	char* ar_a=new char[n+2];
	
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 

		 state.ResumeTiming();
		 
		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 execl("iRRAM_FUNCTIONS/BM_sin",ar_a,ar_a,NULL);
			 exit(0);
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
	 }
	 delete(ar_a);
}

static void BM_cos(benchmark::State& state){
    int n=state.range(0);
	char* ar_a=new char[n+2];
	
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 

		 state.ResumeTiming();
		 
		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 execl("iRRAM_FUNCTIONS/BM_cos",ar_a,ar_a,NULL);
			 exit(0);
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
	 }
	 delete(ar_a);
}

static void BM_tan(benchmark::State& state){
    int n=state.range(0);
	char* ar_a=new char[n+2];
	
	for(auto _:state){
		 
		 //Pausing timer for variable declaration and constructors.
		 state.PauseTiming();
         
		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 toCharArray(str_a,ar_a);
		 

		 state.ResumeTiming();
		 
		 int pid=fork();

		 //If the process is child process 
		 if(!pid){
			 execl("iRRAM_FUNCTIONS/BM_tan",ar_a,ar_a,NULL);
			 exit(0);
		 }
		 //Else Wait for the execution of child process.
		 else wait(NULL);
	 }
	 delete(ar_a);
}

 BENCHMARK(BM_overhead)->RangeMultiplier(10)->Range(10,M);
 BENCHMARK(BM_overhead)->RangeMultiplier(8)->Range(8,1024);
 BENCHMARK(BM_add_int)->RangeMultiplier(10)->Range(10,M);
 BENCHMARK(BM_add_real)->RangeMultiplier(10)->Range(10,M);
 
 BENCHMARK(BM_multiply_int)->RangeMultiplier(10)->Range(10,M/100);
 BENCHMARK(BM_multiply_real)->RangeMultiplier(10)->Range(10,M/100);
 
 BENCHMARK(BM_divide_int)->RangeMultiplier(10)->Range(10,M/100);
 BENCHMARK(BM_divide_real)->RangeMultiplier(10)->Range(10,M/100);

// BENCHMARK(BM_power)->RangeMultiplier(8)->Range(8,1024);
 BENCHMARK(BM_sqrt)->RangeMultiplier(8)->Range(8,1024);
// BENCHMARK(BM_exp)->RangeMultiplier(8)->Range(8,1024);
 
 BENCHMARK(BM_sin)->RangeMultiplier(8)->Range(8,1024);
 BENCHMARK(BM_cos)->RangeMultiplier(8)->Range(8,1024);
 BENCHMARK(BM_tan)->RangeMultiplier(8)->Range(8,1024);

 BENCHMARK_MAIN();
