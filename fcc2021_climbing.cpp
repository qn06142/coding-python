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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    deque<int> dq2, dq1;
    vector<int> ans;

    for (int i = 0; i < n; ++i) {

        if (!dq2.empty() && dq2.front() <= i - m) {
            dq2.pop_front();
        }
        if (!dq1.empty() && dq1.front() <= i - m) {
            dq1.pop_front();
        }

        while (!dq2.empty() && a[dq2.back()] >= a[i]) {
            dq2.pop_back();
        }
        while (!dq1.empty() && a[dq1.back()] <= a[i]) {
            dq1.pop_back();
        }

        dq2.push_back(i);
        dq1.push_back(i);

        if (i >= m - 1) {
            int minVal = a[dq2.front()];
            int maxVal = a[dq1.front()];
            if (maxVal - minVal <= c) {
                ans.push_back(i - m + 2); 
            }
        }
    }

    if (ans.empty()) {
        cout << "NONE" << endl;
    } else {
        for (int result : ans) {
            cout << result << endl;
        }
    }

    return 0;
}