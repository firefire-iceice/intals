#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

char* intal_add(char* intal1, char* intal2) {
	int i1,i2;
	i1 = strlen(intal1);
	i2 = strlen(intal2);
	int sum, carry = 0;
	char *result;
	if (i1 <= i2) {
		result = malloc(sizeof(char) * (i2 + 2));
		for (int i = 0; i < i1; ++i) {
			sum = intal2[i2 - i - 1] + intal1[i1 - i - 1] - '0' - '0' + carry;
			carry = sum/10;
			result[i2 - i - 1] = sum%10 + '0';
		}
		for (int i = 0; i < (i2 - i1); ++i) {
			sum = intal2[i2 - (i1 + i + 1)] - '0' + carry; 
			carry = sum/10;
			result[i2 - (i1 + i + 1)] = sum%10 + '0';
		}
		result[i2] = '\0';
		if (carry != 0) {
			for (int i = i2; i >= 0; --i) {
				result[i + 1] = result[i];
			}
			result[0] = carry + '0';
		}

		return result;
	} else {
		result = malloc(sizeof(char) * (i1 + 2));
		for (int i = 0; i < i2; ++i) {
			sum =  intal1[i1 - i - 1] + intal2[i2 - i - 1] - '0' - '0' + carry;
			carry = sum/10;
			result[i1 - i - 1] = sum%10 + '0';
		}
		for (int i = 0; i < (i1 - i2); ++i) {
			sum = intal1[i1 - (i2 + i + 1)] - '0' + carry; 
			carry = sum/10;
			result[i1 - (i2 + i + 1)] = sum%10 + '0';
		}
		result[i1] = '\0';
		if (carry != 0) {
			for (int i = i1; i >= 0; --i) {
				result[i + 1] = result[i];
			}
			result[0] = carry + '0';
		}
		return result;
	} 
}

int intal_compare(char* intal1, char* intal2) {
	int i1,i2;
	i1 = strlen(intal1);
	i2 = strlen(intal2);
	if (i1 > i2) {
		return 1;
	} else if (i1 < i2) {
		return -1;
	} else {
		// if (!strcmp(intal1,intal2)) {
		// 	return 0;
		// } 
		for (int i = 0; i < i1; ++i) {
			if (intal1[i] < intal2[i]) {
				return -1;
			} else if (intal1[i] > intal2[i]) {
				return 1;
			}
		}
		//this is to eliminate the useless warning message
		return 0;
	}
}

