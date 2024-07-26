
#include <vector>

class Matrix {
    using type = std::vector<std::vector<int>>;
public:
    static type Multi(const type& a, const type& b)
    {
        int m = a.size();
        int n = b[0].size();
        int k = a[0].size();
        type res(m, std::vector<int>(n));
        if (a[0].size() != b.size()) {
            return res;
        }

        type t = transpose_matrix(b);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = 0;
                for (int k = 0; k < m ; ++k) {
                    res[i][j] += a[i][k] * t[k][j];
                }
            }
        }
        return res;
    }


    static type transpose_matrix(const type b)
    {
        int row = b.size();
        int column = b[0].size();
        type res(row, std::vector<int>(column));
        for(int i=0;  i < row; ++i)
        {
            for(int j=0; j < column; ++j)
                res[i][j] = b[j][i];
        }

        return res;
    }


    static bool judgeZero(const type& a, const type& b)
    {
        bool fndsign = false;
        int row = a.size();
        int column = a[0].size();
        for(int i=0; i < row; ++i)
        {
            for(int j=0; j < column; ++j)
            {
                if(a[i][j] * b[i][j]){
                    fndsign = true;
                    break;
                }
                    
            }
            if(fndsign)
                break;
        }

        return fndsign;
    }
};