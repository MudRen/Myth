/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Created by waiwai@2001/05/12

inherit ROOM;

void create()
{
	  set("short", "����");
        set("long",@LONG

����һ���ѱ�������С�ݡ�С�ݺ�������Ҳ�ܳ�ʪ������΢���Ĺ�
�ߣ���Լ����С������ҵضѷ���һЩ���С���ﵽ������֩��
������Ȼ�ܾ�û���������ˡ�
LONG       );

        set("exits", ([
		"east":		__DIR__"road4",
                ]));

        setup();
        replace_program(ROOM);
}

