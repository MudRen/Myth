// xiaolin1.c

inherit ROOM;

void create()
{
  set ("short", "С����");
  set ("long", @LONG

���й��߰�������Լ����������Χ��һ��˵��ʲô������һ��
�����ζ�������㲻�����˿���ĭ��
LONG);
set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"shanlu",
"south" : __DIR__"xiaolin",
]));

set("objects", ([
                __DIR__"npc/tufei": 4,
                __DIR__"npc/guard": 1 
 ]) );

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


