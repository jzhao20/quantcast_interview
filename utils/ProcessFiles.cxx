#include<bits/stdc++.h>
#include "ProcessFiles.hpp"

using namespace std;

unordered_map<string,unordered_map<string,int>> ProcessFiles::process_input(vector<pair<string,string>> &input){
    unordered_map<string,unordered_map<string,int>>ret;
    for(const auto a:input){
        string date,cookie;
        tie(date,cookie)=a;
        if(ret.find(date)==ret.end()){
            //create a new map
            unordered_map<string,int>append;
            append[cookie]=1;
            ret[date]=append;
        }
        else{
            //c++ will handle most of this
            ret[date][cookie]++;
        }
    }
    return ret;
}

unordered_map<string,multimap<int,string,greater<int>>> ProcessFiles::convert_to_multimap(){
    unordered_map<string,multimap<int,string,greater<int>>>ret;
    unordered_map<string,unordered_map<string,int>>input=this->original_input;
    for(const auto &iterator:input){
        string key=iterator.first;

        multimap<int,string,greater<int>>append;
        for(const auto &pairs:iterator.second){
            append.insert(make_pair(pairs.second,pairs.first));
        }
        ret[key]=append;
    }
    return ret;
}
string ProcessFiles::extract_date(string line){
    size_t index=line.find("T");
    return line.substr(0,index);
}

void ProcessFiles::read_file(){
    string filename=this->file_name;
    ifstream file(filename);
    try{
        if(!file.is_open())throw runtime_error("Could not open file");
    }
    catch(const runtime_error& error){
        cout<<error.what()<<"\n";
    }
    //extract the first line
    string line,column;
    getline(file,line);
    stringstream ss(line);

    while(getline(ss,column,',')){
        continue;
    } 
    //read in the stuff
    //the key is going to be the date and this will point to another map which is number of occurrences 
    string val;
    vector<pair<string,string>>input; 
    while(getline(file,line)){
        stringstream ss(line);
        int index=0;
        string cookie,date;
        while(getline(ss,val,',')){
            //find the value
            if(index==0){
                //this means it's a cookie
                cookie=val;
            }
            else{
                date=extract_date(val);
            }
            index++; 
        }
        input.push_back(make_pair(date,cookie));
    }
    //flip it around so that it stores the value for keys so that it's sorted multimap since we can have ties
    this->original_input=process_input(input);
    this->cached_csv=convert_to_multimap();
}

ProcessFiles::ProcessFiles(string file){
    this->file_name=file;
    this->read_file();
}

vector<string> ProcessFiles::get_most_active(string date){
    vector<string>ret;
    unordered_map<string,multimap<int,string,greater<int>>>cached=this->cached_csv;
    multimap<int,string,greater<int>>cookies_of_interest=cached[date];
    int max_val=-1;
    for(const auto &iterator:cookies_of_interest){
        if(max_val==-1){
            max_val=iterator.first;
        }
        if(iterator.first==max_val){
            ret.push_back(iterator.second);
        }
    } 
    return ret;
}