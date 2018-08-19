vector<string> split(string str, char tag){
    vector<string> res;
    string tmp = "";
    for (auto c : str){
        if (c != ' ')tmp += c;
        else{
            res.push_back(tmp);
            tmp = "";
        }
    }
    if (tmp != "")res.push_back(tmp);
    return res;
}