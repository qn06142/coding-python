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

bool isPalindrome(const vector<int>& jewels, int i, int j) {
    while (i < j) {
        if (jewels[i] != jewels[j]) return false;
        i++;
        j--;
    }
    return true;
}

int minSecondsToClearJewels(const vector<int>& jewels) {
    int n = jewels.size();
    vector<vector<int>> dp(n, vector<int>(n, n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (isPalindrome(jewels, i, j)) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i][i] + dp[i + 1][j]; 
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
                if (jewels[i] == jewels[j]) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> jewels(n);
    for (int i = 0; i < n; i++) {
        cin >> jewels[i];
    }

    cout << minSecondsToClearJewels(jewels) << endl;

    return 0;
}