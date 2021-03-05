@echo off
cd %~dp0
g++ -c m_vm.cpp util.cpp m_err.cpp m_cstate.cpp mvm_parse.cpp m_stackops.cpp
g++ m_vm.o util.o m_err.o m_cstate.o mvm_parse.o m_stackops.o -o vm.exe
del /f m_vm.o util.o m_err.o m_cstate.o mvm_parse.o m_stackops.o
vm
pause
