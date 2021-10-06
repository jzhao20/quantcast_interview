#include<bits/stdc++.h>
#ifndef PROFESSFILES_H
#define PROCESSFILES_H

using namespace std;

class ProcessFiles
{
    private:
        string file_name;
        unordered_map<string,unordered_map<string,int>>original_input;
        unordered_map<string,multimap<int,string,greater<int>>>cached_csv;
        
        unordered_map<string,unordered_map<string,int>> process_input(vector<pair<string,string>> &input);
        string extract_date(string line);
        unordered_map<string,multimap<int,string,greater<int>>>convert_to_multimap();
        void read_file();
    public:
        ProcessFiles(string file);
        vector<string>get_most_active(string date);
};
#endif