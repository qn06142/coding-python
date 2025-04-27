#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef long long ll;

typedef struct {
    ll x;
} RobotA;

typedef struct {
    ll y;
} RobotB;

typedef struct {
    ll w, s;
} Object;

int cmp_robotA(const void *a, const void *b) {
    RobotA *ra = (RobotA*)a;
    RobotA *rb = (RobotA*)b;
    if(ra->x < rb->x) return -1;
    else if(ra->x > rb->x) return 1;
    else return 0;
}

int cmp_robotB(const void *a, const void *b) {
    RobotB *ra = (RobotB*)a;
    RobotB *rb = (RobotB*)b;
    if(ra->y < rb->y) return -1;
    else if(ra->y > rb->y) return 1;
    else return 0;
}

int cmp_obj_weight(const void *a, const void *b) {
    Object *o1 = (Object*)a;
    Object *o2 = (Object*)b;
    if(o1->w < o2->w) return -1;
    else if(o1->w > o2->w) return 1;
    else return 0;
}

int cmp_obj_size(const void *a, const void *b) {
    Object *o1 = (Object*)a;
    Object *o2 = (Object*)b;
    if(o1->s < o2->s) return -1;
    else if(o1->s > o2->s) return 1;
    else return 0;
}

// --- Global biến dùng chung ---
int n, m, T_total;
RobotA *robotsA = NULL;
RobotB *robotsB = NULL;
 
// Mảng các đồ vật đã phân chia thành 3 nhóm:
Object *groupA = NULL; // A-only: chỉ robot A nhặt được
int cntA = 0;
Object *groupB = NULL; // B-only: chỉ robot B nhặt được
int cntB = 0;
Object *groupBoth = NULL; // Both: cả 2 loại đều nhặt được
int cntBoth = 0;

// Ngoài ra, để giảm thời gian sắp xếp trong kiểm tra, ta lưu sẵn 2 bản của groupBoth: 
// Một sắp theo trọng lượng, một sắp theo kích thước.
Object *groupBoth_weight = NULL;
Object *groupBoth_size = NULL;

// --- Hàm kiểm tra khả thi với T_min (số phút) cho trước ---
bool feasible(ll T_min) {
    int i, j;
    
    // mảng lưu số slot còn lại của mỗi robot (sau khi gán các đồ vật bắt buộc)
    ll *capA = (ll*)malloc(sizeof(ll)*n);
    ll *capB = (ll*)malloc(sizeof(ll)*m);
    for(i = 0; i < n; i++) capA[i] = T_min;
    for(i = 0; i < m; i++) capB[i] = T_min;
    
    // --- 1. Gán nhóm A-only cho robot A ---
    i = 0;
    for(j = 0; j < cntA; j++){
        // Tìm robot A có x > w của đồ vật và còn slot
        while(i < n && (capA[i] == 0 || robotsA[i].x <= groupA[j].w)) {
            i++;
        }
        if(i == n) { 
            free(capA); free(capB);
            return false;
        }
        capA[i]--; // gán đồ vật cho robot i
    }
    
    // --- 2. Gán nhóm B-only cho robot B ---
    i = 0;
    for(j = 0; j < cntB; j++){
        while(i < m && (capB[i] == 0 || robotsB[i].y <= groupB[j].s)) {
            i++;
        }
        if(i == m) { 
            free(capA); free(capB);
            return false;
        }
        capB[i]--;
    }
    
    // --- 3. Gán nhóm Both --- 
    // Ta thử 2 thứ tự: (Order1) gán trước với robot A rồi B, (Order2) ngược lại.
    bool ok = false;
    for (int order = 0; order < 2 && !ok; order++) {
        // Tạo bản sao của capA, capB để thử thứ tự hiện tại.
        ll *tcapA = (ll*)malloc(sizeof(ll)*n);
        ll *tcapB = (ll*)malloc(sizeof(ll)*m);
        for(i = 0; i < n; i++) tcapA[i] = capA[i];
        for(i = 0; i < m; i++) tcapB[i] = capB[i];
        
        int assigned = 0;
        // Mảng tạm lưu các đồ vật chưa được gán
        int *unassigned = (int*)malloc(sizeof(int)*cntBoth);
        int unassignedCount = 0;
        
        if(order == 0) {
            // Order 1: gán với robot A (theo trọng lượng) trước.
            i = 0;
            // Duyệt groupBoth đã sắp theo trọng lượng
            for(j = 0; j < cntBoth; j++){
                // Với mỗi đồ vật, tìm robot A có x > w
                while(i < n && (tcapA[i] == 0 || robotsA[i].x <= groupBoth_weight[j].w)) {
                    i++;
                }
                if(i < n) {
                    tcapA[i]--;
                    assigned++;
                } else {
                    // Không thể gán cho robot A, lưu lại chỉ số để gán với robot B sau.
                    unassigned[unassignedCount++] = j;
                }
            }
            // Với các đồ vật chưa gán, ta sắp theo kích thước (theo groupBoth_size)
            // Lưu ý: ta cần trích xuất các đồ vật chưa gán dựa trên thứ tự ban đầu.
            // Vì groupBoth_weight và groupBoth_size chứa cùng các đồ vật nhưng sắp khác nhau,
            // ta sẽ xây dựng mảng các đồ vật của nhóm Both theo thứ tự kích thước.
            // Ở đây, ta sẽ sử dụng groupBoth_size trực tiếp.
            i = 0;
            for(j = 0; j < unassignedCount; j++){
                // unassigned[j] là chỉ số của đồ vật trong mảng groupBoth_weight,
                // nhưng ta không có thứ tự tương ứng trong groupBoth_size. 
                // Do đó, ta giải quyết bằng cách gán tất cả các đồ vật trong groupBoth theo thứ tự kích thước,
                // rồi gán các đồ vật mà chưa được gán bởi robot A.
                // Cách làm đơn giản: Gán lại toàn bộ groupBoth theo thứ tự kích thước bằng robot B.
                break;
            }
            // Với Order1, ta gán toàn bộ groupBoth với robot B theo thứ tự kích thước.
            i = 0;
            for(j = 0; j < cntBoth; j++){
                while(i < m && (tcapB[i] == 0 || robotsB[i].y <= groupBoth_size[j].s))
                    i++;
                if(i == m) break;
                tcapB[i]--;
                assigned++;
            }
        } else {
            // Order 2: gán với robot B (theo kích thước) trước.
            i = 0;
            for(j = 0; j < cntBoth; j++){
                while(i < m && (tcapB[i] == 0 || robotsB[i].y <= groupBoth_size[j].s))
                    i++;
                if(i < m){
                    tcapB[i]--;
                    assigned++;
                }
            }
            // Sau đó, gán lại toàn bộ groupBoth với robot A theo thứ tự trọng lượng.
            i = 0;
            for(j = 0; j < cntBoth; j++){
                while(i < n && (tcapA[i] == 0 || robotsA[i].x <= groupBoth_weight[j].w))
                    i++;
                if(i == n) break;
                tcapA[i]--;
                assigned++;
            }
        }
        if(assigned >= cntBoth) ok = true;
        free(tcapA);
        free(tcapB);
        free(unassigned);
    }
    
    free(capA);
    free(capB);
    return ok;
}

