#ifndef BOOST_REAL_RANGE_HELPER_HPP
#define BOOST_REAL_RANGE_HELPER_HPP

namespace boost {
    namespace real {
        namespace helper {

            bool vector_is_lower(const std::vector<int> &lhs, const std::vector<int> &rhs) {

                // Check if lhs is lower than rhs
                auto lhs_it = lhs.cbegin();
                auto rhs_it = rhs.cbegin();
                while (rhs_it != rhs.end() && lhs_it != lhs.end() && *lhs_it == *rhs_it) {
                    ++lhs_it;
                    ++rhs_it;
                }

                //TODO: if it reaches the end of only one number, then that number continues as zeros and comparizon must be done considering that.
                return rhs_it != rhs.end() && lhs_it != lhs.end() && *lhs_it < *rhs_it;
            }

            /*
             * Align two numbers so the digits positions corresponds
             */
            void align_numbers(std::vector<int>& lhs, int& lhs_integers, std::vector<int>& rhs, int& rhs_integers) {
                while (lhs_integers < rhs_integers) {
                    lhs.insert(lhs.begin(), 0);
                    lhs_integers++;
                }

                while (rhs_integers < lhs_integers) {
                    lhs.insert(lhs.begin(), 0);
                    rhs_integers++;
                }

                while (lhs.size() < rhs.size()) {
                    lhs.push_back(0);
                }

                while (rhs.size() < lhs.size()) {
                    rhs.push_back(0);
                }
            }
        }
    }
}

#endif //BOOST_REAL_RANGE_HELPER_HPP
