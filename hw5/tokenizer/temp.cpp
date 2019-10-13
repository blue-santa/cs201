bool ReadLine(vector<string> &input) { 
    getline(cin, input);

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    } else if (!cin || input == "") {
        return false; 
    } else {
        return true; 
    } 
}

unsigned StringToTokenWS(string &input, vector<string> &tokens) {

        istringstream instream(input.at(i));
        int num;
        instream >> num;
        if (!instream) {
            cout << "err" << endl;
        } else {
            cout << num * num << endl;
        }

    size_t tokenSize = tokens.size();

    if (tokens.size() <= sizeof(unsigned)) {
        tokenSize = static_cast<unsigned>(tokenSize);
    }

    return tokenSize; 
}

bool containsEnd(vector<string> &tokens) {

    for (auto token: tokens) {
       string temp = token;
       transform(temp.begin(), temp.end(), temp.begin(), tolower);
       if (temp == "end") {
            return true
       }
    } 
    return false; 
}

void AnalyzeTokens(const vector<string> &tokens) {
    

