#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int T;
    cin >> T; // Read number of test cases
	
	for (int testCase = 0; testCase < T ; testCase++){  // set conditon to -1 to prevent over flow
		int lengths;
		cin >> lengths;
		
		vector<int> walls(lengths);
        for (int i = 0; i < lengths; ++i) {
            cin >> walls[i]; // Read each wall height
        }
		
		if(lengths == 1) { return 0 ;};
	
		// Not signle walls
		int highJump = 0;
		int lowJump = 0;
		int currentWalls = walls[0];
		
		
		for (int i = 1; i < lengths -1 ; i++){  // set conditon to -1 to prevent over flow
			// each i represents height of next wall
			if (currentWalls < walls[i+1]){
				highJump++;
			} else if(currentWalls > walls[i+1]){
				lowJump++;
			}
			currentWalls = walls[i];
		}
		cout << "Case " << testCase << ": " << highJump << " " << lowJump << "\n";
	}
	
	return 0;
}
