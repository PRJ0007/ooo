#ifndef CAFFE_DEVICE_HPP
#define CAFFE_DEVICE_HPP
#include <CL/cl.h>
#include <string>
#include <fstream>
#include "caffe/common.hpp"
namespace caffe {

class Device{
public:
    Device():numPlatforms(0),numDevices(0){}
    ~Device();
    cl_uint numPlatforms;
    cl_platform_id * platformIDs;
    char platformName[64];
    char openclVersion[64];
    cl_uint numDevices;
    cl_device_id * DeviceIDs;
    cl_context Context;
    cl_command_queue CommandQueue;
    cl_command_queue CommandQueue_helper;
    cl_program Program; 
    cl_device_id * pDevices;
    clblasOrder col;
    clblasOrder row;
    std::map<std::string, cl_kernel> Kernels;    
     
    cl_int Init(); 
    cl_int ConvertToString(std::string pFileName,std::string &Str);
    void DisplayPlatformInfo();
    void DisplayInfo(cl_platform_id id, cl_platform_info name, std::string str);

    void GetDeviceInfo();
    
    void BuildProgram(std::string kernel_dir);    

    template <typename T>
    void DisplayDeviceInfo(cl_device_id id, cl_device_info name, std::string str);
    template <typename T>
    void appendBitfield(T info, T value, std::string name, std::string &str);
   
    cl_kernel GetKernel(std::string kernel_name);    

};
extern char* buildOption;
extern Device amdDevice;

}  // namespace caffe

#endif //CAFFE_DEVICE_HPP
