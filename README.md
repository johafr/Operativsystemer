Vi oppdaget et problem med scanf når vi hadde et whitespace som input. Dette var helt unikt for oss og vi rakk ikke å finne ut av problemet før leveringsfristen. Vi bestemte oss dermed for å ha input av tid i to ulike segment (vi synes i tillegg at dette er en mer ryddig måte siden det blir mer oversiktlig for brukeren. Det blir derimot litt mer rotete kode).

I tillegg valgte vi å gå for time_t sin egen formatering av tid siden vi synes den er mer oversiktlig enn den som er presentert i oppgaven.

//TODO:
- fikse cancel alarm så den sletter alarm på parent.
- input i actionS() blir igjen fra forrige input.

Tester:
Kjør programmet ved å skrive inn "gcc OSoving1.c" i terminalen. Trykk deretter "enter" og skriv inn "./a.out" og trykk "enter".

1. Opprette og slette en alarm. Sjekke at child forken blir terminert. 
- skriv "s" som input i terminalen. Deretter skriv inn input på formatet: "yyyy-mm-dd" eks. (2022-02-28).
- Skriv deretter inn input til tidspunkt på formatet: "hh:mm:ss" eks. (12:00:00).
- Det vil nå være opprettet en alarm som er lagret i listen alarms. Brukeren vil få opp en melding i terminalen hvor det står dato og tidspunkt på time_t sitt ctime format, i tillegg til at brukeren får oppgitt hvor mange sekunder det er til alarmen går. 
- Hvis brukeren kommer med et tidspunkt som allerede har passert vil brukeren få opp en melding hvor det står "invalid input" og blir bedt om å skrive inn input på nytt. 
- For å teste at child forken blir terminert kan man skrive inn et tidspunkt i nære fremtid og deretter kansellere alarmen, før man venter til etter alarmen sitt tidspunkt. Man vil da oppdage at terminalen ikke vil skrive ut "ring!" eller komme med den satte ringetonen.
- Trykk deretter x i input for å gå ut av programmet.

- Det som blir testet i denne testen er at menyen fortsetter å kjøre helt til x blir satt som input. I tillegg blir opprettelsen av en alarm testet og den støttede funksjonen for å slette en alarm. Man får også testet om fork()-implementasjonen fungerer slik den skal. 
Det blir og testet om exit() funksjonen til fork termineres.

2. Opprette tre alarmer og sjekke at de blir lagt til i listen. Sjekker også at kun aktive alarmer vises. Sletter en alarm og sjekker igjen at den ikke vises i listen.
- Som i testen over skriver man inn verdiene for de tre alarmene med samme format. 
- Deretter gir man menyen input "l" for å få opp list visningen.
- Hvis programmet fungerer skal man få opp 3 ulike alarmer med plasseringen i listen definert ved siden av tidspunktet (formatert i ctime). 
- Etterpå sletter man en alarm ved å skrive inn "c" som input. Man bruker da indexen som kommer opp til venstre for tidspunktet man får opp i "l" inputen.
- Etter man har kansellert skal det komme opp alle gjenverende alarmer, uten den kansellerte.
- Hvis man legger til en alarm igjen skal den komme opp på første ledige index. Dermed kan man være sikker på at den slettede alarmen ikke bare blir skjult, men også blir nullstilt.

- Denne testen sikrer at alarmene blir lagret på riktig vis og at brukeren kun får opp de aktive alarmene ved input "l". I tillegg sjekker testen for at slettede alarmer blir nullstilt og skrives over ved et nytt input. Man sjekker i tillegg at det er mulig å opprette flere alarmer uten at de påvirker hverandre.

3. Sjekke at det ikke går an å opprette en alarm i fortiden og at programmet fortsetter etter ulovlig input. I tillegg opprett en alarm som ringer i nærmeste fremtid.
- Skriv input "s" som i tidligere oppgaver.
- Skriv deretter inn et tidspunkt fra fortiden. Programmet skal da skrive ut "invalid input, try again" til terminalen og sende brukeren tilbake til startmenyen. 
- Deretter skriver man inn et gyldig tidspunkt i nær fremtid og venter til tidspunktet inntreffer. Programmet skal da skrive ut "ring!" til terminalen eller komme med en ringetone (avhengig av operativsystemet til maskinen).

- Testen sjekker om det er implementert logikk for å ikke opprette en alarm i fortiden, samt om programmet vil kræsje som en konsekvens av dette. I tillegg sjekker den om en gyldig alarm gir riktig output når den settes av. Dette er nødvendig siden brukerfeil fort kan oppstå ved et så strengt format som inputverdiene til oppgaven.

4. Test over at alt fungerer sammen.
- Utfør test 1, 2 og 3 samlet uten å terminere økten.

- Test 4 introduserer ikke noen nye konsepter inn i bildet, men er likevel nødvendig for å sjekke varigheten til programmet. Med kompleks kode kan det hende programmet kjører i spesifikk rekkefølge, men bryter sammen ved gjentagende kjøringer på grunn av bugs eller lignende

- Testen skal gi samme output som tidligere, men med sammenspleisede resultater.