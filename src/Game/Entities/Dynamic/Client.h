#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    protected: // protected en vez de private para que Inspector Subclass pueda acceder
        Burger* burger;
        int originalPatience;
        int patience=2000;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        virtual ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;

        virtual bool isInsp(){return false;}
        bool normal = false;
        bool red = false;
        bool redder = false;
        bool reddest = false;
        static int lostClients; // Añade un contador de los clientes que se van por falta de paciencia
        static int Clientsleaving; // Contador de cuantos clientes se fueron del restaurante (atendidos o no atendidos)


};