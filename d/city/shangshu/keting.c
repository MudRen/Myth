/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Created by waiwai@2001/05/12

#include <allcity.h>

void create()
{
	set("short", "���鸮����");
        set("long",@LONG

���������鸮�Ļ������ƽ�����˾��ڴ˽Ӵ����ˡ�������װ��
�������࣬�������佲�������еļҾ߶����ó���ľ���ģ�ʱʱ
����һ�ɵ�������ζ���Ҿ߱�����һ����Ⱦ�ģ��������������
�ԡ����е���������󣬲������ټ��İ׻�Ƥ��
LONG
        );

	set("exits", ([
		"west" :   __DIR__"yuan",
       ]));

	set("objects", ([
	       CITY_ROOM"shangshu/npc/shangshu":  1,
	]));

        setup();
        replace_program(ROOM);
}

