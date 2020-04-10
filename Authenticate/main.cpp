#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

map<string, string> database;

string sha256(string s) {
    unsigned char out[SHA256_DIGEST_LENGTH];

    SHA256((unsigned char*)s.c_str(), s.size(), out);

    ostringstream s_out;
    s_out << hex;

    for (long long c:out)   s_out << setw(2) << setfill('0') << c;

    return s_out.str();
}

void init_database() {
    fstream file("credentials.csv", ios::in);
    string line, user, pass;
    int i;

    database.clear();

    while(getline(file, line)) {
        user = pass = "";
        for (i = 0; line[i] != ','; i++) {
            user += line[i];
        }
        i++;
        for (; i != line.size(); i++) {
            pass += line[i];
        }

        database.insert(pair<string, string>(user, pass));
    }
}

bool is_valid_credentials(string username, string password) {
    if (database.count(username) != 0 && database[username] == password)    return true;
    return false;
}

int main() {
    init_database();

    string username, password;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (is_valid_credentials(username, sha256(password))) {
        cout << "Authenticated\n";
    } else  cout << "Access Denied\n";

    return 0;
}