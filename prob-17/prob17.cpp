#include <cstdio>

using namespace std;

int main() {
	int count = 0;
	int num = 1;
	int save;

	while ( num < 1000 ) {
		if ( num < 10 ) {
			if ( num == 1 || num == 2 || num == 6 ) {
				count += 3;
			}
			if ( num == 3 || num == 7 || num == 8 ) {
				count += 5;
			}
			if ( num == 4 || num == 5 || num == 9 ) {
				count += 4;
			}
		}
		
		if ( num >= 10 && num < 100 ) {
			if ( num == 10 ) {
				count += 3;
			}
			else if ( num < 20 && num > 10 ) {
				if ( num == 11 || num == 12 ) {
					count += 6;
				}
				if ( num == 13 || num == 14 || num == 18 || num == 19 ) {
					count += 8;
				}
				if ( num == 15 || num == 16 ) {
					count += 7;
				}
				if ( num == 17 ) {
					count += 9;
				}
			}
			else if ( num == 20 || num == 30 || num == 80 || num == 90 ) {
				count += 6;
			}
			else if ( num == 40 || num == 50 || num == 60 ) {
				count += 5;
			}
			else if ( num == 70 ) {
				count += 7;
			}
			else {
				if ( num / 10 == 2 || num / 10 == 3 || num / 10 == 8 || num / 10 == 9 ) {
					count += 6;
				}
				if ( num / 10 == 4 || num / 10 == 5 || num / 10 == 6 ) {
					count += 5;
				}
				if ( num / 10 == 7 ) {
					count += 7;
				}
				if ( num % 10 == 1 || num % 10 == 2 || num % 10 == 6 ) {
					count += 3;
				}
				if ( num % 10 == 3 || num % 10 == 7 || num % 10 == 8 ) {
					count += 5;
				}
				if ( num % 10 == 4 || num % 10 == 5 || num % 10 == 9 ) {
					count += 4;
				}
			}
		}

		if ( num >= 100 ) {
			if ( num == 100 || num == 200 || num == 600 ) {
				count += 10;
			}
			else if ( num == 300 || num == 700 || num == 800 ) {
				count += 12;
			}
			else if ( num == 400 || num == 500 || num == 900 ) {
				count += 11;
			}
			else {
				if ( num / 100 == 1 || num / 100 == 2 || num / 100 == 6) {
					count += 13;
				}
				else if ( num / 100 == 4 || num / 100 == 5 || num / 100 == 9 ) {
					count += 14;
				}
				else if ( num / 100 == 7 || num / 100 == 8 || num / 100 == 3 ) {
					count += 15;
				}
				save = num % 100;
				if ( save < 10 ) {
					if ( save == 1 || save == 2 || save == 6 ) {
						count += 3;
					}
					if ( save == 3 || save == 7 || save == 8 ) {
						count += 5;
					}
					if ( save == 4 || save == 5 || save == 9 ) {
						count += 4;
					}
				}
				else if ( save == 10 ) {
					count += 3;
				}
				else if ( save < 20 && save > 10 ) {
					if ( save == 11 || save == 12 ) {
						count += 6;
					}
					if ( save == 13 || save == 14 || save == 18 || save == 19 ) {
						count += 8;
					}
					if ( save == 15 || save == 16 ) {
						count += 7;
					}
					if ( save == 17 ) {
						count += 9;
					}
				}
				else if ( save == 20 || save == 30 || save == 80 || save == 90 ) {
					count += 6;
				}
				else if ( save == 40 || save == 50 || save == 60 ) {
					count += 5;
				}
				else if ( save == 70 ) {
					count += 7;
				}
				else {
					if ( save / 10 == 2 || save / 10 == 3 || save / 10 == 8 || save / 10 == 9 ) {
						count += 6;
					}
					if ( save / 10 == 4 || save / 10 == 5 || save / 10 == 6 ) {
						count += 5;
					}
					if ( save / 10 == 7 ) {
						count += 7;
					}
					if ( save % 10 == 1 || save % 10 == 2 || save % 10 == 6 ) {
						count += 3;
	 				}
					if ( save % 10 == 3 || save % 10 == 7 || save % 10 == 8 ) {
						count += 5;
					}
				 	if ( save % 10 == 4 || save % 10 == 5 || save % 10 == 9 ) {
				 		count += 4;
				 	}
				}			
			}
		}
		++num;
	}
	count += 11;
	printf( "%d\n", count );
}
