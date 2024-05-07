all: main.class atm.class checking.class saving.class

clean:
	rm -f *.class
	rm -f *.txt
	rm -f *.jar

main.class: main.java atm.java checking.java saving.java
	javac -g main.java atm.java checking.java saving.java

atm.class: atm.java checking.class saving.class
	javac -g atm.java

checking.class: checking.java
	javac -g checking.java

saving.class: saving.java
	javac -g saving.java

run: main.class atm.class checking.class saving.class
	java main

debug:javac -g main.java atm.java checking.java saving.java
	jdb -classpath . main

