# ProgrammingProject
The code for the Online Store Programming Project

### Notes regarding running

This project can sometimes have trouble running on certain operating systems.
Here is what you should do to ensure that everything works accordingly.

#### Windows
If running the executable is not possible directly, you may want to try:
1. Running from PowerShell the command `./Project`
2. Re-building the application (it was build on macOS, which may cause issues)

#### macOS/Linux
The working directory may not load correctly at runtime, causing a segfault.
Therefore I recommend running the program using the provided program.sh file.
If you encounter issues with this, there are two ways to run it regardless:
1. Give executable perms to program.sh: `chmod +x program.sh`
2. Just run the project directly but from Terminal: `./Project` 
