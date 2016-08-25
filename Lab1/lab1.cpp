#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void display(const vector<int> fib);
void fibCount(int, const vector<int>& J);
vector<int> fibMod(int, int, int);
void checkPairs(const vector<int>& V, vector< vector<int> >& V2);
void vectorFill(int, vector< vector<int> >& V);
void displayVector(const vector< vector<int> >& V2);
int secondPair(vector< vector<int> >& V2);
int firstPair(vector< vector<int> >& V2);
int remainingPairs(vector< vector<int> >& V2);

int main()
{
    vector<int> V;
    vector<int> V1;
    vector< vector<int> > V2;
    int userAns = 0;
    int firstNumb = 0;
    int secondNumb = 0; 
    int M = 0;
    int N = 0;
    int runTime = 0;
    int checker = 0;
while(userAns != 1)
{
    cout << "Please enter a value for M: ";
    cin >> M;
    cout << "Would you like to use your own values? [1 for no, 0 for yes]" << endl;
    cin >> N;
    if(N == 0)
    {
        cout << "Please enter a first number for the series: ";
        cin >> firstNumb;
        cout << "Please enter a second number for the series: ";
        cin >> secondNumb;
        cout << endl;
    }
    else
    {
        firstNumb = 0;
        secondNumb = 1;
    }
        cout << "Would you like to run the program 1 time or until complete?"
            << " [1 for complete run, 0 for 1 time]" << endl;
        cin >> runTime;
        vectorFill(M, V2);
        cout << "Repeating Series and occurrence of each value:" << endl;
    while(checker != 1)
    {
        V1 = fibMod(M, firstNumb, secondNumb);
        display(V1);
        cout << "               (";
        for(int i = 0; i != M; ++i)
        {
            fibCount(i, V1);
            if(i != (M - 1))
            {
                cout << ",";
            }
        }
        cout << ") " << endl;
        checkPairs(V1, V2);
        checker = 1;
        if(runTime != 0)
        {
            checker = remainingPairs(V2);
            if(checker == 0)
            {
                firstNumb = firstPair(V2);
                secondNumb = secondPair(V2);
                checker = 0;
            }
        }
    }
    userAns = 1;
    if(runTime != 0)
    {
        cout << "Would you like to continue with different values? [1 for no, 0 for yes]" 
            << endl;
        cin >> userAns;
        cout << endl << endl;
        if(userAns == 0)
        {
            V2.clear();
            checker = 0;
        }
    }
}
    return 0;
}
void display(const vector<int> fib)
{
    cout << "(";
    for(unsigned i = 0; i < fib.size(); ++i)
    {
        cout << fib.at(i);
        if(!(i == fib.size() - 1))
        {
            cout << ", ";
        }
    }
    cout << ")";
}
void fibCount(int M, const vector<int>& J)
{
    int A = M;
    int value = 0;
    for(unsigned i = 0; i < J.size(); ++i)
    {
        if(A == J.at(i))
        {
            ++value;
        }
    }
    cout << value;
}
vector<int> fibMod(int M, int first, int second)
{
    vector<int> fib;
    fib.push_back(first);
    fib.push_back(second);
    int A = 0;
    int J = 0;
    if(M < 6)
    {
        J = M * M * M;
    }
    else
    {
        J = M * M;
    }
    for(int i = 2; i < J; ++i)
    {
        A = (fib.at(i - 1) + fib.at(i - 2)) % M;
        fib.push_back(A);
    }
    vector<int> fib2;
    int counter = 0;
    
    fib2.push_back(fib.at(0));
    fib2.push_back(fib.at(1));
    for(unsigned i = 2; i < fib.size(); ++i)
    {
        if(counter == 0)
        {
            fib2.push_back(fib.at(i));
            if(fib.at(i) == fib.at(0))
            {
                if(fib.at(i + 1) == fib.at(1))
                {
                    fib2.pop_back();
                    counter = 1;
                }
            }
        }
    }
    return fib2;
}
void checkPairs(const vector<int>& V, vector< vector<int> >& V2)
{
    int S = V.at(0);
    int A = V.at(V.size() - 1);
    V2.at(A).at(S) = 1;
    for(unsigned i = 0; i < V.size() - 1; ++i)
    {
        int Q = V.at(i);
        int R = V.at(i + 1);
        V2.at(Q).at(R) = 1;
    }
}
void vectorFill(int M, vector< vector<int> >& V)
{
    for(int j = 0; j < M; ++j)
    {
        V.push_back(vector<int> ());
        for(int i = 0; i < M; ++ i)
        {
            V.at(j).push_back(0);
        }
    }
}
void displayVector(const vector< vector<int> >& V2)
{
    for(unsigned i = 0; i < V2.size(); ++i)
    {
        cout << "|";
        for(unsigned j = 0; j < V2.at(i).size(); ++j)
        {
            if(V2.at(i).at(j) == 1)
            {
                cout << "(_,_)";
            }
            else
            {
                cout << "(" << i << "," << j << ")" << " ";
            }
        }
        cout << "|" << endl;
    }
}
int remainingPairs(vector< vector<int> >& V2)
{
    for(unsigned i = 0; i < V2.size(); ++i)
    {
        for(unsigned j = 0; j < V2.at(i).size(); ++j)
        {
            if(V2.at(i).at(j) == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int firstPair(vector< vector<int> >& V2)
{
    for(unsigned i = 0; i < V2.size(); ++i)
    {
        for(unsigned j = 0; j < V2.at(i).size(); ++j)
        {
            if(V2.at(i).at(j) == 0)
            {
                return i;
            }
        }
    }
    return 0;
}
int secondPair(vector< vector<int> >& V2)
{
    for(unsigned i = 0; i < V2.size(); ++i)
    {
        for(unsigned j = 0; j < V2.at(i).size(); ++j)
        {
            if(V2.at(i).at(j) == 0)
            {
                return j;
            }
        }
    }
    return 0;
}