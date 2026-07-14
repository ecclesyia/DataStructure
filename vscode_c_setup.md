# 🛠️ VS Code C Compilation Setup & Troubleshooting

VS Code is an extremely powerful code editor, but unlike Dev-C++, it does not come with a built-in C compiler. When you try to run a program, VS Code might give you an error, fail to compile, or try to use Visual Studio's `cl.exe` compiler (which might not be installed on your computer).

Follow this guide to set up the **GCC (MinGW)** compiler and configure VS Code correctly on Windows to run all Data Structure programs.

---

## 📥 Step 1: Install the GCC Compiler (via MSYS2)
Windows does not have GCC by default. The best way to get it is through **MSYS2**:

1. Download MSYS2 from [msys2.org](https://www.msys2.org/).
2. Run the installer and follow the wizard (it is recommended to use the default installation path: `C:\msys64`).
3. Once the installation finishes, check the box to **"Run MSYS2 now"**. A black terminal will open.
4. In the MSYS2 terminal, type the following command to install the full MinGW-w64 toolchain (which includes `gcc`, `g++`, and `gdb` debugger):
   ```bash
   pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
   ```
5. Press **Enter** to accept the default options and type `y` to confirm the installation.

---

## ⚙️ Step 2: Add Compiler to Windows System Environment PATH
To allow VS Code (and your computer's terminal) to find the compiler:

1. Press the **Windows Key** and search for **"Edit the system environment variables"**.
2. Click the **Environment Variables...** button at the bottom right.
3. Under "System variables", select the variable named **Path** and click **Edit...**.
4. Click **New** and add the bin path of your MSYS2 compiler (usually `C:\msys64\ucrt64\bin`).
5. Click **OK** on all windows to save.
6. **Verify compilation**: Open Command Prompt (`cmd`) or PowerShell, and type:
   ```cmd
   gcc --version
   ```
   If you see GCC version information, you have successfully configured the environment variables!

---

## 🧩 Step 3: Install VS Code Extensions
Open VS Code and install the following extensions from the Extension Marketplace (`Ctrl + Shift + X`):
1. **C/C++** (by Microsoft) — Provides syntax highlighting, code completion (IntelliSense), and debugging support.
2. **C/C++ Extension Pack** — Installs a collection of useful tools for C/C++ development.
3. *(Optional)* **Code Runner** — Allows you to run code by clicking a Play button in the top right.

---

## 📁 Step 4: Configure VS Code Compilation Task (`tasks.json`)
VS Code compiles code using build tasks defined in a `.vscode/tasks.json` file. If VS Code is trying to use `cl.exe` (Microsoft Visual C++ compiler) but fails, it means your configuration is targeting the wrong compiler.

Here is the correct `.vscode/tasks.json` configuration for GCC (MinGW). We have preconfigured this in this repository:

Create a file named `.vscode/tasks.json` in your project folder with the following content:
```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: gcc.exe build active file",
            "command": "gcc",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe",
                "-std=c11"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Task compiled with GCC compiler."
        }
    ],
    "version": "2.0.0"
}
```

---

## 🎮 Step 5: How to Run the Code
1. Open any `.c` file in VS Code (e.g. `Session_01_PointersAndMemory/pointers_basics.c`).
2. Press **`Ctrl + Shift + B`** to compile the file. This creates an `.exe` file in the same folder.
3. Open the integrated VS Code terminal (`Ctrl + ~`).
4. Run the compiled `.exe` by typing:
   ```powershell
   .\pointers_basics.exe
   ```
5. If you installed the **Code Runner** extension:
   - Go to VS Code Settings (`Ctrl + ,`).
   - Search for `code-runner: Run In Terminal` and check the box.
   - Now you can just click the **Play** button in the top-right corner to compile and run in one click!
