import sys,math
if sys.argv[1] =="-help":
	print "python generate.py <max> <step size>"
	exit(0)
maxx=int(sys.argv[1])
step_size=int(sys.argv[2])
xs=range(-1*maxx,maxx,step_size)

fd=file("p_first_degree.dat" ,'w')
a=2
b=3
for x in xs:
	fd.write( "%d\t%d\n" %(x,a*x+b))
fd.close()

sd=file("p_second_degree.dat" ,'w')
a=1
b=-3
c=-9
for x in xs:
        sd.write( "%d\t%d\n" %(x,a*x**2+b*x+c))

sd.close()

td=file("p_third_degree.dat" ,'w')
a=1
b=2
c=3
d=4
for x in xs:
        td.write( "%d\t%d\n" %(x,a*x**3+b*x**2+c*x+d))

td.close()

sin=file("sin.dat" ,'w')
a=2

for x in xs[800:1200]:
        sin.write( "%d\t%f\n" %(x,float(a)*math.sin(x)))
sin.close()



strange=file("strange.dat" ,'w')
a=2
b=4
c=-2
d=10
e=12
for x in xs:
        strange.write( "%d\t%d\n" %(x,int((a*math.sin(x)+b*x**3+c*x**2))))
strange.close()

