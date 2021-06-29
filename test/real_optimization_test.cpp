#include <catch2/catch.hpp>
#include <real/real.hpp>

TEST_CASE("Optimize") {

    using real = boost::real::real<int>;

    SECTION("Optimize method") {

        SECTION("Top node is +") {
            real a("1"), b("3");
            real c = b, d = b;
            for (int i = 0; i < 5; i++) {
                c += a;
                d += a;
            }
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 3);   // c is b + 5 * a
            CHECK(d.find_num_nodes() == 6);   // d is b + a + a + a + a + a 
            
            
            c = ((a - a) + a) + (b * b);
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 3);   // c is a + (b * b)
            CHECK(d.find_num_nodes() == 5);   // d is ((a - a) + a) + (b * b);


            c = (((a + a) * (a - a)) + (a + b)) + a;
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 6);   // c is ((2 * a) * 0) + (2 * a + b)
            CHECK(d.find_num_nodes() == 7);   // d is (((a + a) * (a - a)) + (a + b)) + a


            c = (a - a) + (a - a);
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 1);   // c is 0
            CHECK(d.find_num_nodes() == 4);   // d is (a - a) + (a - a)


            c = ((a - a) + (a - a)) + a;
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 1);   // c is a
            CHECK(d.find_num_nodes() == 5);   // d is ((a - a) + (a - a)) + a


            c = ((a - a) - (a - a)) + (b - b);
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 1);   // c is 0
            CHECK(d.find_num_nodes() == 6);   // d is ((a - a) - (a - a)) + (b - b)
        }

        SECTION("Top Node is -") {
            real a("1"), b("3");
            real c = b, d = b;
            for (int i = 0; i < 5; i++) {
                c -= a;
                d -= a;
            }
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 3);   // c is b - 5 * a
            CHECK(d.find_num_nodes() == 6);   // d is b - a - a - a - a - a 


            c = ((a - a) - a) - (b * b);
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 4);   // c is (-1) * a - (b * b)
            CHECK(d.find_num_nodes() == 5);   // d is ((a - a) - a) - (b * b)     


            c = (((a + a) * (a - a)) + (a + b)) - a;
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 4);   // c is ((2 * a) * 0) + b
            CHECK(d.find_num_nodes() == 7);   // d is (((a + a) * (a - a)) + (a + b)) - a    


            c = (a - a) - (a - a);
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 1);   // c is 0
            CHECK(d.find_num_nodes() == 4);   // d is (a - a) - (a - a)


            c = ((a - a) + (a - a)) - a;
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 2);   // c is (-1) * a
            CHECK(d.find_num_nodes() == 5);   // d is ((a - a) + (a - a)) - a
        }

        SECTION("Top node is other than +/-") {
            real a("1"), b("3");
            real c = b, d;
            for (int i = 0; i < 5; i++) {
                c += a;
            }
            c *= b;
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 4);   // c is (b + 5 * a) * b;
            CHECK(d.find_num_nodes() == 7);   // d is (b + a + a + a + a + a) * b 


            c = b;
            for (int i = 0; i < 5; i++) {
                c += a;
            }
            c /= a;
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 4);   // c is (b + 5 * a) / a;
            CHECK(d.find_num_nodes() == 7);   // d is (b + a + a + a + a + a) / a 


            c = b;
            real c1 = b;
            for (int i = 0; i < 5; i++) {
                c += a;
                c1 -= a;
            }
            c *= c1;
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 6);   // c is (b + 5 * a) * (b - 5 * a)
            CHECK(d.find_num_nodes() == 12);   // d is (b + a + a + a + a + a) * (b - a - a - a - a - a)
            

            c = ((a - a) + a) * (b * b);
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 3);   // c is a * (b * b)
            CHECK(d.find_num_nodes() == 5);   // d is ((a - a) + a) * (b * b)


            c = (a - a) * (a / a);
            d = c;
            c.optimize();
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 3);   // c is 0 * (a / a)
            CHECK(d.find_num_nodes() == 4);   // d is (a - a) * (a / a)
        }
    }

    SECTION("Set optimize frequency") {

        SECTION("Top node is +") {
            real a("1"), b("3");
            real c = b, d = b;
            c.set_optimize_freq(3);
            for (int i = 0 ; i < 8; ++i) {
                c += a; 
                d += a;
                if (i % 3 == 1) {
                    CHECK(c.find_num_nodes() == 3);   // optimize() is called, c is of form b + k * a
                }
            }
            CHECK(c == d); 


            c = a + b;
            d = a + b;
            c.set_optimize_freq(4);
            for (int i = 0 ; i < 11; ++i) {
                c += (a - a); 
                d += (a - a);
                if (i % 4 == 2) {
                    CHECK(c.find_num_nodes() == 2);   // optimize() is called, c is a + b
                }
            }
            CHECK(c == d);


            real e("5");
            c = (e * e) + (((b + a) + a) + a);
            d = c;
            c.set_optimize_freq(6);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 5);   // c is (e * e) + (b + 3 * a)
            CHECK(d.find_num_nodes() == 6);   // d is (e * e) + (((b + a) + a) + a)
            c += ((a + b) + (b + a)) + (b - b);
            d += ((a + b) + (b + a)) + (b - b);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 6);   // c is (e * e) + (3 * b + 5 * a)
            CHECK(d.find_num_nodes() == 12);   // d is ((e * e) + (((b + a) + a) + a)) + ((a + b) + (b + a)) + (b - b)


            c = (e * e) + (((b + a) + a) + a);
            d = c;
            c.set_optimize_freq(6);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 5);   // c is (e * e) + (b + 3 * a)
            CHECK(d.find_num_nodes() == 6);   // d is (e * e) + (((b + a) + a) + a)
            c *= ((a + b) + (b + a)) + (b - b);
            d *= ((a + b) + (b + a)) + (b - b);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 9);   // c is ((e * e) + (b + 3 * a)) * (2 * a + 2 * b)
            CHECK(d.find_num_nodes() == 12);   // d is ((e * e) + (((b + a) + a) + a)) * (((a + b) + (b + a)) + (b - b))
        }

        SECTION("Top node is -") {
            real a("1"), b("3");
            real c = b, d = b;
            c.set_optimize_freq(3);
            for (int i = 0 ; i < 8; ++i) {
                c -= a; 
                d -= a;
                if (i % 3 == 1) {
                    CHECK(c.find_num_nodes() == 3);   // optimize() is called, c is of form b - k * a
                }
            }
            CHECK(c == d);


            c = a + b;
            d = a + b;
            c.set_optimize_freq(4);
            for (int i = 0 ; i < 11; ++i) {
                c -= (a - a); 
                d -= (a - a);
                if (i % 4 == 2) {
                    CHECK(c.find_num_nodes() == 2);   // optimize() is called, c is a + b
                }
            }
            CHECK(c == d);


            real e("5");
            c = (e * e) - (((b + a) + a) + a);
            d = c;
            c.set_optimize_freq(6);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 5);   // c is ((e * e) - b) - 3 * a
            CHECK(d.find_num_nodes() == 6);   // d is (e * e) - (((b + a) + a) + a)
            c += ((a + b) + (b + a)) + (b - b);
            d += ((a + b) + (b + a)) + (b - b);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 4);   // c is ((e * e) + b) - a
            CHECK(d.find_num_nodes() == 12);   // d is ((e * e) - (((b + a) + a) + a)) + ((a + b) + (b + a)) + (b - b)


            c = (e * e) - (((b + a) + a) + a);
            d = c;
            c.set_optimize_freq(6);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 5);   // c is ((e * e) - b) - 3 * a
            CHECK(d.find_num_nodes() == 6);   // d is (e * e) + (((b + a) + a) + a)
            c *= ((a + b) + (b + a)) + (b - b);
            d *= ((a + b) + (b + a)) + (b - b);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 9);   // c is (((e * e) - b) - 3 * a) * (2 * a + 2 * b)
            CHECK(d.find_num_nodes() == 12);   // d is ((e * e) - (((b + a) + a) + a)) * (((a + b) + (b + a)) + (b - b))
        }

        SECTION("Top node is other than +/-") {
            real a("1"), b("3");
            real c = b, d = b;
            c.set_optimize_freq(8);
            real c1 = b;
            for (int i = 0; i < 3; i++) {
                c += a;
                d += a;
                c1 -= a;
            }
            c *= c1;
            d *= c1;
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 6);   // c is (b + 3 * a) * (b - 3 * a)
            CHECK(d.find_num_nodes() == 8);   // d is (b + a + a + a) * (b - a - a - a)
            c *= (a + a);
            d *= (a + a);
            c += ((a + b) + (b + a)) + (b - b);
            d += ((a + b) + (b + a)) + (b - b);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 12);   // c is (((b + 3 * a) * (b - 3 * a)) * (2 * a)) + (2 * a + 2 * b)
            CHECK(d.find_num_nodes() == 16);   // d is (((b + a + a + a) * (b - a - a - a)) * (2 * a)) + ((a + b) + (b + a)) + (b - b)


            c = b, d = b;
            c.set_optimize_freq(8);
            c1 = b;
            for (int i = 0; i < 3; i++) {
                c += a;
                d += a;
                c1 += a;
            }
            c /= c1;
            d /= c1;
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 6);   // c is (b + 3 * a) / (b + 3 * a)
            CHECK(d.find_num_nodes() == 8);   // d is (b + a + a + a) / (b + a + a + a)
            c *= (a + a);
            d *= (a + a);
            c += ((a + b) + (b + a)) + (b - b);
            d += ((a + b) + (b + a)) + (b - b);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 12);   // c is (((b + 3 * a) / (b + 3 * a)) * (2 * a)) + (2 * a + 2 * b)
            CHECK(d.find_num_nodes() == 16);   // d is (((b + a + a + a) / (b + a + a + a)) * (2 * a)) + ((a + b) + (b + a)) + (b - b)


            c = b, d = b;
            c.set_optimize_freq(8);
            c1 = b;
            for (int i = 0; i < 3; i++) {
                c += a;
                d += a;
                c1 -= a;
            }
            c *= c1;
            d *= c1;
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 6);   // c is (b + 3 * a) * (b - 3 * a)
            CHECK(d.find_num_nodes() == 8);   // d is (b + a + a + a) * (b - a - a - a)
            c += (a - a);
            d += (a - a);
            c += ((a + b) + (b + a)) + (b - b);
            d += ((a + b) + (b + a)) + (b - b);
            CHECK(c == d);
            CHECK(c.find_num_nodes() == 10);   // c is ((b + 3 * a) * (b - 3 * a)) + (2 * a + 2 * b)
            CHECK(d.find_num_nodes() == 16);   // d is (((b + a + a + a) * (b - a - a - a)) + (a - a)) + ((a + b) + (b + a)) + (b - b)
        }
    }
}