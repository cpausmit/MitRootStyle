{
  // Loading the MitRootStyle package
  
  printf(" .rootlogon.C: loading MitRootStyle.C\n");
  gSystem->Load("$MIT_ROOT_STYLE/MitRootStyle_C.so");
  gSystem->AddIncludePath("-I$MIT_ROOT_STYLE");
  gInterpreter->AddIncludePath(TString(gSystem->Getenv("MIT_ROOT_STYLE")));
}
