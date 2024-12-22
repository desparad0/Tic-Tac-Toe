/**
 *    author:  Devesh Singh (IT-1)
 *
 **/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define form(i, a, b) for (int i = a; i < (b); i++)
#define forn(i, a) for (int i = 0; i < (a); i++)
#define rofm(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define rof(i, a) rofm(i, 0, a)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
#define so(x) sort(all(x))
#define rso(x) sort(rall(x))
#define sz(x) int((x).size())

#define big 10e5 + 1
#define mod 1000000007

bool game_over = false;

void print_blank()
{
    cout << "# "; // later to be changed with graphics ;)
}

void print_bigO()
{
    cout << "O "; // later to be changed with graphics ;)
}

void print_bigX()
{
    cout << "X "; // later to be changed with graphics ;)
}

void logic()
{
    int row, col, chance = 0;
    vector<vi> v(3);
    forn(i, 3)
    {
        forn(j, 3)
        {
            v[i].pb(8);
        }
    }
    forn(i, 3)
    {
        forn(j, 3)
        {
            print_blank();
        }
        cout << "\n";
    }
    while (!game_over)
    {
        cout << "Enter the row and column you want to write in : ";
        cin >> row >> col;
        system("CLS");
        if (chance % 2)
        {
            v[row - 1][col - 1] = 1;
            chance++;
        }
        else
        {
            v[row - 1][col - 1] = 0;
            chance++;
        }
        if ((v[0][0] == 0 && v[0][1] == 0 && v[0][2] == 0) || (v[1][0] == 0 && v[1][1] == 0 && v[1][2] == 0) || (v[2][0] == 0 && v[2][1] == 0 && v[2][2] == 0) ||
            (v[0][0] == 0 && v[1][0] == 0 && v[2][0] == 0) || (v[0][1] == 0 && v[1][1] == 0 && v[2][1] == 0) || (v[0][2] == 0 && v[1][2] == 0 && v[2][2] == 0) ||
            (v[0][0] == 0 && v[1][1] == 0 && v[2][2] == 0) || (v[0][2] == 0 && v[1][1] == 0 && v[2][0] == 0))
        {
            cout << "player 1 With sign 'O' WON :)\n";
            game_over = true;
        }
        else if ((v[0][0] == 1 && v[0][1] == 1 && v[0][2] == 1) || (v[1][0] == 1 && v[1][1] == 1 && v[1][2] == 1) || (v[2][0] == 1 && v[2][1] == 1 && v[2][2] == 1) ||
                 (v[0][0] == 1 && v[1][0] == 1 && v[2][0] == 1) || (v[0][1] == 1 && v[1][1] == 1 && v[2][1] == 1) || (v[0][2] == 1 && v[1][2] == 1 && v[2][2] == 1) ||
                 (v[0][0] == 1 && v[1][1] == 1 && v[2][2] == 1) || (v[0][2] == 1 && v[1][1] == 1 && v[2][0] == 1))
        {
            cout << "player 2 With sign 'X' WON :)\n";
            game_over = true;
        }
        forn(i, 3)
        {
            forn(j, 3)
            {
                if (v[i][j] == 8)
                    print_blank();
                if (v[i][j] == 0)
                    print_bigO();
                if (v[i][j] == 1)
                    print_bigX();
            }
            cout << "\n";
        }
    }
}

void play_again()
{
    game_over = false;
    int again;
    cout << "DO YOU WISH TO PLAY AGAIN ?\nPRESS 3 to EXIT and 1 to PLAY again :) ";
    cin >> again;
    system("CLS");
    if (again == 1)
        logic();
    else
        game_over = true;
}

void play()
{
    logic();
    play_again();
}

void credits()
{
    cout << "CREDITS :\nONLY MADE POSSIBLE BY DEVESH :)\n";
}

int main()
{
    cout << "----------Tic-Tac-Toe----------\n1) PLAY\n2)Credits\n3)EXIT\nEnter your choice : ";
    int choice;
    cin >> choice;
    system("CLS");
    if (choice == 1)
        while (!game_over)
            play();
    else if (choice == 2)
    {
        credits();
        cout << "Enter another choice : ";
        choice = 0;
        while (choice != 1 && choice != 3)
        {
            cin >> choice;
            system("CLS");
            if (choice != 1 && choice != 3)
                cout << "AGAIN WRONG CHOICE !! (ENTER AGAIN) : ";
        }
        if (choice == 1)
            while (!game_over)
                play();
        else
            return 0;
    }
    else if (choice == 3)
        return 0;
    else
    {
        cout << "INVALID INPUT!\nREAD AGAIN and TRY AGAIN!";
        while (choice != 1 && choice != 2 && choice != 3)
            cin >> choice;
        system("CLS");
        if (choice == 1)
            while (!game_over)
                play();
        else if (choice == 2)
        {
            credits();
            system("CLS");
        }
        else
            return 0;
    }
    return 0;
}
