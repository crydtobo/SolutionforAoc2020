/*
 * task2.cpp
 *
 *  Created on: Dec 8, 2020
 *      Author: dawid
 */
#include "../include/tasks.h"
#include "../include/boarding_Pass.h"
#include "../include/declaration.h"
#include "../include/bags.h"
#include "../include/instruction.h"
#include "../include/asn1.h"

#include <map>
#include <cmath>
#include <string>


int task2(std::fstream &File2){
	int count = 0, n1 = 0, n2 = 0, line = 0, correct = 0, incorrect = 0;
	char letter, semicolon, dash;
	std::string pass;
	std::vector<std::string> passwords;

	while(File2 >> n1 >> dash >> n2 >> letter >> semicolon >> pass ){
		count = 0;
		line++;
		passwords.push_back(pass);
		for(size_t i = 0; i < pass.size(); i++){
			if(pass[i] == letter){
				count++;
			}
		}
		if (count >= n1 and count <= n2){
			correct++;
		}
		else{
			incorrect++;
		}
	}
	std::cout<<"Poprawne hasla: "<< correct <<std::endl;
	std::cout<<"NIEPoprawne hasla: "<< incorrect <<std::endl;
	std::cout<<std::endl;
	return correct;
}

int task2_prim(std::fstream &File2){
	int n1 = 0, n2 = 0, line = 0, correct = 0, incorrect = 0;
	int flaga =0;
	char letter, semicolon, dash;
	std::string pass;

	while(File2 >> n1 >> dash >> n2 >> letter >> semicolon >> pass ){
		line++;
		for(size_t i = 0; i < pass.size(); i++){
			if(i == ((size_t)n1 - 1)){
				if(pass[i] == letter){
					flaga = 1;
				}
				else{
					flaga = 0;
				}
			}
			if(i == ((size_t)n2 - 1 )){
				if(pass[i] == letter){
					flaga++;
				}
				else{
					flaga += 2;
				}
			}
		}
		if (flaga == 2){
			incorrect++;
		}
		else if (flaga == 3 or flaga == 1){
			correct++;
		}
		else{
			flaga =0;
		}
	}
	std::cout<<"Poprawne: "<< correct <<std::endl;
	std::cout<<"NIEPoprawne: "<< incorrect <<std::endl;
	std::cout<<std::endl;
	return correct;
}

int task3(std::fstream &File3){
	int count = 0, tree = 0;
	size_t step = 0;
	std::string line;
	std::vector<std::string> lines;
	while(File3 >> line){
		if(count > 0 and count % 2 == 0){
			if(line.size()  - 1 >= 1 * step){
				if(line[3*step] == '#'){
					tree++;
				}
			}
			else{
				std::string l_line;
				while(l_line.size() < 1*step + 1  ){
					l_line +=line;
				}
				if(l_line[1*step] == '#'){
					tree++;
				}
			}
		}
		if(count % 2 == 0) step++;
		count++;
	}
	return tree;
}

int task3_prim(std::fstream &File3, int option){
	int count = 0, tree = 0;
	size_t step = 0;
	size_t traverse = 0;
	std::string line;
		while(File3 >> line){
			//zmiana opcji przechodzenia
			traverse = option * step;
			if(count > 0){
				if(line.size() - 1 >= traverse){
					if(line[traverse] == '#'){
						tree++;
					}
				}
				else{
					std::string l_line;
					while(l_line.size() < traverse + 1  ){
						l_line +=line;
					}
					if(l_line[traverse] == '#'){
						tree++;
					}
				}
			}
			step++;
			count++;
		}
	return tree;
}

int task4(std::fstream &file){
	int count_bad = 0, count_correct = 0, count = 0, count_empty = 0;
	std::string line, passport= "";

	while(getline(file, line )){
		if(!line.empty()){
			count++;
			passport = passport + " " + line;
		}
		else{
			count_empty++;
			std::size_t found = passport.find("cid");
			if( std::count(passport.begin(), passport.end(), ':') == 8){
				count_correct++;
			}
			else if(std::count(passport.begin(), passport.end(), ':') ==  7){// 7 lub 8 headersow
				if(found!= std::string::npos ){ // jest cid
					count_bad++;
				}
				else{
					count_correct++;
				}
			}
			else{
				count_bad++;
			}
			passport = "";
		}
	}
	return count_correct + 1;
}

int task4_prim(std::fstream &file){
	int count_correct = 0;
	int counter = 0;
	std::vector<Passport> p = parse_input_from_file(file);
	for (auto i : p) {
		counter++;
		if ( i.is_valid() == 1) {
			count_correct++;
		}
	}
	return count_correct;
}

