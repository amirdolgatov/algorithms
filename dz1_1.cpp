#include <iostream>
#include <vector>

int non_zero_number(std::vector<int>& vec, int number){
	int count = 0;
	for (auto t: vec)
		if(t != number)
			++count;
	return count;
}

void printVector(std::vector<int>& vec){
	for (auto t: vec)
	{
		std::cout << t << " ";
	}
	// std::cout << std::endl;
}

int seek_zero(std::vector<int>& vec, int range){
	for(int i = 0; i < range; ++i)
		if (vec[i] == 0){
			return i;
		}
	return -1;
}


int main(int argc, char const *argv[])
{
	
	int state = 0;
	int index = 0;
	int nextnul = -1;
	int non_zero;
	int zero;
	int count = 1;

	int size = 0;
	std::vector<int> massive;

	std::cin >> size;

	massive.resize(size);

	for(auto& t: massive){
		std::cin >> t;
	}

	if((non_zero = non_zero_number(massive, 0)) == size){
		printVector(massive);
		return 0;
	}


	while((index = seek_zero(massive, non_zero)) >= 0){
		while(index < size - count){
			massive[index] = massive[index + 1];
			massive[index + 1] = 0;
			++index;
		}
		++count;
	}

	printVector(massive);

	

	return 0;
			
}


// enum STATES{
// 	FIRSTSEEK = 1,
// 	ZERO = 2,
// 	MOVE = 3,
// 	END = 4
// };


			
				// int state = 0;

	// int size = 0;
	// std::vector<int> massive;
	// int element = 0;
	// int count = 0;
	// int zero_width = 1;

	// std::cin >> size;

	// massive.resize(size);

	// for(auto& t: massive){
	// 	std::cin >> t;
	// }


	// for(int i = 0; i < massive.size(); ++i){

	// }

	// int index = 0

	// while(false){


	// 	switch(state){
	// 	case FIRSTSEEK: 
	// 		for( ; index < massive.size(); ++index){
	// 			if(massive[index] == 0){
	// 				state = MOVE;
	// 				break;
	// 			}
	// 		}

	// 			if(index = massive.size()){
	// 				state = END
	// 			}
	// 		break;

	// 	case MOVE:
	// 		if(massive[i + 1] != 0){
	// 			.......
	// 		}
	// 		else
	// 			state = ZERO;

	// 		break;

	// 	case ZERO:
	// 		while(massive[index++] == 0 && index < massive.size())
	// 			++zero_width;


	// 	}

	// }

	// for(auto& t: massive){
	// 	std::cout << t;
	// }
			