int main(void){
    int i, j;
    if(scanf("%d %d %d", &n, &m, &T_total) != 3) return 1;
    
    // Đọc dữ liệu robot:
    if(n > 0){
        robotsA = (RobotA*)malloc(sizeof(RobotA)*n);
        for(i = 0; i < n; i++){
            scanf("%lld", &robotsA[i].x);
        }
        qsort(robotsA, n, sizeof(RobotA), cmp_robotA);
    }
    if(m > 0){
        robotsB = (RobotB*)malloc(sizeof(RobotB)*m);
        for(i = 0; i < m; i++){
            scanf("%lld", &robotsB[i].y);
        }
        qsort(robotsB, m, sizeof(RobotB), cmp_robotB);
    }
    
    // Tính maxA, maxB
    ll maxA = 0, maxB = 0;
    if(n > 0) maxA = robotsA[n-1].x;
    if(m > 0) maxB = robotsB[m-1].y;
    
    // Đọc các đồ vật và phân chia thành 3 nhóm
    groupA = (Object*)malloc(sizeof(Object)*T_total);
    groupB = (Object*)malloc(sizeof(Object)*T_total);
    groupBoth = (Object*)malloc(sizeof(Object)*T_total);
    cntA = cntB = cntBoth = 0;
    
    for(i = 0; i < T_total; i++){
        Object obj;
        scanf("%lld %lld", &obj.w, &obj.s);
        // Nếu có cả 2 loại robot:
        if(n > 0 && m > 0){
            bool canA = (obj.w < maxA);
            bool canB = (obj.s < maxB);
            if(!canA && !canB){
                printf("-1\n");
                return 0;
            }
            if(canA && canB){
                groupBoth[cntBoth++] = obj;
            } else if(canA) {
                groupA[cntA++] = obj;
            } else { // canB
                groupB[cntB++] = obj;
            }
        } else if(n > 0){ // chỉ có robot A
            if(obj.w < maxA) {
                groupA[cntA++] = obj;
            } else {
                printf("-1\n");
                return 0;
            }
        } else { // chỉ có robot B
            if(obj.s < maxB) {
                groupB[cntB++] = obj;
            } else {
                printf("-1\n");
                return 0;
            }
        }
    }
    
    // Sắp xếp các nhóm theo thứ tự cần thiết:
    if(cntA > 0)
        qsort(groupA, cntA, sizeof(Object), cmp_obj_weight);
    if(cntB > 0)
        qsort(groupB, cntB, sizeof(Object), cmp_obj_size);
    if(cntBoth > 0){
        // Tạo 2 bản sắp: theo trọng lượng và theo kích thước.
        groupBoth_weight = (Object*)malloc(sizeof(Object)*cntBoth);
        groupBoth_size = (Object*)malloc(sizeof(Object)*cntBoth);
        for(i = 0; i < cntBoth; i++){
            groupBoth_weight[i] = groupBoth[i];
            groupBoth_size[i] = groupBoth[i];
        }
        qsort(groupBoth_weight, cntBoth, sizeof(Object), cmp_obj_weight);
        qsort(groupBoth_size, cntBoth, sizeof(Object), cmp_obj_size);
    }
    
    // --- Binary Search trên thời gian ---
    // Cận dưới: tối thiểu là ceil(T_total/(n+m)) (n+m >=1)
    ll lo = (T_total + (n+m) - 1) / (n+m), hi = T_total, ans = -1;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(feasible(mid)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    if(ans == -1) printf("-1\n");
    else printf("%lld\n", ans);
    
    // Giải phóng bộ nhớ
    if(robotsA) free(robotsA);
    if(robotsB) free(robotsB);
    if(groupA) free(groupA);
    if(groupB) free(groupB);
    if(groupBoth) free(groupBoth);
    if(groupBoth_weight) free(groupBoth_weight);
    if(groupBoth_size) free(groupBoth_size);
    return 0;
}
