namespace isbadrun_nm{
  std::set<int> badruns;
  int lastrun=-1;
  bool lastresult=true;
  bool firstrun=true;
}

bool isbadrun(int run){

  using namespace::isbadrun_nm;

  if(firstrun){
    ifstream in("badruns.dat");
    int irun;
    std::string str;
    while(in>>irun){
      if(irun>0) badruns.insert(irun);
      getline(in,str);
    }
    std::cout<<"Loaded list of "<<badruns.size()<<" bad runs"<<std::endl;
    firstrun=false;
  }
  if(run==lastrun) return lastresult;
  lastrun=run;
  lastresult=false;
  if(badruns.find(run)!=badruns.end()) lastresult=true;

  return lastresult;
}
