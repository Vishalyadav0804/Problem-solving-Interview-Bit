The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.


#Code

string Solution::convert(string s, int numRows) {
    if(numRows == 1) return s;
        vector<string>v(numRows, "");
        int d = 1;
        int row = 0;
        for(auto c: s){
            v[row].push_back(c);
            row += d;
            if(row == numRows - 1) d = -1;
            if(row == 0) d = 1;
        }
        string res;
        for(auto x: v) res.append(x);
        return res;
}
