#ifndef STACK_H
#define STACK_H
#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

#include <iostream>
namespace custom
{
	template <class T>
	class stack
	{
		#ifdef UNIT_TESTING
		friend int ::main(int argc, const char* argv[]);
		#endif
		// I like private first, if that's wrong, then I don't want to be right.
	private:

		T* buffer;
		int numElements;
		int numCapacity;
		void resize(int cap);
		void resize();

	public:

		stack();
		stack(int cap);
		stack(const stack & rhs);
		~stack();

		stack <T> & operator =(stack <T> rhs);

		int size();
		int capacity();
		bool empty();
		void clear();
		void push(T ICanNameThisWhateverIWant); //but ill probably regret it later
		void /* snap crackle */ pop(); // here at Nelson Software, we strive to bring you only the highest quality garbage
		T & top();

	};
	template<class T>
	inline void stack<T>::resize(int cap)
	{
		T* newBuffer;
		
		
		if (cap <= 0)
		{
			newBuffer = new T[0];
			numCapacity = 0;
			buffer = NULL;
			if (numElements > cap)
				numElements = 0;
			return;
		}
		else
		{
			newBuffer = new T[cap];
		}

		for (int i = 0; i < numCapacity; i++)
		{
			newBuffer[i] = buffer[i];
		}

		if (numElements > cap)
			numElements = cap;
		numCapacity = cap;
		buffer = newBuffer;
	}
	template<class T>
	void custom::stack<T>::resize()
	{
		T* newBuffer;
		if (numCapacity <= 0)
		{
			newBuffer = new T[1];
			numCapacity = 1;
		}
		else
		{
			numCapacity *= 2;
			newBuffer = new T[numCapacity];

		}

		if ( !(buffer == NULL))
			for (int i = 0; i < numCapacity; i++)
			{
				newBuffer[i] = buffer[i];
			}
			
			buffer = newBuffer;
	}

	template<class T>
	custom::stack<T>::stack()
	{
		buffer = NULL;
		numElements = 0;
		numCapacity = 0;
	}

	template<class T>
	custom::stack<T>::stack(int cap)
	{
		numElements = 0;
		numCapacity = cap;
		buffer = new T[cap];
	}

	template<class T>
	inline stack<T>::stack(const stack& rhs)
	{
		this->numElements = rhs.numElements;
		if (rhs.numCapacity >= this->numElements)
			this->numCapacity = rhs.numElements;
		else
			this->numCapacity = rhs.numCapacity;

		T* newBuffer;
		newBuffer = new T[numCapacity];
		for (int i = 0; i < numElements; i++)
		{
			newBuffer[i] = rhs.buffer[i];
		}
		buffer = newBuffer;
	}

	template<class T>
	inline stack<T>::~stack()
	{
		delete buffer;
	}


	template<class T>
	stack<T>& custom::stack<T>::operator=(stack<T> rhs)
	{
		this->numElements = rhs.numElements;
		if (rhs.numCapacity >= this->numElements)
			this->numCapacity = rhs.numElements;
		else
			this->numCapacity = rhs.numCapacity;

		T* newBuffer;
		newBuffer = new T[numCapacity];

		for (int i = 0; i < numElements; i++)
		{
			newBuffer[i] = rhs.buffer[i];
		}
		buffer = newBuffer;
		return *this;
	}

	template <class T>
	int custom::stack<T>::size()
	{
		return numElements;
	}

	template <class T>
	int custom::stack<T>::capacity()
	{
		return numCapacity;
	}

	template <class T>
	bool custom::stack<T>::empty()
	{
		return !(numElements);
	}

	template<class T>
	void custom::stack<T>::clear()
	{
		for (int i = 0; i < numElements; i++)
		{
			buffer[i] = '\0';
		}

		this->numElements = 0;
	}

	template<class T>
	void custom::stack<T>::push(T t)
	{
		if (((numElements + 1) > numCapacity))
			resize();

		buffer[numElements] = t;
		numElements++;
	}

	template<class T>
	void custom::stack<T>::pop()
	{
		if (numElements > 0)
			numElements--;
	}

	template<class T>
	T& custom::stack<T>::top()
	{
		
		if (numElements > 0)
			return buffer[numElements - 1];
		/*else*/
	}	
}
#endif