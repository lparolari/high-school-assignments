#include <iostream>

using namespace std;

string cifra(int numero) {
    if (numero == 1) return "uno";
    if (numero == 2) return "due";
    if (numero == 3) return "tre";
    if (numero == 4) return "quattro";
    if (numero == 5) return "cinque";
    if (numero == 6) return "sei";
    if (numero == 7) return "sette";
    if (numero == 8) return "otto";
    if (numero == 9) return "nove";

    return "";
}

string teen(int numero) {
    if (numero == 10) return "dieci";
    if (numero == 11) return "undici";
    if (numero == 12) return "dodici";
    if (numero == 13) return "tredici";
    if (numero == 14) return "quattordici";
    if (numero == 15) return "quindici";
    if (numero == 16) return "sedici";
    if (numero == 17) return "diciassette";
    if (numero == 18) return "diciotto";
    if (numero == 19) return "diciannove";

    return "";
}

string decina(int numero) {
    if (numero >= 90) return "novanta";
    if (numero >= 80) return "ottanta";
    if (numero >= 70) return "settanta";
    if (numero >= 60) return "sessanta";
    if (numero >= 50) return "cinquanta";
    if (numero >= 40) return "quaranta";
    if (numero >= 30) return "trenta";
    if (numero >= 20) return "venti";

    return "";
}

string converti(int numero) {
    if (numero < 10) {
        return cifra(numero);
    }

    else if (numero < 20) {
        return teen(numero);
    }

    else if (numero < 100) {
        return decina(numero) + ((numero % 10 != 0) ? converti(numero % 10) : "");
    }

    else if (numero < 1000) {
        string centinaia = converti(numero / 100);
        if (centinaia == "uno") centinaia = "";
        centinaia += "cento";
        return centinaia + ((numero % 100 != 0) ? converti(numero % 100) : "");
    }

    else if (numero < 1000000) {
        string migliaia = converti(numero / 1000);
        if (migliaia == "uno")
            migliaia = "mille";
        else
            migliaia += "mila";
        return migliaia + ((numero % 1000 != 0) ? converti(numero % 1000) : "");
    }

    else if (numero < 1000000000) {
        string milioni = converti(numero / 1000000);
        if (milioni == "uno")
            milioni = "un milione ";
        else
            milioni += " milioni ";
        return milioni + ((numero % 1000000 != 0) ? converti(numero % 1000000) : "");
    }

    else if (numero < 1000000000000) {
        string miliardi = converti(numero / 1000000000);
        if (miliardi == "uno")
            miliardi = "un miliardo ";
        else
            miliardi += " miliardi";
        return miliardi + ((numero % 1000000000 != 0) ? converti(numero % 1000000000) : "");
    }

    return "error";
}

int main() {
    cout << converti(1) << endl;
    cout << converti(4) << endl;
    cout << converti(16) << endl;
    cout << converti(27) << endl;
    cout << converti(180) << endl;
    cout << converti(258) << endl;
    cout << converti(1112) << endl;
    cout << converti(78966) << endl;
    cout << converti(852177) << endl;
    cout << converti(1555000) << endl;
    cout << converti(10555000) << endl;
    cout << converti(105550009) << endl;
    cout << converti(1055500090) << endl;
}

// else if (numero < 1000000000000) {
//         return nameFornumero(numero / 1000000000) + " billion" + ((numero % 1000000000 != 0) ? " " + nameFornumero(numero % 1000000000) : "");
//     }
