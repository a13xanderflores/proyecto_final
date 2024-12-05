#include "cListaTercero.hpp"


cListaTercero::cListaTercero() : cListaCliente()
{

}

cListaTercero::cListaTercero(cCliente * nuevo, char*place, int tam_clients, int tam_place)
                :cListaCliente(nuevo, place, tam_clients, tam_place)
{

}

void cListaTercero::buscarTelefono(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;

        cTercero *tercero = dynamic_cast<cTercero *>(direccion);
        if (tercero == nullptr) {
            std::cout<<"DYNAMIC CAST FAILED"<<std::endl;
            break;
        }

        const char *cadena = (*tercero).getTelefono();
        int tope = (*tercero).getSize_telef();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

void cListaTercero::buscarCorreo(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;

        cTercero *tercero = dynamic_cast<cTercero *>(direccion);
        if (tercero == nullptr) {
            std::cout<<"DYNAMIC CAST FAILED"<<std::endl;
            break;
        }

        const char *cadena = (*tercero).getCorreo();
        int tope = (*tercero).getSize_correo();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

void cListaTercero::buscarDireccion(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;

        cTercero *tercero = dynamic_cast<cTercero *>(direccion);
        if (tercero == nullptr) {
            std::cout<<"DYNAMIC CAST FAILED"<<std::endl;
            break;
        }

        const char *cadena = (*tercero).getDireccion();
        int tope = (*tercero).getSize_direcc();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

void cListaTercero::buscarNombre(char * codigo, int* temp)//nombre real
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;

        cTercero *tercero = dynamic_cast<cTercero *>(direccion);
        if (tercero == nullptr) {
            std::cout<<"DYNAMIC CAST FAILED"<<std::endl;
            break;
        }


        const char *cadena = (*tercero).getAfiliado();
        int tope = (*tercero).getSize_afiliado();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

void cListaTercero::buscarRegistro(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_client;i++)
    {
        bool flag = true;

        //direccion de memoria
        cCliente * direccion = (manyClients + i);   //manyStorages+i)->codigo;

        cTercero *tercero = dynamic_cast<cTercero *>(direccion);
        if (tercero == nullptr) {
            std::cout<<"DYNAMIC CAST FAILED"<<std::endl;
            break;
        }

        const char *cadena = (*tercero).getRegistro();
        int tope = (*tercero).getSize_registro();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

void cListaTercero::crear_memoria()
{
    if( manyClients != nullptr)
    {   liberar_memoria();    }

    if(size_client>=1)
    {
        manyClients= new cTercero[size_client];
    }
    else
    {
        manyClients= nullptr;
        std::cout<<"size no valid -- no arrange of new memory in manyStorages"<<std::endl;
    }

}

void cListaTercero::crear_memoria_np(int tam, cCliente **destino)
{
    if(*destino != nullptr)
    {
        liberar_memoria_np(destino);
    }

    if (tam > 0) 	//nombre
	{	*destino = new cTercero[tam]; }
	else
	{
		*destino = nullptr;
		std::cout<<"array = 0 bytes?"<< std::endl;
	}
}

cListaTercero::~cListaTercero()
{

}
