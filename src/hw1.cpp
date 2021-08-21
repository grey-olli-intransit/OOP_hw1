#include <iostream>
#include <cmath>
#include <cstdint>

// Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.

class Power {
    double first;
    double second;
    public:
        Power():first(1.0),second(0.0) {} 
        void set(double f, double s) {
	   first = f;
	   second = s;
	}
	double calculate() {
	    return pow(first,second);
	}
};

//Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов.

class RGBA {
    std::uint8_t m_red, m_green, m_blue, m_alpha;
    public:
        RGBA():m_red(0), m_green(0), m_blue(0), m_alpha(255) {}
	RGBA(std::uint8_t red,std::uint8_t green,std::uint8_t blue,std::uint8_t alpha)
                   :m_red(red), m_green(green), m_blue(blue), m_alpha(alpha){}
	void print() {
	    printf("red: %d, green: %d, blue: %d, alpha: %d\n", m_red, m_green, m_blue, m_alpha);
	}
};

// Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
//private-массив целых чисел длиной 10;
//private целочисленное значение для отслеживания длины стека;
//public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
//public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
//public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
//public-метод с именем print(), который будет выводить все значения стека.

#define stack_size 10
class Stack {
    int stack[stack_size];
    int stack_length=-1;
    public:
      void reset() {
          stack_length=-1;
          for(int i=0;i<stack_size;++i) {
              stack[i]=0; 
          }
      }
      bool push(int value) {
          if (stack_length==stack_size-1)
		  return false;
	  if(stack_length<0) {
	      stack_length=0;
	      stack[stack_length]=value;
	      return true;
	  }
	  stack[++stack_length]=value;
	  return true;
      }
      long int pop() {
          if (stack_length<0) {
              printf("Stack is empty!\n");
	      return 0xffffffffff; // возвращаем значение большее чем может храниться в int
	  }
          int value_to_return=stack[stack_length];
          stack[stack_length--]=0;
	  return value_to_return;
      }
      void print() {
          if (stack_length<0) {
              printf("()\n");
	      return;
	  }
	  printf("( ");
          for(int i=0;i<=stack_length;++i) {
              printf("%i ",stack[i]);
          }
	  printf(")\n");
      }
      long int peek() {
          if (stack_length<0) {
              printf("Stack is empty!\n");
	      return 0xffffffffff; // возвращаем значение большее чем может храниться в int
	  }
          return stack[stack_length];
      }
};


int main(int argc, char ** argv) {
    printf("Power:\n");
    Power p;
    p.set(2.0,3.0);
    printf("2.0^3.0: %f\n", p.calculate());

    printf("RGBA:\n");
    RGBA g;
    g.print();
    RGBA r(1,25,3,255);
    r.print();

    printf("Stack:\n");
    Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();
    
    return 0;	

}
