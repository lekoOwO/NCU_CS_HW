import pylab, numpy
import math

# 計算 xsin(x) 函數的前 n 項 Taylor 多項式在 x 的函數值，n >= 1
def taylor_poly(n, x) :
    return sum(((-1) ** k * x ** (2 * (k + 1))) / math.factorial(2 * k + 1) for k in range(n))
    
# 設定 X 範圍在 [a,b] , m 為平分點數量
a , b , m = -2*numpy.pi , 2*numpy.pi , 100
# xs : 在 [a,b] 之間(包含首尾)共產生 m 個平分點
xs = numpy.linspace(a, b, m)
n = 10
# 畫出 xsin(x) 函數的前 n 項 Taylor 多項式函數圖形
for i in range(1, n+1):
    # 計算前 i 項 Taylor 多項式函數 xs 所對應的 ys 值
    ys = taylor_poly(i, xs)
    # 畫折線圖並設定圖示文字
    pylab.plot(xs, ys, label = "P" + str(2*i))
# 畫 xsin(x) 函式並設定圖示文字
pylab.plot(xs, xs*numpy.sin(xs), label="x sin(x)")
# 設定圖形的標頭文字
pylab.title("Taylor polynomials with different orders for x sin(x)")
# 顯示圖形圖示
pylab.legend()
# 顯示圖形背景線
pylab.grid()
# 設定 X 與 Y 軸文字
pylab.xlabel("X")
pylab.ylabel("Y")
# 設定 Y 軸顯示範圍 [-6,2] 之間
pylab.ylim(-6, 2)
# 顯示圖形
pylab.show()