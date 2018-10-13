#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define debug printf("--%d--\n", __LINE__)

using namespace std;
using namespace std::chrono;
system_clock::time_point t0;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef tuple<double, int, int, int> tdiii;
typedef tuple<double, int, int> tdii;
typedef tuple<int, int, int> tiii;
typedef tuple<int, int> tii;
typedef vector<tii> vtii;

typedef short v_t;
typedef short p_t;

template<typename T> string to_string(const vector<T> &x){stringstream ss; for(int i=0;i<x.size();i++) ss << (i==0 ? "[" : ", ") << x[i]; ss << "]"; return ss.str();}

int tmp, tmp2;


//読み込んだら変化しないものたち
int N, M, L, E, F;
bool w[500][500];
short deg[500];
vector<vector<v_t> > vlist(500);
vector<vector<p_t> > plist(3600);

//答え
vector<vector<p_t> > vp(500);
vector<v_t> pv(3600);


//セグメントグラフ
typedef short s_t;
vector<vector<s_t> > slist(500);
bool s[500][500];
vector<vector<p_t> > segmentPosition(500);
//割り当て
vector<v_t> sv(500);
vector<s_t> vs(500);
int score;

//ベスト割り当て
vector<s_t> bestVs(500);
int bestScore;



double drand(){
	return (0.0 + rand())/RAND_MAX;
}
int calculateScoreByVS(){
	//セグメントグラフへの割り当て情報からスコアを計算
	int ret = 5000;
	bool perfect = true;
	for(int i=0;i<N;i++){
		for(int j=0;j<vlist[i].size();j++){
			int i2 = vlist[i][j];
			if (i > i2) continue;
			if (s[vs[i]][vs[i2]]) ret += 100; else perfect = false;
		}
		ret -= (segmentPosition[vs[i]].size() - 1);
	}
	if (perfect) ret += 100000;
	return ret;
}

int elapsedTime(){
	return duration_cast<milliseconds>(system_clock::now() - t0).count();
}
int kingDistance(p_t p1, p_t p2){
	int r1 = p1/L, c1 = p1%L;
	int r2 = p2/L, c2 = p2%L;
	return max(abs(r1-r2), abs(c1-c2));
}

p_t randomVacantPosition(){
	vector<p_t> vac; for(int i=0;i<M;i++) if (pv[i]==-1) vac.pb(i);
	return vac[rand()%vac.size()];
}

void put(v_t v, p_t p){
	vp[v].pb(p);
	pv[p] = v;
	return;
}
void putClique(int x0, int y0, const vector<v_t> &vs){
	//#vs >= 3の時、1辺 (#vs - 1) の正方形領域にサイズ #vs のクリークを展開する
	//(#vs <= 2の時は、1辺 #vs の正方形領域にクリークを展開します)
	int n = vs.size();
	if (n <= 2){
		for(int i=0;i<n;i++) put(vs[i], x0+i+y0*L);
	}else{
		for(int i=0;i<n-1;i++){
			int x = x0 + 1, y = y0 + i, dy = 1 - (i%2)*2;
			for(int j=0;j<n-2;j++){
				put(vs[i], x+y*L);
				x++; y+=dy;
				if (y < y0) {y = y0; dy = 1;}
				else if (y0+n-2 < y) {y = y0+n-2; dy = -1;}
			}
		}
		for(int i=1;i<=max(n-3,1);i++) put(vs[n-1], x0+(y0+i)*L);
	}
	return;
}

