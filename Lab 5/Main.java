public class Main {
	public static void main(String[] args) {
		int uni1[] = {0,2,3,8,10,20};
		int uni2[] = {1,2,3,4,5,12,16,78,85};
		int uni3[] = {-15,-12,-5,-3,0,69,420,432,543,544,545,783};
		int uni4[] = {-15,0,2,5,16,78,432,784};

		SLLSet listObj1 = new SLLSet(uni1);
		SLLSet listObj2 = new SLLSet(uni2);
		SLLSet listObj3 = new SLLSet(uni3);
		SLLSet listObj4 = new SLLSet(uni4);
		
		SLLSet[] listObjA = {listObj1, listObj2, listObj3, listObj4};

		System.out.println(listObj1.isIn(-3));//false
		System.out.println(listObj1.isIn(8));//true

		System.out.println(listObj2.isIn(-4));//false
		System.out.println(listObj2.isIn(4));//true

		System.out.println(listObj3.isIn(-15));//true
		System.out.println(listObj3.isIn(783));//true

		System.out.println(listObj4.isIn(784));//true
		System.out.println(listObj4.isIn(785));//false

		System.out.println(SLLSet.union(listObjA).toString());

		listObj2.remove(85);
		System.out.println(listObj2.toString());

	}
}