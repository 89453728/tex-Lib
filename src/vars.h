#ifndef VARSTEX
#define VARSTEX

#include <string>
namespace tex{
	class Var {
		private:
			std::string name;
			double value;
		public: 
			Var();
			Var(const std::string &n);
			Var(const Var &o);
			
			double eval(const double val);
			
			std::string getName()const;
			void setName(const std::string &n);
			double getVal() const;
			int getValInt() const;
			float getValFloat() const;
			int8_t getValInt8()const;
			int16_t getValInt16()const;
			int32_t getValInt32() const;
			int64_t getValInt64()const;
		};
}

#endif

