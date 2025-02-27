#include<bits/stdc++.h>
using namespace std;
namespace __DEBUG_UTIL__/**/{/**/using namespace std;/**//**/void print(const char *x)/**/{ cerr << x; }/*#########+++++*/void print(bool x)/**/{ cerr << (x ? "T" : "F"); }/**/void print(char x)/*##############################
*/{ cerr << '\'' << x << '\''; }/**/void print(signed short int x)/**/{ cerr << x; }/*##############################++++++*/void print(unsigned short int x)/**/{ cerr << x; }/**/void print(signed int x)/**/{ cerr << x; }/*######
*/void print(unsigned int x)/**/{ cerr << x; }/**/void print(signed long int x)/**/{ cerr << x; }/*################+++++++*/void print(unsigned long int x)/**/{ cerr << x; }/**/void print(signed long long int x)/*###############
*/{ cerr << x; }/**/void print(unsigned long long int x)/**/{ cerr << x; }/**/void print(float x)/*##############+++++++++*/{ cerr << x; }/**/void print(double x)/**/{ cerr << x; }/**/void print(long double x)/*#################
*/{ cerr << x; }/**/void print(string x)/**/{ cerr << '\"' << x << '\"'; }/**/template <size_t N>/*#############++++++++++*/void print(bitset<N> x)/**/{ cerr << x; }/**/void print(vector<bool> v)/**/{ /**/int f = 0;/*###########
*/cerr << '{';/**/for (auto &&i : v)/**/cerr << (f++ ? "," : "") << (i ? "T" : "F");/**/cerr << "}";/**/}/**//*+--+++++++*/template <typename T>/**/void print(T &&x);/**/template <typename T>/*###################################
*/void print(vector<vector<T>> mat);/**/template <typename T, size_t N, size_t M>/*##########################++--++++++++*/void print(T (&mat)[N][M]);/**/template <typename F, typename S>/**/void print(pair<F, S> x);/*##########
*/template <typename T, size_t N>/**/struct Tuple;/**/template <typename T>/**/struct Tuple<T, 1>;/*#######+++--+++++++++*/template <typename... Args>/**/void print(tuple<Args...> t);/**/template <typename... T>/*###############
*/void print(priority_queue<T...> pq);/**/template <typename T>/**/void print(stack<T> st);/*#############+----+++++++++*/template <typename T>/**/void print(queue<T> q);/**//**/template <typename T>/**/void print(T &&x)/**/{/*#
*//**/int f = 0;/**/cerr << '{';/**/for (auto &&i : x)/**/cerr << (f++ ? "," : ""), print(i);/*##########-----++++++++++*/cerr << "}";/**/}/**/template <typename T>/**/void print(vector<vector<T>> mat)/**/{/**/int f = 0;/*######
*/cerr << "\n~~~~~\n";/**/for (auto &&i : mat)/**/{/*##################################+###############+-----++++++++++*/cerr << setw(2) << left << f++, print(i), cerr << "\n";/**/}/**/cerr << "~~~~~\n";/**/}/*##################
*/template <typename T, size_t N, size_t M>/**/void print(T (&mat)[N][M])/**/{/*#####++++#############+-----+++++++++++*/int f = 0;/**/cerr << "\n~~~~~\n";/**/for (auto &&i : mat)/**/{/*##########################################
*/cerr << setw(2) << left << f++, print(i), cerr << "\n";/**/}/*####################++++++#########--------++++++++++++*/cerr << "~~~~~\n";/**/}/**/template <typename F, typename S>/**/void print(pair<F, S> x)/**/{/*############
*/cerr << '(';/**/print(x.first);/**/cerr << ',';/**/print(x.second);/*############++++++######----+-------++++++++++++*/cerr << ')';/**/}/**/template <typename T, size_t N>/**/struct Tuple/**/{/**/static void printTuple(T t)/*#
*/{/**/Tuple<T, N - 1>::printTuple(t);/**/cerr << ",", print(get<N - 1>(t));/*####+++++*/}/*###---+------+++++++++++++*/};/**/template <typename T>/**/struct Tuple<T, 1>/**/{/**/static void printTuple(T t)/*#####################
*/{ print(get<0>(t)); }/**/};/**/template <typename... Args>/*###################+++############-+------++++++++++++++---------*/void print(tuple<Args...> t)/**/{/**/cerr << "(";/**/Tuple<decltype(t),/*##########################
*/sizeof...(Args)>::printTuple(t);/**/cerr << ")";/**/}/*#######################+++############-+-------++++++++++++++++----------++*/template <typename... T>/**/void print(priority_queue<T...> pq)/**/{/**/int f = 0;/*##########
*/cerr << '{';/**/while (!pq.empty())/**/cerr << (f++ ? "," : ""),/*############++############+++-----++++++++++++++++++++++++---------*/print(pq.top()), pq.pop();/**/cerr << "}";/**/}/**/template <typename T>/*#################
*/void print(stack<T> st)/**/{/**/int f = 0;/**/cerr << '{';/*#################++############+++-----+++++++++++++++++++++++++++--++++---+*/while (!st.empty())/**/cerr << (f++ ? "," : ""),/**/print(st.top()), st.pop();/*########
*/cerr << "}";/**/}/**/template <typename T>/**/void print(queue<T> q)/**/{/*#++############+--+----++++++++++++++++++++++++++++++++++++--++*/int f = 0;/**/cerr << '{';/**/while (!q.empty())/**/cerr << (f++ ? "," : ""),/*#######
*/print(q.front()), q.pop();/**/cerr << "}";/**/}/*########################+#++#+##########+++-----+-++++++++++++++++++++++++++++++++++++++-++*/void printer(const char *) {} /**/template <typename T, typename... V>/*############
*/void printer(const char *names, T &&head, V &&...tail)/**/{/**/int i = 0;/*+#++#+######+++----+-+++++----------++++++++++++++++++++++++++++---------*/for (size_t bracket = 0;/**/names[i] != '\0' and/*##########################
*/(names[i] != ',' or bracket != 0); i++)/*########################++++++####++++#######++-----++++++----------++++++++++++++++++++++++++++++++-----------------------*/if (names[i] == '(' or names[i] == '<' or names[i] == '{')/*
*/bracket++;/*###############################################++++++++#########+########+--+------+-----------+++-----+++++++++++++++++++++++++++-----------------------------++++++#################################################
#############################################################+###+++##################++---++++++----------++--------++++++++++++++++++++++++++++-------------------++++++++++++++##################################################
#################################################################+################+#++++++---++-----------+--------+++-------+++++++++++++++++++++------------+++++++++++++++++++###################################################
*/else if (names[i] == ')' or names[i] == '>' or names[i] == '}')/*####+###########+++------++----------+---------+-----------+++++++++++++++++++++----+-++++++++++++++++++++++*/bracket--;/**/cerr.write(names, i) << " = ";/*#####
*/print(head);/**/if (sizeof...(tail))/**/cerr << " ||",/*##########+#+#+######++#+++++-++++--------------------+------------+----+++++++++++++++++++++++++++++++++++++++++++*/printer(names + i + 1, tail...);/**/else/*###########
*/cerr << "]\n";/**/}/**/void printerArr(const char *) {} /*#################+####+++-+++++-----------+-----+-+++-----------++------+++++++++++++++++++++++++++++++++++++++*/template <typename T, typename... V>/*#################
*/void printerArr(const char *names, T arr[], size_t N, V... tail)/**/{/*#########+++++++------------++--+++--+------------++--------+++++++++++++++++++++++++++++++++++++*/size_t ind = 0;/*#######################################
*/for (; names[ind] and names[ind] != ','; ind++)/**/cerr << names[ind];/*####+##+++++++----------------++-++--------------+-----------+++++++++++++++++++++++++++++++++*/for (ind++; names[ind] and names[ind] != ','; ind++)/*####
*******/cerr << " = {";/**/for (size_t i = 0; i < N; i++)/*#####+############+###++++++------------++--++-----------+-----+------------+++++++++++++++++++++++++++++++*/cerr << (i ? "," : ""), print(arr[i]);/**/cerr << "}";/*####
*/if (sizeof...(tail))/**/cerr << " ||",/*####################+++###############++++++---------------+++++---------+---------------------+++++++++++++++++++++++++++*/printerArr(names + ind + 1, tail...);/**/else/*###############
*/cerr << "]\n";/**/}/**/}/*#################################+++++######++######+++++------------+-+++++--------------------------------+++++++++++++++++++++++++###################################################################
############################################################++++++##############++++-------------+++++------------+--------------------+-++++++++++++++++++++++#####################################################################
##########################################################+++++++##############+++++-------------+-+------+-------+-------------------+--+++++++++++++++++++#+######################################################################
#########################################################++++++++##++++######+#++++------------+++++----+------++++-----------------+-++-+++--++++++++++++##########################################################################
########################################################+++++++++##+++#######+++++-------------+++------------++++-------------+----+-+--++---+++++++++++++#########################################################################
#######################################################+++++++++++##+#########++++------------++---+--------+-++++------------------+++---+----++++++++++#+#########################################################################
#######################################################+++++++++++#++#######+++++---------+---+--+---------+++++++----+-----------++++---+-------+++++++###+#######+################################################################
#######################################################++++++++++##++#######++++--------------++------+-+--++--++-----+----------++++++-++------++++++++++##+#########+#############################################################
########################################################+++##+#++++##++#####++++-----------------++++-++++-+----+----+-------+--+++++++-++-----+--++++++++##+##########++###########################################################
#########################################################+++++++#+##+++#+###+++----------++--++++++++++++-+-----+----+---+-----++++++++-++-+---+--++++++++###+##########++##########################################################
#########################################################++++++##+#-++++++++++-----------++--+++++++++++-++++++---+--+--++-----+-+++++--+---------+++++++++###+##########++#########################################################
########################################################+++++++#++#--+++++++++-----------++--+#######++-++++++++-++----+-+----+--++++--++--+---+---++++++++####+###########++#######################################################
########################################################+++++++####+-++++++++---+---------++++##+###+++##+++++++-++--+++++---++++++++-+++--+---+++-+++++++++####+###################################################################
#######################################################++++++++####+-+++++#++------+--++--++++#+###+#+#+#+#++++-++-+-++++-+--+++++---+++--++--+-++++++++++++####+###################################################################
######################################################--++++++++###+-+++++#+-+-----+++-++--+-++++++##+#+##+++++-++-+-++++++-++++++--+++++-+++-+-+++++++++++++####+##################################################################
#####################################################--++-+++++++##--++++#-+-------+++++++-+++++++++++#++#++++-+++++++++++++-++++-+++++-+++-+++-++-++++++++#+####++#################################################################
####################################################---+-++++++++#+--++-++-+++----++++++++++++++++-+-++++++++++++++++-++++++-+++-+++++++++++++--+++++++++++##+####++################################################################
###################################################----+-++++##++#+--++-+---+++---++++++++++++++++++++++++++++++++++++++++++-+++++###+++#+++++--+-++++++++-##++####+#+######################################################--######
##################################################+---+-+++++##++#+--+-+--++++-+--+++++++++++++++++++++++++++++++++++++++++++#++++##+++#++++++---++++++++++###++###++############################################--#####+-----+#####
#################################################+----+-+++#+++++#++-++++---++++--+-++-+++++++++++++++++++++++++++++++++++++++++####+++##+++++---++++++++++-##++####++###########################-+-############+--###++---++#######
#################################################------+++++++++#++++++----++++++++---+++++++++++++++++++++++++++++++++++++++++####+++++#+++++--+++++++++++++###+###++#+######################-----+############---++----+++########
################################################----+-++++++++++#++++++----+-++++++--+--++++-+++++-+++++++++++++++++-++++++++++++++#+-++#+++++-++++++++++++++###++###++++###################-----++#-###+-#####+--++---+++##########
###############################################------++++++++++#+++++------+-+++++---+--+-+++++++++++++++++++++++----++++++++++---+-++###++++-+++++++++++++-++#+#++###++################------++++++--+#---####+--++-+++############
##############################################-------+++++++++++++++---+---++--++++---+-+-++-++++++++++++++++++++++++++++++++++++++#+++++++++++++++++++++++-+++###+####+#############++------++++##+----+--+###+--+-+++#############
#############################################+------++-++++++++++++++---+---+++-++---+--++-+-+++++++++++++++++++++++++++++++++++++++++++#++++++++++++++++++-++++##++###+############++---++++++#####++--++--+#+--+++++##############
############################################+-------+-++++++++++++-+++---+--++++-++--+++-+-+-+++++++++++++++++++++++++++++++++++++++++#++++++++++++++++++-+-++++###++###+##########++---+++++++#######+-----++++++++################
############################################-------++++++++++++++-+--+++--+--++++++--++-++--+-+++++++++++++++++++++++++++++++++++++++#++#-++++++++++++++-+-++++++###+###+#########++---++++++++++####+#+--+---++++##################
###########################################-------++-+++++++++++++--+++++--+--++++++--+-++--+++++++++++++++++++++++++++++++++++++++#+++#+++++++++++++++++++#+++++####+###+#######++----+++++++++++++++++--++++++####################
##########################################--------+-++++++++++++++-++-++++-+---++++++-+-+++--+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++##+#+##+######+------++++++++++--------++++++#####################
#########################################--------++-+++++++++++++++++--++++++---+++++++-+++++++++++++++++++++++++++++++++++++++++++++++-+++-++++++++++++++++++++#+#++##+#+#####+-------------------+--+-+++++++#####################
########################################--------++-+++++++++++++++++++++++++++++-+++++---++++-++++++++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++#++++###+--------------------+--++++++++######################
#######################################--------++-++++++++++++++++++++-++++++++++-++++---+++++-+++++++++++++++++++++++++++++++-++++++--+-+++++++++++++++++++++++++++++##+++###------------------++++++++++++########################
######################################--------++--++++++++++++++++++++-++++++++++++++++-+++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++####++++++--------++-+++++++++++++++###########################
#####################################--------+++++++++++++++++++++++++-++++++++++++++++++++-+++++++++++++++++++++++###+++++++++++++++++++++++++++++++-++++++++++++++#####+++++++------++++++++++++++++##############################
###################################+-----+--++++++++++++++++++++++++++-++++++++++++++++++++-++++###++++++##++#########+-+++++++++++++++++++++++++++++++++++++++++##++++##+++++++----++++++++++++++++################################
#################################-------+--++++++++++++++++++++++++++-++++++++++++++++++++++-++#+####+++++###########++-+++++++++++++++++++++++++++++++++++++++++##+++++++++++++---++++++++#+++++#+++++#############################
################################------+---+++++++++++++++++++++++++++++++++++++++++++++++-+++++#+#####+++###########+++-++++++-+++++++++++++++++++++++++++++++++####++++++++++++-+++++++++#+++++++++++++############################
##############################-------+--++++++++++++++++++++++++++-++++++++++++++++++++++-+-#++#+#####+++##########++++-+++++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++###########################
############################-------++---+++++++++++++++++++++++++++-+++++++++++++++++++++++-+#++#######+##########+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#+#+###+++#++++############################
###########################------+++-+-+++++++++++++++++++++++++++++++++++++++++++++++++##+++#########################++++++++++++++++++--++++++++++++++++++++++++++++++++--+++++++++++++#++++++++#+++++############################
#########################-------+++---+++++++++++++++++++++++++++++++++++++++++++++++++####++++##########################++++++++++++++++++++++++--+++++++++++++++++++++++-+++++++++++++#+++++++###+++++++##########################
#######################-------+++--+-+++++++++++++++++++++++----++++++++++++++++++###++#####+++++##########################++++++++++++++++++++++-+++++++++++++++++++++++++-++++++++++++#+++++####++++++++##########################
######################------++++--++++++++++++++++++++++++-----+++++-+++++++++++####++#######++++++###+#####################+++++++++++++++++++++-++++++++++++++++++++++++++++++++++++++#+++####+++#+++++###########################
####################------+++++-+++++++++++++++++++++++++++------+++-++++-+++++++##+++++########+++++#######################+++++++++++++-+++++++++++++++++++++++++++-++++++++++++##+++++#+#####+++#++++############################
##################-------+++++++++++++++++++++++++++++++++++-----+++-++++++++++++++++++++#############+++##################++++++++++++++++++++++++++++++++++++++++++--+++++++++#+##+++########+#++++++#############################
################-------++++++-++++++++++++++++++++++++++++++++--++++-+++++++++++++++++++++#####+++#+++++++#++############++++++++++++++++-+++++++++++++++++++++++++++-+++++++++#####++++####++#####+################################
###############------++++++++++++++++++++++++++++++++++++--++++++++++-++++-+++++++++++++++++##+++++++++++++++##############++++++++++++-+++++++++++++++++++++++++++++-+++++++++####+++#########+####################################
#############-------+++++++++++++++++++++++++++++++++-----++++++++++++++++++++++++++++++++##+#+++++++#++#####++###########+++++++++++-+++++++++++++++++++++++++++++++-+++++++++###############++####################################
###########-------+++++++++++++++++++++++++++++++++------+++++++++++++++++++++++-+++++++#+++++++++++++++#+++++###########+++++++++++++++++++++++++++++++++++++++++++--+--++++++#####################################################
#########-------++++++++++++++++++++++++++++++++++------+++++++++++++++++++-++++-++++#++---+++++++++++++++++++++++######++++++++++++++++++++++++++++++++++++++++++++--++++++++####+####+#+##########################################
########------++++++++++++++++++++++++++++++++++++-----++++++++++++++++++++++++++++++---+++++++++++++++++++++++++++####+++++++++++++++++++++++++++++++++++++++++++++--+-+++++#####+###++++##########################################
*/
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif
int a[(int)1e5 + 5];
int n, m;

