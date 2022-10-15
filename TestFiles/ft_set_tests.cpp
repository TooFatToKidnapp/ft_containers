#include"./utils.hpp"


void print_set(ft::set<char> set, std::string name)
{
	cout << name << ":\n";
	for (ft::set<char>::iterator it = set.begin(); it != set.end(); it++)
		cout << *it << ", ";
	cout << std::endl;
	cout << std::endl;
}

void print_size(ft::set<char> set, std::string name)
{
	cout << name << " size: " << set.size() << ", max_size: " << set.max_size() << std::endl;
	cout << name << " empty() (1: true 0:false): " << set.empty() << std::endl;
	cout << std::endl;
}

void set_tests()
{
	print_title("CONSTRUCTOR", "set");
	ft::set<char> ft_set;
	print_size(ft_set, "set");

	char c = 'a';
	for (int i = 1; i <= 13; i++, c++)
	{
		ft_set.insert(c);
	}
	print_set(ft_set, "set");
	print_size(ft_set, "set");

	print_title("RANGE", "set");
	ft::set<char> ft_set_range(ft_set.begin(), ft_set.end());
	print_size(ft_set_range, "set_range");
	print_set(ft_set_range, "set_range");

	print_title("COPY CONSTRUCTOR (copy of range)", "set");
	ft::set<char> ft_set_copy(ft_set_range);
	print_size(ft_set_copy, "set_copy");
	print_set(ft_set_copy, "set_copy");


	print_title("ASSIGNATION OPERATOR", "set");
	ft::set<char> ft_set_assignation;
	ft_set_assignation = ft_set_copy;
	print_size(ft_set_assignation, "set_assignation");
	print_set(ft_set_assignation, "set_assignation");


	print_title("ITERATORS TESTS");
	cout << "set (iterator): ";
	for (ft::set<char>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
		cout << *it << ", ";
	cout << "\n" << std::endl;
	cout << "set (const_iterator): ";
	for (ft::set<char>::const_iterator it = ft_set.begin(); it != ft_set.end(); it++)
		cout << *it << ", ";
	cout << "\n" << std::endl;
	cout << "set (reverse_iterator): ";
	for (ft::set<char>::reverse_iterator rit = ft_set.rbegin(); rit != ft_set.rend(); rit++)
		cout << *rit << ", ";
	cout << "\n" << std::endl;
	cout << "set (const_reverse_iterator): ";
	for (ft::set<char>::const_reverse_iterator rit = ft_set.rbegin(); rit != ft_set.rend(); rit++)
		cout << *rit << ", ";
	cout << "\n" << std::endl;

	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, empty");
	print_size(ft_set, "set");

	print_title("SET INSERT(val)");
	for (int i = 14; i <= 19; i++, c++)
	{
		ft_set.insert(c);
	}
	print_set(ft_set, "set");
	print_size(ft_set, "set");

	print_title("SET INSERT(position, val)");
	for (int i = 20; i <= 26; i++, c++)
	{
		ft_set.insert(c);
	}
	print_set(ft_set, "set");
	print_size(ft_set, "set");

	print_title("SET INSERT(first, last)", "set -> set_copy");
	print_title("BEFORE INSERT");
	print_set(ft_set_copy, "set_copy");

	print_title("AFTER INSERT");
	ft_set_copy.insert(ft_set.begin(), ft_set.end());
	print_set(ft_set_copy, "set_copy");
	print_size(ft_set_copy, "set_copy");

	print_title("SET ERASE(position)", "erasing first half of set_copy");
	ft::set<char>::iterator std_it_half = ft_set_copy.find('n');
	for (ft::set<char>::iterator it = ft_set_copy.begin(); it != std_it_half; it++)
		ft_set_copy.erase(it);
	print_set(ft_set_copy, "set_copy");
	print_size(ft_set_copy, "set_copy");

	print_title("SET ERASE(key)", "erasing another half of set_copy");
	c = 'n';
	for (int i = 0; i < 6; i++, c++)
	{
		ft_set_copy.erase(c);
	}
	print_set(ft_set_copy, "set_copy");
	print_size(ft_set_copy, "set_copy");

	print_title("SET ERASE(first, last)", "finishing the job set_copy");
	ft_set_copy.erase(ft_set_copy.begin(), ft_set_copy.end());
	print_set(ft_set_copy, "set_copy");
	print_size(ft_set_copy, "set_copy");

	print_title("SET SWAP() (MEMBER)", "swaping set_range and set_copy");
	print_title("BEFORE SWAP");
	print_set(ft_set_range, "set_range");
	print_set(ft_set_copy, "set_copy");
	ft_set_range.swap(ft_set_copy);
	print_title("AFTER SWAP");
	print_set(ft_set_range, "set_range");
	print_set(ft_set_copy, "set_copy");

	print_title("SET CLEAR", "clearing set copy again");
	print_title("BEFORE");
	print_set(ft_set_copy, "set_copy");
	print_size(ft_set_copy, "set_copy");
	ft_set_copy.clear();
	print_title("AFTER");
	print_set(ft_set_copy, "set_copy");
	print_size(ft_set_copy, "set_copy");

	print_title("SET FIND(key) const and non_const");
	ft::set<char>::iterator find_a = ft_set.find('a');
	ft::set<char>::const_iterator find_z = ft_set.find('z');
	cout << "find('a'): " << *find_a << '\n';
	cout << "find('z'): " << *find_z << '\n';

	print_title("SET COUNT(key)");
	cout << 'a';
	if (ft_set.count('a') > 0)
		cout << " is an element of set.\n";
	else
		cout << " is not an element of set.\n";
	cout << '1';
	if (ft_set.count('1') > 0)
		cout << " is an element of set.\n";
	else
		cout << " is not an element of set.\n";

	print_title("SET LOWER_BOUND AND UPPER_BOUND", "using it to erase from b to g");
	ft::set<char>::iterator itlow = ft_set.lower_bound('b');
	ft::set<char>::iterator itup = ft_set.upper_bound('g');
	ft_set.erase(itlow, itup);
	print_set(ft_set, "set");
	print_size(ft_set, "set");

	print_title("SET EQUAL_RANGE", "for h");
	ft::pair<ft::set<char>::iterator,ft::set<char>::iterator> ret;
	ret = ft_set.equal_range('h');
	cout << "lower bound points to: ";
	cout << *(ret.first) << '\n';
	cout << "upper bound points to: ";
	cout << *(ret.second) << '\n';

	print_title("SET KEY_COMP AND VALUE_COMP", "display everything lower than m");
	ft::set<char>::key_compare mycomp = ft_set.key_comp();

	char highest_key = 'm';
	char highest = *ft_set.find('m');

	ft::set<char>::iterator it = ft_set.begin();
	while (ft_set.value_comp()(*it, highest) && mycomp(*it, highest_key))
	{
		cout << *it << '\n';
		it++;
	}
}
