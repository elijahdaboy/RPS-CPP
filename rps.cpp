#include <iostream>
#include <ctime>
#include <cstdlib>

int winRoundCheck(int currUserInput);

int main() {
	int currUserInput;
	int cpuScore = 0;
    int userScore = 0;
    int didWinRound;
	
	srand(time(NULL));

	for(int i = 0; i < 3; i++) {
        if (cpuScore == 2 || userScore == 2){
            break;
        }
        
        std::cout << "1. Rock\n2. Paper\n3. Scissors\n(Type 1, 2, or 3): ";
        std::cin >> currUserInput;
        
        didWinRound = winRoundCheck(currUserInput);
        
        switch (didWinRound){
            case 0:
                i--;
                break;
            case 1:
                userScore++;
                break;
            case 2:
                cpuScore++;
                break;
            case 3:
                i--;
                break;
        }
        
        std::cout << '\n' << userScore << " - " << cpuScore << "\n\n";
        
        std::cout << "Press enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
	}
	
	std::cout << "Score:\nUser: " << userScore << "\nCPU: " << cpuScore;
	
	return 0;
}

int winRoundCheck(int currUserInput){
    int currCpuInput;
    
    currCpuInput = (rand() % 3) + 1;
    
    switch (currUserInput){
        case 1:
            if (currCpuInput == 1){
                std::cout << "\nCpu picked rock!";
                return 0;
            } else if (currCpuInput == 2){
                std::cout << "\nCpu picked paper!";
                return 2;
            } else{
                std::cout << "\nCpu picked scissors!";
                return 1;
            }
        case 2:
            if (currCpuInput == 1){
                std::cout << "\nCpu picked rock!";
                return 1;
            } else if (currCpuInput == 2){
                std::cout << "\nCpu picked paper!";
                return 0;
            } else{
                std::cout << "\nCpu picked scissors!";
                return 2;
            }
        case 3:
            if (currCpuInput == 1){
                std::cout << "\nCpu picked rock!";
                return 2;
            } else if (currCpuInput == 2){
                std::cout << "\nCpu picked paper!";
                return 1;
            } else{
                std::cout << "\nCpu picked scissors!";
                return 0;
            }
        default:
            std::cout << "\nInvalid option, please enter 1-3 for rock, paper, scissors";
            return 3;
    }
    
    return 4;
}
