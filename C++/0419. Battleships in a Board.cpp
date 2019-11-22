/* Given an 2D board, count how many battleships are in it. The battleships are
 * represented with 'X's, empty slots are represented with '.'s. You may assume
 * the following rules:
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. In other words,
 * they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1
 * column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships -
 * there are no adjacent battleships.
 * Example:
 * X..X
 * ...X
 * ...X
 * In the above board there are 2 battleships.
 * Invalid Example:
 * ...X
 * XXXX
 * ...X
 * This is an invalid board that you will not receive - as battleships will always
 * have a cell separating between them.
 * Follow up:
 * Could you do it in one-pass, using only O(1) extra memory and without modifying
 * the value of the board?
 * https://leetcode.com/problems/battleships-in-a-board/description/
 *
 * Author: Adam Yu Wen
 * Date: June 20, 2018
 */

// It takes 7 ms, which beats 98.81% of cpp submission.
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        int numRow = board.size();
        int numCol = board[0].size();
        for (int row = 0; row < numRow; row++) {
            for (int col = 0; col < numCol; col++) {
                if (board[row][col] == 'X') {
                    cnt++;
                    int battleshipRow = row;
                    int battleshipCol = col;
                    board[battleshipRow][battleshipCol] = '.';
                    while (battleshipRow > 0 && board[battleshipRow - 1][battleshipCol] == 'X') {
                        board[battleshipRow - 1][battleshipCol] = '.';
                        battleshipRow -= 1;
                    }
                    while (battleshipRow < numRow - 1 && board[battleshipRow + 1][battleshipCol] == 'X') {
                        board[battleshipRow + 1][battleshipCol] = '.';
                        battleshipRow += 1;
                    }
                    while (battleshipCol > 0 && board[battleshipRow][battleshipCol - 1] == 'X') {
                        board[battleshipRow][battleshipCol - 1] = '.';
                        battleshipCol -= 1;
                    }
                    while (battleshipCol < numCol - 1 && board[battleshipRow][battleshipCol + 1] == 'X') {
                        board[battleshipRow][battleshipCol + 1] = '.';
                        battleshipCol += 1;
                    }
                }
            }
        }
        return cnt;
    }
};
