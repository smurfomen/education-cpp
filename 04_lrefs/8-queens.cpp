#include <iostream>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

/*
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
    Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

    Example 1:
        Input: n = 4
        Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
        Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

    Example 2:
        Input: n = 1
        Output: [["Q"]]


    Constraints:
        1 <= n <= 9
*/

struct Cell {
    int row, col;
};

struct Queen {
private:
    Cell cell;

public:
    Queen(int row, int column)
        : cell{ row, column }
    { }

    Cell coordinates() const {
        return cell;
    }

    bool isAttack(const Queen& o) const {
        return cell.row == o.cell.row || cell.col == o.cell.col || abs(cell.row - o.cell.row) == abs(cell.col - o.cell.col);
    }
};

int boardSize = 8;

using Board = list<Queen>;

list<Board> generateBoardVariants(Board board = Board{})
{
    if (board.size() == boardSize)
        return list<Board> { {board}};

    // current row
    int row = board.size();

    // 0..4 candidate queen for row, which not attacked exists queens
    list<Board> results;

    // generate available list of queens
    for (int column = 0; column < boardSize; ++column) {
        Queen possibleQueen(row, column);

        auto it = std::find_if(board.begin(), board.end(), [possibleQueen](const Queen& q) { return q.isAttack(possibleQueen); });

        // if not attacked - accept candidate queen
        if (it == board.end()) {
            // add branch with finded candidate
            Board boardWithCandidate = board;
            boardWithCandidate.push_back(possibleQueen);

            // go forward recurse for exist queens with finded not attacked candidate
            list<Board> r = generateBoardVariants(boardWithCandidate);

            results.splice(results.cend(), r);
        }
    }

    return results;
}


int main(int argc, char* argv[]) {
    auto print = [](list<Board>& boards) {
        int i = 0;
        for (Board board : boards)
        {
            cout << "Result #" << ++i << endl;
            cout << "+";
            for (int i = 0; i < boardSize; ++i)
                cout << "_";
            cout << "+" << endl;
            for (auto queen : board)
            {
                stringstream ss;
                cout << "|";
                for (int i = 0; i < boardSize; ++i)
                {
                    if (i == queen.coordinates().col)
                        ss << "Q";
                    else
                    {
                        if (queen.coordinates().row % 2)
                            ss << (i % 2 ? "_" : "#");
                        else
                            ss << (i % 2 ? "#" : "_");
                    }
                }
                cout << ss.str() << "|" << endl;
            }
            cout << "+";
            for (int i = 0; i < boardSize; ++i)
                cout << "_";
            cout << "+" << endl;

            cout << "\n" << endl;
        }
    };


    list<Board> results = generateBoardVariants();
    print(results);

    return 0;
}
