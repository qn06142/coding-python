#include<bits/stdc++.h>
using namespace std;
namespace __DEBUG_UTIL__/**/{/**/using namespace std;/**//**/void print(const char *x)/**/{ cerr << x; }/*#########+++++*/void print(bool x)/**/{ cerr << (x ? "T" : "F"); }/**/void print(char x)/*##############################
*/{ cerr << '\'' << x << '\''; }/**/void print(signed short int x)/**/{ cerr << x; }/*##############################++++++*/void print(unsigned short int x)/**/{ cerr << x; }/**/void print(signed int x)/**/{ cerr << x; }/*######
*/void print(unsigned int x)/**/{ cerr << x; }/**/void print(signed long int x)/**/{ cerr << x; }/*################+++++++*/void print(unsigned long int x)/**/{ cerr << x; }/**/void print(signed long long int x)/*###############
*/{ cerr << x; }/**/void print(unsigned long long int x)/**/{ cerr << x; }/**/void print(float x)/*##############+++++++++*/{ cerr << x; }/**/void print(double x)/**/{ cerr << x; }/**/void print(long double x)/*#################
*/{ cerr << x; }/**/void print(string x)/**/{ cerr << '\"' << x << '\"'; }/**/template <size_t n>/*#############++++++++++*/void print(bitset<n> x)/**/{ cerr << x; }/**/void print(vector<bool> v)/**/{ /**/int f = 0;/*###########
*/cerr << '{';/**/for (auto &&i : v)/**/cerr << (f++ ? "," : "") << (i ? "T" : "F");/**/cerr << "}";/**/}/**//*+--+++++++*/template <typename T>/**/void print(T &&x);/**/template <typename T>/*###################################
*/void print(vector<vector<T>> mat);/**/template <typename T, size_t n, size_t M>/*##########################++--++++++++*/void print(T (&mat)[n][M]);/**/template <typename F, typename S>/**/void print(pair<F, S> x);/*##########
*/template <typename T, size_t n>/**/struct Tuple;/**/template <typename T>/**/struct Tuple<T, 1>;/*#######+++--+++++++++*/template <typename... Args>/**/void print(tuple<Args...> t);/**/template <typename... T>/*###############
*/void print(priority_queue<T...> pq);/**/template <typename T>/**/void print(stack<T> st);/*#############+----+++++++++*/template <typename T>/**/void print(queue<T> q);/**//**/template <typename T>/**/void print(T &&x)/**/{/*#
*//**/int f = 0;/**/cerr << '{';/**/for (auto &&i : x)/**/cerr << (f++ ? "," : ""), print(i);/*##########-----++++++++++*/cerr << "}";/**/}/**/template <typename T>/**/void print(vector<vector<T>> mat)/**/{/**/int f = 0;/*######
*/cerr << "\n~~~~~\n";/**/for (auto &&i : mat)/**/{/*##################################+###############+-----++++++++++*/cerr << setw(2) << left << f++, print(i), cerr << "\n";/**/}/**/cerr << "~~~~~\n";/**/}/*##################
*/template <typename T, size_t n, size_t M>/**/void print(T (&mat)[n][M])/**/{/*#####++++#############+-----+++++++++++*/int f = 0;/**/cerr << "\n~~~~~\n";/**/for (auto &&i : mat)/**/{/*##########################################
*/cerr << setw(2) << left << f++, print(i), cerr << "\n";/**/}/*####################++++++#########--------++++++++++++*/cerr << "~~~~~\n";/**/}/**/template <typename F, typename S>/**/void print(pair<F, S> x)/**/{/*############
*/cerr << '(';/**/print(x.first);/**/cerr << ',';/**/print(x.second);/*############++++++######----+-------++++++++++++*/cerr << ')';/**/}/**/template <typename T, size_t n>/**/struct Tuple/**/{/**/static void printTuple(T t)/*#
*/{/**/Tuple<T, n - 1>::printTuple(t);/**/cerr << ",", print(get<n - 1>(t));/*####+++++*/}/*###---+------+++++++++++++*/};/**/template <typename T>/**/struct Tuple<T, 1>/**/{/**/static void printTuple(T t)/*#####################
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
*/void printerArr(const char *names, T arr[], size_t n, V... tail)/**/{/*#########+++++++------------++--+++--+------------++--------+++++++++++++++++++++++++++++++++++++*/size_t ind = 0;/*#######################################
*/for (; names[ind] and names[ind] != ','; ind++)/**/cerr << names[ind];/*####+##+++++++----------------++-++--------------+-----------+++++++++++++++++++++++++++++++++*/for (ind++; names[ind] and names[ind] != ','; ind++)/*####
*******/cerr << " = {";/**/for (size_t i = 0; i < n; i++)/*#####+############+###++++++------------++--++-----------+-----+------------+++++++++++++++++++++++++++++++*/cerr << (i ? "," : ""), print(arr[i]);/**/cerr << "}";/*####
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
static vector<int> spf;

void build_spf(int n) {
    spf.assign(n+1, 0);
    for(int i = 2; i <= n; i++) {
        if(spf[i] == 0) {
            for(int j = i; j <= n; j += i)
                if(spf[j] == 0) spf[j] = i;
        }
    }
}

map<int,int> factor(int x) {
    map<int,int> cnt;
    while(x > 1) {
        int p = spf[x];
        cnt[p]++;
        x /= p;
    }
    return cnt;
}
map<int, int> merge(map<int, int> a, map<int, int> b) {
    for(pair<int, int> i:a) {
        b[i.first] += i.second;
    }
    return b;
}
map<int, int> gcd(map<int, int> a, map<int, int> b) {
    for(pair<int, int> i:a) {
        b[i.first] = min(b[i.first], i.second);
    }
    for(pair<int, int> i:b) {
        b[i.first] = min(a[i.first], i.second);
    }
    return b;
}
vector<int> read() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i:a) {
        cin >> i;
    }
    return a;
}
map<int, int> combine(vector<int> nums) {
    map<int, int> ans;
    for(int i : nums) {
        ans = merge(ans, factor(i));
    }
    return ans;
}

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){
    build_spf(1e5 + 5);
    auto a = combine(read());
    auto b = combine(read());
    long long ans = 1;
    for(pair<int, int> i:gcd(a, b)) {
        ans *= binpow(i.first, i.second, 1e9 + 7);
        ans %= (long long) 1e9 + 7;
    }
    cout << ans;
}