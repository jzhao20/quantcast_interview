#include <bits/stdc++.h>
#include <boost/program_options.hpp>
#include "utils/ProcessFiles.hpp"


using namespace std;

int main(int argc, char *argv[]){
    //read in arguments
    namespace po=boost::program_options;
    po::options_description desc("Options must both be set");
    desc.add_options()
    ("help,h", "produces help message")
    ("date,d", po::value<vector<string>>()->multitoken(), "dates to find max")
    ("file,f",po::value<string>(),"file")
    ;
    po::positional_options_description p;
    p.add("file",1);
    
    po::variables_map vm;
    po::store(po::command_line_parser(argc,argv).
        options(desc).positional(p).run(),vm);
    po::notify(vm);
    try{
        if(vm.count("help")){
            cout<<desc<<"\n";
            return 0;
        }
        string file;
        vector<string>dates;
        if(vm.count("file")){
            file=vm["file"].as<string>();
            size_t found=file.find(".csv");
            if(found==string::npos)
                throw "must be csv file";
        }
        if(vm.count("date")){
            dates=vm["date"].as<vector<string>>();                
        }
        ProcessFiles processed_file(file);
        if(dates.size()==1){
            vector<string>result=processed_file.get_most_active(dates[0]);
            for(string cookies:result){
                cout<<cookies<<"\n";
            }
        }
        else{
            for(string date:dates){
                cout<<date<<"\n";
                vector<string>result=processed_file.get_most_active(date);
                for(string cookies:result){
                    cout<<cookies<<"\n";
                }
            }
        }
    }
    catch(string &e){
        cerr<<"error: "<<e<<"\n";
        return 1;
    }
}
