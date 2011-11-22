.cc.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<
link:
	$(CXX) $(LDFLAGS) $(TARGETS) -o $(OUTPUT)
