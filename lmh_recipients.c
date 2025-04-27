#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef long long ll;

typedef struct {
    ll pos;   
    ll delta; 
} Event;

int cmp_event(const void *p1, const void *p2) {
    Event *e1 = (Event*) p1;
    Event *e2 = (Event*) p2;
    if(e1->pos < e2->pos) return -1;
    if(e1->pos > e2->pos) return 1;
    return 0;
}

int main(){
    ll n;
    int m;
    scanf("%" SCNd64 " %d", &n, &m);

    ll base = 0;

    int max_events = 4 * m + 2; 
    Event *events = (Event*) malloc(sizeof(Event) * max_events);
    int cnt_events = 0;

    for (int i = 0; i < m; i++){
        ll a, k;
        scanf("%" SCNd64 " %" SCNd64, &a, &k);
        ll full = a / n;
        ll rem = a % n;
        base += full;
        if(rem == 0) continue;  

        ll start = k;
        ll end = k + rem - 1;
        if(end <= n){

            events[cnt_events].pos = start;
            events[cnt_events].delta = 1;
            cnt_events++;
            events[cnt_events].pos = end + 1;
            events[cnt_events].delta = -1;
            cnt_events++;
        } else {

            events[cnt_events].pos = start;
            events[cnt_events].delta = 1;
            cnt_events++;
            events[cnt_events].pos = n + 1;
            events[cnt_events].delta = -1;
            cnt_events++;

            ll r = end - n;  
            events[cnt_events].pos = 1;
            events[cnt_events].delta = 1;
            cnt_events++;
            events[cnt_events].pos = r + 1;
            events[cnt_events].delta = -1;
            cnt_events++;
        }
    }

    events[cnt_events].pos = 1;
    events[cnt_events].delta = 0;
    cnt_events++;
    events[cnt_events].pos = n + 1;
    events[cnt_events].delta = 0;
    cnt_events++;

    qsort(events, cnt_events, sizeof(Event), cmp_event);

    int merged_count = 0;
    Event *merged = (Event*) malloc(sizeof(Event) * cnt_events);
    merged[0] = events[0];
    for (int i = 1; i < cnt_events; i++){
        if(events[i].pos == merged[merged_count].pos) {
            merged[merged_count].delta += events[i].delta;
        } else {
            merged_count++;
            merged[merged_count] = events[i];
        }
    }
    merged_count++;  

    ll current_val = 0;
    ll max_diff = -1000000000000000000LL; 
    ll count_diff = 0;

    for (int i = 0; i < merged_count - 1; i++){
        current_val += merged[i].delta;

        ll seg_start = merged[i].pos;
        ll seg_end = merged[i+1].pos - 1;
        if(seg_start > n) break;  
        if(seg_end > n) seg_end = n;

        ll seg_length = seg_end - seg_start + 1;
        if(seg_length <= 0) continue;

        if(current_val > max_diff){
            max_diff = current_val;
            count_diff = seg_length;
        } else if(current_val == max_diff){
            count_diff += seg_length;
        }
    }

    ll max_gifts = base + max_diff;
    printf("%" PRId64 " %" PRId64 "\n", max_gifts, count_diff);

    free(events);
    free(merged);
    return 0;
}