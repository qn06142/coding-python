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
######-------++++++++++++++++++++++++++++++++++++++-++++++++++++++++++++-++++++++++--++-+++++++++++++++++++++++++++++#+++++++++++++++++++++++++++++++++++++++++++++--+++++++++##+#++##++############################################
####-------+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-+---+++++++++++++++++++++++++++++++++#++++++++++++++++++++++++++++++++++++++++++++--+-+++++++#####++###+###########################################
##+-------+++++++++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++-+-+---++++-+-++++++-++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++--+++++#++++++###+##++#########################################
#-------+++++++++++++++++++++++++++++++++++++++++++++-++++++++++++++++---++++++++++++--+++++++++-+++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++--++++++++++++++######++#+########################################
------+++++++++++++++++++++++++++++++++++++++++++++++++-++++++++++++++-++++-++++++-+--++++++++---++++-++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++------++++++++++#######++++#######################################
----+++++++++++++++++++++++++++++++++++++++++++++++++----------++++++-+----+-++---+-++++--+-++-----+-----+++---+--++++++++++++++++++++++++++++++++++++++++++++++++--------++++++++##################################################
#-+++++++++++++++++++++++++++++++++++++++++++++++++++------------+++++----+--+---+--+----+---+-----++--+-+-----+---+++++++++++++++++++++++++++++++++++++++++++++++-------++++++++++#++######+#++####################################
#+++++++++++++++++++++++++++++++++++++++++++++++++++-------------+++-------++----+-+---------+-------+-+--+---+--++-+-++++++++++++++++++++++++++++++++++++++++++++-------++++++++++++++#######++#++#################################
#++++++++++++++++++++++++++++++++++++++++++++++++++-------------+++-------+-----+-----+------+---------+---+---++++-++++++++++++++++++++++++++++++++++++++++++++++++-----+++++++++++#+++#+######++++################################
+++++++++++++++++++++++++++++++++++++++++--------------++++++++++++-----------------------------------+--------+-++++++++++++++++++++++++++++++++++++++++++++++++-+++----+++++++++++#########+++++++################################
+++++++++++++++++++++++++++++++++++++++++-------------------++++++-------------+--------------+-----+---------++++++++++++++++++++++++++++++++++++++++++++++++++++++-----++++++++++++#++++++#+++++++++##############################
+++++++++++++++++++++++++++++++++++++++++-------------------++++++------+------+---+++---------+---++-+++--+++--+++++++++++++++++++++++++++++++++++++++++++++++++-+-+----++++++++++++#++++++++++++++++++############################
+++++++++++++++++++++++++++++++++++++++++---------+---------++++++------+------------+------+-+-+++++++++-+++++++++++++++++++++++++++++++++++++++++++++++++++++++--+-+--++++++++++++++++++++++++++++++++++##########################
+++++++++++++++++++++++++++++++++++++++++-------+-+++-+-+----++++-+++----+-++++----+-+-+-+-+--+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++---+-++++++++++++++++++++++++++++++++++++++########################
++++++++++++++++++++++++++++++++++++++++-----++++++++++++++---++++++++++--++++-+++++++--+++++++++++++++++++++++++++++++++++++++++++#+++++++++++++++++++++++++++++----+++++++++++++++++++++++++++++++++++++++++######################
++++++++++++++++++++++++++++++++++++++++----+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++------+++++++++++++++++++++++++++++++++++++++++####################
+++++++++++++++++++++++++++++++++++++++-----+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-----+-++++++++++++++++++++++++++++++++++++++++++##################
+++++++++++++++++++++++++++++++++++++++----++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++------++++++++++++++++++++++++++++++++++++++++++++#################
++++++++++++++++++++++++++++++++++++++++++--+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-------++++++++++++++++++++++++++++++++++++++++++++++##############
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++--+-------+++++++++++++++++++++++++++++++++++++++++++++++#############
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++##+++++++++++++++-+-++---------++++++++++++++++++++++++++++++++++++++++++++++++###########
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++##++++++++++++++++++--+++---------++++++++++++++++++++++++++++++++++++++++++++++++++++#######
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#++++++++++++++++-------++++----------+++++++++++++++++++++++++++++++++++++++++++++++++++#######
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#++++++++++++++++++-------+++-+-----------+++++++++++++++++++++++++++++++++++++++++++++++++++++####
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++##++++++++++++++++++++----+-+-----+-----------++++++++++++++++++++++++++++++++++++++++++++++++++++++###
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++###+++###+++++++++++++++++++++++++++++-----+----------+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++##################++++++++++++++++++++++++++++++-+-++--------++++++++++++++#+++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#++++++++++++++++++++++++++++++##########################++++++++++++++++++++++++++++-+++------++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++##+++++++++++++++++++++++###################################+++++++++++++++++++++++--+-++----++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++-++++++++++++++++++++++#+++++++++++++++###########################################++++++++++++++++++++++--++++--+-+-++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++------+++++++++++++++++++++++#+++++++###########++##+##################################++++++++++++++++++++--++++++++-+-++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++--------++++++++++++++++++++#++#+###########++###+++##################################+++++++++++++++++++++--++++++--+-+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++-------+++++++++++++++++++++++###+#########+####++++++###############################++++++++++++++++++++++++++++++--++++++++++++++++++++##+++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++----+--++++++++++++++++++++++#+++#++######++++++++++###################################+++++++++++++++++++++++++++--++++++++++++++++++++#++#++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++----++-++++++++++++++++++++++########+#+++++++++++++++#++++############################++++++++++++++++++++++++++-+++++++++++++++++++++####+++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++----++--+++++++++++++++--++++########++++#######+#+++++++##############################++++++++++++++++++++++++++--++++++++++++++++++++##+++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++---+++--++++++++++++++--++++####+#####+++++#+++#######################################++++++++++++++++++++++++++-++++++++++##++++++++###++#++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++-----++++-+++++++++++++-++++++++++##+#+++++++++++++++##################################++++++++++++++++++++++++++++++++++++#+++++++++####+++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++------+++-++++++++++++++++++++++######+++++++++++######################################++++++++++++++++++++++++++++++++++++##++++++++###++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++-------+++++++++++++++++++++++++++###+++++++++++######################################+++++++++++++++++++++++++++++++++++++###+#+########+++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++--------+++++++++++++++++++++++++++++#+++++++++++++++#+################################+++++++++++++++++++++++++++++++++++++#####++#######+#+++++++++++++++++++++++++++++++++++++++++++
*/
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

const int MAXN = 200000;
const long long INF = 1e18;

int n, t;
vector<pair<int, int>> adj[MAXN + 3]; // stores (city, time_index) for connections
vector<int> time_indices[MAXN + 3];   // stores valid time indices for each city

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;
    for (int i = 1; i <= t; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }
    }

    int k;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        int time_checkpoint;
        cin >> time_checkpoint;
        time_indices[time_checkpoint].push_back(i);
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> min_time(n + 3, INF); // minimum time index required to reach each city
    min_time[1] = 0;
    pq.push({0, 1}); // (time_index, city)

    while (!pq.empty()) {
        auto [current_time, city] = pq.top();
        pq.pop();

        if (min_time[city] < current_time) continue;

        for (const auto& [neighbor, time_index] : adj[city]) {
            auto next_time = upper_bound(time_indices[time_index].begin(), time_indices[time_index].end(), current_time);
            if (next_time != time_indices[time_index].end() && min_time[neighbor] > *next_time) {
                min_time[neighbor] = *next_time;
                pq.push({min_time[neighbor], neighbor});
            }
        }
    }

    if (min_time[n] > k) {
        cout << -1;
    } else {
        cout << min_time[n];
    }

    return 0;
}
