#include <iostream>
#include <vector>
#include <string>


void LCS() {
	std::string x = " ABCBDAB";
	std::string y = " BDCABA";

	std::vector < std::vector <int> > C(x.size(), std::vector <int>(y.size())), movement(x.size(), std::vector <int>(y.size()));


	

	int m = x.size();
	int n = y.size();

	for (int i = 0; i < m; i++)
		C[i][0] = 0;
	for (int j = 0; j < n; j++)
		C[0][j] = 0;

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (x[i] == y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				movement[i][j] = 2; //Recording the movement to backtrack later on
			}
				
			else {
				if (C[i - 1][j] >= C[i][j - 1]) {
					C[i][j] = C[i - 1][j];
					movement[i][j] = 3; //Recording the movement to backtrack later on
				}
					
				else {
					C[i][j] = C[i][j - 1];
					movement[i][j] = 1; //Recording the movement to backtrack later on
				}
					
			}
		}
	}

	for (int i = 0; i < C.size(); i++) {  //displaying the matrix
		for (int j = 0; j < C[i].size(); j++) {
			std::cout << C[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n\nLCS result : " << C[m - 1][n - 1] << std::endl;  //Displaying the bottom right corner value

	std::vector <char> answer;


	int i = m - 1;
	int j = n - 1;
	bool found = false;

	while (!(i <= 0 && j <=0)) { //Finding out the letters for LCS

		if (found == true)
			break;

		switch (movement[i][j]) {
		case 2:  //2 : left-top corner
			if (x[i] == y[j]) {
				answer.push_back(x[i]);
			}
			i = i - 1;
			j = j - 1;
			break;
		case 3: //3 : up
			if (x[i] == y[j]) {
				answer.push_back(x[i]);
			}
			i = i - 1;
			break;
		case 1: // 1 : left
			if (x[i] == y[j]) {
				answer.push_back(x[i]);
			}
			j = j - 1;
			break;
		default:
			found = true;
			break;
		}
	}

	std::cout << "LCS output : ";

	for (auto it = rbegin(answer); it != rend(answer); it++) {  // Outputting the vector from reverse to get the correct answer
		std::cout << *it;
	}

}



int main()
{
	LCS();
}

