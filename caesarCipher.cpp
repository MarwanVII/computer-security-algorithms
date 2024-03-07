#include <bits/stdc++.h>
using namespace std;

string encrypt(string output, int key)
{
	for(auto &c:output)
	{
		if(!isalpha(c))
			continue;
		if(islower(c))
		{
			int dif = (c - 'a' + key)%26;
			c = 'a' + dif;
		}
		else if(isupper(c))
		{
			int dif = (c - 'A' + key)%26;
			c = 'A' + dif;
		}
	}
	return output;
}

string decrypt(string output, int key)
{
	for(auto &c:output)
	{
		if(!isalpha(c))
			continue;
		if(islower(c))
		{
			int dif = abs(c - 'a' - key + 26)%26;
			c = 'a' + dif;
		}
		else if(isupper(c))
		{
			int dif = abs(c - 'A' - key + 26)%26;
			c = 'A' + dif;
		}
	}
	return output;
}

int main() {
	string s;
	int key;
	cout << "Enter a text: ";
	getline(cin,s);
	cout << "Enter a key: ";
	cin >> key;
	string encrypted = encrypt(s,key);
	cout << "Encrypted: " << encrypted << endl;
	cout << "Decrypted: " << decrypt(encrypted,key) << endl;
	return 0;
}
