import os
import platform

def shutdown():
    # Determine the operating system
    if platform.system() == "Windows":
        os.system("shutdown /s /t 1")
    elif platform.system() == "Linux" or platform.system() == "Darwin":  # Darwin is for macOS
        os.system("shutdown now")
    else:
        print("Unsupported OS")

if __name__ == "__main__":
    shutdown()
