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
    cin.tie(NULL);

    int n;
    long long ans = 0;
    stack<int> st;
    map<int, int> cnt;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        while (!st.empty() && x > st.top()) {
            cnt[st.top()]--;
            st.pop();
            ans++;
        }
        
        if (!st.empty())
            ans += (x == st.top()) ? cnt[x] + (st.size() > cnt[x]) : 1;
        
        st.push(x);
        cnt[x]++;
    }
    
    cout << ans << "\n";

    return 0;
}
