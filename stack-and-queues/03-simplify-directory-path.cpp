string Solution::simplifyPath(string s){

    stringstream ss(s);
    string word;
    vector<string> paths;

    while(getline(ss, word, '/')){

        if(word == "." or word == "") continue;

        else if(word == ".."){
            if(paths.size() > 0) paths.pop_back();
        }
        else{
            paths.push_back(word);
        }
    }

    if(paths.size() == 0) return "/";

    string directoryPath = "";
    for(auto path : paths){
        directoryPath += "/" + path;
    }

    return directoryPath;
}