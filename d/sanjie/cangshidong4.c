// sanjie cangshidong4.c

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
              "north" : __DIR__"cangshirest",
              "west" : __DIR__"cangshidong5",
              "east" : __DIR__"cangshidong6",
              "south" : __DIR__"cangshidong3",
        ]));
        setup();
}