#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <openssl/sha.h>
#include <sqlite3.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

void SetStdinEcho(bool enable = true) {
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

sqlite3* database;

string sha256(string s) {
    unsigned char out[SHA256_DIGEST_LENGTH];

    SHA256((unsigned char*)s.c_str(), s.size(), out);

    ostringstream s_out;
    s_out << hex;

    for (long long c:out)   s_out << setw(2) << setfill('0') << c;

    return s_out.str();
}

void init_database() {
    int failure = sqlite3_open("ppab6-test.db", &database);
    if (failure) {
        cout << "ERROR opening DB\n";
        exit(1);
    }
}

static int callback(void* data, int argc, char** argv, char** azColName) {
    if (argv[0] && argv[1]) {
        cout << "\nAuthenticated\n";
    }

    return 0;
}

void validate_credentials(string username, string password) {
    password = sha256(password);

    string sql = "SELECT * FROM USERS WHERE username=\"" + username + "\" AND password_hash=\"" + password + "\";";

    int result = sqlite3_exec(database, sql.c_str(), callback, NULL, NULL);

    if (result != SQLITE_OK) {
        cout << "ERROR fetching data\n";
        exit(1);
    }

}

int main() {
    init_database();

    string username, password;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    SetStdinEcho(false);
    cin >> password;

    SetStdinEcho(true);
    validate_credentials(username, password);

    sqlite3_close(database);
    return 0;
}