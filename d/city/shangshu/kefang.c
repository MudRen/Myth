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
        set("short", "�ͷ�");
        set("long",@LONG

���߽������鸮�Ŀͷ����ͷ����󣬵����õñȽ����ࡣ������
С���������ż����顣��һ���ǽ������˰ѱ������ƺ�������
�˴˵����˾�������˫ȫ��

LONG
        );

        set("exits", ([
		"west":		__DIR__"road2"
                ]));

	create_door ("west", "ľ��", "east", DOOR_CLOSED);

        setup();
}

