vm : m_vm.o m_cstate.o m_err.o m_ioops.o m_stackops.o mvm_parse.o util.o
	g++ m_vm.o m_cstate.o m_err.o m_ioops.o m_stackops.o mvm_parse.o util.o -o vm



m_vm.o m_cstate.o m_err.o m_ioops.o m_stackops.o util.o : m_vm.cpp m_cstate.cpp m_err.cpp m_ioops.cpp mvm_parse.cpp util.cpp m_stackops.cpp
	g++ -c m_vm.cpp m_cstate.cpp m_err.cpp m_ioops.cpp mvm_parse.cpp util.cpp m_stackops.cpp


cleanwin :
	cd %~dp0
	del m_vm.o
	del m_cstate.o
	del m_err.o
	del m_ioops.o
	del m_stackops.o
	del util.o
	del mvm_parse.o


cleanlinux :
	rm m_vm.o 
	rm m_cstate.o
	rm m_err.o
	rm m_ioops.o
	rm m_stackops.o
	rm util.o
	rm mvm_parse.o
