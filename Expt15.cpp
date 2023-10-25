#include <iostream>
#include <vector>

using namespace std;

class SparseMatrix {
public:
    int rows, cols;
    vector<int> values;
    vector<int> column_indices;
    vector<int> row_pointers;

    SparseMatrix(int m, int n) : rows(m), cols(n) {
        row_pointers.push_back(0);
    }

    void insert(int row, int col, int value) {
        values.push_back(value);
        column_indices.push_back(col);
        if (row > row_pointers.size() - 1) {
            while (row > row_pointers.size() - 1) {
                row_pointers.push_back(values.size());
            }
        }
    }

    // Addition of two sparse matrices
    SparseMatrix add(SparseMatrix other) {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Matrix dimensions don't match for addition." << endl;
            return *this;
        }

        SparseMatrix result(rows, cols);

        int i = 0, j = 0;
        while (i < row_pointers.size() - 1 && j < other.row_pointers.size() - 1) {
            int row_start = row_pointers[i];
            int row_end = row_pointers[i + 1];
            int other_row_start = other.row_pointers[j];
            int other_row_end = other.row_pointers[j + 1];

            while (row_start < row_end || other_row_start < other_row_end) {
                if (row_start < row_end && (other_row_start >= other_row_end || column_indices[row_start] < other.column_indices[other_row_start])) {
                    result.insert(i, column_indices[row_start], values[row_start]);
                    row_start++;
                } else if (other_row_start < other_row_end) {
                    result.insert(i, other.column_indices[other_row_start], other.values[other_row_start]);
                    other_row_start++;
                }
            }

            i++;
            j++;
        }

        while (i < row_pointers.size() - 1) {
            int row_start = row_pointers[i];
            int row_end = row_pointers[i + 1];
            while (row_start < row_end) {
                result.insert(i, column_indices[row_start], values[row_start]);
                row_start++;
            }
            i++;
        }

        while (j < other.row_pointers.size() - 1) {
            int other_row_start = other.row_pointers[j];
            int other_row_end = other.row_pointers[j + 1];
            while (other_row_start < other_row_end) {
                result.insert(j, other.column_indices[other_row_start], other.values[other_row_start]);
                other_row_start++;
            }
            j++;
        }

        return result;
    }

    // Transpose the sparse matrix
    SparseMatrix transpose() {
        SparseMatrix result(cols, rows);

        for (int i = 0; i < rows; i++) {
            for (int j = row_pointers[i]; j < row_pointers[i + 1]; j++) {
                int col = column_indices[j];
                int value = values[j];
                result.insert(col, i, value);
            }
        }

        return result;
    }

    // Multiplication of two sparse matrices
    SparseMatrix multiply(SparseMatrix other) {
        if (cols != other.rows) {
            cerr << "Matrix dimensions don't match for multiplication." << endl;
            return *this;
        }

        SparseMatrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int dot_product = 0;
                int row_start = row_pointers[i];
                int row_end = row_pointers[i + 1];

                for (int k = 0; k < other.rows; k++) {
                    int other_row_start = other.row_pointers[k];
                    int other_row_end = other.row_pointers[k + 1];
                    while (row_start < row_end && other_row_start < other_row_end) {
                        int col1 = column_indices[row_start];
                        int col2 = other.column_indices[other_row_start];
                        if (col1 == col2) {
                            dot_product += values[row_start] * other.values[other_row_start];
                            row_start++;
                            other_row_start++;
                        } else if (col1 < col2) {
                            row_start++;
                        } else {
                            other_row_start++;
                        }
                    }
                }

                if (dot_product != 0) {
                    result.insert(i, j, dot_product);
                }
            }
        }

        return result;
    }

    // Print the sparse matrix
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int value = 0;
                for (int k = row_pointers[i]; k < row_pointers[i + 1]; k++) {
                    if (column_indices[k] == j) {
                        value = values[k];
                        break;
                    }
                }
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    SparseMatrix matrix1(3, 4);
    matrix1.insert(0, 1, 2);
    matrix1.insert(0, 3, 3);
    matrix1.insert(1, 2, 1);
    matrix1.insert(2, 0, 4);

    SparseMatrix matrix2(4, 3);
    matrix2.insert(0, 1, 2);
    matrix2.insert(1, 0, 3);
    matrix2.insert(2, 1, 1);
    matrix2.insert(3, 2, 4);

    cout << "Matrix 1:" << endl;
    matrix1.print();

    cout << "Matrix 2:" << endl;
    matrix2.print();

    SparseMatrix addition = matrix1.add(matrix2);
    cout << "Matrix Addition:" << endl;
    addition.print();

    SparseMatrix transposeMatrix = matrix1.transpose();
    cout << "Matrix 1 Transposed:" << endl;
    transposeMatrix.print();

    SparseMatrix multiplication = matrix1.multiply(matrix2);
    cout << "Matrix Multiplication:" << endl;
    multiplication.print();

    return 0;
}
