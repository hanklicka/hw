#FAQ K Domácímu úkolu

### Jak to spustit?

`./jmenoBinarky`

### Ani tak mi to nejde spustit.

Na FreeBSD 11.0-RELEASE to spustit jde.

### Kompilátor vyhazuje chyby

clang na FreeBSD 11.0-RELEASE chyby nevyhazuje.

### Proč je program nespisovný a tak hrubý?

Protože UX nebylo součástí zadání.

### Jak to tedy zkusit?

Pro vlastní testy nainstalujte FreeBSD 11.0-RELEASE a použijte následující příkazy,

+ pro získání lokální kopie:

`pkg install git`

`git clone https://github.com/hanklicka/hw`

`cd hw`

+ pro kompilaci zdrojovych souboru:

`clang++ obdelnik.cpp -o obdelniktest`

`clang++ dan.cpp -o dantest`

`clang++ teplota.cpp -o teplotatest`

+ pro spuštění originálních binárek:

`./obdelnik`

`./dan`

`./teplota`

pro spuštění testovacích binárek:

`./obdelniktest`

`./dantest`

`./teplotatest`

### Můžu přispět?

Tohle je domácí úkol a další vývoj se neočekává. 