// sanjie cangshilang2.c

inherit ROOM;
void create()
{
        set("short", "��ʬ��");
        set("long", @LONG
        
һ���Źֵ�ɽ��������������Χ���˶��ţ����Ҷ��ڳ���Ѭ
�죬���Ǹ��õ���ζ��
LONG );
        set("outdoors", 0);
        set("exits", ([
              "north" : __DIR__"cangshilang3",
 //             "northwest" : __DIR__"cangshidong1",
              "east" : __DIR__"cangshidong2",
              "southdown" : __DIR__"cangshilang1",
        ]));
        setup();
}
