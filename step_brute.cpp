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

#define INF 1000000
const int maxn = 2e7;
int pref[maxn];
int suf[maxn];
int MAX[maxn];
bool dance[maxn];
void build(int tl, int tr, int v) {
    if (tl == tr) {

        MAX[v] = 1;

        pref[v] = 1;

        suf[v] = 1;
    } else {
        int tm = (tl + tr) / 2;
        build(tl, tm, v * 2);
        build(tm + 1, tr, v * 2 + 1);

        MAX[v] = max(MAX[v * 2], MAX[v * 2 + 1]);

        if (dance[tm] == dance[tm + 1]) {
            MAX[v] = max(MAX[v], suf[v * 2] + pref[v * 2 + 1]);
        }

        pref[v] = pref[v * 2];
        if (pref[v * 2] == tm - tl + 1 && dance[tm] == dance[tm + 1]) {
            pref[v] += pref[v * 2 + 1];
        }

        suf[v] = suf[v * 2 + 1];
        if (suf[v * 2 + 1] == tr - tm && dance[tm] == dance[tm + 1]) {
            suf[v] += suf[v * 2];
        }
    }
}

void update(int pos, int tl, int tr, int v) {
    if (tl > pos || tr < pos) {
        return;
    }

    if (tl == tr && tl == pos) {
        MAX[v] = 1;
        pref[v] = 1;
        suf[v] = 1;
    } else {

        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(pos, tl, tm, v * 2);
        } else {
            update(pos, tm + 1, tr, v * 2 + 1);
        }

        MAX[v] = max(MAX[v * 2], MAX[v * 2 + 1]);

        if (dance[tm] == dance[tm + 1]) {
            MAX[v] = max(MAX[v], suf[v * 2] + pref[v * 2 + 1]);
        }

        pref[v] = pref[v * 2];
        if (pref[v * 2] == tm - tl + 1 && dance[tm] == dance[tm + 1]) {
            pref[v] += pref[v * 2 + 1];
        }

        suf[v] = suf[v * 2 + 1];
        if (suf[v * 2 + 1] == tr - tm && dance[tm] == dance[tm + 1]) {
            suf[v] += suf[v * 2];
        }
    }
}

void solveQueries(int n, vector<int> &queries) {

    build(0, n - 1, 1);

    for (int i = 0; i < queries.size(); i++) {
        int pos = queries[i];  

        dance[pos] = dance[pos] ^ 1;

        update(pos, 0, n - 1, 1);

        cout << MAX[1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
	int len = 0;
    for (int i = 0; i < n; i++) {
		memset(dance + len, i & 1 ^ 1, a[i]);
		len += a[i];
    }
	debug(dance);
    vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    solveQueries(len, queries);

    return 0;
}
