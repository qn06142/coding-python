#include<bits/stdc++.h>
using namespace std;
/*
######################################################################-##################################################################
#####################################################################-+++################################################################
##############################################+#####################-++++################################################################
##################################################################-.-++++################################################################
################################+################################-.-++++#################################################################
########################++######+#+###################+++-+###+-...-----#################################################################
##################+++###+#################################++#+....-----##################################################################
##############################+##########++++++##+######+.......-------##+++++#+#########################################################
##########################++++###########################..-....-------+++++########+####################################################
#######++#################+++#####++++##+#################-...--+------......+++++++#####################################################
#######++###+####++++--#+#+++++###++++###+###############+...-+--++++++++++-.....##+#+++#################################################
######+++#+##+###++++++###+++#++##+++++#++++++#########+....--+#---+++#+----#+++#-.-#++######################++##########################
######+++++#++++++++++##+#++++++++++++++++++##########--..-----.-.----++++++++++++++-++#++###############################################
#####+#++++++++++++++++++++--++++++++++###############...---......-+-------+-++++++++#...............+###################################
####++++++++++++--+++-+++++----++++#################+-...-.......-.....++--+--++++++#++............---------#############################
####+++#+++++++++++++-+--+++----++++##############+++..-+......-.....+......+--+++++#+#+......------------+##+###########################
####++++##+-++++++-+++-+--++-----++-############+++-.--............-.......-..---+++++++#--+------------###+##++####++###################
###++++++++-++-+++++-+-----+--------+############+----.......-..-.-.......+.....--++++++-#-----+------+#######+######+###################
###++++++++-+++-----++---------+-++---+##########----........---......-..........-+++++++-+-----+---#++##++#+#######+####################
#+###++++++-++++---+++-++--+---++-----+#########----.........++-..................-++++++-+++--++-##+++#+++++++++++#++###################
#++++++++++---+----+++++++------------+#########+--.......----......-............--+-+++++-++++++###++++++++++++++++++++#################
##+++++++---------+++++-+------+--+---+##++#####--.......--+...-....#............----++++++#-###+###+++++++++++++++++++##################
##-+++++---------+++++++--------++----+##-####+++.........+.......-++..........--.--..+++++#########+++++++++++++#+##+###################
++----------------+++++--------+#---+-+########++.......-..-.....-+-...-.......--.-...--+++########++++##+++++++++++#####################
+#+-----------+----+--+---------+--+##+#######++........-...---.-..-.......-.-----+....--+++#########++--++###++++#######################
++-----------++++-----------------+--##+#-+###-.........-----+-....-..-....---+----.....-+-++##########++++#+++#++#######################
++----++-----+-+---------------------###.---#--.......-.###+#-.----.-.-.-...----.+....-.-+-++##+########++####++#########################
++----+------+-+---------------------+##----#-....---.--#-######---.-..---.----.--.-..--.+-+++##+########+++#+##++####+##################
++---++--------+----------------..---###--#-#-.-..-----.+-#+#####--+------.+--.---.------+--++########+++#++++++-++++++##################
++--++----------+--------------..---+#-#..#----...-------#----+----+-----+.--.----+------+-++#-##+###-+++++++++++-++++###################
--------------++--++-----++----...---#+#...--.+..------------+-------+---+.-.###-##-+..--#+-+#####+#+++++++++##+++++#+#############...###
--+---.--+---+-------------+--..---#++##-++.--+-.-------------------------+.###+#++#-..-##+---####++#-++++++##+++++#-.#######..##-..+####
------.----------.------+----....-+++-#+-+...-----.---+------------------+-++#++-###+.+-+++---##+#####-#+++++++++...-###+####.--..-######
------.---.--..-...---------....----++#++....-.-.-.-.----+----------..------++--##+----++--+--###+##+#########....--##.-..###.-.-+#######
---------------.-.---------....-.-++++--+..-..+---.----.-------------------------##--+-+++---.++############--.---####-.--.#.-+-#########
----------.----------------....---+++------....+--.-...+------------------------##----++++--#-+############-..-----####-.-..-++##########
-------------------.------....-.-+-++---..+-...-+-----.-.--------+------------####+--+++++---#+++##+######-...------.--#.---+############
-----------.---------.---..-.---------+--.-+--..+---.--.-+--------------------++#.--++++++--.+++####+####............-..---+#############
---------------+---+.---..-.-----++---------++++---------++---------------#--+++.-.-++++-----+++++###++##...........-..-+#+##############
----------+-+-+-++++.--.....-.---+-------+----++-+-------+-++-------++-------+++++++-++++----#+++#####++--....---------+#+++#############
----------+----------......--------------+----++--------+-##+++##+#####------++++++++--------#++##+###--+-..------+++#####++#############
++-+++----+--------....-..--------+------------+--------#####++#######-.------++++++---+------+###+++++++------+++++#--+#################
++-+++--+++--.---.....-.-----+-----------------------+-+-#####+######-------+++++++--+-+------+++++-++#+-------####+++#+#################
---++-++++--+---....-.---------++--------------------#.-###############-----+---+--++--.------+++++++--#+----++#######++###+#############
+-++++++-++++-....--.-.----+--++------------------#-###---################--+----------.-------++++------+-++++#######+++#+++############
+++++--++++--....--.-----+---+-----..-----------##--####+#--###############-+#+---+------------++++-+----+###-+#######+#++++#############
+++++++---+....-------------+-------...-----+--##--#######################-++++-----------------+++.-+--++###########+-#++++++++#########
+++-+++--....-----------+--++----------------+-#+-+########+-+-#++######-#+++-+--.+---+++-------+++.---++############++-++-+++++#########
---++--....--------+-------+---....-----+----+#---#####-#+#++####++######++++--.-++---+++++-----+++.--+--###########+++++##-++++####+##++
------....----------------++--...------+-+----##--+#-.--+++##++++##+####+--+--++--+---+-+--+-----+-.--++##############++++++++++##++#####
-++-....-----------------++---..-------+-+-----#+#..---++---++++++++++##++---------+-+-----++-----..--+-######+###+#++++#++++####+++##+++
++....------------------+++-----.-----++++--+----..-----+------++++++++#+++---------+--++++++#+-++.-----+##+###+++++++++++++++++++#######
-....--------+----------++------------+--+..-------.--------.---++--+++++#+------+++++-++++--+++-----++##++######+++-+++--++++#++++++++++
...------+--+----------+-+-------.-..-----...---.-.--.---.---.---.-----+++#++++--++++-++++------#....---+++######+++----+-+++++++++++++##
.------+--++------------+-------.......---..-.-.---.........-..-..-..---+++#+++++++++++++------++....---#++########++-----++++-++++++++++
---+--+--++--+---+------+++----........--..-.-..-......-........-.------++++#+++#+++++++--+--+--++...----#-########+++------++-+--+++++++
----++--+------+++----++-...........----...........-.......-..-...-------++++++++#++++++-+++++-+--+..-------##+###--+++++----------++++++
++-++-++--+-+--+++------+...........---....-...-...-....--.----.---------+++++#+#+#+++++++++++-+-.--.-------##+++--++++++++++--++----++++
-+++-++--+----++++-----+-....----....-----.-----..-...----------------+-++++++#+##+++++++++++++#+..---------+##+++-++++++++---+-++----+++
++-++++-++++--++-+----++...-------------+---------------------------+++++++++++#+###+-+++++#####+..----------#++-+++++++-+++-----++++++++
++++++-++---+-++++----+-..-------------+++++-------------++++++++--++++++++++++##++###+####+####+...--------++++---+++++++-+++----+++++++
+++++++++++--+++++-------------------+-++++++++-+--++++++++++++++++++++++++++++++#++++++#----++-+....-------+++---++--++++++++++--+++++++
++++-++++-++++++++-----+----------+++++++++++++++++-+++++++++++++++++++++++++#+++++###+++++++-.-.....-------+#------+-++++++++++++-++++##
+++-+++++-+-+-+++++-----+----------+++++++++++++-+++++++++++++++++++++++++++++++##---+++++---.--......----+-+++----++++++-+++++++++++++++
+++++++-++++--+++--------+-+--++---+#++++++++++++++++++++++++++++++++++++++++#++++-+--++--.-.---......----+++++-+---++++++-+++++++++##+++
++++++++-+-+-++-+-++-+---+--+++++++++#+++#+++++++-+++++++++++++++++++++####+++++#+----#+.---...-......----+-+#++-+-+++++-+++++#+++++++##+
++++++++-++-++-+++-+-++------++++++++++-++#++++++++++++++++++++##############+#++#+---#---+--+.-.....-----+++##+++++++++++-++++++++++++++
+++++-++-++-++++++-++++++++---+++++#+##+####++++++++++++#######################+#+----+---++-..-..---------++####++++++++++-++++++#+++#++
++++-+++-+--++-+++--+++++++-...+++++++++++++#++++++#############################-+-+-+++--++.--+.----#---++-+####+++++++++++++++++++#+++#
++++-+++++---+-+++--+-+-++++....-+-+-+----+++##########++######################---+---+++-+----+---.##-+-+-++####++++++++++++++++++++#+++
+-+---++-++--+--++++++-+-+++..+.---------++++###################################-----+-+-++-+++----###+-+-+++###+++++++++++++++++#+++++##
+-----++++++-++++++-++--+-++..+.-++--+----.++#####++++++########################------+++++-++--.-###++++++++###+++++++++++++++++++++++++
-+-+--+++++-+-++++++-+-+--++..-----------.++##########+#########################--------+-+++++--+######++++####++++++++++++++++#++++++++
-------+++++-+++++++--+-----...-----++----+--###################################--------+-#+++++++#######++#####++++#++++++++++++++++++++
+------+++++--++++++++--+--.....----+-+----+#######++##+++#####################+--------+++++++++++############++++++++++++++++++++++++++
*/

struct Fraction {
    int numerator;
    int denominator;

    Fraction(int a, int b) : numerator(a), denominator(b) {

        int gcd__ = gcd(a, b);
        numerator /= gcd__;
        denominator /= gcd__;
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
};

struct FractionCompare {
    bool operator()(const Fraction& lhs, const Fraction& rhs) const {
        return lhs < rhs;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    set<Fraction, FractionCompare> fractions;

    for (int b = 1; b <= n; ++b) {
        for (int a = 1; a <= n; ++a) {
            fractions.insert(Fraction(a, b));
        }
    }

    vector<Fraction> sorted_fractions(fractions.begin(), fractions.end());

    for (const auto& frac : sorted_fractions) {
        cout << frac.numerator << " " << frac.denominator << "\n";
    }

    return 0;
}