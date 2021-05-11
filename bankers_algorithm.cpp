#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>

using namespace std;

int main(int argc, char* argv[]){
    ifstream infile; 
    infile.open(argv[1]);
    int resources_types,no_processes;
    infile >> resources_types;
    infile >> no_processes;
    int instances[resources_types];
    string process_id[no_processes];
    vector<string> safe_sequence;
    int allocated[no_processes][resources_types];
    int maximum[no_processes][resources_types];
    int need[no_processes][resources_types];
    int flag = 1;
    int checked =0;
    int done[no_processes]= {0};
    fill_n(done, no_processes, 0);
    int temp[no_processes] ={0};
    fill_n(temp, no_processes, 0);
    int work[resources_types];
    
    cout<<"Banker's Algorithm - Safety Algorithm"<<"\n";
    cout<<"Programmed by: Greg Norman C. Millora"<<"\n";
    cout<<"\n";
    cout<<"Reading data file...";
    for(int ctr=0;ctr<resources_types;ctr++){
        int data;
        infile >> data;
        instances[ctr] = data;
    }
    for(int ctr=0; ctr<no_processes;ctr++){
        string data;
        infile >> data;
        process_id[ctr] = data;
        for(int ctr2=0;ctr2<resources_types;ctr2++){
            int instance;
            infile>> instance;
            allocated[ctr][ctr2] = instance;
        }
        for(int ctr2=0;ctr2<resources_types;ctr2++){
            int max_instance;
            infile>> max_instance;
            maximum[ctr][ctr2] = max_instance;

        }
    }
        infile.close();
    cout<<"done..."<<"\n";

     //---------------------------------------------------------------------------------------------//
    for(int ctr=0;ctr<resources_types;ctr++){
        int sum = 0;
        for(int ctr2=0;ctr2<no_processes;ctr2++){
            sum+= allocated[ctr2][ctr];
        }
        work[ctr] = instances[ctr]-sum;
    }
    
    for(int ctr=0;ctr<no_processes;ctr++){
        for(int ctr2=0;ctr2<resources_types;ctr2++){
            need[ctr][ctr2] = maximum[ctr][ctr2] - allocated[ctr][ctr2];
          
        }
    }

    //---------------------------------------------------------------------------------------------//
    cout<<"There are "<<resources_types<<" resources with the following number of instances:"<<"\n";
    for(int ctr=0;ctr<resources_types;ctr++){
        cout<<"Resource "<<ctr+1<<"(R"<<ctr+1<<") = "<<instances[ctr]<<" instances"<<"\n";
    }
    cout<<"\n"<<"Allocated Resources for the "<<no_processes<<" processes: "<<"\n";
    cout<<"Process\tR1\tR2\tR3\n";
    for(int ctr=0;ctr<no_processes;ctr++){
        cout<<process_id[ctr]<<"\t";
        for(int ctr2=0;ctr2<resources_types;ctr2++) cout<<allocated[ctr][ctr2]<<"\t";
        cout<<"\n";
    }
    cout<<"\n"<<"Maximum Resources for the "<<no_processes<<" processes: "<<"\n";
    cout<<"Process\tR1\tR2\tR3\n";
    for(int ctr=0;ctr<no_processes;ctr++){
        cout<<process_id[ctr]<<"\t";
        for(int ctr2=0;ctr2<resources_types;ctr2++) cout<<maximum[ctr][ctr2]<<"\t";
        cout<<"\n";
    }

    cout<<"\n"<<"Need matrix for the "<<no_processes<<" processes: "<<"\n";
    cout<<"Process\tR1\tR2\tR3\n";
    for(int ctr=0;ctr<no_processes;ctr++){
        cout<<process_id[ctr]<<"\t";
        for(int ctr2=0;ctr2<resources_types;ctr2++) cout<< need[ctr][ctr2]<<"\t";
        cout<<"\n";
    }

    cout<<"\n"<<"Available instances for each resource type: (";
    
    for(int ctr=0;ctr<resources_types;ctr++){
        if(ctr+1==resources_types) cout<<"R"<<ctr+1;
        else cout<<"R"<<ctr+1<<",";
    }
    cout<<") = (";
    for(int ctr=0;ctr<resources_types;ctr++){
        if(ctr+1==resources_types) cout<<work[ctr];
        else cout<<work[ctr]<<",";
    }
    cout<<")"<<"\n";
    //---------------------------------------------------------------------------------------------//
   cout<<"Running the Safety Algorithm...\n\n";
   do{
        for(int ctr=0;ctr<no_processes;ctr++){
            temp[ctr] = done[ctr];
            if(done[ctr]==0){
                bool start=true;
                for(int ctr2=0;ctr2<resources_types;ctr2++){
                    if(need[ctr][ctr2] > work[ctr2]) {
                        start=false;
                        break;
                    }
                }
                if(start){
                    cout<<process_id[ctr]<<" is given the resources..."<<"\n";
                    cout<<"Available is (";
                    for(int ctr2=0;ctr2<resources_types;ctr2++){
                        if(ctr2+1==resources_types) cout<<work[ctr2];
                        else cout<<work[ctr2]<<",";
                    }
                    cout<<") - (";
                    for(int ctr2=0;ctr2<resources_types;ctr2++){
                        if(ctr2+1==resources_types) cout<<need[ctr][ctr2];
                        else cout<<need[ctr][ctr2]<<",";
                        work[ctr2] -= need[ctr][ctr2];
                    }
                    cout<<") = ";
                    cout<<"(";
                    for(int ctr2=0;ctr2<resources_types;ctr2++){
                        if(ctr2+1==resources_types) cout<<work[ctr2];
                        else cout<<work[ctr2]<<",";
                    }
                    cout<<")\n";
                    cout<<process_id[ctr]<<" is done with the resources..."<<"\n";
                    cout<<"Available is (";
                    for(int ctr2=0;ctr2<resources_types;ctr2++){
                        if(ctr2+1==resources_types) cout<<work[ctr2];
                        else cout<<work[ctr2]<<",";
                    }
                    cout<<") + (";
                    for(int ctr2=0;ctr2<resources_types;ctr2++){
                        if(ctr2+1==resources_types) cout<<maximum[ctr][ctr2];
                        else cout<<maximum[ctr][ctr2]<<",";
                        work[ctr2] += maximum[ctr][ctr2];
                    }
                    cout<<") = ";
                    cout<<"(";
                    for(int ctr2=0;ctr2<resources_types;ctr2++){
                        if(ctr2+1==resources_types) cout<<work[ctr2];
                        else cout<<work[ctr2]<<",";
                    }
                    cout<<")\n";
                    cout<<"\n";
                    done[ctr] = 1;
                    safe_sequence.push_back(process_id[ctr]);
                    cout<<"Current Safe Sequence is <";
                    for(int ctr=0;ctr<safe_sequence.size();ctr++){
                        if(ctr+1 == safe_sequence.size())  cout<<safe_sequence[ctr];
                        else cout<<safe_sequence[ctr]<<",";
                    }
                    cout<<">\n\n";
                }
            }
     
        }
        for(int ctr2=0;ctr2<no_processes;ctr2++){
            if(temp[ctr2]!=done[ctr2]){
                flag = 1;
                break;
            }
            else{
                flag = 0;
            }
        }
    }while(flag);
    
    for(int ctr=0;ctr<no_processes;ctr++){
        if(done[ctr]==0){
            checked=0;
            break;
        }
        checked = 1;
    }
    if(!checked){
      cout<< "The system is unsafe.";
    }


    return 0;
        
}