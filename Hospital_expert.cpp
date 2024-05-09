#include <iostream>
#include <string>
using namespace std;

// Define the rules
string rule1(string symptoms[], int size) {
    for (int i = 0; i < size; ++i) {
        if (symptoms[i] == "fever") {
            for (int j = 0; j < size; ++j) {
                if (symptoms[j] == "cough") {
                    for (int k = 0; k < size; ++k) {
                        if (symptoms[k] == "fatigue") {
                            return "You may have the flu.";
                        }
                    }
                }
            }
        }
    }
    return "";
}

string rule2(string symptoms[], int size) {
    for (int i = 0; i < size; ++i) {
        if (symptoms[i] == "fever") {
            for (int j = 0; j < size; ++j) {
                if (symptoms[j] == "rash") {
                    for (int k = 0; k < size; ++k) {
                        if (symptoms[k] == "headache") {
                            return "You may have meningitis.";
                        }
                    }
                }
            }
        }
    }
    return "";
}

string rule3(string symptoms[], int size) {
    for (int i = 0; i < size; ++i) {
        if (symptoms[i] == "pain") {
            for (int j = 0; j < size; ++j) {
                if (symptoms[j] == "swelling") {
                    for (int k = 0; k < size; ++k) {
                        if (symptoms[k] == "bruising") {
                            return "You may have a fracture.";
                        }
                    }
                }
            }
        }
    }
    return "";
}

string rule4(string symptoms[], int size) {
    for (int i = 0; i < size; ++i) {
        if (symptoms[i] == "abdominal pain") {
            for (int j = 0; j < size; ++j) {
                if (symptoms[j] == "diarrhea") {
                    for (int k = 0; k < size; ++k) {
                        if (symptoms[k] == "nausea") {
                            return "You may have food poisoning.";
                        }
                    }
                }
            }
        }
    }
    return "";
}

string rule5(string symptoms[], int size) {
    for (int i = 0; i < size; ++i) {
        if (symptoms[i] == "shortness of breath") {
            for (int j = 0; j < size; ++j) {
                if (symptoms[j] == "chest pain") {
                    for (int k = 0; k < size; ++k) {
                        if (symptoms[k] == "dizziness") {
                            return "You may be having a heart attack. Please seek medical attention immediately.";
                        }
                    }
                }
            }
        }
    }
    return "";
}

// Define the expert system
string diagnose(string symptoms[], int size) {
    string result;
    if (!(result = rule1(symptoms, size)).empty())
        return result;
    if (!(result = rule2(symptoms, size)).empty())
        return result;
    if (!(result = rule3(symptoms, size)).empty())
        return result;
    if (!(result = rule4(symptoms, size)).empty())
        return result;
    if (!(result = rule5(symptoms, size)).empty())
        return result;
    return "Sorry, we could not diagnose your condition.";
}

// Test the expert system
int main() {
    const int MAX_SYMPTOMS = 10;
    string symptoms[MAX_SYMPTOMS];
    int size;

    cout << "Enter the number of symptoms: ";
    cin >> size;

    if (size > MAX_SYMPTOMS || size <= 0) {
        cout << "Invalid number of symptoms." << endl;
        return 1;
    }

    cout << "Enter the symptoms:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Symptom " << i + 1 << ": ";
        cin >> symptoms[i];
    }

    string result = diagnose(symptoms, size);
    cout << result << endl;

    return 0;
}
