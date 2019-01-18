inherit ROOM;

void create ()
{
  set ("short", "���԰԰��");
  set ("long", @LONG
�������ɶ�ߵ����������������������������һƬ
�����де������֣���������������˼֮���������ߵ�ǧ��
��ҡ���ǰվ��һλ�׷��ԲԵ����ع�������Ц�ݿ���ؿ�
���㡣
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tudi" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"pan2c",
  "southwest" : __DIR__"pan3c",
  "northwest" : __DIR__"pan1c",
  "east" :   "/d/dntg/yaochi/wmj6",
]));

  setup();
}

int valid_leave(object me, string dir)
{
        object tudi;
    if ( dir == "west" || dir=="southwest" || dir=="northwest") {
        if(objectp(tudi=present("tu di", environment(me))) && living(tudi) && me->query_temp("dntg/pantao")!="doing" && me->query("dntg/pantao")!="done" )
            return notify_fail("���ع�����������ǰ��Ц�����˵�����԰ʤ�أ����Ӵ���ͣ������ء�\n");
    }
    return ::valid_leave(me, dir);
}
