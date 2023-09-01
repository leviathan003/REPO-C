Table of Contents
Introduction
Prerequisites
Application Overview
Installation and Setup
Using the Calculator
Memory Functions
Troubleshooting
Conclusion

1. Introduction
This documentation provides step-by-step instructions on how to set up and use a Python-based calculator application. The application allows users to perform basic arithmetic operations, save results to memory, and recall stored values.

2. Prerequisites
Before you begin, make sure you have the following prerequisites in place:

A computer or device with Python 3.6 or higher installed.
Basic knowledge of using a command-line interface (CLI).

3. Application Overview
The Python Calculator is a graphical user interface (GUI) application built using PyQt6. It features a main display for input and results, numerical and operational buttons, and memory functions.

4. Installation and Setup
Python Installation: Ensure you have Python 3.6 or higher installed on your computer. If not, download and install it from Python's official website.

Install PyQt6: The calculator relies on the PyQt6 library. You can install it using pip, the Python package manager, by running the following command:

Copy code
pip install PyQt6
Download the Calculator Script: Download the calculator script from GitHub.

5. Using the Calculator
Running the Application: Open a command prompt or terminal and navigate to the folder where you downloaded the calculator script. Run the application by executing the following command:

Copy code
python calculator.py

Calculator Interface: The calculator window will open, displaying a main display area at the top for input and results, numerical buttons (0-9), operational buttons (+, -, *, /), a decimal point (.), clear (AC) button, and an equals (=) button.

Performing Calculations: Use the numerical buttons to enter numbers and the operational buttons to perform arithmetic operations. Click the equals button (=) to calculate the result, which will be displayed in the main display area.

Clearing Input: Click the clear (AC) button to clear the input and start a new calculation.

6. Memory Functions
Memory Save (MS): To save the current result to memory, click the "MS" button. The saved value will appear in the memory section on the right.

Memory Recall: To recall a saved value from memory, click on the respective memory button (e.g., M1, M2) displaying the saved value. The recalled value will be added to the current input expression.

Memory Clear (MC): To clear all saved values from memory, click the "MC" button. This action will remove all saved values, and the memory section will display a placeholder message.

7. Troubleshooting
Division by Zero: If you attempt to divide by zero, the calculator will display an error message in the main display area.
Invalid Syntax: If you enter an invalid expression, such as mismatched parentheses or operators, the calculator will display an "Invalid Syntax" error message.

8. Conclusion
You've successfully set up and used the Python Calculator application. This calculator allows you to perform basic arithmetic calculations, save results to memory, and recall them as needed. Enjoy your calculations!




