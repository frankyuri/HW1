#include <iostream>
#include <iomanip>
using namespace std;
struct node {
	char n;
	node* next;
};
typedef node* NOD;
NOD del(int num, NOD *head) {
	NOD tmp = *head;
	while (tmp) {
		if (tmp->n == num) {
			*head = tmp->next;
			tmp = tmp->next;
		}
		else if (tmp->next == nullptr)
			break;
		else if (tmp->next->n == num)
			tmp->next = tmp->next->next;
		else
			tmp = tmp->next;
	}
	return *head;
}
NOD input(int num, NOD *head)
{
	NOD now = *head;
	NOD tmp = new node;
	tmp->n = num;
	tmp->next = nullptr;
	if (now == nullptr || now->n >= num) {
		tmp->next = *head;
		*head = tmp;
		return tmp;
	}
	else {
		while (now->next != nullptr && now->next->n <num)
			now = now->next;
		tmp->next = now->next;
		now->next = tmp;
		return *head;
	}
}
void display(NOD head) {
	NOD ptr;
	ptr = head;
	while (ptr != nullptr) {
		cout << setw(3) << ptr->n;
		ptr = ptr->next;
	}
	cout << endl;
}
int main() {
	int z = 0;
	char c;
	NOD head = nullptr;
	while (1)
	{
		cout << "Input or Delete?";
		cin >> c;
		char number;
		switch (c)
		{
		case 'I':
		case 'i':
			cin >> number;
			head = input(number, &head);
			display(head);
			break;
		case 'D':
		case 'd':
			cin >> number;
			head = del(number, &head);
			display(head);
			break;
		default:
			z = 1;
			break;
		}
		if (z) break;
	}
}
