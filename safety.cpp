#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>

using namespace std;


int main(int argc, char *argv[]) {
    ifstream useFile;
    int lines = 0;
    int len = 0, row;
    int i, j, tmpCount, proCount = 0, alloCount = 0, maxCount = 0, k, m, n, q, tmpSum;
    string file;
    string text;
    int resource = 0;
    int process;
    string tmp, tmp1, temp, allocTmp;
    bool flagResource = false;
    bool flagStat = false;
    int *resInst;
    int **needMatrix;
    int *work; //Available
    int **max;
    int *finish;
    int **allocation;
    int *available;
    bool checker;
    
    if (argc == 2) {
        file = argv[1];
        useFile.open(file.c_str());
        if (useFile.is_open()) {
            cout << "\nBanker's Algorithm - Safety Algorithm" << endl;
            cout << "Programmed by : Beatrice D. Totanes\n" << endl;
            cout << "Reading data file...done...\n" << endl;
            cout << "The data file is interpreted below: \n" << endl;
            cout << "There are 3 resources with the following number of instances: \n" << endl;
            
            while (getline(useFile, text)) {
                lines++;
                i = 0;
                j = 0;
                
                // Gets no. of resources and processes
                switch (lines) {
                    case 1:
                        for (i = 0; i < text.length(); i++) {
                            j = i;
                            if (flagResource == false) {
                                while (text[j] >= 48 && text[j] <= 57) {
                                    tmp += text[j];
                                    
                                    j++;
                                    i = j;
                                    flagResource = true;
                                }
                            }else{
                                while (text[j] >= 48 && text[j] <= 57) {
                                    tmp1 += text[j];
                                    j++;
                                    i = j;
                                    flagResource = true;
                                }
                            }
                        }
                        
                        istringstream(tmp) >> resource;
                        istringstream(tmp1) >> process;
                        
                        max = (int**)malloc(sizeof(int*)*process);
                        for (i = 0; i < process; i++) {
                            max[i] = (int*)malloc(sizeof(int)*resource);
                        }
                        
                        allocation = (int**)malloc(sizeof(int*)*process);
                        for (i = 0; i < process; i++) {
                            allocation[i] = (int*)malloc(sizeof(int)*resource);
                        }
                        break;
                    case 2:
                        // Gets Resource Instances
                        resInst = (int*)malloc(sizeof(int)*resource);
                        j = 0;
                        i = 0;
                        
                        while (i < resource) {
                            while (text[j] >= 48 && text[j] <= 57) {
                                temp += text[j];
                                if (text[j+1] < 48 || text[j+1] > 57) {
                                    istringstream(temp) >> resInst[i];
                                    temp.clear();
                                    i++;
                                }
                                j++;
                            }
                            
                            if (text[j] == 32) {
                                j++;
                                continue;
                            }
                        }
                        
                        for (i = 0; i < resource; i++) {
                            cout << "Resource " << i + 1 << "(R" << i + 1 << ") = " << resInst[i] << " instances\n";
                        }
                        cout << endl;
                        break;
                    default:
                        i = 0;
                        j = 0;
                        
                        // For allocation
                        while(i < resource) {
                            if (isdigit(text[j]) == 0 && text[j] != ' ') { //Not Digit like 'P' in P0
                                while (text[j] != ' ') {
                                    j++;
                                }
                            }
                           
                            if (text[j] == ' ') {
                                j++;
                            }else{
                                while (isdigit(text[j]) != 0) { //While digit
                                    allocTmp += text[j];
                                    if (isdigit(text[j+1]) == 0) {
                                        istringstream(allocTmp) >> allocation[proCount][i];
                                        allocTmp.clear();
                                        i++;
                                    }
                                    j++;
                                }
                            }
                        }
                        
                        
                        // For max
                        i = 0;
                        allocTmp.clear();
                        while(i < resource) {
                            if (isdigit(text[j]) == 0 && text[j] != ' ') { //Not Digit like 'P' in P0
                                while (text[j] != ' ') {
                                    j++;
                                }
                            }
                            
                            if (text[j] == ' ') {
                                j++;
                            }else{
                                while (isdigit(text[j]) != 0) { //While digit
                                    allocTmp += text[j];
                                    if (isdigit(text[j+1]) == 0) {
                                        istringstream(allocTmp) >> max[proCount][i];
                                        allocTmp.clear();
                                        i++;
                                    }
                                    j++;
                                }
                            }
                        }
                        proCount++;
                        break;
                }
            }
            
            needMatrix = (int**)malloc(sizeof(int*)*process);
            for (i = 0; i < process; i++) {
                needMatrix[i] = (int*)malloc(sizeof(int)*resource);
            }
            
            for (i = 0; i < process; i++) {
                for (j = 0; j < resource; j++) {
                    needMatrix[i][j] = max[i][j] - allocation[i][j];
                }
            }
            
            finish = (int*)malloc(sizeof(int*)*process);
            for (i = 0; i < process; i++) {
                finish[i] = 0;
            }
            
            k = 0;
            work = (int*)malloc(sizeof(int*)*resource);
            for (i = 0; i < resource; i++) {
                tmpSum = 0;
                for (j = 0; j < process; j++) {
                    tmpSum += allocation[j][i];
                }
                work[i] = resInst[i] - tmpSum;
            }
            
            
            // Printing
            cout << "Allocated Resources for the 5 processes: \n" << endl;
            for (i = 0; i < process; i++) {
                cout << "P" << i << "    ";
                for (j = 0; j < resource; j++) {
                    cout << allocation[i][j] << "    ";
                }
                cout << endl;
            }
            
            cout << "\nMaximum Resources for the 5 processes: \n" << endl;
            for (i = 0; i < process; i++) {
                cout << "P" << i << "    ";
                for (j = 0; j < resource; j++) {
                    cout << max[i][j] << "    ";
                }
                cout << endl;
            }
            
            cout << "\nNeed matrix for the 5 processes: \n" << endl;
            for (i = 0; i < process; i++) {
                cout << "P" << i << "    ";
                for (j = 0; j < resource; j++) {
                    cout << needMatrix[i][j] << "    ";
                }
                cout << endl;
            }
            
            cout << "\nAvailable instances for each resource type: ";
            for (i = 0; i < resource; i++) {
                if (i == 0) {
                    cout << "(R" << i + 1 << ",";
                    continue;
                }
                
                if (i == resource - 1) {
                    cout << "R" << i + 1 << ") = ";
                    continue;
                }
                
                cout << "R" << i + 1 << ",";
            }
            
            for (i = 0; i < resource; i++) {
                if (i == 0) {
                    cout << "(" << work[i] << ",";
                    continue;
                }
                
                if (i == resource - 1) {
                    cout << work[i] << ")\n";
                    continue;
                }
                
                cout << work[i] << ",";
            }
            
            // Algorithm
            
            cout << "\nRunning the safety algorithm...\n";
            
            i = 0;
            int safe[process];
            while (i < process) {
                flagStat = false;
                for (m = 0; m < process; m++) {
                    if (finish[m] == 0) {
                        checker = true;
                        for (j = 0; j < resource; j++) {
                            if (needMatrix[m][j] > work[j]) {
                                checker = false;
                                break;
                            }
                        }
                        
                        if (checker == true) {
                            // Printing
                            cout << "\nP" << m << " is given the resources...\n";
                            cout << "Available is ";
                            for (n = 0; n < resource; n++) {
                                if (n == 0) {
                                    cout << "(" << work[n] << ",";
                                    continue;
                                }
                                
                                if (n == resource - 1) {
                                    cout << work[n] << ") - ";
                                    continue;
                                }
                                
                                cout << work[n] << ",";
                            }
                            
                            for (q = 0; q < resource; q++) {
                                if (q == 0) {
                                    cout << "(" << needMatrix[m][q] << ",";
                                    continue;
                                }
                                    
                                if (q == resource - 1) {
                                    cout << needMatrix[m][q] << ") = ";
                                    continue;
                                }
                                cout << needMatrix[m][q] << ",";
                            }
                            
                            // Computing
                            int tmpRes1[resource];
                            for (k = 0; k < resource; k++) {
                                if (k == 0) {
                                    cout << "(" << work[k] - needMatrix[m][k] << ",";
                                }else if(k == resource - 1){
                                    cout << work[k] - needMatrix[m][k] << ")\n";
                                }else cout << work[k] - needMatrix[m][k] << ",";
                                tmpRes1[k] = work[k] - needMatrix[m][k];
                                work[k] = (work[k] - needMatrix[m][k]) + max[m][k];
                            }
                            
                            cout << "P" << m << " is done with the resources...\n";
                            cout << "Available is ";
                            for (n = 0; n < resource; n++) {
                                if (n == 0) {
                                    cout << "(" << tmpRes1[n] << ",";
                                } else if(n == resource - 1){
                                    cout << tmpRes1[n] << ") + ";
                                }else cout << tmpRes1[n] << ",";
                            }
                            
                            for (q = 0; q < resource; q++) {
                                if (q == 0) {
                                    cout << "(" << max[m][q] << ",";
                                    continue;
                                }
                                
                                if (q == resource - 1) {
                                    cout << max[m][q] << ") = ";
                                    continue;
                                }
                                cout << max[m][q] << ",";
                            }
                            
                            for (n = 0; n < resource; n++) {
                                if (n == 0) {
                                    cout << "(" << work[n] << ",";
                                } else if(n == resource - 1){
                                    cout << work[n] << ") \n";
                                }else cout << work[n] << ",";
                            }
                           
                            flagStat = true;
                            safe[i] = m;
                            i++;
                            
                            cout << "\nCurrent safe sequence is: ";
                            for (n = 0; n < i; n++) {
                                if(n == 0 && i == 1) {
                                    cout << "<P" << safe[n] << ">\n";
                                    continue;
                                }
                                if (n == 0) {
                                    cout << "<P" << safe[n] << ",";
                                } else if(n == i - 1){
                                    cout << "P" << safe[n] << "> \n";
                                }else cout << "P" << safe[n] << ",";
                            }
                            finish[m] = 1;
                        }
                    }
                }
                
                if (flagStat == false) {
                    cout << "\nUnsafe sequence\n";
                    break;
                }
            }
            
            useFile.close();
        }else cout << "File does not exist." << endl;
        
        
    }else cout << "Error--no file name." << endl;
    return 0;
}


