.cc.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)
link:
	$(CXX) $(TARGETS) -o $(OUTPUT) $(LDFLAGS)
