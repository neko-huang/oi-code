// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <Licenses - GNU Project - Free Software Foundation>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

 // 17.4.1.2 Headers

 // C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
int dabi, zan, circle, square, dd, dz, dc, ds, ji, li, dun, didun, ding;
int sz, sd, disd, disz; //生产器
int chao, wshan; //记闪与超闪
int b;
int c; //以免不时之需
double sh, dsh, molian, duishou;
int i = 0;
int yu, jing, dyy, djj; //宇宙大爆炸和京城大暴雪
int wkshi, wkong, dkshi, dkong; //空
int diy, didi, yuan, dian; //元素盾，闪电盾
int wpoy, wpof, dpoy, dpof;
int yyy, fff;
void pan0(int a, int b, int k, int y, int c, int d, int yu, int jing) {
	cout << "0 大臂 1 攒 2 圆遁 3 方遁 4 闪 5 超闪 ";
	if (a >= 1) {
		cout << "6 刀 ";
	}
	if (a >= 2) {
		cout << "7 连刀 ";
	}
	if (a >= 3) {
		cout << "8 大砍刀 ";
	}
	if (a >= 4) {
		cout << "9 青龙偃月刀 ";
	}
	if (b >= 1) {
		cout << "10 ber ";
	}
	if (b >= 2) {
		cout << "11 海浪 ";
	}
	if (b >= 3) {
		cout << "12 海啸 ";
	}
	if (b >= 4) {
		cout << "13 惊涛骇浪 ";
	}
	if (a >= 1 && b >= 1) {
		cout << "14 锤 ";
	}
	if (a >= 2 && b >= 2) {
		cout << "15 锤锤 ";
	}
	if (a >= 3 && b >= 3) {
		cout << "16 锤锤锤 ";
	}
	if (a - c >= 2) {
		cout << "17 大臂的小型生产器 ";
	}
	if (a - c >= 4) {
		cout << "18 大臂的大型生产器 ";
	}
	if (b - d >= 2) {
		cout << "19 攒的小型生产器 ";
	}
	if (b - d >= 4) {
		cout << "20 攒的大型生产器 ";
	}
	if (a >= 20) {
		cout << "21 宇宙大爆炸 ";
	}
	if (b >= 20) {
		cout << "22 京城大暴雪 ";
	}
	if (yu == 1) {
		cout << "99 横扫全屏 ";
	}
	if (jing == 1) {
		cout << "100 清扫全屏 ";
	}
	if (k >= 1) {
		cout << "23 脚 ";
	}
	if (k >= 2) {
		cout << "24 连脚 ";
	}
	if (k >= 3) {
		cout << "25 三连脚 ";
	}
	if (k >= 3 && a >= 1) {
		cout << "26 雷劈 ";
	}
	if (k >= 9 && a >= 3) {
		cout << "27 大雷劈 ";
	}
	if (k >= 1 && chao >= 1) {
		cout << "28 元素盾 ";
	}
	if (y >= 1) {
		cout << "29 拳 ";
	}
	if (y >= 2) {
		cout << "30 连拳 ";
	}
	if (y >= 3) {
		cout << "31 三连拳 ";
	}
	if (y >= 1 && k >= 1) {
		cout << "32 拳打脚踢 ";
	}
	if (y >= 2 && k >= 2) {
		cout << "33 连拳连脚 ";
	}
	if (y >= 3 && k >= 3) {
		cout << "34 三连拳三连脚 ";
	}
	if (i <= 5) {
		cout << "999 元辅刀 ";
	}
	cout << endl;
}
int pan1(int a) {
	if (a == 5) {
		if (ding == 0) {
			ding = 1;
			chao++;
			dun += 10;
		}
		else {
			if (chao >= 2) {
				wshan = 0;
				chao -= 2;
				ding = 0;
				cout << "玩家使用超闪之力" << endl;
				dun += 10;
			}
			else {
				cout << "自暴自弃卒一根" << endl;
				exit(0);
			}
		}
	}
	else {
		ding = 0;
		if (ding == 1 && a == 4) {
			cout << "自暴自弃卒一根" << endl;
			exit(0);
		}
		else if (a == 4) {
			wshan++;
			if (wshan == 3) {
				cout << "自暴自弃卒一根" << endl;
				exit(0);
			}
			dun += 2;
		}
		else {
			wshan = 0;
			if (a == 0) {
				return dabi++;
			}
			else if (a == 1) {
				return zan++;
			}
			else if (a == 2) {
				dun += 1;
				return circle++;
			}
			else if (a == 3) {
				dun += 1;
				return square++;
			}
			else if (a == 6 && dabi >= 1) {
				wpoy = 1;
				sh = 1;
				return dabi--;
			}
			else if (a == 7 && dabi >= 2) {
				wpoy = 1;
				sh = 2;
				return dabi -= 2;
			}
			else if (a == 8 && dabi >= 3) {
				sh = 3;
				return dabi -= 3;
			}
			else if (a == 9 && dabi >= 4) {
				sh = 4;
				return dabi -= 4;
			}
			else if (a == 10 && zan >= 1) {
				wpof = 1;
				sh = 1;
				return zan--;
			}
			else if (a == 11 && zan >= 2) {
				wpof = 1;
				sh = 2;
				return zan -= 2;
			}
			else if (a == 12 && zan >= 3) {
				sh = 3;
				return zan -= 3;
			}
			else if (a == 13 && zan >= 4) {
				sh = 4;
				return zan -= 4;
			}
			else if (a == 14 && dabi >= 1 && zan >= 1) {
				sh = 2.5;
				return dabi--, zan--;
			}
			else if (a == 15 && dabi >= 2 && zan >= 2) {
				sh = 5;
				return dabi -= 2, zan -= 2;
			}
			else if (a == 16 && dabi >= 3 && zan >= 3) {
				sh = 7.5;
				return dabi -= 3, zan -= 3;
			}
			else if (a == 17 && dabi >= 2) {
				dabi += 2;
				sd += 4;
			}
			else if (a == 18 && dabi >= 4) {
				dabi += 4;
				sd += 8;
			}
			else if (a == 19 && zan >= 2) {
				zan += 2;
				sz += 4;
			}
			else if (a == 20 && zan >= 4) {
				zan += 4;
				sz += 8;
			}
			else if (a == 21 && dabi >= 20) {
				cout << "玩家使用宇宙大爆炸回合无敌" << endl;
				dabi -= 20;
				yu = 1;
				dun += 10000;
			}
			else if (a == 22 && zan >= 20) {
				jing = 1;
				cout << "玩家使用京城大暴雪回合无敌" << endl;
				zan -= 20;
				dun += 10000;
			}
			else if (a == 99 && yu == 1) {
				cout << "玩家横扫全屏" << endl;
				sh = 10000;
			}
			else if (a == 100 && jing == 1) {
				cout << "玩家清扫全屏" << endl;
				sh = 9999;
			}
			else if (a == 23 && circle >= 1) {
				wpof = 1;
				circle--;
				sh += 0.8;
			}
			else if (a == 24 && circle >= 2) {
				wpof = 1;
				circle -= 2;
				sh += 1.6;
			}
			else if (a == 25 && circle >= 3) {
				wpof = 1;
				circle -= 3;
				sh += 2.4;
			}
			else if (a == 26 && circle >= 3 && dabi >= 1) {
				circle -= 3;
				dabi--;
				sh += 8;
			}
			else if (a == 27 && circle >= 3 && dabi >= 3) {
				circle -= 9;
				dabi -= 3;
				sh += 15;
			}
			else if (a == 28 && circle >= 1 && chao >= 1) {
				chao--;
				circle--;
				yuan++;
			}
			else if (a == 29 && square >= 1) {
				wpoy = 1;
				square--;
				sh += 0.8;
			}
			else if (a == 30 && square >= 2) {
				wpoy = 1;
				square -= 2;
				sh += 1.6;
			}
			else if (a == 31 && square >= 3) {
				wpoy = 1;
				square -= 3;
				sh += 2.4;
			}
			else if (a == 32 && square >= 1 && circle >= 1) {
				square--;
				circle--;
				sh += 2;
			}
			else if (a == 33 && square >= 2 && circle >= 2) {
				square -= 2;
				circle -= 2;
				sh += 4;
			}
			else if (a == 34 && square >= 3 && circle >= 3) {
				square -= 3;
				circle -= 3;
				sh += 6;
			}
			else if (a == 999 && i <= 5) {
				sh = 0.1;
			}
			else {
				cout << "自暴自弃卒一根" << endl;
				exit(0);
			}
		}
	}

}
void n0() {
	if (i == 1) {
		dd++;
		cout << "电脑使用大臂" << endl;
	}
	else if (i == 2) {
		dz++;
		cout << "电脑使用攒" << endl;
	}
	else if (i == 3) {
		didun = 2;
		cout << "电脑使用闪" << endl;
	}
	else if (i == 4) {
		dsh = 2.5;
		dz--;
		dd--;
		cout << "电脑使用锤" << endl;
	}
	else if ((i % 5 == 0 || i % 11 == 0) && i != 5) {
		if (dd >= 4) {
			cout << "电脑使用青龙偃月刀" << endl;
			dd -= 4;
			dsh = 4;
		}
		else if (dz >= 4) {
			cout << "电脑使用惊涛骇浪" << endl;
			dz -= 4;
			dsh = 4;
		}
		else {
			cout << "电脑使用超闪" << endl;
			didun += 10;
		}
	}
	else if (i % 3 == 0) {
		b = rand() % 2;
		if (b == 1) {
			dd++;
			cout << "电脑使用大臂" << endl;
		}
		else {
			dz++;
			cout << "电脑使用攒" << endl;
		}
	}
	else if (i % 3 == 1) {
		b = rand() % 7;
		if (b == 1 && b == 2) {
			if (dd >= 1) {
				dd--;
				dsh = 1;
				cout << "电脑使用刀" << endl;
				dpoy = 1;
			}
			else if (dz >= 1) {
				dz--;
				dsh = 1;
				cout << "电脑使用ber" << endl;
				dpof = 1;
			}
		}

		else {
			if ((dd - disd) >= 2) {
				cout << "电脑使用大臂的小型生产器" << endl;
				dd += 2;
				disd += 4;
			}
			else if ((dz - disz) >= 2) {
				cout << "电脑使用攒的小型生产器" << endl;
				dz += 2;
				disz += 4;
			}
			else {
				didun += 2;
				cout << "电脑使用闪" << endl;
			}
		}

	}
	else {
		if (dd >= 1 && dz >= 1) {
			dsh += 2.5;
			dd--, dz--;
			cout << "电脑使用锤" << endl;
		}
		else if ((dd - disd) >= 4) {
			cout << "电脑使用大逼的大型生产器" << endl;
			dd += 4;
			disd += 8;
		}
		else if ((dz - disz) >= 4) {
			cout << "电脑使用攒的大型生产器" << endl;
			dz += 4;
			disz += 8;
		}
		else {
			didun += 2;
			cout << "电脑使用闪" << endl;
		}
	}

}
void n1() {
	if (((dabi == 2 && dd <= 1) || (zan == 2 && dz <= 1)) && i != 1) {
		cout << "电脑使用闪" << endl;
		didun += 2;
	}
	else if ((dabi >= 4 || zan >= 4 || (dabi >= 1 && zan >= 1)) && dz >= 2) {
		dz -= 2;
		cout << "电脑使用海浪" << endl;
		dpof = 1;
		dsh += 2;
	}
	else if ((dabi >= 4 || zan >= 4 || (dabi >= 1 && zan >= 1)) && dd >= 2) {
		dd -= 2;
		cout << "电脑使用连刀" << endl;
		dpoy = 1;
		dsh += 2;
	}
	else if (dabi >= 4 || zan >= 4 || (dabi >= 1 && zan >= 1)) {
		b = rand() % 4;
		if (b != 0 && b != 1) {
			cout << "电脑使用超闪" << endl;
			didun += 4;
		}
		else if (b == 0) {
			cout << "电脑使用大臂" << endl;
			dd++;
		}
		else {
			cout << "电脑使用攒" << endl;
			dz++;
		}
	}
	else if (dabi == 0 && zan < 2 && circle < 2) {
		cout << "电脑使用大臂" << endl;
		dd++;
	}
	else if (zan == 0 && dabi < 2 && circle < 2) {
		cout << "电脑使用攒" << endl;
		dz++;
	}
	else {
		if (dd == 0) {
			cout << "电脑使用大臂" << endl;
			dd++;
		}
		else if (dz == 0) {
			cout << "电脑使用攒" << endl;
			dz++;
		}
		else {
			if (dd == 1 && dabi >= 1 && zan >= 1) {
				cout << "电脑使用闪" << endl;
				didun += 2;
			}
			else if (dd == 1 && dabi >= 1 && zan == 0) {
				cout << "电脑使用刀" << endl;
				dpoy = 1;
				dd--;
				dsh++;
			}
			else if (dd == 1 && dabi == 0 && zan >= 1) {
				cout << "电脑使用刀" << endl;
				dd--;
				dpoy = 1;
				dsh++;
			}
			else if (dz == 1 && dabi >= 1 && zan >= 1) {
				cout << "电脑使用闪" << endl;
				didun += 2;
			}
			else if (dz == 1 && dabi >= 1 && zan == 0) {
				cout << "电脑使用ber" << endl;
				dpof = 1;
				dsh++;
				dz--;
			}
			else if (dz == 1 && dabi == 0 && zan >= 1) {
				cout << "电脑使用ber" << endl;
				dpof = 1;
				dz--;
				dsh++;
			}
			else {
				if (dz >= 1 && dd >= 1) {
					cout << "电脑使用";
					if ((dd >= dz && dz == 1) || (dz >= dd && dd == 1)) {
						cout << "锤";
						dd--;
						dz--;
						dsh += 2.5;
					}
					else if ((dd >= dz && dz == 2) || (dz >= dd && dd == 2)) {
						cout << "锤锤";
						dd -= 2;
						dz -= 2;
						dsh += 5;
					}
					else if ((dd >= dz && dz == 3) || (dz >= dd && dd == 3)) {
						cout << "锤锤锤";
						dd -= 3;
						dz -= 3;
						dsh += 7.5;
					}
					else {
						dsh += 7.5;
						dd -= 3;
						dz -= 3;
						cout << "锤锤锤";
					}
					cout << endl;
				}
				else if (dd == 2) {
					b = rand() % 2;
					if (b == 1) {
						cout << "电脑使用大臂的小型生产器" << endl;
						dd += 2;
						disd += 4;
					}
					else {
						cout << "电脑使用攒" << endl;
						dz++;
					}
				}
				else if (dz == 2) {
					b = rand() % 2;
					if (b == 1) {
						cout << "电脑使用攒的大型生产器" << endl;
						dz += 2;
						disz += 4;
					}
					else {
						cout << "电脑使用大臂" << endl;
						dd++;
					}
				}
				else if (dd == 3) {
					b = rand() % 4;
					if (b != 0) {
						cout << "电脑使用大臂" << endl;
						dd++;
					}
					else {
						cout << "电脑使用大砍刀" << endl;
						dsh += 3;
						dz -= 3;
					}
				}
				else if (dd == 4 && ding == 1) {
					cout << "电脑使用青龙偃月刀" << endl;
					dsh += 4;
					dd -= 4;
				}
				else if (dd - disd == 4 && ding == 0) {
					if (disd == 0) {
						cout << "电脑使用攒的大型生产器" << endl;
						dd += 4;
						disd += 8;
					}
				}
				else if (dd == 4 && ding == 0) {
					b = rand() % 2;
					if (b == 1) {
						cout << "电脑使用超闪" << endl;
						didun += 10;
					}
					else {
						cout << "电脑使用连刀" << endl;
						dpoy = 1;
						dsh += 2;
						dd -= 2;
					}
				}
				else if (dz == 3) {
					b = rand() % 4;
					if (b != 0) {
						cout << "电脑使用攒" << endl;
						dz++;
					}
					else {
						cout << "电脑使用海啸" << endl;
						dsh += 3;
						dz -= 3;
					}
				}
				else if (dz >= 4 && ding == 1) {
					cout << "电脑使用惊涛骇浪" << endl;
					dsh += 4;
					dz -= 4;
				}
				else if (dz - disz == 4 && ding == 0) {
					if (disz == 0) {
						cout << "电脑使用攒的大型生产器" << endl;
						dz += 4;
						disz += 8;
					}
				}
				else if (dz == 4 && ding == 0) {
					b = rand() % 2;
					if (b == 1) {
						cout << "电脑使用超闪" << endl;
						didun += 10;
					}
					else {
						cout << "电脑使用海浪" << endl;
						dpof = 1;
						dsh += 2;
						dz -= 2;
					}
				}
			}
		}
	}
}
void n2() {
	if (i == 1) {
		cout << "电脑使用圆遁" << endl;
		didun++;
		dc++;
	}
	else if (i == 2) {
		cout << "电脑使用圆遁" << endl;
		didun++;
		dc++;
	}
	else if (i == 3) {
		cout << "电脑使用圆遁" << endl;
		didun++;
		dc++;
	}
	else if (i == 4) {
		b = rand() % 2;
		if (b == 1) {
			cout << "电脑使用三连脚" << endl;
			dpoy = 1;
			dc -= 3;
			dsh += 2.4;
		}
		else {
			cout << "电脑使用大臂" << endl;
			dd++;
		}
	}
	else {
		if (i % 4 == 0) {
			cout << "电脑使用圆遁" << endl;
			didun++;
			dc++;
		}
		else if (i % 4 == 1) {
			b = rand() % 2;
			if (b == 1) {
				cout << "电脑使用大臂" << endl;
				dd++;
			}
			else {
				cout << "电脑使用脚" << endl;
				dpoy = 1;
				dsh += 0.8;
				dc--;
			}
		}
		else if (i % 4 == 2) {
			b = rand() % 2;
			if (b == 1) {
				if (dc >= 3 && dd >= 1) {
					cout << "电脑使用雷劈" << endl;
					dsh += 8;
					dc -= 3;
					dd--;
				}
				else if (dc >= 9 && dd >= 3) {
					cout << "电脑使用大雷劈" << endl;
					dsh += 15;
					dc -= 9;
					dd -= 3;
				}
				else {
					cout << "电脑使用大臂" << endl;
					dd++;
				}
			}
			else {

				if (dc < 3) {
					cout << "电脑使用圆遁" << endl;
					didun++;
					dc++;
				}
				else {
					cout << "电脑使用三连脚" << endl;
					dpoy = 1;
					dc -= 3;
					dsh += 2.4;
				}

			}
		}
		else {
			cout << "电脑使用超闪" << endl;
			didun += 10;
		}
	}
}
void nnn() {
	if (dyy == 1) {
		cout << "电脑使用横扫全屏" << endl;
		dsh += 10000;
		dyy = 0;
	}
	else if (djj == 1) {
		cout << "电脑使用清扫全屏" << endl;
		dsh += 9999;
		djj = 0;
	}
	else {
		c = rand() % 115;
		if (c >= 0 && c <= 4) {
			cout << "电脑使用超闪" << endl;
			didun += 10;
		}
		else if (c >= 5 && c <= 26) {
			cout << "电脑使用刀" << endl;
			dsh = 1;
			dpoy = 1;
		}
		else if (c >= 27 && c <= 38) {
			cout << "电脑使用连刀" << endl;
			dsh = 2;
			dpoy = 1;
		}
		else if (c >= 39 && c <= 44) {
			cout << "电脑使用青龙偃月刀" << endl;
			dsh = 4;
		}
		else if (c == 45 || c == 46) {
			cout << "电脑使用宇宙大爆炸回合无敌" << endl;
			didun += 10000;
			dyy = 1;
		}
		else if (c >= 47 && c <= 56) {
			cout << "电脑使用闪" << endl;
			didun += 2;
		}
		else if (c >= 57 && c <= 78) {
			cout << "电脑使用ber" << endl;
			dpof = 1;
			dsh++;
		}
		else if (c >= 79 && c <= 90) {
			cout << "电脑使用海浪" << endl;
			dpof = 1;
			dsh += 2;
		}
		else if (c >= 91 && c <= 96) {
			cout << "电脑使用惊涛骇浪" << endl;
			dsh += 4;
		}
		else if (c == 97 || c == 98) {
			cout << "电脑使用京城大暴雪回合无敌" << endl;
			djj = 1;
			didun += 10000;
		}
		else {
			cout << "电脑使用元辅刀" << endl;
			dsh += 0.1;
		}
	}

}
int main() {
	srand((unsigned)time(NULL));
	molian = 2, duishou = 2;
	int a = 0;
	ding = 0;
	wshan = 0;
	while (a != 1 && a != 2) {
		cout << "1 战斗 2 电脑开挂模式 3 大事祭" << endl;
		cin >> a;
		if (a == 3) {
			cout << "12.4号开始建" << endl << endl;
			cout << "1.0版本12.6号建成" << endl << endl;
			cout << "2.0版本12.7号建成" << endl << endl;
			cout << "2.0版本增强了电脑" << endl << endl;
			cout << "2.0版本增加了超闪，生产器，还修复了3闪不会g的问题！" << endl << endl;
			cout << "2.1版本12.7号建成" << endl << endl;
			cout << "2.1版本强化了电脑" << endl << endl;
			cout << "2.2版本12.9号建成" << endl << endl;
			cout << "2.2版本增加了电脑的选择情况" << endl << endl;
			cout << "3.0,3.1版本12.10号建成" << endl << endl;
			cout << "3.0版本增强了电脑" << endl << endl;
			cout << "3.0版本增加了宇宙大爆炸，京城大暴雪" << endl << endl;
			cout << "3.1版本修复了依托bug" << endl << endl;
			cout << "4.0版本12.11号建成" << endl << endl;
			cout << "4.0版本增加了圆遁的一系列东西，元辅刀" << endl << endl;
			cout << "5.0版本12.12号建成" << endl << endl;
			cout << "5.0版本增加了新模式和除了闪电盾以外的东西" << endl << endl;
		}
		if (a != 2 && a != 1 && a != 3) {
			cout << "你按这个干啥？？？？？" << endl;
		}
	}
	if (a == 1) {
		cout << "重新开始" << endl;
		chao = 0;
		wshan = 0;
		wkshi = 0;
		wkong = 0;
		for (i = 1;; i++) {
			if (i == 1) {
				c = rand() % 3;
			}
			if (wkshi == 0) {
				wkong = 0;
				pan0(dabi, zan, circle, square, sd, sz, yu, jing);
				cin >> a;
				pan1(a);
				if (dkshi != 0) {
					dkong = 0;
					if (c == 1) {
						n0();
					}
					else if (c == 0) {
						n1();
					}
					else {
						n2();
					}
				}
				else {
					dkshi--;
					dkong = 1;
				}
			}
			else {
				wkshi--;
				wkong = 1;
			}
			if ((a == 2 && dpoy == 1) || (a == 3 && dpof == 1)) {
				dsh += 1;
			}
			if ((yyy == 1 && wpoy == 1) || (fff == 1 && wpof == 1)) {
				sh += 1;
			}
			if (a == 26 && diy >= 1) {
				diy--;
				wkshi = 8;
				cout << "掉一个元素盾空八个回合继续打啦" << endl;
				dsh = 0;
				wkong = 1;
			}
			if (a == 27 && diy >= 3) {
				diy -= 3;
				wkshi = 15;
				cout << "掉三个元素盾空十五个回合继续打啦" << endl;
				dsh = 0;
				wkong = 1;
			}
			if (sh <= dsh) {
				if (dun < dsh - sh) {
					molian -= (dsh - sh - dun);
					cout << "掉" << dsh - sh - dun << "个磨练";
					if (molian < 1) {
						cout << "卒一根" << endl;
						break;
					}
					else {
						cout << "继续打啦" << endl;
					}
				}
			}
			else {
				if (didun < sh - dsh) {
					duishou -= (sh - dsh - didun);
					cout << "电脑掉" << sh - dsh - didun << "个磨练";
					if (duishou < 1) {
						cout << "卒一根" << endl;
						break;
					}
					else {
						cout << "继续打啦" << endl;
					}
				}
			}
			dun = 0;
			dsh = 0;
			didun = 0;
			sh = 0;
			dpoy = 0;
			dpof = 0;
			wpoy = 0;
			wpof = 0;
		}
	}
	else {
		cout << "1 教学 2 开打！！" << endl;
		a = 0;
		while (a != 2) {
			cin >> a;
			if (a == 1) {
				cout << "这个模式，电脑只会出元辅刀，闪，超闪，连刀，青龙偃月刀，宇宙大爆炸，横扫全屏，ber，海浪，惊涛骇浪，京城大暴雪，清扫全屏" << endl;
				cout << "你是正常的" << endl;
				cout << "电脑可以随便出攻击，你需要防守并击败电脑" << endl;
				cout << "电脑有8点血，你有两点" << endl << endl << endl;
				break;
			}
			if (a != 1 && a != 2) {
				cout << "你按这个干啥？？？？？" << endl;
			}
		}
		cout << "重新开始" << endl;
		dian = 0;
		didi = 0;
		chao = 0;
		wshan = 0;
		molian = 2;
		duishou = 8;
		dun = 0;
		didun = 0;
		for (int i = 1;; i++) {
			pan0(dabi, zan, circle, square, sd, sz, yu, jing);
			cin >> a;
			pan1(a);
			nnn();
			if ((a == 2 && dpoy == 1) || (a == 3 && dpof == 1)) {
				dsh += 1;
			}
			if (sh <= dsh) {
				if (dun < dsh - sh) {
					molian -= (dsh - sh - dun);
					cout << "掉" << dsh - sh - dun << "个磨练";
					if (molian < 1) {
						cout << "卒一根" << endl;
						exit(0);
					}
					else {
						cout << "继续打啦" << endl;
					}
				}
			}
			else {
				if (didun < sh - dsh) {
					duishou -= (sh - dsh - didun);
					cout << "电脑掉" << sh - dsh - didun << "个磨练";
					if (duishou < 1) {
						cout << "卒一根" << endl;
						exit(0);
					}
					else {
						cout << "继续打啦" << endl;
					}
				}
			}
			dpoy = 0;
			dpof = 0;
			sh = 0;
			dsh = 0;
			dun = 0;
			didun = 0;
		}

	}
	return 0;
}