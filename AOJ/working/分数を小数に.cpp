#include<stdio.h>

int main(void) {

	int N = 50, d, r, i, j,cnt=1;

	int rr[50], qq[50] = {};//配列の宣言

	r = 1;//　　　　　　　　　　　　　　　　　　1.　ｒ←１

	scanf_s("%d", &d);//　　　　　　　　　　　　２．　ｄ←入力（正整数）

	if (d > r) {//                              ３．ｄ＞ｒならば以下を実行

		printf("0.");//                              �@「０．」と出力
		
		i = 1;//                                     �Ai←１

		j = 0;//　　　　　　　　　　　　　　　　　　�Bｊ←０

		while (r != 0 && j == 0 && i < N) {//       �Cｒ≠０かつｊ＝０かつｉ＜Ｎである限り以下を実行
			
			rr[i] = r;//　　　　　　　　　　　　　　　　　（Ａ）ｒｒ「ｉ」←ｒ

			r *= 10;//　　　　　　　　　　　　　　　　　　（Ｂ）ｒ←ｒ×１０

			qq[i] = r / d;//　　　　　　　　　　　　　　　（Ｃ）ｑｑ「ｉ」← r div d

			r %= d;//                                      （Ｄ）ｒ← r mod d

			j = i;//　　　　　　　　　　　　　　　　　　　（Ｅ）ｊ←ｉ

			while (j != 0&& r != rr[j]) {//　　　　　　　　（Ｆ）ｊ≠０かつｒ≠ｒｒ「ｊ」である限り以下を実行

				j--;//　　　　　　　　　　　　　　　　　　　　　　　　�@ｊ←ｊ−１

			}

			i++;//　　　　　　　　　　　　　　　　　　　　（Ｇ）ｉ←ｉ＋１

		}

		while (cnt < i) {//　　　　　　　　　　　　�D表示　

			printf("%d", qq[cnt++]);
		}
		
	}

	return 0;
}