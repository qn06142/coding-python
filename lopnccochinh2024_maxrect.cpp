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
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> L(n + 1), R(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> stacc;
    for(int i = 1; i <= n; i++) {
        while(!stacc.empty() && a[stacc.top()] >= a[i]) stacc.pop();
        L[i] = stacc.empty() ? 1 : (stacc.top() + 1);
        stacc.push(i);
    }
    while(!stacc.empty()) stacc.pop();
    for(int i = n; i > 0; i--) {
        while(!stacc.empty() && a[stacc.top()] >= a[i]) stacc.pop();
        R[i] = stacc.empty() ? n : (stacc.top() - 1);
        stacc.push(i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, a[i] * (R[i] - L[i] + 1));
    }
    int ans1 = ans;
    cout << max(ans, ans1);
}
