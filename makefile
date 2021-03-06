win :
	g++ -c m_vm.cpp m_cstate.cpp m_err.cpp m_ioops.cpp mvm_parse.cpp util.cpp m_stackops.cpp m_binops.cpp
	g++ m_vm.o m_cstate.o m_err.o m_ioops.o m_stackops.o mvm_parse.o util.o m_binops.o -o vm.exe
	del /f m_vm.o
	del /f m_cstate.o
	del /f m_err.o
	del /f m_ioops.o
	del /f m_stackops.o
	del /f util.o
	del /f mvm_parse.o
	del /f m_binops.o

lin :
	g++ -c m_vm.cpp m_cstate.cpp m_err.cpp m_ioops.cpp mvm_parse.cpp util.cpp m_stackops.cpp m_binops.cpp
	g++ m_vm.o m_cstate.o m_err.o m_ioops.o m_stackops.o mvm_parse.o util.o m_binops.o -o vm
	rm m_vm.o 
	rm m_cstate.o
	rm m_err.o
	rm m_ioops.o
	rm m_stackops.o
	rm util.o
	rm mvm_parse.o
	rm m_binops.o