vector<p_t> getIXStrand(int x0, int y0, int l, int sid){
	//糸の座標番号を返す 角をサボったりはしない
	assert(l >= 2);
	vector<p_t> ret;
	if (sid==0){
		for(int i=0;i<l;i++) ret.pb(x0+(y0+i)*L); //角をサボったりはしない
	}else{
		int x = x0 + 1, y = y0 + (sid-1), dy = 1 - (sid-1)%2*2;
		for(int j=0;j<l-1;j++){
			ret.pb(x+y*L);
			x++; y+=dy;
			if (y < y0) {y = y0; dy = 1;}
			else if (y0+l-1 < y) {y = y0+l-1; dy = -1;}
		}
	}
	return ret;
}
vector<vector<p_t> > getIXSegments(int x0, int y0, int l, int n){
	//l * l の領域（l+1本の糸からなる、うち1本は長さlで、残りl本は長さl-1）上に、
	//n 個のセグメントを作成し、それらの座標番号を返す
	assert(l >= 2);
	if (l+1 > n) {cerr << "WARNING: l+1 > n, creating redundant segments" << endl;}
	vector<vector<p_t> > ret(n);
	int s = n/(l+1), r = n%(l+1); //前半 r 本の糸には s+1 セグメントあり、残りの糸には s セグメントある
	int offs = 0;
	for(int i=0;i<l+1;i++){
		vector<p_t> strand = getIXStrand(x0, y0, l, i);
		//cerr << "strand: " << to_string(strand) << endl;
		int numSegment = ((i<r) ? s+1 : s);
		if (numSegment == 0) break;
		int minorSegmentSize = strand.size() / numSegment; // 100/13 == 7
		int numMajorSegment = strand.size() % numSegment; // 100%13 == 9   => 8*9 + 7*4 == 100
		int strandOffs = 0;
		for(int j=0;j<numSegment;j++){
			int segmentSize = ((j < numMajorSegment) ? minorSegmentSize+1 : minorSegmentSize); // 8 or 7
			for(int k=0;k<segmentSize;k++){
				ret[offs+j].pb(strand[strandOffs]);
				strandOffs++;
			}
		}
		offs += numSegment;
	}
	return ret;
}
void putIX(int x0, int y0, int l, const vector<v_t> &vs){
	//l * l の領域（l+1本の糸からなる、うち1本は長さlで、残りl本は長さl-1）に頂点を配置していく
	assert(l >= 2);
	vector<vector<p_t> > segments = getIXSegments(x0, y0, l, vs.size());
	for(int i=0;i<segments.size();i++){
		for(int j=0;j<segments[i].size();j++){
			put(vs[i], segments[i][j]);
		}
	}
	return;
}




int deltaSwapVertex(v_t v1, v_t v2){
	s_t s1 = vs[v1], s2 = vs[v2];
	int delta = 0;
	for(int i=0;i<slist[s1].size();i++){
		s_t q = slist[s1][i];
		if (sv[q]!=-1 && sv[q]!=v2) delta += (int)(w[sv[q]][v2]) - (int)(w[sv[q]][v1]);
	}
	for(int i=0;i<slist[s2].size();i++){
		s_t q = slist[s2][i];
		if (sv[q]!=-1 && sv[q]!=v1) delta += (int)(w[sv[q]][v1]) - (int)(w[sv[q]][v2]);
	}
	return delta * 100;
}
void swapVertex(v_t v1, v_t v2){
	s_t s1 = vs[v1], s2 = vs[v2];
	swap(vs[v1], vs[v2]); swap(sv[s1], sv[s2]);
	return;
}




