//Cracked by Roath
inherit ROOM;

void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG

ɽ·��ת��������������ɽ�ϡ�ң��ɽ����������ƬƬ��������
ˮ����������һ�����ǰ���������һ���ۣ��������Ǻ���
�ҡ�
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "northwest" : __DIR__"linyin1",
                "southdown" : __DIR__"shanlu1",
                //"west" : __DIR__"binggu",
//                "east" : __DIR__"pool",
                //"up" : __DIR__"***",
                //"down" : __DIR__"***",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                //__DIR__"npc/***" : 1,
        ]));


        set("outdoors", "wuzhuang");

        setup();
}

