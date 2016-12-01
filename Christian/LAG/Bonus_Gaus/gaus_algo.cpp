#include <iostream>
#include <array>
#include <algorithm>

#include <cstdlib>
#include <cmath>

template<unsigned int n, unsigned int m>
class gaus_matrix {
    public :

        using index_type = unsigned int;

        const index_type rows = n;
        const index_type cols = m;
        const index_type n_pos = n > m ? n : m;

        static constexpr float epsilon = std::numeric_limits<double>::epsilon();

        gaus_matrix() :data{} { }

        std::array<double, m> &operator[](index_type index) {
            return data[index];
        }

        const std::array<double, m> &operator[](index_type index) const {
            return data[index];
        }

        index_type find_pivot(index_type index) const {
            return gaus_matrix::find_pivot(data[index], n_pos);
        }

        static index_type find_pivot(const std::array<double, m> &row, index_type n_pos) {
            for (index_type i = 0; i < m; i++)
                if (std::abs(row[i]) > epsilon) 
                    return i;

            return n_pos;
        }

        void scale_and_add(index_type src, index_type dst, float scale) {
            if (dst == src) return;

            auto src_it = data[src].begin(); 
            auto dst_it = data[dst].begin(); 

            while (src_it != data[src].end()) {
                *dst_it += (*src_it) * scale;
                ++src_it;
                ++dst_it;
            }
        }

        // TODO implement error handling
        void solve(index_type start) {
            if (start == std::min(rows, cols)) return;

            index_type not_found = n_pos;
            // sort the rows so that the row with the first leading 
            // pivot element is the top row
            std::sort(data.begin(), data.end(), 
                    [not_found](const std::array<double, m> &row_one, 
                        const std::array<double, m> &row_two){

                        return find_pivot(row_one, not_found) < find_pivot(row_two, not_found);
                    });

            // get pivot for first row 
            index_type pivot = find_pivot(start);

            for (index_type i = start + 1; i < rows; i++) {
                index_type curr_pivot = find_pivot(i); 

                if (curr_pivot == pivot) {
                    // pivot * x = -curr_pivot; | / pivot
                    // x = - curr_pivot / pivot;
                    scale_and_add(start, i, -(data[i][curr_pivot] / data[start][pivot]));
                }
            }

            std::cout << (*this) << std::endl;

            solve(start + 1);
        }

    private : 
        std::array<std::array<double, m>, n> data;

};

template<unsigned int n, unsigned int m> 
std::ostream &operator<<(std::ostream &os, const gaus_matrix<n, m> &mat) {
    for (unsigned int i = 0; i < n; i++) {
        auto arr = mat[i];
        
        for (auto val : arr)
            os << val << "\t";

        os << std::endl;
    }
    return os;
}

int main() {
    gaus_matrix<3, 4> mat;

    mat[0][0] = 2;
    mat[0][1] = 1; 
    mat[0][2] = -1;
    mat[0][3] = 8;

    mat[1][0] = -3;
    mat[1][1] = -1; 
    mat[1][2] = 2;
    mat[1][3] = -11;

    mat[2][0] = -2;
    mat[2][1] = 1; 
    mat[2][2] = 2;
    mat[2][3] = -3;
  
    mat.solve(0);

    return EXIT_SUCCESS;
}
