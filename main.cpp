#include <iostream>
#include "liquefy.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main()
{
	char cStrFile[50] = "./lena.bmp";//打开图像路径，BMP图像必须为24位真彩色格式  
	char cStrFilesave[50] = "./test.bmp";//处理后图像存储路

    unsigned char *pOldColorData=NULL;//液化前的图像数据
    unsigned char *pNewColorData=NULL;//液化后的图像数据
    int nWidth =0;//位图宽度
    int nHeight =0;//位图高度
    int nChannel=0;//通道数

    //可以通过鼠标或者触摸屏获取
    float fOldPointX=100.0;//第一接触的横坐标
    float fOldPointY=100.0;//第一接触的纵坐标
    float fNewPointX=155.0;//第二接触的横坐标
    float fNewPointY=155.0;//第二接触的纵坐标
  
    //读取位图的数据 
    pOldColorData= stbi_load(cStrFile, &nWidth, &nHeight, &nChannel, 0);
    std::cout<<nWidth<<";"<<nHeight<<";"<<nChannel<<std::endl;
    pNewColorData = (unsigned char *)malloc(nWidth*nHeight*nChannel);//开辟内存空间存储图像处理之后数据  
	memset(pNewColorData, 0, nWidth*nHeight*nChannel);
    //调用函数将图片数据部分进行处理，再返回处理后的数据。

    liquefyExecution(fOldPointX,fOldPointY,fNewPointX,fNewPointY,nWidth,nHeight,pOldColorData,pNewColorData);

    //保存处理后的数据，也可以显示出来进行交互。
    stbi_write_png(cStrFilesave, nWidth, nHeight, nChannel, pNewColorData, nWidth*nChannel);
    stbi_image_free(pNewColorData);
    std::cout<<"Done!"<<std::endl;
    return 0;
}