char* intal_diff(char* int1, char* int2) {
	int compValue = intal_compare(int1, int2);
	int i1,i2;
	i1 = strlen(int1);
	i2 = strlen(int2);
	int diff = 0;
	char *result;
	char *intal1 = malloc(sizeof(char) * (i1 + 1));
	char *intal2 = malloc(sizeof(char) * (i2 + 1));
	strcpy(intal1, int1);
	strcpy(intal2, int2);
	if (compValue == 0) {
		result = malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
		return result;
	} else if (compValue == -1) {
		result = malloc(sizeof(char) * (i2 + 2));
		for (int i = 0; i < i1; ++i) {
			diff = (intal2[i2 - i - 1] - '0') - (intal1[i1 - i - 1] - '0');
			if (diff < 0) {
				diff += 10;
				if (intal2[i2 - i - 2] == '0') {
					int k = 0;
					while (intal2[i2 - i - 2 - k] == '0') {
						intal2[i2 - i - 2 - k] = '9';
						k++;
					}
					intal2[i2 - i - 2 - k] = ((intal2[i2 - i - 2 - k] - '0') - 1) + '0';
				} else {
					intal2[i2 - i - 2] = ((intal2[i2 - i - 2] - '0') - 1) + '0';
				}
			} 
			result[i2 - i - 1] = diff + '0';

		}
		for (int i = 0; i < (i2 - i1); ++i) {
			result[i2 - (i1 + i + 1)] = intal2[i2 - (i1 + 1 + i)];
		}
		result[i2] = '\0';
		int count = 0;
		for (int i = 0; result[i] == '0'; ++i) {
			++count;
		}
		for (int i = 0; i <= i2 - count; ++i) {
			result[i] = result[i + count];
		}
		result[i2 - count + 1] = '\0';
		free(intal1);
		free(intal2);
		return result;
	} else {
		result = malloc(sizeof(char) * (i1 + 2));
		for (int i = 0; i < i2; ++i) {
			diff = (intal1[i1 - i - 1] - '0') - (intal2[i2 - i - 1] - '0');
			if (diff < 0) {
				diff += 10;
				if (intal1[i1 - i - 2] == '0') {
					int k = 0;
					while (intal1[i1 - i - 2 - k] == '0') {
						intal1[i1 - i - 2 - k] = '9';
						k++;
					}
					intal1[i1 - i - 2 - k] = ((intal1[i1 - i - 2 - k] - '0') - 1) + '0';
				} else {
					intal1[i1 - i - 2] = ((intal1[i1 - i - 2] - '0') - 1) + '0';
				}
			} 
			result[i1 - i - 1] = diff + '0';

		}
		for (int i = 0; i < (i1 - i2); ++i) {
			result[i1 - (i2 + i + 1)] = intal1[i1 - (i2 + 1 + i)];
		}
		result[i1] = '\0';
		int count = 0;
		for (int i = 0; result[i] == '0'; ++i) {
			++count;
		}
		for (int i = 0; i <= i1 - count; ++i) {
			result[i] = result[i + count];
		}
		result[i1 - count + 1] = '\0';
		free(intal1);
		free(intal2);
		return result;
	}
}

static int convertToInt(char *s) {
	int len = strlen(s);
	int n = 0;
	for (int i = 0; i < strlen(s); ++i) {
		n *= 10;
		n += s[i] - '0';
	}
	return n;
}

static char *convertToIntal(int n) {
	if (n == 0) {
		char *result = malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
		return result;
	}
	int n1 = n;
	int count = 0;
	while (n >= 1) {
		n = n / 10;
		++count;
	}
	n = n1;
	char *result = malloc(sizeof(char) * (count + 1));
	for (int i = 0; i < count; ++i) {
		result[count - i - 1] = n%10 + '0';
		n = n / 10;
	}
	result[count] = '\0';
	return result;
}

static void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

static char* strrev(char const* str) 
{ 
	int n = strlen(str); 
	char *rev = malloc(sizeof(char) * (n + 1));
	strcpy(rev, str); 
    for (int i=0, j=n-1; i<j; i++,j--) 
		swap(&rev[i], &rev[j]);        
	return rev; 
} 


char* intal_multiply(char* int1, char* int2) {
	int i1, i2, temp;
	i1 = strlen(int1);
	i2 = strlen(int2);
	char *result = malloc(sizeof(char) * (i1 + i2 + 1));
	for (int c = 0; c <= i1 + i2; ++c) {
		result[c] = '0';
	}
	char *intal1 = strrev(int1);
	char *intal2 = strrev(int2);
	if (i1 < i2) {
		int tempnum1;
		char *tempnum2;
		tempnum1 = i1;
		i1 = i2;
		i2 = tempnum1;
		tempnum2 = intal1;
		intal1 = intal2;
		intal2 = tempnum2;
	}
		int count = 0;
		int i = 0;
		int j = 0;
		while (i < i2) {
			int carry = 0;
			j = 0;
			while (j < i1) {
				temp = ((result[j + count] - '0') + (intal2[i] - '0')*(intal1[j] - '0') + carry);
				carry = temp / 10;
				result[j + count] = (temp % 10) + '0';
				++j;
			}
			temp = ((result[j + count] - '0') + carry);
			carry = temp/10;
			result[j + count] = (temp%10) + '0';
			++j;
			if (carry != 0) {
				result[j + count] = carry + '0';
			}
			++i;
			++count;
		}
		result[j + count - 1] = '\0';

		result = strrev(result);
		int p = 0;
		for (int i = 0; result[i] == '0'; ++i) {
			p++;
		}
		for (i = 0; i < (strlen(result) - p); ++i) {
			result[i] = result[i + p];
		}
		
		
		if (result[0] == '0') {
			result[0] = '0';
			result[1] = '\0';
		} else {
			result[i] = '\0';
		}
		free(intal1);
		free(intal2);
		return result;

}