int task5(std::fstream &file){
	int max = 0;
	std::vector<std::string> t = decode_input(file);
	std::vector<int> maxi;
	for(auto i: t){
		max = decode_seat(i);
		maxi.push_back(max);
	}
	int solution = *max_element(maxi.begin(),maxi.end());
	std::sort(maxi.begin(),maxi.end());
	for(int k =0; k < (int)maxi.size(); k++){
		if(maxi[k] + 1 != maxi[k+1]){
			return maxi[k]+1;
		}
	}
	return solution;
}

int task6(std::fstream &file){
	int solution = 0;
	Declaration object;
	std::vector<std::vector<std::string>> t2 = parse_file2(file);
	object.check_second(t2);
	solution = object.sum;
	return solution;
}
/*
int task7(std::fstream &file)
{
	Bags object;
	Bags::contained_t contained;
	Bags::contains_t contains;

	std::vector<std::string> b = decode_input(file);
	object.parse_input(b, contained, contains);

	auto bags = contains["shiny gold"];
	std::deque<std::string> q({"shiny gold"});
	std::unordered_set<std::string> seen({"shiny gold"});
	while (!q.empty())
	{
		std::string bag_name = q.front();
		for (auto &bag : contained[bag_name])
		{
			if (seen.insert(bag).second)
			{
				q.push_back(bag);
			}
		}
		q.pop_front();
	}
	
	uint32_t numbers = object.count_bags(contains, "shiny gold");
	std::cout << "Solution 2: " << numbers << std::endl;
	std::cout << "Solution 1: ";
	return seen.size();
}
*/
int project_euler(){
	int result{0};
	result = one();
	result = fibonnaci();
	return result;
}
int one(){
	int game{0};
	for(int i = 1; i<1000 ; i++){
		if((i % 3 == 0) or (i % 5 == 0)){
			game += i;
		}
	}
	return game;
}

int fibonnaci(){
	int y = 0, x = 1, next = 0, sum = 0;
	int theEnd = (4*(pow(10,6)));
	while (next < theEnd){
		next = y + x;
		y = x;
		x = next;
		if(next % 2 == 0){
			sum += next;
		}
	}

	return sum;
}

int theLargestPrimeFactor(){
	//long long int n = 600851475143;
	int primeFactor = 0;
	return primeFactor;
}


int task8(std::fstream &file){
	int solution{0};
	std::vector<std::string> result;
    //result = decode_input(file);
    //Instruction obj;
    //obj.reading_instructions(result);
    return solution;
}


//ASN1 decoding BER 
void encode_tag(std::vector<uint8_t>& encoded_tag, ASN1_Tag class_tag_a, ASN1_Tag type_tag_a ){
	const uint32_t class_tag = static_cast<uint32_t>(class_tag_a);
	const uint32_t type_tag = static_cast<uint32_t>(type_tag_a);

	if(class_tag != 0x00 ){
		//TODO support for error and exception
		std::cout<<"DER encoding error, should be 0x00 (tag:universal) but is" + std::to_string(class_tag)<<std::endl;
	}

	//tags all happen to be under  31 (0x1F)
	if(type_tag <= 30 ){
		encoded_tag.push_back(static_cast<uint8_t>(type_tag | class_tag));
	}
	else{
		/* for above 31 -> rather rare
		 * for cases when any universal tag numbers higher than 31
		 * then those need to use the high tag number form, which takes extra bytes
		 */
		size_t blocks = high_bit(static_cast<uint32_t>(type_tag)) + 6;
		blocks = (blocks - (blocks % 7)) / 7;
		assert(blocks > 0);

		encoded_tag.push_back(static_cast<uint8_t>(class_tag | 0x1F));
		for(size_t i = 0; i != blocks - 1; ++i)
			encoded_tag.push_back(0x80 | ((type_tag >> 7*(blocks-i-1)) & 0x7F));
		encoded_tag.push_back(type_tag & 0x7F);
	}

}

int task_cert(std::fstream &file){
	int solution{0};
	/*
	std::vector<std::string> result;

	std::vector<uint8_t> encoded;
	encode_tag(encoded, ASN1_Tag::UNIVERSAL , ASN1_Tag::OCTET_STRING);

	for(auto i: encoded){
		std::cout<< " " << std::hex << int(i) << std::endl;
	}
	uint32_t test = 0x023000000;
	auto test_result = significant_bytes(test);
	std::cout<< "Result significant : " << test_result << std::endl;


	size_t blocks = high_bit(static_cast<uint32_t>(ASN1_Tag::APPLICATION));
	std::cout<< "Blocks: : " << blocks << std::endl;
	std::cout<<"Make Pair::"<<std::endl;
	std::vector<uint8_t> m;
	std::vector<std::vector<uint8_t>> m_set_contents;
	size_t len = 10;
	const uint8_t add[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
	m.reserve(len);
	for(int i = 0; i < 10; i++){
		m += std::make_pair(add, len);
		m_set_contents.push_back(std::move(m));
	}
	std::cout<<"Dalej::"<<std::endl;
	int co = 0;
	for(auto i: m_set_contents){
		co++;
		for(auto k: i){


			std::cout<<"Count " << co << " -> EL: "<<std::hex<<(int)k <<std::endl;

			}
	}
	*/
	std::cout <<"Test C++"<<std::endl;
	std::vector<uint8_t> encoded;

	for(auto i: encoded){
			std::cout<< " " << std::hex << int(i) << std::endl;
		}
    return solution;
}


