#include <iostream>
#include <string>
using namespace std;

class Zorb {
public:
    Zorb(int p, int t) : _power(p), _team_id(t)
     {}

    virtual bool operator< (const Zorb& z) 
    const {
        if (this->_team_id == z._team_id)
            return false;
        return this->_power < z._power;
    }

    virtual Zorb operator+ (const Zorb& z) 
    const {
        return Zorb(this->_power + z._power,
                    ((*this < z) ? z._team_id : this->_team_id));
    }

    virtual int getPower() 
    const { 
        return _power; 
        }
    virtual int getTeamID() 
    const { 
        return _team_id; 
        }

    friend ostream& operator<< (ostream& out, const Zorb& z)
     {
        out << "Zorb(Power: " << z._power << ", Team: " << z._team_id << ")";
        return out;
    }

protected:
    int _power;
    int _team_id;
};

class KiloZorb : public Zorb 
{
public:
    KiloZorb(int p, int t) : Zorb(p * 1000, t) {}

    bool operator< (const Zorb& z)
     const {
        return Zorb::operator<(z);
    }

    KiloZorb operator+ (const KiloZorb& z) 
    const {
        Zorb baseSum = Zorb::operator+(z);
        return KiloZorb(baseSum.getPower() / 1000, baseSum.getTeamID());
    }

    friend ostream& operator<< (ostream& out, const KiloZorb& kz)
     {
        out << "KiloZorb(Power: " << kz.getPower() << ", Team: " << kz.getTeamID() << ")";
        return out;
    }
};

int main(int argc, char* argv[])
 {
 Zorb scout(80, 1);
    Zorb warrior(200, 2);

    KiloZorb mega1(5, 1);   // 5000 power
    KiloZorb mega2(3, 2);   // 3000 power

    cout << "Scout Zorb: " << scout << endl;
    cout << "Warrior Zorb: " << warrior << endl;
    cout << "Mega Zorb 1: " << mega1 << endl;
    cout << "Mega Zorb 2: " << mega2 << endl;

    // Compare different KiloZorbs
    if (mega2 < mega1)
        cout << "Mega Zorb 1 is stronger (different teams, higher power)." << endl;
    else
        cout << "Mega Zorb 2 is not weaker than Mega Zorb 1." << endl;

    Zorb alliance = scout + warrior;
    cout << "Scout + Warrior = " << alliance << endl;

    KiloZorb fusion = mega1 + mega2;
    cout << "Mega Zorb 1 + Mega Zorb 2 = " << fusion << endl;

    return 0;
}
