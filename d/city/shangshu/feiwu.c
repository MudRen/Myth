/***************************************
MUDLIB：Biographies         〓悟空传〓  
Created Admin By Waiwai@2001/02/18
Admin Email：wkzstory@21cn.com         
****************************************/
//Created by waiwai@2001/05/12

inherit ROOM;

void create()
{
	  set("short", "废屋");
        set("long",@LONG

这是一间已被废弃的小屋。小屋很阴暗，也很潮湿。就着微弱的光
线，隐约看见小屋里胡乱地堆放着一些杂物。小屋里到处挂着蜘蛛
网，显然很久没有人来过了。
LONG       );

        set("exits", ([
		"east":		__DIR__"road4",
                ]));

        setup();
        replace_program(ROOM);
}

