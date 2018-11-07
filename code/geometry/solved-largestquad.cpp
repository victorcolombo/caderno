/* There are n points in the plane. Find the largest area of a quadrilateral with vertices in four of the given points. The quadrilateral should not have self-intersections. */
int convex_hull (vec * v, int n, int border_in) { // nlg | border_in (should border points stay?)
	swap(v[0], *min_element(v,v+n)); int s, i;
	sort(v+1, v+n, [&v] (vec a, vec b) { int o = b.ccw(v[0], a); return (o?o==1:v[0].sq(a)<v[0].sq(b)); });
	if (border_in) {
		for (s = n-1; s > 1 && v[s].ccw(v[s-1],v[0]) == 0; s--);
		reverse(v+s, v+n);
	}
	for (i = s = 0; i < n; i++) if (!s || !(v[s-1] == v[i])) {
		for (; s >= 2 && v[s-1].ccw(v[s-2],v[i]) >= border_in; s--);
		swap(v[s++],v[i]);
	}
	return s;
}//$

pii antipodal (vec * p, int n, vec v, int md) { // lg(n) | extreme segments relative to direction v TODO
	// po: closest to dir, ne: furthest from dir
	bool sw = ((p[1]-p[0])*v < 0);
	if (sw) v = vec(0,0) - v; // lower_bound returns the first such that lambda is false
	//int md = lower_bound(p+1, p+n, v, [p] (vec & a, vec v) { return (a-p[0])*v > eps; }) - p; // chain separation
	int po = lower_bound(p, p+md-1, v, [p,n] (vec & a, vec v) { return (p[(&a+1-p)%n]-a)*v > eps; }) - p; // positive
	int ne = (lower_bound(p+md, p+n, v, [p,n] (vec & a, vec v) { return (p[(&a+1-p)%n]-a)*v <= eps; }) - p)%n; // negative
	if (sw) swap(po,ne);
	return pii(po,ne);
}//$

const int N = 10123;
int n;
vec v[N], p[N];

int main () {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &v[i].x, &v[i].y);
		p[i] = v[i];
	}
	int m = convex_hull(p, n, 0);

	ll r = 0;
	if (m == 3) {
		ll base = p[0].cross(p[1],p[2]);
		for (int i = 3; i < n; i++)
			for (int j = 0; j < 3; j++) 
				r = max(r, base - abs(p[i].cross(p[j],p[(j+1)%3])));
	} else {
		for (int i = 0; i < m; i++) p[i+m] = p[i];
		for (int i = 0; i < m; i++)
			for (int j = i+1; j < m; j++) {
				pii rr = antipodal(p+i, m, (p[j]-p[i]).rot90(), j-i);
				vec a = p[rr.first+i], b = p[rr.second+i];
				if (a.ccw(p[i],p[j])*b.ccw(p[i],p[j]) != -1) continue;
				r = max(r, abs(a.cross(p[i],p[j])) + abs(b.cross(p[i],p[j])));
			}
	}
	printf("%lld.%lld\n", r/2, 5*(r%2));
}