// sanjie cangshidong6.c

inherit ROOM;
void create()
{
        set("short", "��ʬ��");
        set("long", @LONG
        
һ���Źֵ�ɽ��������������Χ���˶��ţ����Ҷ��ڳ���Ѭ
�죬���Ǹ��õ���ζ������һЩ�ɲݡ�
LONG );
        set("outdoors", 0);
        set("no_clean_up", 1);
  	set("sleep_room",1);
  	set("if_bed",1);
        set("exits", ([
              "south" : __DIR__"cangshidong4",
        ]));
        setup();
        replace_program(ROOM);
}