char* intal_mod(char* intal1, char* intal2) {
	int res = intal_compare(intal1, intal2);
	int i1, i2;
	i1 = strlen(intal1);
	i2 = strlen(intal2);
	char *int1 = malloc(sizeof(char) * (i1 + 1));
	char *int2 = malloc(sizeof(char) * (i2 + 1));
	char *temp = malloc(sizeof(char));
	strcpy(int1, intal1);
	strcpy(int2, intal2);
	if (res == 1) {
		// while (((intal_compare(int1, int2)) == 1) || ((intal_compare(int1, int2)) == 0)) {
		// 	int1 = intal_diff(int1, int2);
		// }
		// free(int2);
		// return int1;
		char *prev = NULL;
		// printf("%s %s %d %d\n", int1,int2,i1,i1 - 1 - (i2 - 1));
		int2 = intal_multiply(int2, intal_pow(convertToIntal(10),convertToIntal(i1 - 1 - (i2 - 1) - 1)));
		// printf("%s %s\n", int1,int2);
		int i = 0;
		while (intal_compare(int1, int2) == 1) {
			// printf("rofl:%s %s\n", int1, int2);
			free(temp);
			temp = int2;
			int2 = intal_add(int2, int2);
		}
		prev = int2;
		int2 = intal_diff(int2, temp);
		free(prev);
		free(temp);
		temp = intal_diff(int1, int2);
		prev = intal_mod(temp, intal2);
		free(temp);
		free(int1);
		free(int2);
		return prev;
		// while (intal_compare(int1, int2) == 1) {
		// 	printf("rofl1:%s %s\n", int1, int2);
		// 	temp = int2;
		// 	int2 = intal_add(int2, intal2);
		// 	free(temp);
		// }
		// temp = int2;
		// int2 = intal_diff(int2, intal2);
		// free(temp);

	} else if (res == -1){
		free(int2);
		return int1;
	} else {
		char *zero = malloc(sizeof(char) * 2);
		zero[0] = '0';
		zero[1] = '\0';
		return zero;
	}
}

char* intal_pow(char* intal1, char* intal2) {
	char zero[2] = {'0', '\0'};
	int i1 = strlen(intal1);
	int i2 = strlen(intal2);
	if (!strcmp(intal1, zero)) {
		char *result = malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
		return result;
	} else if (!strcmp(intal2, zero)) {
		char *result = malloc(sizeof(char) * 2);
		result[0] = '1';
		result[1] = '\0';
		return result;
	} else {
		// zero[0] = '1';
		// char *int1 = malloc(sizeof(char) * 10000);
		// char *int2 = malloc(sizeof(char) * 10000);
		// char *temp = malloc(sizeof(char) * 10000);
		// strcpy(temp, intal1);
		// strcpy(int1, intal1);
		// strcpy(int2, intal2);
		// int i = 1;
		// while (intal_compare(zero, int2)) {
		// 	int1 = intal_multiply(int1, temp);
		// 	int2 = intal_diff(int2, zero);
		// }
		// free(temp);
		// free(int2);
		// return int1;
		int n = convertToInt(intal2);
		int n1 = n;
		n = n/2;
		char *newintal2 = convertToIntal(n);
		char *resprev = intal_pow(intal1, newintal2);
		char *result = intal_multiply(resprev, resprev);
		if (n1%2 == 1) {
			result = intal_multiply(result, intal1);
		}
		return result;

	}
}

