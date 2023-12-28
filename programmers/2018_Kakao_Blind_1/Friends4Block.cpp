#include <bits/stdc++.h>

using namespace std;

int isStop;
bool checker[35][35];

void find4same(int m, int n, vector<string> board) {
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            char c = board[i][j];
            if(c == '0') continue;
            if(c == board[i-1][j] && c == board[i][j-1] && c == board[i-1][j-1]) {
                isStop++;
                checker[i][j] = true; checker[i-1][j] = true;
                checker[i][j-1] = true; checker[i-1][j-1] = true;
            }
        }
    }
}

void downChar(int m, int n, vector<string>& board) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(checker[i][j] == true) {
                for(int k=i; k>0; k--)
                    board[k][j] = board[k-1][j];
                board[0][j] = '0';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(1) {
        isStop = 0;
        memset(checker, false, sizeof(checker));
        find4same(m,n,board);
        if(!isStop) break;
        downChar(m,n,board);
    }
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(board[i][j] == '0') answer++;
    return answer;
}