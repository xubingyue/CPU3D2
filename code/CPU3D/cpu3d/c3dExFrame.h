#pragma once
//�����Ƿ�ʹ��һ����ͼ����
#include "c3d.h"
#include "c3dCameara.h"
#include "c3dTexture.h"
#include "c3dShapes.h"
class c3dExFrame
{
public:
	static c3dExFrame& GetInstance()
	{
		static c3dExFrame frame;
		return frame;
	}
	c3dExFrame();
	~c3dExFrame();
	int c3dInit();
	void c3dUpdate();
	void c3dDraw();
	void c3dLookAt(mat4x4& m,vec4& eyePos,vec4& at,vec4& up);
	//�����̻���
	void c3dKeyPressed(int key);
	void c3dKeyUp(int key);
	void c3dMouseDown(int button,int x,int y);
	void c3dMouseUp(int button,int x,int y);
	void c3dMouseMove(int button,int x,int y);
	void perspective(mat4x4& m, float fovy, float aspect, float zn, float zf);
	void dispatch();
private:
	void c3dDeviceSetTexture( void *bits, long pitch, int w, int h );
	void c3dSetIdentity(mat4x4& m);
	void c3dSetZero(mat4x4& m);
	void c3dToScreenCoord(vec2&,vec4&);
	void close();
	
	void apply(vec4& y,vec4& x,mat4x4& m);
private:
	c3dCameara cam;	//���
	vec2 screen;
	mat4x4	mview;	//ģ�;���
	mat4x4  mworld;	//�������
	mat4x4 project;	//ͶӰ����
	mat4x4 transform;
	HDC sHdc;		//��ʱ
	HBITMAP hbitmap;		//
	HBITMAP screen_ob;		//
	unsigned char *screen_fb;	//framebuffer
	HWND hwnd;
	long screen_pitch;

	unsigned int **texture;          // ������ͬ����ÿ������
	int tex_width;              // ��������
	int tex_height;             // �����߶�
	float max_u;
	float max_v;
	int renderState;
	int screenw ;
	int screenh ;
	//---------------------
	c3dTexture tex;

	bool skey[512];

	vec2 lastPoint;

	//���������� ��һ��Щ������
	c3dCube cube;
	bool bMouseDown;
};
static LRESULT screen_events(HWND hWnd, UINT msg, 
							 WPARAM wParam, LPARAM lParam) ;