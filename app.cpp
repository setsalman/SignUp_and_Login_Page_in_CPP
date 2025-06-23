#include <iostream>     // Include input/output stream for cin, cout
#include <fstream>      // Include file stream for reading/writing files
#include <string>       // Include string class to handle text
using namespace std;    // Use the standard namespace

// Class definition for LoginSystem
class LoginSystem {
private:
    const string filename = "records.txt";  // File where user records (username and password) will be stored

public:
    // Main menu function to display options repeatedly
    void mainMenu() {
        int choice;     // Variable to store user menu choice
        while (true) {  // Infinite loop to keep showing the menu until the user chooses to exit
            cout << "\n==== Login System ====\n";           
            cout << "1. Login\n";                          
            cout << "2. Register\n";                       
            cout << "3. Forgot Password\n";                 
            cout << "4. Exit\n";                            
            cout << "Choice: ";                             
            cin >> choice;                                 

            switch (choice) {                               
                // If choice is 1, call login() function
                case 1: login(); break;   

                // If choice is 2, call registerUser() function
                case 2: registerUser(); break;     

                // If choice is 3, call forgotPassword() function
                case 3: forgotPassword(); break;        
                
                // If choice is 4, print exit message and break loop
                case 4: cout << "Goodbye!\n"; return;  
                
                // If input doesn't match any case, show error
            
                default: cout << "Invalid choice.\n";
                
            }
        }
    }

    // Function to handle user login
    void login() {

        // Variables for entered credentials and file data
        string username, password, id, pass;  
        bool found = false;                   

        cout << "\nUsername: "; cin >> username;  // Prompt and input for username
        cout << "Password: "; cin >> password;    // Prompt and input for password

        // Open the file to read stored usernames/passwords
        ifstream file(filename);                  

        while (file >> id >> pass) {              
            if (id == username && pass == password) {  
                found = true;                     
                break;                            
            }
        }
        // Close the file after reading
        file.close();                             

        // Print success if match found
        if (found) cout << "\n✅ Login successful!\n";  

        // Print error if no match
        else cout << "\n❌ Invalid username or password.\n";  
    }

    // Function to handle user registration (sign up)
    void registerUser() {
        string username, password;               

        cout << "\nChoose Username: "; cin >> username;  
        cout << "Choose Password: "; cin >> password;    

        // Open the file in append mode to add new record
        ofstream file(filename, ios::app);       
        file << username << ' ' << password << endl; 
        file.close();                            

        cout << "\n✅ Registration successful!\n";  
    }

    // Function to help retrieve forgotten password by searching username
    void forgotPassword() {
        string username, id, pass, found_pass;   
        bool found = false;                      

        cout << "\nEnter your username to retrieve your password: ";  
        cin >> username;                                           

        ifstream file(filename);                  
        while (file >> id >> pass) {              
            if (id == username) {                 
                found = true;                     
                found_pass = pass;                
                break;                            
            }
        }
        file.close();                             

        if (found) cout << "\n✅ Your password is: " << found_pass << "\n";  
        else cout << "\n❌ Username not found.\n";                           
    }
};

// Main function 
int main() {
    LoginSystem system;       // Create an object of the LoginSystem class
    system.mainMenu();        // Call mainMenu() on the object to start the program
    return 0;                 
}
