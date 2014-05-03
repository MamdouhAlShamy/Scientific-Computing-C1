/*
 * GAUSSIANELIMINATIONSolver.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: mostafa
 */

#include "GAUSSIANELIMINATIONSolver.h"
#include "iostream"
using namespace std;
GAUSSIAN_ELIMINATION_Solver::GAUSSIAN_ELIMINATION_Solver() {
	// TODO Auto-generated constructor stub

}

static double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}


vector<double> GAUSSIAN_ELIMINATION_Solver::solve(vector<vector<double> > A,int N)
{

  	  vector<double>  X=vector<double>(N);
	   double AMAX,XM,SUM;  /* AMAX save  a_{pk} = max_{k<=i<=n} |a_{ik}^{(k)}| */
	   int NROW[N]; /* save  order of rows due to pivoting */

	   int M,ICHG,I,NN,IMAX,J,JJ,IP,JP,NCOPY,I1,J1,N1,K,N2,LL,KK,OK = true;

	      M = N + 1;
	      /* STEP 1 */
	      for (I=1; I<=N; I++) NROW[I-1] = I;

	      //Add your code to compute scale factor for each row here

	      /* initialize row pointer */
	      NN = N - 1;
	      ICHG = 0;
	      I = 1;
	      /* STEP 2 */
	      while ((OK) && (I <= NN)) {
	         /* STEP 3 */
	         // For the scaled partial pivoting, AMAX should be scaled by the scale factor

	         IMAX = NROW[I-1];
	         AMAX = absval(A[IMAX-1][I-1]);
	         IMAX = I;
	         JJ = I + 1;
	         for (IP=JJ; IP<=N; IP++)
	         {
	            JP = NROW[IP-1];
	            if (absval(A[JP-1][I-1]) > AMAX)
	            {
	               AMAX = absval(A[JP-1][I-1]);
	               IMAX = IP;
	            }

	         }
	         /* STEP 4 */
	         if (AMAX <= ZERO) OK = false;
	         else {
	            /* STEP 5 */
	            /* simulate row interchange */
	            if ( NROW[I-1] != NROW[IMAX-1])
	            {
	               ICHG = ICHG + 1;
	               NCOPY = NROW[I-1];
	               NROW[I-1] = NROW[IMAX-1];
	               NROW[IMAX-1] = NCOPY;
	            }
	            I1 = NROW[I-1];
	            /* STEP 6 --- Gaussian elimination step */
	            for (J=JJ; J<=N; J++)
	            {
	               J1 = NROW[J-1];
	               /* STEP  7 */
	               XM = A[J1-1][I-1] / A[I1-1][I-1];
	               /* STEP 8 */
	               for (K=JJ; K<=M; K++)
	                  A[J1-1][K-1] = A[J1-1][K-1] - XM * A[I1-1][K-1];
	               /* Multiplier XM could be saved in A[J1-1,I-1]  */
	               A[J1-1][I-1] = 0.0;
	            }
	         }
	         I++;
	      }


	      if (OK)
	      {
	         /* STEP 9 */
	         N1 = NROW[N-1];
	         if (absval(A[N1-1][N-1]) <= ZERO) OK = false;
	         /* system has no unique solution */
	         else
	         {
	            /* STEP 10 */
	            /* start backward substitution */
	            X[N-1] = A[N1-1][M-1] / A[N1-1][N-1];
	            /* STEP 11 */
	            for (K=1; K<=NN; K++) {
	               I = NN - K + 1;
	               JJ = I + 1;
	               N2 = NROW[I-1];
	               SUM = 0.0;
	               for (KK=JJ; KK<=N; KK++) {
	                  SUM = SUM - A[N2-1][KK-1] * X[KK-1];
	               }
	               X[I-1] = (A[N2-1][N] + SUM) / A[N2-1][I-1];
	            }
	            /* STEP 12 */
	            /* procedure completed successfully */

	         }
	      }
	      if (!OK) std::cerr<<"System has no unique solution"<<std::endl;
	      return X;

}

GAUSSIAN_ELIMINATION_Solver::~GAUSSIAN_ELIMINATION_Solver() {
	// TODO Auto-generated destructor stub
}