namespace sub1 {
    bool cando() {
        for (int i = 2; i <= n; i++) {
            if (a[i - 1] >= a[i]) return false;
        }
        return true;
    }

    void main() {
        int ans = 0;
        int maxdist = 0;
        for (int i = 2; i <= n; i++) {
            ans += a[i] - a[i - 1];
            maxdist = max(maxdist, a[i] - a[i - 1]);
        }
        cout << ans - maxdist + 1 << endl;
    }
}

namespace sub2 {
    bool cando() {
        return n * m <= 1e6;
    }

    int dist(int a, int b) {
        int clockwise = (b - a + m) % m;
        return clockwise;
    }

    int calc(int x) {
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            int c = dist(a[i - 1], a[i]);
            int d = dist(x, a[i]) + 1;
            if(c < d) {
                ans += c;
            } else {
                ans += d;
            }
        }
        return ans;
    }

    void main() {
        int ans = INT_MAX;
        for (int i = 1; i <= m; i++) {
            ans = min(ans, calc(i));
        }
        cout << ans << endl;
    }
}

namespace sub3 {
    bool cando() {
        return true; // Default case when sub1 and sub2 are not applicable.
    }

    void main() {
        vector<int> pref(n + 1, 0);
        vector<int> suff(n + 2, 0);

        for (int i = 2; i <= n; i++) {
            pref[i] = pref[i - 1] + (a[i] - a[i - 1] + m) % m;
        }

        for (int i = n - 1; i >= 1; i--) {
            suff[i] = suff[i + 1] + (a[i + 1] - a[i] + m) % m;
        }

        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int cost = max(pref[i], suff[i + 1]);
            ans = min(ans, cost);
        }

        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    /*if (sub1::cando()) {
        sub1::main();
        return 0;
    }
    if (sub2::cando()) {
        sub2::main();
        return 0;
    }*/
    if (sub3::cando()) {
        sub3::main();
        return 0;
    }
    return 1;
}