char* intal_fibonacci(unsigned int n) {
	char *prev = malloc(sizeof(char) * 2);
	char *curr = malloc(sizeof(char) * 2);
	prev[0] = '0';
	curr[0] = '1';
	prev[1] = curr[1] = '\0';
	if (n == 0) {
		return prev;
	} else if (n == 1) {
		return curr;
	}
	for (int i = 2; i <= n; ++i) {
		curr = intal_add(curr, prev);
		prev = intal_diff(curr, prev);
	}
	free(prev);
	return curr;
}

char* intal_gcd(char* a, char* b) {
	if (!intal_compare(a, "0")) {
		// printf("no\n");
		return b;
	} else {
		// printf("yes %s %s\n", a, b);
		return intal_gcd(intal_mod(b,a), a);
	}
}

char* intal_factorial(unsigned int n) {
	char *temp = malloc(sizeof(char) * 2);
	char *result = malloc(sizeof(char) * 2);
	result[0] = '1';
	result[1] = '\0';
	temp[0] = '1';
	temp[1] = '\0';
	char one[] = {'1', '\0'};
	for (int i = 2; i <= n; ++i) {
		temp = intal_add(temp, one);
		result = intal_multiply(result, temp);
	}
	free(temp);
	return result;
}

static void freeRow(char **a, int k) {
	for (int i = 0; i <= k; ++i) {
		free(a[i]);
	}
	free(a);
}
//TO DO
static int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

static char *intal_bin(char *n, char *k) {
	char *one = malloc(sizeof(char) * 2);
	char *zero = malloc(sizeof(char) * 2);
	one[0] = '1';
	zero[0] = '0';
	one[1] = zero[1] = '\0';
	if ((!intal_compare(k,zero)) || (!intal_compare(k,n))){
		return one;
	} else {
		// return intal_add(intal_bin(intal_diff(n, one), intal_diff(k, one)),intal_bin(intal_diff(n,one),k));
		int k1 = convertToInt(k);
		int n1 = convertToInt(n);
		char ***dpTable;
		dpTable = malloc(2 * sizeof(char**));
		for (int i = 0; i < 2; ++i) {
			dpTable[i] = malloc(sizeof(char *) * (k1 + 1));
		}
		for (int i = 0; i <= min(0,k1); ++i) {
			dpTable[0][i] = convertToIntal(1);
		}
		for (int i = 0; i <= min(1,k1); ++i) {
			if ((i == 1) || (i == 0)) {
				dpTable[1][i] = convertToIntal(1);
			} else {
				// dpTable[1][i] = convertToIntal(convertToInt(dpTable[0][i]) + convertToInt(dpTable[0][i - 1]));
				dpTable[1][i] = intal_add(dpTable[0][i], dpTable[0][i - 1]);
			}
		}
		char **temp;
		for (int i = 2; i <= n1; ++i) {
			temp = dpTable[0];
			dpTable[0] = dpTable[1];
			freeRow(temp,k1);
			dpTable[1] = malloc(sizeof(char *) * (k1 + 1));
			for (int j = 0; j <= min(i,k1); ++j) {
				if ((j == i) || (j == 0)) {
					dpTable[1][j] = convertToIntal(1);
				} else {
					// dpTable[1][j] = convertToIntal(convertToInt(dpTable[0][j - 1]) + convertToInt(dpTable[0][j]));
					dpTable[1][j] = intal_add(dpTable[0][j - 1], dpTable[0][j]);
				}
			}
		}
		// for (int i = 0; i <= k1; ++i) {
		// 	printf("%s ", dpTable[0][i]);
		// }
		// printf("\n");
		// for (int i = 0; i <= k1; ++i) {
		// 	printf("%s ", dpTable[1][i]);
		// }
		// printf("\n");
		freeRow(dpTable[0],k1);
		for (int i = 0; i < k1; ++i) {
			free(dpTable[1][i]);
		}
		char *result = dpTable[1][k1];
		return result;


	}
}