int main(void){
	t0 = system_clock::now();
	srand(114514);
	scanf("%d %d", &N, &E);
	for(int i=0;i<E;i++){
		scanf("%d %d", &tmp, &tmp2);
		w[tmp-1][tmp2-1] = true;
		w[tmp2-1][tmp-1] = true;
		deg[tmp-1]++;
		deg[tmp2-1]++;
		vlist[tmp-1].pb(tmp2-1);
		vlist[tmp2-1].pb(tmp-1);
	}
	scanf("%d %d", &M, &F);
	for(int i=0;i<F;i++){
		scanf("%d %d", &tmp, &tmp2);
		plist[tmp-1].pb(tmp2-1);
		plist[tmp2-1].pb(tmp-1);
	}
	L = (int)sqrt(M);
	assert(L*L==M);
	for(int i=0;i<M;i++) pv[i] = -1;



	if (N <= L+1){ //完全グラフが作れるケース
		vector<v_t> all(N); for(int i=0;i<N;i++) all[i] = i;
		putClique(0, 0, all);
	}else{
		//とりあえず、クリークで埋めるか
		/*
		if (0){ //小さなクリークをいっぱい作る
			int d = 2;
			for(;;d++){ //サイズ d のクリーク ((d-1)*(d-1)の場所を取る) で全体を埋めたら N 頂点確保できるか
				if ( d * (L/(d-1)) * (L/(d-1)) < N ) {d--; break;}
			}
			//cerr << "d = " << d << endl;
			assert(d >= 2);
			if (d==2){
				for(int i=0;i<N;i++) vp[i].pb(i); //並べるだけ
			}else{
				int c = L/(d-1); //クリークを、横にcまい、縦にcまい展開できる
				for(int i=0;;i++){
					if (d*i>=N) break;
					vector<v_t> vs;
					for(int j=d*i;j<min(d*i+d,N);j++){
						vs.pb(j);
					}

					int x0 = i%c * (d-1), y0 = i/c * (d-1);
					putClique(x0, y0, vs);
				}
			}
		}else if (0){//(2 * E < 0.1 * N * N){ //大きなクリーク1つと、あとはランダムに置く、これはどうだろう
			//この条件式はもっと理論的に改善できうるかも
			int d = 2;
			for(;;d++){
				if (d + M-(d-1)*(d-1) < N) {d--; break;}
			}
			assert(d >= 2);
			//次数ランキングを作成
			vector<pair<short, v_t> > degRank;
			for(int i=0;i<N;i++) degRank.pb(mp(deg[i], i));
			sort(degRank.begin(), degRank.end(), greater<pair<short, v_t> >());

			vector<v_t> vs; for(int i=0;i<min(d,N);i++) vs.pb(degRank[i].second);
			putClique(0, 0, vs);
			for(int i=d;i<N;i++){
				put(degRank[i].second, randomVacantPosition());
			}
		}else if (0){ // 一つの IX 構造に全頂点を乗せてしまおう
			vector<v_t> all(N); for(int i=0;i<N;i++) all[i] = i;
			putIX(0, 0, min(L,N-1), all);
		}else{*/ // 一つの IX 構造に全頂点を乗せてしまい、焼きなます
			segmentPosition = getIXSegments(0, 0, min(L,N-1), N);
			int scnt = 0;
			//slist[]とs[][]を埋める
			for(int i=0;i<N;i++){
				vector<p_t> s1 = segmentPosition[i];
				for(int j=0;j<i;j++){ //セグメント i と j の関係を見る
					vector<p_t> s2 = segmentPosition[j];
					bool connected = false;
					for(int k=0;k<s1.size();k++){
						for(int l=0;l<s2.size();l++){
							if (kingDistance(s1[k], s2[l]) == 1){
								connected = true; break;
							}
						}if (connected) break;
					}
					if (connected){
						slist[i].pb(j); slist[j].pb(i);
						s[i][j] = true; s[j][i] = true; scnt++;
					}
				}
			}
			//cerr << "L == " << L << ", scnt == " << scnt << endl;

			//vs, svを作成
			for(int i=0;i<N;i++) {vs[i] = i; sv[i] = i;}
			score = calculateScoreByVS();
			bestVs = vs; bestScore = score;
			cerr << "initial score: " << score << endl;

			//vsを焼き鈍す score もオンラインアップデートする
			for(int step=0;;step++){
				double temp = 0.1;

				//まずはシンプルなスワッピング
				int i1 = rand()%N; int i2 = (i1 + 1 + rand()%(N-1))%N;
				int delta = deltaSwapVertex(i1, i2);
				//cerr << "delta: " << delta << endl;
				double accProb = exp(delta / temp);
				if (drand() < accProb){
					swapVertex(i1, i2);
					score += delta;

					if (bestScore < score){
						bestScore = score;
						//cerr << "bestScore: " << bestScore << endl;
						bestVs = vs;
					}
				}
				if (step % 1000 == 0 && elapsedTime() > 1900) break;
			}
			cerr << "best score: " << bestScore << endl;


			//bestVsからvpを作成
			for(int i=0;i<N;i++){
				for(int j=0;j<segmentPosition[bestVs[i]].size();j++){
					put(i, segmentPosition[bestVs[i]][j]);
				}
			}

		//}
	}


	//vpの中身を出力
	for(int i=0;i<N;i++){
		printf("%d", vp[i].size());
		for(int j=0;j<vp[i].size();j++){
			printf(" %d", 1+vp[i][j]);
		}
		printf("\n");
	}

	return 0;
}
