public class UpperTriangularMatrix{

	private int matrixSize;
	private int[] matrixData;

	public UpperTriangularMatrix(int n) { //constructor 1
		matrixSize = n <= 0 ? 1 : n; //sets size to 1 if input number is invalid (0 or less)
		matrixData = new int[matrixSize*(matrixSize+1)/2];
	}

	public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException { //constructor 2
		if (upTriM.isUpperTr() && (upTriM.getCols() == upTriM.getRows())) { //make sure input matrix is triangular and square

			matrixSize = upTriM.getRows(); //set size instance
			matrixData = new int[matrixSize*(matrixSize+1)/2]; //allocate appropriate amount of memory for 1d array
			
			int compactIndex = 0;
			for (int i = 0; i < upTriM.getRows(); i++) {
				for (int j = i; j < upTriM.getCols(); j++) {//starting at diagonal index
					matrixData[compactIndex] = upTriM.getElement(i, j);//set the desired index of the matrixData instance to the element 
					++compactIndex;
				}
			}
		} else {
			throw new IllegalArgumentException(); //throw an exception if the matrix isn't triangular and square
		}
	}

	public int getDim() {
		return matrixSize;
	}

	public int getElement(int i, int j) throws IndexOutOfBoundsException {
		if ( i < getDim() && j < getDim()) {
			if (i<=j){
				return matrixData[(i*matrixSize)+j-(i*(i+1)/2)]; //return appropriate index of 1D array corresponding to the requested index of the full matrix
			} else {
				return 0;
			}
		} else {
			throw new IndexOutOfBoundsException("Invalid index");
		}
	}
	
	public void setElement(int x, int i, int j) throws IndexOutOfBoundsException, IllegalArgumentException {
			if(i>j && x!=0){
				throw new IllegalArgumentException("Incorrect Argument"); //throw an exception if you're trying to change a value below the diagonal to a non-zero
			} else {
				// try {
					getElement(i, j);
					matrixData[(i*matrixSize)+j-(i*(i+1)/2)] = x; //set the corresponding 1D index to x that is passed as a parameter
				// } catch (Exception e) {
					// throw new IndexOutOfBoundsException("Invalid index");
				// }
			}
	}

	public Matrix fullMatrix() {
		Matrix output = new Matrix(matrixSize, matrixSize);

		for (int i = 0; i < matrixSize; i++){
			for (int j = 0; j < matrixSize; j++){
				output.setElement(getElement(i, j), i, j); //set each element of newly created matrix to that of the compactly stored matrix (will be zeros below the diagonal)
			}
		}

		return output;
	}
	
	public void print1DArray() {
		for (int i = 0; i < matrixSize*(matrixSize+1)/2; i++) {
			System.out.print(matrixData[i] + "  ");//print each element in the 1d matrix
		}
		System.out.println();
	}
	
	public String toString() {
		return fullMatrix().toString(); //call the toString method on the matrix object returned by fullMatrix method
	}
	
	public int getDet() {
		int diagonalProduct = 1; //starting at 1 because we are doing a product
		for (int i = 0; i < matrixSize; i++){
				diagonalProduct *= getElement(i, i); //multiply the product by each diagonal element going down the matrix
		}
		return diagonalProduct;
	}
	
	public double[] effSolve(double[] b) throws IllegalArgumentException {
		//see the commented code lines to more easily understand the operations that are occurring (these operations use methods)

		int determinant = 1;

		for (int i = 0; i < matrixSize; i++){ //returns the determinant of the matrix (same as getDet method)
			// diagonalProduct *= getElement(i, i);
			determinant *= matrixData[(i*matrixSize)+i-(i*(i+1)/2)];
		}


		if (determinant != 0 && b.length == matrixSize) {
			double[] vector = new double[matrixSize];//generate new answer vector
			// vector[matrixSize-1] = b[matrixSize-1]/getElement(matrixSize-1, matrixSize-1);			
			vector[matrixSize-1] = b[matrixSize-1]/matrixData[(matrixSize*matrixSize)/2+(matrixSize/2)]; //set last element of answer vector equal to the last element of the matrix divided by the last element of the vector	
			for (int i = matrixSize-1; i > 0; i--){ //using back-propagation to populate the answer vector
				double subtractTerm = 0;
				for (int j = matrixSize-1; j >= i ; j--){ // starting at last column of the matrix and going backwards to the diagonal element
					// subtractTerm += getElement(i-1, j)*vector[j]; 
					subtractTerm += matrixData[((i-1)*matrixSize)+j-((i-1)*i/2)]*vector[j]; //find the sum of the extra terms created (that then must be removed)
				}
				// vector[i-1] = (b[i-1]-subtractTerm)/getElement(i-1, i-1);
				vector[i-1] = (b[i-1]-subtractTerm)/matrixData[((i-1)*matrixSize)+(i-1)-((i-1)*i/2)];// for each n-1 element set it equal to the b[n-1] element minus the required subtract term divided by the element diagonally above it in the matrix
			}
			return vector;
		} else {
			throw new IllegalArgumentException(); //throws exception if there is no solution vector possible
		}
	}
}