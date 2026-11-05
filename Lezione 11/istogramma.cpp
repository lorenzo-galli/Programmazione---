#include "TH1F.h"
#include "TCanvas.h"


// un altro giorno installerò ROOT e lo compilerò
int main() {
    // nome, titolo, intervalli, minimo, massimo
    TH1F h1("h1", "Pesi iniziali", 100, -3.0, 3.0);
    h1.FillRandom("gaus", 10000);

    // nome, titolo, larghezza e altezza in pixel
    TCanvas c1("c1", "Pesi", 800, 600);
    h1.Draw();
    c1.SaveAs("pesi.pdf");
    return 0;
}