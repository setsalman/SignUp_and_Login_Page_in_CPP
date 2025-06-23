A simple console-based Login System developed in C++. It allows users to:

--> Register (Sign Up)
--> Login
--> Recover Forgotten Password

User data is stored in a local file (records.txt).


File Structure:

.
├── app.cpp             # Main C++ source code
├── records.txt         # User data (auto-created if not present)
└── README.md           # This file




Features:

User Registration (Username + Password)
Login Authentication
Forgot Password feature (retrieve password by username)
Data storage using file handling (fstream)
Simple text-based interface


How to run it correctly:

1. Compile: g++ login_system.cpp -o login_system
2. Run: ./login_system     # Linux/Mac
        login_system.exe   # Windows

    Or if you are using VS Code: Ctrl + Alt + N



