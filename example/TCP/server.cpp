#include <stdint.h>
#include <iostream>
#include <vector>

#include <OpenP2P.hpp>
#include <OpenP2P/TCP.hpp>

using namespace OpenP2P;

template <typename T>
class Container{
	public:
		~Container(){
			for(typename std::vector<T *>::iterator i = data_.begin(); i != data_.end(); ++i){
				delete (*i);
			}
		}

		T * add(T * t){
			data_.push_back(t);
			return t;
		}

	private:
		std::vector<T *> data_;

};

class ClientThread: public Runnable{
	public:
		ClientThread(){ }

		TCP::Stream& getTCPStream(){
			return tcpStream_;
		}

		void run(){
			std::cout << "---Started transfer" << std::endl;

			BinaryIOStream stream(tcpStream_);
	
			for(unsigned int i = 0; i < 1000; i += 2){
				uint32_t v;
				stream >> v;

				if(v != i){
					std::cout << "Wrong number: " << v << ", Expected: " << (i + 1) << " - Terminating connection" << std::endl;
					return;
				}

				std::cout << "Received: " << i << std::endl;

				stream << uint32_t(i + 1);
			}

			std::cout << "---Successfully completed transfer" << std::endl;
		}

		void cancel(){
			tcpStream_.close();
		}

	private:
		TCP::Stream tcpStream_;

};

int main(){
	TCP::Acceptor acceptor(45556);

	Container<ClientThread> clientThreads;
	Container<Thread> threads;

	while(true){
		ClientThread * c = clientThreads.add(new ClientThread());

		std::cout << "Start accept" << std::endl;
		if(acceptor.accept(c->getTCPStream()).get()){
			//thread per connection
			threads.add(new Thread(*c));
		}else{
			std::cout << "Error: Accept failed" << std::endl;
			return 1;
		}
	}

	return 0;
}
