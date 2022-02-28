Vi oppdaget et problem med scanf når vi hadde et whitespace som input. Dette var helt unikt for oss og vi rakk ikke å finne ut av problemet før leveringsfristen. Vi bestemte oss dermed for å ha input av tid i to ulike segment (vi synes i tillegg at dette er en mer ryddig måte siden det blir mer oversiktlig for brukeren. Det blir derimot litt mer rotete kode).

I tillegg valgte vi å gå for time_t sin egen formatering av tid siden vi synes den er mer oversiktlig enn den som er presentert i oppgaven.

//TODO:
- fikse cancel alarm så den sletter alarm på parent
