// sanjie cangshidong5.c

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
              "east" : __DIR__"cangshidong4",
        ]));
        set("objects", ([
                __DIR__"npc/guiyou": 1 ]) );
        setup();
}