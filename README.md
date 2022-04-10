# cppProject

## Sovelluksen toiminnat

Sovelluksessa opettajat pääsevät luomaan kursseja ja poistamaan niitä. Sovelluksessa myös opiskelijat pääsevät liittymän kursseille.<br><br>
Ensin opettajan on kirjautuva sisään sovellukseen. </br></br>
Kun opettaja luo kurssin, niin sovellus luo tiedoston kurssin nimellä ja lisää opettajan tiedot tiedostoon. Se myös lisää kurssin nimen courses.txt tiedostoon.</br></br>
Kun opettaja poistaa kurssin, niin sovellus poistaa kurssin tiedoston ja poistaa nimen courses.txt tiedostosta. </br></br>
Kun opiskelija haluaa liittyä kurssiin, hän antaa ensin tietonsa. Sen jälkeen hän valitsee kurssin, johon hän haluaa liittyä, 
jolloin sovellus lisää opiskelijan tiedot kurssin tiedostoon. </br>
Tämän jälkeen opettaja voi hakea kurssin nimellä varustetun tekstitiedoston, jossa on kaikki kursille osallistujat. Ylimpänä on kurssin opettaja.

## Sovelluksen käyttö

### Opettajan ohjeet

![image](https://user-images.githubusercontent.com/79226961/162613820-27864b26-dfcb-45a6-9000-5b897c63149e.png)

Valikossa eteneminen onnistuu valitsemalla numeron,joka on otsikon vieressä.

![image](https://user-images.githubusercontent.com/79226961/162614475-74c7ebd4-db1c-42bc-a1a6-d8568670e0c7.png)

Opettajan puolelle kirjautuminen onnistuu käyttäjänimellä teacher1 ja salasanalla test tai opettaja2 ja salasanalla salasana123.<br>
Uuden opettajan saa lisättyä sen teachers.txt tiedostoon muodossa etunimi,sukunimi,käyttäjänimi,salasana.

![image](https://user-images.githubusercontent.com/79226961/162615446-579f7ccd-a4c4-4bd5-8cd5-038372296c59.png)

Kun luo uuden kurssin, niin sovellus kertoo tiedostopolun, mistä kurssin tiedosto löytyy.<br>
Jos koittaa luoda saman nimistä kurssia, niin sovellus ei anna luoda sitä.

![image](https://user-images.githubusercontent.com/79226961/162616051-c99f4deb-3868-4a7f-8922-3a3486fff9fe.png)

Kurssia poistaessa valitse kurssin numero, jonka haluat poistaa.

### Opiskelijan ohjeet

![image](https://user-images.githubusercontent.com/79226961/162616248-01ab26cc-cc5e-43b0-b775-f14aca62e0d0.png)

Kurssille liittyessä anneetaan ensin omat tiedot ja sen jälkeen valitsemalla kurssi.<br>
Samalle kurssille ei saa liityttyä kahta kertaa tai samalla opiskelijanumerolla.
