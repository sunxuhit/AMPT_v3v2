#include <TSystem>

// root4star -b -q Resolution.C\(1,1,0,0,1,1024\)
void Resolution(const Int_t Energy = 1, const Int_t Mode = 1, const Int_t Screen = 0, const Int_t List = 0, const Long64_t StartEvent = 1000, const Long64_t StopEvent = 10024) // Energy = 0: 7GeV, 1: 11GeV, 2: 19GeV, 3: 27GeV, 4: 39GeV, 5: 62GeV, 6: 200 GeV | Mode = 0: Default, 1: String Melting | Screen = 0: 1.5mb, 1: 3mb, 2: 6mb
{
  gSystem->Load("AMPT_resolution");

  cout << "All libraries are loaded!!!!" << endl;
  cout << "Start to Calculate Resolution!!" << endl;

  AMPT_resolution *mRes = new AMPT_resolution(Energy,Mode,Screen,List,StartEvent,StopEvent);
  mRes->Init();
  mRes->Make();
  mRes->Finish();
  delete mRes;

  cout << "End of the Calculation!!" << endl;
}
