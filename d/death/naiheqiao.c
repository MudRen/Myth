inherit ROOM;

void create ()
{
  set ("short", "�κ���");
  set ("long", @LONG

����һ��������֮������֮����ʯ�š����к������������
Ѫ�����ϡ����������޷��֣��վ�֮·��ͬƥ�����������
֮ˮ�������ˣ��ȷ��˱ǡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bidouya",
  "north" : __DIR__"huangwai",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shizhe" : 2,
]));

  setup();
}
/*
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "bridge") ))
                return notify_fail("��Ҫ����������������׼��������\n");
        else

message_vision("$N����һ�е���������ȥ������\n",me);
                me->move("/d/diyu/gufen");
                me->die();
                return 1;
}

*/
