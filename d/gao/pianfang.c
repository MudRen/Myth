// pianfang.c

inherit ROOM;

void create()
{
  set ("short", "ƫ��");
  set ("long", @LONG

һ��СС��ƫ��������ܼ򵥣�ֻ��һ�����Ӻͼ������Ӷ��ѣ���
�����˼���ׯ����Ժ����ʵ����Щ����è����ֻ�������˰��ˣ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"west" :__DIR__"zhyuan",
]));
set("objects", ([
                __DIR__"npc/jiading": 2 ]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


