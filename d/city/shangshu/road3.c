/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Created by waiwai@2001/05/12

inherit ROOM;

void create()
{
	  set("short", "��԰С��");
        set("long",@LONG

���������鸮�Ļ�԰С����С�����Ϸ����ǻ�԰�����������
Ʈ������ʹ�˾�����񡣳�����С���Ķ��棬��������ȥ������
����ͥԺ��
LONG
        );

        set("exits", ([
		"north":	__DIR__"yuan",
		"south":	__DIR__"huayuan",
		"east":		__DIR__"chufang",
                ]));

        set("outdoors", "city");

 	setup();
        replace_program(ROOM);
}

