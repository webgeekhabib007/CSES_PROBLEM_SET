// C++ code
#include <bits/stdc++.h>
using namespace std;

vector<int>
collectingnumbersII(int n, int m, vector<int>& values,
                    vector<vector<int> >& swaps)
{
    // Make the array 1-indexed
    values.insert(values.begin(), 0);
    vector<int> res;
    vector<int> position(n + 1);

    // Store the positions of the values
    for (int i = 1; i <= n; i++)
        position[values[i]] = i;

    // Calculate the initial number of rounds
    int count = 1;
    for (int i = 1; i < n; i++)
        // Increase the count if there is an inversion i.e.
        // if the position of i is greater than the position
        // of i+1
        count += (position[i] > position[i + 1]);

    // Declare a set to store the pairs of values that will
    // be updated
    set<pair<int, int> > updatedPairs;

    for (int i = 0; i < m; i++) {
        // Declare two integers l and r to store the
        // positions to be swapped
        int l = swaps[i][0], r = swaps[i][1];

        // Insert the pairs of values that will be updated
        // into the set
        if (values[l] + 1 <= n)
            updatedPairs.insert(
                { values[l], values[l] + 1 });
        if (values[l] - 1 >= 1)
            updatedPairs.insert(
                { values[l] - 1, values[l] });
        if (values[r] + 1 <= n)
            updatedPairs.insert(
                { values[r], values[r] + 1 });
        if (values[r] - 1 >= 1)
            updatedPairs.insert(
                { values[r] - 1, values[r] });

        // Update the count before the swap
        for (auto swapped : updatedPairs)
            // Subtract from the count, the inversions
            // formed by our current set as there may be
            // some elements that don’t form an inversion
            // after the swap and if they form they'll be
            // counted.
            count -= position[swapped.first]
                     > position[swapped.second];

        // Perform the swap
        swap(values[l], values[r]);

        // Update the position of the value at position l
        position[values[l]] = l;
        // Update the position of the value at position r
        position[values[r]] = r;

        // Update the count after the swap
        for (auto swapped : updatedPairs)
            // Count and add the inversions by adjacent
            // elements to our existing count.
            count += position[swapped.first]
                     > position[swapped.second];

        // Add the count to the result vector.
        res.push_back(count);

        // Clear the set for the next operation
        updatedPairs.clear();
    }
    // Return result
    return res;
}

// Driver Code
int main()
{
    int n , m ;cin>>n>>m;
    vector<int> values(n);
    for(auto &x: values)cin>>x;
    vector<vector<int> > swaps(m);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        swaps[i].push_back(a);
        swaps[i].push_back(b);
    }
    vector<int> res
        = collectingnumbersII(n, m, values, swaps);

    for (auto i : res)
        cout << i << "\n";

    return 0;
}
