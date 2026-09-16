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
	
		int highJump = 0, lowJump = 0;
		int currentWalls = walls[0];

   // if the length == 1 also, they it can not pass the for loop conditon check. so no need write a special case for it
		for (int i = 1; i < lengths; i++){  
			// each i represents height of next wall
			if (currentWalls < walls[i]){
				highJump++;
			} else if(currentWalls > walls[i]){
				lowJump++;
			}
			currentWalls = walls[i];
		}
		cout << "Case " << testCase + 1<< ": " << highJump << " " << lowJump << "\n";
	}
	
	return 0;
}