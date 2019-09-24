#ifndef _APPLE_WRAPPER_H__  
#define _APPLE_WRAPPER_H_  
#ifdef __cplusplus  
extern "C" {  
#endif  
int  GetInstance(int *handle);  
void ReleaseInstance(int *handle);  
extern void SetColor(int handle, int color);  
extern int GetColor(int handle);  
#ifdef __cplusplus  
};  
#endif  
#endif  