/*
	uint32_t test1 = 0xF0F08400; // 16
	uint32_t test2 = 0xFF008400; // 0
	uint32_t test3 = 0x08008400; //4
	uint32_t test4 = 0x70008400; //1
	uint8_t test5 = 0x84;
	uint8_t test6 = 0x00;
	uint8_t test7 = 0x01;
	uint8_t test8 = 0x32;
	uint8_t test13 = 0xFF;
	uint64_t test9 = 0x0000840000008400;
	uint64_t test10 = 0x7000FFFF00008400;
	uint64_t test11 = 0xF000840000008400;
	uint64_t test12 = 0x000000000000000;
	auto test_result = expand_top_bit(static_cast<uint32_t>(test1));
	std::cout<< "Result: " << test_result << std::endl;
	std::cout<< "High bit: " << static_cast<int>(0x10) << std::endl;
	std::cout<< "High bit: " << test1 << " to:  "<< int(high_bit(test1)) << std::endl;
	std::cout<< "High bit: " << test2 << " to:  "<< int(high_bit(test2)) << std::endl;
	std::cout<< "High bit: " << test3 << " to:  "<< int(high_bit(test3)) << std::endl;
	std::cout<< "High bit: " << test4 << " to:  "<< int(high_bit(test4)) << std::endl;
	std::cout<< "High bit: " << test5 << " to:  "<< int(high_bit(test5)) << std::endl;
	std::cout<< "High bit: " << test6 << " to:  "<< int(high_bit(test6)) << std::endl;
	std::cout<< "High bit: " << test7 << " to:  "<< int(high_bit(test7)) << std::endl;
	std::cout<< "High bit: " << test8 << " to:  "<< int(high_bit(test8)) << std::endl;
	std::cout<< "High bit: " << test9 << " to:  "<< int(high_bit(test9)) << std::endl;
	std::cout<< "High bit: " << test10 << " to:  "<< int(high_bit(test10)) << std::endl;
	std::cout<< "High bit: " << test11 << " to:  "<< int(high_bit(test11)) << std::endl;
	std::cout<< "High bit: " << test12 << " to:  "<< int(high_bit(test12)) << std::endl;
	std::cout<< "Not " << ~0x0001001<< std::endl;
	std::cout<< "Sub" << 0x70001001 - 1 << std::endl;
	std::cout<< "Sub" << 0x00010070 - 1 << std::endl;
	std::cout<< "ct: " << check(test1) << std::endl;
		std::cout<< "Hctt: " << check(test2)  << std::endl;
		std::cout<< "ctt: " << std::hex << int(check(test6))   << std::endl;
		std::cout<< "ctt: " << std::hex << int(check(test12))   << std::endl;
		std::cout<< "ctt: " << std::hex << int(check(test13))   << std::endl;

		//my high_bit
		std::cout<< "High bit: " << test1 << " to:  "<< int(high_bit_my(test1)) << std::endl;
			std::cout<< "High bit: " << test2 << " to:  "<< int(high_bit_my(test2)) << std::endl;
			std::cout<< "High bit: " << test3 << " to:  "<< int(high_bit_my(test3)) << std::endl;
			std::cout<< "High bit: " << test4 << " to:  "<< int(high_bit_my(test4)) << std::endl;
			std::cout<< "High bit: " << test5 << " to:  "<< int(high_bit_my(test5)) << std::endl;
			std::cout<< "High bit: " << test6 << " to:  "<< int(high_bit_my(test6)) << std::endl;
			std::cout<< "High bit 7: " << test7 << " to:  "<< int(high_bit_my(test7)) << std::endl;
			std::cout<< "High bit: " << test8 << " to:  "<< int(high_bit_my(test8)) << std::endl;
			std::cout<< "High bit: " << test9 << " to:  "<< int(high_bit_my(test9)) << std::endl;
			std::cout<< "High bit: " << test10 << " to:  "<< int(high_bit_my(test10)) << std::endl;
			std::cout<< "High bit: " << test11 << " to:  "<< int(high_bit_my(test11)) << std::endl;
			std::cout<< "High bit: " << test12 << " to:  "<< int(high_bit_my(test12)) << std::endl;*/