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
#define int long long
struct fraction {
    int a, b;
    const bool operator<(fraction other) {
        return 1LL * a * other.b < 1LL * other.a * b;
    }
    const bool operator==(fraction other) {
        return 1LL * a * other.b == 1LL * other.a * b;
    }
    fraction() {
        a = b = 0;
    }
    fraction(int x, int y) {
        a = x;
        b = y;
    }
};
fraction a[(int) 1e6];
int arr[(int) 1e5 + 5][2];
int dp[(int) 1e5 + 5][2];
int bit[(int) 4e5 + 5];
void update(int x, int v) {
    while(x <= 4e5 + 4) {
        bit[x] = max(bit[x], v);
        x += (x & (-x));
    }
}
int query(int x) {
    int ans = 0;
    while(x > 0) {
        ans = max(ans, bit[x]);
        x -= (x & (-x));
    }
    return ans;
}
signed main() {
    int n;
    bool w;
    cin >> n >> w;
    vector<fraction> cmp;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b;
        cmp.push_back(a[i]);
        if(w)
        cmp.push_back(fraction(a[i].b, a[i].a));
    }
    sort(cmp.begin(), cmp.end());
    cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
    for(int i = 1; i <= n; i++) {
        arr[i][0] = lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin() + 1;
        if(w)
        arr[i][1] = lower_bound(cmp.begin(), cmp.end(), fraction(a[i].b, a[i].a)) - cmp.begin() + 1;
        else
        arr[i][1] = arr[i][0];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 1;
        for(int j = 1; j < i; j++) {
            for(int k = 0; k < 2; k++) {
                if(arr[j][k] < arr[i][k])
                dp[i][k] = max(dp[i][k], dp[j][k] + 1);
                if(arr[j][!k] < arr[i][k])
                dp[i][k] = max(dp[i][k], dp[j][!k] + 1);
            }
        }
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
}