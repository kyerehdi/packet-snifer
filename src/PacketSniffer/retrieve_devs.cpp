 #include "pcap.h"
 #include <iostream>

 class RetrieveDevices {

    public:
         char errbuf[PCAP_ERRBUF_SIZE];

    public: 
        pcap_if_t *all_devices;


    public:
        void retrieveDevices(){

        int get_devices = pcap_findalldevs(&all_devices, errbuf);

        if(get_devices == -1){
           std::cout << "No devices detected\n";
        } else {
            for(pcap_if_t* device = all_devices; device != nullptr; device = device->next){
                printf(device->description);
                std::cout << " here is the address" << device->addresses << "\n";
            }


            pcap_freealldevs(all_devices);
        } 
    } 
 };


 int main() {
    RetrieveDevices retriever;
    retriever.retrieveDevices();
    return 0;
}