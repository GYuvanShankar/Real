#ifndef BOOST_REAL_OPTIMIZATION_DATA_HPP
#define BOOST_REAL_OPTIMIZATION_DATA_HPP

#include <utility>
#include <memory>

#include <real/real_data.hpp>

namespace boost {
    namespace real {

        template <typename T>
        struct optimization_data {
            // Frequency of optimizing the tree
            // -1 denotes no optimization
            int optimize_freq = -1;

            // number of variables in the real tree
            int num_vars = 0;
            // number of variables at the time of last optimization
            int num_vars_at_last_optimize = 0;

            // indicates whether we use the information of previous optimization
            bool use_prev = false;
            // info of the top node at last optimization, used when use_prev is true
            std::pair<std::shared_ptr<real_data<T>>, std::map<std::shared_ptr<real_data<T>>, int>> prev_top;
        };
    }
}

#endif // BOOST_REAL_OPTIMIZATION_DATA_HPP