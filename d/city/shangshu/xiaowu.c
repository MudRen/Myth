/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Created by waiwai@2001/05/12

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long",@LONG

�㲽�����鸮�ڵ�һ��С�ݡ�С���ںܺڣ�ʲôҲ����������Ī
���ظе�һ��ɱ����������ת����ܵ���ͷ��
LONG
        );

        set("exits", ([
		"west":		__DIR__"road1"
                ]));

	create_door ("west", "Сľ��", "east", DOOR_CLOSED);

        setup();
        replace_program(ROOM);
}

