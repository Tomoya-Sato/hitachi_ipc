#ifndef GPU_MANAGER_H
#define GPU_MANAGER_H

#define BUF_SIZE 10

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <ros/ros.h>

class GpuIpc
{
  public:
    GpuIpc();
    ~GpuIpc();
    unsigned char* initGpuMemory();
    void freeResource();
    void storeBuffer(pcl::PointXYZ *tmp, int size);
    int updateData();

  private:
    // Params
    pcl::PointXYZ *data_; // GPU
    pcl::PointXYZ *buf_[BUF_SIZE];
    int sizeBuffer_[BUF_SIZE];
    int bufCounter_;

    // Function
    void rotateBuffer();
};

#endif
