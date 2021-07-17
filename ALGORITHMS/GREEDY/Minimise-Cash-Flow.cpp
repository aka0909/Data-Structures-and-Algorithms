// C++ program to fin maximum cash flow among a set of persons
#include<iostream>
using namespace std;

// Number of persons (or vertices in the graph)
#define N 3

// A utility function that returns index of minimum value in arr[]
int getMin(int arr[])
{
	int minInd = 0;
	for (int i=1; i<N; i++)
		if (arr[i] < arr[minInd])
			minInd = i;
	return minInd;
}

// A utility function that returns index of maximum value in arr[]
int getMax(int arr[])
{
	int maxInd = 0;
	for (int i=1; i<N; i++)
		if (arr[i] > arr[maxInd])
			maxInd = i;
	return maxInd;
}

// A utility function to return minimum of 2 values
int minOf2(int x, int y)
{
	return (x<y)? x: y;
}

// amount[p] indicates the net amount to be credited/debited
// to/from person 'p'
// If amount[p] is positive, then i'th person will amount[i]
// If amount[p] is negative, then i'th person will give -amount[i]
void minCashFlowRec(int amount[])
{
    int mxCredit=getMax(amount);
    int mxDebit=getMin(amount);

    if(amount[mxCredit]==0 && amount[mxDebit]==0)return;

    int minn = min(amount[mxCredit],-amount[mxDebit]);

    amount[mxCredit]-=minn;
    amount[mxDebit]+=minn;

    cout << "Person " << mxDebit << " pays " << minn
         << " to " << "Person " << mxCredit << endl;

    minCashFlowRec(amount);



}

// Given a set of persons as graph[] where graph[i][j] indicates
// the amount that person i needs to pay person j, this function
// finds and prints the minimum cash flow to settle all debts.
void minCashFlow(int graph[][N])
{
	int amount[N]={0};

	for(int p=0;p<N;p++)
    {
        for(int i=0;i<N;i++)
        {
            amount[p]+=(graph[i][p]-graph[p][i]);
        }
    }
    minCashFlowRec(amount);
}

// Driver program to test above function
int main()
{
	// graph[i][j] indicates the amount that person i needs to
	// pay person j
	int graph[N][N] = { {0, 1000, 2000},
						{0, 0, 5000},
						{0, 0, 0},};

	// Print the solution
	minCashFlow(graph);
	return 0;
}
