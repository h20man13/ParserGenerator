all:
	clang -I. -o ParserGen *.c
clean:
	rm -rf *~ *# ParserGen
