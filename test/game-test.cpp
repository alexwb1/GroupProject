#include "../src/game.h"

using namespace std;

int main () {

    Game game(10000*100, "Bob");
    cout << game.setBrokerage("Ally Invest") << endl;
    cout << game.setAdviser("Theodore Warner") << endl;
    cout << game.buyAsset("MFT", 1) << endl;
    cout << (game.getName() == "Bob") << endl;
    cout << game.buyAsset("MFT", 1) << endl;
    cout << (game.getCapital()) << endl;
    vector<Asset> p = game.getAssets();
    for (int i = 0; i < p.size(); i++) {
        cout << p[i].getTicker() << " - " << p[i].getQuantity() << endl;
    }


    return 0;
}