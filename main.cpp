//
//  main.cpp
//  receipt
//
//  Created by 신기열 on 19/07/2019.
//  Copyright © 2019 신기열. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {

    string str_buf;
    fstream fs;
    ofstream output("output.txt");
    
    fs.open("/Users/singiyeol/Desktop/베다니/receiptMOD/test.txt", ios::in);
    
    int i = 0;
    bool Isword = false;
    vector<string> temp(5);
    
    while(!fs.eof()){
        
        getline(fs,str_buf,'\n');
        cout << str_buf << '\n';
        
        str_buf.erase(std::remove(str_buf.begin(), str_buf.end(), ' '), str_buf.end());
 
        if(str_buf.find("베다니기") != string::npos){
            temp[0] = str_buf;
            i++;
        }
        
        if(str_buf.find("1.기부자") != string::npos){
            
            getline(fs,str_buf,'\n');
            str_buf.erase(std::remove(str_buf.begin(), str_buf.end(), ' '), str_buf.end());
            
            string temp1= str_buf;
            
            getline(fs,str_buf,'\n');
            str_buf.erase(std::remove(str_buf.begin(), str_buf.end(), ' '), str_buf.end());
            
            string temp2 = str_buf;
            
            getline(fs,str_buf,'\n');
            str_buf.erase(std::remove(str_buf.begin(), str_buf.end(), ' '), str_buf.end());
            
            string temp3 = str_buf;
            
            temp[1] = temp1 + temp2 + temp3;
            i++;
        }
        
        if(str_buf.find("지정기부금") != string::npos && Isword == false){
            temp[2] = "지정기부금";
            Isword = true;
            i++;
        }
        
        if((str_buf.find("합계") != string::npos)){
            temp[3] = str_buf;
            i++;
        }
        else if((str_buf[0] - 48 >= 1 && str_buf[0] - 48 <= 9) && (str_buf.find(',') != string::npos) && (str_buf.find("원") != string::npos)){
            if(str_buf.find("년") == string::npos && str_buf.find("월") == string::npos && str_buf.find("일") == string::npos){
                temp[3] = str_buf;
                i++;
            }
        }
        
        if(str_buf[0] - 48 == 2){
            if((str_buf.find("년") != string::npos)){
                if(str_buf.find("월") != string::npos){
                    if(str_buf.find("일") != string::npos){
                        if(str_buf.find("지정기부금") == string::npos && str_buf.find(",") == string::npos){
                            temp[4] = str_buf;
                            i++;
                        }
                    }
                }
           }
        }
        
        
        
        if(i == 5){
            for(int j = 0; j < 5; j++){
                if(j <= 3) output << temp[j] << ", ";
                else if(j == 4) output << temp[j] << '\n';
            }
            //temp.clear();
            i = 0; Isword = false;
            while(str_buf.find("일련번호") == string::npos && !fs.eof()){
                getline(fs,str_buf,'\n');
            }
        }
    }
    
    output.close();
    fs.close();
    
    return 0;
}
