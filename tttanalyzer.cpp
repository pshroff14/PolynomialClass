// Copyright 2020 Poras Shroff pshroff4@bu.edu

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "movedef.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;

// 3.1 String-Representation 'tttresult'
char tttresult(string tttboard) {
  // initalize count for x vs o on the board
  int xnum = 0;
  int onum = 0;
  // initialize winner bool function
  bool xwin = false;
  bool owin = false;

  for (char i : tttboard) {
    if (i == 'x') xnum++;
    if (i == 'o') onum++;
  }
  // check for unbalanced numbers
  int beta = xnum-onum;
  if (beta > 1) return 'i';
  if (beta < 0) return 'i';

  // recognize errors of board
  // if char is larger than 9 report 'e'
  if (tttboard.size() != 9) return 'e';
  // if char is not 'x''o' or '#' report 'e'
  for (char i : tttboard) {
    if (i != 'o' && i != 'x' && i != '#') return 'e';
  }

  // check diagonals for wins
  if ((tttboard.at(0) == tttboard.at(4) && tttboard.at(4) == tttboard.at(8))) {
    if (tttboard.at(4) == 'x') xwin = true;
    if (tttboard.at(4) == 'o') owin = true;
  }
  if ((tttboard.at(2) == tttboard.at(4) && tttboard.at(4) == tttboard.at(6))) {
    if (tttboard.at(4) == 'x') xwin = true;
    if (tttboard.at(4) == 'o') owin = true;
  }

  // loop by each column
  for (int i = 0; i < 3; i++) {
    // checking columns for wins
    if (tttboard.at(i) == tttboard.at(i + 3) &&
      tttboard.at(i + 3) == tttboard.at(i + 6)) {
      if (tttboard.at(i) == 'x') xwin = true;
      if (tttboard.at(i) == 'o') owin = true;
    }
    // checking rows for wins
    int alpha = 3 * i;
    if (tttboard.at(alpha) == tttboard.at(alpha + 1) &&
     tttboard.at(alpha) == tttboard.at(alpha + 2)) {
      if (tttboard.at(alpha) == 'x') xwin = true;
      if (tttboard.at(alpha) == 'o') owin = true;
    }
  }


  // if both win return invalid
  if (xwin && owin) return 'i';

  if (!xwin && !owin) {
    // if neither x or o win but still empty spaces game still continues
    if (xnum + onum < 9) return 'c';
    // if neither x or o win by no empty spaces game is a tie
    if (xnum + onum == 9) return 't';
  }
  // if x wins 
  if (xwin) {
    if (beta == 1) return 'x';
  }
  // if o wins 
  if (owin) {
    if (beta == 0) return 'o';
  }

  return 'i';
}

char tttresult(vector<Move> tttboard) {
  string result = "#########";
  for (auto & i : tttboard) {
    // moves from movedef.h file 
    if (i.r == 0) result.at(i.c) = i.player;
    if (i.r == 1) result.at(i.c + 3) = i.player;
    if (i.r == 2) result.at(i.c + 6) = i.player;
  }
  return tttresult(result);
}
// 3.3 Function Get all Boards 
vector<string> get_all_boards() {
  vector<string> boardog;
  string tttboard = "#########";
  boardog.push_back(tttboard);

  while (tttboard != "xxxxxxxxx") {
    int i = 8;
    while (tttboard.at(i) == 'x') {
      i = i - 1;
    }
    if (tttboard.at(i) == '#') {
      tttboard.at(i) = 'o';
    } else if (tttboard.at(i) == 'o') {
      tttboard.at(i) = 'x';
    }
    for (i = i + 1; i < 9; i++) {
      tttboard.at(i) = '#';
    }
    boardog.push_back(tttboard);
  }
  return boardog;
}

// 3.4 Fucntion ttt tally  3^9=19683
// auto link https://stackoverflow.com/questions/7576953/c-auto-keyword-why-is-it-magic
void ttt_tally() {
  map<char, int> tally;
  for ( auto c : string("toxic")) {
    tally.insert({c, 0});
  }
  for (auto & board : get_all_boards()) {
    tally.at(tttresult(board))++;
  }
  for (auto const& pair : tally) {
    std::cout << pair.first << " " << pair.second << "\n";
  }
}

// MAIN
int main() {
  int n;
  std::string board;
  Move m;
  std::vector<Move> moves;
  std::vector<std::string> boards;
  std::string asktype;

  while (std::cin >> asktype) {
    if (asktype == "v") {  // test tttresult vector
      moves.clear();
      std::cin >> n;
      for (int i = 0; i < n; i++) {
        std::cin >> m.r >> m.c >> m.player;
        moves.push_back(m);
      }
      std::cout << tttresult(moves) << "\n";
    } else if (asktype == "s") {  // test tttresult string
      std::cin >> board;
      std::cout << tttresult(board) << "\n";
    } else if (asktype == "a") {  // test get_all_boards
      boards = get_all_boards();
      for (auto b : boards) {
        std::cout << b << "\n";
      }
    } else if (asktype == "t") {  // test ttt_tally
      ttt_tally();
    } else {
      return 0;
    }
  }
  return 0;
}

// // Testing movedef
// int main() {
//   vector<Move> moves;
//   bool error;
//   char result;

//   Move m; // make a move 
//   m.r = 0; // fill the data
//   m.c = 1;
//   m.player = 'x';

//   moves.push_back(m); // put the move on the vector representing the board.

//   result = tttresult(moves);  // returns 'c'
//   result = tttresult("###xxxoo#"); // returns 'x'
//   result = tttresult("xxxoooHI!"); // returns 'e'
// }

////RESOURCES
///For tttResult
//https://www.youtube.com/watch?v=JNFCdHU3SP0&t=607s
///For get boards
//https://stackoverflow.com/questions/48858578/tic-tac-toe-generating-combinations-of-boards-c