char* intal_bincoeff(unsigned int n, unsigned int k) {
	int lenn, lenk;
	lenn = lenk = 0;
	int n1 = n;
	int k1 = k;
	while (n >= 1) {
		++lenn;
		n = n / 10;
	}
	while (k >= 1) {
		++lenk;
		k = k / 10;
	}
	n = n1;
	k = k1;
	char *nn = malloc(sizeof(char) * (lenn + 1));
	char *kk = malloc(sizeof(char) * (lenk + 1));
	for (int i = 0; i < lenn; ++i) {
		nn[lenn - i - 1] = n%10 + '0';
		n = n / 10;
	}
	for (int j = 0; j < lenk; ++j) {
		kk[lenk - j - 1] = k%10 + '0';
		k = k / 10;
	}
	nn[lenn] = kk[lenk] = '\0';
	char *result = intal_bin(nn,kk);
	free(nn);
	free(kk);
	return result;
}

int intal_max(char **arr, int n) {
	char *max = convertToIntal(0);
	int count = 0;
	for (int i = 0; i < n; ++i) {

		if (intal_compare(max, arr[i]) == -1) {
			free(max);
			count = i;
			max = malloc(sizeof(char) * (strlen(arr[i]) + 1));
			strcpy(max, arr[i]);
			max[strlen(max)] = '\0';
		}
	}
	free(max);
	return count;
}

int intal_min(char **arr, int n) {
	char *min = malloc(sizeof(char) * (strlen(arr[0]) + 1));
	int count = 0;
	strcpy(min, arr[0]);
	min[strlen(min)] = '\0';
	for (int i = 1; i < n; ++i) {
		if (intal_compare(min, arr[i]) == 1) {
			free(min);
			count = i;
			min = malloc(sizeof(char) * (strlen(arr[i]) + 1));
			strcpy(min, arr[i]);
			min[strlen(min)] = '\0';
		}
	}
	free(min);
	return count;
}

int intal_search(char **arr, int n, char* key) {
	int i = 0;
	while (i < n) {
		if (!intal_compare(arr[i], key)) {
			return i;
		}
		++i;
	}
	return -1;
}

int intal_binsearch(char **arr, int n, char* key) {
	int k = convertToInt(key);
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		int num = convertToInt(arr[mid]);
		if (num == k) {
			return mid;
		} else if (k < num) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return -1;
}

static void swap1(char *a, char *b) {
	int n = strlen(a);
	char *temp = malloc(sizeof(char) * (n + 1));
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b,temp);
	free(temp);
}

static void heapify(char **arr, int i, int n) {
	if (2*i > n) {
		return;
	}
	int j = 2*i;
	if ((j + 1) <= n) {
		if (intal_compare(arr[j], arr[j - 1]) == 1) {
			j = j + 1;
		}
	}
	if (intal_compare(arr[j - 1], arr[i - 1]) == 1) {
		swap1(arr[j - 1], arr[i - 1]);
		heapify(arr, j, n);
	}
}

void intal_sort(char **arr, int n) {
	for (int i = n/2; i >= 1; --i) {
		heapify(arr, i, n);
	}
	for (int i = n; i > 1; --i) {
		swap1(arr[i - 1], arr[0]);
		heapify(arr, 1, i - 1);
	}
}

char* coin_row_problem(char **arr, int n) {
	char *zero = malloc(sizeof(char) * 2);
	zero[0] = '0';
	zero[1] = '\0';
	char *temp;
	char *a1 = convertToIntal(0);
	char *a2 = malloc(sizeof(char) * (strlen(arr[0]) + 1));
	strcpy(a2, arr[0]);
	for (int i = 2; i <= n; ++i) {
		if (intal_compare(intal_add(arr[i - 1], a1), a2) == 1) {
			temp = a1;
			a1 = a2;
			a2 = intal_add(arr[i - 1], temp);
			free(temp);
		} else {
			free(a1);
			a1 = a2;
			a2 = intal_add(a2, zero);
		}
	}
	free(zero);
	free(a1);
	return a2;
}

int main(void) {
	
}