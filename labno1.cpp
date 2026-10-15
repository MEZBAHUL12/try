#include <iostream>
using namespace std;

bool isNumericConstant(char str[]) {
    if (str[0] == '\0')
        return false;

    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;

    if (str[i] == '\0')
        return false;

    int dotCount = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {

        }
        else if (str[i] == '.' && dotCount == 0) {
            dotCount++;
        }
        else {
            return false;
        }
        i++;
    }
    return true;
}
void findOperators(char str[]) {
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        char ch = str[i];

        if (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '%' || ch == '=') {
            count++;
            cout << "operator" << count << ": " << ch << endl;
        }
        i++;
    }

    if (count == 0)
        cout << "No operators found." << endl;
}

int isComment(char str[]) {

    int len = 0;
    while (str[len] != '\0')
        len++;

    while (len > 0) {
        char c = str[len - 1];
        if (c == '\n' || c == '\r' || c == ' ' || c == '\t') {
str[len - 1] = '\0';
            len--;
        }
        else {
break;
        }
    }

 if (len >= 2 && str[0] == '/' && str[1] == '/')
        return 1;

    if (len >= 2 && str[0] == '/' && str[1] == '*')
        return 2;
return 0;
}

bool isIdentifier(char str[]) {
    if (str[0] == '\0')
        return false;

    char c = str[0];
    if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_'))
        return false;

    int i = 1;
    while (str[i] != '\0') {
        c = str[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') || c == '_') {

        }
else {
            return false;
        }
        i++;
    }
return true;
}
float findAverage(int arr[], int n) {
    float sum = 0;
for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    return sum / n;
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
return max;
}

void concatenate(char first[], char last[], char full[]) {
    int i = 0;

    while (first[i] != '\0') {
        full[i] = first[i];
        i++;
    }
 full[i] = ' ';
i++;

    int j = 0;
    while (last[j] != '\0') {
        full[i] = last[j];
        i++;
j++;
    }
full[i] = '\0';
}
int main() {
    int choice, n, arr[100];
    char input[500];
    char firstName[50], lastName[50], fullName[110];

    cout << "LAB TASK 1" << endl;
    cout << "1. Numeric Constant" << endl;
    cout << "2. Operators" << endl;
    cout << "3. Comment Detection" << endl;
    cout << "4. Identifier" << endl;
    cout << "5. Average of Array" << endl;
    cout << "6. Minimum and Maximum" << endl;
    cout << "7. Concatenate Names" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter input: ";
        cin >> input;
        if (isNumericConstant(input))
            cout << "Numeric Constant" << endl;
        else
            cout << "Not Numeric" << endl;
    }
    else if (choice == 2) {
        cout << "Enter expression: ";
        cin >> input;
        findOperators(input);
    }
    else if (choice == 3) {
        cin.ignore(10000, '\n');
        cout << "Enter comment: ";
        cin.getline(input, 500);

        int r = isComment(input);
        if (r == 1)
            cout << "Single-line comment" << endl;
        else if (r == 2)
            cout << "Multiline comment or its beginning" << endl;
        else
            cout << "Not a comment" << endl;
    }
    else if (choice == 4) {
        cout << "Enter identifier: ";
        cin >> input;
        if (isIdentifier(input))
            cout << "Valid Identifier" << endl;
        else
            cout << "Invalid Identifier" << endl;
    }
    else if (choice == 5) {
        cout << "Enter number of elements: ";
        cin >> n;
        if (n <= 0 || n > 100) {
            cout << "Invalid array size" << endl;
        }
        else {
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Average = " << findAverage(arr, n) << endl;
        }
    }
    else if (choice == 6) {
        cout << "Enter number of elements: ";
        cin >> n;
        if (n <= 0 || n > 100) {
            cout << "Invalid array size" << endl;
        }
        else {
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Minimum = " << findMin(arr, n) << endl;
            cout << "Maximum = " << findMax(arr, n) << endl;
        }
    }
    else if (choice == 7) {
        cout << "Enter first name: ";
        cin >> firstName;
        cout << "Enter last name: ";
        cin >> lastName;
        concatenate(firstName, lastName, fullName);
        cout << "Full name = " << fullName << endl;
    }
    else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
