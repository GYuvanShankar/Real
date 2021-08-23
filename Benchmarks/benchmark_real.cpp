 #include<benchmark/benchmark.h>
 #include<real/real.hpp>
 #include "include/helper.hpp"
 #define M 100
 
 static void BM_add_int(benchmark::State& state){
	 for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomIntegerOfLen(state.range(0));
		 std::string str_b=randomIntegerOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;
		 boost::real::real b(str_b);

		 state.ResumeTiming();

		 boost::real::real sum=a+b;
	 }
	 
}
static void BM_add_real(benchmark:: State& state){
	for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomRealOfLen(state.range(0));
		 std::string str_b=randomRealOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;
		 boost::real::real b(str_b);

		 state.ResumeTiming();

		 boost::real::real sum=a+b;
	 }
}
static void BM_multiply_int(benchmark:: State& state){
	for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomIntegerOfLen(state.range(0));
		 std::string str_b=randomIntegerOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;
		 boost::real::real b(str_b);

		 state.ResumeTiming();

		 boost::real::real res=a*b;
	 }
}
static void BM_multiply_real(benchmark:: State& state){
	for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomRealOfLen(state.range(0));
		 std::string str_b=randomRealOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;
		 boost::real::real b(str_b);

		 state.ResumeTiming();

		 boost::real::real res=a*b;
	 }
}
static void BM_divide_int(benchmark:: State& state){
    for(auto _:state){
        state.PauseTiming();
        
         std::string str_a=randomIntegerOfLen(state.range(0));
		 std::string str_b=randomIntegerOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;
		 boost::real::real b(str_b);

		 state.ResumeTiming();
		 
		 boost::real::real res=a/b;
	}
}
static void BM_divide_real(benchmark:: State& state){
    for(auto _:state){
        state.PauseTiming();
        
         std::string str_a=randomRealOfLen(state.range(0));
		 std::string str_b=randomRealOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;
		 boost::real::real b(str_b);

		 state.ResumeTiming();
		 
		 boost::real::real res=a/b;
	}
}
static void BM_power(benchmark::State& state){
	for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomRealOfLen(state.range(0));
		 std::string str_b=randomRealOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;
		 boost::real::real b(str_b);

		 state.ResumeTiming();

		 boost::real::real res = boost::real::real<int>::power(a,b);
	 }
}

static void BM_sqrt(benchmark::State& state){
	for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomRealOfLen(state.range(0));
		 boost::real::real a(str_a) ;

		 state.ResumeTiming();

		 boost::real::real res = boost::real::real<int>::sqrt(a);
	 }
}

static void BM_exp(benchmark::State& state){
	for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;

		 state.ResumeTiming();

		 boost::real::real res=boost::real::real<int>::exp(a);
	 }
}

static void BM_log(benchmark::State& state){
	for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;

		 state.ResumeTiming();

		 boost::real::real res=boost::real::real<int>::log(a);
	 }
}

static void BM_sin(benchmark::State& state){
	for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;

		 state.ResumeTiming();

		 boost::real::real res=boost::real::real<int>::sin(a);
	 }
}

static void BM_cos(benchmark::State& state){
	for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;

		 state.ResumeTiming();

		 boost::real::real res=boost::real::real<int>::cos(a);
	 }
}

static void BM_tan(benchmark::State& state){
	for(auto _:state){
		 
		 state.PauseTiming();

		 std::string str_a=randomRealOfLen(state.range(0));
		 
		 boost::real::real a(str_a) ;

		 state.ResumeTiming();

		 boost::real::real res=boost::real::real<int>::tan(a);
	 }
}

 BENCHMARK(BM_add_int)->RangeMultiplier(10)->Range(10,M);
 BENCHMARK(BM_add_real)->RangeMultiplier(10)->Range(10,M);
 
 BENCHMARK(BM_multiply_int)->RangeMultiplier(10)->Range(10,M/10);
 BENCHMARK(BM_multiply_real)->RangeMultiplier(10)->Range(10,M/10);
 
 BENCHMARK(BM_divide_int)->RangeMultiplier(10)->Range(10,M/10);
 BENCHMARK(BM_divide_real)->RangeMultiplier(10)->Range(10,M/10);
 
 BENCHMARK(BM_power)->RangeMultiplier(8)->Range(8,1024);
 BENCHMARK(BM_sqrt)->RangeMultiplier(8)->Range(8,1024);
 BENCHMARK(BM_exp)->RangeMultiplier(8)->Range(8,1024);
 
 BENCHMARK(BM_sin)->RangeMultiplier(8)->Range(8,1024);
 BENCHMARK(BM_cos)->RangeMultiplier(8)->Range(8,1024);
 BENCHMARK(BM_tan)->RangeMultiplier(8)->Range(8,1024);
 
 BENCHMARK_MAIN();
 /*
 1. boost::real(const std::string& number)
2. boost::real(const std::string& number, std::string type)
3. boost::real(const std::string& number, boost::real::TYPE)
4. boost::real(const initializer_vector<int> digits)
5. boost::real(const initializer_vector<int> digits, bool positive)
6. boost::real(const initializer_vector<int> digits, int exponent)
7. boost::real(const initializer_vector<int> digits, int exponent, bool positive)
8. boost::real((unsigned int) -> int digits, int exponent)
9. boost::real((unsigned int) -> int digits, int exponent, bool positive)
10. boost::real(const boost::real& x)
11. boost::~real()

1. boost::real operator+=(const boost::real& x)
2. boost::real operator-=(const boost::real& x)
3. boost::real operator*=(const boost::real& x)
4. boost::real operator+(const boost::real& x) const
5. boost::real operator-(const boost::real& x) const
6. boost::real operator*(const boost::real& x) const
7. boost::real& operator=(const boost::real& x)
8. boost::real& operator=(const std::string& x)
9. boost::real& operator==(const boost::real& x)
10. bool operator<(const real& other) const
11. std::ostream& operator<<(std::ostream& os, const boost::real& x)
12. int operator[](unsigned int n) const

1. boost::real power(boost::real number, boost::real power)
2. boost::real sqrt(boost::real number)
3. boost::real exp(boost::real number)
4. boost::real log(boost::real number)
5. boost::real sin(boost::real number)
6. boost::real cos(boost::real number)
7. boost::real tan(boost::real number)
8. boost::real sec(boost::real number)
9. boost::real cosec(boost::real number)
10.boost::real cot(boost::real number) 
*/
