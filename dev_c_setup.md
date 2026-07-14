# 🛠️ Dev-C++ Installation and Setup Guide

Dev-C++ is a classic, lightweight Integrated Development Environment (IDE) widely used at Binus University because it comes pre-packaged with the **MinGW (GCC)** compiler and requires almost zero setup. However, to compile modern C code (like standard structure initializations, arrays, and standard libraries), you should configure it correctly.

Follow this step-by-step guide to install, configure, compile, and troubleshoot Dev-C++.

---

## 📥 1. Installation
1. Download the latest version of Dev-C++ (Embarcadero Dev-C++ is recommended as it is actively maintained).
2. Run the installer and follow the instructions.
3. Ensure the option to install the compiler **(TDM-GCC or MinGW)** is checked during installation.

---

## ⚙️ 2. Critical Configuration: Enable C99/C11 Standard
By default, Dev-C++ might compile using an older C standard, which can throw syntax errors for modern C practices (like declaring a variable inside a `for` loop `for(int i = 0; ...)`). 

To enable the C99 or C11 standard:
1. Open Dev-C++.
2. Go to the top menu and select **Tools** ➡️ **Compiler Options**.
3. In the Compiler Options window, select the **Compiler** tab.
4. Check the box that says: **"Add the following commands when calling the compiler:"**
5. In the text box below it, type exactly:
   ```text
   -std=c11
   ```
   *(If you prefer C99, type `-std=c99`)*
6. Click **OK** to save the changes.

---

## 💻 3. Compiling and Running Programs
Writing, compiling, and running C code is simple using keyboard shortcuts:
* **Create New File**: `Ctrl + N`
* **Save File**: `Ctrl + S` (Make sure to save with the `.c` extension, not `.cpp` if writing pure C!).
* **Compile Only**: Press **F9** (checks for syntax errors and builds the executable).
* **Run Only**: Press **F10** (runs the previously compiled executable).
* **Compile & Run**: Press **F11** (recommended: compiles and runs in one step).

---

## 🔍 4. Troubleshooting Common Errors

### ❌ Error 1: "Source file not compiled"
This occurs when you try to run (F10) a file that hasn't been compiled yet, or the compilation failed due to a path or permission issue.
* **Solution**: Press **F11** instead of F10 to compile it first. If it still fails, ensure your file path does not contain special characters or emojis, and that you have permission to write to the folder (avoid compiling files directly inside `C:\Program Files` or system folders).

### ❌ Error 2: The Console Window Opens and Closes Instantly
When you run the code, the terminal window pops up and disappears before you can see the output.
* **Solution**: Add a system pause or a character input block before `return 0;` at the end of your `main` function.
  ```c
  #include <stdio.h>
  
  int main() {
      printf("Hello, World!\n");
      
      // This keeps the console window open in older systems
      printf("Press Enter to exit...");
      getchar(); 
      return 0;
  }
  ```

### ❌ Error 3: "undefined reference to..."
This usually happens if you declare a function but forget to define it, or if you are working with multiple files but didn't compile them together as a Dev-C++ "Project".
* **Solution**: If you have multiple `.c` and `.h` files, do not compile them as single files. Instead:
  1. Go to **File** ➡️ **New** ➡️ **Project**.
  2. Select **Console Application**, choose **C Project**, and click OK.
  3. Add all your files to the project and compile the project as a whole.
