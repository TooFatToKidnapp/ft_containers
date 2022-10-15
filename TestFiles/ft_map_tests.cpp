#include "./utils.hpp"

void print_map(ft::map<char, int> map, std::string name)
{
	cout << name << ":\n";
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
		cout << (*it).first << " = " << (*it).second << ", ";
	cout << std::endl;
	cout << std::endl;
}

void print_size(ft::map<char, int> map, std::string name)
{
	cout << name << " size: " << map.size() << ", max_size: " << map.max_size() << std::endl;
	cout << name << " empty() (1: true 0:false): " << map.empty() << std::endl;
	cout << std::endl;
}

void map_tests()
{
	print_title("CONSTRUCTOR", "map");
	ft::map<char, int> ft_map;
	print_size(ft_map, "map");

	char c = 'a';
	for (int i = 1; i <= 13; i++, c++)
	{
		ft_map[c] = i;
	}
	print_map(ft_map, "map");
	print_size(ft_map, "map");

	print_title("RANGE", "map");
	ft::map<char, int> ft_map_range(ft_map.begin(), ft_map.end());
	print_size(ft_map_range, "map_range");
	print_map(ft_map_range, "map_range");

	print_title("COPY CONSTRUCTOR (copy of range)", "map");
	ft::map<char, int> ft_map_copy(ft_map_range);
	print_size(ft_map_copy, "map_copy");
	print_map(ft_map_copy, "map_copy");


	print_title("ASSIGNATION OPERATOR", "map");
	ft::map<char, int> ft_map_assignation;
	ft_map_assignation = ft_map_copy;
	print_size(ft_map_assignation, "map_assignation");
	print_map(ft_map_assignation, "map_assignation");


	print_title("ITERATORS TESTS");
	cout << "map (iterator): ";
	for (ft::map<char, int>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
		cout << (*it).first << " = " << (*it).second << ", ";
	cout << "\n" << std::endl;
	cout << "map (const_iterator): ";
	for (ft::map<char, int>::const_iterator it = ft_map.begin(); it != ft_map.end(); it++)
		cout << (*it).first << " = " << (*it).second << ", ";
	cout << "\n" << std::endl;
	cout << "map (reverse_iterator): ";
	for (ft::map<char, int>::reverse_iterator rit = ft_map.rbegin(); rit != ft_map.rend(); rit++)
		cout << (*rit).first << " = " << (*rit).second << ", ";
	cout << "\n" << std::endl;
	cout << "map (const_reverse_iterator): ";
	for (ft::map<char, int>::const_reverse_iterator rit = ft_map.rbegin(); rit != ft_map.rend(); rit++)
		cout << (*rit).first << " = " << (*rit).second << ", ";
	cout << "\n" << std::endl;

	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, empty");
	print_size(ft_map, "map");

	print_title("MAP INSERT(val)");
	for (int i = 14; i <= 19; i++, c++)
	{
		ft_map.insert(ft::make_pair(c, i));
	}
	print_map(ft_map, "map");
	print_size(ft_map, "map");

	print_title("MAP INSERT(position, val)");
	for (int i = 20; i <= 26; i++, c++)
	{
		ft_map.insert(ft::make_pair(c, i));
	}
	print_map(ft_map, "map");
	print_size(ft_map, "map");

	print_title("MAP INSERT(first, last)", "map -> map_copy");
	print_title("BEFORE INSERT");
	print_map(ft_map_copy, "map_copy");

	print_title("AFTER INSERT");
	ft_map_copy.insert(ft_map.begin(), ft_map.end());
	print_map(ft_map_copy, "map_copy");
	print_size(ft_map_copy, "map_copy");

	print_title("MAP ERASE(position)", "erasing first half of map_copy");
	ft::map<char, int>::iterator std_it_half = ft_map_copy.find('n');
	for (ft::map<char, int>::iterator it = ft_map_copy.begin(); it != std_it_half; it++)
		ft_map_copy.erase(it);
	print_map(ft_map_copy, "map_copy");
	print_size(ft_map_copy, "map_copy");

	print_title("MAP ERASE(key)", "erasing another half of map_copy");
	c = 'n';
	for (int i = 0; i < 6; i++, c++)
	{
		ft_map_copy.erase(c);
	}
	print_map(ft_map_copy, "map_copy");
	print_size(ft_map_copy, "map_copy");

	print_title("MAP ERASE(first, last)", "finishing the job map_copy");
	ft_map_copy.erase(ft_map_copy.begin(), ft_map_copy.end());
	print_map(ft_map_copy, "map_copy");
	print_size(ft_map_copy, "map_copy");

	print_title("MAP SWAP() (MEMBER)", "swaping map_range and map_copy");
	print_title("BEFORE SWAP");
	print_map(ft_map_range, "map_range");
	print_map(ft_map_copy, "map_copy");
	ft_map_range.swap(ft_map_copy);
	print_title("AFTER SWAP");
	print_map(ft_map_range, "map_range");
	print_map(ft_map_copy, "map_copy");

	print_title("MAP CLEAR", "clearing map copy again");
	print_title("BEFORE");
	print_map(ft_map_copy, "map_copy");
	print_size(ft_map_copy, "map_copy");
	ft_map_copy.clear();
	print_title("AFTER");
	print_map(ft_map_copy, "map_copy");
	print_size(ft_map_copy, "map_copy");

	print_title("MAP FIND(key) const and non_const");
	ft::map<char, int>::iterator find_a = ft_map.find('a');
	ft::map<char, int>::const_iterator find_z = ft_map.find('z');
	cout << "find('a'): " << (*find_a).first << " = " << (*find_a).second << '\n';
	cout << "find('z'): " << (*find_z).first << " = " << (*find_z).second << '\n';

	print_title("MAP COUNT(key)");
	cout << 'a';
	if (ft_map.count('a') > 0)
		cout << " is an element of map.\n";
	else
		cout << " is not an element of map.\n";
	cout << '1';
	if (ft_map.count('1') > 0)
		cout << " is an element of map.\n";
	else
		cout << " is not an element of map.\n";

	print_title("MAP LOWER_BOUND AND UPPER_BOUND", "using it to erase from b to g");
	ft::map<char,int>::iterator itlow = ft_map.lower_bound('b');
	ft::map<char,int>::iterator itup = ft_map.upper_bound('g');
	ft_map.erase(itlow, itup);
	print_map(ft_map, "map");
	print_size(ft_map, "map");

	print_title("MAP EQUAL_RANGE", "for h");
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = ft_map.equal_range('h');
	cout << "lower bound points to: ";
	cout << ret.first->first << " => " << ret.first->second << '\n';
	cout << "upper bound points to: ";
	cout << ret.second->first << " => " << ret.second->second << '\n';

	print_title("MAP KEY_COMP AND VALUE_COMP", "display everything lower than m");
	ft::map<char,int>::key_compare mycomp = ft_map.key_comp();

	char highest_key = 'm';
	ft::pair<char,int> highest = *ft_map.find('m');

	ft::map<char,int>::iterator it = ft_map.begin();
	while (ft_map.value_comp()(*it, highest) && mycomp((*it).first, highest_key))
	{
		cout << it->first << " => " << it->second << '\n';
		it++;
	}
}
