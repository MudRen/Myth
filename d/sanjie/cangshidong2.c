// sanjie cangshidong2.c

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
              "west" : __DIR__"cangshilang2",
        ]));
        set("objects", ([
                __DIR__"npc/guipohai": 1 ]) );
        setup();
}