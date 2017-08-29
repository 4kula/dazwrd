using namespace BWAPI;

// Houses all of the reuseable functions this bot will need
class TemplarArchives {
    // simple communication black box
    public static void _p(string raw) {
        Broodwar->sendText(raw);
    }
}
