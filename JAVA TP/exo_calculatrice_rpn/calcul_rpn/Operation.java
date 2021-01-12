package calcul_rpn;

public enum Operation {
	PLUS("+") {
		@Override
		public double eval(double op1 , double op2) {
			return op1 + op2;
		}
	},
	MOINS("-") {
		@Override
		public double eval(double op1, double op2) {
			return op1-op2;
		}
	},
	MULT("*") {
		@Override
		public double eval(double op1, double op2) {
			return op1*op2;
		}
	},
	DIV("/") {
		@Override
		public double eval(double op1, double op2) {
			return op1 / op2;
		}
	};

	private String Symbole;
	
	Operation(String Symbole){
		this.Symbole =Symbole;
	}
	
	public String getSymbole() {
		return Symbole;
	}
	
	
	
	
	abstract public double eval(double op1 ,double op2);
}
